#pragma once
#include "NNActiveSide.h"
#include "NNOrientation.h"
#include "TMap.h"

#include "TSize.h"

extern int g_sRectangleWidth;
extern int g_sRectangLength;
extern int g_sRectangHeight;

static int sDefaultXPosition = 0;
static int sDefaultYPosition = 0;



class TRectangleObject {
	public:
	TRectangleObject();
	virtual ~TRectangleObject() = default;

	public:
	TSize Size(); 
	std::vector<TMapPoint> SizeToOffsets();

	NNActiveSide::NActiveSide ActiveSide();
	TMapPoint BaseCell();
	std::vector<TMapPoint> OffsetsByActiveSide();
	std::vector<TMapPoint> OccupiedArea();
	std::vector<TMapPoint> PossibleMovesAccordToOrientation();
	

	public:
	TMapPoint m_BaseCellRectangleLocation;
	TSize m_Size;

	NActiveSide m_activeSide;
	NNOrientation::NOrientation m_orientation;
};

