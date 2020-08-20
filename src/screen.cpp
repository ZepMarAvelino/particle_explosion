#include "screen.h"

namespace afzm{

Screen_SDL::Screen_SDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cerr << "SDL init failed." << std::endl;
        throw 1;
    }

    window_ = SDL_CreateWindow("Particle Fire Explosion", 
                            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                            SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window_ == NULL) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        throw 2;
    }

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_PRESENTVSYNC);
    if (renderer_ == NULL){
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window_);
        SDL_Quit();
        throw 3;
    }

    texture_ = SDL_CreateTexture(renderer_, SDL_PIXELFORMAT_ARGB8888, 
                                SDL_TEXTUREACCESS_STATIC,
                                SCREEN_WIDTH, SCREEN_HEIGHT);
    if (texture_ == NULL){
        std::cerr << "Failed to create Texture: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window_);
        SDL_DestroyRenderer(renderer_);
        SDL_Quit();
        throw 4;
    }

    buffer_size_ = (unsigned long)SCREEN_WIDTH * (unsigned long)SCREEN_HEIGHT;

    try{
        pixel_buffer_ = new uint32_t[buffer_size_];
    }
    catch(std::bad_alloc& ba){
        std::cerr << "Bad Alloc: " << ba.what() << std::endl;    
        SDL_DestroyTexture(texture_);
        SDL_DestroyRenderer(renderer_);
        SDL_DestroyWindow(window_);
        SDL_Quit();
        throw 5;
    }
    catch(std::exception& e){
        std::cerr << "Failed to allocate memory: " << e.what() << std::endl;    
        SDL_DestroyTexture(texture_);
        SDL_DestroyRenderer(renderer_);
        SDL_DestroyWindow(window_);
        SDL_Quit();
        throw 5;
    }
    blur_pixel_buffer_ = NULL;
}

Screen_SDL::~Screen_SDL(){
    SDL_DestroyTexture(texture_);
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    delete [] pixel_buffer_;
    delete [] blur_pixel_buffer_;
    SDL_Quit();
}


void Screen_SDL::update(){
    SDL_UpdateTexture(texture_, NULL, pixel_buffer_, SCREEN_WIDTH*sizeof(uint32_t));
    SDL_RenderClear(renderer_);
    SDL_RenderCopy(renderer_, texture_, NULL, NULL);
    SDL_RenderPresent(renderer_);
}

void Screen_SDL::blur(){
    if(blur_pixel_buffer_ == NULL){
        try{
            blur_pixel_buffer_ = new uint32_t[buffer_size_];
        }
        catch(std::exception& e){
            std::cerr << "Failed to allocate memory: " << e.what() << std::endl;   
            return;
        }
    }
    uint32_t* swapPointer = pixel_buffer_;
    pixel_buffer_ = blur_pixel_buffer_;
    blur_pixel_buffer_ = swapPointer;
    swapPointer = NULL;

    uint32_t** pixel_double_pointer = new uint32_t*[SCREEN_HEIGHT];
    uint32_t** blur_double_pointer = new uint32_t*[SCREEN_HEIGHT];
    int x = 0;
    for(int y = 0; y < SCREEN_HEIGHT; y++, x+=SCREEN_WIDTH){
        pixel_double_pointer[y] = pixel_buffer_ + x;
        blur_double_pointer[y] = blur_pixel_buffer_ + x;
    }

    for(x = 0; x < SCREEN_WIDTH; x++){
        for(int y = 0; y < SCREEN_HEIGHT; y++){
            uint16_t red = 0;
            uint16_t green = 0;
            uint16_t blue = 0;
            uint32_t rgb = 0;
            int valid_pixels = 0;
            for(int row = -1; row < 2; row++){
                for (int col = -1; col < 2; col++){
                    int row_coord = x + row;
                    int col_coord = y + col;
                    if( (row_coord >= 0) && (row_coord < SCREEN_WIDTH) && (col_coord >= 0) && (col_coord < SCREEN_HEIGHT)){
                        rgb = blur_double_pointer[col_coord][row_coord];
                        blue += static_cast<uint16_t>(rgb & 0x000000FF);
                        rgb >>= 8;
                        green += static_cast<uint16_t>(rgb & 0x000000FF);
                        rgb >>= 8;
                        red += static_cast<uint16_t>(rgb & 0x000000FF);
                        valid_pixels++;
                    }
                }
            }
            red /= valid_pixels;
            green /= valid_pixels;
            blue /= valid_pixels;
            pixel_double_pointer[y][x] = 0xFF;
            pixel_double_pointer[y][x] <<= 8;
            pixel_double_pointer[y][x] += red;
            pixel_double_pointer[y][x] <<= 8;
            pixel_double_pointer[y][x] += green;
            pixel_double_pointer[y][x] <<= 8;
            pixel_double_pointer[y][x] += blue;
            // std::cout << "X: " << x << "\tY: " << y << "\npixel_buffer address: " << &(pixel_buffer_[x + (y * SCREEN_WIDTH)]) << "\tdouble pointer address: " << &(pixel_double_pointer[y][x]) << std::endl;
            // std::cout << "X: " << x << "\tY: " << y << "\nblur_buffer address: " << &(blur_pixel_buffer_[x + (y * SCREEN_WIDTH)]) << "\tdouble pointer address: " << &(blur_double_pointer[y][x]) << std::endl;
        }
    }
}

