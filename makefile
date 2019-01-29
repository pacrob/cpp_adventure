#/*********************************************************************
#** Program name: makefile for Final Project - Adventure
#** Author: Paul Robinson
#** Date: 24-Nov-2017
#** Description: makefile for Final Project - Adventure
#*********************************************************************/


CXX = g++
CXXFLAGS = -std=c++0x
#CXXFLAGS += -g

SRCSA = adventureMain.cpp
SRCSB =	menuChoice.cpp adventureMenu.cpp adventure.cpp
SRCSC = space.cpp animalSpace.cpp natureSpace.cpp peopleSpace.cpp

OBJSA = adventureMain.o
OBJSB = menuChoice.o adventureMenu.o adventure.o
OBJSC = space.o animalSpace.o natureSpace.o peopleSpace.o

#HEADERSA =
HEADERSB = menuChoice.hpp adventureMenu.hpp adventure.hpp
HEADERSC = space.hpp animalSpace.hpp natureSpace.hpp peopleSpace.hpp

EXEC = advent


all: ${OBJSA} ${OBJSB} ${OBJSC} ${HEADERSA} ${HEADERSB} ${HEADERSC}
	${CXX} ${OBJSA} ${OBJSB} ${OBJSC} ${CXXFLAGS} -o ${EXEC}

${OBJSA}: ${SRCSA}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

${OBJSB}: ${SRCSB}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

${OBJSC}: ${SRCSC}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o ${EXEC}

#target: dependencies
#	rule to build
