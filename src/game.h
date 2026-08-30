#ifndef GAME_H
#define GAME_H

#include "main.h"
#include "ball.h"

struct Game {
    SDL_Window *window;
    SDL_Renderer *renderer;
    struct Ball *ball;
    SDL_Event event;
    bool is_running;
    bool is_playing;
};

bool game_new(struct Game **game);
void game_free(struct Game **game);
bool game_run(struct Game *g);

#endif
