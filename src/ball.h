#ifndef BALL_H
#define BALL_H

#include "main.h"

struct Ball {
    SDL_Renderer *renderer;
    SDL_FRect rect;
    float x_vel;
    float y_vel;
};

bool ball_new(struct Ball **ball, SDL_Renderer *renderer);
void ball_free(struct Ball **ball);
void ball_update(struct Ball *b);
void ball_draw(const struct Ball *b);

#endif
