#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include "DataHandler.cpp"

class Server {
private:
    int main_port;
    int number_of_clients_in_listening_queue;
    Menu main_menu;
public:
    Server(int main_port_c, int number_of_clients_in_listening_queue_c, const Menu& menu_c) {
        main_port = main_port_c;
        number_of_clients_in_listening_queue = number_of_clients_in_listening_queue_c;
        main_menu = menu_c;
    }
    Server(const Server& to_copy) = delete;
    ~Server() = default;
    Server& operator = (const Server& to_copy) = delete;
    void run() {
        int main_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (main_socket_fd < 0) {
            throw std::runtime_error("ERROR, couldn't create socket!");
        }
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
        char buffer[256];
        int correctness_checker = 0;
        while (true) {
            correctness_checker = read(client_socket, buffer, sizeof(buffer) - 1);
            if (correctness_checker < -1) {
                std::cout << "Something went wrong in reading info\n";
                break;
            }
            std::map<std::string, int> string_converter;
        }
        close(main_socket_fd);
        close(client_socket);
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        throw std::runtime_error("ERROR, no port provided!");
    }

    return 0;
}