#include <stdio.h> //printf, perror
#include <stdlib.h> //exit
#include <string.h> //memset
#include <unistd.h> //close
#include <sys/socket.h> //socket, bind, listen...
#include <sys/select.h>
#include <netinet/in.h> //ipv4
#include <arpa/inet.h>//inet_htons
#include <time.h> //time_t
#include <stddef.h>

#ifndef SERVER_H
#define SERVER_H

#define PORT 8080
#define MAX_CLIENTS 24
#define BUFFER_SIZE 1024
#define LOG_FILE "server.log"

void log_event(const char *msg);
void broadcast_message(const char *msg, int sender_fd, int client_fds[], int max_clients);
int accept_new_client(int client_fd, int client_fds[], int max_clients);
int handle_client_data(int fd, int client_fds[], char *buffer);

#endif