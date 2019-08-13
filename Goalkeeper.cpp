#include "Goalkeeper.h"

using namespace std;

Goalkeeper::Goalkeeper(){
	x = -1;
	y = -1;
	id = -1;
	team = -1;
	goalkeeping = -1;
}

Goalkeeper::Goalkeeper(int player_id, int team_id) {
	x = 2;
	y = 0;
	id = player_id;
	team = team_id;
	goalkeeping = rand()%50 + 50;
}

int Goalkeeper::take_on_ball_action(){
	//Goalkeeper will always pass and will always complete pass
	int teammate = rand()%10;
	if(team == 1){
		teammate += 1; 
	}

	else if(team == 2){
		teammate += 12;
	}

	return teammate;
}