#include <GL/glut.h>
#include "scene.h"



void init();
void display();
void reshape(int, int);
void timer(int);

int sceneNumber = 1;
const int TOTAL_SCENE = 9;
const int FRAME_PER_SECOND = 60;
const int TIME_PER_FRAME = 1000 / FRAME_PER_SECOND;
const float FIELD_OF_VIEW = 60.0;



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1000, 1000);


	glutCreateWindow("3D Animation");
	glutDisplayFunc(display);
	glutTimerFunc(TIME_PER_FRAME, timer, 0);

	init();

	glutMainLoop();

}


void init()
{
	glClearColor(1.0, 1.0, 0.0, 0.8);
	glClear(GL_COLOR_BUFFER_BIT);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	switch (sceneNumber)
	{
		case 1: sceneNumber += scene1();
				break;	
		case 2: sceneNumber += scene2();
				break;
		case 3: sceneNumber += scene3();
				break;
		case 4: sceneNumber += scene4();
				break;
		case 5: sceneNumber += scene5();
				break;
		case 6: sceneNumber += scene6();
				break;
		case 7: sceneNumber += scene7();
				break;
		case 8: sceneNumber += scene8();
				break;
		case 9: sceneNumber += scene9();
				break;
	}
		

	glutSwapBuffers();
}

void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(FIELD_OF_VIEW, 1.0, 2.0, 50.0);
	glMatrixMode(GL_MODELVIEW);

}


void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(TIME_PER_FRAME, timer, 0);
}

