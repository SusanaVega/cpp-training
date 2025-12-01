#include <iostream>
#include "monsterGame.h"

void printMonster(MonsterStruct& printStruct)
{
    std::cout << "The Monster's type is: ";
    switch (printStruct.monster)
    {
        case Monster::ogre:         std::cout << "ogre"         << std::endl; break;
        case Monster::dragon:       std::cout << "dragon"       << std::endl; break;
        case Monster::orc:          std::cout << "orc"          << std::endl; break;
        case Monster::giant_spider: std::cout << "giant_spider" << std::endl; break;
        case Monster::slime:        std::cout << "slime"        << std::endl; break;
        default:                    std::cout << "???"          << std::endl; break;
    }
    std::cout << "The Monster's name is: " << printStruct.monsterName << std::endl;
    std::cout << "The Monster's health is: " << printStruct.monsterHealth << std::endl;
}