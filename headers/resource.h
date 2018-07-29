//
// Created by msd on 6/27/18.
//

#ifndef SFMLPONG_RESOURCE_H
#define SFMLPONG_RESOURCE_H

#include "game.h"
#include <string>

class Resource {
public:
    Resource(Game* game);

    void set(std::string);
    std::string get();
private:
    Game* game;
};


#endif //SFMLPONG_RESOURCE_H
