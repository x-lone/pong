#ifndef BALL_H
#define BALL_H

#include "main.h"

struct Ball {
    SDL_Renderer *renderer;
    SDL_FRect rect;
    float x_dir;
    float y_dir;
    float speed;
    int spawn_delay;
};

bool ball_new(struct Ball **ball, SDL_Renderer *renderer);
void ball_free(struct Ball **ball);
void ball_reset(struct Ball *b);
bool ball_in_goal(struct Ball *b);
void ball_paddle_collision(struct Ball *b, const SDL_FRect paddle_rect);
void ball_update(struct Ball *b);
void ball_draw(const struct Ball *b);

#endif
