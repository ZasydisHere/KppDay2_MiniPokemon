#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "WildPokemon.h"
#include "ElitePokemon.h"
#include "BattleSystem.h"

class GameManager{
    private:
        std::unique_ptr<Player> player;
        std::vector<std::unique_ptr<ElitePokemon>> elites;

        
        std::unique_ptr<WildPokemon> createRandomWild(){
            static const char* names[] = {"Virogoth", "Zangoose", "Rattice"};
            int idx = std::rand() % 3;
            return std::make_unique<WildPokemon>(names[idx]);
        }

        void initElitesByStarter(const std::string& starter){
            elites.clear();

            if (starter == "Treecko" || starter == "Grovyle" || starter == "Sceptile"){

                elites.emplace_back(std::make_unique<ElitePokemon>("Kingdra",   Type::Water));
                elites.emplace_back(std::make_unique<ElitePokemon>("Cacturne",  Type::Grass));
                elites.emplace_back(std::make_unique<ElitePokemon>("Chandelure",Type::Fire));
            } else if (starter == "Mudkip" || starter == "Marshtomp" || starter == "Swampert"){

                elites.emplace_back(std::make_unique<ElitePokemon>("Chandelure",Type::Fire));
                elites.emplace_back(std::make_unique<ElitePokemon>("Kingdra",   Type::Water));
                elites.emplace_back(std::make_unique<ElitePokemon>("Cacturne",  Type::Grass));
            } else {

                elites.emplace_back(std::make_unique<ElitePokemon>("Cacturne",  Type::Grass));
                elites.emplace_back(std::make_unique<ElitePokemon>("Chandelure",Type::Fire));
                elites.emplace_back(std::make_unique<ElitePokemon>("Kingdra",   Type::Water));
            }
        }

        static void showPartnerStatus(const StarterPokemon* p){
            std::cout << "\n=== Status Partner ===\n";
            std::cout << "Nama   : " << p->getName() << " (" << typeToString(p->getType()) << ")\n";
            std::cout << "Level  : " << p->getLevel() << "\n";
            std::cout << "HP     : " << p->getHp() << "\n";
            std::cout << "ATK/SPD: " << p->getAttack() << "/" << p->getSpeed() << "\n";
            std::cout << "Moves  : ";
            auto mv = p->availableMoves();
            for(size_t i=0;i<mv.size();++i){ std::cout << mv[i] << (i+1<mv.size()?", ":"\n"); }
            if (mv.empty()) std::cout << "-\n";
        }
    
    public:
        GameManager(){ std::srand(static_cast<unsigned>(std::time(nullptr))); }

        void start(){
            std::cout << "Halo, selamat datang di region Hoenn sekarang pilihlah pokemonmu sebagai rekanmu\n";
            std::cout << "1. Torchic (Fire)\n2. Treecko (Grass)\n3. Mudkip (Water)\n> ";
            int c = 1; std::cin >> c; if (c<1||c>3) c=1;

            std::unique_ptr<StarterPokemon> starter;
            if (c==1) starter = std::make_unique<StarterPokemon>("Torchic", Type::Fire);
            else if (c==2) starter = std::make_unique<StarterPokemon>("Treecko", Type::Grass);
            else starter = std::make_unique<StarterPokemon>("Mudkip", Type::Water);

            player = std::make_unique<Player>("Doni", std::move(starter));
            initElitesByStarter(player->getPartner()->getName());
            mainMenu();
        }

        void mainMenu(){
            while (true){
                std::cout << "\n=== MENU ===\n";
                std::cout << "1. Berjalan ke semak-semak\n";
                std::cout << "2. Pergi ke Medical Center\n";
                std::cout << "3. Melawan Elite\n";
                std::cout << "4. Lihat Status Partner (Read)\n";
                std::cout << "5. Keluar\n> ";
                int pick = 0; std::cin >> pick;
                if (pick==1) wildEncounter();
                else if (pick==2) medicalCenter();
                else if (pick==3) eliteBattle();
                else if (pick==4) showPartnerStatus(player->getPartner());
                else if (pick==5) break;
            }
        }

        void medicalCenter(){
            player->getPartner()->healFull();
            std::cout << "Partner dipulihkan ke HP penuh! (HP disimpan antar pertarungan)\n";
        }

        void wildEncounter(){
            auto wild = createRandomWild(); 
            bool win = BattleSystem::fight(player->getPartner(), wild.get());
            if (win){

                player->getPartner()->levelUp();
                player->getPartner()->onAfterBattle();
            }

        }

        void eliteBattle(){
            if (elites.empty()){
                std::cout << "CONGRATS CHAMPIONS\n";
                return;
            }
            ElitePokemon* boss = elites.front().get();
            std::cout << "\nMenantang Elite: " << boss->getName() << " (" << typeToString(boss->getType()) << ")\n";
            bool win = BattleSystem::fight(player->getPartner(), boss);
            if (win){

                elites.erase(elites.begin());
                
                player->getPartner()->levelUp();
                player->getPartner()->onAfterBattle();
                if (elites.empty()) std::cout << "CONGRATS CHAMPIONS\n";
            }
        }
};

#endif