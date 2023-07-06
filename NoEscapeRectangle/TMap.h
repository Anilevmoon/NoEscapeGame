#pragma once
#include "TMapPoint.h"

static int g_sMapWidth =  4;
static int g_sMapLength = 4;

class TMap {
	public:

	TMap(int wight = 4, int lenght = 4);

	virtual ~TMap() = default;

	std::vector<TMapPoint> CreateMap(int width, int length);

	std::vector<TMapPoint> m_vMap;


	int  m_Wight;
	int m_Lenght;
};

