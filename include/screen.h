
#ifndef _SCREEN_SDL_H_
#define _SCREEN_SDL_H_

#if defined (_WIN32) || defined (_WIN64)
#ifndef SDL_MAIN_HANDLED
#define SDL_MAIN_HANDLED
#endif
#endif

#include <iostream>

#include <SDL.h>

#include "defines_sdl.h"

namespace afzm{

class Screen_SDL{
    public:

        Screen_SDL();
        //Screen_SDL(const Screen_SDL& other);

        ~Screen_SDL();

        void update();
        void blur();
        bool processEvents();
        void clear();

        void setPixel(unsigned int x, unsigned int y, uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue);
        unsigned int cartesianX2CoordX(double cartesian_x);
        unsigned int cartesianY2CoordY(double cartesian_y);

        SDL_Window* getWindow();
        SDL_Renderer* getRenderer();
        SDL_Texture* getTexture();
        uint32_t* getPixelBuffer();
        unsigned long getPixelBufferSize();

        void setWindow(SDL_Window* window_ptr);
        void setRenderer(SDL_Renderer* renderer_ptr);
        void setTexture(SDL_Texture* texture_ptr);
        void setPixelBuffer(uint32_t* buffer_ptr, unsigned long buffer_size);

    private:

        SDL_Window *window_;
        SDL_Renderer *renderer_;
        SDL_Texture *texture_;
        uint32_t *pixel_buffer_;
        uint32_t *blur_pixel_buffer_;
        unsigned long buffer_size_;

};

}

#endif //_SCREEN_SDL_H_