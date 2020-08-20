#ifndef _SWARM_SDL_H_
#define _SWARM_SDL_H_

#include "defines_sdl.h"
#include "particle.h"
#include "screen.h"


namespace afzm{
    class Swarm
    {
    public:
        Swarm(/* args */);
        ~Swarm();

        const Particle* const getParticles();

        void drawParticles(Screen_SDL* const screen, uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue);
        void updateParticles(uint32_t interval);

    private:
        Particle* const p_particles_;
    };

}

#endif  //_PARTICLE_SDL_H_