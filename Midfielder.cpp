#include "Midfielder.h"

using namespace std;

Midfielder::Midfielder(){
	x = -1;
	y = -1;
	id = -1;
	team = -1;
	defensive = -1;
	pace = -1;
	shooting = -1;
	passing = -1;
	dribbling = -1;
}

Midfielder::Midfielder(int player_id, int team_id, map<int, field_grid> *fm, map<int, int> *player_pos){

	x = rand()%5;
	y = 2;
	id = player_id;
	team = team_id;

	defensive = rand()%65 + 35;
	pace = rand()%50 + 50;
	shooting = rand()%50 + 40;
	passing = rand()%40 + 50;
	dribbling = rand()%50 + 40;

	field_map = fm;
	player_positions = player_pos;
	(*field_map)[discretize_position()].in_grid.push_back(id);
	(*player_positions)[id] = discretize_position();

}

Midfielder::Midfielder(int player_id, int team_id, int x_pos, int y_pos, map<int, field_grid> *fm, map<int, int> *player_pos){

	x = x_pos;
	y = y_pos;
	id = player_id;
	team = team_id;

	defensive = rand()%65 + 35;
	pace = rand()%50 + 50;
	shooting = rand()%50 + 40;
	passing = rand()%40 + 50;
	dribbling = rand()%50 + 40;

	field_map = fm;
	player_positions = player_pos;
	(*field_map)[discretize_position()].in_grid.push_back(id);
	(*player_positions)[id] = discretize_position();
}

int Midfielder::discretize_position(){
	return 5*y + x;
}


void Midfielder::take_off_ball_action(){
	//Need to remove player from original field grid, 
	// then add player back to whatver field grid they end up in

	// Get random action from on_ball_action array
	int i = rand()%2;
	string action = off_ball_actions[i];

	//If action is move, move the player
	if(action == "move")
		move_player();

	//Else if action is stay, do nothing
	int pos = discretize_position();
	field_grid fg = (*field_map)[pos];
}


void Midfielder::move_player(){
	//Get movement direction
	int start_pos = (*player_positions)[id];

	int i = rand()%4;
	string direction = moves[i];
	if(direction == "North"){
		if(y < 5)
			y++;
	}

	else if(direction == "South"){
		if(y > 0)
			y--;
	}

	else if(direction == "East"){
		if(x < 4)
			x++;
	}

	else if(direction == "West"){
		if(x > 0){
			x--;
		}
	}

	int new_pos = discretize_position();

	if(new_pos != start_pos){
		//Remove player from original grid
		deque<int>::iterator it = find((*field_map)[start_pos].in_grid.begin(), (*field_map)[start_pos].in_grid.end(), id);
		if(it != (*field_map)[start_pos].in_grid.end())
			(*field_map)[start_pos].in_grid.erase(it);

		//Put player in new grid
		(*field_map)[new_pos].in_grid.push_back(id);
		(*player_positions)[id] = new_pos;
	}

}



int Midfielder::take_on_ball_action(){
	// Get random action from on_ball_action array
	int i = rand()%3;
	string action = on_ball_actions[i];

	//If random action is shoot:
	if(action == "shoot")
		return shoot();	

	//Else If random action is pass:
	else if(action == "pass")
		return pass();

	//Else If random action is dribble:
	else if(action == "dribble")
		return dribble();

	return -1;
}


int Midfielder::shoot(){
	//take shot on other players goalie
	if(team == 0){
		if(x < 4){
			//turnover
			return -1;
		}

		else if(x == 4){
			//cout << "midfield space" << endl;
			return -1;
		}

		else if (x == 5){
			//cout << "penalty space" << endl;
			return 22;
		}
	}

	else if(team == 1){
		if(x > 4){
			//turnover
			return -1;
		}
	}


	return 22;
}



int Midfielder::pass(){
	int teammate = rand()%10;
	if(team == 1){
		teammate += 1; 
	}

	else if(team == 2){
		teammate += 12;
	}

	int num_opponents = 0;
	int last_opponent = -1;
	int teammate_pos = (*player_positions)[teammate];

	field_grid teammate_grid = (*field_map)[teammate_pos];

	//If teammate is only player in grid
	if(teammate_grid.in_grid.size() == 1){
		return teammate;
	}

	else {

		for(int i = 0; i < teammate_grid.in_grid.size(); i++){
			int player_id = teammate_grid.in_grid[i];
			if(team == 1){
				if(player_id > 10){
					num_opponents++;
					last_opponent = player_id;
				}
			}

			else if(team == 2){
				if(player_id < 11){
					num_opponents++;
					last_opponent = player_id;
				}
			}
		}

		if(num_opponents == 1){
			int success = rand()%2;
			if(success){
				return teammate;
			}

			else {
				return last_opponent;
			}
		}

		else if(num_opponents > 1){
			return last_opponent;
		}

	}

	return teammate;
}


int Midfielder::dribble(){
	int start_pos = (*player_positions)[id];
	//(*field_map)[start_pos].in_grid
	field_grid current_grid = (*field_map)[start_pos];

	for(int i = 0; i < current_grid.in_grid.size(); i++){
		int player_id = current_grid.in_grid[i];
		if(team == 1){
			if(player_id > 10){
				int success = rand()%2;
				if(success)
					continue;
				else
					return player_id;
			}
		}

		else if(team == 2){
			if(player_id < 11){
				int success = rand()%2;
				if(success)
					continue;
				else
					return player_id;
			}
		}
	}

	move_player();
	return id;
}





