/*********************************************************************
** Program name: Adventure
** Author: Paul Robinson
** Date: 24-Nov-2017
** Description: Adventure menu functions - Provides menu and user input verification
** wherever required for the game, specifically: at start of game, for each round
** to get what user wants to use or do, to choose which item to use, and to choose
** which tool/food to take from a person.
*********************************************************************/

#include "adventureMenu.hpp"

int adventureMainMenu()
{
    std::cout << "\n\nWelcome to The Adventure!\nIn this game, you are a helpful traveler who has come\n"
              << "upon a kingdom that is beset by woe. A number of winged creatures\n"
              << "are terrorizing the countryside. You need catch each animal, using\n"
              << "tools you find along the way to help you.\nFor more information, talk to the king.\n"
              << "What would you like to do:\n1) Play the game\n2) Quit\n";
    return menuChoice(1, 2);
}

int adventureSpaceMenu(int spaceType)
{
    std::cout << "What would you like to do:\n";
    if (spaceType == 1)
    {
        std::cout << "1) Look around\n";
    }
    else if (spaceType == 2)
    {
        std::cout << "1) Talk\n";
    }
    else if (spaceType == 3)
    {
        std::cout << "1) Use your net\n";
    }
    std::cout << "2) Use an item\n3) Move north\n4) Move east\n5) Move south\n6) Move west\n7) Quit game\n";
    return menuChoice(1, 7);
}

std::string useItemMenu(std::string item0, std::string item1)
{

    std::cout << "What item would you like to use?\n1) " << item0 << "\n2) " << item1 << "\n";
    int choice = menuChoice(1, 2);
    if (choice == 1)
    {
        return item0;
    }
    else if (choice == 2)
    {
        return item1;
    }
    else
    {
        return "use item error";
    }
}

int peopleToolMenu()
{
    std::cout << "Welcome to the workshop! I can help you on your mission by providing tools."
              << "\nRemember that you can only carry two items at a time.\nIf you take more, you'll just drop one that you already have."
              << "\n\nWhat tool would you like?\n1) scythe\n2) machete\n3) axe\n";
    return menuChoice(1, 3);
}

int peopleFoodMenu()
{
    std::cout << "Welcome to the village!\nBoy, are we mad at our king. Lazy jerk just lets these animals run crazy.\n"
              << "We're gonna toss him out if this goes on much longer. Oh, you're trying to help?\nWell, all we can offer is some of our food."
              << "\nRemember that you can only carry two items at a time.\nIf you take more, you'll just drop one that you already have."
              << "\n\nWhat food would you like?\n1) corn\n2) bananas\n3) peanuts\n";
    return menuChoice(1, 3);
}
