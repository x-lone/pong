#ifndef PADDLE_H
#define PADDLE_H

#include "main.h"

struct Paddle {
    SDL_Renderer *renderer;
    SDL_FRect rect;
    const bool *keystate;
};

bool paddle_new(struct Paddle **paddle, SDL_Renderer *renderer);
void paddle_free(struct Paddle **paddle);
SDL_FRect paddle_get_rect(const struct Paddle *p);
void paddle_update(struct Paddle *p);
void paddle_draw(const struct Paddle *p);

#endif
