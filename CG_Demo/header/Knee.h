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

class Knee {

public:
	Knee();  //constructor
	~Knee();   //Destroyer

	void draw(); //A function signature

	float radiusk;	//Class variable
};

