#include "TBoxRun3DEscapeGame.h"
TBoxRun3DEscapeGame::TBoxRun3DEscapeGame() : m_Map(new TMap{}), m_Box(new TRectangleObject()), m_TurnsGiven(10) {}

void TBoxRun3DEscapeGame::CreateGame() {

}

int TBoxRun3DEscapeGame::Step(NMoves move) {
	switch(move)
	{
		case MoveLeft:
		if(m_Box->ActiveSide()==NNActiveSide::NActiveSide::Small) {
			switch(m_Box->m_orientation)
			{
				case Stands:
				m_Box->m_BaseCellRectangleLocation = m_Box->m_BaseCellRectangleLocation+TMapPoint(-m_Box->m_Size.x, 0);
				m_Box->m_orientation = HorisontalReverse;
				m_Box->m_activeSide = Big;

				break;

				case StandsReverse:
				m_Box->m_BaseCellRectangleLocation = m_Box->m_BaseCellRectangleLocation+TMapPoint(-m_Box->m_Size.z, 0);
				m_Box->m_orientation = Horisontal;
				m_Box->m_activeSide = Big;

				break;

				default:
				break;
			}
		} else {
			switch(m_Box->m_orientation)
			{
				case Horisontal:
				m_Box->m_BaseCellRectangleLocation = m_Box->m_BaseCellRectangleLocation+TMapPoint(-m_Box->m_Size.x, 0);
				m_Box->m_orientation = Stands;
				m_Box->m_activeSide = Small;

				break;

				case HorisontalReverse:
				m_Box->m_BaseCellRectangleLocation = m_Box->m_BaseCellRectangleLocation+TMapPoint(-m_Box->m_Size.z, 0);
				m_Box->m_orientation = StandsReverse;
				m_Box->m_activeSide = Small;

				break;

				case Vertical:
				m_Box->m_BaseCellRectangleLocation = m_Box->m_BaseCellRectangleLocation+TMapPoint(-m_Box->m_Size.x, 0);
				m_Box->m_activeSide = Big;

				break;

				case VerticalReverse:
				m_Box->m_BaseCellRectangleLocation = m_Box->m_BaseCellRectangleLocation+TMapPoint(-m_Box->m_Size.x, 0);
				m_Box->m_activeSide = Big;

				break;


				default:
				break;
			}
		}
		break;

		case MoveRight:
		if(m_Box->ActiveSide()==NNActiveSide::NActiveSide::Small) {
			switch(m_Box->m_orientation)
			{
				case Stands:
				m_Box->m_BaseCellRectangleLocation = m_Box->m_BaseCellRectangleLocation+TMapPoint(m_Box->m_Size.x, 0);
				m_Box->m_orientation = Horisontal;
				m_Box->m_activeSide = Big;

				break;

				case StandsReverse:
				m_Box->m_BaseCellRectangleLocation = m_Box->m_BaseCellRectangleLocation+TMapPoint(m_Box->m_Size.z, 0);
				m_Box->m_orientation = HorisontalReverse;
				m_Box->m_activeSide = Big;

				break;

				default:
				break;
			}
		} else {
			switch(m_Box->m_orientation)
			{
				case Horisontal:
				m_Box->m_BaseCellRectangleLocation = m_Box->m_BaseCellRectangleLocation+TMapPoint(m_Box->m_Size.x, 0);
				m_Box->m_orientation = StandsReverse;
				m_Box->m_activeSide = Small;

				break;

				case HorisontalReverse:
				m_Box->m_BaseCellRectangleLocation = m_Box->m_BaseCellRectangleLocation+TMapPoint(m_Box->m_Size.z, 0);
				m_Box->m_orientation = Stands;
				m_Box->m_activeSide = Small;

				break;

				case NNOrientation::Vertical:
				m_Box->m_BaseCellRectangleLocation = m_Box->m_BaseCellRectangleLocation+TMapPoint(m_Box->m_Size.x, 0);
				m_Box->m_activeSide = Big;

				break;

				case NNOrientation::VerticalReverse:
				m_Box->m_BaseCellRectangleLocation = m_Box->m_BaseCellRectangleLocation+TMapPoint(m_Box->m_Size.x, 0);
				m_Box->m_activeSide = Big;

				break;


				default:
				break;
			}
		}
		break;


		case MoveUP:
		if(m_Box->ActiveSide()==NNActiveSide::NActiveSide::Small) {
			switch(m_Box->m_orientation)
			{
				case NNOrientation::Stands:
				m_Box->m_BaseCellRectangleLocation = m_Box->m_BaseCellRectangleLocation+TMapPoint(0, -m_Box->m_Size.x);
				m_Box->m_orientation = NNOrientation::Vertical;
				m_Box->m_activeSide = Big;

				break;

				case NNOrientation::StandsReverse:
				m_Box->m_BaseCellRectangleLocation = m_Box->m_BaseCellRectangleLocation+TMapPoint(0, -m_Box->m_Size.z);
				m_Box->m_orientation = NNOrientation::VerticalReverse;
				m_Box->m_activeSide = Big;

				break;

				default:
				break;
			}
		} else {
			switch(m_Box->m_orientation)
			{
				case NNOrientation::Horisontal:
				m_Box->m_BaseCellRectangleLocation = m_Box->m_BaseCellRectangleLocation+TMapPoint(0, -m_Box->m_Size.x);
				m_Box->m_activeSide = Big;

				break;

				case NNOrientation::HorisontalReverse:
				m_Box->m_BaseCellRectangleLocation = m_Box->m_BaseCellRectangleLocation+TMapPoint(0, -m_Box->m_Size.x);
				m_Box->m_activeSide = Big;

				break;

				case NNOrientation::Vertical:
				m_Box->m_BaseCellRectangleLocation = m_Box->m_BaseCellRectangleLocation+TMapPoint(0, -m_Box->m_Size.z);
				m_Box->m_orientation = NNOrientation::Stands;
				m_Box->m_activeSide = Small;

				break;

				case NNOrientation::VerticalReverse:
				m_Box->m_BaseCellRectangleLocation = m_Box->m_BaseCellRectangleLocation+TMapPoint(0, -m_Box->m_Size.z);
				m_Box->m_orientation = NNOrientation::StandsReverse;
				m_Box->m_activeSide = Small;

				break;


				default:
				break;
			}
		}
		break;


		case MoveDown:
		if(m_Box->ActiveSide()==NNActiveSide::NActiveSide::Small) {
			switch(m_Box->m_orientation)
			{
				case Stands:
				m_Box->m_BaseCellRectangleLocation = m_Box->m_BaseCellRectangleLocation+TMapPoint(0, m_Box->m_Size.x);
				m_Box->m_orientation = VerticalReverse;
				m_Box->m_activeSide = Big;
				break;

				case StandsReverse:
				m_Box->m_BaseCellRectangleLocation = m_Box->m_BaseCellRectangleLocation+TMapPoint(0, m_Box->m_Size.z);
				m_Box->m_orientation = Vertical;
				m_Box->m_activeSide = Big;

				break;

				default:
				break;
			}
		} else {
			switch(m_Box->m_orientation)
			{
				case Horisontal:
				m_Box->m_BaseCellRectangleLocation = m_Box->m_BaseCellRectangleLocation+TMapPoint(0, m_Box->m_Size.x);
				m_Box->m_activeSide = Big;

				break;

				case HorisontalReverse:
				m_Box->m_BaseCellRectangleLocation = m_Box->m_BaseCellRectangleLocation+TMapPoint(0, m_Box->m_Size.x);
				m_Box->m_activeSide = Big;

				break;

				case Vertical:
				m_Box->m_BaseCellRectangleLocation = m_Box->m_BaseCellRectangleLocation+TMapPoint(0, m_Box->m_Size.z);
				m_Box->m_orientation = NNOrientation::StandsReverse;
				m_Box->m_activeSide = Small;

				break;

				case VerticalReverse:
				m_Box->m_BaseCellRectangleLocation = m_Box->m_BaseCellRectangleLocation+TMapPoint(0, m_Box->m_Size.z);
				m_Box->m_orientation = NNOrientation::Stands;
				m_Box->m_activeSide = Small;

				break;


				default:
				break;
			}
		}
		break;

		default:
		break;
	}
	return 0;
}

void TBoxRun3DEscapeGame::Reset() {
	m_Box->m_BaseCellRectangleLocation = TMapPoint(sDefaultXPosition, sDefaultYPosition);
	m_TurnsLeft = m_TurnsGiven;
}

bool TBoxRun3DEscapeGame::is_Done() {
	if(m_TurnsLeft>=0) {
		return true;
	} else if(m_Box->m_BaseCellRectangleLocation.x<0||m_Box->m_BaseCellRectangleLocation.x>g_sMapWidth||m_Box->m_BaseCellRectangleLocation.x<0||m_Box->m_BaseCellRectangleLocation.x>g_sMapLength) {
		return true;
	}
	return false;
}

void TBoxRun3DEscapeGame::PrintLocation() {
	std::cout<<"   ( "<<m_Box->m_BaseCellRectangleLocation.x<<" ,  "<<m_Box->m_BaseCellRectangleLocation.y<<" )    "<<std::endl;

}
