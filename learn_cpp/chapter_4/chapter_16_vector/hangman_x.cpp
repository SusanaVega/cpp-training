#include <iostream>
#include <cassert>
#include <vector>
#include <string_view>
#include <limits>
#include "C:\Users\jorge\OneDrive\Documentos 1\cpp\learn_cpp\chapter_4\Chapter_8\Random.h"
#include <algorithm>
#define MAX_ATTEMPTS 6


using namespace std::literals::string_view_literals;

namespace WordList
{
    const std::vector<std::string_view> word{"mystery"sv, "broccoli"sv, "account"sv, "almost"sv, "spaghetti"sv, "opinion"sv, "beautiful"sv, "distance"sv, "luggage"sv};

    std::string_view randWord()
    {
        //std::cout << "test: " << WordList::word[Random::get(0,WordList::word.size())];
        return WordList::word[Random::get(0,WordList::word.size())];
    }

}



class Session
{
    private:
    std::string_view m_randomWord {WordList::randWord()};
    std::vector<char> m_letterTracker{};
    std::vector<char> m_guesses{'+','+','+','+','+','+'};
    std::size_t m_failedCounter{};
    std::vector<bool> m_winFlag {}; 


    public:
    Session(std::string_view str)
        :m_randomWord{str}, m_winFlag (m_randomWord.size())
    {

    }
    std::string_view getWord() const {return m_randomWord;}
    void setLetterTracker(char letterInput) {m_letterTracker.push_back(letterInput);}
    std::vector<char> getLetterTracker() const {return m_letterTracker;}
    std::vector<char> getGuesses() const {return m_guesses;}
    void setFailedCounter() {m_failedCounter++;}
    std::vector<bool> getWinFlag() {return m_winFlag;}
    void setWinFlag(size_t element) {m_winFlag[element]=true;}
    std::size_t getFailedCounter() {return m_failedCounter;}
    void setGuesses() 
    {
        m_guesses[m_guesses.size()-m_failedCounter] = getLetterTracker().back();
    }
    void sortGuesses()
    {
        char temp{};
        //m_guesses={'d','r','a'};
        for (auto i{0}; i<m_guesses.size(); i++)
        {
            for (size_t j{0}; j < m_guesses.size(); j++)
            {
                if ((m_guesses[i] < m_guesses[j]) && (m_guesses[i] != '+'))
                {
                    temp = m_guesses[i];
                    m_guesses[i] = m_guesses[j];
                    m_guesses[j] = temp;
                }
            }
        }    
    }
    
};

void checkGuesses(Session& s1, bool isInTheWord =false)
{
    for (auto i : s1.getWord())
    {
        if (!s1.getLetterTracker().empty())
        {
            if (i == s1.getLetterTracker().back())
            {
                isInTheWord = true;
            } 
        }  
    }
    std::cout << "   Wrong guesses: " ;
    for (auto i : s1.getGuesses())
    {
        std::cout << i;
    }
    std::cout << std::endl;

    if (isInTheWord)
    {
        std::cout << "Yes,  "<< "'" << s1.getLetterTracker().back() << "'" <<" is in the word!" << std::endl;
    }
    else if (!s1.getLetterTracker().empty())
    {
        s1.setFailedCounter();
        std::cout << "No,  "<< "'" << s1.getLetterTracker().back() << "'" <<" is not in the word!" << std::endl;
        s1.setGuesses();
        s1.sortGuesses();
    }
    
}

char userInput(const Session& s1)
{
    char letter{};
    std::cout << "Enter your next letter: ";
    std::cin >> letter;
    while (!std::cin || !std::isalpha(letter)) // handle bad input
    {
        std::cout << "That wasn't a valid input.  Try again."<< std::endl;
        std::cin.clear();
	    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter your next letter: " ;
        std::cin >> letter;        
    }
    while (true)
    {
        bool brake_flag {false};
        if (s1.getLetterTracker().empty())
        {
            break;
        }
        for (auto i : s1.getLetterTracker())
        {
            if (i == letter)
            {
                std::cout << "You already guessed that. Try Again." << std::endl;
            }
            else
            {
                brake_flag = true;
            }
            
        }
        if (brake_flag)
        {
            break;
        }
        
        std::cin.clear();
	    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter your next letter: " ;
        std::cin >> letter;        
    }
    //std::cout << std::endl << "You entered: " << letter << std::endl;
    return letter;
}

void gameStatus (Session& s1)
{
    std::cout <<std::endl << "The word: ";
    bool letterFound{false};
    bool isInTheWord{false};
    for (size_t i{}; i < s1.getWord().size(); i++)
    {
        if (!s1.getLetterTracker().empty())
        {
            if (s1.getWord()[i] == s1.getLetterTracker().back())
            {
                isInTheWord = true;
            } 
        }  
        for (size_t j{}; j < s1.getLetterTracker().size(); j++)
        {
            
            if (s1.getLetterTracker()[j] == s1.getWord()[i])
            {
                letterFound = true;
                //isInTheWord = false;
            }  
        }
        if (letterFound)
        {
            std::cout << s1.getWord()[i];
            s1.setWinFlag(i);
            letterFound = false;
            //isInTheWord = true;
        }
        else
        {
            std::cout << "_" ;
        }
        
    }
    checkGuesses(s1, isInTheWord);

    
}

bool winLossCondition(Session& s1)
{
    bool winLossCondition{false};

    if (s1.getFailedCounter() == MAX_ATTEMPTS)
    {
        winLossCondition = true;
        std::cout << "You lost! "<<  "The word was: "<< s1.getWord() << std::endl;
        return winLossCondition;
    }


    //Win
    int winCounter {};
    for (size_t i = 0; i < s1.getWord().size(); i++)
    {
        if (s1.getWinFlag()[i] == true)
        {
            winCounter++;
        }
    }

    if (winCounter == s1.getWord().size())
    {
        winLossCondition = true;
        std::cout << "You won! "<<  "The word was: "<< s1.getWord() << std::endl;
    }
     
    return winLossCondition;
}




int main()
{
    std::cout << "Welcome to C++man (avariant of Hangman)" << std::endl;
    std::cout << "To win: guess the word.  To lose: run out of pluses." << std::endl << std::endl;
    std::string_view myRandWord {WordList::randWord()};
    std::cout << "The word is: " << myRandWord << std::endl;
    Session first_session{myRandWord};
    gameStatus(first_session);
    bool lostCondition{false};
    while (lostCondition == false)
    {
        first_session.setLetterTracker(userInput(first_session));
        gameStatus(first_session);
        lostCondition = winLossCondition(first_session);
    }
    return 0;
}