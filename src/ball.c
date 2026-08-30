#include "ball.h"

bool ball_new(struct Ball **ball, SDL_Renderer *renderer) {
    *ball = calloc(1, sizeof(struct Ball));
    if (!*ball) {
        fprintf(stderr, "Error in calloc of new Ball.\n");
        return false;
    }
    struct Ball *b = *ball;

    b->renderer = renderer;

    b->rect.x = WINDOW_WIDTH / 2;
    b->rect.y = WINDOW_HEIGHT / 2;
    b->rect.w = BALL_SIZE;
    b->rect.h = BALL_SIZE;

    b->x_vel = BALL_VEL;
    b->y_vel = BALL_VEL;
    
    return true;
}

void ball_free(struct Ball **ball) {
    if (*ball) {
        struct Ball *b = *ball;

        b->renderer = NULL;

        free(b);
        b = NULL;
        *ball = NULL;

        printf("Free Ball.\n");
    }
}

void ball_paddle_collision(struct Ball *b, SDL_FRect paddle_rect) {
    float ball_center = b->rect.x + b->rect.w / 2;
    float window_midpoint = WINDOW_WIDTH / 2;

    if (SDL_HasRectIntersectionFloat(&b->rect, &paddle_rect)) {
        if (ball_center > window_midpoint) {
            b->x_vel = -BALL_VEL;
        } else if (ball_center < window_midpoint) { 
            b->x_vel = BALL_VEL;
        }
    }
}

void ball_update(struct Ball *b) {
    b->rect.x += b->x_vel;
    b->rect.y += b->y_vel;

    if (b->rect.x + b->rect.w > WINDOW_WIDTH) {
        b->x_vel = -BALL_VEL;
    } else if (b->rect.x < 0) {
        b->x_vel = BALL_VEL;
    }

    if (b->rect.y + b->rect.h > WINDOW_HEIGHT) {
        b->y_vel = -BALL_VEL;
    } else if (b->rect.y < 0) {
        b->y_vel = BALL_VEL;
    }
}

void ball_draw(const struct Ball *b) {
    SDL_SetRenderDrawColor(b->renderer, 255, 255, 255, 255);
        
    SDL_RenderFillRect(b->renderer, &b->rect);
}
