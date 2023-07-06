#include "TRectangleObject.h"

TRectangleObject::TRectangleObject() {
	m_Size = TSize(g_sRectangleWidth, g_sYDefaultLength, g_sZDefaultHeight);
	m_activeSide = NNActiveSide::NActiveSide::Small;
	m_orientation = NNOrientation::NOrientation::Stands;
	m_BaseCellRectangleLocation = TMapPoint(sDefaultXPosition, sDefaultYPosition);
}


TSize TRectangleObject::Size() { return m_Size; }

NNActiveSide::NActiveSide TRectangleObject::ActiveSide() { return m_activeSide; }

TMapPoint TRectangleObject::BaseCell() { return m_BaseCellRectangleLocation; }


std::vector<TMapPoint> TRectangleObject::SizeToOffsets() {													

	return std::vector<TMapPoint>();
}



std::vector<TMapPoint> TRectangleObject::PossibleMovesAccordToOrientation() {		//Possible moves
	std::vector<TMapPoint> offsets;

	switch(m_activeSide)
	{
		case NNActiveSide::Small:
		switch(m_orientation)
		{
			case NNOrientation::Stands:
			offsets ={{0, m_Size.y}, {m_Size.x, 0}, {0, -m_Size.y}, {-m_Size.x, 0}};
			break;

			case NNOrientation::StandsReverse:
			offsets ={{0, m_Size.z}, {m_Size.z, 0}, {0, -m_Size.z}, {-m_Size.y, m_Size.z}};
			break;
		}
		break;


		case NNActiveSide::Big:
		switch(m_orientation)
		{
			case NNOrientation::Horisontal:
			offsets ={{0, m_Size.y}, {m_Size.z, 0}, {0, -m_Size.y}, {-m_Size.x, 0}};
			break;


			case NNOrientation::HorisontalReverse:
			offsets ={{0, m_Size.y}, {m_Size.x, 0}, {0, -m_Size.y}, {-m_Size.z, 0}};
			break;


			case NNOrientation::Vertical:
			offsets ={{0, m_Size.z}, {m_Size.x, 0}, {0, -m_Size.y}, {-m_Size.x, 0}};
			break;


			case NNOrientation::VerticalReverse:
			offsets ={{0, m_Size.y}, {m_Size.x, 0}, {0, -m_Size.z}, {-m_Size.x, 0}};
			break;

			default:
			offsets ={};
			break;
		}
		break;

		default:
		break;
	}
	return offsets;
}



std::vector<TMapPoint> TRectangleObject::OffsetsByActiveSide() {
	std::vector<TMapPoint> offsets;

	switch(m_activeSide)
	{
		case NNActiveSide::Small:
		offsets ={{0, 0}};
		break;


		case NNActiveSide::Big:
		switch(m_orientation)
		{
			case NNOrientation::Horisontal:
			offsets ={{0, 0}, {1, 0}};
			break;


			case NNOrientation::HorisontalReverse:
			offsets ={{0, 0}, {-1, 0}};
			break;


			case NNOrientation::Vertical:
			offsets ={{0, 0}, {0, 1}};
			break;


			case NNOrientation::VerticalReverse:
			offsets ={{0, 0}, {0, -1}};
			break;

			default:
			offsets ={};
			break;
		}
		break;

		default:
		break;
	}
	return offsets;
}
std::vector<TMapPoint> TRectangleObject::OccupiedArea() {
	std::vector<TMapPoint> result;
	std::vector<TMapPoint> offsetLocat = OffsetsByActiveSide();	
	for(auto &cell:offsetLocat) {
		result.push_back({m_BaseCellRectangleLocation+cell});
	}
	return result;
}
