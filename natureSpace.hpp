/*********************************************************************
** Program name: Adventure
** Author: Paul Robinson
** Date: 24-Nov-2017
** Description: Adventure natureSpace definition. Has constructors,
** other functions not used for natureSpaces.
*********************************************************************/
#ifndef NATURESPACE_HPP
#define NATURESPACE_HPP

class NatureSpace : public Space
{

public:
    NatureSpace();
    NatureSpace(Space* northIn, Space* eastIn, Space* southIn, Space* westIn);
    virtual int interact(int val);
    virtual int getSpaceLevel();
};

#endif
