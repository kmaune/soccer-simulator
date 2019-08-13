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
	field = new Field();
	//cout << "Field created" << endl;

	//Create Team 1
	team_1 = new Team(1, field->field_map, field->player_positions);
	//cout << team_1->players.size() << endl;

	//Create Team 2
	team_2 = new Team(2, field->field_map, field->player_positions);
	//cout << team_2->players.size() << endl;

}

Team* Game::get_team_1(){
	return team_1;
}


Game::~Game(){
	delete field;
	delete team_1;
	delete team_2;
}

void Game::play(){
	cout << "Playing" << endl;
	int iterations = 0; 
	while( (team_1->goals != 3 && team_2->goals != 3) || iterations > 10000){
		iterations++;
		take_actions();
		cout << "actions taken" << endl;
	}

	cout << "FINAL SCORE" << endl;
	cout << "Team 1 " << team_1->goals << " : " << team_2->goals << " Team 2" << endl;

	if(team_1->goals == team_2->goals)
		cout << "Match is a draw!" << endl;

	else if(team_1->goals > team_2->goals)
		cout << "Team 1 wins!" << endl;

	else
		cout << "Team 2 wins!" << endl;
}



void Game::take_actions(){
	cout << "About to take actions" << endl;
	//Player on ball moves first, then teamates with possession, then defense

	//Get Player on ball
	if(team_possession == 0){
		shared_ptr<Defender> d = dynamic_pointer_cast<Defender,Player>(team_1->players[player_possession-1]);
		cout << "possession" <<  player_possession << endl;
		int ret = d->take_on_ball_action();
		cout << "took on ball action -- 1" << endl;
		cout << "return value" << ret << endl;
		//If a goal
		if(ret == 22){
			team_1->goals++;
			team_possession = 1;
			player_possession = 12;
			return;
		}

		//If a turnover
		else if(ret > 10){
			team_possession = 1;
			player_possession = ret;
		}

		else{
			player_possession = ret;
		}

		//Move Rest of Team and opponents
		for(int i = 1; i < 10; i++){
			if(i == player_possession){
				d = dynamic_pointer_cast<Defender,Player>(team_2->players[i]);
				d->take_off_ball_action();
				cout << "took off ball action 2 -- a" << endl;
			}
				
			else{
				d = dynamic_pointer_cast<Defender,Player>(team_1->players[i]);
				d->take_off_ball_action();
				cout << "took off ball action 1 -- a" << endl;
				d = dynamic_pointer_cast<Defender,Player>(team_2->players[i]);
				d->take_off_ball_action();
				cout << "took off ball action 2 --b "<< endl;
			}
		}


	}

	else{
		shared_ptr<Defender> d = dynamic_pointer_cast<Defender,Player>(team_1->players[player_possession-12]);
		cout << "possession" <<  player_possession << endl;
		int ret = d->take_on_ball_action();
		cout << "took on ball action -- 2" << endl;
		cout << "return value" << ret << endl;
		if(ret == 22){
			team_2->goals++;
			team_possession = 0;
			player_possession = 1;
		}

		else if(ret < 11){
			team_possession = 0;
			player_possession = ret;
		}

		else{
			player_possession = ret;
		}

		for(int i =0; i < 10; i++){
			if(i == player_possession){
				d = dynamic_pointer_cast<Defender,Player>(team_1->players[i]);
				d->take_off_ball_action();
				cout << "took off ball action 1 -- b" << endl;
			}
				
			else{
				d = dynamic_pointer_cast<Defender,Player>(team_2->players[i]);
				d->take_off_ball_action();
				cout << "Took off ball action 2 -- c" << endl;
				d = dynamic_pointer_cast<Defender,Player>(team_1->players[i]);
				d->take_off_ball_action();
				cout << "took off ball action 1 -- c" << endl;
			}		
		}
	}

}

