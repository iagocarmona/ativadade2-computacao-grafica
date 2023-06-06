// Felipe Martins Sanches, 2390809
// Iago Ortega Carmona, 2277980
// Amanda Ferrari, 2380480

#include <GL/freeglut.h>


float dia = 0, hora = 0;
float angleZ = 0.0f;

void Timer(int value){
    hora += 1.0f;
    if (hora >= 24.0f){
        hora = 0.0f;
        dia += 1.0f;
        if (dia >= 360.0f){
            dia = 0.0f;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(40,Timer, 1);
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Viewport 1 (top-left)
    glViewport(0, 300, 300, 300);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-3, 3, -3, 3, 1, 50);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 30, 0,
              0.0, 0.0, 0.0,
              0.0, 0.0, -1.0);
    glColor3f(1, 0, 0);
    glutWireTeapot(1.5);

    // Viewport 2 (top-right)
    glViewport(300, 300, 300, 300);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-3, 3, -3, 3, 1, 50);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(10, 0, 0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    glColor3f(1, 0, 0);
    glutWireTeapot(1.5);

    // Viewport 3 (bottom-left)
    glViewport(0, 0, 300, 300);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-3, 3, -3, 3, 1, 50);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0, 0, 10,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    glColor3f(1, 0, 0);
    glutWireTeapot(1.5);

    // Viewport 4 (bottom-right)
    glViewport(300, 0, 300, 300);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-3, 3, -3, 3, 1, 50);

    gluPerspective(70.0f, 1.0f, 1.0f, 50.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

    gluLookAt(0, 0, 5,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    glRotatef(45.0, 1.0, 0.0, 0.0);
    glColor3f(1, 0, 0);
    glutWireTeapot(1.5);

    glPopMatrix();

    glFlush();
}

void idle() {

    angleZ += 1.0f;
    if (angleZ > 360.0f) {
        angleZ -= 360.0f;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);                           //inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);    //configura o modo de display
    glutInitWindowPosition(200,0);                  //seta a posi��o inicial da janela
    glutInitWindowSize(600,600);                    //configura a largura e altura da janela de exibi��o
    glutCreateWindow("3D");                 //cria a janela de exibi��o

    init();                                         //executa fun��o de inicializa��o
    glutDisplayFunc(display);
    glutTimerFunc(40,Timer, 1);
    glutIdleFunc(idle);
    glutMainLoop();                                  //mostre tudo e espere
    return 0;

}
