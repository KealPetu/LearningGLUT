#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

int forma = 1;

void display();
void reshape(int w, int h);

int main(int argc, char *argv[]){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(800, 800);

    glutCreateWindow("Peñafiel Kevin");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(0.0f, 0.9f, 0.5f, 1.0f);

    glutMainLoop();
    return EXIT_SUCCESS;
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glLineWidth(10.0f);
    // draw
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 0.0, 1.0);
    if (forma == 0)
    {
        glVertex2f(0.0,         1);
        glVertex2f(0.2,         0.6);
        glVertex2f(0.8,         0.6);
        glVertex2f(0.36363636,  0.272727);
        glVertex2f(0.8,         -0.6);
        glVertex2f(0.0,         0.0);
        glVertex2f(-0.8,        -0.6);
        glVertex2f(-0.36363636, 0.272727);
        glVertex2f(-0.8,        0.6);
        glVertex2f(-0.2,        0.6);
    } else {
        glVertex2f(0.0,         0.5);
        glVertex2f(0.5,         -0.5);
        glVertex2f(-0.5,        -0.5);
    }
    
    glEnd();
    glFlush();
}

void reshape(int w, int h){
    glViewport(0,0,(GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}