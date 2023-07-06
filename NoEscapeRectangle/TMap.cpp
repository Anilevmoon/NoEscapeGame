#include "TMap.h"


TMap::TMap(int wight, int lenght) : m_Wight(wight), m_Lenght(lenght) {
	m_vMap = CreateMap(m_Wight, m_Lenght);
}

std::vector<TMapPoint> TMap::CreateMap(int width, int length) {
	std::vector<TMapPoint> result;
	for(int i = 0; i<g_sMapWidth; i++) {
		for(int it = 0; it<g_sMapLength; it++) {
			result.push_back({i, it});
		}
	}
	return result;
}
