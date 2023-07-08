#include "segment.h"
#include "MyPoint.h"
#include <math.h>

segment::segment()
{
	p1.setCoords(0, 0);
	p2.setCoords(1, 1);
}

segment::segment(MyPoint a, MyPoint b)
{
	p1 = a;
	p2 = b;
}

float segment::longeur()
{
	return sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
