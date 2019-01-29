/*********************************************************************
** Program name: Adventure
** Author: Paul Robinson
** Date: 24-Nov-2017
** Description: Adventure animal space subclass. Defines constructors,
** the animalSpace interact function, and required get/set functions.
*********************************************************************/

#include "space.hpp"
#include "animalSpace.hpp"

/*********************************************************************
* default constructor - just sets all pointers to nullptr
*********************************************************************/
AnimalSpace::AnimalSpace()
{
    north = east = south = west = nullptr;
}

/*********************************************************************
* constructor - sets all pointers to place it in the grid, sets the spaceType
* and spaceLevel, and other variables to 0 to start.
*********************************************************************/
AnimalSpace::AnimalSpace(Space* northIn, Space* eastIn, Space* southIn, Space* westIn, int spaceLevelIn)
{
    north = northIn;
    east = eastIn;
    south = southIn;
    west = westIn;
    spaceType = 3;
    directionToOpen = 0;
    spaceLevel = spaceLevelIn;
    baited = 0;
    caught = 0;
}

/*********************************************************************
* Animal interact - called Use your net in the user menu, displays results of
* trying to catch an animal. Receives the level of the player's net and returns
* whether the call resulted in a catch (signified by returning a 1)
*********************************************************************/
int AnimalSpace::interact(int netLevel)
{
    if (netLevel < spaceLevel)
    {
        std::cout << "Your net can't handle these creatures. You need an upgrade.\n";
        return 0;
    }
    else if (!baited)
    {
        std::cout << "They're keeping their distance. You need something to distract them.\n";
        return 0;
    }
    else if (baited && !caught)
    {
        std::cout << "You caught them in your net! Hurry back to the king!\n";
        return 1;
    }
    else
    {
        std::cout << "There's nothing more to catch.\n";
        return 0;
    }
}

/*********************************************************************
* Animal get and set functions
*********************************************************************/
int AnimalSpace::getSpaceLevel()
{
    return spaceLevel;
}
void AnimalSpace::setBaited()
{
    baited = 1;
}
void AnimalSpace::setCaught()
{
    caught = 1;
}
