#include <string>
#include "monster.h"

// Constructors
Enemy::Enemy(std::string new_name, int new_health) {
	name = new_name;
	health = new_health;
	xp = 10;
}	

// Getters
std::string Enemy::get_name() {return name;}
int Enemy::get_health() { return health; }
int Enemy::get_xp() {return xp;}

// Setters
void Enemy::set_health(int new_health) { health = new_health; }
