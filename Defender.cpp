#include "Defender.h"

using namespace std;

Defender::Defender(){
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

Defender::Defender(int player_id, int team_id, map<int, field_grid> *fm){
	x = rand()%5;
	y = 1;
	id = player_id;
	team = team_id;

	defensive = rand()%65 + 35;
	pace = rand()%50 + 50;
	shooting = rand()%50 + 40;
	passing = rand()%40 + 50;
	dribbling = rand()%50 + 40;

	field_map = fm;
	(*field_map)[discretize_position()].in_grid.push_back(id);
}


Defender::Defender(int player_id, int team_id, int x_pos, int y_pos, map<int, field_grid> *fm){
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
}

int Defender::discretize_position(){
	return 5*y + x;
}

void Defender::take_off_ball_action(){
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

void Defender::move_player(){
	//Get movement direction
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
}

void Defender::take_on_ball_action(){
	return;
	// Get random action from on_ball_action array
	int i = rand()%3;
	string action = on_ball_actions[i];


	//If random action is shoot:
	if(action == "shoot")
		shoot();	

	//Else If random action is pass:
	else if(action == "pass")
		pass();

	//Else If random action is dribble:
	else if(action == "dribble")
		dribble();
}


//Return 1 for goal, negative 0 for turnover (Other teams goalie gets possession)
void Defender::shoot(){
//take shot on other players goalie

	if(team == 0){
		if(x < 4){
			//turnover
			cout << "turnover, team 1" << endl;
		}

		else if(x == 4){
			cout << "midfield space" << endl;
		}

		else if (x == 5){
			cout << "penalty space" << endl;
		}

	}

	else if(team == 1){
		if(x > 4){
			//turnover
			cout << "turnover, team 2" << endl;
		}
	}


	/* 
		If you are not in the opponents penalty area or closest 
		half-space/midfield area--> turnover


		If you are in the closest midfield are or halfspace
		--> no shot multiplier, small GK mutliplier

		If you are in the penalty area --> small shot multiplier, 
		no GK multiplier
	
		If there is a goal, give other team possession and update score

		If there is a save, other teams goalie has possession
		
		( Maybe incorporate blocks? )
		****NEED to account for shots from wings --> turnover

	*/
}

//Return 0-10 for successful pass, -1 - -10 or 11 for turnover
void Defender::pass(){
	/*
	Select @ random a teamate to pass too
	
	If # of opponents in Grid with teammate > 1 --> turnover
	(Maybe just increase the likelihood of a turnover)
	If # of opponents in Grid with teamate == 1, 
	--> Random choice based on passing ability of passer 
	and defensive ability of defender for success or turnover

	If number of opponents in Grid with teamate == 0, 
	--> succesful pass

*/

}

//Return 1 on success -1- -10 or 11 for turnover
void Defender::dribble(){
/*
	if 0 defneders in grid with you --> success

	if > 0 defender in grid with you --> random choice 
	for each defender in grid based on dribbling ability
	vs defensive ability
*/

}


