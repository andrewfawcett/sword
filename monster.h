#ifndef MONSTER_H_
#define MONSTER_H_

#include <string>

class Enemy { 
private:
	std::string m_name;
	int m_level;
	int m_xp;
	
	int m_health;
	int m_strength;

public:
	// Constructors
	Enemy(std::string name, int level);
	
	// Getters
	std::string get_name();
	int get_strength();
	int get_health();
	int get_xp();
	
	// Setters
	void set_health(int health);
};

#endif
