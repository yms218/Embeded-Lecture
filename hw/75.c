#include "GL/freeglut.h"
#include <math.h>
#include <stdlib.h> 
#include <time.h>
#define PI 3.141592

int rand_num(void)
{
	srand(time(NULL));
	return rand() % 9 + 1;
}

float gaussian_func(float x)
{	
	float sigma = 1.0;
	float mu = 0.0;
//	float amp = rand_num();
	return (1/(sqrt(2*PI*sigma*sigma)))*exp(-0.5*((x-mu)/sigma*sigma)*((x-mu)/sigma*sigma));	
}

void DoDisplay()
{
	float sum = 0;
	float j = 2;
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
	for(float i=-50; i<50; i++)
	{
		glVertex2f((i/50),  0.5*sin((PI*4/50*i))); 
	}
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_STRIP); 
	glVertex2f(0.0, 0.0);
	while(j<50.0)
	{
		sum += 0.5*sin((PI*4/50*j));
		j = j + 2;
	}
	j = 2; 
	while(j<50.0)
	{
		glVertex2f((j/50), sum);
		j = j + 2;
	}
	glEnd();
	glFlush();
}




int main(int argc, char **argv) 
{ 
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
