#include <GL/glut.h>
#include <algorithm>
#include "characters.h"
#include "basicshape.h"


void drawSemibot(float x, float y, float z, float r, float g, float b, float eyeDirX, float eyeDirY, float rotAngle, bool isTalking, float &mouthAngle, bool &isOpen)
{
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(rotAngle, 0.0f, 1.0f, 0.0f); // Rotate the whole bot around Y-axis

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


	// Draw right hand
	glTranslatef(-1.0, -0.05, 0.0);
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

	// Draw left leg
	glTranslatef(-0.6, -2.5, 0.0);
	glPushMatrix();
	glRotatef(180.0, 1.0, 0.0, 0.0);
	glRotatef(-10.0, 0.0, 0.0, 1.0);
	drawCone(0.35, 1.2);
	glPopMatrix();

	// Draw right leg
	glTranslatef(-0.8, 0, 0.0);
	glPushMatrix();
	glRotatef(180.0, 1.0, 0.0, 0.0);
	glRotatef(10.0, 0.0, 0.0, 1.0);
	drawCone(0.35, 1.2);
	glPopMatrix();

	// Open and close mouth while talking 
	if (isTalking)
	{
		glPushMatrix();
		glTranslatef(0.40, 2.75, -0.95);
		glRotatef(mouthAngle, 1.0, 0.0, 0.0);
		glPushMatrix();
		glTranslatef(0.0, 0.95, 0.95);
		drawHead(0.0, 0.0, 0.0, 0.929, 0.039, 0.365, true, eyeDirX, eyeDirY,0,0,0);
		glPopMatrix();

		glPopMatrix();

		if (isOpen)
		{
			mouthAngle -= 3;
			if (mouthAngle == -30)
				isOpen = false;
		}
		else
		{
			mouthAngle += 2;
			if (mouthAngle == 0)
				isOpen = true;
		}
		
	}
	else
	{
		glPushMatrix();
		glTranslatef(0.40, 3.76, -0.05);
		drawHead(0.0, 0.0, 0.0, 0.929, 0.039, 0.365, true, eyeDirX, eyeDirY,0,0,0);
		glPopMatrix();

	}
	glPopMatrix();
}

