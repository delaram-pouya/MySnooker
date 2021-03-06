
#include "../headers/resource.h"
#include <sstream>
#include <iostream>

Resource::Resource(Game *game) {
    this->game = game;
}

void Resource::set(std::string str) {

    std::stringstream inp(str);

    double white_x, red1_x, red2_x, red3_x, red4_x, red5_x, red6_x,
            red7_x, red8_x, red9_x, red10_x, red11_x, red12_x, red13_x, red14_x, red15_x,
            yellow_x, brown_x, green_x, blue_x, pink_x, black_x,

            white_y, red1_y, red2_y ,red3_y, red4_y, red5_y, red6_y,
            red7_y, red8_y, red9_y, red10_y, red11_y, red12_y, red13_y, red14_y, red15_y,
            yellow_y, brown_y, green_y, blue_y, pink_y, black_y;

    int game_turn;
    int server_score, player_score;

    double white_speed, teta;
    bool red_flag;


    int declared_index, last_potted,  collide_by_cue_ball,  red_count;

    std::string first,last;

    //   >> declared_index >> last_potted >> collide_by_cue_all >> red_count,

    // clear player_turn????

    inp >> first >>game_turn >>red_flag >>server_score >> player_score >> teta>>
         declared_index >> last_potted >> collide_by_cue_ball >>
        red_count >> white_speed >> white_x >> white_y >>red1_x >> red1_y >> red2_x  >>  red2_y >> red3_x >> red3_y >> red4_x >> red4_y >>
        red5_x >> red5_y>> red6_x >> red6_y >> red7_x >> red7_y >> red8_x >> red8_y >> red9_x >> red9_y >> red10_x >> red10_y
        >> red11_x >> red11_y >> red12_x >> red12_y >> red13_x  >> red13_y >> red14_x >> red14_y >> red15_x >> red15_y >>
        yellow_x >> yellow_y >> brown_x >> brown_y >> green_x>> green_y >> blue_x >> blue_y >> pink_x >> pink_y >> black_x >> black_y ;


    // in_hole variable is set for both below conditions(server & client)
    for(int i = 0 ; i < 22; i++){
        bool in_hole ;
        inp >> in_hole;
        this->game->get_ball(i)->set_in_hole(in_hole);
    }

    inp >> last;


    // cout input data to screen --> for debugging
    //std::cout << inp.str() << endl;

    // to check if the data is received completely check if first and last there is a {}
    if(first != "{" || last != "}")
        return;

    // to sync clinet and server playing
    if(this->game->get_server() && (this->game->get_game_turn() != this->game->get_player_turn() ) ){

        this->game->set_game_turn(game_turn);
        //this->game->set_player_turn(player_turn);  // comment this??
        this->game->get_ball(0)->set_teta(teta);
        this->game->get_ball(0)->set_speed(white_speed);
        this->game->set_score(0, server_score);
        this->game->set_score(1, player_score);
        this->game->set_red_flag(red_flag);
    }

    if(!this->game->get_server()) {
        this->game->set_red_flag(red_flag);

        this->game->set_declare_ball_index(declared_index);
        this->game->set_last_potted(last_potted);
        this->game->set_collided_by_cue_ball(collide_by_cue_ball);
        this->game->set_red_ball_count(red_count);

        this->game->set_game_turn(game_turn);
        //this->game->set_player_turn(player_turn);   // comment this ??

        this->game->get_ball(0)->set_speed(white_speed);

        this->game->get_ball(0)->set_teta(teta);

        this->game->set_score(0, server_score);
        this->game->set_score(1, player_score);

        this->game->get_ball(0)->set_x(white_x);
        this->game->get_ball(0)->set_y(white_y);

        this->game->get_ball(1)->set_x(red1_x);
        this->game->get_ball(1)->set_y(red1_y);

        this->game->get_ball(2)->set_x(red2_x);
        this->game->get_ball(2)->set_y(red2_y);

        this->game->get_ball(3)->set_x(red3_x);
        this->game->get_ball(3)->set_y(red3_y);

        this->game->get_ball(4)->set_x(red4_x);
        this->game->get_ball(4)->set_y(red4_y);

        this->game->get_ball(5)->set_x(red5_x);
        this->game->get_ball(5)->set_y(red5_y);

        this->game->get_ball(6)->set_x(red6_x);
        this->game->get_ball(6)->set_y(red6_y);

        this->game->get_ball(7)->set_x(red7_x);
        this->game->get_ball(7)->set_y(red7_y);

        this->game->get_ball(8)->set_x(red8_x);
        this->game->get_ball(8)->set_y(red8_y);

        this->game->get_ball(9)->set_x(red9_x);
        this->game->get_ball(9)->set_y(red9_y);

        this->game->get_ball(10)->set_x(red10_x);
        this->game->get_ball(10)->set_y(red10_y);

        this->game->get_ball(11)->set_x(red11_x);
        this->game->get_ball(11)->set_y(red11_y);

        this->game->get_ball(12)->set_x(red12_x);
        this->game->get_ball(12)->set_y(red12_y);

        this->game->get_ball(13)->set_x(red13_x);
        this->game->get_ball(13)->set_y(red13_y);

        this->game->get_ball(14)->set_x(red14_x);
        this->game->get_ball(14)->set_y(red14_y);

        this->game->get_ball(15)->set_x(red15_x);
        this->game->get_ball(15)->set_y(red15_y);

        this->game->get_ball(16)->set_x(yellow_x);
        this->game->get_ball(16)->set_y(yellow_y);

        this->game->get_ball(17)->set_x(brown_x);
        this->game->get_ball(17)->set_y(brown_y);

        this->game->get_ball(18)->set_x(green_x);
        this->game->get_ball(18)->set_y(green_y);

        this->game->get_ball(19)->set_x(blue_x);
        this->game->get_ball(19)->set_y(blue_y);

        this->game->get_ball(20)->set_x(pink_x);
        this->game->get_ball(20)->set_y(pink_y);

        this->game->get_ball(21)->set_x(black_x);
        this->game->get_ball(21)->set_y(black_y);

    }

    return;


}

