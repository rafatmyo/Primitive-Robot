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

#include "Gun.h"

class Head {

public:
	Head();  //constructor
	~Head();   //Destroyer

	void draw(); //A function signature

	Gun* gun;

	float headsize;	//Class variable
};

