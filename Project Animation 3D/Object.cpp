#include <GL/glut.h>
#include "Object.h"
#include "basicshape.h"

void drawChair(float x, float y, float z)
{
	float brightnessFactor = 0.2f;  // small specular brightness for mild shine
	GLfloat mat_specular[4];

	GLfloat mat_ambient[] = { 0.2f, 0.1f, 0.05f, 1.0f };  // dark brownish ambient
	GLfloat mat_diffuse[] = { 0.3f, 0.15f, 0.05f, 1.0f };   // darker diffuse brown

	// Calculate mild specular highlight (just a little shininess)
	for (int i = 0; i < 3; i++) {
		mat_specular[i] = mat_diffuse[i] * brightnessFactor;
		if (mat_specular[i] > 1.0f) mat_specular[i] = 1.0f;
	}
	mat_specular[3] = 1.0f;

	GLfloat mat_shininess[] = { 20.0f };  // low shininess for soft, subtle specular

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);


	float frontLeg = 1.8;
	float backLeg = 4.8;
	float legSize = 0.18;

	glPushMatrix(); //1
	glTranslatef(x, y, z);
	drawSphere(0.3);
	glPushMatrix(); //2

	// Drawing legs
	glPushMatrix(); //3
	// Drawing front right leg
	glPushMatrix(); //4
	glTranslatef(1.0, frontLeg/2, 1.0);
	drawCube(legSize, legSize, frontLeg);
	glPopMatrix(); //4

	// Drawing front left leg
	glPushMatrix(); //4
	glTranslatef(-1.0, frontLeg/2, 1.0);
	drawCube(legSize, legSize, frontLeg);
	glPopMatrix(); //4

	// Drawing back right leg
	glPushMatrix(); //4
	glTranslatef(1.0, backLeg/2, -1.0);
	drawCube(legSize, legSize, backLeg);
	glPopMatrix(); //4

	// Drawing back left leg
	glPushMatrix(); //4
	glTranslatef(-1.0, backLeg/2, -1.0);
	drawCube(legSize, legSize, backLeg);
	glPopMatrix(); //4
	glPopMatrix(); //3

	// Drawing the seat
	glPushMatrix(); //3
	glTranslatef(0.0, frontLeg + 0.1, 0.0);
	drawCube(2.2, 2.2, 0.2);
	glPopMatrix(); //3

	// Drawing the backrest
	glPushMatrix(); //3
	glTranslatef(0.0, 3.8, -1);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	drawCube(2.2, 1.5, 0.15);
	glPopMatrix(); //3

	glPopMatrix(); //2
	glPopMatrix(); //1
}

void drawTable(float x, float y, float z)
{
	float brightnessFactor = 0.2f;  // small specular brightness for mild shine
	GLfloat mat_specular[4];

	GLfloat mat_ambient[] = { 0.2f, 0.1f, 0.05f, 1.0f };  // dark brownish ambient
	GLfloat mat_diffuse[] = { 0.3f, 0.15f, 0.05f, 1.0f };   // darker diffuse brown

	// Calculate mild specular highlight (just a little shininess)
	for (int i = 0; i < 3; i++) {
		mat_specular[i] = mat_diffuse[i] * brightnessFactor;
		if (mat_specular[i] > 1.0f) mat_specular[i] = 1.0f;
	}
	mat_specular[3] = 1.0f;

	GLfloat mat_shininess[] = { 20.0f };  // low shininess for soft, subtle specular

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	float legHeight = 6.0;
	float legSize = 0.5;


	glPushMatrix(); //1
	glTranslatef(x, y, z);
	drawSphere(0.1);

	glPushMatrix(); //2
	glTranslatef(0.0, legHeight/2, 0.0);

	// Drawing legs
	glPushMatrix(); //3

	// Drawing front right leg
	glPushMatrix(); //4
	glTranslatef(8.0, 0.0, 3.0);
	drawCube(legSize, legSize, legHeight);
	glPopMatrix(); //4

	// Drawing front left leg
	glPushMatrix(); //4
	glTranslatef(-8.0, 0.0, 3.0);
	drawCube(legSize, legSize, legHeight);
	glPopMatrix(); //4

	// Drawing back right leg
	glPushMatrix(); //4
	glTranslatef(8.0, 0.0, -3.0);
	drawCube(legSize, legSize, legHeight);
	glPopMatrix(); //4

	// Drawing back left leg
	glPushMatrix(); //4
	glTranslatef(-8.0, 0.0, -3.0);
	drawCube(legSize, legSize, legHeight);
	glPopMatrix(); //4
	glPopMatrix(); //3
	 

	// Drawing tabletop
	glPushMatrix(); //3
	glTranslatef(0.0, 2.8, 0.0);
	drawCube(16.6, 6.5, 0.7);
	glPopMatrix(); //3

	glPopMatrix(); //2
	glPopMatrix(); //1
}

