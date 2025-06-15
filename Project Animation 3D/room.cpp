#include <GL/glut.h>
#include "room.h"
#include "basicshape.h"
#include "object.h"



void room1()
{
	GLfloat concrete_ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };
	GLfloat concrete_diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat concrete_specular[] = { 0.1f, 0.1f, 0.1f, 1.0f };  // Still low for dull surface
	GLfloat concrete_shininess[] = { 5.0f };                   // Low shininess for matte finish

	glMaterialfv(GL_FRONT, GL_AMBIENT, concrete_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, concrete_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, concrete_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, concrete_shininess);

	glPushMatrix(); //1
	drawSphere(0.2);


	glPushMatrix(); //2


	// Drawing floor
	glPushMatrix(); //3
	glTranslatef(0.0, -25.0, 0.0);
	drawCube(60.0, 60.0, 50.0);
	glPopMatrix(); //3

	// Drawing hallway outside the room1
	glPushMatrix();
	glTranslatef(0.0, -25.0, 60.0);
	drawCube(15.0, 60.0, 50.0);
	glPopMatrix();


	// Drawing Wall #1 (without door right)
	glPushMatrix(); //3
	glTranslatef(30.0, 17.5, 0.0);
	drawCube(3.0, 60.0, 35.0);
	glPopMatrix(); //3

	// Drawing Wall #2 (without door front)
	glPushMatrix();
	glTranslatef(0.0, 17.5, -30.0);
	drawCube(60.0, 3.0, 35.0);
	glPopMatrix();

	// Drawing Wall #3 (without door left)
	glPushMatrix(); //3
	glTranslatef(-30.0, 17.5, 0.0);
	drawCube(3.0, 60.0, 35.0);
	glPopMatrix(); //3

	// Drawing Wall #4 (left side)
	glPushMatrix();
	glTranslatef(18.0, 17.5, 28.5);
	drawCube(21.0, 3.0, 35.0);
	glPopMatrix();

	// Drawing Wall #5 (right side)
	glPushMatrix();
	glTranslatef(-18.0, 17.5, 28.5);
	drawCube(21.0, 3.0, 35.0);
	glPopMatrix();

	// Drawing Wall #6 (top side)
	glPushMatrix();
	glTranslatef(0.0, 27.5, 28.5);
	drawCube(15.0, 3.0, 15.0);
	glPopMatrix();

	// Drawing Wall #1 (outside room1)
	glPushMatrix();
	glTranslatef(30.0, 0.0, 60.0);
	drawCube(3.0, 60.0, 100.0);
	glPopMatrix();

	// Drawing Wall #2 (outside room1)
	glPushMatrix();
	glTranslatef(-30.0, 0.0, 60.0);
	drawCube(3.0, 60.0, 100.0);
	glPopMatrix();

	// Drawing floor (room2)
	glPushMatrix(); //3
	glTranslatef(0.0, -25.0, 120.0);
	drawCube(60.0, 60.0, 50.0);
	glPopMatrix(); //3

	// Drawing Wall #1 (room2 right side)
	glPushMatrix();
	glTranslatef(18.0, 17.5, 91.5);
	drawCube(21.0, 3.0, 35.0);
	glPopMatrix();

	// Drawing Wall #2 (room2 left side)
	glPushMatrix();
	glTranslatef(-18.0, 17.5, 91.5);
	drawCube(21.0, 3.0, 35.0);
	glPopMatrix();

	// Drawing Wall #3 (room 2 top side)
	glPushMatrix();
	glTranslatef(0.0, 27.5, 91.5);
	drawCube(15.0, 3.0, 15.0);
	glPopMatrix();

	// Drawing Wall #4 (right wall)
	glPushMatrix(); //3
	glTranslatef(30.0, 17.5, 120.0);
	drawCube(3.0, 60.0, 35.0);
	glPopMatrix(); //3

	// Drawing Wall #5 (left wall)
	glPushMatrix(); //3
	glTranslatef(-30.0, 17.5, 120.0);
	drawCube(3.0, 60.0, 35.0);
	glPopMatrix(); //3
	
	//_________________________________________________________________________//
	
	// Drawing Wall #1 (room2 right side)
	glPushMatrix();
	glTranslatef(18.0, 17.5, 151.5);
	drawCube(21.0, 3.0, 35.0);
	glPopMatrix();

	// Drawing Wall #2 (room2 left side)
	glPushMatrix();
	glTranslatef(-18.0, 17.5, 151.5);
	drawCube(21.0, 3.0, 35.0);
	glPopMatrix();

	// Drawing Wall #3 (room 2 top side)
	glPushMatrix();
	glTranslatef(0.0, 27.5, 151.5);
	drawCube(15.0, 3.0, 15.0);
	glPopMatrix();

	// Drawing floor #1
	glPushMatrix(); //3
	glTranslatef(0.0, -25.0, 180.0);
	drawCube(60.0, 60.0, 50.0);
	glPopMatrix(); //3

	//___________________________________________________________________________//

	// Drawing table
	glPushMatrix();
	glTranslatef(25, 0.0, 0.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	drawTable(0.0, 0.0, 0.0);
	glPopMatrix();

	// Drawing chair1
	glPushMatrix();
	glTranslatef(19.5, 0.0, -4.0);
	glRotatef(70.0, 0.0, 1.0, 0.0);
	glScalef(2.0, 2.0, 2.0);
	drawChair(0.0, 0.0, 0.0);
	glPopMatrix();

	// Drawing chair2
	glPushMatrix();
	glTranslatef(21.3, 0.0, 2.5);
	glRotatef(124.0, 0.0, 1.0, 0.0);
	glScalef(2.0, 2.0, 2.0);
	drawChair(0.0, 0.0, 0.0);
	glPopMatrix();

	// Drawing chair3 (flipped)
	glPushMatrix();
	glTranslatef(24.0, 2.22, 17.0);
	glRotatef(225.0, 0.0, 1.0, 0.0);
	glRotatef(-90.0, 0.0, 0.0, 1.0);
	glScalef(2.0, 2.0, 2.0);
	drawChair(0.0, 0.0, 0.0);
	glPopMatrix();

	// Drawing chair4 (flipped)
	glPushMatrix();
	glTranslatef(-5.0, 2.22, -15);
	glRotatef(24.0, 0.0, 1.0, 0.0);
	glRotatef(-90.0, 0.0, 0.0, 1.0);
	glScalef(2.0, 2.0, 2.0);
	drawChair(0.0, 0.0, 0.0);
	glPopMatrix();

	// Drawing chair5
	glPushMatrix();
	glTranslatef(-18, 0.0, 6.5);
	glRotatef(-45.0, 0.0, 1.0, 0.0);
	glScalef(2.0, 2.0, 2.0);
	drawChair(0.0, 0.0, 0.0);
	glPopMatrix();

	
	// Drawing cupboard1
	glPushMatrix();
	drawCupboard(24.0, 0.0, -27.0);
	glPopMatrix();

	// Drawing cupboard2
	glPushMatrix();
	drawCupboard(16.5, 0.0, -27.0);
	glPopMatrix();

	// Drawing cupboard3
	glPushMatrix();
	drawCupboard(9.0, 0.0, -27.0);
	glPopMatrix();

	// Drawing cupboard4 (flipped)
	glPushMatrix();
	glTranslatef(-25.0, 7, -2.0);
	glRotatef(70.0, 0.0, 1.0, 0.0);
	glRotatef(-90.0, 0.0, 0.0, 1.0);
	glScalef(2.0, 2.0, 2.0);
	drawCupboard(0.0, 0.0, 0.0);
	glPopMatrix();

	// Drawing table (room 2)
	glPushMatrix();
	glTranslatef(-25, 0.0, 135.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	drawTable(0.0, 0.0, 0.0);
	glPopMatrix();

	// Drawing chair (room 2)
	glPushMatrix();
	glTranslatef(-21.3, 0.0, 132.0);
	glRotatef(312.0, 0.0, 1.0, 0.0);
	glScalef(2.0, 2.0, 2.0);
	drawChair(0.0, 0.0, 0.0);
	glPopMatrix();
	
	// Drawing cupboard #1 (room2)
	glPushMatrix();
	glTranslatef(-26.6, 0.0, 115.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	drawCupboard(0.0, 0.0, 0.0);
	glPopMatrix();
	

	// Drawing cupboard #2 (room2)
	glPushMatrix();
	glTranslatef(24, 1.5, 123.0);
	glRotatef(140.0, 0.0, 1.0, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	drawCupboard(0.0, 0.0, 0.0);
	glPopMatrix();





	glPopMatrix(); //2

	glPopMatrix(); //1
}

void room2()
{

}

