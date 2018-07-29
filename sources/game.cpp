

#include "../headers/game.h"
#include <algorithm>
#include <SFML/System/Clock.hpp>
#include <cmath>
#include <iostream>

Game::Game(int width, int height, double pocket_x[],
           double pocket_y[], double ball_radius, double pocket_radius, double line_x, double D_radius,
                                  double cue_x, double cue_y,double cue_speed, double rotationDegree,
                                             int declared_index,int potted_index, int collide_by_cue_ball,
                                                       int red_count, int game_t, int player_t
                                         ,bool is_server, bool red_turn, bool is_foul) {

    this->width = width;
    this->height = height;

    this->ball_radius = ball_radius;
    this->pocket_radius = pocket_radius;
    this->line_x = line_x;
    this->D_radius = D_radius;
    this->rotationDegree = rotationDegree;

    this->declared_ball_index = declared_index;
    this->last_potted_index = potted_index;
    this->collided_by_cue_ball = collide_by_cue_ball;

    this->game_turn = game_t;
    this->player_turn = player_t;

    this->cue_x = cue_x;
    this->cue_y = cue_y;
    this->cue_speed = cue_speed;

    this->is_server = is_server;

    this->red_count = red_count;

    this->pocket_x[0] = pocket_x[0];
    this->pocket_x[1] = pocket_x[1];
    this->pocket_x[2] = pocket_x[2];
    this->pocket_x[3] = pocket_x[3];
    this->pocket_x[4] = pocket_x[4];
    this->pocket_x[5] = pocket_x[5];

    this->pocket_y[0] = pocket_y[0];
    this->pocket_y[1] = pocket_y[1];
    this->pocket_y[2] = pocket_y[2];
    this->pocket_y[3] = pocket_y[3];
    this->pocket_y[4] = pocket_y[4];
    this->pocket_y[5] = pocket_y[5];

    this->red_turn = red_turn;

    this->is_foul = is_foul;
    //Ball::Ball(double x, double y, double dx, double dy, double speed ,std::string color,
    //int score, bool in_hole, double teta)

// balls index:
// 0: white, 1:15 red, 16:yellow, 17:brown, 18:green, 19:blue, 20:pink, 21:black

    balls[0] = new Ball(line_x-(D_radius/2), height/2 , 1, 1,0 ,"white", 0, false,0, line_x-(D_radius/2), height/2); //white

    //red balls:
    balls[1] = new Ball(272.5*2 , 88.5*2 , 1, 1 , 0, "red", 1, false,0, 272.5*2 , 88.5*2 ); //red_1
    balls[2] = new Ball(277.3*2 , 91.25*2 , 1, 1 , 0, "red", 1, false, 0, 277.3*2 , 91.25*2); //red_2
    balls[3] = new Ball(277.3*2 , 85.75*2 , 1, 1 , 0, "red", 1, false, 0, 277.3*2 , 85.75*2); //red_3
    balls[4] = new Ball(282.1*2 , 94*2 , 1 , 1, 0, "red", 1, false, 0, 282.1*2 , 94*2); //red_4
    balls[5] = new Ball(282.1*2 , 88.5*2 , 1 , 1 , 0,"red", 1, false, 0, 282.1*2 , 88.5*2 ); //red_5
    balls[6] = new Ball(282.1*2 , 83*2 , 1, 1, 0,"red", 1, false, 0,282.1*2 , 83*2); //red_6
    balls[7] = new Ball(286.9*2 , 96.75*2 , 1 , 1 , 0,"red", 1, false, 0,286.9*2 , 96.75*2); //red_7
    balls[8] = new Ball(286.9*2 , 91.25*2 , 1, 1, 0,"red", 1, false, 0,286.9*2 , 91.25*2); //red_8
    balls[9] = new Ball(286.9*2 , 85.75*2 , 1, 1, 0,"red", 1, false, 0, 286.9*2 , 85.75*2); //red_9
    balls[10] = new Ball(286.9*2 , 80.25*2 , 1, 1 , 0,"red", 1, false, 0, 286.9*2 , 80.25*2); //red_10
    balls[11] = new Ball(291.7*2, 99.5*2 , 1, 1, 0,"red", 1, false, 0, 291.7*2, 99.5*2); //red_11
    balls[12] = new Ball(291.7*2 , 94*2 , 1, 1 , 0,"red", 1, false, 0, 291.7*2 , 94*2); //red_12
    balls[13] = new Ball(291.7*2 , 88.5*2 ,1 , 1 , 0,"red", 1, false, 0, 291.7*2 , 88.5*2); //red_13
    balls[14] = new Ball(291.7*2 , 83*2 , 1, 1, 0, "red", 1, false, 0, 291.7*2 , 83*2); //red_14
    balls[15] = new Ball(291.7*2 , 77.5*2 , 1, 1 , 0,"red", 1, false, 0, 291.7*2 , 77.5*2); //red_15

    // colored balls:
    balls[16] = new Ball(line_x , 117.5*2 , 1, 1, 0, "yellow", 2, false, 0, line_x , 117.5*2 );  //yellow
    balls[17] = new Ball(line_x , 88.5*2 , 1, 1, 0,"brown", 4, false, 0, line_x , 88.5*2);  //brown
    balls[18] = new Ball(line_x , 59.5*2 , 1, 1, 0, "green", 3, false, 0, line_x , 59.5*2 );  //green
    balls[19] = new Ball(width/2 , 88.5*2 , 1, 1, 0, "blue", 5, false, 0, width/2 , 88.5*2 );  //blue
    balls[20] = new Ball(267*2 , 88.5*2  , 1, 1, 0, "pink", 6, false, 0, 267*2 , 88.5*2 );  //pink
    balls[21] = new Ball(323.6*2 , 88.5*2 , 1, 1, 0,"black", 7, false, 0, 323.6*2 , 88.5*2);  // black
}

