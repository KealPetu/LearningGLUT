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
    //glutInitWindowPosition(10, 10);
    glutInitWindowSize(800, 800);

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
        glColor3f(1.0f, 0.0f,0.0f);
        glVertex2f(0.0f,0.5f);
        glColor3f(0.0f, 1.0f,0.0f);
        glVertex2f(-0.5f,-0.5f);
        glColor3f(0.0f, 0.0f,1.0f);
        glVertex2f(0.5f,-0.5);
    glEnd();
    glFlush();
}

void reshape(int w, int h){
    glViewport(0,0,(GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1.0f, 1.0f, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
}