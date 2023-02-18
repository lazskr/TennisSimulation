#ifndef AUTOS_H
#define AUTOS_H
#include <string>
#include "Simulation.h"


class autonomousSimulation : public Simulation {
private:

       //tournament which the players will be playing in
       std::string tournament; 

       int num_sets; //number of sets which will need to be played in the tournament 
       int sets2_win; 
       int games; //player's who reach 6 games first will win the set (with the exception of 5-5, 6-5 where the first two 7 will win
       //if the score is 6-6, there will be a tiebreak

       //The probability of the players winning a point (this is represented by the total points won on the ATP tour offical website)
       double probability1; 
       double probability2;

       std::string first_server; //first server of the match
       std::string cur_server; //current server of the match 


       //these variables will be used for the run_sim() function - returns who won more often 
       double num_sims;  //user input 
       double p1_wins = 0; 
       double p2_wins = 0; 
       std::string avg_winner; 

       //these variables will determine which set was most played in the simulation 
       int sets_played; //set played during match 
       int two_set = 0; 
       int three_set = 0;
       int four_set = 0;
       int five_set = 0; 

       //temp variables

       //player who won the most simulations from run_sim() (if more than 1 match was played)
       std::string winner; 

public:
        
        //if run_sim() simulates >1 matches, the player who won the most matches will be returned
        std::string run_sim_winner(); 

        //determines whether user wants to simulate by a point-by-point basis or the entirety of the matches at once
        void select_run_time(); 

        //after run_sim() is executed, most_sets will calculate how many sets were played for each match simulated and all 
        //values will be printed out in increasing order to the user automatically after run_sim() is called 
        std::string most_sets();         

        //Function which calls x simulations and calculates the average winner 
        double run_sim(); 

        //tiebreak which is played if score becomes 6-6
        //point to win is 7 (in normal tiebreak or ATP masters tournament) or 10 (final set in grandslams)
        std::string tiebreak(int point_to_win);

        //The user decies who will serve first 
        void first_serve();

        //The user selects the tournament that they would like to simulate (Australian Open, US Open, French Open (Roland Garros), Wimbeldon or an ATP masters)
        //Thus, by selecting the tournmanent, the number of sets and games to win per set will be established 
        void select_tournament(); 

        //default constructor
        autonomousSimulation();

        //functions which set the probability as well as returns the final probability for the user to
        void set_probabilty();

        //uses the array_points array to print the results of the recently run simulation
        void print_simulation_results();

        //function called once the tennis match will be simulated
        std::string simulate_singlesMatch(); //for singles match
        
        // //calculating the percentage of points won for the inputted player/s
        void calculate_percent_pointsWon_player1();
        void calculate_percent_pointsWon_player2();

        //returns the percentage of points won for the inputted player/s
        double return_percent_pointsWon_player1();
        double return_percent_pointsWon_player2();

        //deconstructor
        ~autonomousSimulation();

}; 

#endif //UTOS_H