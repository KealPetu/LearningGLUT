#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display();

int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(10, 10);
    glutInitWindowSize(500, 500);

    glutCreateWindow("GLUT window");

    glutDisplayFunc(display);
    glClearColor(0.0f, 1.0f, 1.0f, 1.0f);

    glutMainLoop();
    return EXIT_SUCCESS;
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    // draw
    glFlush();
}
