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
    const int slices = 36; // horizontal divisions (like longitude)
    const int stacks = 18; // vertical divisions (like latitude)

    GLUquadric* quad = gluNewQuadric();

    glPushMatrix();
    gluSphere(quad, radius, slices, stacks);  // draw the sphere
    glPopMatrix();

    gluDeleteQuadric(quad);
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

void drawCube(float length, float width, float height)
{
    float lx = length / 2.0f;
    float ly = height / 2.0f;
    float lz = width / 2.0f;

    glBegin(GL_QUADS);

    // Front face
    glNormal3f(0, 0, 1);
    glVertex3f(-lx, -ly, lz);
    glVertex3f(lx, -ly, lz);
    glVertex3f(lx, ly, lz);
    glVertex3f(-lx, ly, lz);

    // Back face
    glNormal3f(0, 0, -1);
    glVertex3f(-lx, -ly, -lz);
    glVertex3f(-lx, ly, -lz);
    glVertex3f(lx, ly, -lz);
    glVertex3f(lx, -ly, -lz);

    // Left face
    glNormal3f(-1, 0, 0);
    glVertex3f(-lx, -ly, -lz);
    glVertex3f(-lx, -ly, lz);
    glVertex3f(-lx, ly, lz);
    glVertex3f(-lx, ly, -lz);

    // Right face
    glNormal3f(1, 0, 0);
    glVertex3f(lx, -ly, -lz);
    glVertex3f(lx, ly, -lz);
    glVertex3f(lx, ly, lz);
    glVertex3f(lx, -ly, lz);

    // Top face
    glNormal3f(0, 1, 0);
    glVertex3f(-lx, ly, -lz);
    glVertex3f(-lx, ly, lz);
    glVertex3f(lx, ly, lz);
    glVertex3f(lx, ly, -lz);

    // Bottom face
    glNormal3f(0, -1, 0);
    glVertex3f(-lx, -ly, -lz);
    glVertex3f(lx, -ly, -lz);
    glVertex3f(lx, -ly, lz);
    glVertex3f(-lx, -ly, lz);

    glEnd();

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

void drawTriangularPrism(float length, float width, float height)
{
    float lx = length / 2.0f;
    float wz = width / 2.0f;
    float h = height;

    glBegin(GL_TRIANGLES);
    // Front face
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-lx, 0.0f, wz);         // Bottom-left
    glVertex3f(lx, 0.0f, wz);          // Bottom-right
    glVertex3f(0.0f, h, wz);           // Top-center

    // Back face
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-lx, 0.0f, -wz);        // Bottom-left (back)
    glVertex3f(0.0f, h, -wz);          // Top-center (back)
    glVertex3f(lx, 0.0f, -wz);         // Bottom-right (back)
    glEnd();

    glBegin(GL_QUADS);
    // Bottom face
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-lx, 0.0f, -wz);
    glVertex3f(lx, 0.0f, -wz);
    glVertex3f(lx, 0.0f, wz);
    glVertex3f(-lx, 0.0f, wz);

    // Left face
    glNormal3f(-1.0f, 1.0f, 0.0f); // approximate
    glVertex3f(-lx, 0.0f, -wz);
    glVertex3f(-lx, 0.0f, wz);
    glVertex3f(0.0f, h, wz);
    glVertex3f(0.0f, h, -wz);

    // Right face
    glNormal3f(1.0f, 1.0f, 0.0f); // approximate
    glVertex3f(lx, 0.0f, wz);
    glVertex3f(lx, 0.0f, -wz);
    glVertex3f(0.0f, h, -wz);
    glVertex3f(0.0f, h, wz);
    glEnd();
}

void drawPyramid(float length, float width, float height)
{
    float lx = length / 2.0f;
    float lz = width / 2.0f;

    glBegin(GL_TRIANGLES);
    // Front face
    glNormal3f(0.0f, 0.5f, 1.0f);
    glVertex3f(-lx, 0.0f, lz);
    glVertex3f(lx, 0.0f, lz);
    glVertex3f(0.0f, height, 0.0f);

    // Right face
    glNormal3f(1.0f, 0.5f, 0.0f);
    glVertex3f(lx, 0.0f, lz);
    glVertex3f(lx, 0.0f, -lz);
    glVertex3f(0.0f, height, 0.0f);

    // Back face
    glNormal3f(0.0f, 0.5f, -1.0f);
    glVertex3f(lx, 0.0f, -lz);
    glVertex3f(-lx, 0.0f, -lz);
    glVertex3f(0.0f, height, 0.0f);

    // Left face
    glNormal3f(-1.0f, 0.5f, 0.0f);
    glVertex3f(-lx, 0.0f, -lz);
    glVertex3f(-lx, 0.0f, lz);
    glVertex3f(0.0f, height, 0.0f);
    glEnd();

    // Base (drawn separately as a quad)
    glBegin(GL_QUADS);
    glNormal3f(0.0f, -1.0f, 0.0f); // Facing downward
    glVertex3f(-lx, 0.0f, lz);
    glVertex3f(lx, 0.0f, lz);
    glVertex3f(lx, 0.0f, -lz);
    glVertex3f(-lx, 0.0f, -lz);
    glEnd();
}


