#ifndef MIDFIELDER_H
#define  MIDFIELDER_H

#include "Player.h"


class Midfielder : public Player{

public:
	Midfielder();
	Midfielder(int player_id, int team_id, map<int, field_grid> *fm, map<int, int> *player_pos);
	Midfielder(int player_id, int team_id, int x_pos, int y_pos, map<int, field_grid> *fm, map<int, int> *player_pos);
	int discretize_position();
	void take_off_ball_action();
	void move_player();
	int take_on_ball_action();
	int shoot();
	int pass();
	int dribble();
	map<int, field_grid> *field_map;
	map<int, int> *player_positions;

};

#endif