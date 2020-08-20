#include "particle.h"

namespace afzm{

    Particle::Particle(){
        x_coord_ = (2.0 *(rand() / (double)RAND_MAX)) - 1;
        y_coord_ = (2.0 *(rand() / (double)RAND_MAX)) - 1;

        movement_flag_ = false;
        x_vel_ = 0;
        y_vel_ = 0;

        rotation_axis_flag_ = false;
        rotation_axis_x_ = 0;
        rotation_axis_y_ = 0;
        rotation_axis_strength_ = 0;
    }

    Particle::Particle(double location_limiter){
        x_coord_ = ((2.0 *(rand() / (double)RAND_MAX)) - 1) * location_limiter;
        y_coord_ = ((2.0 *(rand() / (double)RAND_MAX)) - 1) * location_limiter;

        movement_flag_ = false;
        x_vel_ = 0;
        y_vel_ = 0;

        rotation_axis_flag_ = false;
        rotation_axis_x_ = 0;
        rotation_axis_y_ = 0;
        rotation_axis_strength_ = 0;
    }

    Particle::Particle(double location_limiter, bool movement_flag, double velocity){
        x_coord_ = ((2.0 *(rand() / (double)RAND_MAX)) - 1) * location_limiter;
        y_coord_ = ((2.0 *(rand() / (double)RAND_MAX)) - 1) * location_limiter;

        movement_flag_ = movement_flag;
        velocity = (velocity > 1) ? 1 : (velocity < -1 ? -1 : velocity);
        x_vel_ = velocity;
        y_vel_ = velocity;

        rotation_axis_flag_ = false;
        rotation_axis_x_ = 0;
        rotation_axis_y_ = 0;
        rotation_axis_strength_ = 0;
    }

    Particle::Particle(double location_limiter, bool movement_flag, double vel_x, double vel_y){
        x_coord_ = ((2.0 *(rand() / (double)RAND_MAX)) - 1) * location_limiter;
        y_coord_ = ((2.0 *(rand() / (double)RAND_MAX)) - 1) * location_limiter;

        movement_flag_ = movement_flag;
        
        x_vel_ = (vel_x > 1.0) ? 1.0 : (vel_x < -1.0 ? -1.0 : vel_x);
        y_vel_ = (vel_y > 1.0) ? 1.0 : (vel_y < -1.0 ? -1.0 : vel_y);

        rotation_axis_flag_ = false;
        rotation_axis_x_ = 0;
        rotation_axis_y_ = 0;
        rotation_axis_strength_ = 0;
    }

    Particle::Particle(double location_limiter, bool movement_flag, double vel_x, double vel_y, 
                        bool rotation_axis_flag, double rotation_axis_x, double rotation_axis_y, double rotation_axis_strength){
        x_coord_ = ((2.0 *(rand() / (double)RAND_MAX)) - 1) * location_limiter;
        y_coord_ = ((2.0 *(rand() / (double)RAND_MAX)) - 1) * location_limiter;

        movement_flag_ = movement_flag;
        x_vel_ = (vel_x > 1.0) ? 1.0 : (vel_x < -1.0 ? -1.0 : vel_x);
        y_vel_ = (vel_y > 1.0) ? 1.0 : (vel_y < -1.0 ? -1.0 : vel_y);

        rotation_axis_flag_ = rotation_axis_flag;
        rotation_axis_x_ = (rotation_axis_x > 1.0) ? 1.0 : (rotation_axis_x < -1.0 ? -1.0 : rotation_axis_x);
        rotation_axis_y_ = (rotation_axis_y > 1.0) ? 1.0 : (rotation_axis_y < -1.0 ? -1.0 : rotation_axis_y);
        rotation_axis_strength_ = rotation_axis_strength;
    }

    Particle::Particle(double location_limiter, bool movement_flag, bool polar_velocity, double velocity, double direction){
        x_coord_ = ((2.0 *(rand() / (double)RAND_MAX)) - 1) * location_limiter;
        y_coord_ = ((2.0 *(rand() / (double)RAND_MAX)) - 1) * location_limiter;

        movement_flag_ = movement_flag;
        x_vel_ = velocity * cos(direction);
        y_vel_ = velocity * sin(direction);

        rotation_axis_flag_ = false;
        rotation_axis_x_ = 0;
        rotation_axis_y_ = 0;
        rotation_axis_strength_ = 0;
    }

