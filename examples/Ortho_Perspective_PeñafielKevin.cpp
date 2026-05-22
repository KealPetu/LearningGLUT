#include <GL/glut.h>

int switchView = 1;

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);                  // Limpiamos la pantalla
    glMatrixMode(GL_PROJECTION);                   // Modo de proyección
    glLoadIdentity();                              // Cargamos la matriz identidad

    if (switchView == 0)
    {
        glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);     // Vista ortogonal (2D)
    } else {
        gluPerspective(60.0, 1.0, 1.0, 100.0);        //Vista Perspectiva
        glTranslatef(0,0,-5);
    }

    glMatrixMode(GL_MODELVIEW);                    // Modo de modelado
    glLoadIdentity();

    glBegin(GL_QUADS);                             // Dibujamos un cuadrado
    glColor3f(0.0, 1.0, 1.0);                      // Color azul (RGB)

    glVertex3f(-0.5, 0.5, -0.5);                         // Vértice superior-izquierdo
    glVertex3f(-0.5, -0.5, 0.5);                        // Vértice inferior-izquierdo
    glVertex3f(0.5, -0.5, 0.5);                         // Vértice inferior-derecho
    glVertex3f(0.5, 0.5, -0.5);                          // Vértice superior-derecho
    glEnd();

    glFlush();                                     // Renderiza los comandos
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);   // Modo de color RGB y búfer simple
    glutInitWindowSize(500, 500);                  // Tamaño de la ventana
    glutInitWindowPosition(50, 20);                // Posición en la pantalla
    glutCreateWindow("GLUT Square");               // Título de la ventana
    glClearColor(0.0, 0.0, 0.0, 0.0);             // Color de fondo (negro)
    glutDisplayFunc(display);                      // Llama a la función display
    glutMainLoop();                                // Bucle principal

    return EXIT_SUCCESS;
}