#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display();
void reshape(int w, int h);

int main(int argc, char *argv[]){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(10, 10);
    glutInitWindowSize(500, 500);

    glutCreateWindow("GLUT Points");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutMainLoop();
    return EXIT_SUCCESS;
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glPointSize(10.0f);
    // draw
    glBegin(GL_TRIANGLES);
        glVertex2f(0.0f,5.0f);
        glVertex2f(4.0f,-3.0f);
        glVertex2f(-4.0f,-3.0);
    glEnd();
    glFlush();
}

void reshape(int w, int h){
    glViewport(0,0,(GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}