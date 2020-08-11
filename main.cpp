#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>

#include "monster.h"

using namespace std;

class Player {
private:
	int total_xp = 0;
	
	int m_max_health = 10;
	int m_health = 10;
	int strength = 1;
	int weapon = 0;

public:
	// Constructors
	
	// Getters
	int get_xp() { return total_xp; };
	int get_max_health() { return m_max_health; };
	int get_health() { return m_health; }
		
	// Setters
	void add_xp(int xp) { total_xp += xp; };
	void set_health(int health) { m_health = health; };
	void use_potion(int health) { 
		if (m_health + health > m_max_health) { m_health = m_max_health; } 
		else { m_health = health; }
	};
	
	// Special
	void equip_weapon(int new_weapon) { weapon = new_weapon; };
	int attack() { return strength + weapon; };
};

void battle(Player &character, Enemy monster ) {
	
	cout << "You encountered " << monster.get_name() << endl;
	char action;
	while (monster.get_health() > 0) {
		cout << monster.get_name() << " has " << monster.get_health() << " health." << endl;
		cout << "(a)ttack, (i)tem, or (r)un: ";
		cin >> action;
		if (action == 'a') {
			monster.set_health(monster.get_health() - character.attack()) ;
			cout << "You deal " << character.attack() << " damage!" << endl;
		}
		character.set_health(character.get_health() - monster.get_strength());
		cout << "You took " << monster.get_strength() << " damange!" << endl;
	};
	cout << "You defeated the enemy!" << endl;
	character.add_xp(monster.get_xp());
	cout << "You earned " << monster.get_xp() << " experience points." << endl;
};

void inventory(Player &character) {
	// const int fist = 0;
	const int sword = 1;
	
	vector<std::string> items {"sword", "potion"};
	for (auto item : items) {
		cout << item << endl;
	}
	
	char action;
	string input;
	while (action != 'b') {
		cout << "(e)quip, (i)tem, (b)ack: ";
		cin >> action;
		if (action == 'e') {
			cout << "Equip which item? ";
			cin >> input;
			if (input == "sword") {
				character.equip_weapon(sword);
				cout << "You equiped a weapon!" << endl;
			} else {
				cout << "That is not a weapon!" << endl;
			}
		}
		if (action == 'i') {
			cout << "Use which item? ";
			cin >> input;
			if (input == "potion") {
				character.use_potion(8);
				cout << "Using a potion" << endl;
			}
		}
	}
};
	
void save(Player character) {
	cout << "Saving the game..." << endl;
	ofstream save_file;
	save_file.open ("save.txt");
	save_file << character.get_xp() << endl;
	save_file.close();
};

int main() {
	cout << "Welcome Warrior of Light!" << endl;
	
	Player Andrew;
	srand (time(NULL));
	int asp_level = rand() % 3 + 1;
	Enemy Asp ("Asp", asp_level);

	char action;
	
/*
	while (action != 'l' and 'n' and 'q' ) {
		cout << "(l)oad game, (n)ew game, (q)uit: ";
		cin >> action;
		if (action == 'l') {
			cout << "loading game" << endl;
		} else if (action == 'n') {
			cout << "starting new game!" << endl;
		}
	}
*/
	
	while (action !=  'q') {
		cout << "(c)haracter, (i)nventory, (b)attle, (s)ave, (q)uit: ";
		cin >> action;
		if (action == 'c') {
			cout << endl;
			cout << "Character Status" << endl;
			cout << "================" << endl;
			cout << "Health: " << Andrew.get_health() << " / " << Andrew.get_max_health() << endl;
			cout << "Experience: " << Andrew.get_xp() << endl;
		} else if (action == 'i') {
			inventory(Andrew);
		} else if (action == 'b') {
			battle(Andrew, Asp);
		} else if (action == 's') {
			save(Andrew);
		}
	}
	
	cout << "You earned " << Andrew.get_xp() << " experience points!" << endl;
	cout << "Well done hero!" << endl;

	return 0;
}


	
