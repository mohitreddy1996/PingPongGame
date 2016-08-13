#ifndef BALL_H
#define BALL_H

#include "utils.h"

extern const int ball_size;
extern const int ball_speed;

extern float ball_pos_x;
extern float ball_pos_y;
extern float ball_dir_x;
extern float ball_dir_y;

// draw the ball on the console window.
void draw_ball(float x, float y, float m, float n);

void vec2_norm(float &x, float &y);

void collision_actions();

void update_ball();

#endif // BALL_H
