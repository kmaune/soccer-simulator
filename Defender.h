#ifndef DEFENDER_H
#define DEFENDER_H

#include "Player.h"


class Defender : public Player {

public: 

	Defender();
	Defender(int player_id, int team_id, map<int, field_grid> *fm);
	Defender(int player_id, int team_id, int x_pos, int y_pos, map<int, field_grid> *fm);
	int discretize_position();
	void take_off_ball_action();
	void move_player();
	void take_on_ball_action();
	void shoot();
	void pass();
	void dribble();
	map<int, field_grid> *field_map;


};

#endif