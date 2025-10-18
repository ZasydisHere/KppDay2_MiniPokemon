#ifndef WILD_POKEMON_H
#define WILD_POKEMON_H
#include "Pokemon.h"

class WildPokemon : public Pokemon{

    public:
        explicit WildPokemon(const std::string& species)
            : Pokemon(species, Type::Normal, 45, 10, 10, 3) {}
        
        std::vector<std::string> availableMoves() const override{
            return {"Scratch"};
        }

        int computeDamage(int , Type) const override{

            return 5 + attack;

        }

};

#endif