#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "Point.h"
#include "structure.h"

void afficherParcours(vector<Point> vPoints)
{
	glBegin(GL_LINE_STRIP);
	for (double i = 0.0; i < 50.0; i+=0.01)
	{
		glVertex3f(i, 0, 5*cos(i));
	}
	glEnd();

	/*glBegin(GL_LINE_STRIP);
	for (int i = 0; i < (int)vPoints.size(); i++)
	{
		glVertex3i(vPoints[i].getAx(), vPoints[i].getAy(), vPoints[i].getAz());
	}
	glEnd();*/
}

void repereXY(int taille)
{
	for (int i = -taille; i <= taille; i++)
	{
		glBegin(GL_LINE_STRIP);
		glVertex3i(i, -taille, 0);
		glVertex3i(i, taille, 0);
		glEnd();
	}

	for (int i = -taille; i <= taille; i++)
	{
		glBegin(GL_LINE_STRIP);
		glVertex3i(-taille, i, 0);
		glVertex3i(taille, i, 0);
		glEnd();
	}
}


