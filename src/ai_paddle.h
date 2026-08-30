#ifndef AI_PADDLE_H
#define AI_PADDLE_H

#include "main.h"

struct AI_Paddle {
    SDL_Renderer *renderer;
    SDL_FRect rect;
};

bool ai_paddle_new(struct AI_Paddle **ai_paddle, SDL_Renderer *renderer);
void ai_paddle_free(struct AI_Paddle **ai_paddle);
void ai_paddle_update(struct AI_Paddle *p, SDL_FRect ball_rect);
void ai_paddle_draw(const struct AI_Paddle *p);

#endif
