/*********************************************************************
** Program name: Adventure
** Author: Paul Robinson
** Date: 24-Nov-2017
** Description: Adventure animal space subclass. Defines constructors,
** the animalSpace interact function, and required get/set functions.
*********************************************************************/

#ifndef ANIMALSPACE_HPP
#define ANIMALSPACE_HPP

class AnimalSpace : public Space
{
private:
    bool baited;    // specific to animals, to indicate whether baited or caught
    bool caught;

public:
    AnimalSpace();
    AnimalSpace(Space* northIn, Space* eastIn, Space* southIn, Space* westIn, int netLevelIn);

    virtual int interact(int netLevel);
    virtual int getSpaceLevel();
    virtual void setBaited();
    virtual void setCaught();
};

#endif