    Particle::Particle(double location_limiter, bool movement_flag, bool polar_velocity, double velocity, double direction, 
                        bool rotation_axis_flag, double rotation_axis_x, double rotation_axis_y, double rotation_axis_strength){
        x_coord_ = ((2.0 *(rand() / (double)RAND_MAX)) - 1) * location_limiter;
        y_coord_ = ((2.0 *(rand() / (double)RAND_MAX)) - 1) * location_limiter;

        movement_flag_ = movement_flag;
        x_vel_ = velocity * cos(direction);
        y_vel_ = velocity * sin(direction);

        rotation_axis_flag_ = rotation_axis_flag;
        rotation_axis_x_ = (rotation_axis_x > 1.0) ? 1.0 : (rotation_axis_x < -1.0 ? -1.0 : rotation_axis_x);
        rotation_axis_y_ = (rotation_axis_y > 1.0) ? 1.0 : (rotation_axis_y < -1.0 ? -1.0 : rotation_axis_y);
        rotation_axis_strength_ = rotation_axis_strength;
    }

    Particle::Particle(double location_limiter, bool rotation_axis_flag, double rotation_axis_x, 
                        double rotation_axis_y, double rotation_axis_strength){
        x_coord_ = ((2.0 *(rand() / (double)RAND_MAX)) - 1) * location_limiter;
        y_coord_ = ((2.0 *(rand() / (double)RAND_MAX)) - 1) * location_limiter;

        movement_flag_ = false;
        x_vel_ = 0;
        y_vel_ = 0;

        rotation_axis_flag_ = rotation_axis_flag;
        rotation_axis_x_ = (rotation_axis_x > 1.0) ? 1.0 : (rotation_axis_x < -1.0 ? -1.0 : rotation_axis_x);
        rotation_axis_y_ = (rotation_axis_y > 1.0) ? 1.0 : (rotation_axis_y < -1.0 ? -1.0 : rotation_axis_y);
        rotation_axis_strength_ = rotation_axis_strength;
    }

    Particle::Particle(double location_limiter, bool movement_flag, bool rotation_axis_flag, 
                        double rotation_axis_x, double rotation_axis_y, double rotation_axis_strength){
        x_coord_ = ((2.0 *(rand() / (double)RAND_MAX)) - 1) * location_limiter;
        y_coord_ = ((2.0 *(rand() / (double)RAND_MAX)) - 1) * location_limiter;

        movement_flag_ = movement_flag;
        x_vel_ = 0;
        y_vel_ = 0;

        rotation_axis_flag_ = rotation_axis_flag;
        rotation_axis_x_ = (rotation_axis_x > 1.0) ? 1.0 : (rotation_axis_x < -1.0 ? -1.0 : rotation_axis_x);
        rotation_axis_y_ = (rotation_axis_y > 1.0) ? 1.0 : (rotation_axis_y < -1.0 ? -1.0 : rotation_axis_y);
        rotation_axis_strength_ = rotation_axis_strength;
    }

    Particle::Particle(bool movement_flag, double velocity){
        x_coord_ = (2.0 *(rand() / (double)RAND_MAX)) - 1;
        y_coord_ = (2.0 *(rand() / (double)RAND_MAX)) - 1;

        movement_flag_ = movement_flag;
        velocity = (velocity > 1) ? 1 : (velocity < -1 ? -1 : velocity);
        x_vel_ = velocity;
        y_vel_ = velocity;

        rotation_axis_flag_ = false;
        rotation_axis_x_ = 0;
        rotation_axis_y_ = 0;
        rotation_axis_strength_ = 0;
    }

