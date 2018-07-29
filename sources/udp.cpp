#include <string>
#include <iostream>
#include <SFML/Network.hpp>
#include "../headers/udp.h"
#include <vector>
#include <list>


extern bool flag;


//extern vector<string> list;
string list2[100] = {""};
int counter = 0;

void receive() {
    sf::UdpSocket socket;
    socket.setBlocking(false);
    char buffer[1024];
    std::size_t received = 0;
    sf::IpAddress sender;
    unsigned short port;
    while(flag) {
        //cout << "salam" << endl;
        socket.unbind();
        socket.bind(55002);
        sf::sleep(sf::seconds(.7));
        if(socket.receive(buffer, sizeof(buffer), received, sender, port) == sf::Socket::Done){
            // it couts the IP address only once because when a clint binds --> it stops broadcasting
            std::cout << sender.toString() << std::endl;
            list2[counter] = sender.toString();
            counter++;
        }
        socket.unbind();
        //list.push_back(sender.toString());

    }
}


void broadcast() {
// Send a message to sf::IpAddress::Broadcast on port 55002
    sf::UdpSocket socket;
    //socket.bind(55001); // different port cus client & server are on same computer
    sf::IpAddress broadcast_add = sf::IpAddress::Broadcast;
    std::string message = "Hi, I am server with IP: " + sf::IpAddress::getLocalAddress().toString();
    while(flag){
        sf::sleep(sf::seconds(.5));
        //std::cout<<"CALLED"<<std::endl;
        socket.send(message.c_str(), message.size() + 1, broadcast_add, 55002);}
}

//nc -lvu 55002  --> cheing in terminal