std::string Resource::get() {
    std::stringstream res;

    // to check if the data is received completely check if first and last there is a {}
    res << "{ "
        //<< this->game->get_player_turn() << " "    // comment this???
        << this->game->get_game_turn() << " "

        << this->game->get_red_flag() << " "
        << this->game->get_score(0) << " " << this->game->get_score(1) << " "
        << this->game->get_ball(0)->get_teta() << " "

        << this->game->get_declared_ball_index() << " "
        << this->game->get_last_potted() << " "
        << this->game->get_collided_by_cue_ball() << " "
        << this->game->red_ball_count() << " "

        << this->game->get_ball(0)->get_speed() << " "

        << this->game->get_ball(0)->get_x() << " " << this->game->get_ball(0)->get_y() << " "
        << this->game->get_ball(1)->get_x() << " " << this->game->get_ball(1)->get_y() << " "
        << this->game->get_ball(2)->get_x() << " " << this->game->get_ball(2)->get_y() << " "
        << this->game->get_ball(3)->get_x() << " " << this->game->get_ball(3)->get_y() << " "
        << this->game->get_ball(4)->get_x() << " " << this->game->get_ball(4)->get_y() << " "
        << this->game->get_ball(5)->get_x() << " " << this->game->get_ball(5)->get_y() << " "
        << this->game->get_ball(6)->get_x() << " " << this->game->get_ball(6)->get_y() << " "
        << this->game->get_ball(7)->get_x() << " " << this->game->get_ball(7)->get_y() << " "
        << this->game->get_ball(8)->get_x() << " " << this->game->get_ball(8)->get_y() << " "
        << this->game->get_ball(9)->get_x() << " " << this->game->get_ball(9)->get_y() << " "
        << this->game->get_ball(10)->get_x() << " " << this->game->get_ball(10)->get_y() << " "
        << this->game->get_ball(11)->get_x() << " " << this->game->get_ball(11)->get_y() << " "
        << this->game->get_ball(12)->get_x() << " " << this->game->get_ball(12)->get_y() << " "
        << this->game->get_ball(13)->get_x() << " " << this->game->get_ball(13)->get_y() << " "
        << this->game->get_ball(14)->get_x() << " " << this->game->get_ball(14)->get_y() << " "
        << this->game->get_ball(15)->get_x() << " " << this->game->get_ball(15)->get_y() << " "

        << this->game->get_ball(16)->get_x() << " " << this->game->get_ball(16)->get_y() << " "
        << this->game->get_ball(17)->get_x() << " " << this->game->get_ball(17)->get_y() << " "
        << this->game->get_ball(18)->get_x() << " " << this->game->get_ball(18)->get_y() << " "
        << this->game->get_ball(19)->get_x() << " " << this->game->get_ball(19)->get_y() << " "
        << this->game->get_ball(20)->get_x() << " " << this->game->get_ball(20)->get_y() << " "
        << this->game->get_ball(21)->get_x() << " " << this->game->get_ball(21)->get_y() << " ";

        for(int i = 0 ; i < 22; i++){
            res <<" " <<this->game->get_ball(i)->check_in_hole()<< " ";
        }

        res << " } ";

    return res.str();
}



