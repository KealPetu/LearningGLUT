#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>

int forma;

void display();
void reshape(int w, int h);

void configurarVerticesEstrella();
void configurarVerticesTriangulo();

int main(int argc, char *argv[]){

    std::cout << "Ingresa que forma quieres visualizar\n0. Triangulo\n1. Estrella\nopcion: ";
    std::cin >> forma;

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

    if (forma == 1)
    {
        configurarVerticesEstrella();
    } else {
        configurarVerticesTriangulo();
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

void configurarVerticesEstrella(){

    GLfloat verticesEstrella[] = {
        0.0, 1.0,
        0.2, 0.6,
        0.8, 0.6,
        0.36363636, 0.272727,
        0.8, -0.6,
        0.0, 0.0,
        -0.8, -0.6,
        -0.36363636, 0.272727,
        -0.8, 0.6,
        -0.2, 0.6
    };

    int tam = sizeof(verticesEstrella)/sizeof(GLfloat);

    for (int i = 0; i < tam; i+=2)
    {
        glVertex2f(verticesEstrella[i], verticesEstrella[i+1]);
    }
    

}

void configurarVerticesTriangulo(){

    float verticesTriangulo[] = {
        0.0, 0.5,
        0.5, -0.5,
        -0.5, -0.5
    };

    int tam = sizeof(verticesTriangulo)/sizeof(GLfloat);

    for (int i = 0; i < tam; i+=2)
    {
        glVertex2f(verticesTriangulo[i], verticesTriangulo[i+1]);
    }
    
}