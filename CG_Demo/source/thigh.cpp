#include "Tigh.h"


Thigh::Thigh()
{
	lenght = 2.0f;
}

Thigh::~Thigh()
{
}

void Thigh::draw()
{
	glPushMatrix();
	{
		glutSolidCube(0.5);
	}
	glPopMatrix();
}
