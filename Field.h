#ifndef FIELD_H
#define FIELD_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <map>
#include <deque>
#include <memory>
#include "Player.h"
#include "Goalkeeper.h"

using namespace std; 


struct field_grid {
	int id = -1;
	string grid_type = "Grid";
	int x = -1;
	int y = -1;
	double attacking_threat = 0.0;
	//Probably need to update this to a map
	//map from player_id to grid position
	//this will make removing a player easier and can still get size
	deque<int> in_grid; 
};

class Field{
public:
	Field();
	void init();
	map<int, field_grid> *field_map;
	map<int, int> *player_positions;

	~Field();


private:
	int discretize_field(int x, int y);
	string get_grid_type(int id);
	void set_threat_value(field_grid &fg);
	
	

};


#endif