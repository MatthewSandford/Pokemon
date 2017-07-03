#include "move.h"

void Move::load_move_data(std::string name)
{
	max_pp = 10;
	current_pp = 10;
	damage = 12;

	move_name = name;
}
