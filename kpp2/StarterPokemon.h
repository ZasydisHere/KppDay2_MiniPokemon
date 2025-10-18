#ifndef STARTER_POKEMON_H
#define STARTER_POKEMON_H
#include "Pokemon.h"

class StarterPokemon : public Pokemon {
    public:
        StarterPokemon(const std::string& species, Type t)
            : Pokemon(species, t, 50, 20, 15, 5) {}

        std::vector<std::string> availableMoves() const override {
            std::vector<std::string> m;

            m.push_back("Scratch");

            if(level >= 16){
                
                if (type==Type::Fire)   m.push_back("Ember");
                if (type==Type::Grass)  m.push_back("Energy Ball");
                if (type==Type::Water)  m.push_back("Water Pump");

            }

            if(level >= 36){
                
                if (type==Type::Fire)   m.push_back("Overheat");
                if (type==Type::Grass)  m.push_back("Razor Leaf");
                if (type==Type::Water)  m.push_back("Hydro Pump");

            }
            
            return m;

        }

        int computeDamage(int moveIndex, Type enemyType) const override{
            
            int base = 0;
            if (moveIndex == 0) base = 5 + attack;
            else if (moveIndex == 1 && level >= 16) base = 20 + attack;
            else if (moveIndex == 2 && level >= 36) base = 25 + attack;
            else base = 0;

            Type atkType = (moveIndex==0 ? Type::Normal : type);
            double mult = effectiveness(atkType, enemyType);
            return static_cast<int>(base * mult);

        }

        void onAfterBattle() override {

            if (level >= 16) {
                if (name == "Torchic") name = "Combusken";
                else if (name == "Treecko") name = "Grovyle";
                else if (name == "Mudkip") name = "Marshtomp";
            }

            if (level >= 36) {
                if (name == "Combusken") name = "Blaziken";
                else if (name == "Grovyle") name = "Sceptile";
                else if (name == "Marshtomp") name = "Swampert";
            }
        }




};




#endif