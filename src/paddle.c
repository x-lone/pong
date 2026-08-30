#include "paddle.h"

bool paddle_new(struct Paddle **paddle, SDL_Renderer *renderer) {
    *paddle = calloc(1, sizeof(struct Paddle));
    if (!*paddle) {
        fprintf(stderr, "Error in calloc of new Paddle.\n");
        return false;
    }
    struct Paddle *p = *paddle;

    p->renderer = renderer;

    p->rect.x = 10;
    p->rect.y = 10;
    p->rect.w = PADDLE_WIDTH;
    p->rect.h = PADDLE_HEIGHT;
    
    p->keystate = SDL_GetKeyboardState(NULL);

    return true;
}

void paddle_free(struct Paddle **paddle) {
    if (*paddle) {
        struct Paddle *p = *paddle;

        p->keystate = NULL;

        p->renderer = NULL;

        free(p);
        p = NULL;
        *paddle = NULL;

        printf("Free Paddle.\n");
    }
}

SDL_FRect paddle_get_rect(const struct Paddle *p) {return p->rect;}

void paddle_update(struct Paddle *p) {
    if (p->keystate[SDL_SCANCODE_UP] || p->keystate[SDL_SCANCODE_W]) {
        p->rect.y -= PADDLE_VEL;
    }
    if (p->keystate[SDL_SCANCODE_DOWN] || p->keystate[SDL_SCANCODE_S]) {
        p->rect.y += PADDLE_VEL;
    }

    if (p->rect.y <= 0) {
        p->rect.y = 0;
    }
    if (p->rect.y + p->rect.h >= WINDOW_HEIGHT) {
        p->rect.y = WINDOW_HEIGHT - p->rect.h;
    }
}

void paddle_draw(const struct Paddle *p) {
    SDL_SetRenderDrawColor(p->renderer, 255, 255, 255, 255);
        
    SDL_RenderFillRect(p->renderer, &p->rect);
}
