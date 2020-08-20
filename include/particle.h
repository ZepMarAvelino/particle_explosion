#ifndef _PARTICLE_SDL_H_
#define _PARTICLE_SDL_H_

#include <cmath>
#include <cstdlib>
#include <iostream>

namespace afzm{
    class Particle
    {
    public:

        /**
         * @brief Construct a new Particle object with no movement or rotation axis.
         * The particle is created pseudo-randomly within a cartesian plane of -1 to 1.
         */
        Particle();
        /**
         * @brief Construct a new Particle object with no movement or rotation axis.
         * The particle is created pseudo-randomly within a cartesian plane of -locationLimiter to +locationLimiter.
         * 
         * @param location_limiter Multiplier of the pseudo-random generated location of the particle. Limit -1 to 1.
         */
        Particle(double location_limiter);
        /**
         * @brief Construct a new Particle object with equal velocity on the x and y axis. No rotation axis.
         * The particle is created pseudo-randomly within a cartesian plane of -locationLimiter to +locationLimiter.
         * 
         * @param location_limiter Multiplier of the pseudo-random generated location of the particle. Limit -1 to 1.
         * @param movement_flag True: Particles with move at the indicated velocity. False: No movement
         * @param velocity Velocity of the particle. Assigns same X and Y velocity. Limit -1 to 1.
         */
        Particle(double location_limiter, bool movement_flag, double velocity);
        /**
         * @brief Construct a new Particle object
         * 
         * @param location_limiter Multiplier of the pseudo-random generated location of the particle. Limit -1 to 1.
         * @param movement_flag True: Particles with move at the indicated velocity. False: No movement
         * @param vel_x Velocity of the particle in the X axis. Limit -1 to 1.
         * @param vel_y Velocity of the particle in the Y axis. Limit -1 to 1.
         */
        Particle(double location_limiter, bool movement_flag, double vel_x, double vel_y);
        /**
         * @brief Construct a new Particle object
         * 
         * @param location_limiter Multiplier of the pseudo-random generated location of the particle. Limit -1 to 1.
         * @param movement_flag True: Particles with move at the indicated velocity. False: No movement
         * @param vel_x Velocity of the particle in the X axis. Limit -1 to 1.
         * @param vel_y Velocity of the particle in the Y axis. Limit -1 to 1.
         * @param rotation_axis_flag True: Rotation axis will be active, gravitational pull will be assigned. False: No gravitational pull.
         * @param rotation_axis_x X coordinate of the gravitational pull. Limit -1 to 1.
         * @param rotation_axis_y Y coordinate of the gravitational pull. Limit -1 to 1.
         * @param rotation_axis_strength Acceleration effect on the particle from the gravitational pull
         */
        Particle(double location_limiter, bool movement_flag, double vel_x, double vel_y, 
                bool rotation_axis_flag, double rotation_axis_x, double rotation_axis_y, double rotation_axis_strength);
        /**
         * @brief Construct a new Particle object
         * 
         * @param location_limiter 
         * @param movement_flag 
         * @param polar_velocity 
         * @param speed 
         * @param direction 
         */
        Particle(double location_limiter, bool movement_flag, bool polar_velocity, double speed, double direction);
        /**
         * @brief Construct a new Particle object
         * 
         * @param location_limiter 
         * @param movement_flag 
         * @param polar_velocity 
         * @param speed 
         * @param direction 
         * @param rotation_axis_flag 
         * @param rotation_axis_x 
         * @param rotation_axis_y 
         * @param rotation_axis_strength 
         */
        Particle(double location_limiter, bool movement_flag, bool polar_velocity, double speed, double direction, 
                        bool rotation_axis_flag, double rotation_axis_x, double rotation_axis_y, double rotation_axis_strength);
        /**
         * @brief Construct a new Particle object
         * 
         * @param location_limiter Multiplier of the pseudo-random generated location of the particle. Limit -1 to 1.
         * @param rotation_axis_flag True: Rotation axis will be active, gravitational pull will be assigned. False: No gravitational pull.
         * @param rotation_axis_x X coordinate of the gravitational pull. Limit -1 to 1.
         * @param rotation_axis_y Y coordinate of the gravitational pull. Limit -1 to 1.
         * @param rotation_axis_strength Acceleration effect on the particle from the gravitational pull
         */
        Particle(double location_limiter, bool rotation_axis_flag, double rotation_axis_x, 
                double rotation_axis_y, double rotation_axis_strength);
        /**
         * @brief Construct a new Particle object
         * 
         * @param location_limiter Multiplier of the pseudo-random generated location of the particle. Limit -1 to 1.
         * @param movement_flag True: Particles with move at the indicated velocity. False: No movement
         * @param rotation_axis_flag True: Rotation axis will be active, gravitational pull will be assigned. False: No gravitational pull.
         * @param rotation_axis_x X coordinate of the gravitational pull. Limit -1 to 1.
         * @param rotation_axis_y Y coordinate of the gravitational pull. Limit -1 to 1.
         * @param rotation_axis_strength Acceleration effect on the particle from the gravitational pull
         */
        Particle(double location_limiter, bool movement_flag, bool rotation_axis_flag, 
                double rotation_axis_x, double rotation_axis_y, double rotation_axis_strength);
        /**
         * @brief Construct a new Particle object
         * 
         * @param movement_flag True: Particles with move at the indicated velocity. False: No movement
         * @param velocity Velocity of the particle. Assigns same X and Y velocity. Limit -1 to 1.
         */
        Particle(bool movement_flag, double velocity);
        /**
         * @brief Construct a new Particle object
         * 
         * @param movement_flag True: Particles with move at the indicated velocity. False: No movement
         * @param vel_x Velocity of the particle in the X axis. Limit -1 to 1.
         * @param vel_y Velocity of the particle in the Y axis. Limit -1 to 1.
         */
        Particle(bool movement_flag, double vel_x, double vel_y);
        /**
         * @brief Construct a new Particle object
         * 
         * @param movement_flag True: Particles with move at the indicated velocity. False: No movement
         * @param vel_x Velocity of the particle in the X axis. Limit -1 to 1.
         * @param vel_y Velocity of the particle in the Y axis. Limit -1 to 1.
         * @param rotation_axis_flag True: Rotation axis will be active, gravitational pull will be assigned. False: No gravitational pull.
         * @param rotation_axis_x X coordinate of the gravitational pull. Limit -1 to 1.
         * @param rotation_axis_y Y coordinate of the gravitational pull. Limit -1 to 1.
         * @param rotation_axis_strength Acceleration effect on the particle from the gravitational pull
         */
        Particle(bool movement_flag, double vel_x, double vel_y, bool rotation_axis_flag, 
                double rotation_axis_x, double rotation_axis_y, double rotation_axis_strength);
        /**
         * @brief Construct a new Particle object
         * 
         * @param movement_flag 
         * @param polar_velocity 
         * @param speed 
         * @param direction 
         */
        Particle(bool movement_flag, bool polar_velocity, double speed, double direction);
        /**
         * @brief Construct a new Particle object
         * 
         * @param movement_flag True: Particles with move at the indicated velocity. False: No movement
         * @param polar_velocity 
         * @param speed 
         * @param direction 
         * @param rotation_axis_flag True: Rotation axis will be active, gravitational pull will be assigned. False: No gravitational pull.
         * @param rotation_axis_x X coordinate of the gravitational pull. Limit -1 to 1.
         * @param rotation_axis_y Y coordinate of the gravitational pull. Limit -1 to 1.
         * @param rotation_axis_strength Acceleration effect on the particle from the gravitational pull
         */
        Particle(bool movement_flag, bool polar_velocity, double speed, double direction, bool rotation_axis_flag, 
                double rotation_axis_x, double rotation_axis_y, double rotation_axis_strength);
        /**
         * @brief Construct a new Particle object
         * 
         * @param rotation_axis_flag True: Rotation axis will be active, gravitational pull will be assigned. False: No gravitational pull.
         * @param rotation_axis_x X coordinate of the gravitational pull. Limit -1 to 1.
         * @param rotation_axis_y Y coordinate of the gravitational pull. Limit -1 to 1.
         * @param rotation_axis_strength Acceleration effect on the particle from the gravitational pull
         */
        Particle(bool rotation_axis_flag, double rotation_axis_x, double rotation_axis_y, double rotation_axis_strength);
        /**
         * @brief Construct a new Particle object
         * 
         * @param movement_flag True: Particles with move at the indicated velocity. False: No movement
         * @param rotation_axis_flag True: Rotation axis will be active, gravitational pull will be assigned. False: No gravitational pull.
         * @param rotation_axis_x X coordinate of the gravitational pull. Limit -1 to 1.
         * @param rotation_axis_y Y coordinate of the gravitational pull. Limit -1 to 1.
         * @param rotation_axis_strength Acceleration effect on the particle from the gravitational pull
         */
        Particle(bool movement_flag, bool rotation_axis_flag, double rotation_axis_x, 
                double rotation_axis_y, double rotation_axis_strength);
        /**
         * @brief Construct a new Particle object
         * 
         * @param x_coord X coordinates of particle in a cartesian plane. Limit -1 to 1.
         * @param y_coord Y coordinates of particle in a cartesian plane. Limit -1 to 1.
         */
        Particle(double x_coord, double y_coord);
        /**
         * @brief Construct a new Particle object
         * 
         * @param x_coord X coordinates of particle in a cartesian plane. Limit -1 to 1.
         * @param y_coord Y coordinates of particle in a cartesian plane. Limit -1 to 1.
         * @param movement_flag True: Particles with move at the indicated velocity. False: No movement
         * @param velocity Velocity of the particle. Assigns same X and Y velocity. Limit -1 to 1.
         */
        Particle(double x_coord, double y_coord, bool movement_flag, double velocity);
        /**
         * @brief Construct a new Particle object
         * 
         * @param x_coord X coordinates of particle in a cartesian plane. Limit -1 to 1.
         * @param y_coord Y coordinates of particle in a cartesian plane. Limit -1 to 1.
         * @param movement_flag True: Particles with move at the indicated velocity. False: No movement
         * @param vel_x Velocity of the particle in the X axis. Limit -1 to 1.
         * @param vel_y Velocity of the particle in the Y axis. Limit -1 to 1.
         */
        Particle(double x_coord, double y_coord, bool movement_flag, double vel_x, double vel_y);
        /**
         * @brief Construct a new Particle object
         * 
         * @param x_coord X coordinates of particle in a cartesian plane. Limit -1 to 1.
         * @param y_coord Y coordinates of particle in a cartesian plane. Limit -1 to 1.
         * @param movement_flag True: Particles with move at the indicated velocity. False: No movement
         * @param vel_x Velocity of the particle in the X axis. Limit -1 to 1.
         * @param vel_y Velocity of the particle in the Y axis. Limit -1 to 1.
         * @param rotation_axis_flag True: Rotation axis will be active, gravitational pull will be assigned. False: No gravitational pull.
         * @param rotation_axis_x X coordinate of the gravitational pull. Limit -1 to 1.
         * @param rotation_axis_y Y coordinate of the gravitational pull. Limit -1 to 1.
         * @param rotation_axis_strength Acceleration effect on the particle from the gravitational pull
         */
        Particle(double x_coord, double y_coord, bool movement_flag, double vel_x, double vel_y, bool rotation_axis_flag, 
                double rotation_axis_x, double rotation_axis_y, double rotation_axis_strength);
        /**
         * @brief Construct a new Particle object
         * 
         * @param x_coord 
         * @param y_coord 
         * @param movement_flag 
         * @param polar_velocity 
         * @param speed 
         * @param direction 
         */
        Particle(double x_coord, double y_coord, bool movement_flag, bool polar_velocity, double speed, double direction);
        /**
         * @brief Construct a new Particle object
         * 
         * @param x_coord 
         * @param y_coord 
         * @param movement_flag 
         * @param polar_velocity 
         * @param speed 
         * @param direction 
         * @param rotation_axis_flag 
         * @param rotation_axis_x 
         * @param rotation_axis_y 
         * @param rotation_axis_strength 
         */
        Particle(double x_coord, double y_coord, bool movement_flag, bool polar_velocity, double speed, double direction, 
                        bool rotation_axis_flag, double rotation_axis_x, double rotation_axis_y, double rotation_axis_strength);
        /**
         * @brief Construct a new Particle object
         * 
         * @param x_coord X coordinates of particle in a cartesian plane. Limit -1 to 1.
         * @param y_coord Y coordinates of particle in a cartesian plane. Limit -1 to 1.
         * @param rotation_axis_flag True: Rotation axis will be active, gravitational pull will be assigned. False: No gravitational pull.
         * @param rotation_axis_x X coordinate of the gravitational pull. Limit -1 to 1.
         * @param rotation_axis_y Y coordinate of the gravitational pull. Limit -1 to 1.
         * @param rotation_axis_strength Acceleration effect on the particle from the gravitational pull
         */
        Particle(double x_coord, double y_coord, bool rotation_axis_flag, double rotation_axis_x, double rotation_axis_y, double rotation_axis_strength);
        /**
         * @brief Construct a new Particle object
         * 
         * @param x_coord X coordinates of particle in a cartesian plane. Limit -1 to 1.
         * @param y_coord Y coordinates of particle in a cartesian plane. Limit -1 to 1.
         * @param movement_flag True: Particles with move at the indicated velocity. False: No movement
         * @param rotation_axis_flag True: Rotation axis will be active, gravitational pull will be assigned. False: No gravitational pull.
         * @param rotation_axis_x X coordinate of the gravitational pull. Limit -1 to 1.
         * @param rotation_axis_y Y coordinate of the gravitational pull. Limit -1 to 1.
         * @param rotation_axis_strength Acceleration effect on the particle from the gravitational pull
         */
        Particle(double x_coord, double y_coord, bool movement_flag, bool rotation_axis_flag, double rotation_axis_x, 
                double rotation_axis_y, double rotation_axis_strength);

