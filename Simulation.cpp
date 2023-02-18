#include "Simulation.h"
#include "Player.h"
#include "Menu.h"
#include <iostream>
#include <string>
using namespace std; 


    //default constructor 
    Simulation::Simulation(){}

    void Simulation::select_run_time(){

    string choice; 
    while(true) {
        cout << "If you want a instantaneous simulation/s please enter I/i." << endl; 
        cout << "If you would like a point-by-point simulation/s please enter P/p." << endl; 
        cin >> choice; 

        if (choice == "I" || choice == "i" || choice == "P" || choice == "p") {
            break; 
        } else {
            system("clear");
            continue; 
        }
    }

    if (choice == "P" || choice == "p") {
        accelerate = false; 
        system("clear");
    } else {
        accelerate = true; //if choice == I or i 
        system("clear");
    }

    }
    
     void Simulation::setting_menu_object(Menu menu) {
         extract = menu; 
     }
    
    //tranfers the array of created players from menu into a new array called athlete in the parent simulation class
    void Simulation::participatingPlayers(Player* the_players_address) {
        Player* temp_array = new Player[2]; 
        temp_array = the_players_address;
        
        athlete = new Player[2]; 
        
        for (int i = 0; i<2; i++){
            athlete[i] = temp_array[i]; 
        }
        
    } 
    
    
    //function which calculates the percentage of points won for player 1
    void Simulation::calculate_percent_pointsWon_player1(){
        percent_pointsWon_player1 = ((num_pointsWon_player1)/(num_point))*100; 
    }
    
    //function which calculates the percentage of points won for player 2
     void Simulation::calculate_percent_pointsWon_player2(){
        percent_pointsWon_player2 = ((num_pointsWon_player2)/(num_point))*100; 
    }
    
    //function which returns the percentage of points won for player 1
    double Simulation::return_percent_pointsWon_player1(){
        return percent_pointsWon_player1; 
    }
    
    //function which returns the percentage of points won for player 2
    double Simulation::return_percent_pointsWon_player2(){
        return percent_pointsWon_player2; 
    }
    
    //deconstructor which deletes athlete array 
    Simulation::~Simulation(){
        delete[] athlete;
        
    }
    
    void Simulation::print_simulation_results(){
        //make it into std vector and reset it after each match

        cout << "The results of the most recent simulation:" << endl; 
        
        for (int i = 0; i<points.size()-1; i++) {
            if (points.at(i) == 50) {
                cout << "Ad" << " : " << points.at(i+1) << endl;
            } else if (points.at(i+1) == 50) {
                cout << points.at(i) << " : " << "Ad" << endl; 
            } else {
                cout << points.at(i) << " : " << points.at(i+1) << endl; 
            }
            i++; 
        }
    
        cout << "" << endl;
        
    }
    
    