#include "Player.h"
#include <string>
#include <iostream>
using namespace std; 


        //default constructor - should never be called
        Player::Player(){}
        
        //set's the player's name
        void Player::setName(){
            
            cout << "Please enter a name for the player:" << endl;
            cin >> playerName; 
            cout << "" << endl; 
        }
        
        
        //returns the player's name
        string Player::getName(){
            
            return playerName; 
            
        }
        
        
        //set's the player's gender 
        void Player::setGender(){
            
            //state of while loop 
            int state = 0; 
            
            //while loop which obtains gender of player
            while (!state) { 
                cout << "Please enter the gender for the player." << endl;
                cout << "'M' for male | 'F' for female" << endl; 
                cin >> playerGender; 
                cout << "" << endl;
            
                if (playerGender != 'M' && playerGender != 'F') {
                    system("clear"); 
                    cout << "Invalid input. The only valid inputs are: M, m, F or f. Try again." << endl; //change this 
                    cout << "" << endl;
                    continue; 
                } else {
                    state = 1; //stops and exits the while loop 
                }
            } 
        
        }
        
        char Player::getGender(){
            return playerGender; 
        }
        
      