    Particle::Particle(bool movement_flag, double vel_x, double vel_y){
        x_coord_ = (2.0 *(rand() / (double)RAND_MAX)) - 1;
        y_coord_ = (2.0 *(rand() / (double)RAND_MAX)) - 1;

        movement_flag_ = movement_flag;
        x_vel_ = (vel_x > 1.0) ? 1.0 : (vel_x < -1.0 ? -1.0 : vel_x);
        y_vel_ = (vel_y > 1.0) ? 1.0 : (vel_y < -1.0 ? -1.0 : vel_y);

        rotation_axis_flag_ = false;
        rotation_axis_x_ = 0;
        rotation_axis_y_ = 0;
        rotation_axis_strength_ = 0;
    }

    Particle::Particle(bool movement_flag, double vel_x, double vel_y, bool rotation_axis_flag, 
                        double rotation_axis_x, double rotation_axis_y, double rotation_axis_strength){
        x_coord_ = (2.0 *(rand() / (double)RAND_MAX)) - 1;
        y_coord_ = (2.0 *(rand() / (double)RAND_MAX)) - 1;

        movement_flag_ = movement_flag;
        x_vel_ = (vel_x > 1.0) ? 1.0 : (vel_x < -1.0 ? -1.0 : vel_x);
        y_vel_ = (vel_y > 1.0) ? 1.0 : (vel_y < -1.0 ? -1.0 : vel_y);

        rotation_axis_flag_ = rotation_axis_flag;
        rotation_axis_x_ = (rotation_axis_x > 1.0) ? 1.0 : (rotation_axis_x < -1.0 ? -1.0 : rotation_axis_x);
        rotation_axis_y_ = (rotation_axis_y > 1.0) ? 1.0 : (rotation_axis_y < -1.0 ? -1.0 : rotation_axis_y);
        rotation_axis_strength_ = rotation_axis_strength;
    }

    Particle::Particle(bool movement_flag, bool polar_velocity, double velocity, double direction){
        x_coord_ = (2.0 *(rand() / (double)RAND_MAX)) - 1;
        y_coord_ = (2.0 *(rand() / (double)RAND_MAX)) - 1;

        movement_flag_ = movement_flag;
        x_vel_ = velocity * cos(direction);
        y_vel_ = velocity * sin(direction);

        rotation_axis_flag_ = false;
        rotation_axis_x_ = 0;
        rotation_axis_y_ = 0;
        rotation_axis_strength_ = 0;
    }

    Particle::Particle(bool movement_flag, bool polar_velocity, double velocity, double direction, bool rotation_axis_flag, 
                        double rotation_axis_x, double rotation_axis_y, double rotation_axis_strength){
        x_coord_ = (2.0 *(rand() / (double)RAND_MAX)) - 1;
        y_coord_ = (2.0 *(rand() / (double)RAND_MAX)) - 1;

        movement_flag_ = movement_flag;
        x_vel_ = velocity * cos(direction);
        y_vel_ = velocity * sin(direction);

        rotation_axis_flag_ = rotation_axis_flag;
        rotation_axis_x_ = (rotation_axis_x > 1.0) ? 1.0 : (rotation_axis_x < -1.0 ? -1.0 : rotation_axis_x);
        rotation_axis_y_ = (rotation_axis_y > 1.0) ? 1.0 : (rotation_axis_y < -1.0 ? -1.0 : rotation_axis_y);
        rotation_axis_strength_ = rotation_axis_strength;
    }

    Particle::Particle(bool rotation_axis_flag, double rotation_axis_x, double rotation_axis_y, double rotation_axis_strength){
        x_coord_ = (2.0 *(rand() / (double)RAND_MAX)) - 1;
        y_coord_ = (2.0 *(rand() / (double)RAND_MAX)) - 1;

        movement_flag_ = false;
        x_vel_ = 0;
        y_vel_ = 0;

        rotation_axis_flag_ = rotation_axis_flag;
        rotation_axis_x_ = (rotation_axis_x > 1.0) ? 1.0 : (rotation_axis_x < -1.0 ? -1.0 : rotation_axis_x);
        rotation_axis_y_ = (rotation_axis_y > 1.0) ? 1.0 : (rotation_axis_y < -1.0 ? -1.0 : rotation_axis_y);
        rotation_axis_strength_ = rotation_axis_strength;
    }

