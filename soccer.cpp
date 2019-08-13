#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include "Field.h"
#include "Player.h"
#include "Team.h"

using namespace std;

int main(int argc, char*argv[]){

	srand(time(NULL));
	Game g;
	g.play();
	
	return 0;

}