#include "ball.h"

bool ball_new(struct Ball **ball, SDL_Renderer *renderer) {
    *ball = calloc(1, sizeof(struct Ball));
    if (!*ball) {
        fprintf(stderr, "Error in calloc of new Ball.\n");
        return false;
    }
    struct Ball *b = *ball;

    b->renderer = renderer;

    b->rect.w = BALL_SIZE;
    b->rect.h = BALL_SIZE;
    
    ball_reset(b);

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

void ball_reset(struct Ball *b) {
    b->rect.x = (WINDOW_WIDTH - BALL_SIZE) / 2;
    b->rect.y = (WINDOW_HEIGHT - BALL_SIZE) / 2;

    b->x_dir = (float) (rand() % 2 ? BALL_SERVE_SPEED : -BALL_SERVE_SPEED);
    b->y_dir = (float) (rand() % 2 ? BALL_SERVE_SPEED : -BALL_SERVE_SPEED);

    b->speed = 1.0f;

    b->spawn_delay = SPAWN_DELAY;
}

bool ball_in_goal(struct Ball *b) {
    if (b->rect.x + b->rect.w > WINDOW_WIDTH) {
        return true;
    } else if (b->rect.x < 0) {
        return true;
    }

    return false;
}

void ball_paddle_collision(struct Ball *b, SDL_FRect paddle_rect) {
    float ball_center = b->rect.y + b->rect.h / 2;
    float paddle_center = paddle_rect.y + paddle_rect.h / 2;
    float offset = ball_center - paddle_center;

    if (SDL_HasRectIntersectionFloat(&b->rect, &paddle_rect)) {
        b->x_dir = b->rect.x > WINDOW_WIDTH / BALL_SPEED ? -BALL_SPEED : BALL_SPEED;

        b->y_dir = offset / 5;

        if (b->y_dir > BALL_SPEED) {
            b->y_dir = BALL_SPEED;
        } else if (b->y_dir < -BALL_SPEED) {
            b->y_dir = -BALL_SPEED;
        }

        b->speed *= BALL_SPEED_MULTI;
    }
}

void ball_update(struct Ball *b) {
    if (b->spawn_delay > 0) {
        b->spawn_delay--;
        return;
    }

    b->rect.x += b->x_dir * b->speed;
    b->rect.y += b->y_dir * b->speed;
    
    if (b->rect.y + b->rect.h > WINDOW_HEIGHT - BORDER_THICKNESS) {
        b->y_dir = -fabsf(b->y_dir);
    } else if (b->rect.y < 0 + BORDER_THICKNESS) {
        b->y_dir = fabsf(b->y_dir);
    }
}

void ball_draw(const struct Ball *b) {
    SDL_SetRenderDrawColor(b->renderer, 255, 255, 255, 255);
        
    SDL_RenderFillRect(b->renderer, &b->rect);
}
