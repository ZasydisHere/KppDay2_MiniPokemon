#ifndef POKEMON_H
#define POKEMON_H
#include <string>
#include <vector>
#include <iostream>
#include "Types.h"
#include "Effectiveness.h"


class Pokemon {
    protected:
        std::string name;
        Type type;
        int hp;
        int attack;
        int speed;
        int level;

    public:
    Pokemon(const std::string& n, Type t, int baseHp, int atk, int spd, int lvl) 
            : name(n), type(t), hp(baseHp), attack(atk), speed(spd), level(lvl) {}
    virtual ~Pokemon() = default;

    const std::string& getName() const {return name;}
    Type getType() const {return type;}
    int getHp() const {return hp;}
    int getAttack() const {return attack;}
    int getSpeed() const {return speed;}
    int getLevel() const {return level;}

    void setHp(int value){
        hp = (value<0?0:value);
    }

    void setLevel(int value){
        level = value;
    }

    virtual void healFull(){
        int base = 50 + (level -5) * 5;
        if (base < 1) base = 1;
        hp = base;
    }

    virtual std::vector<std::string> availableMoves() const = 0; 
    virtual int computeDamage(int moveIndex, Type enemyType) const = 0;

    virtual void levelUp(){
        ++level;
        hp += 5;
        attack += 1;
        speed += 2;
        std::cout<< name <<" naik level ke "<<level<< "!\n";
    }

    virtual void onAfterBattle(){}
    
};

#endif