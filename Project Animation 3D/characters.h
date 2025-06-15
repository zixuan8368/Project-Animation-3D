#ifndef CHARACTERS_H
#define CHARACTERS_H

void drawSemibot(float x, float y, float z, float r, float g, float b, float eyeDirX, float eyeDirY, float rotAngle, bool isTalking, float& mouthAngle, bool& isOpen);
void drawCrouchSemibot(float x, float y, float z, float r, float g, float b, float eyeDirX, float eyeDirY, float rotAngle);
void drawHideSemibot();
void drawHead(float x, float y, float z, float r, float g, float b, bool alive, float eyeDirX, float eyeDirY, float rotX, float rotY, float rotZ);
void drawSemibot2(float x, float y, float z, float r, float g, float b, float eyeDirX, float eyeDirY, float rotAngle, bool isTalking, float& mouthAngle, bool& isOpen,bool isWalking, float& legAngle, bool& isForward);
void drawEnemy3D();
void drawHuntsman();
void drawRobe(float x, float y, float z, float rotAngle, bool isWalking);


#endif
