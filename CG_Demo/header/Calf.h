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

class Calf {

public:
	Calf();  //constructor
	~Calf();   //Destroyer

	void draw(); //A function signature

	float lenght;	//Class variable
};

