#include "pokemon_spawner.h"

Pokemon* Pokemon_Spawner::spawn_random()
{
	int i(rand()%3);

	switch(i)
	{
		case 0:
		{
			Pokemon* charmander = new Charmander;
			return charmander;
		}
		break;

		case 1:
		{
			Pokemon* bulbasaur = new Bulbasaur;
			return bulbasaur;
		}
		break;

		case 2:
		{
			Pokemon* squirtle = new Squirtle;
			return squirtle;
		}
		break;
	}
}

Pokemon* Pokemon_Spawner::spawn_bulbasaur()
{
	Pokemon* bulbasaur = new Bulbasaur;
	return bulbasaur;
}

Pokemon* Pokemon_Spawner::spawn_charmander()
{
	Pokemon* charmander = new Charmander;
	return charmander;
}

Pokemon* Pokemon_Spawner::spawn_squirtle()
{
	Pokemon* squirtle = new Squirtle;
	return squirtle;
}
