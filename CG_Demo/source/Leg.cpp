#include "cLeg.h"
float dir2;

Leg::Leg()
{
	foot = new Foot();
	ankle = new Ankle();
	calf = new Calf();
	knee = new Knee();
	thigh = new Thigh();

	/*second = new Wheel();
	third = new Wheel();
	fourth = new Wheel();*/
	dir2 = 2.0;
	zRot = 0.0f;
}

Leg::~Leg()
{
	delete foot;
	delete ankle;
	delete calf;
	delete knee;
	delete thigh;
}

void Leg::draw()
{
	glPushMatrix();
	{
		/*glPushMatrix();
		{
			
			glScalef(1, 0.2, 1);
			glutWireCube(1.0);
		}
		glPopMatrix();*/

		glPushMatrix();
		{
			glColor3f(0, 0, 1);
			/*glTranslatef(0.0f, 0.0f, 0.0f);*/
			glScalef(0.2f, 1.5f, 0.15f);
			thigh->draw();

			glPushMatrix();
			{
				glColor3f(1, 0, 0);

				//glTranslatef(-xleg, -yleg, 0);		// Position at the edge
				//glRotatef(-rotleg, 0, 0, 1);		// Rotate
				//glTranslatef(xleg, yleg, 0);		// Take back

				glTranslatef(-0.0f, -0.3f, -0.3f);
				glScalef(0.8f, -0.1f, 0.2f);
				glTranslatef(-0.0f, -0.3f, -0.3f);
				glRotatef(-zRot, 0, 0, 1);
				glTranslatef(0.0f, 0.3f, 0.3f);
				knee->draw();

				glPushMatrix();
				{
					glColor3f(0, 0, 1);
					glTranslatef(0.0f, 2.0f, 1.5f);
					glScalef(1.0f, 6.0f, 5.0f);
					glRotatef(0, 0, 0, 1);
					calf->draw();

					glPushMatrix();
					{
						glColor3f(1, 0, 0);
						glTranslatef(0.0f, 0.3f, -0.24f);
						glScalef(1.0f, 0.15f, 0.5f);
						glRotatef(0, 0, 0, 1);
						ankle->draw();


						glPushMatrix();
						{
							glColor3f(0.0f, 1.0f, 0.0f);
							glTranslatef(-0.5f, 1.0, 0.6f);
							glScalef(1.2f, 0.5f, 1.0f);
							glRotatef(0, 0, 0, 1);
							foot->draw();
						}
						glPopMatrix();
					}
					glPopMatrix();

				}
				glPopMatrix();
			}
			glPopMatrix();
		}
		glPopMatrix();

		//Right leg




	}
	glPopMatrix();

	zRot += dir2 * 0.06f;
	if (zRot > 90 || zRot <= 0)
	{
		dir2 = -dir2;
	}

}