#include "Team.h"

using namespace std;

Team::Team(){
	team  = -1;
	goals = -1;
}

Team::Team(int team_id, map<int, field_grid> *fm){

	goals = 0;
	team = team_id;
	field_map = fm;

	int player_id;
	if(team == 1){
		player_id = 1;
	}

	else
		player_id = 12;

	//Create GK
	gk = Goalkeeper(team_id);



	//Create 4 defenders
	for(int i = 0; i < 4; i++){
		players.push_back(shared_ptr<Player>(new Defender(player_id, team_id, field_map)));
		player_id++;
	}
	
	//Create 3 midfielders


	for(int i = 0; i < 3; i++){
		players.push_back(shared_ptr<Player>(new Midfielder(player_id, team_id)));
		player_id++;
	}

	//Create 3 forwards
	
	for(int i = 0; i < 3; i++){
		players.push_back(shared_ptr<Player>(new Forward(player_id, team_id)));
		player_id++;
	}

}
