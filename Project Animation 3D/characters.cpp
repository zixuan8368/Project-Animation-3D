#include <GL/glut.h>
#include "characters.h"
#include "basicshape.h"


void drawSemibot(float x, float y , float z, float r, float g, float b)
{
	glPushMatrix();

	glTranslatef(x, y, z);

	float brightnessFactor = 1.1f;  // how much brighter specular is
	GLfloat mat_specular[4];

	GLfloat mat_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };   // ambient color
	GLfloat mat_diffuse[] = { r, g, b, 1.0f };   // diffuse color (red)

	// Scale diffuse RGB by brightnessFactor but clamp at 1.0
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

	drawCylinder(1.1, 0.85);
	glTranslatef(0.0, 0.85, 0.0);
	drawCylinder(1.05, 1.75);
	glTranslatef(0.0, 1.75, 0.0);
	drawCylinder(1.0, 0.45);
	glTranslatef(0.0, 0.75, 0.0);
	drawHemisphereWithNeck(0.95, 0.75);

	// Draw right hand
	glTranslatef(-1.0, -0.8, 0.0);
	glPushMatrix();
	glRotatef(180.0, 1.0, 0.0, 0.0);
	glRotatef(25.0, 0.0, 0.0, 1.0);
	drawCone(0.15, 1.8);
	glPopMatrix();

	// Draw left hand
	glTranslatef(2.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(180.0, 1.0, 0.0, 0.0);
	glRotatef(-25.0, 0.0, 0.0, 1.0);
	drawCone(0.15, 1.8);
	glPopMatrix();

	// Draw left legs
	glTranslatef(-0.6, -2.5, 0.0);
	glPushMatrix();
	glRotatef(180.0, 1.0, 0.0, 0.0);
	glRotatef(-10.0, 0.0, 0.0, 1.0);
	drawCone(0.35, 1.2);
	glPopMatrix();

	glTranslatef(-0.8, 0, 0.0);
	glPushMatrix();
	glRotatef(180.0, 1.0, 0.0, 0.0);
	glRotatef(10.0, 0.0, 0.0, 1.0);
	drawCone(0.35, 1.2);
	glPopMatrix();


	glPopMatrix();
}