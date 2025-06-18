#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include "scene.h"


void init();
void display();
void reshape(int, int);
void timer(int);

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int sceneNumber = 1;
const int TOTAL_SCENE = 9;
const int FRAME_PER_SECOND = 60;
const int TIME_PER_FRAME = 1000 / FRAME_PER_SECOND;
const float FIELD_OF_VIEW = 70.0;



// Camera position and direction
float cameraX = 0.0f, cameraY = 6.0f, cameraZ = 10.0f;
float pitch = 0.0f, yaw = -90.0f;
float lastX = 400, lastY = 300;
bool leftMousePressed = false;
float cameraSpeed;

// Look direction
float lookX = 0.0f, lookY = 0.0f, lookZ = -1.0f;

float deltaTime = 0.0f;
float lastFrame = 0.0f;
float baseSpeed = 45.0f; // adjustable

void updateCameraDirection() {
	float radYaw = yaw * M_PI / 180.0f;
	float radPitch = pitch * M_PI / 180.0f;

	lookX = cos(radYaw) * cos(radPitch);
	lookY = sin(radPitch);
	lookZ = sin(radYaw) * cos(radPitch);
}

void keyboard(unsigned char key, int x, int y) {
	cameraSpeed = baseSpeed * deltaTime;
	float forwardX = lookX * cameraSpeed;
	float forwardZ = lookZ * cameraSpeed;

	float rightX = -lookZ * cameraSpeed;
	float rightZ = lookX * cameraSpeed;

	switch (key) {
	case 'w': cameraX += forwardX; cameraZ += forwardZ; break;
	case 's': cameraX -= forwardX; cameraZ -= forwardZ; break;
	case 'a': cameraX -= rightX;   cameraZ -= rightZ;   break;
	case 'd': cameraX += rightX;   cameraZ += rightZ;   break;
	case 'q': cameraY += cameraSpeed; break;
	case 'e': cameraY -= cameraSpeed; break;
	case 27:  exit(0); // ESC to quit
	}

	glutPostRedisplay();
}

void mouseMotion(int x, int y) {
	if (!leftMousePressed) return;

	float xoffset = x - lastX;
	float yoffset = lastY - y;

	lastX = x;
	lastY = y;

	float sensitivity = 0.1f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f) pitch = 89.0f;
	if (pitch < -89.0f) pitch = -89.0f;

	updateCameraDirection();
	glutPostRedisplay();
}

void mouseClick(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			leftMousePressed = true;
			lastX = x;
			lastY = y;
		}
		else if (state == GLUT_UP) {
			leftMousePressed = false;
		}
	}

	// Scroll wheel zoom
	if (button == 3) { // Scroll up
		cameraX += lookX * cameraSpeed;
		cameraY += lookY * cameraSpeed;
		cameraZ += lookZ * cameraSpeed;
		glutPostRedisplay();
	}
	else if (button == 4) { // Scroll down
		cameraX -= lookX * cameraSpeed;
		cameraY -= lookY * cameraSpeed;
		cameraZ -= lookZ * cameraSpeed;
		glutPostRedisplay();
	}
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1000, 1000);


	glutCreateWindow("3D Animation");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(TIME_PER_FRAME, timer, 0);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouseClick);
	glutMotionFunc(mouseMotion);
	updateCameraDirection();
	//glutSetCursor(GLUT_CURSOR_NONE);

	init();

	glutMainLoop();
	return 0;

}


void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);  
	glEnable(GL_LIGHT0);     
	//glDisable(GL_LIGHT0);

	// Optional: define light properties
	GLfloat light_pos[] = { 0.0f, 10.0f, 0.0f, 1.0f };
	GLfloat ambient[] = { 0.6f, 0.6f, 0.6f, 1.0f };
	GLfloat diffuse[] = { 0.9f, 0.9f, 0.9f, 1.0f };
	GLfloat specular[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	// Fogs
	glEnable(GL_FOG);

	GLfloat fogColor[] = { 0.0f, 0.0f, 0.0f, 1.0f };  // black fog
	glFogfv(GL_FOG_COLOR, fogColor);

	glFogi(GL_FOG_MODE, GL_LINEAR);  // Linear fog
	glFogf(GL_FOG_START, 35.0f);     // Start fading at 90
	glFogf(GL_FOG_END, 70.0f);      // Fully dark at 100

	glDisable(GL_CULL_FACE);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	//gluLookAt(cameraX, cameraY, cameraZ, cameraX + lookX, cameraY + lookY, cameraZ + lookZ, 0.0f, 1.0f, 0.0f);

	/*switch (sceneNumber)
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
	}*/
	
	scene7();

	glutSwapBuffers();
}

void reshape(int width, int height)
{
	//glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(FIELD_OF_VIEW, 1.0, 2.0, 80.0);
	glMatrixMode(GL_MODELVIEW);

}


void timer(int)
{
	//glutPostRedisplay();
	//glutTimerFunc(TIME_PER_FRAME, timer, 0);

	float currentFrame = glutGet(GLUT_ELAPSED_TIME) / 1000.0f; // seconds
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

	glutPostRedisplay();
	glutTimerFunc(TIME_PER_FRAME, timer, 0);
}



