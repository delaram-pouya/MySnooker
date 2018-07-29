#include "headers/game.h"
#include "headers/renderer.h"
#include "headers/network.h"
#include "headers/udp.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>

bool flag= true;

bool red = true;

//vector<string> list;

int main() {
    int a;
    std::cin >> a;

    double pocket_x[6] = {0, 178 * 2, 356 * 2, 0, 178 * 2, 356 * 2};
    double pocket_y[6] = {0, 0, 0, 177 * 2, 177 * 2, 177 * 2};

    //Game(int width, int height, int p_width, double pocket_x[],
    //        double pocket_y[], double ball_radius, double pocket_radius, double line_x
    //        ,double D_radius, double cue_x, double cue_y, double cue_speed, double rotationDegree
    //           int declared_index,int potted_index, int collide_by_cue_ball, int red_count, int game_t, int player_t);

    Game *game = new Game(356 * 2, 177 * 2, pocket_x, pocket_y, 4.75 , 4 * 2, 73.7 * 2, 29 * 2, 350, 180, 20, 0,-1,-1,-1,15,0,0,true); //13
    Resource *resource = new Resource(game);
    Network *network;

    // choose if you are a server or a client:

    if (a == 0) {
        network = new Network(resource);
        pthread_t thread;
        pthread_create(&thread, NULL, reinterpret_cast<void *(*)(void *)>(broadcast), NULL);
        network->listen();
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

    ////////////  implement a list of servers for the client to choose between them:
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

    while (window.isOpen()) {

        game_turn = game->get_game_turn();
        player_turn = game->get_player_turn();

// change this line:
        //game_turn = player_turn = 1;

        while (window.pollEvent(event)) {

            if(game_turn == player_turn){
                if (event.type == sf::Event::Closed)
                    window.close();
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
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (((game->get_ball(0)->get_x() - game->get_ball_radius()) <= event.mouseButton.x &&
                             event.mouseButton.x <= (game->get_ball(0)->get_x() + game->get_ball_radius()))
                            && ((game->get_ball(0)->get_y() - game->get_ball_radius()) <= event.mouseButton.y &&
                                event.mouseButton.y <= (game->get_ball(0)->get_y() + game->get_ball_radius())))
                        {
                            std::cout << "in white ball! " << std::endl;
                            if(!red || game->red_ball_count()==0){
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
                                teta = (game->get_rotatation_degree() + 180 )/180;
                                teta = teta *  3.141592653589793;
                                game->get_ball(0)->set_teta(teta);

                                int user_speed;
                                std::cout << "enter the speed: 18, 19, 20 " << endl;
                                cin >> user_speed;
                                game->set_cue_speed(user_speed);
                                game->get_ball(0)->set_speed(game->get_cue_speed());
                                //std::cout << "white ball initial speed is: " << game->get_ball(0)->get_speed() << std::endl;
                                red = true;
                            }
                            // if it's red ball turn :
                            else if(red){

                                game->set_declare_ball_index(23);
                                teta = (game->get_rotatation_degree() + 180 )/180;
                                teta = teta *  3.141592653589793;
                                game->get_ball(0)->set_teta(teta);
                                game->get_ball(0)->set_speed(game->get_cue_speed());
                                //std::cout << "white ball initial speed is: " << game->get_ball(0)->get_speed() << std::endl;
                                red = false;
                            }

                            // if it's colored ball turn

                        }
                    }
                }
            }
        }

        game->update(); //moves balls and calls --> check_wall_collision , check_ball2ball_collision
        //game->rules();  //checks if the cue ball has collided with any ball and if it has collided with the right ball
        game->check_potted();  // checks if any ball has been potted
        //std::cout << "my score is "  << game->get_score(game->get_player_turn()) << std::endl;
        //std::cout << "apponent score is: " << game->get_score(game->get_opponent_turn()) << std::endl;

        if( game->is_turn_finished() )
            game->set_game_turn(game->get_opponent_turn());

        //if(a==0)
        network->send();
        //else
        network->receive();

        std::this_thread::sleep_for (std::chrono::milliseconds(40));

        window.clear(sf::Color(0, 100, 0));
        renderer(&window, game);
        window.display();
    }
}

