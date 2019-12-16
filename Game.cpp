#include "Game.h"

using namespace std;

Game::Game(){

	// Initialize Game
	init();
}

void Game::init(){

	//Create the Field
	field = new Field();

	//Create Team 1
	team_1 = new Team(1, field->field_map, field->player_positions);

	//Create Team 2
	team_2 = new Team(2, field->field_map, field->player_positions);

}

Team Game::get_team_1(){
	return *team_1;
}

Team Game::get_team_2(){
	return *team_2;
}


Game::~Game(){
	delete field;
	delete team_1;
	delete team_2;
}

void Game::play(){
	cout << "Playing" << endl;
	int iterations = 0; 
	while( (team_1->get_goals_scored() != 3 && team_2->get_goals_scored() != 3) && iterations < 10000){
		iterations++;
		take_actions();
	}

	cout << "FINAL SCORE" << endl;
	cout << "Team 1 " << team_1->get_goals_scored() << " : " << team_2->get_goals_scored() << " Team 2" << endl;

	if(team_1->get_goals_scored() == team_2->get_goals_scored())
		cout << "Match is a draw!" << endl;

	else if(team_1->get_goals_scored() > team_2->get_goals_scored())
		cout << "Team 1 wins!" << endl;

	else
		cout << "Team 2 wins!" << endl;
}



void Game::take_actions(){
	int ret = -1;
	//Player on ball moves first, then teamates with possession, then defense
	//Get Player on ball
	if(team_possession == 0){

		if(player_possession-1 < 4){
			shared_ptr<Defender> d = dynamic_pointer_cast<Defender,Player>(team_1->players[player_possession-1]);
			ret = d->take_on_ball_action();
		}

		else if(player_possession -1 < 7){
			shared_ptr<Midfielder> m = dynamic_pointer_cast<Midfielder, Player>(team_1->players[player_possession-1]);
			ret = m->take_on_ball_action();
		}

		else{
			shared_ptr<Forward> f = dynamic_pointer_cast<Forward, Player>(team_1->players[player_possession-1]);
			ret = f->take_on_ball_action();
		}

		
		//If a goal
		if(ret == 22){
			cout << "Goal Team 1!" << endl;
			team_1->add_goal_scored();
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
			if(i == player_possession-1){
				if(i < 4){
					shared_ptr<Defender> d = dynamic_pointer_cast<Defender,Player>(team_2->players[i]);
					d->take_off_ball_action();
				}

				else if(i < 7){
					shared_ptr<Midfielder> m = dynamic_pointer_cast<Midfielder,Player>(team_2->players[i]);
					m->take_off_ball_action();
				}

				else{
					shared_ptr<Forward> f = dynamic_pointer_cast<Forward,Player>(team_2->players[i]);
					f->take_off_ball_action();
				}
				
			}
				
			else{
				if(i < 4){
					shared_ptr<Defender> d = dynamic_pointer_cast<Defender,Player>(team_1->players[i]);
					d->take_off_ball_action();
					d = dynamic_pointer_cast<Defender,Player>(team_2->players[i]);
					d->take_off_ball_action();
				}

				else if(i < 7){
					shared_ptr<Midfielder> m = dynamic_pointer_cast<Midfielder,Player>(team_1->players[i]);
					m->take_off_ball_action();
					m = dynamic_pointer_cast<Midfielder,Player>(team_2->players[i]);
					m->take_off_ball_action();
				}

				else{
					shared_ptr<Forward> f = dynamic_pointer_cast<Forward,Player>(team_1->players[i]);
					f->take_off_ball_action();
					f = dynamic_pointer_cast<Forward,Player>(team_2->players[i]);
					f->take_off_ball_action();
				}
				
			}
		}


	}

	else{
		if(player_possession-12 < 4){
			shared_ptr<Defender> d = dynamic_pointer_cast<Defender,Player>(team_1->players[player_possession-12]);
			ret = d->take_on_ball_action();
		}

		else if(player_possession-12 < 7){
			shared_ptr<Midfielder> m = dynamic_pointer_cast<Midfielder,Player>(team_1->players[player_possession-12]);
			ret = m->take_on_ball_action();
		}

		else{
			shared_ptr<Forward> f = dynamic_pointer_cast<Forward,Player>(team_1->players[player_possession-12]);
			ret = f->take_on_ball_action();
		}

		if(ret == 22){
			cout << "Goal Team 2!" << endl;
			team_2->add_goal_scored();
			team_possession = 0;
			player_possession = 1;
			return;
		}

		else if(ret < 11){
			team_possession = 0;
			player_possession = ret;
		}

		else{
			player_possession = ret;
		}

		for(int i =0; i < 10; i++){
			if(i == player_possession-12){
				if(i < 4){
					shared_ptr<Defender> d = dynamic_pointer_cast<Defender,Player>(team_1->players[i]);
					d->take_off_ball_action();
				}

				else if(i < 7){
					shared_ptr<Midfielder> m = dynamic_pointer_cast<Midfielder,Player>(team_1->players[i]);
					m->take_off_ball_action();
				}

				else{
					shared_ptr<Forward> f = dynamic_pointer_cast<Forward,Player>(team_1->players[i]);
					f->take_off_ball_action();
				}
				
			}
				
			else{
				if(i < 4){
					shared_ptr<Defender> d = dynamic_pointer_cast<Defender,Player>(team_2->players[i]);
					d->take_off_ball_action();
					d = dynamic_pointer_cast<Defender,Player>(team_1->players[i]);
					d->take_off_ball_action();
				}

				else if(i < 7){
					shared_ptr<Midfielder> m = dynamic_pointer_cast<Midfielder,Player>(team_2->players[i]);
					m->take_off_ball_action();
					m = dynamic_pointer_cast<Midfielder,Player>(team_1->players[i]);
					m->take_off_ball_action();
				}

				else{
					shared_ptr<Forward> f = dynamic_pointer_cast<Forward,Player>(team_2->players[i]);
					f->take_off_ball_action();
					f = dynamic_pointer_cast<Forward,Player>(team_1->players[i]);
					f->take_off_ball_action();
				}

			}		
		}
	}

}