int Game::get_width() {
    return this->width;
}

int Game::get_height() {
    return this->height;
}

Ball* Game::get_ball(int index) {
    return this->balls[index];
}

double Game::get_pocketPos_x(int index) {
    return this->pocket_x[index];
}

double Game::get_pocketPos_y(int index) {
    return this->pocket_y[index];
}

double Game::get_ball_radius() {
    return this->ball_radius;
}

double Game::get_pocket_radius() {
    return this->pocket_radius;
}

double Game::get_line_x() {
    return this->line_x;
}

double Game::get_D_radius() {
    return this->D_radius;
}

double Game::get_cue_x() {
    return this->cue_x;
}

double Game::get_cue_y() {
    return this->cue_y;
}


double Game::get_cue_speed() {
    return this->cue_speed;
}

void Game::set_cue_x(double cue_x_value) {
    this->cue_x = cue_x_value;
}


void Game::set_cue_y(double cue_y_value) {
    this->cue_y = cue_y_value;
}

void Game::set_cue_speed(double cue_force_value) {
    this->cue_speed = cue_force_value;
}


double Game::get_rotatation_degree() {
    return this->rotationDegree;
}


void Game::rotate_cue(char way) {
    float speed = 10;
    if(way == 'R')
        this->rotationDegree = rotationDegree  + speed;

    if(way == 'L')
        this->rotationDegree = rotationDegree  - speed;
}

void Game::check_ball2ball_collision() {
    double vf1, vf2, teta;
    for(int i = 0; i < 22; i++){
        for(int j = i + 1; j < 22; j++){
            int first = i , second = j;

            if( abs( this->balls[i]->get_x() - this->balls[j]->get_x()) < 2* this->get_ball_radius()
                && abs( this->balls[i]->get_y() - this->balls[j]->get_y()) < 2*this->get_ball_radius()){


                this->balls[i]->set_x_before_collide(this->balls[i]->get_x());
                this->balls[i]->set_y_before_collide(this->balls[i]->get_y());
                this->balls[j]->set_x_before_collide(this->balls[j]->get_x());
                this->balls[j]->set_y_before_collide(this->balls[j]->get_y());

                std::cout << this->balls[i]->get_color() << " ball and " << this->balls[j]->get_color() << " have collided" << std::endl;
                if( balls[i]->get_speed()== 0){
                    first = j;
                    second = i; }

                //if the cue ball has collided with some ball:
                if(first == 0 ){
                    this->collided_by_cue_ball = second;
                }
                else
                    this->collided_by_cue_ball = -1;

//                cout << "before: " << endl;
//                cout << "first ball: " << balls[first]->get_color() <<" vf1 is: "
//                     << balls[first]->get_speed() <<" teta is: "<< balls[first]->get_teta() << std::endl;
//                cout << "second ball: " << balls[second]->get_color() << " vf2 is: "
//                     << balls[second]->get_speed()<<" teta is: "<< balls[second]->get_teta() << std::endl;
//
//                cout << this->balls[first]->get_color() << " was moving and " << this->balls[second]->get_color() << " was static" << std::endl;
                teta = balls[first]->get_teta();

                vf2 =abs( balls[first]->get_speed()/  sqrt(1 + ( cos(teta)*cos(teta) )/( (sin(2*teta)* sin(2*teta))))   );
                vf1 = (cos(teta)/sin(2*teta) )* vf2;

                vf1 = abs(vf1) + 0.05;
                vf2 = abs(vf2) + 0.05;

                //second vs first is teta , 2*teta

                this->get_ball(second)->set_speed(vf2);
                this->get_ball(second)->set_teta(2*teta);

                this->get_ball(first)->set_speed(vf1);
                this->get_ball(first)->set_teta(teta);

                this->get_ball(first)->move();
                this->get_ball(second)->move();

//                cout << "after: " << endl;
//                cout << "first ball: " << balls[first]->get_color() <<" vf1 is: "
//                     << balls[first]->get_speed() <<" teta is: "<< balls[first]->get_teta() << std::endl;
//                cout << "second ball: " << balls[second]->get_color() << " vf2 is: "
//                     << balls[second]->get_speed()<<" teta is: "<< balls[second]->get_teta() << std::endl;

                cout << "first ball: " << balls[first]->get_color() <<" x is: "
                     << balls[first]->get_x() <<" y is: " << balls[first]->get_y() << std::endl;
                cout << "second ball: " << balls[second]->get_color() << " x is: "
                     << balls[second]->get_x()<<" y is: "<< balls[second]->get_y() << std::endl;
            }
        }
    }
}


