#include "Ankle.h"

Ankle::Ankle()
{
	radius = 0.6f;
}

Ankle::~Ankle()
{
}

void Ankle::draw()
{
	glPushMatrix();
	{
		glutSolidCylinder(radius, 1, 20, 20);
		
	}
	glPopMatrix();
}
