#include "Team.h"

using namespace std;

Team::Team(int team_id){

	goals = 0;

	int player_id = 0;

	//Create GK
	gk = Goalkeeper(team_id);


	//Create 4 defenders
	
	for(int i = 0; i < 4; i++){
		players.push_back(shared_ptr<Player>(new Defender(player_id, team_id)));
	}
	
	//Create 3 midfielders

	/* 
		for(int i = 0; i < 3; i++){
			Midfielder m = Midfielder(player_id);
			players.push(m);
		}
	*/

	//Create 3 forwards
	/*
		for(int i = 0; i < 3; i++){
			Forward f = Forward(player_id);
			players.push(f);
		}
	*/


}