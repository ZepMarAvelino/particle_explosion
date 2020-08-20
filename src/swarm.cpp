#include "swarm.h"

namespace afzm{
Swarm::Swarm(/* args */): p_particles_(new Particle[NUMBER_PARTICLES]){
    for(unsigned int i = 0; i < NUMBER_PARTICLES; ++i){
        double speed = ((2.0 *(rand() / (double)RAND_MAX)) - 1) * 0.0001;
        double direction = (rand() / (double)RAND_MAX) * 3.1415;
        //p_particles_[i] = Particle(true, ((2.0 *(rand() / (double)RAND_MAX)) - 1) * 0.001, ((2.0 *(rand() / (double)RAND_MAX)) - 1) * 0.001, true, 0, 0, 0.0000001);
        //p_particles_[i] = Particle(0.0, 0.0, true, true, speed, direction, true, 0, 0, 0.000000001);
    }
    p_particles_[0] = Particle(0.35355, 0.35355, true, 0.02236, -0.02236, true, 0.0, 0.0, 0.001);
    p_particles_[1] = Particle(-0.35355, 0.35355, true, -0.02236, -0.02236, true, 0.0, 0.0, 0.001);
    p_particles_[2] = Particle(0.35355, -0.35355, true, 0.02236, 0.02236, true, 0.0, 0.0, 0.001);
    p_particles_[3] = Particle(-0.35355, -0.35355, true, -0.02236, 0.02236, true, 0.0, 0.0, 0.001);
}
Swarm::~Swarm(){
    delete [] p_particles_;
}

const Particle* const Swarm::getParticles(){
    return p_particles_;
}

void Swarm::drawParticles(Screen_SDL* const screen, uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue){
    for (unsigned int i = 0; i < NUMBER_PARTICLES; ++i){
        unsigned int x = screen->cartesianX2CoordX(p_particles_[i].getXCoord());
        unsigned int y = screen->cartesianY2CoordY(p_particles_[i].getYCoord());

        //std::cout << "X: " << x << "\tY: " << y << std::endl;


        screen->setPixel(x, y, alpha, red, green, blue);
        screen->setPixel(x, y-2, alpha, red, green, blue);
        screen->setPixel(x, y-1, alpha, red, green, blue);
        screen->setPixel(x, y+1, alpha, red, green, blue);
        screen->setPixel(x, y+2, alpha, red, green, blue);
        screen->setPixel(x-1, y-1, alpha, red, green, blue);
        screen->setPixel(x-1, y, alpha, red, green, blue);
        screen->setPixel(x-1, y+1, alpha, red, green, blue);
        screen->setPixel(x+1, y-1, alpha, red, green, blue);
        screen->setPixel(x+1, y, alpha, red, green, blue);
        screen->setPixel(x+1, y+1, alpha, red, green, blue);
        screen->setPixel(x+2, y, alpha, red, green, blue);
        screen->setPixel(x-2, y, alpha, red, green, blue);

    }

}
void Swarm::updateParticles(uint32_t interval){
    for(int j = 0; j < interval; j++){
        for(unsigned int i = 0; i < NUMBER_PARTICLES; ++i){
            p_particles_[i].update();
        }
    }
}

}