#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <random>

std::random_device rd;
std::mt19937 gen(rd());

std::uniform_real_distribution<> distrib(0.1f, 0.9f);

void display();
void reshape(int w, int h);

void dibujarPoligonos(int a, int b, int c);
void dibujarNariz();
void dibujarOjos();

GLfloat transformarX(double coordenadaOriginalX);
GLfloat transformarY(double coordenadaOriginalY);

GLfloat verticesLobo[] = {
    //Contorno Lobo (Derecha)
    transformarX(344.5),   transformarY(150.0), //0
    transformarX(463.0),   transformarY(182.0), //1
    transformarX(563.0),   transformarY(88.0),  //2
    transformarX(624.0),   transformarY(28.0),  //3
    transformarX(642.0),   transformarY(100.0), //4
    transformarX(641.0),   transformarY(234.0), //5
    transformarX(633.0),   transformarY(306.0), //6
    transformarX(678.0),   transformarY(417.0), //7
    transformarX(644.0),   transformarY(580.0), //8
    transformarX(505.0),   transformarY(642.0), //9
    transformarX(438.0),   transformarY(747.0), //10
    transformarX(344.5),   transformarY(786.0), //11
    //Ojo del Lobo (Derecha)
    transformarX(425.0),   transformarY(425.0), //12
    transformarX(503.0),   transformarY(409.0), //13
    transformarX(427.0),   transformarY(469.0), //14
    //Nariz del Lobo (Centro y Derecha)
    transformarX(344.5),   transformarY(628.0), //15 Centro superior
    transformarX(413.0),   transformarY(659.0), //16
    transformarX(394.0),   transformarY(713.0), //17
    transformarX(344.5),   transformarY(748.0), //18 Centro inferior
    //Vertices internos (derecha)
    transformarX(551.0),   transformarY(255.0), //19 Oreja
    transformarX(480.0),   transformarY(354.0), //20 Ceja i
    transformarX(570.0),   transformarY(394.0), //21 Ceja d
    transformarX(489.0),   transformarY(519.0), //22 Mejilla
    //Vertices medios internos
    transformarX(344.5),   transformarY(290.0), //23 Medio superior
    transformarX(344.5),   transformarY(475.0), //24 Medio inferior
};



int main(int argc, char *argv[]){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(700, 800);

    glutCreateWindow("Peñafiel Kevin");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glutMainLoop();
    return EXIT_SUCCESS;
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glLineWidth(5.0f);
    // draw
    dibujarPoligonos(0, 1, 23);
    dibujarPoligonos(1, 19, 23);
    dibujarPoligonos(1, 2, 19);
    dibujarPoligonos(2, 3, 4);
    dibujarPoligonos(2, 4, 19);
    dibujarPoligonos(4, 5, 19);
    dibujarPoligonos(5, 6, 19);
    dibujarPoligonos(23, 20, 19);
    dibujarPoligonos(20, 19, 21);
    dibujarPoligonos(19, 21, 6);
    dibujarPoligonos(21, 6, 7);
    dibujarPoligonos(20, 13, 21);
    dibujarPoligonos(23, 20, 12);
    dibujarPoligonos(23, 12, 24);
    dibujarPoligonos(12, 13, 20);
    dibujarPoligonos(12, 14, 24);
    dibujarPoligonos(24, 14, 22);
    dibujarPoligonos(14, 13, 22);
    dibujarPoligonos(13, 21, 22);
    dibujarPoligonos(7, 8, 21);
    dibujarPoligonos(8, 21, 22);
    dibujarPoligonos(8, 9, 22);
    dibujarPoligonos(9, 16, 22);
    dibujarPoligonos(9, 10, 16);
    dibujarPoligonos(10, 16, 17);
    dibujarPoligonos(10, 17, 18);
    dibujarPoligonos(10, 11, 18);
    dibujarPoligonos(15, 16, 22);
    dibujarPoligonos(15, 22, 24);

    dibujarNariz();
    dibujarOjos();

    glFlush();
}

void reshape(int w, int h){
    glViewport(0,0,(GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

GLfloat transformarX(double coordenadaOriginalX){
    GLfloat nuevaCoordenadaX = (coordenadaOriginalX-344.5)/344.5;
    return nuevaCoordenadaX;
}
GLfloat transformarY(double coordenadaOriginalY){
    GLfloat nuevaCoordenadaY = (397.5-coordenadaOriginalY)/397.5;
    return nuevaCoordenadaY;
}

void dibujarPoligonos(int a, int b, int c){

    float randValue = distrib(gen);
    glColor3f(randValue, randValue, randValue);
    glBegin(GL_POLYGON);
    glVertex2f(verticesLobo[a * 2], verticesLobo[a * 2 + 1]);
    glVertex2f(verticesLobo[b * 2], verticesLobo[b * 2 + 1]);
    glVertex2f(verticesLobo[c * 2], verticesLobo[c * 2 + 1]);
    glEnd();

    //randValue = distrib(gen);
    glColor3f(randValue, randValue, randValue);
    glBegin(GL_POLYGON);
    glVertex2f(-verticesLobo[a * 2], verticesLobo[a * 2 + 1]);
    glVertex2f(-verticesLobo[b * 2], verticesLobo[b * 2 + 1]);
    glVertex2f(-verticesLobo[c * 2], verticesLobo[c * 2 + 1]);
    glEnd();
}

void dibujarNariz(){
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(verticesLobo[15 * 2], verticesLobo[15 * 2 + 1]);
    glVertex2f(verticesLobo[16 * 2], verticesLobo[16 * 2 + 1]);
    glVertex2f(verticesLobo[17 * 2], verticesLobo[17 * 2 + 1]);
    glVertex2f(verticesLobo[18 * 2], verticesLobo[18 * 2 + 1]);
    glVertex2f(-verticesLobo[17 * 2], verticesLobo[17 * 2 + 1]);
    glVertex2f(-verticesLobo[16 * 2], verticesLobo[16 * 2 + 1]);
    glEnd();
}

void dibujarOjos(){
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(verticesLobo[12 * 2], verticesLobo[12 * 2 + 1]);
    glVertex2f(verticesLobo[13 * 2], verticesLobo[13 * 2 + 1]);
    glVertex2f(verticesLobo[14 * 2], verticesLobo[14 * 2 + 1]);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-verticesLobo[12 * 2], verticesLobo[12 * 2 + 1]);
    glVertex2f(-verticesLobo[13 * 2], verticesLobo[13 * 2 + 1]);
    glVertex2f(-verticesLobo[14 * 2], verticesLobo[14 * 2 + 1]);
    glEnd();
}