    Particle::Particle(bool movement_flag, bool rotation_axis_flag, double rotation_axis_x, 
                        double rotation_axis_y, double rotation_axis_strength){
        x_coord_ = (2.0 *(rand() / (double)RAND_MAX)) - 1;
        y_coord_ = (2.0 *(rand() / (double)RAND_MAX)) - 1;

        movement_flag_ = movement_flag;
        x_vel_ = 0;
        y_vel_ = 0;

        rotation_axis_flag_ = rotation_axis_flag;
        rotation_axis_x_ = (rotation_axis_x > 1.0) ? 1.0 : (rotation_axis_x < -1.0 ? -1.0 : rotation_axis_x);
        rotation_axis_y_ = (rotation_axis_y > 1.0) ? 1.0 : (rotation_axis_y < -1.0 ? -1.0 : rotation_axis_y);
        rotation_axis_strength_ = rotation_axis_strength;
    }

    Particle::Particle(double x_coord, double y_coord){
        x_coord_ = (x_coord > 1.0) ? 1.0 : (x_coord < -1.0 ? -1.0 : x_coord);
        y_coord_ = (y_coord > 1.0) ? 1.0 : (y_coord < -1.0 ? -1.0 : y_coord);

        movement_flag_ = false;
        x_vel_ = 0;
        y_vel_ = 0;

        rotation_axis_flag_ = false;
        rotation_axis_x_ = 0;
        rotation_axis_y_ = 0;
        rotation_axis_strength_ = 0;
    }

    Particle::Particle(double x_coord, double y_coord, bool movement_flag, double velocity){
        x_coord_ = (x_coord > 1.0) ? 1.0 : (x_coord < -1.0 ? -1.0 : x_coord);
        y_coord_ = (y_coord > 1.0) ? 1.0 : (y_coord < -1.0 ? -1.0 : y_coord);

        movement_flag_ = movement_flag;
        velocity = (velocity > 1) ? 1 : (velocity < -1 ? -1 : velocity);
        x_vel_ = velocity;
        y_vel_ = velocity;

        rotation_axis_flag_ = false;
        rotation_axis_x_ = 0;
        rotation_axis_y_ = 0;
        rotation_axis_strength_ = 0;
    }

    Particle::Particle(double x_coord, double y_coord, bool movement_flag, double vel_x, double vel_y){
        x_coord_ = (x_coord > 1.0) ? 1.0 : (x_coord < -1.0 ? -1.0 : x_coord);
        y_coord_ = (y_coord > 1.0) ? 1.0 : (y_coord < -1.0 ? -1.0 : y_coord);

        movement_flag_ = movement_flag;
        x_vel_ = (vel_x > 1.0) ? 1.0 : (vel_x < -1.0 ? -1.0 : vel_x);
        y_vel_ = (vel_y > 1.0) ? 1.0 : (vel_y < -1.0 ? -1.0 : vel_y);

        rotation_axis_flag_ = false;
        rotation_axis_x_ = 0;
        rotation_axis_y_ = 0;
        rotation_axis_strength_ = 0;
    }

    Particle::Particle(double x_coord, double y_coord, bool movement_flag, double vel_x, double vel_y, bool rotation_axis_flag, 
                        double rotation_axis_x, double rotation_axis_y, double rotation_axis_strength){
        x_coord_ = (x_coord > 1.0) ? 1 : (x_coord < -1 ? -1.0 : x_coord);
        y_coord_ = (y_coord > 1.0) ? 1 : (y_coord < -1 ? -1.0 : y_coord);

        movement_flag_ = movement_flag;
        x_vel_ = (vel_x > 1.0) ? 1.0 : (vel_x < -1.0 ? -1.0 : vel_x);
        y_vel_ = (vel_y > 1.0) ? 1.0 : (vel_y < -1.0 ? -1.0 : vel_y);

        rotation_axis_flag_ = rotation_axis_flag;
        rotation_axis_x_ = (rotation_axis_x > 1.0) ? 1.0 : (rotation_axis_x < -1.0 ? -1.0 : rotation_axis_x);
        rotation_axis_y_ = (rotation_axis_y > 1.0) ? 1.0 : (rotation_axis_y < -1.0 ? -1.0 : rotation_axis_y);
        rotation_axis_strength_ = rotation_axis_strength;
    }

