#include "Head.h"

Head::Head()
{
	gun = new Gun();

	 headsize = 0.6f;
}

Head::~Head()
{
}

void Head::draw()
{
	glPushMatrix();
	{

		glColor3f(1, 0, 0);
		glTranslatef(0, 0.8f, 0);
		glutSolidCube(headsize);
		
		glPushMatrix();
		{
			glColor4f(1.0, 1.0, 0.0, 0.75);
			glTranslatef(-0.7f, -0.1f, 0.35f);
			glScalef(0.1f, 0.1f, 0.1f);
			gun->draw();

		}
		glPopMatrix();

		glPushMatrix();
		{
			glColor4f(1.0, 1.0, 0.0, 0.75);
			glTranslatef(-0.7f, -0.1f, -0.35f);
			glScalef(0.1f, 0.1f, 0.1f);
			gun->draw();

		}
		glPopMatrix();

		glPushMatrix();
		{
			glColor4f(1.0, 1.0, 0.0, 0.75);
			glTranslatef(-0.8f, 0.1f, 0.0f);
			glScalef(0.1f, 0.1f, 0.1f);
			gun->draw();

		}
		glPopMatrix();


	}
	glPopMatrix();
}
