#include <iostream>
#include <glew.h>
#include <glut.h>
#include "Point.h"

using namespace std;

Point::Point()
{
	x = 0;
	y = 0;
	z = 0;
	h = 0;
	vx = 0;
	vy = 0;
	vz = 0;
	ax = 0;
	ay = 0;
	az = 0;
}

Point::Point(double dx, double dy, double dz)
{
	x = dx;
	y = dy;
	z = dz;
}

Point::Point(double dax, double day, double daz, double dh)
{
	x = 0;
	y = 0;
	z = 0;
	h = dh;
	vx = 0;
	vy = 0;
	vz = 0;
	ax = dax;
	ay = day;
	az = day;
}

double Point::getX()
{
	return x;
}

double Point::getY()
{
	return y;
}

double Point::getZ()
{
	return z;
}

double Point::getAx()
{
	return ax;
}

double Point::getAy()
{
	return ay;
}

double Point::getAz()
{
	return az;
}

double Point::getH()
{
	return h;
}

