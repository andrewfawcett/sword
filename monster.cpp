#include <string>
#include "monster.h"

// Constructors
Enemy::Enemy(std::string name, int level) {
	m_name = name;
	m_level = level;
	m_strength = 1;
	m_health = 5 + (level * 5);
	m_xp = 2 + (level * 4);
}	

// Getters
std::string Enemy::get_name() {return m_name;}
int Enemy::get_health() { return m_health; }
int Enemy::get_strength() { return m_strength;}
int Enemy::get_xp() { return m_xp; }

// Setters
void Enemy::set_health(int health) { m_health = health; }
