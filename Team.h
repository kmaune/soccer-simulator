#ifndef TEAM_H
#define TEAM_H

#include <memory>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Player.h"
#include "Goalkeeper.h"
#include "Defender.h"
#include "Midfielder.h"
#include "Forward.h"

using namespace std;


class Team {

public:

	// Add feature to team where you can input a formation if desired
	//Default formation 4-3-3
	Team();
	Team(int team_id);
	int team;
	Goalkeeper gk;
	vector<shared_ptr<Player>> players; //All field players in the team
	int goals = 0; // Keeps track of how many goals the team scored
	
};



#endif