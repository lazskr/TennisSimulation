#ifndef SIM_H
#define SIM_H
#include "Player.h"
#include "Menu.h"
#include <vector>


class Simulation{
protected:


        Player* athlete; //keeps an array of players which were created in menu     
        
        //will store all of the points  
        std::vector<int> points; //for autonomous

        //object from menu which will be used to return specific values for simulateMatch()
        Menu extract; //object named extract as it returns the values of functions in Menu 
      
        //Note that player1 will represent team 1 for doubles
        //and player2 will represent team 2 for doubles
        //data members required for storing percentage of points won for both players 
        double percent_pointsWon_player1;
        double percent_pointsWon_player2;
        
        double num_point; //number of points played during match 
        
        //number of points won for both players 
        double num_pointsWon_player1; 
        double num_pointsWon_player2; 
        
        //the random number which will be used to determine which player wins the point 
        double random_num; 

        //acceleration 
        bool accelerate; 


public:    

        //defualt constructor 
        Simulation(); 

        //function which allows user to execute the simulation instantaneously or by a point-by-point basis
        void virtual select_run_time(); 
       
        //uses the array_points array to print the results of the recently run simulation        
        virtual void print_simulation_results(); 
       
        //function which transfers the participating players into the simulation so that they can be 
        //used for the match (i.e. opies the players array from Menu and tranfers each player to athlete array) 
        void participatingPlayers(Player* the_players_address); 
        
        //stores the menu object created in the main function by assigning it to extract
        void setting_menu_object(Menu menu); 

        //functions called once the tennis match will be simulated
        std::string virtual simulate_singlesMatch() = 0; //for singles match
        
        //calculating the percentage of points won for the inputted player/s
        void virtual calculate_percent_pointsWon_player1();
        void virtual calculate_percent_pointsWon_player2();
        
        //returns the percentage of points won for the inputted player/s
        double virtual return_percent_pointsWon_player1(); 
        double virtual return_percent_pointsWon_player2();
        
        //deconstructor for athletes array 
        virtual ~Simulation(); 
};

#endif //SIM_H