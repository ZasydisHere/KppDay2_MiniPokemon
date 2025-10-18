#ifndef EFFECTIVENESS_H
#define EFFECTIVENESS_H
#include "Types.h"

inline double effectiveness(Type atk, Type def){

    if (def == Type::Normal || atk == Type::Normal) return 1.0;

    if ((atk == Type::Fire && def == Type::Grass) || 
        (atk == Type::Fire && def == Type::Grass) || 
        (atk == Type::Fire && def == Type::Grass) ) return 2.0;

    if ((atk == Type::Fire && def == Type::Grass) || 
        (atk == Type::Fire && def == Type::Grass) || 
        (atk == Type::Fire && def == Type::Grass) ) return 0.5;    
    
    return 1.0;

}


#endif