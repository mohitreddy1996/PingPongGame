#ifndef RACQUET_H
#define RACQUET_H

#include "utils.h"
#include "ball.h"

extern const int racquet_width;
extern const int racquet_height;
extern const int racquet_speed;

extern float racquet_left_x;
extern float racquet_right_x;
extern float racquet_left_y;
extern float racquet_right_y;

void draw_racquets(float x, float y, float width, float height);

#endif
