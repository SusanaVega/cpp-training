#include <iostream>
#include "monsterGame.h"
// In designing a game, we decide we want to have monsters, because everyone likes fighting monsters.
// Declare a struct that represents your monster.
// The monster should have a type that can be one of the following: an ogre, a dragon, an orc, a giant spider, or a slime.
// Each individual monster should also have a name (use a std::string), as well as an amount of health that represents how much damage they can take before they die.



int main()
{
    MonsterStruct myMonster {Monster::ogre,"Teofilo",25};
    MonsterStruct myMonster2 {Monster::slime,"Pepe",25};
    //std::cout << myMonster.monsterName;
    printMonster(myMonster); 
    printMonster(myMonster2); 
    return 0;
}