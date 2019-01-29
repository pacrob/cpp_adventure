/*********************************************************************
** Program name: Adventure
** Author: Paul Robinson
** Date: 24-Nov-2017
** Description: Adventure peopleSpace definition. Has constructors, a get
** function for spaceLevel, and its interact function, which determines
** which item menu to display.
*********************************************************************/
#ifndef PEOPLESPACE_HPP
#define PEOPLESPACE_HPP

#include "adventureMenu.hpp"

class PeopleSpace : public Space
{

public:
    PeopleSpace();
    PeopleSpace(Space* northIn, Space* eastIn, Space* southIn, Space* westIn, int spaceLevelIn);
    virtual int interact(int spaceLevelIn);
    virtual int getSpaceLevel();
};

#endif
