/*********************************************************************
** Program name: Menu Choice
** Author: Paul Robinson
** Date: 22-Oct-2017
** Description: Accepts 2 ints as arguments as low to high range, both inclusive.
** Uses getIntIn and isValidUnsignedInt to get a valid, verified integer from user,
** tests that it is within the range specified. Will continue to ask until valid input received.
*********************************************************************/

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include "menuChoice.hpp"

int menuChoice(int low, int high)
{
    int choice;

    do
    {
        choice = getIntIn();

        if (choice < low || choice > high)
        {
            std::cout << "Invalid selection, try again\n";
        }

    } while (choice < low || choice > high);

    return choice;
}

int getIntIn()
{
    std::string testString = "";
    int testedInt;

    std::getline(std::cin, testString);

    while (testString.empty() || !(isValidUnsignedInt(testString)) || (testString.size() > 5))
    {
        std::cout << "Invalid input. Enter a valid number.\n";
        std::getline(std::cin, testString);
    }

    testedInt = std::stoi(testString);

    return testedInt;
}

int isValidUnsignedInt(std::string strToValidate)
{
    int returnVal = 1;
    int count = 0;

    while ((returnVal == 1) && (count < strToValidate.size()))
    {
        if (!std::isdigit(strToValidate[count]))
        {
            returnVal = 0;
        }
        count++;
    }
    return returnVal;
}
