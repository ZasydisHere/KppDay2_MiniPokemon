#ifndef ELITE_POKEMON_H
#define ELITE_POKEMON_H
#include "Pokemon.h"

class ElitePokemon : public Pokemon{
    public:
        ElitePokemon(const std::string& species, Type t)
            : Pokemon(species, t, 150, 35, 40, 50) {}


        std::vector<std::string> availableMoves() const override{

            return {"Elite Strike"};

        }

        int computeDamage(int, Type enemyType) const override {
            
            int base = 20 + attack;
            double mult = effectiveness(type, enemyType);
            return static_cast<int>(base * mult);
            
        }
};

#endif