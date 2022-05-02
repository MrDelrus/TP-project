#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        throw std::runtime_error("ERROR, no port provided!");
    }
    int main_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (main_socket_fd < 0) {
        throw std::runtime_error("ERROR, couldn't create socket!");
    }
    int main_port = atoi(argv[1]);
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(main_port);
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    int bind_checker = bind(main_socket_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if (bind_checker < 0) {
        throw std::runtime_error("ERROR, couldn't bind the socket!");
    }
    listen(main_socket_fd, 5);
    struct sockaddr_in cli_addr;
    socklen_t client_length = sizeof(cli_addr);
    int client_socket = accept(main_socket_fd, (struct sockaddr*)&cli_addr, &client_length);
    if (client_socket < 0) {
        throw std::runtime_error("ERROR, couldn't accept");
    }
    //TODO: while loop
    close(main_socket_fd);
    close(client_socket);
    return 0;
}