#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Game.h"

using namespace std;

Game::Game(){

	// Initialize Game
	init();
}

void Game::init(){

	//Create the Field
	field = new Field;

	//Create Team 1
	//team_1 = new Team();

	//Create Team 2
	//team_2 = new Team();

}


/*
void Game::play(){
	int iterations = 0; 
	while( (team_1->goals != 3 && team2->goals != 3) || iterations > 10000){
		iterations++;

		take_actions();
	}

	cout << "FINAL SCORE" << endl;
	cout << "Team 1 " << team_1->goals << " : " << team_2->goals << " Team 2"

	if(team_1->goals == team_2->goals)
		cout << "Match is a draw!" << endl;

	else if(team_1->goals > team_2->goals)
		cout << "Team 1 wins!" << endl;

	else
		cout << "Team 2 wins!" << endl;
}
*/

/*
void Game::take_actions(){

	Player on ball moves first, then teamates with possession, then defense

	Get Player on ball
		if(team_possession = 0){
			team_1->players[player_possession].take_on_ball_action()

			//Move Rest of Team and opponents
			for(int i = 1; i < 11; i++){
				if i == player_possession
					team_2->players[i].take_off_ball_action()
				else
					team_1->players[i].take_off_ball_action()
					team_2->players[i].take_off_ball_action()
			}

	
		}

		else
			team_2->players[player_possession].take_on_ball_action();

			for(int i =0; i < 11; i++){
				if i == player_possession
					team_1->players[i].take_off_ball_action()
				else
					team_2->players[i].take_off_ball_action()
					team_1->players[i].take_off_ball_action()
			}
*/