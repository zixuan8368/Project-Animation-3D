#include <GL/glut.h>
#include <math.h>
#include "scene.h"
#include "characters.h"
#include "basicshape.h"
#include "Object.h"

const int FPS = 60;
int counter = 0;

float semibot1 = 0;
bool semibot1check = true;

float mouthAngle[6] = { 0, 0, 0, 0, 0, 0 };
bool isOpen[6] = { true, true, true, true, true, true };
float legAngle[6] = { 0, 0, 0, 0, 0, 0 };
bool isForward[6] = { true, true, true, true, true, true };

float r = 1;
float g = 1;
float b = 0.365;

int scene1()
{
	//glClearColor(0.0, 0.0, 0.0, 1.0);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glLoadIdentity();

	//// ==== CAMERA ANIMATION ====
	//float camX = 0.0f;
	//float camY = 0.0f;
	//float camZ = 5.0f - counter * 0.02;
	//gluLookAt(camX, camY, camZ,    // Camera position
	//	0.0, 0.0, -2.0,      // Look at center
	//	0.0, 1.0, 0.0);      // Up vector

	float brightnessFactor = 1.1f;  // how much brighter specular is
	GLfloat mat_specular[4];

	GLfloat mat_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };   // ambient color
	GLfloat mat_diffuse[] = { r, g, b, 1.0f };   // diffuse color (red)

	//Scale diffuse RGB by brightnessFactor but clamp at 1.0
	for (int i = 0; i < 3; i++) {
		mat_specular[i] = mat_diffuse[i] * brightnessFactor;
		if (mat_specular[i] > 1.0f) mat_specular[i] = 1.0f;  // clamp max to 1.0
	}
	mat_specular[3] = 1.0f;

	GLfloat mat_shininess[] = { 60.0f };                    // shininess (0-128)

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glPushMatrix();
	glTranslatef(0.0, 0.0, -5.0);
	drawSphere(0.1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0.0, -2.0, -8.0);
	drawSemibot2(0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, false, mouthAngle[0], isOpen[0], false, legAngle[0], isForward[0]);
	glPopMatrix();

	counter++;
	if (counter >= 5 * FPS)
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