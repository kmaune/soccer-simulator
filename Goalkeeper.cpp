#include "Goalkeeper.h"

using namespace std;

Goalkeeper::Goalkeeper(){
	x = -1;
	y = -1;
	id = -1;
	team = -1;
	goalkeeping = -1;
}

Goalkeeper::Goalkeeper(int team_id) {
	x = 2;
	y = 0;
	id = 0;
	team = team_id;
	goalkeeping = rand()%50 + 50;
}