
#ifndef SFMLPONG_BALL_H
#define SFMLPONG_BALL_H

#include <math.h>
#include <cstring>
#include <string>


using namespace std;
class Ball
{
public:
    Ball(double x, double y, double dx , double dy ,double speed,
          std::string color, int score, bool in_hole,double teta, double x_before_col, double y_before_col);

    bool check_in_hole();  //implement later

    //get functions:
    double get_x();
    double get_y();
    double get_speed();
    double get_dx();
    double get_dy();
    double get_teta();
    double make_Rad(double);

    //set functions:
    void set_x(double);
    void set_y(double);
    void set_dx(double);
    void set_dy(double);
    void set_teta(double);
    void set_speed(double);
    void set_in_hole(bool);
    void set_x_before_collide(double);
    void set_y_before_collide(double);

    double get_x_before_collide();
    double get_y_before_collide();

    void reverse_dx();
    void reverse_dy();

    int get_score();
    string get_color();
    double get_weight();

    void move();

private:
    double x, y, dx, dy,speed, teta;
    double x_before_col, y_bofore_col;
    const double weight = 10;
    std::string color;
    int score;
    bool in_hole;
};

#endif //SFMLPONG_BALL_H
