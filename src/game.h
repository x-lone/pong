#ifndef GAME_H
#define GAME_H

#include "main.h"
#include "ball.h"
#include "player_paddle.h"
#include "ai_paddle.h"

struct Game {
    SDL_Window *window;
    SDL_Renderer *renderer;
    struct Ball *ball;
    struct Player_Paddle *player_paddle;
    struct AI_Paddle *ai_paddle;
    SDL_Event event;
    bool is_running;
    bool is_playing;
};

bool game_new(struct Game **game);
void game_free(struct Game **game);
bool game_run(struct Game *g);

#endif
