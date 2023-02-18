#ifndef INTS_H
#define INTS_H
#include "Simulation.h"


class interactiveSimulation:public Simulation {
private:
        
        double probability; //probability for the user's player player 
        
        //keeps the answer for the user regarding the player/s feeling and attributes
        std::string answer; 

        //sets the number of sets (odd number) and the number of games the user's tennis player must get to win
        int user_sets; 
        int user_games_to_win; 

        //Player attributes which will be used to alter the
        //probability of winning a point    
        int playerAge;
        std::string playerHand;
        double playerSpeed;
        double playerHeight;
        double playerPower;
        double permenant_effect; 
      
      
public: 

        //default constructor 
        interactiveSimulation(); 

        void select_run_time();

        //5 functions with each function asking the user for the input about a statistic pertaining to the player/s
        void setAge(); 
        void set_playingHand(); 
        void setSpeed(); 
        void setHeight();
        void setPower();

        //determining the number of sets (which must be odd) and how many games to win the set 
        void match_parameters(); 
        
        //uses the array_points array to print the results of the recently run simulation        
        void print_simulation_results();
        
        //functions called once the tennis match will be simulated
        std::string simulate_singlesMatch(); //for singles match
        
        // //calculating the percentage of points won for the inputted player/s
        void calculate_percent_pointsWon_player1();
        void calculate_percent_pointsWon_player2();
        
        //returns the percentage of points won for the inputted player/s
        double return_percent_pointsWon_player1(); 
        double return_percent_pointsWon_player2();
        
        ~interactiveSimulation(); 
};

#endif //INTS_H