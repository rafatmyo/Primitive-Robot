#include "Calf.h"


Calf::Calf()
{
	lenght = 2.0f;
}

Calf::~Calf()
{
}

void Calf::draw()
{
	glPushMatrix();
	{
		glutSolidCube(0.5);
	}
	glPopMatrix();
}
