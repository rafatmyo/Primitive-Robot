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

class Thigh {

public:
	Thigh();  //constructor
	~Thigh();   //Destroyer

	void draw(); //A function signature

	float lenght;	//Class variable
};

