#include "GL/freeglut.h"
#include <math.h>
#include <time.h>
#include <stdlib.h> 
#define PI 3.141592
int rand_num(int arr[50])
{
	srand(time(NULL));
	for(int i = 0; i<50; i++)
		arr[i] = (rand() % 50 + 1);	
}

void DoDisplay()
{
	int arr[50] = {0};
	int j = 0;
	rand_num(arr);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	// 좌표	
	glColor3f(1.0 ,0.0 ,0.0);
	glBegin(GL_LINES);
	glVertex2f(-1.0, 0.0);
	glVertex2f(1.0, 0.0);
	glVertex2f(0.0, 1.0);
	glVertex2f(0.0, -1.0);
	glEnd();
	
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (float i=0; i<50; i++){
			glVertex2f((i/50),  0.5*sin((PI*arr[j])/50*i));
			j++;
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
