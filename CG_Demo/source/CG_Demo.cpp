/*
* Rafael Tamayo A01421337
* Rogger Barcena A01335167
*
* TC3022. Computer Graphics Course.
* Object-Oriented Programming example.
*/

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

#include "cLeg.h"
#include "union.h"
#include "Head.h"

Head* head;
Leg* LeftLeg;
Leg* RightLeg;
Union* Unnion;
float xleg;
float yleg;

float rotleg;
float rotReg;

float dirL;
float dirR;
float road1;

void init()
{
	
	xleg = 0.0;
	yleg = -0.3;
	rotleg = -45.0;
	rotReg = -45.0;

	dirL = 3.0f;
	dirR = 3.0f;

	road1 = 0.0;

	LeftLeg = new Leg();
	RightLeg = new Leg();
	Unnion = new Union();
	head = new Head();

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);			// Enable check for close and far objects.
	glClearColor(0.0, 0.0, 0.0, 0.0);	// Clear the color state.
	glMatrixMode(GL_MODELVIEW);			// Go to 3D mode.
	glLoadIdentity();					// Reset 3D view matrix.
}

void display()							// Called for each frame (about 60 times per second).
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				// Clear color and depth buffers.


	glPushMatrix();
	{
		glTranslatef(-xleg, -yleg, 0);		// Position at the edge
		glRotatef(rotleg, 0, 1, 0);		// Rotate
		glTranslatef(xleg, yleg, 0);		// Take back
			head->draw();
	}
	glPopMatrix();
	
	glPushMatrix();
	{
		glTranslatef(-xleg, -yleg, 0);		// Position at the edge
		glRotatef(rotleg, 0, 0, 1);		// Rotate
		glTranslatef(xleg, yleg, 0);		// Take back
		LeftLeg->draw();
	}
	glPopMatrix();

	glPushMatrix();
	{

		glTranslatef(-xleg, -yleg, -0.3f);
		glRotatef(-rotReg, 0, 0, 1);		// Rotate
		glTranslatef(xleg, yleg, -0.3f);		// Take back
		RightLeg->draw();
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(0.0f, 0.0, -0.7f);
		Unnion->draw();

	}
	glPopMatrix();

	//Scenery

	
	glBegin(GL_QUADS);
	glColor3d(1, 0, 0);
	glVertex3f(-10, -2, -10);

	glColor3d(1, 0, 1);
	glVertex3f(10, -2, -10);
	glColor3d(1, 1, 1);
	glVertex3f(10, -3, -10);
	glColor3d(0, 1, 1);
	glVertex3f(-10, -3, -10);
	glEnd();

	
	glBegin(GL_QUADS);
	{
		glColor3d(1, 0, 0);
		glVertex3f(-10 + road1, -2, -9.9f);
		glVertex3f(-12 + road1, -2, -9.9f);
		glVertex3f(-12 + road1, -3, -9.9f);
		glVertex3f(-10 + road1, -3, -9.9f);
	}
	glEnd();

	glBegin(GL_QUADS);
	{
		glColor3d(1, 0, 0);
		glVertex3f(-6+road1, -2, -9.9f);
		glVertex3f(-8+road1, -2, -9.9f);
		glVertex3f(-8+road1, -3, -9.9f);
		glVertex3f(-6+road1, -3, -9.9f);
	}
	glEnd();

	glBegin(GL_QUADS);
	{
		glColor3d(1, 0, 0);
		glVertex3f(-2 + road1, -2, -9.9f);
		glVertex3f(-4 + road1, -2, -9.9f);
		glVertex3f(-4 + road1, -3, -9.9f);
		glVertex3f(-2 + road1, -3, -9.9f);
	}
	glEnd();

	glBegin(GL_QUADS);
	{
		glColor3d(1, 0, 0);
		glVertex3f(2 + road1, -2, -9.9f);
		glVertex3f(0 + road1, -2, -9.9f);
		glVertex3f(0 + road1, -3, -9.9f);
		glVertex3f(2 + road1, -3, -9.9f);
	}
	glEnd();

	glBegin(GL_QUADS);
	{
		glColor3d(1, 0, 0);
		glVertex3f(6 + road1, -2, -9.9f);
		glVertex3f(4 + road1, -2, -9.9f);
		glVertex3f(4 + road1, -3, -9.9f);
		glVertex3f(6 + road1, -3, -9.9f);
	}
	glEnd();


	glBegin(GL_QUADS);
	glColor3d(1, 1, 1);
	glVertex3f(10, -3, -10);
	glVertex3f(-10, -3, -10);
	glVertex3f(-10, 20, -10);
	glVertex3f(10, 20, -10);

	glEnd();

	



	glutSwapBuffers();												// Swap the hidden and visible buffers.

}

void idle()															// Called when drawing is finished.
{

	

	if (road1 >= 4)
	{
		road1 = 0.0;
	}

	road1 += 0.01;


	rotleg += dirL * 0.05f;

	if (rotleg > 60 || rotleg < -45)
	{
		dirL = -dirL;
	}

	rotReg += dirR * 0.05f;

	if (rotReg > 60 || rotReg < -45)
	{
		dirR = -dirR;
	}

	glutPostRedisplay();											// Display again.
}

void reshape(int x, int y)											// Called when the window geometry changes.
{
	glMatrixMode(GL_PROJECTION);	 // 2D								// Go to 2D mode.
	glLoadIdentity();												// Reset the 2D matrix.
	gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);		// Configure the camera lens aperture.
	glMatrixMode(GL_MODELVIEW); // 3D										// Go to 3D mode.
	glViewport(0, 0, x, y);											// Configure the camera frame dimensions.
	gluLookAt(0.0, 0.0, 9.0,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);
	display();
}



int main(int argc, char* argv[])
{
	glutInit(&argc, argv);											// Init GLUT with command line parameters.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);		// Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
	glutInitWindowSize(800, 800);
	glutCreateWindow(argv[0]);

	init();
	glutReshapeFunc(reshape);										// Reshape CALLBACK function.
	glutDisplayFunc(display);										// Display CALLBACK function.
	glutIdleFunc(idle);												// Idle CALLBACK function.

	glutMainLoop();													// Begin graphics program.
	return 0;														// ANSI C requires a return value.
}