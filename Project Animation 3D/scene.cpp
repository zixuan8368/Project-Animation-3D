#include <GL/glut.h>
#include <math.h>
#include <algorithm>
#include "scene.h"
#include "characters.h"
#include "basicshape.h"
#include "Object.h"
#include "room.h"
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

const int FPS = 60;
int counter = 0;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

float mouthAngle[6] = { 0, 0, 0, 0, 0, 0 };
bool isOpen[6] = { true, true, true, true, true, true };
float legAngle[6] = { 0, 0, 0, 0, 0, 0 };
bool isForward[6] = { true, true, true, true, true, true };

float r = 1;
float g = 1;
float b = 0.365;


int scene1()
{
	if (counter == 0)
	{
		DWORD volume = 0x4CCC4CCC; // 30% volume for both left and right channels
		waveOutSetVolume(NULL, volume);
		PlaySound(TEXT("REPO.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}


	room1();

	

	counter++;
	if (counter >= 5 * FPS)
	{
		counter = 0;
		return 1;
	}
	else
		return 0;
}

float value21;
float value22;
// Wake up in the garden
int scene2()
{
	// ==== CAMERA ANIMATION ====
	float camX = 0.0f;
	float camY = 4.0f;
	float camZ = 200.0f;

	if (counter <= 200)
	{
		// Red semibot look up brom the ground and saw blue semibot wall into the room infront of him
		value21 = -4.0 + counter * 0.04;
		value22 = 195 - counter * 0.15;
		gluLookAt(camX, camY, camZ, 0.0, value21 < 4 ? value21: 4, 185.0, 0.0, 1.0, 0.0);
		glPushMatrix();
		glTranslatef(5.0, 0.0, value22);
		glRotatef(180, 0.0, 1.0, 0.0);
		glScalef(1.7, 1.7, 1.7);
		drawSemibot2(0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, false, mouthAngle[2], isOpen[2], true, legAngle[2], isForward[2]);
		glPopMatrix();
	}
	else if(counter <= 650)
	{
		// Red semibot look left and right to check the surrounding
		gluLookAt(camX, camY, camZ,  2 * sin((counter - 200) * 0.014), 4.0, 185.0, 0.0, 1.0, 0.0);
		// While blue semibot still walking into the room
		glPushMatrix();
		glTranslatef(5.0, 0.0, value22 - (counter - 200) * 0.15);
		glRotatef(180, 0.0, 1.0, 0.0);
		glScalef(1.7, 1.7, 1.7);
		drawSemibot2(0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, false, mouthAngle[2], isOpen[2], true, legAngle[2], isForward[2]);
		glPopMatrix();
	}
	else
	{
		gluLookAt(camX, camY, camZ - (counter - 650) * 0.15, 0.0, 4.0, 0.0, 0.0, 1.0, 0.0);
	}
	room1();

	counter++;
	if (counter >= 15 * FPS)
	{
		counter = 0;
		return 1;
	}
	else
		return 0;
}

float value31;
float value32;
// Walking inside the room
int scene3()
{	
	// ==== CAMERA ANIMATION ====
	float camX = 23.0f;
	float camY = 25.0f;
	float camZ = 105.0f;
	gluLookAt(camX, camY, camZ, 0.0, 3.0, 135.0 - counter * 0.05, 0.0, 1.0, 0.0);
	room1();

	if (counter == 0)
	{
		DWORD volume = 0x7FFF7FFF; // 50% volume for both left and right channels
		waveOutSetVolume(NULL, volume);
		PlaySound(TEXT("Boombox Music.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}

	// First orb beside the flipped cupboard
	glPushMatrix();
	glTranslatef(10.0, 2.0, 125.0);
	glScalef(1.1, 1.1, 1.1);
	drawOrb(0.0, 0.0, 0.0);
	glPopMatrix();

	// Second orb on the another cupboard
	glPushMatrix();
	glTranslatef(-21.0, 2.0, 105.0);
	glScalef(1.1, 1.1, 1.1);
	drawOrb(0.0, 0.0, 0.0);
	glPopMatrix();

	// Red semibot, look around and try to go to next room to find loot
	glPushMatrix();
	glTranslatef(1.0, 0.0 ,160.0 - counter * 0.12);
	glScalef(1.7, 1.7, 1.7);
	glRotatef(180 + 30 * sin(counter * 0.085), 0.0, 1.0, 0.0);
	drawSemibot2(0.0, 0.0, 0.0, 1.0, 0.0, 0.0, sin(counter * 0.085), 0.0, 0.0, false, mouthAngle[0], isOpen[0], true, legAngle[0], isForward[0]);
	glPopMatrix();

	// Green semibot, directly run toward the next room while playing music or talking
	glPushMatrix();
	glTranslatef(-4.0, 0.0, 175.0 - counter * 0.22);
	glScalef(1.7, 1.7, 1.7);
	glRotatef(180, 0.0, 1.0, 0.0);
	drawSemibot2(0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, true, mouthAngle[1], isOpen[1], true, legAngle[1], isForward[1]);
	glPopMatrix();

	// Blue semibot, try to pick up the second orb
	glPushMatrix();

	if (counter <= 185)
	{	
		value31 = 19.0 - counter * 0.15;
		glTranslatef(value31, 0.0, 115);
		glRotatef(270, 0.0, 1.0, 0.0);
		glScalef(1.7, 1.7, 1.7);
		drawSemibot2(0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, false, mouthAngle[2], isOpen[2], true, legAngle[2], isForward[2]);
	}
	else if (counter <= 300)
	{
		value32 = 270 - (counter - 185) * 0.2;
		glTranslatef(value31, 0.0, 115);
		glRotatef(value32, 0.0, 1.0, 0.0);
		glScalef(1.7, 1.7, 1.7);
		drawSemibot2(0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, false, mouthAngle[2], isOpen[2], false, legAngle[2], isForward[2]);
	}
	else
	{
		glTranslatef(value31 - (counter - 300) * 0.07, 0.0, 115 - (counter - 300) * 0.033);
		glRotatef(value32, 0.0, 1.0, 0.0);
		glScalef(1.7, 1.7, 1.7);
		drawSemibot2(0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, false, mouthAngle[2], isOpen[2], true, legAngle[2], isForward[2]);
	}

	glPopMatrix();

	counter++;
	if (counter >= 8 * FPS)
	{
		PlaySound(NULL, 0, 0); // Stop
		counter = 0;
		return 1;
	}
	else
		return 0;
}


int scene4()
{
	// ==== CAMERA ANIMATION ====
	float camX = 23.0f;
	float camY = 25.0f;
	float camZ = 105.0f;
	//gluLookAt(camX, camY, camZ, 0.0, 3.0, 135.0 - counter * 0.05, 0.0, 1.0, 0.0);
	
	counter++;
	if (counter >= 10 * FPS)
	{
		counter = 0;
		return 1;
	}
	else
		return 0;
}

int scene5()
{
	// ==== CAMERA ANIMATION ====
	float camX = 0.0f;
	float camY = 0.0f;
	float camZ = 5.0f;
	//gluLookAt(camX, camY, camZ,    // Camera position
	//	0.0, 0.0, 0.0,      // Look at center
	//	0.0, 1.0, 0.0);      // Up vector

	room1();

	glPushMatrix();
	glTranslatef(18.0, 0.0, 10.0);
	glScalef(1.7, 1.7, 1.7);
	drawSemibot2(0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, false, mouthAngle[0], isOpen[0], false, legAngle[0], isForward[0]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(25.0, 0.0, 0.0);
	glRotatef(-45, 0.0, 1.0, 0.0);
	glScalef(1.5, 1.5, 1.5);
	drawCrouchSemibot(0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0);
	glPopMatrix();

	// Drawing Orb(on the table)
	glPushMatrix();
	glTranslatef(25.0, 7.9, 1.0);
	glScalef(1.1, 1.1, 1.1);
	drawOrb(0.0, 0.0, 0.0);
	glPopMatrix();

	// Drawing Sword (leaning on the wall)
	glPushMatrix();
	glTranslatef(-26.0, 1.5, 20.0);
	glRotatef(15.0, 0.0, 0.0, 1.0);
	glScalef(2.5, 2.5, 2.5);
	drawSword(0.0, 0.0, 0.0);
	glPopMatrix();

	counter++;
	if (counter >= 10 * FPS)
	{
		counter = 0;
		return 1;
	}
	else
		return 0;
}

int scene6()
{

	counter++;
	if (counter >= 2 * FPS)
	{
		counter = 0;
		return 1;
	}
	else
		return 0;
}

// Blue semibot playing some music and killed by robe
int scene7()
{

	// ==== CAMERA ANIMATION ====
	if(counter <540)
	{
		float camX = -23.0f;
		float camY = 2.0f;
		float camZ = 25.0f;
		gluLookAt(camX, camY, camZ, 0.0, 5.0, 21.0, 0.0, 1.0, 0.0);
	}

	if (counter <= 60)
	{
		if (counter == 55)
		{
			DWORD volume = 0x7FFF7FFF; // 50% volume for both left and right channels
			waveOutSetVolume(NULL, volume);
			PlaySound(TEXT("Robe.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
		glPushMatrix();
		glTranslatef(0.0, 0.0, 12.0);
		glScalef(1.7, 1.7, 1.7);
		glRotatef(0.0, 0.0, 1.0, 0.0);
		drawSemibot2(0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, false, mouthAngle[1], isOpen[1], false, legAngle[1], isForward[1]);
		glPopMatrix();
	}
	else if(counter <= 400)
	{	
		if (counter == 325)
		{
			DWORD volume = 0x7FFF7FFF; // 50% volume for both left and right channels
			waveOutSetVolume(NULL, volume);
			PlaySound(TEXT("Semibot die.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
		glPushMatrix();
		glTranslatef(0.0, 0.0, 12 + (counter - 60) * 0.1);
		glScalef(1.7, 1.7, 1.7);
		glRotatef(0.0, 0.0, 1.0, 0.0);
		drawSemibot2(0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, true, mouthAngle[1], isOpen[1], true, legAngle[1], isForward[1]);
		glPopMatrix();
	}
	else
	{
		glPushMatrix();
		glTranslatef(0.0, 10.0 - (counter - 400) * 0.06, 35 - (counter - 400) * 0.3);
		glScalef(1.4, 1.4, 1.4);
		glRotatef(counter * 15, 1.0, 1.0, 1.0);
		drawHead(0.0, 0.0, 0.0, 0.0, 1.0, 0.0, false, 0.0, 0.0, 0.0, 0.0, 0.0);
		glPopMatrix();
	}

	if (counter >= 540)
	{
		float camX = -19.0f;
		float camY = 8.0f;
		float camZ = 20.0f;
		gluLookAt(camX, camY, camZ, -30.0, 8.0, 20.0, 0.0, 1.0, 0.0);
		glPushMatrix();
		glTranslatef(-23.0, 0.0, 20);
		glScalef(1.7, 1.7, 1.7);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		drawSemibot2(0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, false, mouthAngle[1], isOpen[1], false, legAngle[1], isForward[1]);
		glPopMatrix();
	}
	
	room1();

	counter++;
	if (counter >= 10 * FPS)
	{
		PlaySound(NULL, 0, 0); // Stop
		counter = 0;
		return 1;
	}
	else
		return 0;
}

int scene8()
{

	counter++;
	if (counter >= 2 * FPS)
	{
		counter = 0;
		return 1;
	}
	else
		return 0;
}

bool temp = true;

int scene9()
{
	if (temp)
	{
		DWORD volume = 0xFFFFFFFF;
		PlaySound(TEXT("I love.wav"), NULL, SND_FILENAME | SND_ASYNC);
		temp = false;
	}
	// ==== CAMERA ANIMATION ====
	float camX = 0.0f;
	float camY = 15.0f;
	float camZ = 1.0f;
	gluLookAt(camX, camY, camZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);    

	room2();

	if (counter <= 0.7 * FPS)
	{
		glPushMatrix();
		glTranslatef(0.0, 2.2, 0.0);
		glRotatef(-15.0, 0.0, 1.0, 0.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glScalef(1.5, 1.5, 1.5);
		drawLoveSemibot(1.0, 1.0, 0.0, false, mouthAngle[5], true, legAngle[5], isForward[5]);
		glPopMatrix();
	}
	else if(counter <= 2.4 * FPS)
	{
		glPushMatrix();
		glTranslatef(0.0, 2.2, 0.0);
		glRotatef(-15.0, 0.0, 1.0, 0.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glScalef(1.5, 1.5, 1.5);
		drawLoveSemibot(1.0, 1.0, 0.0, true, mouthAngle[5], true, legAngle[5], isForward[5]);
		glPopMatrix();
	}
	else if (counter <= 2.9 * FPS)
	{
		glPushMatrix();
		glTranslatef(0.0, 2.2, 0.0);
		glRotatef(-15.0, 0.0, 1.0, 0.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glScalef(1.5, 1.5, 1.5);
		drawLoveSemibot(1.0, 1.0, 0.0, false, mouthAngle[5], false, legAngle[5], isForward[5]);
		glPopMatrix();
	}
	else if(counter <= 4.3 * FPS)
	{
		glPushMatrix();
		glTranslatef(0.0, 2.2, 0.0);
		glRotatef(-15.0, 0.0, 1.0, 0.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glScalef(1.5, 1.5, 1.5);
		drawLoveSemibot(1.0, 1.0, 0.0, true, mouthAngle[5], false, legAngle[5], isForward[5]);
		glPopMatrix();
	}
	else if (counter <= 5.6 * FPS)
	{
		glPushMatrix();
		glTranslatef(0.0, 2.2, 0.0);
		glRotatef(-15.0, 0.0, 1.0, 0.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glScalef(1.5, 1.5, 1.5);
		drawLoveSemibot(1.0, 1.0, 0.0, false, mouthAngle[5], false, legAngle[5], isForward[5]);
		glPopMatrix();
	}
	else if (counter <= 9.3 * FPS)
	{
		glPushMatrix();
		glTranslatef(0.0, 2.2, 0.0);
		glRotatef(-15.0, 0.0, 1.0, 0.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glScalef(1.5, 1.5, 1.5);
		drawLoveSemibot(1.0, 1.0, 0.0, true, mouthAngle[5], true, legAngle[5], isForward[5]);
		glPopMatrix();
	}
	else if (counter <= 10.4 * FPS)
	{
		glPushMatrix();
		glTranslatef(0.0, 2.2, 0.0);
		glRotatef(-15.0, 0.0, 1.0, 0.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glScalef(1.5, 1.5, 1.5);
		drawLoveSemibot(1.0, 1.0, 0.0, false, mouthAngle[5], true, legAngle[5], isForward[5]);
		glPopMatrix();
	}
	else if (counter <= 12.0 * FPS)
	{
		glPushMatrix();
		glTranslatef(0.0, 2.2, 0.0);
		glRotatef(-15.0, 0.0, 1.0, 0.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glScalef(1.5, 1.5, 1.5);
		drawLoveSemibot(1.0, 1.0, 0.0, true, mouthAngle[5], true, legAngle[5], isForward[5]);
		glPopMatrix();
	}
	else if (counter <= 12.4 * FPS)
	{
		glPushMatrix();
		glTranslatef(0.0, 2.2, 0.0);
		glRotatef(-15.0, 0.0, 1.0, 0.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glScalef(1.5, 1.5, 1.5);
		drawLoveSemibot(1.0, 1.0, 0.0, false, mouthAngle[5], false, legAngle[5], isForward[5]);
		glPopMatrix();
	}
	else if (counter <= 13.9 * FPS)
	{
		glPushMatrix();
		glTranslatef(0.0, 2.2, 0.0);
		glRotatef(-15.0, 0.0, 1.0, 0.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glScalef(1.5, 1.5, 1.5);
		drawLoveSemibot(1.0, 1.0, 0.0, true, mouthAngle[5], true, legAngle[5], isForward[5]);
		glPopMatrix();
	}
	else if (counter <= 19.7 * FPS)
	{
		glPushMatrix();
		glTranslatef(0.0, 2.2, 0.0);
		glRotatef(-15.0, 0.0, 1.0, 0.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glScalef(1.5, 1.5, 1.5);
		drawLoveSemibot(1.0, 1.0, 0.0, true, mouthAngle[5], true, legAngle[5], isForward[5]);
		glPopMatrix();
	}
	else
	{
		glPushMatrix();
		glTranslatef((counter - 19.7 * FPS) * 0.04, 2.2, (counter - 19.7 * FPS) * 0.015);
		glRotatef(-15.0, 0.0, 1.0, 0.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glRotatef((counter - 19.7 * FPS) * 0.5, 0.0, 1.0, 0.0);
		glScalef(1.5, 1.5, 1.5);
		drawLoveSemibot(1.0, 1.0, 0.0, false, mouthAngle[5], true, legAngle[5], isForward[5]);
		glPopMatrix();
	}
	counter++;
	if (counter >= 25 * FPS)
	{
		counter = 0;
		return 1;
	}
	else
		return 0;
}