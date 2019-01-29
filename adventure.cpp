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

#include "adventure.hpp"


/*********************************************************************
* Adventure constructor - initializes all variables used through the game,
* and sets up the spaces including what tools are effective, what people might
* say or do, or what happens when you interact with a space.
* State messages are automatically printed when user enters a space
* Interact messages print when user chooses the interact option (look around, talk, catch)
* UseItem messages print when the user uses a specific item in the appropriate place.
*********************************************************************/
Adventure::Adventure()
{
    stepsLeft = 50;
    pouch[0] = "empty";
    pouch[1] = "empty";
    netLevel = 0;
    monkeysCaught = 0;
    elephantsCaught = 0;
    pigsCaught = 0;

    // create 12 spaces
    castleFront = NatureSpace(&kingRoom, nullptr, &village, nullptr);
    castleFront.setStateMessage(1, "You are in front of the castle.\nGo north to enter and see the king. A village lies to the south.\n");
    castleFront.setInteractMessage(1, "The castle is enormous! Must be a pretty important king.\n");
    castleFront.setCurrentStateMessage(1);
    castleFront.setCurrentInteractMessage(1);
    // Player always starts outside the castle
    currentSpace = &castleFront;

    kingRoom = PeopleSpace(nullptr, nullptr, &castleFront, &workshop, 1);
    kingRoom.setStateMessage(1, "You are in the king's chambers.\nTalk to the king! Go west to visit the workshop or south to exit the castle.\n");
    kingRoom.setInteractMessage(1, "Welcome to my kingdom! I'm in a bit of trouble. Can you help?\nWinged creatures are terrorizing the land."
                                    "\nYou look capable. I'll give you this net to allow you to catch them,\nthough it may need improvement for"
                                    " some of the larger animals.\nFlying pigs, flying monkeys, and even flying elephants have been reported!\n"
                                    "You'll need to collect some items to help you along the way.\nStart by going to see the workshop for tools.\n"
                                    "Oh, and please don't dally - the people are promising to overthrow me\nif the animal problem isn't handled soon.\n"
                                    "You'll be able to make 50 moves before they storm the castle and\nthen who knows what will happen. Please hurry!\n"
                                    "Come back and see me after you catch each animal and I'll see about\ngetting you a better net each time.\n"
                                    "The pigs should be the easiest to catch. You'll find them near the fields.\n");
    kingRoom.setInteractMessage(2, "The pigs should be the easiest to catch. You'll find them near the fields.\n");
    kingRoom.setInteractMessage(3, "You caught the pigs! Thank you so much! Pesky buggers. Next on the list is the flying monkeys.\n"
                                    "You'll need a better net - here's one that has a closure at the top\nto keep the monkeys from escaping.\n"
                                    "You should start searching for the monkeys near the jungle.\nIt's somewhere east of the village. Good luck!\n");
    kingRoom.setInteractMessage(4, "You should start searching for the monkeys near the jungle.\nIt's somewhere east of the village. Good luck!\n");
    kingRoom.setInteractMessage(5, "Oh my goodness, you got the monkeys! You're doing so well!\nThe last on the list are the elephants. They're huge!\n"
                                    "You'll definitely need more net. Here's the biggest one I could find. I hope it does the trick\n"
                                    "The elephants were last reported near the forest. That's west of the fields. Please hurry!\n");
    kingRoom.setInteractMessage(6, "The elephants were last reported near the forest. That's west of the fields. Please hurry!\n");
    kingRoom.setInteractMessage(7, "You've caught all the animals! You're amazing! Here is lots of money as a reward.\n\nGame Over\n");
    kingRoom.setCurrentStateMessage(1);
    kingRoom.setCurrentInteractMessage(1);

    workshop = PeopleSpace(nullptr, &kingRoom, nullptr, nullptr, 2);
    workshop.setStateMessage(1, "You are in the workshop.\nTalk to the workman! You can go east to go see the king.\n");
    workshop.setCurrentStateMessage(1);

    village = PeopleSpace(&castleFront, &hills, &fields, nullptr, 3);
    village.setStateMessage(1, "You are in the village.\nTalk to the locals! The castle lies to the north.\nGrassy fields are to the south and rolling hills to the east.\n");
    village.setCurrentStateMessage(1);

    fields = NatureSpace(&village, nullptr, nullptr, &forest);
    fields.setStateMessage(1, "You are in the fields.\nA huge forest is to the west. The village lies to the north.\nThe path east is blocked by tall grass.\n");
    fields.setStateMessage(2, "You are in the fields.\nA huge forest is to the west. The village lies to the north.\nThe path east is clear.\n");
    fields.setUseItemMessage(1, "The scythe cuts easily through the tall grass. A path opens to the east.\n");
    fields.setUseItemMessage(2, "You've already cut all the grass you need to.\n");
    fields.setInteractMessage(1, "The grass around here is really out of hand. Perhaps a proper tool would help clear a path?\n");
    fields.setInteractMessage(2, "The grass is still pretty tall in places, but at least you can see where you're going now.\n");
    fields.setCurrentStateMessage(1);
    fields.setCurrentItemMessage(1);
    fields.setCurrentInteractMessage(1);
    fields.setValidItem("scythe");
    fields.setDirectionToOpen(2);
    fields.setOpenedSpace(&pigs);

    hills = NatureSpace(&jungle, nullptr, nullptr, &village);
    hills.setStateMessage(1, "You are in the hills.\nYou can see the village to the west and a steamy valley of green to the north.\n");
    hills.setInteractMessage(1, "The hills are rolling and green. Not much else to say.\n");
    hills.setCurrentStateMessage(1);
    hills.setCurrentInteractMessage(1);

    jungle = NatureSpace(nullptr, nullptr, &hills, nullptr);
    jungle.setStateMessage(1, "You are in the jungle.\nYou can see the peaks of the hills to the south.\nThe path north is blocked by dense vines.\n");
    jungle.setStateMessage(2, "You are in the jungle.\nYou can see the peaks of the hills to the south.\nThe path north is clear.\n");
    jungle.setUseItemMessage(1, "The machete cuts through the vines like butter. A path opens to the north.\n");
    jungle.setUseItemMessage(2, "You've already cleared all the foliage in your way.\n");
    jungle.setInteractMessage(1, "The jungle is thick, lush, and green. The vines blocking your way are thick tangle, but perhaps they could be cut?\n");
    jungle.setInteractMessage(2, "The jungle is thick, lush, and green. Only the sounds of birds and insects disturb the silence.\n");
    jungle.setCurrentStateMessage(1);
    jungle.setCurrentItemMessage(1);
    jungle.setCurrentInteractMessage(1);
    jungle.setValidItem("machete");
    jungle.setDirectionToOpen(1);
    jungle.setOpenedSpace(&monkeys);

    forest = NatureSpace(&river, &fields, nullptr, nullptr);
    forest.setStateMessage(1, "You are in the forest.\nYou can see the grasslands of the fields to the east.\nA trail leads north, deeper into the woods.\n");
    forest.setInteractMessage(1, "The trees around you are huge and a thick blanket of pine needles covers the ground.\nYou hears sounds of rushing water to the north.\n");
    forest.setCurrentStateMessage(1);
    forest.setCurrentInteractMessage(1);

    river = NatureSpace(nullptr, nullptr, &forest, nullptr);
    river.setStateMessage(1, "You are at the river.\nDeep forest lies to the south. The path north is blocked by a fast, deep river.\n");
    river.setStateMessage(2, "You are at the river.\nDeep forest lies to the south. The path north is clear.\n");
    river.setUseItemMessage(1, "You fell a few trees so they fall across the river. You may now proceed north.\n");
    river.setUseItemMessage(2, "You don't need to chop down any more trees.\n");
    river.setInteractMessage(1, "The river is fast, and looks deep.\nThere are some tall trees right on the bank. Perhaps they could be of use?\n");
    river.setInteractMessage(2, "The river is fast, and looks deep.\nFortunately, the trees lying across it are strong and stable.\n");
    river.setCurrentStateMessage(1);
    river.setCurrentItemMessage(1);
    river.setCurrentInteractMessage(1);
    river.setValidItem("axe");
    river.setDirectionToOpen(1);
    river.setOpenedSpace(&elephants);

    monkeys = AnimalSpace(nullptr, nullptr, &jungle, nullptr, 2);
    monkeys.setStateMessage(1, "You see a bunch of flying monkeys!\nThe only way open is back into the jungle to the south.\n");
    monkeys.setStateMessage(2, "The monkeys are busily munching bananas.\nThe only way open is back into the jungle to the south.\n");
    monkeys.setStateMessage(3, "You see an empty clearing.\nThe only way open is back into the jungle to the south.\n");
    monkeys.setUseItemMessage(1, "The monkeys swarm around the bananas. They are completely distracted.\n");
    monkeys.setUseItemMessage(2, "Using more bananas will do you no good here.\n");
    monkeys.setCurrentStateMessage(1);
    monkeys.setCurrentItemMessage(1);
    monkeys.setValidItem("bananas");

    elephants = AnimalSpace(nullptr, nullptr, &river, nullptr, 3);
    elephants.setStateMessage(1, "You see a bunch of flying elephants!\nThe only way open is back into the forest to the south.\n");
    elephants.setStateMessage(2, "The elephants are munching on the peanuts you tossed them.\nThe only way open is back into the forest to the south.\n");
    elephants.setStateMessage(3, "You see an empty clearing.\nThe only way open is back into the forest to the south.\n");
    elephants.setUseItemMessage(1, "The elephants swarm around the peanuts. They are completely distracted.\n");
    elephants.setUseItemMessage(2, "Using more peanuts will do you no good here.\n");
    elephants.setCurrentStateMessage(1);
    elephants.setCurrentItemMessage(1);
    elephants.setValidItem("peanuts");

    pigs = AnimalSpace(nullptr, nullptr, nullptr, &fields, 1);
    pigs.setStateMessage(1, "You see a bunch of flying pigs!\nThe only way open is the fields to the west.\n");
    pigs.setStateMessage(2, "The pigs are devouring the corn.\nThe only way open is the fields to the west.\n");
    pigs.setStateMessage(3, "You see an empty clearing.\nThe only way open is the fields to the west.\n");
    pigs.setUseItemMessage(1, "The pigs swarm around the corn. They are completely distracted.\n");
    pigs.setUseItemMessage(2, "Using more corn will do you no good here.\n");
    pigs.setCurrentStateMessage(1);
    pigs.setCurrentItemMessage(1);
    pigs.setValidItem("corn");

    }

