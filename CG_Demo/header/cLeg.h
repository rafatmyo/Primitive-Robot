#pragma once
#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
	#include <GLUT/glut.h>
	#include <math.h>
#else
	#include "freeglut.h"
	#include <stdio.h>
	#include <math.h>
#endif

#include "cFoot.h"
#include "Ankle.h"
#include "Calf.h"
#include "Knee.h"
#include "Tigh.h"

class Leg
{
public:
	Leg();
	~Leg();

	void draw();

	// Instance these in the constructor:
	Foot* foot;	//pointer to a foot
	Ankle* ankle;
	Calf* calf;
	Knee* knee;
	Thigh* thigh;

	float zRot;
};

