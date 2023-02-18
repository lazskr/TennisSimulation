#include "interactiveSimulation.h"
#include "Simulation.h"
#include "Menu.h"
#include "Player.h"
using namespace std;
#include <stdio.h> //for null
#include <stdlib.h> //for the random number
#include <time.h>  //for the time function used to generate a random seed for the rand() function
#include <iostream>
#include <string>


//default constructor
interactiveSimulation::interactiveSimulation(){}

//user decides the number of sets and the number of games to win 
    void interactiveSimulation::match_parameters(){

        //resets the points2 vector which will hold the points for this simulation 
        points.clear();

        user_sets = -1; //for the while loop to be entered
        while (!(user_sets%2 != 0 && user_sets > 0)) { //user sets must be positive and odd 
            cout << "What is the number of sets that the player's must reach to win?" << endl;
            cin >> user_sets; 
        } 

        user_games_to_win = -1; //for while loop to be entered
        while (user_games_to_win <= 0) {
            cout << "What is the number of games that a player must reach to win the set?" << endl; 
            cin >> user_games_to_win; 
        }


    }

    void interactiveSimulation::setAge() {
        
        
        int state_prob = 0;
            while (!state_prob) {
                cout << "What is the age of " << athlete[0].getName() << "?" << endl;
                cout << "The age must not be a negative number." << endl;
                cin >> playerAge;
            
            if (playerAge > 0) {
                    state_prob = 1; 
            }
            
        } 

        if (playerAge < 26) {
            permenant_effect += 0.1;
        } else if (playerAge >= 26 && playerAge < 30) {
            permenant_effect += 0.05;
        } else {
            permenant_effect -= 0.05;
        }

        
      cout << endl; 
      system("clear");
    }


    void interactiveSimulation::set_playingHand() {
        system("clear");
        int state_prob = 0;
            while (!state_prob) {
                cout << "What is " << athlete[0].getName() << "'s playing hand?" << endl;
                cout << "Please enter L/l for left hand, R/r for right hand or A/a for ambidextrous." << endl;
                cin >> playerHand;
            
                if (playerHand == "R" || playerHand == "r" || playerHand == "L" || playerHand == "l" || playerHand == "A" || playerHand == "a") {
                    state_prob = 1; 
                }
            } 

        if (playerHand == "L" || playerHand == "l" || playerHand == "A" || playerHand == "a") {
            permenant_effect += 0.15;
        }

      cout << endl; 
      system("clear");


    }


    void interactiveSimulation::setSpeed() {

        int state_prob = 0;
            while (!state_prob) {
                cout << "What is the average serving speed of " << athlete[0].getName() << " in km/h?" << endl;
                cout << "The average serving speed cannot be less than 0." << endl;
                cin >> playerSpeed;
        
                if (playerSpeed > 0) {
                    state_prob = 1; 
                }
        
            }

        if (playerSpeed > 180) {
            permenant_effect += 0.05;
        } else if (playerSpeed > 130 && playerSpeed <= 180) {
            permenant_effect += 0.025;
        } else {
            permenant_effect -= 0.01;
        }

        cout << endl; 
        system("clear");

    }


    void interactiveSimulation::setHeight() {

        int state_prob = 0;
            while (!state_prob) {
                cout << "What is the height of " << athlete[0].getName() << " in cm?" << endl;
                cout << "The height of the player cannot be less than 0." << endl;
                cin >> playerHeight;
                
                if (playerHeight > 0) {
                    state_prob = 1;
                }    
            } 
                    
                    
        if (playerHeight >= 183) {
            permenant_effect += 0.05;
        } else if (playerHeight >= 160 && playerHeight < 180) {
            permenant_effect += 0.025;
        } else {
            permenant_effect -= 0.015;
        }
        
        cout << endl; 
      system("clear");

    }

    void interactiveSimulation::setPower(){

    int state_prob = 0;
            while (!state_prob) {
                cout << "What is the hitting power of " << athlete[0].getName() << "?" << endl;
                cout << "The hitting power must be between 0 and 10 where 0 is extremely weak and 10 is extremely strong." << endl;
                cin >> playerPower; 
                
                if (playerPower >= 0 && playerPower <= 10) {
                    state_prob = 1; 
                }
            } 
        
      if (playerPower >= 8) {
          permenant_effect += 0.05;
      } else if (playerPower >= 6 && playerPower < 8) {
          permenant_effect += 0.025;
      } else {
          permenant_effect -= 0.015;
      }
        
        cout << endl; 
      system("clear");

    }


 //simulation of the singles match
    string interactiveSimulation::simulate_singlesMatch(){

        system("clear");

        //setting the state for the while loop
        int state = 0;

        //sets won for the player and opponent
        //player is represented by player 1
        //opponent is represented by player 2
        int player_sets = 0;
        int opponent_sets = 0;

        //games won for the player and opponent
        int player_games = 0;
        int opponent_games = 0;

        //current points (0, 15, 30, 40, advantage) for the player and opponent
        //may add advantage in final version
        int player_point = 0;
        int opponent_point = 0;

        points.push_back(player_point);
        points.push_back(opponent_point);

        cout << "The interactive simulation for the singles match will now begin." << endl;
        cout << "" << endl;

        while (!state) {

            srand (time(NULL)); //The time(NULL) parameter will provide a seed based on the time on the computer.
            random_num = rand()%101; //using the seed, a random number is generated between 0 and 100
            random_num /= 100; //random number is now between 0 and 1

            int state_prob = 0; //for while loop below

            while (!state_prob) {
            cout << "What is the probability of " << athlete[0].getName() << " winning this point? (between 0 and 1 inclusive)" << endl;
            cin >> probability;

            if (probability < 0 || probability > 1) {
                cout << "invalid probability. Valid inputs are between 0 and 1 inclusive. Try again" << endl;
                continue;
            } else {
                system("clear");
                probability += permenant_effect; //adding the attributes effect onto the probability of winning a point 
                state_prob = 1;
            }
          }

            //provides the user oppurtunity to increase or decrease player 1's probability of winning a point 
            if (random_num >= 0 && random_num < 0.20) {
                cout << "Does " << athlete[0].getName() << " want a drink of cool water (Y/y for yes | any other input for no)?" << endl;
                cout << "some replenishment could help with the next point..." << endl;
                cin >> answer;
                system("clear");
                
                if (answer == "Y" || answer == "y") {
                    probability += 0.015; 
                } else {probability -= 0.015;}
                
            } else if (random_num >= 0.20 && random_num < 0.40) {
                cout << "Does " << athlete[0].getName() << " want to swap for a new racquet? (Y/y for yes | any other input for no)" << endl; 
                cout << "some new strings might help with the power of the swing..." << endl; 
                cin >> answer;
                system("clear");
                
                if (answer == "Y" || answer == "y") {
                    probability += 0.015; 
                } else {probability -= 0.015;} 
                
            } else if (random_num >= 0.40 && random_num < 0.60) {
                cout << "Does " << athlete[0].getName() << " want a medical timeout? (Y/y for yes | any other input for no)" << endl; 
                cout << "Making sure the body is better functioning for the next point could be crucial..." << endl; 
                cin >> answer;
                system("clear");
                
                if (answer == "Y" || answer == "y") {
                    probability += 0.015; 
                } else {probability -= 0.015;}
                
            } else if (random_num >= 0.60 && random_num < 0.80) {
                cout << "Dpes " << athlete[0].getName() << " need to quickly devise a new way to win the next point? (Y/y for yes | any other input for no)" << endl; 
                cout << "planning correctly could be the way towards success..." << endl; 
                cin >> answer;
                system("clear");
                
                if (answer == "Y" || answer == "y") {
                    probability += 0.015; 
                } else {probability -= 0.015;}
                
            } else if (random_num >= 0.80 && random_num <= 1) {
                cout << "Does " << athlete[0].getName() << " need a quick chat with the coach? (Y/y for yes | any other input for no)" << endl; 
                cout << "Maybe some quick advice will help with the next point ..." << endl; 
                cin >> answer;
                system("clear");
                
                if (answer == "Y" || answer == "y") {
                    probability += 0.015; 
                } else {probability -= 0.015;} 
    
            } else {
                cout << "" << endl;   
            }
            
            //if probability > 1 or < 0, it is reset to the closest edge values (0 or 1)
            if (probability > 1) {
                probability  = 1; 
            } else if (probability  < 0) {
                probability  = 0; 
            } else {
                cout << "" << endl; 
            }
            
            

            if (random_num <= probability) { //player
                num_point++;
                num_pointsWon_player1++;

                if (player_point == 0) {
                    player_point = 15;

                    points.push_back(player_point);
                    points.push_back(opponent_point);

                    cout << athlete[0].getName() << " won the point!" << endl;
                    cout << "" << endl;
                    cout << athlete[0].getName() << ": " << player_point << endl;
                    cout << athlete[1].getName()  << ": " << opponent_point << endl;
                    cout << "" << endl;
                    continue;

                } else if (player_point == 15) {
                    player_point = 30;

                    points.push_back(player_point);
                    points.push_back(opponent_point);

                    cout << athlete[0].getName() << " won the point!" << endl;
                    cout << "" << endl;
                    cout << athlete[0].getName()  << ": " << player_point << endl;
                    cout << athlete[1].getName()  << ": " << opponent_point << endl;
                    cout << "" << endl;
                    continue;

                } else if (player_point == 30) {
                    player_point = 40;

                    points.push_back(player_point);
                    points.push_back(opponent_point);

                    cout << athlete[0].getName() << " won the point!" << endl;
                    cout << "" << endl;
                    cout << athlete[0].getName()  << ": " << player_point << endl;
                    cout << athlete[1].getName()  << ": " << opponent_point << endl;
                    cout << "" << endl;
                    continue;

                } else { //player_point == 40

                    player_games++;
                    player_point = 0;
                    opponent_point = 0;

                    if (player_sets != user_sets) {
                        points.push_back(player_point);
                        points.push_back(opponent_point);
                    }

                    //check if the set is won and then determines if the match is over (exits the loop)
                    if (player_games == user_games_to_win) { //if the player gets 3 games, that means a set has been won
                        player_sets++;

                        if (player_sets == user_sets) {
                            system("clear");
                            num_pointsWon_player2 = num_point - num_pointsWon_player1; //calculates the number of points won by player2
                            cout << "" << endl;
                            cout << "Game, set, match " << athlete[0].getName() << " wins!" << endl;
                            return "p1"; 
                            state = 1;
                        } else {
                            player_games = 0;
                            opponent_games = 0;
                            player_point = 0;
                            opponent_point = 0;
                            cout << "A new set will now begin." << endl;
                            continue;
                        }
                    }

                    if (player_sets != user_sets) {
                        if (player_games > opponent_games) {
                            cout << "Game." << endl;
                            cout << athlete[0].getName() << " leads with " << player_games << " games to " << opponent_games << endl;
                            continue;
                    } else if (player_games < opponent_games) {
                            cout << "Game." << endl;
                            cout << athlete[1].getName() << " leads with " << opponent_games << " games to " << player_games << endl;
                            continue;
                    } else {
                            cout << "Game." << endl;
                            cout << "The set is tied at " << player_games << " -all" << endl;
                            continue;
                    }

                  }
                }


            } else { //opponent wins the point

                num_point++;

                if (opponent_point == 0) {
                    opponent_point = 15;

                    points.push_back(player_point);
                    points.push_back(opponent_point);

                    cout << athlete[1].getName() << " won the point!" << endl;
                    cout << "" << endl;
                    cout << athlete[0].getName()  << ": " << player_point << endl;
                    cout << athlete[1].getName()  << ": " << opponent_point << endl;
                    cout << "" << endl;
                    continue;

                } else if (opponent_point == 15) {
                    opponent_point = 30;

                    points.push_back(player_point);
                    points.push_back(opponent_point);

                    cout << athlete[1].getName() << " won the point!" << endl;
                    cout << "" << endl;
                    cout << athlete[0].getName()  << ": " << player_point << endl;
                    cout << athlete[1].getName()  << ": " << opponent_point << endl;
                    cout << "" << endl;
                    continue;

                } else if (opponent_point == 30) {
                    opponent_point = 40;

                    points.push_back(player_point);
                    points.push_back(opponent_point);

                    cout << athlete[1].getName() << " won the point!" << endl;
                    cout << "" << endl;
                    cout << athlete[0].getName()  << ": " << player_point << endl;
                    cout << athlete[1].getName()  << ": " << opponent_point << endl;
                    cout << "" << endl;
                    continue;

                } else { //player_point == 40

                    opponent_games++;
                    player_point = 0;
                    opponent_point = 0;

                    if (opponent_sets != user_sets) {
                        points.push_back(player_point);
                        points.push_back(opponent_point);
                    }

                    //check if the set is won and then determines if the match is over (exits the loop)
                    if (opponent_games == user_games_to_win) { //if the player gets 3 games, that means a set has been won
                        opponent_sets++;

                        if (opponent_sets == user_sets) {
                            system("clear");
                            num_pointsWon_player2 = num_point - num_pointsWon_player1; //calculates the number of points won by player2
                            cout << "" << endl;
                            cout << "Game, set,  " << athlete[1].getName() << " wins!" << endl;
                            return "p2"; 
                            state = 1;
                        }

                        player_games = 0;
                        opponent_games = 0;
                        player_point = 0;
                        opponent_point = 0;
                        cout << "A new set will now begin." << endl;
                        continue;
                    }

                if (opponent_sets != user_sets) {
                    if (player_games > opponent_games) {
                            cout << "Game." << endl;
                            cout << athlete[0].getName() << " leads with " << player_games << " games to " << opponent_games << endl;
                            continue;
                    } else if (player_games < opponent_games) {
                            cout << "Game." << endl;
                            cout << athlete[1].getName() << " leads with " << opponent_games << " games to " << player_games << endl;
                            continue;
                    } else {
                            cout << "Game." << endl;
                            cout << "The set is tied at " << player_games << " -all" << endl;
                            continue;
                    }


                  }

                }


            }  //if statement end

        } // while loop end

        return "end";

    } //function end


    void interactiveSimulation::calculate_percent_pointsWon_player1(){
        Simulation::calculate_percent_pointsWon_player1();
    }

    void interactiveSimulation::calculate_percent_pointsWon_player2(){
        Simulation::calculate_percent_pointsWon_player2();
    }

    double interactiveSimulation::return_percent_pointsWon_player1(){
        double percentage = Simulation::return_percent_pointsWon_player1();
        return percentage;
    }

    double interactiveSimulation::return_percent_pointsWon_player2(){
        double percentage = Simulation::return_percent_pointsWon_player2();
        return percentage;
    }

    void interactiveSimulation::print_simulation_results(){
        Simulation::print_simulation_results();
    }
    
    void interactiveSimulation::select_run_time(){
        Simulation::select_run_time(); 
    }


    interactiveSimulation::~interactiveSimulation(){}