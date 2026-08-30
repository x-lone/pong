#include "player_paddle.h"

bool player_paddle_new(struct Player_Paddle **player_paddle, SDL_Renderer *renderer) {
    *player_paddle = calloc(1, sizeof(struct Player_Paddle));
    if (!*player_paddle) {
        fprintf(stderr, "Error in calloc of new Player Paddle.\n");
        return false;
    }
    struct Player_Paddle *p = *player_paddle;

    p->renderer = renderer;

    p->rect.x = PADDLE_HORIZONTAL_OFFSET;
    p->rect.y = (WINDOW_HEIGHT - PADDLE_HEIGHT) / 2;
    p->rect.w = PADDLE_WIDTH;
    p->rect.h = PADDLE_HEIGHT;
    
    p->keystate = SDL_GetKeyboardState(NULL);

    return true;
}

void player_paddle_free(struct Player_Paddle **player_paddle) {
    if (*player_paddle) {
        struct Player_Paddle *p = *player_paddle;

        p->keystate = NULL;

        p->renderer = NULL;

        free(p);
        p = NULL;
        *player_paddle = NULL;

        printf("Free Player Paddle.\n");
    }
}

void player_paddle_update(struct Player_Paddle *p) {
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

void player_paddle_draw(const struct Player_Paddle *p) {
    SDL_SetRenderDrawColor(p->renderer, 255, 255, 255, 255);
        
    SDL_RenderFillRect(p->renderer, &p->rect);
}
