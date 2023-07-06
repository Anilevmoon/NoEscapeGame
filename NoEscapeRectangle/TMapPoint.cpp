#include "TMapPoint.h"
TMapPoint operator+(const TMapPoint& point0, const TMapPoint& point) {
	return TMapPoint(point0.x+point.x, point0.y+point.y);
}

TMapPoint::TMapPoint(int xInput, int yInput) : x(xInput), y(yInput) {}
