#include "headers/game.h"
#include "headers/renderer.h"
#include "headers/network.h"
#include "headers/udp.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>

bool flag= true;


int main() {
    int a;
    std::cin >> a;

    double pocket_x[6] = {0, 178 * 2, 356 * 2, 0, 178 * 2, 356 * 2};
    double pocket_y[6] = {0, 0, 0, 177 * 2, 177 * 2, 177 * 2};

    //Game(int width, int height, int p_width, double pocket_x[],
    //        double pocket_y[], double ball_radius, double pocket_radius, double line_x
    //        ,double D_radius, double cue_x, double cue_y, double cue_speed, double rotationDegree
    //           int declared_index,int potted_index, int collide_by_cue_ball, int red_count, int game_t, int player_t, bool is_server,
    //                             bool red_turn, bool is_foul );

    Game *game = new Game(356 * 2, 177 * 2, pocket_x, pocket_y, 4.75 , 4 * 2, 73.7 * 2, 29 * 2, 350, 180, 20,
                                                                 0, -1, -1, -1, 15, -1, -1, true, true, false); //13
    Resource *resource = new Resource(game);
    Network *network;

    // choose if you are a server or a client:

    if (a == 0) {
        network = new Network(resource);
        pthread_t thread;
        pthread_create(&thread, NULL, reinterpret_cast<void *(*)(void *)>(broadcast), NULL);
        network->listen();
        ////  if you need a list of servers for the client to choose between them --> omit --> flag = false
        flag=false;
        game->set_is_server(true);
        game->set_player_turn(0);

    } else {
        // thread --> bind the port to receive data from server
        network = new Network(resource, "127.0.0.1");
        pthread_t thread;
        pthread_create(&thread, NULL, reinterpret_cast<void *(*)(void *)>(receive), NULL);
        network->connect();
        game->set_is_server(false);
        game->set_player_turn(1);
    }

    /// display the list on the sreen --> the client should

    sf::RenderWindow window(sf::VideoMode(356 * 2, 177 * 2), "SFML Application");
    sf::CircleShape shape;
    shape.setRadius(40.f);
    shape.setPosition(100.f, 100.f);
    shape.setFillColor(sf::Color::Cyan);
    sf::Event event;
    double teta = 0;

// balls index:
// 0: white, 1:15 red, 16:yellow, 17:brown, 18:green, 19:blue, 20:pink, 21:black

    int game_turn, player_turn ;
    game->set_game_turn(0);

    while (window.isOpen()) {

        game_turn = game->get_game_turn();
        player_turn = game->get_player_turn();

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();

            // check if it's the players turn and all the ball have stopped:
            if(game->is_turn_finished()) {
                cout << "foul is: " << game->get_is_foul() << endl;
                cout << "player turn is: " << game->get_player_turn() << " game turn is: " << game->get_game_turn()
                     << endl;
            }

            if(game_turn == player_turn && game->is_turn_finished()){

                //cout << "it's my: " << player_turn << " turn" << endl;
                if (event.type == sf::Event::KeyPressed) {

                    if (event.key.code == sf::Keyboard::Right)
                        game->rotate_cue('R');

                    if (event.key.code == sf::Keyboard::Left)
                        game->rotate_cue('L');
                }

                if (event.type == sf::Event::MouseMoved) {
                    game->set_cue_x(event.mouseMove.x);
                    game->set_cue_y(event.mouseMove.y);
                }

                if( !game->get_red_flag() || game->red_ball_count() == 0 )
                    cout << "it's colored turn or red balls are finished " << endl;

                else if(game->get_red_flag())
                    cout << "it's red turn " << endl;

                if (event.type == sf::Event::MouseButtonPressed) {

                    if (event.mouseButton.button == sf::Mouse::Left) {

                        if (((game->get_ball(0)->get_x() - game->get_ball_radius()) <= event.mouseButton.x &&
                             event.mouseButton.x <= (game->get_ball(0)->get_x() + game->get_ball_radius()))
                            && ((game->get_ball(0)->get_y() - game->get_ball_radius()) <= event.mouseButton.y &&
                                event.mouseButton.y <= (game->get_ball(0)->get_y() + game->get_ball_radius())))
                        {
                            std::cout << "in white ball! " << std::endl;

                            // if you want to get cue speed from user instead of default value: 20
                            int user_speed =  20;
                            //std::cout << "enter the speed: 18, 19, 20 " << endl;
                            //cin >> user_speed;

                            // attempt to pot a colored ball:
                            if( !game->get_red_flag() || game->red_ball_count() == 0 ){
                                cout << "it's colored turn or red balls are finished " << endl;

                                int ball_index;
                                std::cout << "enter ball index(16:yellow, 17:brown, 18:green, 19:blue, 20:pink, 21:black):  " << endl;
                                std::cin >> ball_index;
                                //  if all the red balls have been potted ball index should be from small ro large
                                if( game->red_ball_count() == 0 )
                                    // 16: yellow, 17: brown, 18: green, 19: blue, 20: pink, 21: black
                                    for(int i = 16 ; i < 22 ; i++)
                                        if(!game->get_ball(i)->check_in_hole()){
                                            ball_index = i;
                                            cout << "ball " << i << " is outside pocket! " << endl;
                                        }

                                game->set_declare_ball_index(ball_index);
                                // in order to avoid getting out of range
                                teta = int(teta) % 360;
                                teta = (game->get_rotatation_degree() + 180 )/180;
                                teta = teta *  3.141592653589793;
                                game->get_ball(0)->set_teta(teta);
                                game->set_cue_speed(user_speed);
                                game->get_ball(0)->set_speed(game->get_cue_speed());
                                //std::cout << "white ball initial speed is: " << game->get_ball(0)->get_speed() << std::endl;
                                game->set_red_flag(true);
                            }
                            // if it's red ball turn :
                                // attempt to pot a red ball:
                            else if(game->get_red_flag()){
                                cout << "it's red turn " << endl;

                                game->set_declare_ball_index(23);
                                // in order to avoid getting out of range
                                teta = int(teta) % 360;
                                teta = (game->get_rotatation_degree() + 180 )/180;
                                teta = teta *  3.141592653589793;
                                game->get_ball(0)->set_teta(teta);
                                game->set_cue_speed(user_speed);
                                game->get_ball(0)->set_speed(game->get_cue_speed());
                                //std::cout << "white ball initial speed is: " << game->get_ball(0)->get_speed() << std::endl;
                                game->set_red_flag(false);
                                cout << "at the end of red turn, red flag is switched to  " << game->get_red_flag() << endl;
                            }
                        }
                    }
                }
            }
        }

        game->update(); //moves balls and calls --> check_wall_collision , check_ball2ball_collision
        game->rules();  //checks if the cue ball has collided with any ball and if it has collided with the right ball
        game->check_potted();  // checks if any ball has been potted
        //std::cout << "my score is "  << game->get_score(game->get_player_turn()) << std::endl;
        //std::cout << "apponent score is: " << game->get_score(game->get_opponent_turn()) << std::endl;

        // a == 0 ?
        if(game->get_is_foul() && a == 0 )
            game->check_foul();

        network->send();
        network->receive();

        std::this_thread::sleep_for (std::chrono::milliseconds(40));

        // check if game is finished:
        if(game->is_game_finished()){

            cout <<  " ***** "  << setw(10) << "GAME FINISHED" << setw(10) << " ***** " << endl;
            int winner = game->get_winner_index();
            if(winner == -1)
                cout << "game is tide " << endl;
            else{
                cout << "winner is player: ";
                if(winner == 0 )
                    cout << "server player " << endl;
                else if(winner == 1)
                    cout << "client player " << endl;
            }
        }

        window.clear(sf::Color(0, 100, 0));
        renderer(&window, game);
        window.display();
    }
}

