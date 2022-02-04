#include <iostream>
#include <ctime>


void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou're a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room...\n You need to enter the correct code in order to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    //display start message
    PrintIntroduction(Difficulty);


    // Declares 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;


    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Prints sum and product to terminal
    std::cout << std::endl;
    std::cout << "There are 3 numbers in the code";
    std::cout << "\n+ The codes add up to: " << CodeSum << std::endl;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    //store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if guess is correct
    if (GuessSum == CodeSum && GuessProduct == GuessProduct)
    {
        std::cout << "\nYou Win!";
        return true;
    }
    else
    {
        std::cout << "\nYou Lose :(";
        return false;
    }
}

int main()
{
    srand(time(NULL));

    int LevelDifficulty = 1;
    int const MaxLevelDifficulty = 5;

    while (LevelDifficulty <= MaxLevelDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //clears any arrors
        std::cin.ignore(); //discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    
    std::cout << "\n*** Great Work!! You got all the files!! Now get out of there!!! ***\n";
    return 0;
}
