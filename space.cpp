/*********************************************************************
** Program name: Adventure
** Author: Paul Robinson
** Date: 24-Nov-2017
** Description: Adventure space class definitions: has destructor, then is
** mostly get and set functions for basic aspects of spaces - the pointers
** to other spaces, the messages printed with different user activities and as
** the game progresses, which items can be used in a specific space, and
** which directions can be "opened" into another previously unreachable space.
*********************************************************************/

#include "space.hpp"



Space::~Space()
{

}

/*********************************************************************
* direction pointer - returns a pointer to the space in the direction received
*********************************************************************/
Space* Space::getDirectionPtr(int direction)
{
    if (direction == 1)
    {
        return north;
    }
    else if (direction == 2)
    {
        return east;
    }
    else if (direction == 3)
    {
        return south;
    }
    else if (direction == 4)
    {
        return west;
    }
    else
    {
        std::cout << "menu error\n";
        return 0;
    }
}

/*********************************************************************
* direction pointer - sets a new direction pointer. Used when opening a new space
*********************************************************************/
void Space::setDirectionPtr(int direction, Space* newPath)
{
    if (direction == 1)
    {
        north = newPath;
    }
    else if (direction == 2)
    {
        east = newPath;
    }
    else if (direction == 3)
    {
        south = newPath;
    }
    else if (direction == 4)
    {
        west = newPath;
    }
    else
    {
        std::cout << "path set error\n";
    }
}

/*********************************************************************
* state message - set at beginning of game
*********************************************************************/
void Space::setStateMessage(int messageNum, std::string messageIn)
{
    if (messageNum == 1)
    {
        stateMsg1 = messageIn;
    }
    else if (messageNum == 2)
    {
        stateMsg2 = messageIn;
    }
    else if (messageNum == 3)
    {
        stateMsg3 = messageIn;
    }
    else
    {
        std::cout << "message assignment error\n";
    }
}
/*********************************************************************
* interact message - set at beginning of game
*********************************************************************/
void Space::setInteractMessage(int messageNum, std::string messageIn)
{
    if (messageNum == 1)
    {
        interactMsg1 = messageIn;
    }
    else if (messageNum == 2)
    {
        interactMsg2 = messageIn;
    }
    else if (messageNum == 3)
    {
        interactMsg3 = messageIn;
    }
    else if (messageNum == 4)
    {
        interactMsg4 = messageIn;
    }
    else if (messageNum == 5)
    {
        interactMsg5 = messageIn;
    }
    else if (messageNum == 6)
    {
        interactMsg6 = messageIn;
    }
    else if (messageNum == 7)
    {
        interactMsg7 = messageIn;
    }
    else
    {
        std::cout << "message assignment error\n";
    }
}
/*********************************************************************
* use item message - set at beginning of game
*********************************************************************/
void Space::setUseItemMessage(int messageNum, std::string messageIn)
{
    if (messageNum == 1)
    {
        useItemMsg1 = messageIn;
    }
    else if (messageNum == 2)
    {
        useItemMsg2 = messageIn;
    }
    else
    {
        std::cout << "message assignment error\n";
    }
}

/*********************************************************************
* current message setters - to change which message is printed as
* the game progresses
*********************************************************************/
void Space::setCurrentStateMessage(int num)
{
    currentStateMessage = num;
}
void Space::setCurrentInteractMessage(int num)
{
    currentInteractMessage = num;
}
void Space::setCurrentItemMessage(int num)
{
    currentItemMessage = num;
}

/*********************************************************************
* get current item message indicator - to determine which item message is set,
* used when using an item on a space to determine whether it has been used
* on that space before.
*********************************************************************/
int Space::getCurrentItemMessage()
{
    return currentItemMessage;
}

/*********************************************************************
* print message functions - uses currentMessage indicators to print
* out the appropriate message.
*********************************************************************/
void Space::printCurrentStateMessage()
{
    if (currentStateMessage == 1)
    {
        std::cout << stateMsg1;
    }
    else if (currentStateMessage == 2)
    {
        std::cout << stateMsg2;
    }
    else if (currentStateMessage == 3)
    {
        std::cout << stateMsg3;
    }
    else
    {
        std::cout << "state message print error\n";
    }
}
void Space::printCurrentInteractMessage()
{
    if (currentInteractMessage == 1)
    {
        std::cout << interactMsg1;
    }
    else if (currentInteractMessage == 2)
    {
        std::cout << interactMsg2;
    }
    else if (currentInteractMessage == 3)
    {
        std::cout << interactMsg3;
    }
    else if (currentInteractMessage == 4)
    {
        std::cout << interactMsg4;
    }
    else if (currentInteractMessage == 5)
    {
        std::cout << interactMsg5;
    }
    else if (currentInteractMessage == 6)
    {
        std::cout << interactMsg6;
    }
    else if (currentInteractMessage == 7)
    {
        std::cout << interactMsg7;
    }
    else
    {
        std::cout << "interact message print error\n";
    }
}
void Space::printCurrentItemMessage()
{
    if (currentItemMessage == 1)
    {
        std::cout << useItemMsg1;
    }
    else if (currentItemMessage == 2)
    {
        std::cout << useItemMsg2;
    }
    else
    {
        std::cout << "item message print error\n";
    }
}

/*********************************************************************
* item functions - set used in constructor, get used to check if what
* the player is using matches the current spaces valid item
*********************************************************************/
void Space::setValidItem(std::string itemIn)
{
    validItem = itemIn;
}
std::string Space::getValidItem()
{
    return validItem;
}

/*********************************************************************
* getSpaceType - returns an int, 1 = nature, 2 = people, 3 = animal
*********************************************************************/
int Space::getSpaceType()
{
    return spaceType;
}

/*********************************************************************
* space opening functions - used when a previously closed direction is
* opened by the use of an item.
*********************************************************************/
void Space::setDirectionToOpen(int direction)
{
    directionToOpen = direction;
}
int Space::getDirectionToOpen()
{
    return directionToOpen;
}
void Space::setOpenedSpace(Space* newSpace)
{
    openedSpace = newSpace;
}
Space* Space::getOpenedSpace()
{
    return openedSpace;
}
