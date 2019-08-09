#ifndef MIDFIELDER_H
#define  MIDFIELDER_H

#include "Player.h"


class Midfielder : public Player{

public:
	Midfielder();
	Midfielder(int player_id, int team_id);
	Midfielder(int player_id, int team_id, int x_pos, int y_pos);

};

#endif