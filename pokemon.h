#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "move.h"
#include "move_set.h"

class Pokemon
{
public:

	Pokemon() : state("normal") {};
	~Pokemon() {};

	std::string get_state() { return state; }
	std::string get_name() { return name; }
	std::string get_pokemon() { return pokemon; }

	int get_max_health() { return max_health; }
	int get_current_health() { return current_health; }

	void take_move(Move* move);

	Move* use_move(std::string move_name);
	Move* use_random_move();

protected:

	std::string name;
	std::string pokemon;

	void load_pokemon_data(std::string pokemon_type);

	std::map<std::string, Move*> move_map;

private:

	int max_health;
	int current_health;
	std::string state;

	void inflict_damage(int damage);
};