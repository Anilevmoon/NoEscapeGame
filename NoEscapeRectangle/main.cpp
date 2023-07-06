#include <iostream>
#include "TBoxRun3DEscapeGame.h"
int main()
{
	TBoxRun3DEscapeGame game;
	game.CreateGame();  
	//while(!game.is_Done()) {
		//game.Step(MoveDown);
		game.Step(MoveRight);
		game.PrintLocation();
		game.Step(MoveDown);
		game.PrintLocation();
		game.Step(MoveDown);
		game.PrintLocation();
		game.Step(MoveDown);
		game.Step(MoveDown);
		game.Step(MoveRight);
		game.Step(MoveLeft);
		game.PrintLocation();
//	}

	return 0;
}
