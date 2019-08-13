#ifndef FORWARD_H
#define FORWARD_H

#include "Player.h"


class Forward : public Player {

public:

	Forward();
	Forward(int player_id, int team_id, map<int, field_grid> *fm, map<int, int> *player_pos);
	Forward(int player_id, int team_id, int x_pos, int y_pos, map<int, field_grid> *fm, map<int, int> *player_pos);

	void take_off_ball_action();
	int take_on_ball_action();

private:
	int discretize_position();
	void move_player();
	int shoot();
	int pass();
	int dribble();
	map<int, field_grid> *field_map;
	map<int, int> *player_positions;
	
};

#endif