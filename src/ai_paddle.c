#include "ai_paddle.h"

bool ai_paddle_new(struct AI_Paddle **ai_paddle, SDL_Renderer *renderer) {
    *ai_paddle = calloc(1, sizeof(struct AI_Paddle));
    if (!*ai_paddle) {
        fprintf(stderr, "Error in calloc of new AI Paddle.\n");
        return false;
    }
    struct AI_Paddle *p = *ai_paddle;

    p->renderer = renderer;

    p->rect.x = WINDOW_WIDTH - PADDLE_WIDTH - PADDLE_HORIZONTAL_OFFSET;
    p->rect.y = (WINDOW_HEIGHT - PADDLE_HEIGHT) / 2;
    p->rect.w = PADDLE_WIDTH;
    p->rect.h = PADDLE_HEIGHT;
 
    return true;
}

void ai_paddle_free(struct AI_Paddle **ai_paddle) {
    if (*ai_paddle) {
        struct AI_Paddle *p = *ai_paddle;

        p->renderer = NULL;

        free(p);
        p = NULL;
        *ai_paddle = NULL;

        printf("Free AI Paddle.\n");
    }
}

void ai_paddle_update(struct AI_Paddle *p, SDL_FRect ball_rect) {
    float ball_center = ball_rect.y + ball_rect.h / 2;
    float paddle_center = p->rect.y + p->rect.h / 2;
    
    if (paddle_center > ball_center) {
        p->rect.y += -PADDLE_VEL;
    } else if (paddle_center < ball_center) {
        p->rect.y += PADDLE_VEL;
    }

    if (p->rect.y <= 0) {
        p->rect.y = 0;
    }
    if (p->rect.y + p->rect.h >= WINDOW_HEIGHT) {
        p->rect.y = WINDOW_HEIGHT - p->rect.h;
    }
}

void ai_paddle_draw(const struct AI_Paddle *p) {
    SDL_SetRenderDrawColor(p->renderer, 255, 255, 255, 255);
        
    SDL_RenderFillRect(p->renderer, &p->rect);
}
