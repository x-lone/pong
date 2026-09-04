#ifndef MAIN_H
#define MAIN_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SDL_FLAGS SDL_INIT_VIDEO

#define WINDOW_TITLE "Pong"
#define WINDOW_HEIGHT 216
#define WINDOW_WIDTH 280

#define BORDER_THICKNESS 4
#define BORDER_DASH_SIZE 10

#define BALL_SIZE 4
#define BALL_SPEED 2.5f
#define BALL_SPEED_MULTI 1.05f
#define BALL_SERVE_SPEED 1.0f
#define SPAWN_DELAY 50

#define PADDLE_WIDTH 4
#define PADDLE_HEIGHT 24
#define PADDLE_HORIZONTAL_OFFSET 10
#define PADDLE_VEL 2

#define NUMBER_WIDTH 20
#define NUMBER_HEIGHT 36

#endif