        /**
         * @brief Destroy the Particle object
         * 
         */
        ~Particle();

        /**
         * @brief 
         * 
         */
        void update();


        /**
         * @brief 
         * 
         * @return double 
         */
        double getXCoord();
        /**
         * @brief 
         * 
         * @return double 
         */
        double getYCoord();

        /**
         * @brief 
         * 
         * @param x 
         */
        void setXCoord(double x);
        /**
         * @brief 
         * 
         * @param y 
         */
        void setYCoord(double y);
        /**
         * @brief Set the Coord object
         * 
         * @param x 
         * @param y 
         */
        void setCoord(double x, double y);

        /**
         * @brief 
         * 
         * @return double 
         */
        double getXVel();
        /**
         * @brief 
         * 
         * @return double 
         */
        double getYVel();
        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        bool isMoving();

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        bool hasRotationAxis();
        /**
         * @brief Get the Rotation Axis X Coord object
         * 
         * @return double 
         */
        double getRotationAxisXCoord();
        /**
         * @brief Get the Rotation Axis Y Coord object
         * 
         * @return double 
         */
        double getRotationAxisYCoord();
        /**
         * @brief Get the Rotation Axis Strength object
         * 
         * @return double 
         */
        double getRotationAxisStrength();

        /**
         * @brief Get the Distance To Rotation Axis X object
         * 
         * @return double 
         */
        double getDistanceToRotationAxisX();
        /**
         * @brief Get the Distance To Rotation Axis Y object
         * 
         * @return double 
         */
        double getDistanceToRotationAxisY();
        /**
         * @brief Get the Distance To Rotation Axis object
         * 
         * @return double 
         */
        double getDistanceToRotationAxis();
        /**
         * @brief Get the Distance To Rotation Axis object
         * 
         * @param relative_x_distance 
         * @param relative_y_distance 
         * @return double 
         */
        double getDistanceToRotationAxis(double relative_x_distance, double relative_y_distance);

