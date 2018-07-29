
#include "../headers/ball.h"


Ball::Ball(double x, double y, double dx, double dy, double speed ,std::string color,
           int score, bool in_hole, double teta,double x_before_col,double y_before_col) {
    this->x = x;
    this->y = y;
    this->dx = dx;
    this->dy = dy;
    this->speed = 0;
    this->teta = 0;
    this->in_hole = in_hole;
    this->score = score;
    this->color = color;
    this->x_before_col = x_before_col;
    this->y_bofore_col = y_before_col;
}

double Ball::get_x() {
    return this->x;
}

double Ball::get_y() {
    return this->y;
}

void Ball::set_x(double value) {
    this->x = value;
}

void Ball::set_y(double value) {
    this->y = value;
}


int Ball::get_score() {
    return this->score;
}

string Ball::get_color() {
    return std::__cxx11::string(color);
}

double Ball::get_weight() {
    return weight;
}


void Ball::move() {
    double u = 0.05;

    if( this->x <= 0 || this->x >= 356 * 2 ){
        this->reverse_dx();
        //this->teta =  atan(( sin(this->teta)*this->dy )/ ( cos(this->teta)*this->dx ) ) ;

    }

    if( this->y <= 0 || this->y >= 177 * 2 ){
        this->reverse_dy();
        //this->teta =  atan(( sin(this->teta)*this->dy )/ ( cos(this->teta)*this->dx ) ) ;
    }

    this->x += this->dx*0.7  * this->speed * cos(this->teta) ;
    this->y += this->dy*0.7  * this->speed * sin(this->teta);
    if(this->speed >= u )
        this->speed = this->speed - u;
    else
        this->speed = 0;

}

void Ball::reverse_dx() {
    //if( this->dx > 0)
    this->dx = - this->dx;
}

void Ball::reverse_dy() {
    //if(this->dy > 0 )
    this->dy = - this->dy;
}

double Ball::get_speed() {
    return this->speed;
}

double Ball::get_dx() {
    return this->dx;
}

double Ball::get_dy() {
    return this->dy;
}

double Ball::get_teta() {
    return this->teta;
}

void Ball::set_dx(double value) {
    this->dx = value;
}

void Ball::set_dy(double value) {
    this->dy = value;
}

void Ball::set_teta(double value) {
    this->teta = value;
}

void Ball::set_speed(double value) {
    this->speed = value;
}

double Ball::make_Rad(double degree) {
    return (degree/180)*3.14;
}

bool Ball::check_in_hole() {
    return in_hole;
}

void Ball::set_in_hole(bool value) {
    this->in_hole = value;
}

void Ball::set_x_before_collide(double value) {
    this->x_before_col = value;
}

void Ball::set_y_before_collide(double value) {
    this->y_bofore_col = value;
}

double Ball::get_x_before_collide() {
    return this->x_before_col;
}

double Ball::get_y_before_collide() {
    return this->y_bofore_col;
}