    Particle::Particle(double x_coord, double y_coord, bool movement_flag, bool polar_velocity, double velocity, double direction){
        x_coord_ = (x_coord > 1.0) ? 1.0 : (x_coord < -1.0 ? -1.0 : x_coord);
        y_coord_ = (y_coord > 1.0) ? 1.0 : (y_coord < -1.0 ? -1.0 : y_coord);

        movement_flag_ = movement_flag;
        x_vel_ = velocity * cos(direction);
        y_vel_ = velocity * sin(direction);

        rotation_axis_flag_ = false;
        rotation_axis_x_ = 0;
        rotation_axis_y_ = 0;
        rotation_axis_strength_ = 0;
    }

    Particle::Particle(double x_coord, double y_coord, bool movement_flag, bool polar_velocity, double velocity, double direction, 
                        bool rotation_axis_flag, double rotation_axis_x, double rotation_axis_y, double rotation_axis_strength){
        x_coord_ = (x_coord > 1.0) ? 1 : (x_coord < -1 ? -1.0 : x_coord);
        y_coord_ = (y_coord > 1.0) ? 1 : (y_coord < -1 ? -1.0 : y_coord);

        movement_flag_ = movement_flag;
        x_vel_ = velocity * cos(direction);
        y_vel_ = velocity * sin(direction);

        rotation_axis_flag_ = rotation_axis_flag;
        rotation_axis_x_ = (rotation_axis_x > 1.0) ? 1.0 : (rotation_axis_x < -1.0 ? -1.0 : rotation_axis_x);
        rotation_axis_y_ = (rotation_axis_y > 1.0) ? 1.0 : (rotation_axis_y < -1.0 ? -1.0 : rotation_axis_y);
        rotation_axis_strength_ = rotation_axis_strength;
    }

    Particle::Particle(double x_coord, double y_coord, bool rotation_axis_flag, double rotation_axis_x, double rotation_axis_y, 
                        double rotation_axis_strength){
        x_coord_ = (x_coord > 1.0) ? 1 : (x_coord < -1 ? -1.0 : x_coord);
        y_coord_ = (y_coord > 1.0) ? 1 : (y_coord < -1 ? -1.0 : y_coord);

        movement_flag_ = false;
        x_vel_ = 0;
        y_vel_ = 0;

        rotation_axis_flag_ = rotation_axis_flag;
        rotation_axis_x_ = (rotation_axis_x > 1.0) ? 1.0 : (rotation_axis_x < -1.0 ? -1.0 : rotation_axis_x);
        rotation_axis_y_ = (rotation_axis_y > 1.0) ? 1.0 : (rotation_axis_y < -1.0 ? -1.0 : rotation_axis_y);
        rotation_axis_strength_ = rotation_axis_strength;
    }

    Particle::Particle(double x_coord, double y_coord, bool movement_flag, bool rotation_axis_flag, double rotation_axis_x, 
                        double rotation_axis_y, double rotation_axis_strength){
        x_coord_ = (x_coord > 1.0) ? 1 : (x_coord < -1 ? -1.0 : x_coord);
        y_coord_ = (y_coord > 1.0) ? 1 : (y_coord < -1 ? -1.0 : y_coord);

        movement_flag_ = movement_flag;
        x_vel_ = 0;
        y_vel_ = 0;

        rotation_axis_flag_ = rotation_axis_flag;
        rotation_axis_x_ = (rotation_axis_x > 1.0) ? 1.0 : (rotation_axis_x < -1.0 ? -1.0 : rotation_axis_x);
        rotation_axis_y_ = (rotation_axis_y > 1.0) ? 1.0 : (rotation_axis_y < -1.0 ? -1.0 : rotation_axis_y);
        rotation_axis_strength_ = rotation_axis_strength;
    }


    Particle::~Particle(){}


