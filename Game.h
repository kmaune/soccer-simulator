
#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <map>
#include "Field.h"
#include "Player.h"
#include "Team.h"

using namespace std;


class Game {

public:

	Game();
	void init();
	Team* get_team_1();
	//void play();
	//void take_actions();

	~Game();

private:
	Field *field;
	
	Team *team_1;
	Team *team_2;

	int team_possession = 0;
	int player_possession = 0;



};


#endif