/*********************************************************************
* Adventure destructor - no dynamically allocated memory, so not much here
*********************************************************************/
Adventure::~Adventure()
{

}

/*********************************************************************
* Adventure playGame - main game loop here. Lots going on.
* Defines which messages to print when user moves around and interacts or
* uses items. Calls out to animal and people spaces with the interact method
* to perform tasks of getting items and baiting/catching animals. Also has
* calls to move player around spaces, and checks to make sure steps are remaining.
*********************************************************************/
void Adventure::playGame()
{

    int inPlay = 1;
    int userChoice;  // used for a variety of user options

    // Player always starts outside the castle
    currentSpace = &castleFront;

    // welcome user menu, give option to play or quit
    userChoice = adventureMainMenu();
    if (userChoice == 2)
    {
        std::cout << "Goodbye!\n";
        inPlay = 0;
    }

    while (inPlay)
    {
        // each loop starts printing the number of steps remaining and the
        // current State message - what is immediately observed about the space.
        std::cout << "\n********************\n";
        std::cout << "Steps left: " << stepsLeft << "\n\n";
        currentSpace->printCurrentStateMessage();
        std::cout << "********************\n\n";
        userChoice = adventureSpaceMenu(currentSpace->getSpaceType());
        std::cout << "--------------------\n";

        // print out the menu options each round
        if (userChoice == 1)
        {


            // Look Around a nature space
            if (currentSpace->getSpaceType() == 1)
            {
                currentSpace->printCurrentInteractMessage();
            }
            // Talk in a people space
            else if (currentSpace->getSpaceType() == 2)
            {
                // choice variable defined here is used lower down in following else if clauses
                int choice = currentSpace->interact(currentSpace->getSpaceLevel());

                // this defines what happens when you talk to the king, depending on
                // how far through the game you've progressed
                if (currentSpace->getSpaceLevel() == 1)
                {
                    if (netLevel == 0)
                    {
                        currentSpace->setCurrentInteractMessage(1);
                        currentSpace->printCurrentInteractMessage();
                        std::cout << "\nYou got a basic net!\n";
                        netLevel = 1;
                    }
                    else if (netLevel == 1 && pigsCaught == 0)
                    {
                        currentSpace->setCurrentInteractMessage(2);
                        currentSpace->printCurrentInteractMessage();

                    }
                    else if (netLevel == 1 && pigsCaught == 1)
                    {
                        currentSpace->setCurrentInteractMessage(3);
                        currentSpace->printCurrentInteractMessage();
                        std::cout << "\nYou got a drawstring net!\n";
                        netLevel = 2;
                    }
                    else if (netLevel == 2 && monkeysCaught == 0)
                    {
                        currentSpace->setCurrentInteractMessage(4);
                        currentSpace->printCurrentInteractMessage();

                    }
                    else if (netLevel == 2 && monkeysCaught == 1)
                    {
                        currentSpace->setCurrentInteractMessage(5);
                        currentSpace->printCurrentInteractMessage();
                        std::cout << "\nYou got a ginormous net!\n";
                        netLevel = 3;
                    }
                    else if (netLevel == 3 && elephantsCaught == 0)
                    {
                        currentSpace->setCurrentInteractMessage(6);
                        currentSpace->printCurrentInteractMessage();

                    }
                    else if (netLevel == 3 && elephantsCaught == 1)
                    {
                        currentSpace->setCurrentInteractMessage(7);
                        currentSpace->printCurrentInteractMessage();
                        inPlay = 0;
                    }

                }

                // talking to the workman in the workshop - get a tool
                else if (currentSpace->getSpaceLevel() == 2)
                {
                    // add tool to pouch
                    std::cout << "Tool added\n";
                    if (choice == 1)
                    {
                        addToPouch("scythe");
                    }
                    else if (choice == 2)
                    {
                        addToPouch("machete");
                    }
                    else if  (choice == 3)
                    {
                        addToPouch("axe");
                    }
                    else
                    {
                        std::cout << "tool add to pouch error\n";
                    }
                }

                // talking to the people in the village - get a food
                else if (currentSpace->getSpaceLevel() == 3)
                {
                    // add food to pouch
                    std::cout << "Food added\n";
                    if (choice == 1)
                    {
                        addToPouch("corn");
                    }
                    else if (choice == 2)
                    {
                        addToPouch("bananas");
                    }
                    else if  (choice == 3)
                    {
                        addToPouch("peanuts");
                    }
                    else
                    {
                        std::cout << "food add to pouch error\n";
                    }
                }

            }

            // The interact method when in an animal space is called catch
            // Checks to see if the
            else if (currentSpace->getSpaceType() == 3)
            {
                int caught = currentSpace->interact(netLevel);
                // interact with an animal space will attempt to catch the animal
                // if the animal has been baited and the user has the correct net,
                // it will be caught. Otherwise, user will be informed of not caught.

                if (caught)
                {
                    if (currentSpace->getSpaceLevel() == 1)
                    {
                        pigsCaught = 1;
                    }
                    else if (currentSpace->getSpaceLevel() == 2)
                    {
                        monkeysCaught = 1;
                    }
                    else if (currentSpace->getSpaceLevel() == 3)
                    {
                        elephantsCaught = 1;
                    }
                    // set State message to show animals caught
                    currentSpace->setCurrentStateMessage(3);
                    // set the animal caught in it's Space as well
                    // so that appropriate status messages can be printed
                    // if they user tries to catch the animal again
                    static_cast<AnimalSpace*>(currentSpace)->setCaught();

                }
            }
        }

        // using an item in any space
        else if (userChoice == 2)
        {
            // if they have no items, let user know
            if (pouch[0] == "empty" && pouch[1] == "empty")
            {
                std::cout << "You have no items.\n";
            }

            // otherwise, use an item
            else
            {
                std::string item0Str = pouch[0];
                std::string item1Str = pouch[1];

                // a menu us called to list the items and get user's selection
                std::string itemUsed = useItemMenu(item0Str, item1Str);

                // if the item being used isn't for the current space, nothing happens
                if (itemUsed != currentSpace->getValidItem())
                {
                    std::cout << "Nothing happened.\n";
                }

                // if it is the correct item for the space:
                else if (itemUsed == currentSpace->getValidItem() && currentSpace->getCurrentItemMessage() == 1)
                {
                    // if the correct item is used and has not been used before:
                    // print the message saying what the item use has done
                    currentSpace->printCurrentItemMessage();
                    // update item message to the one that shows it has already been used
                    currentSpace->setCurrentItemMessage(2);
                    // update the state message to the one that shows it has already been used
                    currentSpace->setCurrentStateMessage(2);
                    // update the interact message to the one that shows it has been used
                    currentSpace->setCurrentInteractMessage(2);

                    // if the item opened a new space, update the space pointer to allow movement
                    if (currentSpace->getDirectionToOpen() > 0)
                    {
                        currentSpace->setDirectionPtr(currentSpace->getDirectionToOpen(), currentSpace->getOpenedSpace());
                    }

                    // if the item baited an animal, mark that animal as baited
                    if (currentSpace->getSpaceType() == 3)
                    {

                        static_cast<AnimalSpace*>(currentSpace)->setBaited();
                    }
                }
                else
                {
                    // if the bait has already been used, print the message that says so
                    currentSpace->printCurrentItemMessage();
                }
            }
        }
        else if (userChoice == 3)
        {
            // move north
            if (moveSpace(1))
            {
                std::cout << "You moved north.\n";
            }
        }
        else if (userChoice == 4)
        {
            // move east
            if (moveSpace(2))
            {
                std::cout << "You moved east.\n";
            }
        }
        else if (userChoice == 5)
        {
            // move south
            if (moveSpace(3))
            {
                std::cout << "You moved south.\n";
            }
        }
        else if (userChoice == 6)
        {
            // move west
            if (moveSpace(4))
            {
                std::cout << "You moved west.\n";
            }
        }
        else if (userChoice == 7)
        {
            // quit game
            inPlay = 0;
            std::cout << "Goodbye!\n";
        }
        std::cout << "--------------------\n";

        // user runs out of steps, game over.
        if (stepsLeft == 0)
        {
            std::cout << "Time's up! The villagers storm the castle and kill the king.\n"
                      << "You have failed in your mission.\n";
            inPlay = 0;
        }
    }
}

/*********************************************************************
* Adventure moveSpace - looks at the pointers the currentSpace has, either
* moves to the space of the user's choosing or informs them that that
* direction is not available.
*********************************************************************/
int Adventure::moveSpace(int direction)
{
    nextSpace = currentSpace->getDirectionPtr(direction);
    // if move an invalid direction, let user know, otherwise move that direction
    if (nextSpace == nullptr)
    {
        std::cout << "You can't move that direction.\n";
        return 0;
    }
    else
    {
        currentSpace = nextSpace;
        stepsLeft--;
        return 1;
    }
}

/*********************************************************************
* Adventure addToPouch - adds a new item to the front of the pouch,
* scoots an item from index 0 to index 1, drops whatever is in index 1
*********************************************************************/
void Adventure::addToPouch(std::string itemIn)
{
    pouch[1] = pouch[0];
    pouch[0] = itemIn;
}
