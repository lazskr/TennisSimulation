#include "Menu.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std; 

    //default constructor 
    Menu::Menu(){}
    
    void Menu::Instructions(){
    
        cout << "Hi, Welcome to the Tennis Simulation. There are two types of simulation that you can do." << endl;
        
        cout << "" << endl; 

        cout << "The first is an interactive simulation. This tennis simulation only offers a simulation for a singles match" << endl; 
        cout << "You will have the choice for the number of sets which will be played and the number of games which must." << endl; 
        cout << "be won in order to win a set. There are no tiebreaks and  no Ad's on points. This interactive s-" << endl; 
        cout << "-imulation will act as an RPG where you as the user will customize your player based on the attributes of" << endl; 
        cout << "playing speed, hand, power, age and the height of player where your choices will have either positive or negative" << endl;
        cout << "consequences on your player's probability of winning each point. Additionally, at the begining of each point, " << endl; 
        cout << "you will be prompted with decisions to make regarding your player that could either positively or negatively effect" << endl; 
        cout << "them winning the point so make sure to choose wisely. This simulation will require you to input the probability" << endl; 
        cout << "that your player will win the point for each point throughout the sets" << endl; 

        cout << "" << endl; 
        
        cout << "The second simulation is an autonomous simulation. This tennis simulation only offers a simulation for a singles match" << endl; 
        cout << "The tennis match will be played in either a grand slam or ATP masters format (best of 3 or 5 sets). There are tiebreaks" << endl; 
        cout << "included and there are Ad's on points during play. This simulation can be ran as many times as you would like in order" << endl;
        cout << "to get an average winner. This Simulation will require you to input the probability of both player's winning the probability" << endl; 
        cout << "only once. This value is also known as the 'total points won' throughout a player's career." << endl; 
        
        cout << "" << endl;    
        user_choice = 'r'; //resets user choice 

    while (user_choice != 'E' && user_choice != 'e' && user_choice != 'A' && user_choice != 'a' && user_choice != 'I' && user_choice != 'i') {    
        cout << "If you would like to exit the program, input 'E' or 'e' and press enter" << endl; 
        cout << "Otherwise, what simulation would you like to run? Enter I/i for interactive and A/a for autonomous" << endl;
        cout << "" << endl; 
        cin >> user_choice; 
        system("clear"); 
    } 
     system("clear");    
        
    }
    
    char Menu::return_user_choice(){
        return user_choice; //E/e or I/i
    }
    
    
    Player* Menu::return_players_address(){
        Player* returning_players = new Player; 
        returning_players = players; 
        return returning_players; 
    }
        

  
    //function which creates an array of players for the singles (called after num_of_players())
    void Menu::createPlayers() {
        players = new Player[2]; 
        
            for (int i = 0; i<2; i++) { //1 for loop for a singles match 
                    players[i].setName(i+1); 
                    players[i].setGender(i+1); 
            }
        
    }
         
    
    //deconstructor which deletes players array after the program ends
    //player array address will be transferred and deleted in simulation deconstructor 
    Menu::~Menu(){}
