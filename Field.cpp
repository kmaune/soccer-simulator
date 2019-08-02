#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include "Field.h"


using namespace std;

Field::Field(){
	init();
}


void Field::init(){

	// Create all structs of field space 
	field_grid fg;
	//Create wings
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 5; j++) {
			fg.id = discretize_field(j, i);
			fg.grid_type = get_grid_type(fg.id);
			fg.x = j;
			fg.y = i;
			set_threat_value(fg);
			//Insert each field grid into the field map
			(*field_map)[fg.id] = fg;
		}
	}

}


int Field::discretize_field(int x, int y){
	return 5*y + x;
}

string Field::get_grid_type(int id) {
	
	if(id == 1 || id == 2 || id == 3 || id == 26 || id == 27 || id == 28)
		return "penalty_area";

	else if (id == 7 || id == 12 || id == 17 || id == 22)
		return "midfield_space";

	else if(id == 6 || id == 8 || id == 11 || id == 13 || id == 16 || 
		id == 18 || id == 21 || id == 23)
		return "half_space";
	
	else return "wings";
}


void Field::set_threat_value(field_grid &fg){

	if(fg.grid_type == "penalty_area")
		fg.attacking_threat = 0.6;

	else if(fg.grid_type == "midfield_space"){
		if(fg.id == 12 || fg.id == 17)
			fg.attacking_threat = 0.2;

		else
			fg.attacking_threat = 0.5;
	}

	else if(fg.grid_type == "half_space"){
		if(fg.id == 11 || fg.id == 13 || fg.id == 16 || fg.id == 18)
			fg.attacking_threat = 0.1;
		else
			fg.attacking_threat = 0.4;
	}

	else
		if(fg.id == 10 || fg.id == 14 || fg.id == 15 || fg.id == 19)
			fg.attacking_threat = -0.1;
		else if(fg.id == 5 || fg.id == 9 || fg.id == 20 || fg.id == 24)
			fg.attacking_threat = 0.0;
		else
			fg.attacking_threat = 0.2;
}




