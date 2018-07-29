

#include "../headers/network.h"
#include <SFML/Network.hpp>

Network::Network(Resource *resource) {
    this->resource = resource;
    this->is_server = true;
    this->ip = "0.0.0.0";

    this->listener = new sf::TcpListener;

    listener->listen(12345);
}

Network::Network(Resource *resource, std::string ip) {
    this->resource = resource;
    this->is_server = false;
    this->ip = ip;
}

void Network::listen() {
    if (this->is_server) {
        this->socket = new sf::TcpSocket;
        this->listener->accept(*this->socket);
    }
}

void Network::connect() {
    if (not this->is_server){
        this->socket = new sf::TcpSocket;
        this->socket->connect(this->ip, 12345);
    }
}

void Network::send() {
    std::string message = this->resource->get();
    char* c_message = new char[(int)message.size() + 1];

    for (int i = 0; i < message.size(); i++)
        c_message[i] = message[i];

    this->socket->send(c_message, (int)message.size());

    delete c_message;
}

void Network::receive() {
    char data[1024];
    size_t received;
    this->socket->receive(data, 1024, received);

    if (received != 0) {
        std::string message = std::string(data);
        this->resource->set(message);
    }
}
