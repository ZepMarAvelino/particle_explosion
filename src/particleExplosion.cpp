#if defined (_WIN32) || defined (_WIN64)
#ifndef SDL_MAIN_HANDLED
#define SDL_MAIN_HANDLED
#endif
#endif

#include <iostream>
#include <cmath>
#include <chrono>

#include <SDL.h>

#include "particle.h"
#include "screen.h"
#include "swarm.h"

using namespace std;
using namespace afzm;


int main(int argc, char** argv){
    #if defined (_WIN32) || defined (_WIN64)
    SDL_SetMainReady();
    #endif
    
    srand(time(NULL));

    //Initialize objects mentioned above. If one of them fails, quit.
    Screen_SDL *screen;
    Swarm *swarm;

    try {
        screen = new Screen_SDL;
    }
    catch (int e){
        exit(EXIT_FAILURE);
    }

    try {
        swarm = new Swarm;
    }
    catch (exception e){
        cerr << "Failed to initialize Swarm: " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
    
    uint32_t lastCycle = SDL_GetTicks();

    while(true){
        //Draw particles
        //Check for messages/events
        //screen->clear();
        uint32_t ticks = SDL_GetTicks();
        double red_temp = 1 + sin(ticks * 0.0005) * 128;
        double green_temp = 1 + sin(ticks * 0.00025) * 128;
        double blue_temp = 1 + sin(ticks * 0.000125) * 128;

        uint8_t red = red_temp >= 256 ? 255u : (red_temp < 50u ? 50u : static_cast<uint8_t>(red_temp));
        uint8_t green = green_temp >= 256 ? 255u : (green_temp < 50u ? 50u : static_cast<uint8_t>(green_temp));
        uint8_t blue = blue_temp >= 256 ? 255u : (blue_temp < 50u ? 50u : static_cast<uint8_t>(blue_temp));

        // screen->setPixel(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 0xFF, 0xFF, 0xFF, 0xFF);
        // screen->setPixel((SCREEN_WIDTH/2) + 1, SCREEN_HEIGHT/2, 0xFF, 0xFF, 0xFF, 0xFF);
        // screen->setPixel(SCREEN_WIDTH/2, (SCREEN_HEIGHT/2) + 1, 0xFF, 0xFF, 0xFF, 0xFF);
        // screen->setPixel((SCREEN_WIDTH/2) - 1, SCREEN_HEIGHT/2, 0xFF, 0xFF, 0xFF, 0xFF);
        // screen->setPixel(SCREEN_WIDTH/2, (SCREEN_HEIGHT/2) - 1, 0xFF, 0xFF, 0xFF, 0xFF);
        
        swarm->updateParticles(ticks - lastCycle);
        swarm->drawParticles(screen, 0xFF, red, green, blue);
        
        screen->blur();
        screen->update();

        lastCycle = ticks;
        if(!screen->processEvents()){
            break;
        }
    }
    

    delete (screen);
    return 0;
}