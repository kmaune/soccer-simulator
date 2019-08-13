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


int Player::take_on_ball_action(){
	cout << "Generic player on ball action, shouldn't be here" << endl;
	return -1;
}

void Player::take_off_ball_action(){
	cout << "Generic player off ball action, shouldn't be here" << endl;
	return;
}

Player::~Player(){
	
}