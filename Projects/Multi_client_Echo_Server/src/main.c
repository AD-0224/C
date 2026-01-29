#include"server.h"
int main (void)
{
    int server_fd; //socket serveur
    struct sockaddr_in server_addr; //structure contenant les infos réseaux du serveur
  
    int client_fds[MAX_CLIENTS]; //tableau sockets clients
    int fd_max; //pour select
    fd_set readfds; //surveillé par select
    char buffer[BUFFER_SIZE]; //pour copier
    
    for (int i = 0; i < MAX_CLIENTS; i++)
        client_fds[i] = -1; // initialise le tableau à -1 slot libre
    
    server_fd = socket(AF_INET, SOCK_STREAM, 0); //AF_INET= adresse famille IPV4; SOCK_STREAM= type de communication fluide; 0 protocole par défaut ici TCP
    if (server_fd < 0){perror("Socket"); exit(EXIT_FAILURE);} //toujours sécurisé pour éviter des comportements indéfinis

    memset(&server_addr, 0, sizeof(server_addr)); //rappel memset initialise à une valeure choisie
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; //accepte toutes les interfaces
    server_addr.sin_port = htons(PORT); //conversion de port

    //bind = socket <-> serveur
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("bind");
        close(server_fd);
        exit(EXIT_FAILURE); //proteger les fluxs suivants
    }
    //listen = socket en mode écoute
    if(listen(server_fd, MAX_CLIENTS) < 0)
    {
         perror("listen");close(server_fd); exit(EXIT_FAILURE); //proteger les fluxs suivants
    }
    printf("Le serveur écoute sur le port : %d\n",PORT);

    while (1)
    {
        FD_ZERO(&readfds); //on vide tout on doit reiterer à chaque itération
        FD_SET(server_fd, &readfds); //ajt le fd dans l'ensemble à surveiller
        fd_max = server_fd; //initialise fd_max

        //ajt tous les clients actifs à readfds
        for(int i = 0; i < MAX_CLIENTS; i++)
        {
            if(client_fds[i] != -1)
            {
                FD_SET(client_fds[i], &readfds);
                if (client_fds[i] > fd_max)
                    fd_max = client_fds[i];
            }
        }
        //select: attend qu'un fd soit prêt
        if (select(fd_max + 1, &readfds, NULL, NULL, NULL) < 0)
        {
             perror("select");
             break;
        }
        //nouvelle connexion détecté
        if (FD_ISSET(server_fd, &readfds)) //test si le fd fait partie de l'ensemble aprés select
            accept_new_client(server_fd,client_fds,MAX_CLIENTS);
    
        //lecture données clients
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
