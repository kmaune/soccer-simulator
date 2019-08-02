
#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <map>
#include "Field.h"

using namespace std;


class Game {

public:

	Game();
	void init();

private:
	Field *field;


};


#endif