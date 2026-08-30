#include "game.h"
#include "init_sdl.h"

bool game_events(struct Game *g);
void game_update(struct Game *g);
void game_draw(struct Game *g);

bool game_new(struct Game **game) {
    *game = calloc(1, sizeof(struct Game));
    if (*game == NULL) {
        fprintf(stderr, "Error in Calloc of New Game.\n");
        return false;
    }
    struct Game *g = *game;

    g->is_running = true;

    if (!game_init_sdl(g)) {
        return false;
    }

    if (!ball_new(&g->ball, g->renderer)) {
        return false;
    }

    if (!player_paddle_new(&g->player_paddle, g->renderer)) {
        return false;
    }

    if (!ai_paddle_new(&g->ai_paddle, g->renderer)) {
        return false;
    }

    return true;
}

void game_free(struct Game **game) {
    if (*game) {
        struct Game *g = *game;

        if (g->ai_paddle) {
            ai_paddle_free(&g->ai_paddle);
        }

        if (g->player_paddle) {
            player_paddle_free(&g->player_paddle);
        }

        if (g->ball) {
            ball_free(&g->ball);
        }

        if (g->renderer) {
            SDL_DestroyRenderer(g->renderer);
            g->renderer = NULL;
        }

        if (g->window) {
            SDL_DestroyWindow(g->window);
            g->window = NULL;
        }

        SDL_Quit();

        free(g);
        g = NULL;
        *game = NULL;

        printf("All clean!\n");
    }
}

bool game_events(struct Game *g) {
    while (SDL_PollEvent(&g->event)) {
        switch (g->event.type) {
        case SDL_EVENT_QUIT:
            g->is_running = false;
            break;
        case SDL_EVENT_KEY_DOWN:
            switch (g->event.key.scancode) {
            case SDL_SCANCODE_ESCAPE:
                g->is_running = false;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }

    return true;
}

void game_update(struct Game *g) {
    ball_paddle_collision(g->ball, g->player_paddle->rect);
    ball_paddle_collision(g->ball, g->ai_paddle->rect);
        
    ball_update(g->ball);
    player_paddle_update(g->player_paddle);
    ai_paddle_update(g->ai_paddle, g->ball->rect);
}

void game_draw(struct Game *g) {
    SDL_SetRenderDrawColor(g->renderer, 0, 0, 0, 255);
    SDL_RenderClear(g->renderer);

    ball_draw(g->ball);
    player_paddle_draw(g->player_paddle);
    ai_paddle_draw(g->ai_paddle);

    SDL_RenderPresent(g->renderer);
}

bool game_run(struct Game *g) {
    while (g->is_running) {
        if (!game_events(g)) {
            return false;
        }

        game_update(g);

        game_draw(g);

        SDL_Delay(16);
    }

    return true;
}
