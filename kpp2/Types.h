#ifndef TYPES_H
#define TYPES_H
#include <string>

enum class Type {Fire, Water, Grass, Normal};

inline std::string typeToString(Type t){
    switch(t){
        case Type::Fire: return "Fire";
        case Type::Water: return "Water";
        case Type::Grass: return "Grass";
        default: return "Normal";
    }
}

#endif