        /**
         * @brief 
         * 
         * @param new_x_vel 
         */
        void setXVel(double new_x_vel);
        /**
         * @brief 
         * 
         * @param new_y_vel 
         */
        void setYVel(double new_y_vel);
        /**
         * @brief Set the Movement object
         * 
         * @param movement_active 
         */
        void setMovement(bool movement_active);

        /**
         * @brief Set the Rotation Axis object
         * 
         * @param axis_active 
         */
        void setRotationAxis(bool axis_active);
        /**
         * @brief Set the Rotation Axis object
         * 
         * @param new_x_axis_coord 
         * @param new_y_axis_coord 
         */
        void setRotationAxis(double new_x_axis_coord, double new_y_axis_coord);
        /**
         * @brief Set the Rotation Axis object
         * 
         * @param new_x_axis_coord 
         * @param new_y_axis_coord 
         * @param new_axis_strength 
         */
        void setRotationAxis(double new_x_axis_coord, double new_y_axis_coord, double new_axis_strength);
        /**
         * @brief Set the Rotation Axis object
         * 
         * @param axis_active 
         * @param new_x_axis_coord 
         * @param new_y_axis_coord 
         */
        void setRotationAxis(bool axis_active, double new_x_axis_coord, double new_y_axis_coord);
        /**
         * @brief Set the Rotation Axis object
         * 
         * @param axis_active 
         * @param new_x_axis_coord 
         * @param new_y_axis_coord 
         * @param new_axis_strength 
         */
        void setRotationAxis(bool axis_active, double new_x_axis_coord, double new_y_axis_coord, double new_axis_strength);
        /**
         * @brief Set the Rotation Strength object
         * 
         * @param new_axis_strength 
         */
        void setRotationStrength(double new_axis_strength);

