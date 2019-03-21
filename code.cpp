#include <iostream>
#include <math.h>
#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>

#define Left -100
#define Right 100
#define Bottom -100
#define Top 100
#define PI acos(-1) //3.14

float DTR (float degree) {
    return degree / 180 * PI;
}

void Transformations() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(Left, Right, Top, Bottom);
}

void Axis() {
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
        glVertex2f(Left, 0);
        glVertex2f(Right, 0);
        glVertex2f(0, Top);
        glVertex2f(0, Bottom);
    glEnd();
}

void Line() {
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
        glVertex2f(0, 0);
        glVertex2f(50, 50);
    glEnd();
}

void Triangle() {
    glColor3f(0, 0, 0);
    glBegin(GL_TRIANGLES);
        glVertex2d(0, 50);
        glVertex2d(25, 0);
        glVertex2d(-25, 0);
    glEnd();
}

void Circle(float h, float k, float r, float Start, float End) {
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    for (float i = Start; i <= End; i++){
        float theta = DTR(i);
        float x = r * cos(theta) + h;
        float y = r * sin(theta) + k;
        glVertex2f(x, y);
    }
    glEnd();
}

void Ellipse(float h, float k, float r, float Start, float End, float ExtendX, float ExtendY) {
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    for (float i = Start; i <= End; i++) {
        float theta = DTR(i);
        float x = (r * cos(theta) + h) * ExtendX;
        float y = (r * sin(theta) + k) * ExtendY;
        glVertex2f(x, y);
    }
    glEnd();
}

void Draw() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    Axis();
    Line()
    Triangle()
    Circle(0, 0, 7, 0, 180);
    Ellipse(0, 0, 7, 0, 180, 1.3, 1.65);
    glFlush();
}

void Initialize(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Program");
    Transformations();
    glutDisplayFunc(Draw);
    glutMainLoop();
}


void main(int argc, char *argv[]) {
    Initialize(argc, argv);
}
