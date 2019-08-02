#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <string>

using namespace std; 


struct field_grid {
	int id = -1;
	string grid_type = "Grid";
	int x = -1;
	int y = -1;
	double attacking_threat = 0.0;
};

class Field{
public:
	Field();
	void init();


private:
	int discretize_field(int x, int y);
	string get_grid_type(int id);
	void set_threat_value(field_grid &fg);
	map<int, field_grid> *field_map;
	

};


#endif