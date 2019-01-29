/*********************************************************************
** Program name: Adventure
** Author: Paul Robinson
** Date: 24-Nov-2017
** Description: Adventure class - game play runs via a loop in playGame. Further
** detail in the method description, but it is called by main in adventureMain.cpp.
** Also has methods to move the currentSpace to the nextSpace that the user
** indicates and add an item to the pouch. Constructor sets up all spaces that
** the user can move through.
*********************************************************************/

#ifndef ADVENTURE_HPP
#define ADVENTURE_HPP

#include <iostream>
#include "space.hpp"
#include "natureSpace.hpp"
#include "animalSpace.hpp"
#include "peopleSpace.hpp"
#include "adventureMenu.hpp"


class Adventure
{
private:

    Space* currentSpace;    // keeping track of which space the player is in
    Space* nextSpace;
    std::string pouch[2];   // container to hold items
    int netLevel;           // strengths of the player's net
    bool monkeysCaught;     // whether each animal type has been caught yet
    bool elephantsCaught;
    bool pigsCaught;
    int stepsLeft;          // counter to limit how many spaces the player may move

    // all the spaces that are created to move around in
    NatureSpace castleFront;
    PeopleSpace kingRoom;
    PeopleSpace workshop;
    PeopleSpace village;
    NatureSpace fields;
    NatureSpace hills;
    NatureSpace jungle;
    NatureSpace forest;
    NatureSpace river;
    AnimalSpace monkeys;
    AnimalSpace elephants;
    AnimalSpace pigs;
public:
    Adventure();
    ~Adventure();
    void playGame();    
    int moveSpace(int direction);
    void addToPouch(std::string itemIn);

};

#endif
