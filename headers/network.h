//
// Created by delaram on 7/27/18.
//

#ifndef SFMLPONG_NETWORK_H
#define SFMLPONG_NETWORK_H


#include "resource.h"
#include <SFML/Network.hpp>


class Network {
public:
    Network(Resource* resource);
    Network(Resource* resource, std::string ip);

    void send();
    void receive();
    void listen();
    void connect();
private:
    Resource* resource;
    bool is_server;
    std::string ip;
    sf::TcpListener* listener;
    sf::TcpSocket* socket;
};


#endif //SFMLPONG_NETWORK_H
