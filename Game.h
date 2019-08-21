
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>
#include "Field.h"
#include "Team.h"

using namespace std;


class Game {

public:

	Game();
	void init();
	void play();
	void take_actions();

	Team get_team_1();
	Team get_team_2();

	~Game();

private:
	Field *field;
	
	Team *team_1;
	Team *team_2;

	int team_possession = 0;
	int player_possession = 1;



};


#endif