#include "GL/freeglut.h"
#include <math.h> 
#define PI 3.141592
void DoDisplay()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	// 좌표	
	glColor3f(1.0 ,0.0 ,0.0);
	glBegin(GL_LINES);
	glVertex2f(-1.0, 0.0);
	glVertex2f(1.0, 0.0);
	glVertex2f(0.0, 1.0);
	glVertex2f(0.0, -1.0);

	for(int i=1; i<=7; i++){
		glVertex2f(-1.0, (float)(i/7.0));
		glVertex2f(1.0, (float)(i/7.0));
	}

	for(int i=1; i<=7; i++){
                glVertex2f(-1.0, (float)(i/7.0));
                glVertex2f(1.0, (float)(i/7.0));
        }

	glEnd();
	
	glColor3f(0.0, 1.0, 0.0);
	glLineWidth(0.5);
	glBegin(GL_LINE_STRIP);
	for (float i=0; i<100; i++){
		glVertex2f((i/100), 0.2*sin((PI*4)/100*i));
	}
	glEnd();
	glFlush();
}


int main(int argc, char **argv) {
 
    // glut 초기화
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 640);
    glutCreateWindow("sin_wave");
 
    glutDisplayFunc(DoDisplay);
    glutMainLoop();
 
    return 1;
}
