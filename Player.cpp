#include "Player.h"
#include <string>
#include <iostream>
using namespace std; 


        //default constructor - should never be called
        Player::Player(){}
        
        //set's the player's name
        void Player::setName(int player_num){
            system("clear");
            cout << "Please enter a name for player " + to_string(player_num) + ": " << endl;
            cin >> playerName; 
            cout << "" << endl; 
        }
        
        
        //returns the player's name
        string Player::getName(){
            
            return playerName; 
            
        }
        
        
        //set's the player's gender 
        void Player::setGender(int player_num){
            
            //state of while loop 
            int state = 0; 
            
            //while loop which obtains gender of player
            while (!state) { 
                cout << "Please enter the gender for player " + to_string(player_num) + ": " << endl;
                cout << "'M' for male | 'F' for female" << endl; 
                cin >> playerGender; 
                cout << "" << endl;
            
                if (playerGender != 'M' && playerGender != 'F') {
                    system("clear"); 
                    cout << "Invalid input. The only valid inputs are: M, m, F or f. Try again." << endl; //change this 
                    cout << "" << endl;
                    continue; 
                } else {
                    system("clear"); 
                    state = 1; //stops and exits the while loop 
                }
            } 
        
        }
        
        char Player::getGender(){
            return playerGender; 
        }
        
      