#include <GL/glut.h>
#include "scene.h"
#include "characters.h"

const int FPS = 60;
int counter = 0;


int scene1()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	drawSemibot(0.0, -2.0, -10.0, 0.929, 0.039, 0.365);

	

	counter++;
	if (counter == 5 * FPS)
	{
		counter = 0;
		return 1;
	}
	else
		return 0;
}

int scene2()
{
	glClearColor(0.285, 0.611, 0.912, 0.456);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	return 1;
}

int scene3()
{
	glClearColor(0.748, 0.199, 0.384, 0.821);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	return 1;
}

int scene4()
{
	glClearColor(0.053, 0.875, 0.667, 0.394);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	return 1;
}

int scene5()
{
	glClearColor(0.938, 0.317, 0.210, 0.709);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	return 1;
}

int scene6()
{

	return 1;
}

int scene7()
{

	return 1;
}

int scene8()
{

	return 1;
}

int scene9()
{

	return 1;
}