#include "Forward.h"

using namespace std;

Forward::Forward(){
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

Forward::Forward(int player_id, int team_id){

	x = rand()%5;
	y = 2;
	id = player_id;
	team = team_id;

	defensive = rand()%65 + 35;
	pace = rand()%50 + 50;
	shooting = rand()%50 + 40;
	passing = rand()%40 + 50;
	dribbling = rand()%50 + 40;

}

Forward::Forward(int player_id, int team_id, int x_pos, int y_pos){

	x = x_pos;
	y = y_pos;
	id = player_id;
	team = team_id;

	defensive = rand()%65 + 35;
	pace = rand()%50 + 50;
	shooting = rand()%50 + 40;
	passing = rand()%40 + 50;
	dribbling = rand()%50 + 40;
}