#ifndef BATTLE_SYSTEM_H
#define BATTLE_SYSTEM_H
#include <iostream>
#include <limits>
#include "Pokemon.h"

class BattleSystem {

    public:
        static bool fight(Pokemon* playerMon, Pokemon* enemy){
            std::cout << "\n=== Battle: " << playerMon->getName() << " (" << typeToString(playerMon->getType())
                << ") vs " << enemy->getName() << " (" << typeToString(enemy->getType()) << ") ===\n";

            bool playerTurn = playerMon->getSpeed() >= enemy->getSpeed();

            while (playerMon->getHp() > 0 && enemy->getHp() > 0){
                
                if (playerTurn){
                    
                    auto moves = playerMon->availableMoves();
                    std::cout << "HP Kamu: " << playerMon->getHp() << " | HP Musuh: " << enemy->getHp() << "\n";
                    std::cout << "Pilih serangan:\n";

                    for (size_t i=0;i<moves.size();++i){
                        std::cout << (i+1) << ". " << moves[i] << "\n";
                    }

                    std::cout << "> ";
                    int pick = 1;

                    if(!(std::cin >> pick)){ std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); pick = 1; }
                    --pick; if (pick < 0) pick = 0; if (pick >= (int)moves.size()) pick = (int)moves.size()-1;
                    int dmg = playerMon->computeDamage(pick, enemy->getType());
                    enemy->setHp(enemy->getHp() - dmg);
                    std::cout << "Seranganmu memberi " << dmg << " damage!\n";

                } else {
                    
                    int dmg = enemy->computeDamage(0, playerMon->getType());
                    playerMon->setHp(playerMon->getHp() - dmg);
                    std::cout << enemy->getName() << " menyerang dan memberi " << dmg << " damage!\n";

                }
                playerTurn = !playerTurn; 
            }

            bool win = playerMon->getHp() > 0;
            if (win) std::cout << enemy->getName() << " kalah!\n";
            else     std::cout << playerMon->getName() << " pingsan!\n";
            return win;

        }
};

#endif