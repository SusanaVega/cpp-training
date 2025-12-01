#undef NDEBUG // disable asserts (must be placed before any #includes)
#include <cassert>
#include <iostream>
#include "Random.h"
#define NUMOFCHANCES 7u
#define MIN 0u
#define MAX 100u


int readInput (int guessNum) {
    //This while is handling wrong inputs
    int input{};
    while (true){
        std::cin >> input;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input please enter another number" << std::endl;
        }
        else{
            break;
        }

    }
    //assert(input >= MIN && input <= MAX && "Invalid input");
    // clear out any extraneous input
    std::cout << "Guess #" << guessNum << ": " << input << std::endl;
    return input;
}

void gameLoop (){
    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is." << std::endl;
    std::cout << __cplusplus << std::endl;
    int randomNum = Random::get(MIN , MAX);
    std::cout << "randomNum: " << randomNum << std::endl;
    for (int i = 1; i <= NUMOFCHANCES; i++){
        int userGuess = readInput(i);
        if(userGuess < randomNum){
            std::cout << "Your guess is too low" << std::endl;
        }
        else if(userGuess > randomNum){
            std::cout << "Your guess is too high" << std::endl;
        }
        else if (userGuess == randomNum){
            std::cout << "Correct! You win!" << std::endl;
            break;
        }
    }
}

int main (){
    gameLoop(); 
        while(true){
            std::cout << "Would you like to play again (y/n)";
            char playAgain {};
            std:: cin >> playAgain;
            if (playAgain == 'y'){
                gameLoop();
            }
            else if (playAgain == 'n'){
                std::cout << "Thanks you for playing" << std::endl;
                break;
            }
            else{
                std::cout << "Would you like to play again (y/n)";
            }

        }
    return 0;
}