#include "Team.h"

using namespace std;

Team::Team(){
	team  = -1;
	goals = -1;
}

Team::Team(int team_id, map<int, field_grid> *fm, map<int, int> *player_pos){
	cout << "Creating team: " << team_id << endl;
	goals = 0;
	team = team_id;
	field_map = fm;
	player_positions = player_pos;

	int player_id, gk_id;
	if(team == 1){
		gk_id = 0;
		player_id = 1;
	}

	else{
		gk_id = 11;
		player_id = 12;
	}

	//Create GK
	gk = Goalkeeper(gk_id, team_id);


	//Create 4 defenders
	for(int i = 0; i < 4; i++){
		players.push_back(shared_ptr<Player>(new Defender(player_id, team_id, field_map, player_pos)));
		player_id++;
	}
	
	
	//Create 3 midfielders
	for(int i = 0; i < 3; i++){
		players.push_back(shared_ptr<Player>(new Midfielder(player_id, team_id, field_map, player_pos)));
		player_id++;
	}
	

	//Create 3 forwards
	for(int i = 0; i < 3; i++){
		players.push_back(shared_ptr<Player>(new Forward(player_id, team_id, field_map, player_pos)));
		player_id++;
	}


}


int Team::get_goals_scored() const {
	return goals;
}

void Team::add_goal_scored(){
	goals++;
}

Team::~Team(){
	while(players.size() > 0){
		shared_ptr<Player> p = players.back();
		p.reset();
		players.pop_back();
	}
}
