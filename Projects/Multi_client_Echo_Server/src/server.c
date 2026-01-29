#include "server.h"

//Logging simple: écrit un msg dans le fichier LOG_FILE (nouvelle notion)
void log_event(const char *msg)
{
     FILE *log = fopen(LOG_FILE, "a"); //pointe vers une structure
     if (log)
     {
        time_t now = time(NULL);
        fprintf(log, "[%s] %s", ctime(&now), msg); //fprintf = écrire dans un fichier
        fclose(log);
     }
}
//Broadcast : envoie un message à tout le monde sauf l'envoyeur (nouvelle notion)
void broadcast_message(const char *msg, int sender_fd, int client_fds[], int max_clients)
{
    for (int i = 0; i < max_clients; i++)
    {
        if (client_fds[i] != -1 && client_fds[i] != sender_fd) //-1 cases vides
            send(client_fds[i], msg, strlen(msg), 0); //socket, buffer, taille, flag
    }
}
int accept_new_client(int server_fd, int client_fds[], int max_clients)
{
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    int client_fd = accept(server_fd,(struct sockaddr*)&client_addr, &client_len);
    if (client_fd < 0)
    {
        perror("accept");
        return -1;
    }
    for (int i = 0; i < max_clients; i++)
    {
        if (client_fds[i] == -1)
        {
            client_fds[i] = client_fd;
            char log_msg[128];
            snprintf(log_msg, sizeof(log_msg), "Nouveau client connecté : fd = %d", client_fd);
            printf("%s\n", log_msg);
            log_event(log_msg);
            return client_fd;
        }
    }
    printf("Serveur plein, connexion refusé : fd = %d\n", client_fd); // si il y'a plus de place donc > max_clients
    close(client_fd);
    return -1;
}
int handle_client_data(int fd, int client_fds[], char *buffer)
{
    int bytes = recv(fd, buffer,BUFFER_SIZE - 1, 0);
    if (bytes <= 0)
    {
        char log_message[128];
        snprintf(log_message, sizeof(log_message), "Client fd = %d s'est déconnecté", fd);
        printf("%s\n", log_message);
        log_event(log_message);
        close(fd);

        for (int i = 0; i < MAX_CLIENTS; i++)
        {
            if (client_fds[i] == fd)
            {
                client_fds[i] = -1;
                break;
            }
        }
        return 0;
    }
    else 
    {
        buffer[bytes] = '\0';
        char log_msg[128];
        snprintf(log_msg, sizeof(log_msg), "Client fd = %d dit : %s", fd, buffer);
        printf("%s\n", log_msg);
        log_event(log_msg);

        broadcast_message(buffer,fd,client_fds,MAX_CLIENTS);
        return 1;
    }
}
