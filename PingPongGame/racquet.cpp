#include "racquet.h"
#include "utils.h"


void draw_racquets(float x, float y, float width, float height) {
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
    glEnd();
}
