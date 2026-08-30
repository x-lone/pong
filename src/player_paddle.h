#ifndef PLAYER_PADDLE_H
#define PLAYER_PADDLE_H

#include "main.h"

struct Player_Paddle {
    SDL_Renderer *renderer;
    SDL_FRect rect;
    const bool *keystate;
};

bool player_paddle_new(struct Player_Paddle **player_paddle, SDL_Renderer *renderer);
void player_paddle_free(struct Player_Paddle **player_paddle);
void player_paddle_update(struct Player_Paddle *p);
void player_paddle_draw(const struct Player_Paddle *p);

#endif
