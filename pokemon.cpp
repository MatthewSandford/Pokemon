#include "pokemon.h"

void Pokemon::take_move(Move * move)
{
	std::cout << pokemon << " took: " << move->get_damage() << " damage!" << std::endl;
	inflict_damage(move->get_damage());
}

Move * Pokemon::use_move(std::string move_name)
{
	if (state == "normal")
	{
		std::cout << pokemon << "used: " << move_name << std::endl;
		return move_map[move_name];
	}
}

Move * Pokemon::use_random_move()
{
	std::map<std::string, Move*>::iterator item = move_map.begin();
	std::advance(item, rand()%move_map.size() );

	std::cout << pokemon << " used: " << item->first << std::endl;

	return item->second;
}

void Pokemon::load_pokemon_data(std::string pokemon_type)
{
	Json::Value root;
	Json::Reader reader;
	reader.parse("pokemon.json", root);

	pokemon = pokemon_type;

	Json::Value pokemon_root(root[pokemon_type]);
	Json::Value moves_root(pokemon_root["moves"]);

	max_health = pokemon_root.get("max_health", 0).asInt();
	current_health = max_health;

	std::string move_name;
	std::vector<std::string> move_names;
	for (int i(0); i < moves_root.size(); i++)
		move_name = moves_root[i].asString();
		move_names.push_back(move_name);
		std::cout << move_name << std::endl;

	Move* move_1 = new Flame_Thrower;
	Move* move_2 = new Scratch;

	move_map.insert(std::pair<std::string, Move*>(move_1->get_move_name(), move_1));
	move_map.insert(std::pair<std::string, Move*>(move_2->get_move_name(), move_2));
}

void Pokemon::inflict_damage(int damage)
{
	current_health -= damage;

	if (current_health < 0)
	{
		current_health = 0;
		state = "dead";

		std::cout << pokemon << " pased out!" << std::endl;
	}
}
