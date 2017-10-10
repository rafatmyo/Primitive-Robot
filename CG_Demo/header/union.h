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

class Union {

public:
	Union();  //constructor
	~Union();   //Destroyer

	void draw(); //A function signature

	float rad;	//Class variable
};

#pragma once
