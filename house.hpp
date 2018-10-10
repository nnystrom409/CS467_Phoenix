#ifndef HOUSE_HPP
#define HOUSE_HPP

#include <string>
#include <stack>
#include <vector>
#include "room.hpp"

class House
{
	private:
		std::map<std::string,Room *> houseMap;   // this is a map of the house... room is key, holds the room pointer

	public:
		House(); // constructor
		~House();	// destructor
		Room *buildHouse(std::string);		// Takes starting Room, Builds House, then returns the ptr of the starting room
		bool hasRoom(std::string);   			// Returns true if room ("Foyer" for instance) is found in the houseMap
		Room *getRoomPtr(std::string);      // Retruns the ptr of the Room object for the requested room.
		bool printRooms();						// For debugging really
};

#endif