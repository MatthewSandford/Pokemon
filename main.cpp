#include <iostream>
#include <time.h>

#include "pokemon.h"
#include "pokemon_spawner.h"

int main(int argc, char** argv)
{
	srand(time(NULL));

	Pokemon_Spawner spawner;

	Pokemon* pokemon_1(spawner.spawn_random());
	Pokemon* pokemon_2(spawner.spawn_random());

	std::cout << "Let the battle commence between: " << pokemon_1->get_pokemon() << " and " << pokemon_2->get_pokemon() << std::endl;

	int turn(0);

	while (pokemon_1->get_state() != "dead" && pokemon_2->get_state() != "dead")
	{
		if (turn)
		{
			pokemon_1->take_move(pokemon_2->use_random_move());
		}
		else
		{
			pokemon_2->take_move(pokemon_1->use_random_move());
		}

		turn = 1 - turn;
	}

	system("PAUSE");

	return 0;
}