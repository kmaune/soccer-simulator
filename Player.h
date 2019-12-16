#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>    // std::find
#include "Field.h"

using namespace std;

/*
	Should I make this an abstract class since no 'Players' should be made
	Since all players made should be a specific position
*/

class Player {

public:

	Player();
	
	virtual ~Player();

protected:
	int x;
	int y;
	int id;
	int team;
	double defensive;
	double pace;
	double shooting;
	double passing;
	double dribbling;
	const string on_ball_actions[3] = {"pass", "dribble", "shoot"};
	const string off_ball_actions[2] = {"stay", "move"};
	const string moves[4] = {"North", "South", "East", "West"};
};



#endif
