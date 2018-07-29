//
// Created by delaram on 7/27/18.
//
#include <SFML/System/Clock.hpp>

#ifndef SFMLPONG_GAME_H
#define SFMLPONG_GAME_H

#include "ball.h"

class Game
{
public:
    Game(int width, int height, double pocket_x[],
         double pocket_y[], double ball_radius, double pocket_radius, double line_x
          ,double D_radius, double cue_x, double cue_y, double cue_speed, double rotationDegree,
         int declared_index,int last_potted, int collide_by_cue_all, int red_count, int game_t, int player_t,bool is_server);

    int get_width();
    int get_height();

    double get_pocketPos_x(int index);
    double get_pocketPos_y(int index);
    Ball* get_ball(int);
    double get_ball_radius();
    double get_pocket_radius();
    double get_line_x();
    double get_D_radius();

    double get_cue_x();
    double get_cue_y();
    double get_cue_speed();

    void set_cue_x(double);
    void set_cue_y(double);
    void set_cue_speed(double);

    double get_rotatation_degree();
    void rotate_cue(char);
    void check_wall_collision();
    void check_ball2ball_collision();
    void update();
    void rules();
    void check_potted();

    void set_declare_ball_index(int);
    int get_declared_ball_index();

    int red_ball_count();

    int get_game_turn();
    void set_game_turn(int);

    int get_player_turn();
    void set_player_turn(int);

    int get_opponent_turn();

    int get_score(int);
    void set_score(int, int);

    void set_is_server(bool);
    bool get_server();

    bool is_turn_finished();


private:
    int width, height, scores[2] ;
    //float p_positions[2];
    Ball *balls[22];
    double pocket_x[6], pocket_y[6]; // pocket positions
    double ball_radius;
    double pocket_radius;
    double line_x;
    double D_radius;
    double cue_x, cue_y, cue_speed;
    double rotationDegree;

    int last_potted_index;
    int declared_ball_index;
    int collided_by_cue_ball;
    int red_count;

    int game_turn;
    int player_turn;

    bool is_server;
};

#endif //SFMLPONG_GAME_H
