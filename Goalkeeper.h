#ifndef GOALKEEPER_H
#define GOALKEEPER_H

#include <cstdlib>

class Goalkeeper {

public:

	Goalkeeper();
	Goalkeeper(int player_id, int team_id);
	int x;
	int y;
	int id;
	int team;
	int take_on_ball_action();

private:
	double goalkeeping; 

};

#endif
