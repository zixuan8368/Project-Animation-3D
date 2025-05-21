#include <GL/glut.h>
#include "basicshape.h"


void drawCylinder(float radius, float height)
{
    const int slices = 36; // more slices = smoother cylinder

    // Create a quadric object for drawing
    GLUquadric* quad = gluNewQuadric();

    // Save the current matrix
    glPushMatrix();

    // Rotate cylinder so it's upright (along Y-axis)
    glRotatef(-90, 1, 0, 0);  // rotate -90° around X to shift from Z-axis to Y-axis

    // Draw cylinder body
    gluCylinder(quad, radius, radius, height, slices, 1);

    // Draw the bottom disk
    glPushMatrix();
    glRotatef(180, 1, 0, 0); // Flip to draw downward-facing cap
    gluDisk(quad, 0.0, radius, slices, 1);
    glPopMatrix();

    // Draw the top disk
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, height); // Move to top
    gluDisk(quad, 0.0, radius, slices, 1);
    glPopMatrix();

    // Restore matrix and free quadric
    glPopMatrix();
    gluDeleteQuadric(quad);

}

void drawSphere(float radius)
{

}

void drawHemisphere(float radius) {

    glPushMatrix();
    // Create a quadric object
    GLUquadric* quad = gluNewQuadric();

    glRotatef(90.0, 1.0, 0.0, 0.0);

    // Enable clipping plane to cut the bottom half (z < 0)
    glEnable(GL_CLIP_PLANE0);
    GLdouble clip_plane[] = { 0.0, 0.0, -1.0, 0.0 }; // z >= 0
    glClipPlane(GL_CLIP_PLANE0, clip_plane);

    // Draw the sphere (bottom half is clipped)
    gluSphere(quad, radius, 36, 18);

    // Disable clipping and clean up
    glDisable(GL_CLIP_PLANE0);
    gluDeleteQuadric(quad);

    glPopMatrix();
}

void drawHemisphereWithNeck(float radius, float neckHeight) {
    
    glPushMatrix();
    drawHemisphere(radius);
    glTranslatef(0.0, -neckHeight, 0.0);
    drawCylinder(radius, neckHeight);

    glPopMatrix();
}

void drawCube(float length, float width, float heigth)
{

}

void drawCone(float radius, float height)
{
    const int slices = 36;  // controls smoothness
    const int stacks = 1;

    GLUquadric* quad = gluNewQuadric();

    glPushMatrix();

    // Rotate so cone is upright along Y-axis
    glRotatef(-90, 1, 0, 0);

    // Draw cone body
    gluCylinder(quad, radius, 0.0, height, slices, stacks);

    // Draw base cap
    glPushMatrix();
    glRotatef(180, 1, 0, 0);  // flip to draw base disk
    gluDisk(quad, 0.0, radius, slices, 1);
    glPopMatrix();

    glPopMatrix();

    gluDeleteQuadric(quad);
}