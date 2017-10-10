#include "cFoot.h"

Foot::Foot()
{
	radius = 2.0f;
}

Foot::~Foot()
{
}

void Foot::draw()
{
	glPushMatrix();
	{
		glutSolidCube(2);
	}
	glPopMatrix();
}
