#ifndef MONSTER_H_
#define MONSTER_H_

#include <string>

class Enemy { 
private:
	std::string name;
	int health;
	int xp;

public:
	// Constructors
	Enemy(std::string new_name, int new_health);
	
	// Getters
	std::string get_name();
	int get_health();
	int get_xp();
	
	// Setters
	void set_health(int new_health);
};

#endif
