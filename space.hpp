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
#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
#include <iostream>



class Space
{
protected:
    Space* north;   // pointers to other spaces
    Space* east;
    Space* south;
    Space* west;

    std::string stateMsg1;      // messages to be printed throughout the game
    std::string stateMsg2;
    std::string stateMsg3;
    std::string interactMsg1;
    std::string interactMsg2;
    std::string interactMsg3;
    std::string interactMsg4;
    std::string interactMsg5;
    std::string interactMsg6;
    std::string interactMsg7;
    std::string useItemMsg1;
    std::string useItemMsg2;

    int currentStateMessage;    // to determine which of several messages to print
    int currentInteractMessage;
    int currentItemMessage;


    std::string validItem;      // if a space has an item that can be used in it
                                // it is defined in this variable

    // if a space can be "opened" to another space, that is defined here
    int directionToOpen;
    Space* openedSpace;

    // to clarify which type of space it is in calls
    int spaceType;
    // to clarify which of several spaces of the same type a specific space is
    int spaceLevel;

public:
    ~Space();
    Space* getDirectionPtr(int direction);
    void setDirectionPtr(int direction, Space* newPath);
    void setStateMessage(int messageNum, std::string messageIn);
    void setInteractMessage(int messageNum, std::string messageIn);
    void setUseItemMessage(int messageNum, std::string messageIn);
    void setCurrentStateMessage(int num);
    void setCurrentInteractMessage(int num);
    void setCurrentItemMessage(int num);
    int getCurrentItemMessage();
    void printCurrentStateMessage();
    void printCurrentInteractMessage();
    void printCurrentItemMessage();
    void setValidItem(std::string itemIn);
    std::string getValidItem();
    int getSpaceType();
    virtual int interact(int val) = 0;
    virtual int getSpaceLevel() = 0;
    // setting and updating space pointers mid-game
    void setDirectionToOpen(int direction);
    int getDirectionToOpen();
    void setOpenedSpace(Space* newSpace);
    Space* getOpenedSpace();
};

#endif