    private:
        double x_coord_;
        double y_coord_;

        bool movement_flag_;
        double x_vel_;
        double y_vel_;

        bool rotation_axis_flag_;
        double rotation_axis_x_;
        double rotation_axis_y_;
        double rotation_axis_strength_;


        double rotationAxisAcceleration();
        double rotationAxisAcceleration(double relative_distance);
        double rotationAxisAcceleration(double relative_x_distance, double relative_y_distance);
        /**
         * @brief 
         * 
         * @return double 
         */
        double rotationAxisAccelerationX();
        /**
         * @brief 
         * 
         * @param distance_to_axis 
         * @param relative_x_distance 
         * @return double 
         */
        double rotationAxisAccelerationX(double distance_to_axis, double relative_x_distance);
        /**
         * @brief 
         * 
         * @param distance_to_axis 
         * @param relative_x_distance 
         * @param acceleration 
         * @return double 
         */
        double rotationAxisAccelerationX(double distance_to_axis, double relative_x_distance, double acceleration);
        /**
         * @brief 
         * 
         * @return double 
         */
        double rotationAxisAccelerationY();
        /**
         * @brief 
         * 
         * @param distance_to_axis 
         * @param relative_y_distance 
         * @return double 
         */
        double rotationAxisAccelerationY(double distance_to_axis, double relative_y_distance);
        /**
         * @brief 
         * 
         * @param distance_to_axis 
         * @param relative_y_distance 
         * @param acceleration 
         * @return double 
         */
        double rotationAxisAccelerationY(double distance_to_axis, double relative_y_distance, double acceleration);
    };

}

#endif  //_PARTICLE_SDL_H_