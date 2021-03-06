#include <bits/stdc++.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <GL/glfw.h>
#include "racquet.h"
#include "ball.h"
#include "utils.h"


using namespace std;

// console window dimensions;
const int width = 500;
const int length = 500;
const int interval = 1000/60;

// player scores.
int leftPlayer = 0;
int rightPlayer = 0;

// Racquet dimensions and utils.
const int racquet_height = 80;
const int racquet_width = 10;
const int racquet_speed = 30;

// ball dimensions and speed.

const int ball_size = 8;
const int ball_speed = 3;

// position the racquets.
float racquet_left_x = 10.0f;
float racquet_left_y = 250.0f;
float racquet_right_x = length - racquet_width - 10.0f;
float racquet_right_y = 250.0f;

// position the ball

float ball_pos_x = (width + 100) / 2;
float ball_pos_y = (length + 100) / 2;
float ball_dir_x = -1.0f;
float ball_dir_y = 0.0f;

// draw the required scores on the top of the screen.

void draw_score(float x, float y, string text){
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char*)text.c_str());
}

// write a function for all the objects to be shown.
void draw(){
    // clear the buffer first.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // required elements to be drawn here.
    draw_racquets(racquet_left_x, racquet_left_y, racquet_width, racquet_height);
    draw_racquets(racquet_right_x, racquet_right_y, racquet_width, racquet_height);


    // draw the ball.
    draw_ball(ball_pos_x - ball_size / 2, ball_pos_y - ball_size / 2, (float)ball_size, (float)ball_size);

    // draw the score.
    draw_score(length/2 - 25, width - 15, int2str(leftPlayer) + " : " + int2str(rightPlayer));

    // swap buffers.
    glutSwapBuffers();
}

void myKeyboardFunction(unsigned char key, int x, int y){
    switch(key){
        case 'w':
            racquet_left_y += racquet_speed;
            break;
        case 's':
            racquet_left_y -= racquet_speed;
            break;
        case 'o':
            racquet_right_y += racquet_speed;
            break;
        case 'l':
            racquet_right_y -= racquet_speed;
            break;
        default:
            cout<<"Wrong key!";
            break;
    }
}


// write a function for ball and the raquet movements.
void update(int value){

    // For any OS.
    glutKeyboardFunc(myKeyboardFunction);

    // update the ball position;
    update_ball();

    // recall the function (update) after the given interval.
    glutTimerFunc(interval, update, 0);

    // redisplay the updated frame.
    glutPostRedisplay();

}

void enable2D(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, width, 0.0f, height, 0.0f, 1.0f);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Ping Pong Game");
    glutInitWindowSize(length, width);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

   // register the callback functions. 1) draw function 2) gluTimefun to call the update function after given milliseconds.
    glutDisplayFunc(draw);
    glutTimerFunc(interval, update, 0);

    // setup the display as 2D display.
    enable2D(length, width);
    // draw color = white.
    glColor3f(1.0f, 1.0f, 1.0f);

    glutMainLoop();
    return 0;
}
