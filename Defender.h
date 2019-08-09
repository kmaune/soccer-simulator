#ifndef DEFENDER_H
#define DEFENDER_H

#include "Player.h"


class Defender : public Player {

public: 

	Defender();
	Defender(int player_id, int team_id);
	Defender(int player_id, int team_id, int x_pos, int y_pos);
	void take_off_ball_action();
	void move_player();
	void take_on_ball_action();

};

#endif