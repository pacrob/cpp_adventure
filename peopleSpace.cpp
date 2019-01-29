/*********************************************************************
** Program name: Adventure
** Author: Paul Robinson
** Date: 24-Nov-2017
** Description: Adventure peopleSpace definition. Has constructors, a get
** function for spaceLevel, and its interact function, which determines
** which item menu to display.
*********************************************************************/

#include "space.hpp"
#include "peopleSpace.hpp"

/*********************************************************************
* default constructor - just sets all pointers to nullptr
*********************************************************************/
PeopleSpace::PeopleSpace()
{
    north = east = south = west = nullptr;
}

/*********************************************************************
* constructor - sets all pointers to place it in the grid, sets the spaceType,
* and other variables to 0 to start.
*********************************************************************/
PeopleSpace::PeopleSpace(Space* northIn, Space* eastIn, Space* southIn, Space* westIn, int spaceLevelIn)
{
    north = northIn;
    east = eastIn;
    south = southIn;
    west = westIn;
    spaceType = 2;
    directionToOpen = 0;
    spaceLevel = spaceLevelIn;
}

/*********************************************************************
* peopleSpace interact function - for people, interact functions to determine
* which item menu to show the user (for spaceLevel, 1 is king, 2 is workshop
* and 3 is village).
*********************************************************************/
int PeopleSpace::interact(int spaceLevelIn)
{
    if (spaceLevelIn == 1)
    {
        return 0;
    }
    else if (spaceLevelIn == 2)
    {
        return peopleToolMenu();
    }
    else if (spaceLevelIn == 3)
    {
        return peopleFoodMenu();
    }
    else
    {
        return 1;
    }
}

/*********************************************************************
* peopleSpace get function
*********************************************************************/
int PeopleSpace::getSpaceLevel()
{
    return spaceLevel;
}