void Game::check_wall_collision() {
    for(int index = 0 ; index < 22; index++) {
        double ball_x = this->balls[index]->get_x(), ball_y = this->balls[index]->get_y();

        if (ball_y <= 0 || ball_y >= this->height){  //collision with wall
            this->balls[index]->reverse_dy();
            //spin?
//            double teta_1 = this->balls[index]->get_teta();
//            double teta_2 = atan( (sin(teta_1)* this->balls[index]->get_dy()) / (cos(teta_1)*this->balls[index]->get_dx()) );
//            this->balls[index]->set_teta(teta_2);
        }

        if (ball_x <= 0 || ball_x >= this->width){  //collision with wall
            this->balls[index]->reverse_dx();
            //spin?
//            double teta_1 = this->balls[index]->get_teta();
//            double teta_2 = atan( (sin(teta_1)* this->balls[index]->get_dy()) / (cos(teta_1)*this->balls[index]->get_dx()) );
//            this->balls[index]->set_teta(teta_2);
        }

        for(int p_index = 0 ; p_index < 6; p_index++) { //checks if ball is in hole

            double delta_x = abs(this->pocket_x[p_index] - ball_x);
            double delta_y = abs(this->pocket_y[p_index] - ball_y);
            double center_distance = sqrt( delta_x*delta_x + delta_y*delta_y );

            if (center_distance <= this->pocket_radius) {
                this->balls[index]->set_in_hole(true);
                this->last_potted_index = index;
                this->balls[index]->set_speed(0);
            }
        }
    }
}
// balls index:
// 0: white, 1:15 red, 16:yellow, 17:brown, 18:green, 19:blue, 20:pink, 21:black

void Game::rules() {
    // if cue collision with a ball happends:
    // check if cue ball has collided with anything --> check if it's with the right ball

    // this only captures the last collision:
    if( this->collided_by_cue_ball>0) {

        // if it's red ball turn: --> (0,15)
        if(this->declared_ball_index == 23 && this->collided_by_cue_ball < 16){
            //has collided with right ball
            this->check_potted(); // checks if wrong balls haven't been potted and sets the score
        }

        // if it's colored ball turn:
        else if( this->declared_ball_index == this->collided_by_cue_ball && this->collided_by_cue_ball > 15){
            //has collided with right ball
            this->check_potted(); // checks is wrong balls haven't been potted and sets the score
        }
            // if cue ball has collided with :
            /// not in turn ball(red vs colored)
            /// not the declared ball when it's colored ball turn
        else{
            this->scores[this->get_opponent_turn()] += max(this->balls[collided_by_cue_ball]->get_score(), 4);
            //loose turn
            this->is_foul = true;

        }
    }

    // if cue_ball doesn't touch any ball --> loose point and loose turn
    if(this->collided_by_cue_ball == -1 && this->declared_ball_index > 0 ){
        this->scores[this->get_opponent_turn()] += 4;
        //loose turn
        this->is_foul = true;
    }
}


void Game::set_declare_ball_index(int index) {
    this->declared_ball_index = index;
}


int Game::get_declared_ball_index() {
    return this->declared_ball_index;
}


