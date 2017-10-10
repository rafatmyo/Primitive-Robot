#include "Knee.h"

Knee::Knee()
{
	radiusk = 0.6f;
}

Knee::~Knee()
{
}

void Knee::draw()
{
	glPushMatrix();
	{

		glutSolidCylinder(radiusk, 3, 20, 20);

	}
	glPopMatrix();
}
