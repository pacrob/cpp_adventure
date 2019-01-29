/*********************************************************************
** Program name: Final Project - Adventure
** Author: Paul Robinson
** Date: 24-Nov-2017
** Description: Adventure is a text based game where the user must collect items
** and animals to keep the people of the kingdom from overthrowing their king.
** Interaction is done through a menu, where each location/space has the option
** to use an item or move to an adjacent space, and the 'interact' option is
** different depending on the space. There are 16 spaces total.
** Net upgrades are from the king, tools are from the workshop, and food is from
** the village. As a bit of a cheat sheet, 1) get the corn and scythe to catch
** the pigs, 2) get the bananas and the machete to catch the monkeys, and 3) get
** the peanutes and the axe to catch the elephants. Go to the king after catching
** each animal to get the required net upgrade.
*********************************************************************/

#include <iostream>
#include "adventureMenu.hpp"
#include "adventure.hpp"

int main()
{

    Adventure theGame = Adventure();

    theGame.playGame();

    return 0;
}
