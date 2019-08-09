#ifndef FORWARD_H
#define FORWARD_H

#include "Player.h"


class Forward : public Player {

public:
	Forward();
	Forward(int player_id, int team_id);
	Forward(int player_id, int team_id, int x_pos, int y_pos);


};

#endif