#include "ball.h"
#include "utils.h"
#include "racquet.h"

void draw_ball(float x, float y, float width, float height) {
    glBegin(GL_QUADS);

    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);

    glEnd();
}

void vec2_norm(float &x, float &y){
    float length = sqrt((x * x) + (y * y));

    if (length != 0.0f) {
        length = 1.0f / length;
        x *= length;
        y *= length;
    }

}

void collision_actions(){
    // hit by the left racquet.
    if(ball_pos_x < racquet_left_x + racquet_width &&
       ball_pos_x > racquet_left_x &&
       ball_pos_y < racquet_left_y + racquet_height &&
       ball_pos_y > racquet_left_y){

            float yAngle = (ball_pos_y - racquet_left_y)/racquet_height - 0.5f;
            ball_dir_x = fabs(ball_dir_x);
            ball_dir_y = yAngle;

       }

    // hit by the right racquet.
    if(ball_pos_x > racquet_right_x &&
       ball_pos_x < racquet_right_x + racquet_width &&
       ball_pos_y > racquet_right_y &&
       ball_pos_y < racquet_right_y + racquet_height){
            float yAngle = (ball_pos_y - racquet_right_y)/racquet_height - 0.5f;
            ball_dir_x = -fabs(ball_dir_x);
            ball_dir_y = yAngle;
       }

    // hit the left wall. Reset the position of the ball.
    if(ball_pos_x < 0){
        ++rightPlayer;
        ball_pos_x = (width+100) / 2;
        ball_pos_y = (length+100) / 2;
        ball_dir_x = fabs(ball_dir_x);
        ball_dir_y = 0;
    }


    // hit the right wall. Reset the position of the ball. Send the ball in the opposite direction.
    if(ball_pos_x > width){
        ++leftPlayer;
        ball_pos_x = (width+100)/2;
        ball_pos_y = (length+100)/2;
        ball_dir_x = -fabs(ball_dir_x);
        ball_dir_y = 0;
    }

    // the top wall or the bottom wall.
    if(ball_pos_y < 0 || ball_pos_y > length){
        ball_dir_y = -1*ball_dir_y;
    }

    vec2_norm(ball_dir_x, ball_dir_y);

}

void update_ball(){
    ball_pos_x += (ball_dir_x * ball_speed);
    ball_pos_y += (ball_dir_y * ball_speed);
    collision_actions();
}


