/*********************************************************************
** Program name: Adventure
** Author: Paul Robinson
** Date: 24-Nov-2017
** Description:** Description: Adventure menu functions - Provides menu and user input verification
** wherever required for the game, specifically: at start of game, for each round
** to get what user wants to use or do, to choose which item to use, and to choose
** which tool/food to take from a person.
*********************************************************************/

#include <iostream>
#include <string>
#include "menuChoice.hpp"

int adventureMainMenu();

int adventureSpaceMenu(int spaceType);

std::string useItemMenu(std::string item0, std::string item1);

int peopleToolMenu();
int peopleFoodMenu();
