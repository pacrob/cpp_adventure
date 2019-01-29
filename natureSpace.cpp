/*********************************************************************
** Program name: Adventure
** Author: Paul Robinson
** Date: 24-Nov-2017
** Description: Adventure natureSpace definition. Has constructors,
** other functions not used for natureSpaces.
*********************************************************************/

#include "space.hpp"
#include "natureSpace.hpp"

/*********************************************************************
* default constructor - just sets all pointers to nullptr
*********************************************************************/
NatureSpace::NatureSpace()
{
    north = east = south = west = nullptr;
}
/*********************************************************************
* constructor - sets all pointers to place it in the grid, sets the spaceType,
* and other variables to 0 to start.
*********************************************************************/
NatureSpace::NatureSpace(Space* northIn, Space* eastIn, Space* southIn, Space* westIn)
{
    north = northIn;
    east = eastIn;
    south = southIn;
    west = westIn;
    spaceType = 1;
    directionToOpen = 0;
}
int NatureSpace::interact(int val)
{
    return 0;
}
int NatureSpace::getSpaceLevel()
{
    return 0;
}
