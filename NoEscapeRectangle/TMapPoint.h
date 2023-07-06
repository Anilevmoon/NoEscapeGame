#pragma once
#include <vector>
#include <iostream>

struct TMapPoint {
	public:
	TMapPoint() = default;
	TMapPoint(int xInput, int yInput);
	int x = 0;
	int y = 0;
	friend TMapPoint operator+(const TMapPoint& point0, const TMapPoint& point);	
};