    void Particle::update(){
        //Get the change in position if there is movement.
        if(movement_flag_){
            x_coord_ += x_vel_;
            y_coord_ += y_vel_;
            //Get the change in velocity if there is a rotation axis
            if(rotation_axis_flag_){
                //Get the relative distance, plus the individual x and y distance (Trade passing variables for less mathematical calculations)
                double x_distance = getDistanceToRotationAxisX();
                double y_distance = getDistanceToRotationAxisY();
                double distance = getDistanceToRotationAxis(x_distance, y_distance);
                double acceleration = rotationAxisAcceleration(distance);
                acceleration = acceleration >= rotation_axis_strength_ ? rotation_axis_strength_ : (acceleration <= -rotation_axis_strength_ ? -rotation_axis_strength_ : acceleration);
                if(distance){
                    double x_vel_change = rotationAxisAccelerationX(distance, x_distance, acceleration);
                    x_vel_ -= x_vel_change;
                    double y_vel_change = rotationAxisAccelerationY(distance, y_distance, acceleration);
                    y_vel_ -= y_vel_change;
                }
                else{
                    movement_flag_ = false;
                }
            }
            if(x_coord_ > 2 || x_coord_ < -2 || y_coord_ > 2 || y_coord_ < -2){ 
                x_coord_ = 0;
                y_coord_ = 0;
            }
        }
    }

    double Particle::getXCoord(){ return x_coord_; }

    double Particle::getYCoord(){ return y_coord_; }


    void Particle::setXCoord(double x){
        x_coord_ = x;
    }

    void Particle::setYCoord(double y){
        y_coord_ = y;
    }

    void Particle::setCoord(double x, double y){
        x_coord_ = x;
        y_coord_ = y;
    }


    bool Particle::isMoving(){ return movement_flag_; }

    double Particle::getXVel(){ return x_vel_; }

    double Particle::getYVel(){ return y_vel_; }


    bool Particle::hasRotationAxis() { return rotation_axis_flag_; }

    double Particle::getRotationAxisXCoord() { return rotation_axis_x_; }

    double Particle::getRotationAxisYCoord() { return rotation_axis_y_; }


    double Particle::getDistanceToRotationAxisX(){ return x_coord_ - rotation_axis_x_; }

    double Particle::getDistanceToRotationAxisY(){ return y_coord_ - rotation_axis_y_; }
    
    double Particle::getDistanceToRotationAxis() { 
        double relative_x_distance = x_coord_ - rotation_axis_x_;
        double relative_y_distance = y_coord_ - rotation_axis_y_;
        return std::sqrt(std::pow(relative_x_distance, 2.0) + std::pow(relative_y_distance, 2.0)); 
    }

    double Particle::getDistanceToRotationAxis(double relative_x_distance, double relative_y_distance) { 
        return std::sqrt(std::pow(relative_x_distance, 2.0) + std::pow(relative_y_distance, 2.0)); 
    }


    void Particle::setXVel(double new_x_vel) { x_vel_ = new_x_vel; }

    void Particle::setYVel(double new_y_vel) { y_vel_ = new_y_vel; }

    void Particle::setMovement(bool movement_active) { movement_flag_ = movement_active; }


    void Particle::setRotationAxis(bool axis_active) { rotation_axis_flag_ = axis_active; }

    void Particle::setRotationAxis(double new_x_axis_coord, double new_y_axis_coord) {
        rotation_axis_x_ = new_x_axis_coord < -1 ? -1 : (new_x_axis_coord > 1 ? 1 : new_x_axis_coord);
        rotation_axis_y_ = new_y_axis_coord < -1 ? -1 : (new_y_axis_coord > 1 ? 1 : new_y_axis_coord);
    }

    void Particle::setRotationAxis(double new_x_axis_coord, double new_y_axis_coord, double new_axis_strength) {
        rotation_axis_x_ = new_x_axis_coord < -1 ? -1 : (new_x_axis_coord > 1 ? 1 : new_x_axis_coord);
        rotation_axis_y_ = new_y_axis_coord < -1 ? -1 : (new_y_axis_coord > 1 ? 1 : new_y_axis_coord);
        rotation_axis_strength_ = new_axis_strength;
    }

    void Particle::setRotationAxis(bool axis_active, double new_x_axis_coord, double new_y_axis_coord) {
        rotation_axis_flag_ = axis_active ? true : false;
        rotation_axis_x_ = new_x_axis_coord < -1 ? -1 : (new_x_axis_coord > 1 ? 1 : new_x_axis_coord);
        rotation_axis_y_ = new_y_axis_coord < -1 ? -1 : (new_y_axis_coord > 1 ? 1 : new_y_axis_coord);
    }

