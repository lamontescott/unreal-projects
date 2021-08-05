//Title: Triple X
//Author: Lamonte Scott
//Purpose: Terminal base guessing game.
//************************************

//Preprocessor Directives
#include <iostream>
#include <ctime>

//Function Prototype
bool PlayGame (int Level);
void PlayerIntrdouction(int Difficulty);

int main() 
{
    srand(time(NULL));
    
    int LevelDifficulty = 1;
    const int maxDifficulty = 5;

    while (LevelDifficulty <= maxDifficulty) //Loop game until are level are covered
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Reset the working state / Discards the errors
        std::cin.ignore(); //Discards the buffer

        if (bLevelComplete)
            {
                //Increased the level difficulty
                ++LevelDifficulty;
            }
    }
   
   std::cout << "\n*** Great work agrent! You got all the files! Now get out of there! **\n ";
    
    return 0;
}

void PrintIntroduction(int Difficulty)
{
      //Print welcome message to the terminal
    std::cout << "\n\nYou are CodeA scret agent breaking into a level " << Difficulty << " a secure serve room..." << std::endl;
    std::cout << "Enter the correct code to continue..." << std::endl;

}


bool PlayGame (int Level)
{
    PrintIntroduction(Level);

     //Local Variables
    const int CodeA = rand() % Level + Level, CodeB = rand() % Level + Level, CodeC = rand() % Level + Level;
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    int GuessA, GuessB, GuessC;
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA + GuessB + GuessC;

    
    //Print CodeSum and CodeProduct to the terminal
    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code." << std::endl;
    std::cout << "+ The codes add-up to: " << CodeSum <<  std::endl;
    std::cout << "+ The codes multiply to give: " << CodeProduct << std::endl;

    std::cout << "\nPlease enter your three guesses: ";
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "You entered: " << GuessA << " " << GuessB << " " << GuessC << std::endl;

    //Check if player guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
        {
            std::cout << "\nCongrats, you broke the codes." << std::endl;
            std::cout << "You Win\n";
            return true;
        }
    else 
        {
            std::cout << "\nSorry, the codes did match." << std::endl;
            std::cout << "You lose\n";
            return false;
        }

}