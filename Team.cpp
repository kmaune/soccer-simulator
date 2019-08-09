#include "Team.h"

using namespace std;

Team::Team(){
	team  = -1;
	goals = -1;
}

Team::Team(int team_id){

	goals = 0;
	team = team_id;

	int player_id = 1;

	//Create GK
	gk = Goalkeeper(team_id);


	//Create 4 defenders
	for(int i = 0; i < 4; i++){
		players.push_back(shared_ptr<Player>(new Defender(player_id, team_id)));
		player_id++;
	}
	
	//Create 3 midfielders

	/* 
		for(int i = 0; i < 3; i++){
			
			player_id++;
		}
	*/

	//Create 3 forwards
	/*
		for(int i = 0; i < 3; i++){
			players.push_back(shared_ptr<Player>(new Forward(player_id, team_id)));
			player_id++;
		}
	*/


}