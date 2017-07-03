#pragma once

#include "pokemon.h"
#include "pokemon_set.h"

class Pokemon_Spawner
{
public:

	Pokemon_Spawner() {};
	~Pokemon_Spawner() {};

	Pokemon* spawn_random();
	Pokemon* spawn_bulbasaur();
	Pokemon* spawn_charmander();
	Pokemon* spawn_squirtle();

protected:

private:

};
