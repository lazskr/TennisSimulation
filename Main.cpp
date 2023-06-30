using namespace std;
#include <iostream>
#include <string>
#include "Menu.h"
#include "interactiveSimulation.h"
#include "autonomousSimulation.h"
#include "Simulation.h"

//g++ -std=c++11 Player.cpp Menu.cpp Simulation.cpp interactiveSimulation.cpp autonomousSimulation.cpp main.cpp -o execute

int main(){

   string run_program; //determines if user will continue with another simulation or exit the program
   int state_of_game = 0; //determines state of while loop
   Menu main_menu; //creating an object called main_menu from the Menu class

 while (!state_of_game) {
    system("clear");

    main_menu.Instructions(); //calls for instructions on simulation

    if (main_menu.return_user_choice() == 'E' || main_menu.return_user_choice() == 'e') {
        break; 
    }


  if (main_menu.return_user_choice() == 'I' || main_menu.return_user_choice() == 'i') {
      main_menu.createPlayers();

      interactiveSimulation intMatch; //creating one objects from the derived class //FIX INTERACTIVE TO RETURN A STRING
      Simulation* selectedSim = &intMatch; //having a pointer of the parent class point to the addresses of the derived class

      selectedSim->setting_menu_object(main_menu); //sending menu object to simulation parent class so that data members can be accessed from the menu class

      Player* temp_array = main_menu.return_players_address(); //sending array of players to the simulation parent class
      selectedSim->participatingPlayers(temp_array);

      intMatch.match_parameters();

      intMatch.set_playingHand();
      intMatch.setAge();
      intMatch.setHeight();
      intMatch.setPower();
      intMatch.setSpeed(); 

      intMatch.select_run_time();

      selectedSim->simulate_singlesMatch();

      selectedSim->calculate_percent_pointsWon_player1();
      cout << temp_array[0].getName() << " won " << selectedSim->return_percent_pointsWon_player1() << " percent of their points." << endl;
      cout << "" << endl;

      selectedSim->calculate_percent_pointsWon_player2();
      cout << temp_array[1].getName() << " won " << selectedSim->return_percent_pointsWon_player2() << " percent of their points." << endl;
      cout << "" << endl;

      //returns the results (points) of the simulation for user analysis
      selectedSim->print_simulation_results();

      cout << "" << endl;
      cout << "Would you like to end the program or be brought to the main menu again?" << endl;
      cout << "If you would like to exit enter E/e, otherwise enter any other character or word to continue." << endl;
      cin >> run_program;
      if (run_program == "E" || run_program == "e") {
          system("clear");
          state_of_game = 1;
      } 
      

  } else {

      main_menu.createPlayers();

      autonomousSimulation autoSim;
      Simulation* selectedSim = &autoSim;

      selectedSim->setting_menu_object(main_menu);

      Player* temp_array = main_menu.return_players_address();
      selectedSim->participatingPlayers(temp_array);

      autoSim.select_tournament();

      autoSim.first_serve(); 

      autoSim.set_probabilty(); //sets the player's probability of winning a point

      autoSim.select_run_time();

      double result = autoSim.run_sim(); 

      if (result == -1.00) {
        selectedSim->calculate_percent_pointsWon_player1();
        cout << temp_array[0].getName() << " won " << selectedSim->return_percent_pointsWon_player1() << " percent of the points." << endl;
        cout << "" << endl;

        selectedSim->calculate_percent_pointsWon_player2();
        cout << temp_array[1].getName() << " won " << selectedSim->return_percent_pointsWon_player2() << " percent of the points." << endl;
        cout << "" << endl;
        
        selectedSim->print_simulation_results();
      } else {
        system("clear"); 
        string winner = autoSim.run_sim_winner(); 
        cout << winner << " has won the most matches overall winning " << result*100 << "%" << " of the matches." << endl;
        cout << winner << " won most matches in " << autoSim.most_sets() << endl; 
      }

      cout << "Would you like to end the program or be brought to the main menu again?" << endl;
      cout << "If you would like to exit enter E/e, otherwise enter any other character or word to continue" << endl;
      cin >> run_program;
      if (run_program == "E" || run_program == "e") {
        system("clear");
        state_of_game = 1;  
      } 
           
  }

 }
    return 0;
 }
