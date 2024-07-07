#include <iostream>
#include <vector>
#include <algorithm>
// We only need this header for the random stuff :)
#include <stdlib.h>

int main()
{
    // Introduction
    std::cout << "Hello, welcome to Rock, Paper and Scissors" << std::endl;
    std::cout << "You need to defeat your enemy three times to win" << std::endl;
    std::cout << "Press R for Rock, P for Paper and S for Scissors" << std::endl;
    std::cout << "Good luck :)" << std::endl;

    // Initializing RNG
    srand(time(0));

    // Behaviour
    int counter = 0;
    while (true)
    {

        std::cout << "\nEnter your Answer:" << std::endl;
        std::cout << "Enter C to check counter" << std::endl;
        char Userinput;
        // User Input
        std::cin >> Userinput;
        if (Userinput == 'C')
        {
            std::cout << counter << std::endl;
            std::cout << "Enter your Answer:" << std::endl;
            std::cin >> Userinput;
        }

        // checking if the user put another value different from the allowed ones
        // So, this is a vector that contains all the values that can be entered
        std::vector<char> v = {'P', 'R', 'S'};
        // This statement checks if the userinput is found in the vector
        // i had to use the algorithm library because of this function.
        if (std::none_of(v.cbegin(), v.cend(), [&Userinput](char p)
                         { return p == Userinput; }))
        {
            std::cout << "Incorrect value, enter a correct value, please." << std::endl;
            std::cin >> Userinput;
        }

        // Random Input
        // We need to convert the integer random input into a char to avoid confussion
        int n = 1 + (rand() % 3);
        char Machineinput;
        if (n == 1)
        {
            Machineinput = 'R';
        }
        else if (n == 2)
        {
            Machineinput = 'P';
        }
        else if (n == 3)
        {
            Machineinput = 'S';
        }

        std::cout << "CPU has chosen " << Machineinput << std::endl;

        // Now we need to compare both variables
        // Maybe there is another way to  avoid all of these if statements, but
        // if it works, it works.
        if (Userinput == Machineinput)
        {
            std::cout << "Draw (+0)";
        }
        else if (Userinput == 'R' and Machineinput == 'S' ||
                 Userinput == 'P' and Machineinput == 'R' ||
                 Userinput == 'S' and Machineinput == 'P')
        {
            std::cout << "You win (+1)" << std::endl;
            counter++;
        }
        else
        {
            std::cout << "You lose (-1)" << std::endl;
            counter--;
        }

        //Checking who wins
        if (counter == 3)
        {
            std::cout << "You have Won the game :)";
            break;
        }
        else if (counter == -3)
        {
            std::cout << "You have lose the game :(";
            break;
        }
    }
    return -1;

    
}