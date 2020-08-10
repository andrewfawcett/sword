#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Player {
private:
	int total_xp = 0;
	int strengh = 1;
	int weapon = 0;

public:
	int get_xp() { return total_xp; };
	void add_xp(int xp) { total_xp += xp; };
	void equip_weapon(int new_weapon) { weapon = new_weapon; };
	int attack() { return strengh + weapon; };
};

class Enemy { 
private:
	string name;
	int health;
	int xp;

public:
	// Constructors
	Enemy(string new_name, int new_health);
	string get_name();
	int get_health();
	void set_health(int new_health);
	int get_xp();
};

Enemy::Enemy(string new_name, int new_health) {
	name = new_name;
	health = new_health;
}	

string Enemy::get_name() {return name;}
int Enemy::get_health() { return health; }
void Enemy::set_health(int new_health) { health = new_health; }
int Enemy::get_xp() {return xp;}



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
	};
	cout << "You defeated the enemy!" << endl;
	character.add_xp(monster.get_xp());
	cout << "You earned " << monster.get_xp() << " experience points." << endl;
};

void inventory(Player &character) {
	// const int fist = 0;
	const int sword = 1;
	
	char action;
	while (action != 'q') {
		cout << "(e)quip, (l)ist, (q)uit: ";
		cin >> action;
		if (action == 'e') {
			character.equip_weapon(sword);
			cout << "You equiped a weapon!" << endl;
		};
	};
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
	Enemy Asp ("Asp", 7);

	char action;
	
	while (action != 'l' and 'n' and 'q' ) {
		cout << "(l)oad game, (n)ew game, (q)uit: ";
		cin >> action;
		if (action == 'l') {
			cout << "loading game" << endl;
		} else if (action == 'n') {
			cout << "starting new game!" << endl;
		}
	}
	
	while (action !=  'q') {
		cout << "(i)nventory, (b)attle, (s)ave, (q)uit: ";
		cin >> action;
		if (action == 'i') {
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


	
