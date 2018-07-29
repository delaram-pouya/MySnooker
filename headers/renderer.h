//
// Created by msd on 6/27/18.
//

#ifndef SFMLPONG_RENDERER_H
#define SFMLPONG_RENDERER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"

void renderer(sf::RenderWindow *window, Game *game)
{
    Ball * white_ball = game->get_ball(0);
    sf::CircleShape white;
    white.setRadius(game->get_ball_radius());
    white.setPosition(white_ball->get_x(), white_ball->get_y());
    white.setOrigin(game->get_ball_radius(), game->get_ball_radius());
    white.setFillColor(sf::Color::White);
    bool w_flag = white_ball->check_in_hole();

    Ball * yellow_ball = game->get_ball(16);
    sf::CircleShape yellow;
    yellow.setRadius(game->get_ball_radius());
    yellow.setPosition(yellow_ball->get_x(), yellow_ball->get_y());
    yellow.setOrigin(game->get_ball_radius(), game->get_ball_radius());
    yellow.setFillColor(sf::Color::Yellow);
    bool yellow_flag = yellow_ball->check_in_hole();

    Ball * brown_ball = game->get_ball(17);
    sf::CircleShape brown;
    brown.setRadius(game->get_ball_radius());
    brown.setPosition(brown_ball->get_x(), brown_ball->get_y());
    brown.setOrigin(game->get_ball_radius(), game->get_ball_radius());
    brown.setFillColor(sf::Color(0xA5, 0x2A, 0x2A)); //what is the code for brown??
    bool brown_flag = brown_ball->check_in_hole();

    Ball * green_ball = game->get_ball(18);
    sf::CircleShape green;
    green.setRadius(game->get_ball_radius());
    green.setPosition(green_ball->get_x(), green_ball->get_y());
    green.setOrigin(game->get_ball_radius(), game->get_ball_radius());
    green.setFillColor(sf::Color::Green);
    bool green_flag = green_ball->check_in_hole();

    Ball * blue_ball = game->get_ball(19);
    sf::CircleShape blue;
    blue.setRadius(game->get_ball_radius());
    blue.setPosition(blue_ball->get_x(), blue_ball->get_y());
    blue.setOrigin(game->get_ball_radius(), game->get_ball_radius());
    blue.setFillColor(sf::Color::Blue);
    bool blue_flag = blue_ball->check_in_hole();

    Ball * pink_ball = game->get_ball(20);
    sf::CircleShape pink;
    pink.setRadius(game->get_ball_radius());
    pink.setPosition(pink_ball->get_x(), pink_ball->get_y());
    pink.setOrigin(game->get_ball_radius(), game->get_ball_radius());
    pink.setFillColor(sf::Color::Magenta);
    bool pink_flag = pink_ball->check_in_hole();

    Ball * black_ball = game->get_ball(21);
    sf::CircleShape black;
    black.setRadius(game->get_ball_radius());
    black.setPosition(black_ball->get_x(), black_ball->get_y());
    black.setOrigin(game->get_ball_radius(), game->get_ball_radius());
    black.setFillColor(sf::Color::Black);
    bool black_flag = black_ball->check_in_hole();

    Ball * red_ball_1 = game->get_ball(1);
    sf::CircleShape red1;
    red1.setRadius(game->get_ball_radius());
    red1.setPosition(red_ball_1->get_x(), red_ball_1->get_y());
    red1.setOrigin(game->get_ball_radius(), game->get_ball_radius());
    red1.setFillColor(sf::Color::Red);
    bool red1_flag = red_ball_1->check_in_hole();

    Ball * red_ball_2 = game->get_ball(2);
    sf::CircleShape red2;
    red2.setRadius(game->get_ball_radius());
    red2.setPosition(red_ball_2->get_x(), red_ball_2->get_y());
    red2.setOrigin(game->get_ball_radius(), game->get_ball_radius());
    red2.setFillColor(sf::Color::Red);
    bool red2_flag = red_ball_2->check_in_hole();


    Ball * red_ball_3 = game->get_ball(3);
    sf::CircleShape red3;
    red3.setRadius(game->get_ball_radius());
    red3.setPosition(red_ball_3->get_x(), red_ball_3->get_y());
    red3.setOrigin(game->get_ball_radius(), game->get_ball_radius());
    red3.setFillColor(sf::Color::Red);
    bool red3_flag = red_ball_3->check_in_hole();

    Ball * red_ball_4 = game->get_ball(4);
    sf::CircleShape red4;
    red4.setRadius(game->get_ball_radius());
    red4.setPosition(red_ball_4->get_x(), red_ball_4->get_y());
    red4.setOrigin(game->get_ball_radius(), game->get_ball_radius());
    red4.setFillColor(sf::Color::Red);
    bool red4_flag = red_ball_4->check_in_hole();

    Ball * red_ball_5 = game->get_ball(5);
    sf::CircleShape red5;
    red5.setRadius(game->get_ball_radius());
    red5.setPosition(red_ball_5->get_x(), red_ball_5->get_y());
    red5.setOrigin(game->get_ball_radius(), game->get_ball_radius());
    red5.setFillColor(sf::Color::Red);
    bool red5_flag = red_ball_5->check_in_hole();

    Ball * red_ball_6 = game->get_ball(6);
    sf::CircleShape red6;
    red6.setRadius(game->get_ball_radius());
    red6.setPosition(red_ball_6->get_x(), red_ball_6->get_y());
    red6.setOrigin(game->get_ball_radius(), game->get_ball_radius());
    red6.setFillColor(sf::Color::Red);
    bool red6_flag = red_ball_6->check_in_hole();

    Ball * red_ball_7 = game->get_ball(7);
    sf::CircleShape red7;
    red7.setRadius(game->get_ball_radius());
    red7.setPosition(red_ball_7->get_x(), red_ball_7->get_y());
    red7.setOrigin(game->get_ball_radius(), game->get_ball_radius());
    red7.setFillColor(sf::Color::Red);
    bool red7_flag = red_ball_7->check_in_hole();


    Ball * red_ball_8 = game->get_ball(8);
    sf::CircleShape red8;
    red8.setRadius(game->get_ball_radius());
    red8.setPosition(red_ball_8->get_x(), red_ball_8->get_y());
    red8.setOrigin(game->get_ball_radius(), game->get_ball_radius());
    red8.setFillColor(sf::Color::Red);
    bool red8_flag = red_ball_8->check_in_hole();


    Ball * red_ball_9 = game->get_ball(9);
    sf::CircleShape red9;
    red9.setRadius(game->get_ball_radius());
    red9.setPosition(red_ball_9->get_x(), red_ball_9->get_y());
    red9.setOrigin(game->get_ball_radius(), game->get_ball_radius());
    red9.setFillColor(sf::Color::Red);
    bool red9_flag = red_ball_9->check_in_hole();


    Ball * red_ball_10 = game->get_ball(10);
    sf::CircleShape red10;
    red10.setRadius(game->get_ball_radius());
    red10.setPosition(red_ball_10->get_x(), red_ball_10->get_y());
    red10.setOrigin(game->get_ball_radius(), game->get_ball_radius());
    red10.setFillColor(sf::Color::Red);
    bool red10_flag = red_ball_10->check_in_hole();


    Ball * red_ball_11 = game->get_ball(11);
    sf::CircleShape red11;
    red11.setRadius(game->get_ball_radius());
    red11.setPosition(red_ball_11->get_x(), red_ball_11->get_y());
    red11.setOrigin(game->get_ball_radius(), game->get_ball_radius());
    red11.setFillColor(sf::Color::Red);
    bool red11_flag = red_ball_11->check_in_hole();


    Ball * red_ball_12 = game->get_ball(12);
    sf::CircleShape red12;
    red12.setRadius(game->get_ball_radius());
    red12.setPosition(red_ball_12->get_x(), red_ball_12->get_y());
    red12.setOrigin(game->get_ball_radius(), game->get_ball_radius());
    red12.setFillColor(sf::Color::Red);
    bool red12_flag = red_ball_12->check_in_hole();


    Ball * red_ball_13 = game->get_ball(13);
    sf::CircleShape red13;
    red13.setRadius(game->get_ball_radius());
    red13.setPosition(red_ball_13->get_x(), red_ball_13->get_y());
    red13.setOrigin(game->get_ball_radius(), game->get_ball_radius());
    red13.setFillColor(sf::Color::Red);
    bool red13_flag = red_ball_13->check_in_hole();


    Ball * red_ball_14 = game->get_ball(14);
    sf::CircleShape red14;
    red14.setRadius(game->get_ball_radius());
    red14.setPosition(red_ball_14->get_x(), red_ball_14->get_y());
    red14.setOrigin(game->get_ball_radius(), game->get_ball_radius());
    red14.setFillColor(sf::Color::Red);
    bool red14_flag = red_ball_14->check_in_hole();


    Ball * red_ball_15 = game->get_ball(15);
    sf::CircleShape red15;
    red15.setRadius(game->get_ball_radius());
    red15.setPosition(red_ball_15->get_x(), red_ball_15->get_y());
    red15.setOrigin(game->get_ball_radius(),game->get_ball_radius());
    red15.setFillColor(sf::Color::Red);
    bool red15_flag = red_ball_15->check_in_hole();


    /////////////
    // cue
    sf::RectangleShape cue(sf::Vector2f(70, 3));
    cue.rotate(game->get_rotatation_degree());
    //cue.rotate(80);
    cue.setPosition (game->get_cue_x(), game->get_cue_y());
    cue.setFillColor(sf::Color::Black);

    /////////////
    sf::RectangleShape line(sf::Vector2f(game->get_height(), 1));
    line.rotate(90);
    line.setPosition (game->get_line_x(), 0);

    sf::CircleShape DLoop;
    DLoop.setRadius(game->get_D_radius());
    DLoop.setPosition(game->get_line_x(), game->get_height()/2);
    DLoop.setOrigin(game->get_D_radius(), game->get_D_radius());
    DLoop.setFillColor(sf::Color(0, 100, 0));
    DLoop.setOutlineThickness(2);
    DLoop.setOutlineColor(sf::Color::White);

    sf::RectangleShape Fillrect(sf::Vector2f((game->get_D_radius()+3)*2, game->get_D_radius()+3));
    Fillrect.rotate(90);
    Fillrect.setPosition (game->get_line_x() + game->get_D_radius() + 3, game->get_height()/2 - game->get_D_radius() -2);
    Fillrect.setFillColor(sf::Color(0, 100, 0));

    sf::CircleShape pocket1;
    pocket1.setRadius(game->get_pocket_radius());
    pocket1.setPosition(game->get_pocketPos_x(0), game->get_pocketPos_y(0));
    pocket1.setOrigin(game->get_pocket_radius(), game->get_pocket_radius());
    pocket1.setFillColor(sf::Color::Black);

    sf::CircleShape pocket2;
    pocket2.setRadius(game->get_pocket_radius());
    pocket2.setPosition(game->get_pocketPos_x(1), game->get_pocketPos_y(1));
    pocket2.setOrigin(game->get_pocket_radius(), game->get_pocket_radius());
    pocket2.setFillColor(sf::Color::Black);

    sf::CircleShape pocket3;
    pocket3.setRadius(game->get_pocket_radius());
    pocket3.setPosition(game->get_pocketPos_x(2), game->get_pocketPos_y(2));
    pocket3.setOrigin(game->get_pocket_radius(), game->get_pocket_radius());
    pocket3.setFillColor(sf::Color::Black);

    sf::CircleShape pocket4;
    pocket4.setRadius(game->get_pocket_radius());
    pocket4.setPosition(game->get_pocketPos_x(3), game->get_pocketPos_y(3));
    pocket4.setOrigin(game->get_pocket_radius(), game->get_pocket_radius());
    pocket4.setFillColor(sf::Color::Black);

    sf::CircleShape pocket5;
    pocket5.setRadius(game->get_pocket_radius());
    pocket5.setPosition(game->get_pocketPos_x(4), game->get_pocketPos_y(4));
    pocket5.setOrigin(game->get_pocket_radius(), game->get_pocket_radius());
    pocket5.setFillColor(sf::Color::Black);

    sf::CircleShape pocket6;
    pocket6.setRadius(game->get_pocket_radius());
    pocket6.setPosition(game->get_pocketPos_x(5), game->get_pocketPos_y(5));
    pocket6.setOrigin(game->get_pocket_radius(), game->get_pocket_radius());
    pocket6.setFillColor(sf::Color::Black);


    window->draw(DLoop);
    window->draw(line);
    window->draw(Fillrect);
    window->draw(pocket1);
    window->draw(pocket2);
    window->draw(pocket3);
    window->draw(pocket4);
    window->draw(pocket5);
    window->draw(pocket6);

    if(!w_flag)
        window->draw(white);
    if(!yellow_flag)
        window->draw(yellow);
    if(!brown_flag)
        window->draw(brown);
    if(!green_flag)
        window->draw(green);
    if(!blue_flag)
        window->draw(blue);
    if(!pink_flag)
        window->draw(pink);
    if(!black_flag)
        window->draw(black);
    if(!red1_flag)
        window->draw(red1);
    if(!red2_flag)
        window->draw(red2);
    if(!red3_flag)
        window->draw(red3);
    if(!red4_flag)
        window->draw(red4);
    if(!red5_flag)
        window->draw(red5);
    if(!red6_flag)
        window->draw(red6);
    if(!red7_flag)
        window->draw(red7);
    if(!red8_flag)
        window->draw(red8);
    if(!red9_flag)
        window->draw(red9);
    if(!red10_flag)
        window->draw(red10);
    if(!red11_flag)
        window->draw(red11);
    if(!red12_flag)
        window->draw(red12);
    if(!red13_flag)
        window->draw(red13);
    if(!red14_flag)
        window->draw(red14);
    if(!red15_flag)
        window->draw(red15);

    window->draw(cue);

}

#endif //SFMLPONG_RENDERER_H