void drawCrouchSemibot(float x, float y, float z, float r, float g, float b, float eyeDirX, float eyeDirY, float rotAngle)
{
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



	glPushMatrix(); //1
	glTranslatef(x, y, z);
	glRotatef(rotAngle, 0.0, 1.0, 0.0);
	drawSphere(0.1);	// Visually display of the center point
	
	glPushMatrix(); //2
	glTranslatef(0.0, 0.6, 0.0); // This is to make the center point of the semibots is between the legs

	// Drawing left leg
	glPushMatrix(); //3
	glRotatef(180.0, 1.0, 0.0, 0.0);
	glRotatef(3.0, 0.0, 0.0, 1.0);
	glTranslatef(-0.4, 0.0, 0.0);
	drawCone(0.25, 0.6);
	glPopMatrix(); //3

	// Drawing right leg
	glPushMatrix(); //3
	glRotatef(180.0, 1.0, 0.0, 0.0);
	glRotatef(-3.0, 0.0, 0.0, 1.0);
	glTranslatef(0.4, 0.0, 0.0);
	drawCone(0.25, 0.6);
	glPopMatrix(); //3

	// Drawing the first lower cylinder
	glPushMatrix(); //3
	drawCylinder(1.1, 0.35);
	glPopMatrix(); //3

	// Drawing the second cylinder above the first cylinder
	glPushMatrix(); //3
	glTranslatef(0.0, 0.35, 0.0);
	drawCylinder(1.0, 0.6);
	glPopMatrix();	//3

	//Matrix for drawing hands
	glPushMatrix(); //3
	glTranslatef(0.0, 0.55, 0.0);

	// Drawing right hand
	glPushMatrix(); //4
	glTranslatef(0.9, 0.0, 0.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	glRotatef(-50.0, 0.0, 0.0, 1.0);
	drawCone(0.18, 0.7);
	glPopMatrix(); //4

	// Drawing left hand
	glPushMatrix(); //4
	glTranslatef(-0.9, 0.0, 0.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	glRotatef(50.0, 0.0, 0.0, 1.0);
	drawCone(0.18, 0.7);
	glPopMatrix(); //4

	glPopMatrix(); //3

	// Drawing head
	glPushMatrix();
	glTranslatef(0.0, 0.95, -1.0);
	drawHead(0.0, 0.0, 0.0, r, g, b, true, eyeDirX, eyeDirY, 0.0, 0.0, 0.0);
	glPopMatrix();
	
	glPopMatrix(); //2

	glPopMatrix(); //1
}

void drawHideSemibot()
{

}

void drawHead(float x, float y, float z, float r, float g, float b, bool alive, float eyeDirX, float eyeDirY, float rotX, float rotY, float rotZ)
{
	// Color
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


	glPushMatrix(); //1
	glTranslatef(x, y, z);
	//drawSphere(0.3); // Comment this is you don't want to see the center point of the head
	if (!alive) {
		glRotatef(rotX, 1.0, 0.0, 0.0);
		glRotatef(rotY, 0.0, 1.0, 0.0);
		glRotatef(rotZ, 0.0, 0.0, 1.0);
	}

	glPushMatrix(); //2
	glTranslatef(0.0, 0.0, 1); // This is to make the center point on the back of the head

	// Drawing neck
	glPushMatrix(); //3
	drawCylinder(0.95, 0.75);
	glPopMatrix(); //3

	// Drawing head without eye
	glPushMatrix(); //3
	glTranslatef(0.0, 0.75, 0.0);
	drawHemisphere(0.95);
	glPopMatrix(); //3

	//Drawing hinge behind the head
	glPushMatrix(); //3
	glTranslatef(0.0, 0.0, -0.95);
	glRotatef(180, 1.0, 1.0, 0.0);
	drawCylinder(0.05, 0.2);
	glPopMatrix(); //3

	glPushMatrix(); //3
	glTranslatef(0.0, 0.65, 0.75);
	// color of the eyes (determined by the semibots whether is alive or not)
	if (alive)
	{
		GLfloat eye_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		GLfloat eye_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		GLfloat eye_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
		GLfloat eye_shininess[] = { 50.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, eye_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, eye_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, eye_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, eye_shininess);
	}
	else
	{
		GLfloat eye_diffuse[] = { 0.0f, 0.0f, 0.0f, 1.0f };     // Black diffuse
		GLfloat eye_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };     // Black ambient
		GLfloat eye_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };    // White specular (for shine)
		GLfloat eye_shininess[] = { 125.0f };                  // High shininess for glossy effect

		glMaterialfv(GL_FRONT, GL_AMBIENT, eye_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, eye_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, eye_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, eye_shininess);
	}

	// Drawing left eye
	glPushMatrix(); //4
	glTranslatef(-0.5, 0.0, 0.0);
	drawSphere(0.4);
	glPopMatrix(); //4

	// Drawing right eye
	glPushMatrix(); //4
	glTranslatef(0.5, 0.0,0.0);
	drawSphere(0.4);
	glPopMatrix(); //4
	glPopMatrix(); //3

	glPushMatrix(); //3
	glTranslatef(0.0, 0.65, 1.09);
	// draw pupils
	if (alive)
	{
		// Pupil material
		GLfloat pupil_diffuse[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		GLfloat pupil_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		GLfloat pupil_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		GLfloat pupil_shininess[] = { 60.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, pupil_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, pupil_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, pupil_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, pupil_shininess);

		float pupilOffsetScale = 0.15f; // how far pupil can move inside the eye
		float pupilRadius = 0.1f;

		// Right pupil
		glPushMatrix(); //4
		glTranslatef(0.5f + eyeDirX * pupilOffsetScale, eyeDirY * pupilOffsetScale, 0);
		drawSphere(pupilRadius);
		glPopMatrix(); //4

		// Left pupil
		glPushMatrix(); //4
		glTranslatef(-0.5f + eyeDirX * pupilOffsetScale, eyeDirY * pupilOffsetScale, 0);
		drawSphere(pupilRadius);
		glPopMatrix(); //4
	}
	glPopMatrix(); //3

	glPopMatrix(); //2

	glPopMatrix(); //1
}

void drawSemibot2(float x, float y, float z, float r, float g, float b, float eyeDirX, float eyeDirY, float rotAngle, bool isTalking, float& mouthAngle, bool& isOpen,bool isWalking, float& legAngle, bool& isForward)
{
	// Set the color of the semibots
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

	glPushMatrix(); //1
	glTranslatef(x, y, z);
	glRotatef(rotAngle, 0.0, 1.0, 0.0);
	drawSphere(0.3);

	glPushMatrix(); //2
	glTranslatef(0.0, 1.2, 0.0);

	
	// Matrix for legs
	glPushMatrix(); //3
	glTranslatef(0.0, 0.5, 0.0);
	// Drawing right leg
	glPushMatrix(); //4
	if (isWalking)
	{
		float angle = legAngle;
		glRotatef(angle, 1.0, 0.0, 0.0);
		if (isForward)
		{
			legAngle += 1;
			if (legAngle >= 35)
				isForward = false;
		}
		else
		{
			
			legAngle -= 1;
			if (legAngle <= -35)
				isForward = true;
		}
	}
	glPushMatrix(); //5
	glTranslatef(0.6, 0.0, 0.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	drawCone(0.5, 1.7);
	glPopMatrix(); //5
	glPopMatrix(); //4

	// Drawing left leg
	glPushMatrix(); //4
	if (isWalking)
	{
		float angle = legAngle;
		glRotatef(-angle, 1.0, 0.0, 0.0);
		if (isForward)
		{
			legAngle += 1;
			if (legAngle >= 35)
				isForward = false;
		}
		else
		{

			legAngle -= 1;
			if (legAngle <= -35)
				isForward = true;
		}
	}
	glPushMatrix(); //5
	glTranslatef(-0.6, 0.0, 0.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	drawCone(0.5, 1.7);
	glPopMatrix(); //5
	glPopMatrix(); //4

	glPopMatrix(); //3

	// Drawing first cylinder
	glPushMatrix(); //3
	drawCylinder(1.1, 0.85);
	glPopMatrix(); //3

	// Drawing second cylinder on top of first cylinder
	glPushMatrix(); //3
	glTranslatef(0.0, 0.85, 0.0);
	drawCylinder(1.05, 1.75);
	glPopMatrix(); //3

	// Drawing third cylinde on top of second cylinder
	glPushMatrix(); //3
	glTranslatef(0.0, 2.6, 0.0);
	drawCylinder(1.0, 0.45);
	glPopMatrix(); //3

	glPushMatrix(); //3
	glTranslatef(0.0, 2.3, 0.0);
	// Drawing right hand
	glPushMatrix(); //4
	glTranslatef(0.9, 0.0, 0.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	glRotatef(-15.0, 0.0, 0.0, 1.0);
	drawCone(0.25, 1.60);
	glPopMatrix(); //4

	// Drawing left hand
	glPushMatrix(); //4
	glTranslatef(-0.9, 0.0, 0.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	glRotatef(15.0, 0.0, 0.0, 1.0);
	drawCone(0.25, 1.60);
	glPopMatrix(); //4

	glPopMatrix(); //3

	glPushMatrix(); //3
	glTranslatef(0.0, 3.1, -1.05);
	if (isTalking)
	{
		if (isOpen)
		{
			float angle = mouthAngle;
			glRotatef(-angle, 1.0, 0.0, 0.0);
			mouthAngle += 3;
			if (mouthAngle >= 35)
				isOpen = false;
		}
		else
		{
			float angle = mouthAngle;
			glRotatef(-angle, 1.0, 0.0, 0.0);
			mouthAngle -= 3;
			if (mouthAngle <= 0)
				isOpen = true;
		}
	}	
	drawHead(0.0, 0.0, 0.0, r, g, b, true, eyeDirX, eyeDirY, 0.0, 0.0, 0.0);
	glPopMatrix(); //3

	glPopMatrix(); //2

	glPopMatrix(); //1




}

