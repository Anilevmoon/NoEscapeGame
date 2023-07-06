#pragma once
#include "TMap.h"
#include "TRectangleObject.h"
#include "NNMoves.h"



class TBoxRun3DEscapeGame {
	public:
	TBoxRun3DEscapeGame();
	virtual ~TBoxRun3DEscapeGame() = default;


	public:
	void CreateGame();

	public:
	int Turns() { return m_TurnsLeft; }								
	std::vector<TMapPoint> Map() { return m_Map->m_vMap; }			
	TRectangleObject *Box() { return m_Box; }						
	int Score() { return m_Score; };													//Returns m_TakedBonuses on map???

	public:
	int Step(NNMoves::NMoves move);		//Make Move 
	void Reset();						//Restarts Game


	public:
	int m_Score = 0;
	int m_TurnsLeft =0;
	int m_TurnsGiven =10;
	bool is_Done();

	void PrintLocation();

	TMap *m_Map;
	TRectangleObject *m_Box;
};

