#include "union.h"

Union::Union()
{
	rad = 0.10f;
}

Union::~Union()
{
}

void Union::draw()
{
	glPushMatrix();
	{
		glColor3f(1, 0, 0);
		glTranslatef(0.0f, 0.3f, -0.02f);
		glutSolidCylinder(rad, 0.8f, 10, 10);

		glPushMatrix();
		{
			glColor3f(0, 0, 1);
			glTranslatef(0.0f, 0.3f, 0.45f);
			glRotatef(90, 1, 0, 0);
			glutSolidCylinder(rad-0.05f, 0.4, 10, 10);
		}
		glPopMatrix();

	}
	glPopMatrix();
}