bool Screen_SDL::processEvents(){
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            std::cout << "Quit clicked" << std::endl;
            return false;
        }
    }
    return true;
}

void Screen_SDL::clear(){
    //Set all pixels to black
    memset(pixel_buffer_, 0, buffer_size_*sizeof(uint32_t));
}

void Screen_SDL::setPixel(unsigned int x, unsigned int y, uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue){
    if(x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT){
        return;
    }
    unsigned long pixel_coord = x + (y * SCREEN_WIDTH);

    pixel_buffer_[pixel_coord] = (uint32_t)alpha;
    pixel_buffer_[pixel_coord] <<= 8;
    pixel_buffer_[pixel_coord] += red;
    pixel_buffer_[pixel_coord] <<= 8;
    pixel_buffer_[pixel_coord] += green;
    pixel_buffer_[pixel_coord] <<= 8;
    pixel_buffer_[pixel_coord] += blue;

}

unsigned int Screen_SDL::cartesianX2CoordX(double cartesian_x){
    if(SCREEN_HEIGHT < SCREEN_WIDTH){
        return static_cast<unsigned int>(((((cartesian_x) * (SCREEN_HEIGHT - 1)) / 2.0) + 0.5) + SCREEN_WIDTH_HALF);
    }
    else{
        return static_cast<unsigned int>((((1.0 + cartesian_x) * (SCREEN_WIDTH - 1)) / 2.0) + 0.5);
    }
}

unsigned int Screen_SDL::cartesianY2CoordY(double cartesian_y){    
    if(SCREEN_WIDTH < SCREEN_HEIGHT){
        return static_cast<unsigned int>(((((cartesian_y) * (-SCREEN_WIDTH - 1)) / 2.0) - 0.5) + SCREEN_HEIGHT_HALF);
    }
    else{
        return static_cast<unsigned int>(((((cartesian_y - 1.0) * (SCREEN_HEIGHT - 1)) / 2.0) + 0.5) + SCREEN_HEIGHT);
    }
}


SDL_Window* Screen_SDL::getWindow(){
    return window_;
}

SDL_Renderer* Screen_SDL::getRenderer(){
    return renderer_;
}

SDL_Texture* Screen_SDL::getTexture(){
    return texture_;
}

uint32_t* Screen_SDL::getPixelBuffer(){
    return pixel_buffer_;
}

unsigned long Screen_SDL::getPixelBufferSize(){
    return buffer_size_;
}


void Screen_SDL::setWindow(SDL_Window* window_ptr){
    window_ = window_ptr;
}

void Screen_SDL::setRenderer(SDL_Renderer* renderer_ptr){
    renderer_ = renderer_ptr;
}

void Screen_SDL::setTexture(SDL_Texture* texture_ptr){
    texture_ = texture_ptr;
}

void Screen_SDL::setPixelBuffer(uint32_t* buffer_ptr, unsigned long new_buffer_size){
    pixel_buffer_ = buffer_ptr;
    buffer_size_ = new_buffer_size;
}

}