#ifndef SCORE
#define SCORE

#include "main.h"

struct Score {
    SDL_Renderer *renderer;
    SDL_Texture *image;
    SDL_FRect *src_rects;
    unsigned digits[2];
    unsigned score;
};

bool score_new(struct Score **score, SDL_Renderer *renderer);
void score_free(struct Score **score);
void score_increment(struct Score *s);
void score_draw(const struct Score *s, float x, float y);

#endif