void Game::check_potted() {

    //loop through balls to see if any of them has fallen into a pocket
    for(int i = 0 ; i < 22; i++){
        if(this->balls[i]->check_in_hole() ){ //if a ball has fallen to a pocket
            cout << this->balls[i]->get_color() << " is in pocket " << endl;

            // if the white ball has been potted:
            if( i == 0 ){
                this->balls[0]->set_x(line_x-(D_radius/2));
                this->balls[0]->set_y(height/2);
                this->scores[this->get_opponent_turn()] += 4;
                // loose the turn
                this->is_foul = true;
            }

            // if a red ball has been potted:
            else if( i > 0 && i < 16) {
                // if it's the first potted ball of game or the last potted ball was a colored ball:
                if( ( (this->last_potted_index == -1) || (this->last_potted_index>15 && this->last_potted_index < 22)) ){
                    this->scores[this->player_turn]++;
                }
                else{
                    //if last potted ball is also a red
                    this->scores[this->get_opponent_turn()] ++;
                    // loose the turn
                    this->is_foul = true;
                    }
            }

            // if a colored ball has been potted:
            // if player has declared this ball and last potted is a red
            else if( i == this->get_declared_ball_index() && this->last_potted_index > 0 && this->last_potted_index < 16)
                this->scores[this->player_turn] += this->balls[i]->get_score();


            else{
                this->scores[this->get_opponent_turn()] += max(4, this->balls[i]->get_score());
                this->is_foul = true;
            }
        }
    }



    //count red balls on the table:
    int red_num = 0;
    for(int i = 0 ; i < 22; i++){
        if(this->balls[i]->get_color() == "red" && !this->balls[i]->check_in_hole())
            red_num ++;
    }
    this->red_count = red_num;

    // putting red balls back on the table
    // if there are any red balls left on the table --> if any colored ball falls in pocket --> put back on last position before collision
    if(red_count>0){
        for(int i = 16 ; i < 22; i++){
            if(this->balls[i]->check_in_hole()){
                this->balls[i]->set_x(this->balls[i]->get_x_before_collide());
                this->balls[i]->set_y(this->balls[i]->get_y_before_collide());
            }
        }
    }
}


void Game::update() {
    for (int i = 0; i < 22; i++) {
        double ball_speed = this->get_ball(i)->get_speed();
        if (ball_speed > 0) {
            //cout << game->get_ball(i)->get_color() << " has non-zero speed" << std::endl;
            this->get_ball(i)->move();
            //cout << game->get_ball(i)->get_color() << " ball X: " << game->get_ball(i)->get_x() << " Y: "
            //     << game->get_ball(i)->get_y() << std::endl;
        }
        this->check_wall_collision(); //checks collision with walls
        this->check_ball2ball_collision(); //checks ball to ball collisions
    }
}

int Game::red_ball_count() {
    return this->red_count;
}

int Game::get_game_turn() {
    return this->game_turn;
}

int Game::get_player_turn() {
    return this->player_turn;
}

void Game::set_player_turn(int turn) {
    this->player_turn = turn;
}

int Game::get_opponent_turn() {
    if(this->player_turn == 0 )
        return 1;
    else if(this->player_turn == 1)
        return 0;
}


int Game::get_score(int index) {
    return this->scores[index];
}


void Game::set_game_turn(int turn) {
    this->game_turn = turn;
}


void Game::set_score(int p_index, int score) {
    this->scores[p_index] = score;
}


void Game::set_is_server(bool value) {
    this->is_server = value;
}


bool Game::get_server() {
    return this->is_server;
}

bool Game::is_turn_finished() {
    for(int i = 0 ; i < 22 ; i++ )
        if( this->get_ball(i)->get_speed() != 0)
            return false;
    return true;
}

bool Game::is_game_finished() {
    for(int i = 0 ; i < 22 ; i ++)
        if(!this->get_ball(i)->check_in_hole())
            return false;
    return true;
}

int Game::get_winner_index() {
    int winner = 0;
    if ( this->scores[0] < this->scores[1]  )
        winner = 1;
    if(this->scores[0] == this->scores[1])
        winner = -1;
    return winner;
}

void Game::reset() {

    this->set_red_flag(true);
    // next player need to declare new balls(red: 23 , colored:index)
    this->declared_ball_index = -1;
    //
    this->last_potted_index = -1;
    // turn to not collided state for the next round :
    this->collided_by_cue_ball = -1;
    this->get_ball(0)->set_in_hole(false);
    if(this->red_ball_count() != 0 )
        for(int i = 16; i < 22 ; i ++)
            this->get_ball(i)->set_in_hole(false);
    //
}

void Game::set_red_flag(bool flag) {
    this->red_turn = flag;
}

bool Game::get_red_flag() {
    return this->red_turn;
}

bool Game::get_is_foul() {
    return this->is_foul;
}

void Game::set_is_foul(bool value) {
    this->is_foul = value;
}

void Game::check_foul() {
    if(this->is_foul) {
        this->reset();
        this->set_game_turn(this->get_opponent_turn());
    }
}


