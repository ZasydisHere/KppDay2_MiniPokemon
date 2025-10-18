#ifndef PLAYER_H
#define PLAYER_H
#include <memory>
#include <string>
#include "StarterPokemon.h"

class Player{
    private:
        std::string name;
        std::unique_ptr<StarterPokemon> partner;
    
    public:
        Player(std::string n, std::unique_ptr<StarterPokemon> p)
            : name(std::move(n)), partner(std::move(p)) {}


        const std::string& getName() const { return name; }
        StarterPokemon* getPartner() const { return partner.get(); }



};

#endif