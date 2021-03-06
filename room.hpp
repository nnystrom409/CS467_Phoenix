#ifndef ROOM_HPP
#define ROOM_HPP


#include <string>
#include <stack>
#include <vector>
#include "utilities.hpp"
#include "engine.hpp"


#define MAX_RM_CONNECTIONS 7

class Doorway 
{
	private:
		std::string displayName;
		std::string goesTo;
		std::vector<std::string> keyWords;
		std::string strToLowercase(std::string);
		bool doorLocked;

  public:
		Doorway(); // constructor
		~Doorway(); // destructor
		void setDoorway(std::string);  // Parses string and sets the correct values.
		std::string getDisplayName();
		std::string getExitRoomName();
		bool isExitKeywordFound(std::string); // looks in keywords to see if found. returns true if so, false otherwise.
		std::string Examine();
		void lockDoor();
		void unlockDoor();
		bool isDoorLocked();

};

class Room
{
	private:
		bool roomSeen;
		std::string key;
		std::string roomName;
		std::string longDesc;
		std::string shortDesc;
		std::string additionalDesc;
		std::string blockedText;
		std::string unlockText;
		int numExits;
		Doorway * Connections[MAX_RM_CONNECTIONS]; 	// Exits from the room
		std::string strToLowercase(std::string);


	public:
	 	// IRL these would be private with iterator and get/set functions. TODO
		std::string dependsOn;
		std::vector<std::string> roomFeatures;
		std::vector<Feature *> features;
		
		Room(std::string, std::string, std::stack<lockDoorStruct> &);
		//Room(std::string, std::string, std::stack<lockDoorStruct> &); 									// constructor
		~Room();													// destructor


		std::string getRoomName();							// returns name of this room.
		std::string getLongDesc();							// returns the long description of this room.
		std::string getShortDesc();						// returns the short description of this room.
		std::string getAdditionalDesc();					// returns the additional description of this room.
		std::string getKeyName();						// return the 'canonical' name of the room
		std::string getUnlockText();
		std::string getBlockedText();
		void getRoomHint();
		void setKeyName(std::string);
		void setRoomSeen();
		bool getRoomSeen();
		void Examine(GameState *);
		void addExitsToStack(std::stack<std::string> &);	// Adds Room's exits to the given stack - used in House::buildHouse -- should not be needed anywhere else
		std::string getExitRoomByKey(std::string, bool);			// searches exits by keyword (such as south) and if found, returns the room name. If not found, returns null.
		std::string getExitsForDisplay(GameState *);
		bool lockExitDoorByKey(std::string);			// will lock the door to one of the rooms based on a doorway keyword.
		bool unlockExitDoorByKey(std::string);
		bool isExitDoorLockedByKey(std::string);
		void displayRoom();
		Room * goRoom(std::string, GameState *);
		Room * getRoomOtherSideOfDoor(std::string, GameState *);
		std::vector<std::string> getFeaturesVector();
		Feature * getFeaturePtr(std::string, GameState *); // returns the pointer if feature is in the room
		void deleteFeature(std::string);
		void addFeature(std::string, GameState *); // byName ?
		bool isFeatureInThisRoom(std::string);
		Feature * findFeatureByUnlocksString(std::string, GameState *);
		std::string getLockedDoorsSaveString();
		void unlockAllDoorsInThisRoom();  // used for loading saved game.
		void deleteAllFeaturesInThisRoom(); // used for loading saved game.

};



#endif
