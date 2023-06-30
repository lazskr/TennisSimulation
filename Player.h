#ifndef PLAYER_H
#define PLAYER_H
#include <string> 

class Player {
private:
        std::string playerName; //holds player name
        char playerGender; //holds player gender 
       
public:

        //default constructor 
        Player(); 
        
        //setter and getter for the player/s name
        void setName(int player_num);
        std::string getName(); 
        
        //setter for the player/s gender
        void setGender(int player_num);
        char getGender(); 
        
  
};

#endif //PLAYER_H