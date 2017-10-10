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

class Gun
{
public:
	Gun();  //constructor
	~Gun();   //Destroyer

	void draw(); //A function signature

	float gunsize;	//Class variable
};

