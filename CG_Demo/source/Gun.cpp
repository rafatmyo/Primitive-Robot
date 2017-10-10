#include "Gun.h"

Gun::Gun()
{
	gunsize =10.0f;
}

Gun::~Gun()
{
}

void Gun::draw()
{
	glPushMatrix();
	{
		glRotatef(90, 0, 1, 0);
		glutSolidCylinder(0.5f, gunsize, 20, 10);
	}
	glPopMatrix();
}