void drawCupboard(float x, float y, float z)
{
	glPushMatrix();
	glTranslatef(x, y, z);

	glPushMatrix();
	glTranslatef(0.0, 8.0, 0.0);

	// Color for main body
	GLfloat body_ambient[] = { 0.6f, 0.4f, 0.2f, 1.0f };
	GLfloat body_diffuse[] = { 0.7f, 0.5f, 0.3f, 1.0f };
	GLfloat body_specular[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat body_shininess[] = { 10.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, body_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, body_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, body_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, body_shininess);

	// Main body
	glPushMatrix();
	drawCube(7.0f, 2.0f, 16.0f); // length, width, height
	glPopMatrix();

	//// Shelf inside (middle)
	//glPushMatrix();
	//glTranslatef(0.0f, 0.0f, 0.0f); // center shelf
	//drawCube(3.8f, 1.8f, 0.1f);
	//glPopMatrix();

	// Color for door
	GLfloat door_ambient[] = { 0.4f, 0.1f, 0.1f, 1.0f };
	GLfloat door_diffuse[] = { 0.7f, 0.2f, 0.2f, 1.0f };
	GLfloat door_specular[] = { 0.2f, 0.1f, 0.1f, 1.0f };
	GLfloat door_shininess[] = { 10.0f };

	glMaterialfv(GL_FRONT, GL_AMBIENT, door_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, door_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, door_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, door_shininess);
	// Left door
	glPushMatrix();
	glTranslatef(-1.8f, 0.0f, 1.05f); // half length left, front
	drawCube(3.4f, 0.3f, 16.0f);
	glPopMatrix();

	// Right door
	glPushMatrix();
	glTranslatef(1.8f, 0.0f, 1.05f); // half length right, front
	drawCube(3.4f, 0.3f, 16.0f);
	glPopMatrix();

	// Rigth door knob
	// Left door knob
	// Ok maybe next time

	glPopMatrix();
	glPopMatrix();
}

void drawCup(float x, float y, float z)
{

}

void drawVase(float x, float y, float z)
{
    
}

void drawOrb(float x, float y, float z) {
	// Draw solid inner core
	GLfloat core_ambient[] = { 1.0f, 0.4f, 0.8f, 1.0f };
	GLfloat core_diffuse[] = { 1.0f, 0.4f, 0.8f, 1.0f };
	GLfloat core_specular[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat core_shininess[] = { 50.0f };

	glMaterialfv(GL_FRONT, GL_AMBIENT, core_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, core_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, core_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, core_shininess);

	glPushMatrix();
	glTranslatef(x, y, z);
	drawSphere(0.8f);
	glPopMatrix();

	// Draw transparent outer shell
	GLfloat shell_ambient[] = { 1.0f, 0.4f, 0.8f, 0.3f };
	GLfloat shell_diffuse[] = { 1.0f, 0.4f, 0.8f, 0.3f };
	GLfloat shell_specular[] = { 0.8f, 0.8f, 0.8f, 0.3f };
	GLfloat shell_shininess[] = { 50.0f };

	glMaterialfv(GL_FRONT, GL_AMBIENT, shell_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, shell_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, shell_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shell_shininess);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthMask(GL_FALSE);

	glPushMatrix();
	glTranslatef(x, y, z);
	drawSphere(1.5f);
	glPopMatrix();

	glDepthMask(GL_TRUE);
	glDisable(GL_BLEND);
}

void drawSword(float x, float y, float z)
{
	glPushMatrix();
	glTranslatef(x, y, z);

	// ==== Blade (silver/gray) ====
	{
		GLfloat mat_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
		GLfloat mat_diffuse[] = { 0.6f, 0.6f, 0.6f, 1.0f };
		GLfloat mat_specular[] = { 0.8f, 0.8f, 0.8f, 1.0f };
		GLfloat mat_shininess[] = { 60.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

		glPushMatrix();
		glTranslatef(0.0f, 1.0f, 0.0f);  // move blade upward
		drawCube(0.1f, 0.3f, 2.0f);      // thin, tall blade
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0, 2.0, 0.0);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		drawTriangularPrism(0.3, 0.1, 0.2);
		glPopMatrix();
	}

	// ==== Guard (gold) ====
	{
		GLfloat mat_ambient[] = { 0.4f, 0.3f, 0.0f, 1.0f };
		GLfloat mat_diffuse[] = { 0.8f, 0.6f, 0.1f, 1.0f };
		GLfloat mat_specular[] = { 0.9f, 0.8f, 0.4f, 1.0f };
		GLfloat mat_shininess[] = { 50.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

		glPushMatrix();
		glRotatef(90.0, 0.0, 1.0, 0.0);
		drawCube(0.9f, 0.13f, 0.16f);       // wide crossguard
		glPopMatrix();
	}

	// ==== Handle (dark brown) ====
	{
		GLfloat mat_ambient[] = { 0.1f, 0.05f, 0.02f, 1.0f };
		GLfloat mat_diffuse[] = { 0.3f, 0.15f, 0.05f, 1.0f };
		GLfloat mat_specular[] = { 0.2f, 0.1f, 0.05f, 1.0f };
		GLfloat mat_shininess[] = { 15.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

		glPushMatrix();
		glTranslatef(0.0f, -0.6f, 0.0f);  // below the guard
		drawCylinder(0.05f, 0.8f);        // vertical handle
		glPopMatrix();
	}

	glPopMatrix();
}

void drawBaseballBat(float x, float y, float z)
{
	// Set baseball bat material (brown with slight shine)
	GLfloat mat_ambient[] = { 0.15f, 0.10f, 0.05f, 1.0f };  // soft brown
	GLfloat mat_diffuse[] = { 0.40f, 0.26f, 0.13f, 1.0f };  // warm brown
	GLfloat mat_specular[] = { 0.2f, 0.2f, 0.2f, 1.0f };    // subtle reflection
	GLfloat mat_shininess[] = { 15.0f };                   // low shininess (wood)

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);


	const float length = 1.0f;
	const float gripRadius = 0.05f;
	const float barrelRadius = 0.12f;
	const int slices = 60;

	GLUquadric* quad = gluNewQuadric();

	glPushMatrix();

	// Move to desired position
	glTranslatef(x, y, z);

	// Rotate so bat stands upright (along Y-axis)
	glRotatef(-90, 1, 0, 0);

	// Grip section
	float gripLength = length * 0.25f;
	gluCylinder(quad, gripRadius, gripRadius, gripLength, slices, 1);

	// Tapered middle section
	float middleLength = length * 0.5f;
	glTranslatef(0.0, 0.0, gripLength);
	gluCylinder(quad, gripRadius, barrelRadius, middleLength, slices, 1);

	// Barrel section
	float barrelLength = length * 0.25f;
	glTranslatef(0.0, 0.0, middleLength);
	gluCylinder(quad, barrelRadius, barrelRadius, barrelLength, slices, 1);

	// Top cap (barrel end)
	glPushMatrix();
	glTranslatef(0.0, 0.0, barrelLength);
	gluDisk(quad, 0.0, barrelRadius, slices, 1);
	glPopMatrix();

	// Bottom cap (grip end)
	glPushMatrix();
	glRotatef(180, 1, 0, 0);
	gluDisk(quad, 0.0, gripRadius, slices, 1);
	glPopMatrix();

	glPopMatrix();
	gluDeleteQuadric(quad);
}

void drawGun(float x, float y, float z)
{

	// Set gun color (black or dark gray)
	GLfloat mat_ambient[] = { 0.05f, 0.05f, 0.05f, 1.0f };
	GLfloat mat_diffuse[] = { 0.1f, 0.1f, 0.1f, 1.0f };
	GLfloat mat_specular[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat mat_shininess[] = { 10.0f };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glPushMatrix(); //1
	glTranslatef(x, y, z);
	drawSphere(0.2);

	glPushMatrix(); //2
	glTranslatef(1.0, -1.5, 0);

	// ----- Barrel -----
	glPushMatrix(); //3
	glTranslatef(0.0, 2.0, 0.0);
	drawCube(2.3, 0.3, 0.4);
	glPopMatrix(); //3


	// ----- Barrel (Cylinder) -----
	glPushMatrix(); //3
	glTranslatef(1.3, 2.0, 0.0);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	drawCylinder(0.1, 0.3);
	glPopMatrix(); //3

	// ----- Handle (Cube) ----
	glPushMatrix(); //3-
	glTranslatef(-1.0, 1.3, 0.0);
	glRotatef(-15, 0.0, 0.0, 1.0);
	drawCube(0.5, 0.3, 1.2);
	glPopMatrix(); //3

	// ----- Trigger ----
	glPushMatrix(); //3
	glTranslatef(-0.4, 1.7, 0.0);
	glRotatef(35.0, 0.0, 0.0, 1.0);
	drawCube(0.1,0.1,0.4);
	glPopMatrix(); //3

	glPopMatrix(); //2

	glPopMatrix(); //1
}

void drawCart(float x, float y, float z)
{
	float length = 6.0f;    // X-axis (coffin length)
	float height = 2.5f;    // Y-axis (coffin height)
	float width = 2.5f;    // Z-axis (coffin width)
	float wallThickness = 0.2f;
	float wheelSize = 0.5f;

	glPushMatrix();
	glTranslatef(x, y, z);

	// Rotate so coffin is open on top
	//glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

	// === Wood Material ===
	GLfloat wood_ambient[] = { 0.2f, 0.1f, 0.0f, 1.0f };
	GLfloat wood_diffuse[] = { 0.5f, 0.25f, 0.1f, 1.0f };
	GLfloat wood_specular[] = { 0.1f, 0.1f, 0.1f, 1.0f };
	GLfloat wood_shininess[] = { 8.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, wood_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, wood_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, wood_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, wood_shininess);

	// Bottom
	glPushMatrix();
	glTranslatef(0.0f, wallThickness / 2.0f, 0.0f);
	drawCube(length, width, wallThickness);
	glPopMatrix();

	// Left wall
	glPushMatrix();
	glTranslatef(-length / 2.0f + wallThickness / 2.0f, height / 2.0f, 0.0f);
	drawCube(wallThickness, width, height);
	glPopMatrix();

	// Right wall
	glPushMatrix();
	glTranslatef(length / 2.0f - wallThickness / 2.0f, height / 2.0f, 0.0f);
	drawCube(wallThickness, width, height);
	glPopMatrix();

	// Back wall
	glPushMatrix();
	glTranslatef(0.0f, height / 2.0f, -width / 2.0f + wallThickness / 2.0f);
	drawCube(length, wallThickness, height);
	glPopMatrix();

	// Front wall
	glPushMatrix();
	glTranslatef(0.0f, height / 2.0f, width / 2.0f - wallThickness / 2.0f);
	drawCube(length, wallThickness, height);
	glPopMatrix();

	// === Wheels (Using cubes) ===
	GLfloat wheel_color[] = { 0.1f, 0.1f, 0.1f, 1.0f };  // dark gray
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, wheel_color);

	float wheelY = -wheelSize / 2.0f;
	float offsetX = length / 2.0f - wheelSize / 2.0f;
	float offsetZ = width / 2.0f - wheelSize / 2.0f;

	// Front-left wheel
	glPushMatrix();
	glTranslatef(-offsetX, wheelY, offsetZ);
	drawCube(wheelSize, wheelSize, wheelSize);
	glPopMatrix();

	// Front-right wheel
	glPushMatrix();
	glTranslatef(offsetX, wheelY, offsetZ);
	drawCube(wheelSize, wheelSize, wheelSize);
	glPopMatrix();

	// Back-left wheel
	glPushMatrix();
	glTranslatef(-offsetX, wheelY, -offsetZ);
	drawCube(wheelSize, wheelSize, wheelSize);
	glPopMatrix();

	// Back-right wheel
	glPushMatrix();
	glTranslatef(offsetX, wheelY, -offsetZ);
	drawCube(wheelSize, wheelSize, wheelSize);
	glPopMatrix();

	glPopMatrix();
}