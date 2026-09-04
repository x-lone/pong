#include "score.h"
#include "load_media.h"

void score_update_digits(struct Score *s);

bool score_new(struct Score **score, SDL_Renderer *renderer) {
    *score = calloc(1, sizeof(struct Score));
    if (*score == NULL) {
        fprintf(stderr, "Error Calloc of New Score\n");
        return false;
    }
    struct Score *s = *score;

    s->renderer = renderer;

    s->score = 0;

    if (!load_media_sheet(s->renderer, &s->image, "images/digits.png", NUMBER_WIDTH, NUMBER_HEIGHT, &s->src_rects)) {
        return false;
    }

    score_update_digits(s);

    return true;
}

void score_free(struct Score **score) {
    if (*score) {
        struct Score *s = *score;

        if (s->src_rects) {
            free(s->src_rects);
            s->src_rects = NULL;
        }
        if (s->image) {
            SDL_DestroyTexture(s->image);
            s->image = NULL;
        }

        s->renderer = NULL;

        free(s);
        s = NULL;
        *score = NULL;

        printf("Free Score.\n");
    }
}

void score_update_digits(struct Score *s) {
    if (s->score > 99) {
        s->score = 99;
    }

    s->digits[0] = (s->score > 9) ? (s->score / 10) % 10 : 0;
    s->digits[1] = s->score % 10;
}

void score_increment(struct Score *s) {
    s->score++;
    score_update_digits(s);
}

void score_draw(const struct Score *s, float x, float y) {
    SDL_FRect digit_rect = {x, y, NUMBER_WIDTH, NUMBER_HEIGHT};
    for (int i = 0; i < 2; i++) {
        digit_rect.x = (float)i * NUMBER_WIDTH + x;
        SDL_RenderTexture(s->renderer, s->image, &s->src_rects[s->digits[i]], &digit_rect);
    }
}
