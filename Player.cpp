#include "Player.h"

using namespace std; 



Player::Player(){
	x = -1;
	y = -1;
	id = -1;
	team = -1;
	defensive = rand()%50 + 50;
	pace = rand()%50 + 50;
	shooting = rand()%50 + 50;
	passing = rand()%50 + 50;
	dribbling = rand()%50 + 50;
}


Player::~Player(){
	
}