    void Particle::setRotationAxis(bool axis_active, double new_x_axis_coord, double new_y_axis_coord, double new_axis_strength) {
        rotation_axis_flag_ = axis_active ? true : false;
        rotation_axis_x_ = new_x_axis_coord < -1 ? -1 : (new_x_axis_coord > 1 ? 1 : new_x_axis_coord);
        rotation_axis_y_ = new_y_axis_coord < -1 ? -1 : (new_y_axis_coord > 1 ? 1 : new_y_axis_coord);
        rotation_axis_strength_ = new_axis_strength;
    }

    void Particle::setRotationStrength(double new_axis_strength){ rotation_axis_strength_ = new_axis_strength; }

    /************ PRIVATE *************/

    double Particle::rotationAxisAcceleration(){
        double relative_x_distance =  (x_coord_ - rotation_axis_x_);
        double relative_y_distance =  (y_coord_ - rotation_axis_y_);
        return rotation_axis_strength_ / ((relative_x_distance * relative_x_distance) + (relative_y_distance * relative_y_distance));
    }

    double Particle::rotationAxisAcceleration(double relative_distance){
        return rotation_axis_strength_ / (relative_distance * relative_distance);
    }

    double Particle::rotationAxisAcceleration(double relative_x_distance, double relative_y_distance){
        return rotation_axis_strength_ / ((relative_x_distance * relative_x_distance) + (relative_y_distance * relative_y_distance));
    }

    double Particle::rotationAxisAccelerationX(){
        double relative_x_distance =  (x_coord_ - rotation_axis_x_);
        double relative_y_distance =  (y_coord_ - rotation_axis_y_);
        double relative_distance = getDistanceToRotationAxis(relative_x_distance, relative_y_distance);
        double acceleration = rotationAxisAcceleration(relative_distance);
        return acceleration * (relative_x_distance / relative_distance);

        // if(rotation_axis_strength_ > 0){
        //     if(temp_accel > 0){
        //         return temp_accel > rotation_axis_strength_ ? rotation_axis_strength_ : temp_accel;
        //     }
        //     else if(temp_accel < 0){
        //         return temp_accel < -rotation_axis_strength_ ? -rotation_axis_strength_ : temp_accel;
        //     }
        // }        
        // else if(rotation_axis_strength_ < 0){
        //     if(temp_accel < 0){
        //         return temp_accel > rotation_axis_strength_ ? rotation_axis_strength_ : temp_accel;
        //     }
        //     else if (temp_accel > 0){
        //         return temp_accel < -rotation_axis_strength_ ? -rotation_axis_strength_ : temp_accel;
        //     }
        // }
        // return 0;
    }

    double Particle::rotationAxisAccelerationX(double distance_to_axis, double relative_x_distance){
        double acceleration = rotationAxisAcceleration(distance_to_axis);
        return acceleration * (relative_x_distance / distance_to_axis);
    }

    double Particle::rotationAxisAccelerationX(double distance_to_axis, double relative_x_distance, double acceleration){
        return acceleration * (relative_x_distance / distance_to_axis);
    }

    double Particle::rotationAxisAccelerationY(){
        double relative_x_distance =  (x_coord_ - rotation_axis_x_);
        double relative_y_distance =  (y_coord_ - rotation_axis_y_);
        double relative_distance = getDistanceToRotationAxis(relative_x_distance, relative_y_distance);
        double acceleration = rotationAxisAcceleration(relative_distance);
        return acceleration * (relative_y_distance / relative_distance);
    }

    double Particle::rotationAxisAccelerationY(double distance_to_axis, double relative_y_distance){
        double acceleration = rotationAxisAcceleration(distance_to_axis);
        return acceleration * (relative_y_distance / distance_to_axis);
    }

    double Particle::rotationAxisAccelerationY(double distance_to_axis, double relative_y_distance, double acceleration){
        return acceleration * (relative_y_distance / distance_to_axis);
    }

}
