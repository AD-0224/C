#include"server.h"
int main (void)
{
    int server_fd; //Server Socket
    struct sockaddr_in server_addr; //structure containing the server's network information
  
    int client_fds[MAX_CLIENTS]; //Table of client sockets
    int fd_max; //For select
    fd_set readfds; //Monitored by select
    char buffer[BUFFER_SIZE]; //For copy
    
    for (int i = 0; i < MAX_CLIENTS; i++)
        client_fds[i] = -1; // Initializes the array to -1 free slot
    
    server_fd = socket(AF_INET, SOCK_STREAM, 0); //AF_INET= IPv4 address family; SOCK_STREAM= fluid communication type; 0 default protocol here TCP
    if (server_fd < 0){perror("Socket"); exit(EXIT_FAILURE);} //Always secure to prevent undefined behavior

    memset(&server_addr, 0, sizeof(server_addr)); //Reminder memset initializes to a chosen value
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; //Accepts all interfaces
    server_addr.sin_port = htons(PORT); //Port conversion

    //bind = socket <-> server
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("bind");
        close(server_fd);
        exit(EXIT_FAILURE); //protect the following streams
    }
    //Listen = socket in listening mode
    if(listen(server_fd, MAX_CLIENTS) < 0)
    {
         perror("listen");close(server_fd); exit(EXIT_FAILURE); //Protect the following streams
    }
    printf("Le serveur écoute sur le port : %d\n",PORT);

    while (1)
    {
        FD_ZERO(&readfds); //We empty everything, we must repeat this at each iteration
        FD_SET(server_fd, &readfds); //Add the fd in the whole to monitor
        fd_max = server_fd;

        //Add all active clients to readfds
        for(int i = 0; i < MAX_CLIENTS; i++)
        {
            if(client_fds[i] != -1)
            {
                FD_SET(client_fds[i], &readfds);
                if (client_fds[i] > fd_max)
                    fd_max = client_fds[i];
            }
        }
        //Select: wait until a file is ready
        if (select(fd_max + 1, &readfds, NULL, NULL, NULL) < 0)
        {
             perror("select");
             break;
        }
        //New connection detected
        //Test if the fd is part of the set after select
        if (FD_ISSET(server_fd, &readfds))
            accept_new_client(server_fd,client_fds,MAX_CLIENTS);
    
        //Reading client data
        for(int i = 0; i < MAX_CLIENTS; i++)
        {
            int fd = client_fds[i];
            if (fd != -1 && FD_ISSET(fd, &readfds))
            {
                handle_client_data(fd,client_fds,buffer);
            }
        }
    }
        for (int i = 0; i < MAX_CLIENTS; i++)
        {
            if (client_fds[i] != -1)
                close(client_fds[i]);
        }
        close(server_fd);
        return 0;
    }
