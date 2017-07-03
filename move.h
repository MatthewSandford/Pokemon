#pragma once

#include <iostream>

class Move
{
public:

	Move() {};
	~Move() {};

	int get_damage() { return damage; }
	int get_current_pp() { return current_pp; }
	std::string get_move_name() { return move_name; }

protected:

	int damage;
	int max_pp;
	int current_pp;

	std::string move_name;

	void load_move_data(std::string name);

private:

};
