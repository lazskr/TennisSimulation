#ifndef MENU_H
#define MENU_H
#include "Player.h"

class Menu {
public:

       //Player pointer pointing to object called players
       Player* players; 
       
       //keeps the user choice which will determine if and which simulation will run or if the program will be executed
       char user_choice; 
       
        
public:

        //will later add instructions, start and exit functions -> 3 more functions needed at minimum 
        
        
        //default deconstructor 
        Menu(); 
        
        void Instructions(); 

        //determines establishes the player/s name and gender (asks user to input)
        void createPlayers(); 
        
        //returns the address of the players data member
        Player* return_players_address();

        //function which returns the user choice
        char return_user_choice(); 

        //deconstructor 
        ~Menu(); 
    
};

#endif //MENU_H