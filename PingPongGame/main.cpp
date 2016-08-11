
#include <GL/glut.h>

// define the length and width of the console window.
int length = 500;
int width = 400;
int interval = 1000/60; // 60 fps.

// write a function for all the objects to be shown.
void draw(){
    // clear the buffer first.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // required elements to be drawn here.

    // swap buffers.
    glutSwapBuffers();
}

// write a function for ball and the raquet movements.
void update(int value){

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
