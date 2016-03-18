#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <iostream>
#include <glew.h>
#include <glut.h>
#include "Point.h"

using namespace std;

class Point
{
public:
	Point();
	Point(double dax, double day, double daz, double dh);
	Point(double dx, double dy, double dz);
	double getX();
	double getY();
	double getZ();
	double getAx();
	double getAy();
	double getAz();
	double getH();

private:
	//coordonnées
	double x;
	double y;
	double z;
	//hauteur
	double h;
	//vitesse
	double vx;
	double vy;
	double vz;
	//accélération
	double ax;
	double ay;
	double az;

};

#endif
