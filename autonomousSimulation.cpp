#include <iostream>
using namespace std; 
#include "Simulation.h"
#include "Menu.h"
#include "Player.h"
#include "autonomousSimulation.h"
#include <stdio.h> //for null
#include <stdlib.h> //for the random number
#include <time.h>  //for the time function used to generate a random seed for the rand() function
#include <string>
#include <vector>
#include <unistd.h> //for sleep


    //default constructor
    autonomousSimulation::autonomousSimulation(){}

    string autonomousSimulation::run_sim_winner(){
        return avg_winner; 
    }

    string autonomousSimulation::most_sets() {

        std::vector<int> sorted_sets; 
        sorted_sets.push_back(two_set);
        sorted_sets.push_back(three_set);
        sorted_sets.push_back(four_set);
        sorted_sets.push_back(five_set);

        int size = sorted_sets.size();
       
        //bubble sort algorithm (increasing) with time compelxity n^2
        int i, j; 
        for (i = 0; i<size-1; i++) {
            for  (j = 0; j<size-i-1; j++) {
                if (sorted_sets.at(j) > sorted_sets.at(j+1)) {
                   swap(sorted_sets.at(j), sorted_sets.at(j+1));
                }
            }
        }

        if (sorted_sets.at(3) == two_set) {
            return "2 sets";
        } else if (sorted_sets.at(3) == three_set) {
            return "3 sets";
        } else if (sorted_sets.at(3) == four_set) {
            return "4 sets";
        } else {
            return "5 sets";
        }

    }

    double autonomousSimulation::run_sim() {

        points.clear(); //clears the vector which holds the points
        
        //resets all variables involved in this function if it is called again by the user 
        p1_wins = 0;
        p2_wins = 0; 
        two_set = 0;
        three_set = 0;
        four_set = 0; 
        five_set = 0; 


        while (true) {
            cout << "How many times would you like the simulation to run?" << endl; 
            cout << "This value must be a positive integer number greater than 0." << endl; 
            cin >> num_sims; 

            if (num_sims <= 0) {
                system("clear"); 
                continue; 
            } else {
                break; 
                system("clear"); 
            }
        }


        if (num_sims == 1) {
            simulate_singlesMatch(); 
            return -1.00; 
        }


        string result; 
        for (int i = 0; i<num_sims; i++) {
            result = simulate_singlesMatch(); 
            if (result == "p1") {
                p1_wins++; 
            } else {
                p2_wins++;
            }
        }


        if (p1_wins > p2_wins) {
            avg_winner = athlete[0].getName();
            return (p1_wins/num_sims);
        } else if (p2_wins > p1_wins) {
            avg_winner = athlete[1].getName();
            return (p2_wins/num_sims);
        } else { //p2_wins = p1_wins
            avg_winner = "Neither";
            return 0.5; //p1 and p2 won an equal number of matches 
        }

    }

    string autonomousSimulation::tiebreak(int point_to_win) {
    
    cout << "A tiebreak will now begin." << endl; 

        int p1_points = 0;
        int p2_points = 0; 
        string server = cur_server; 

        points.push_back(p1_points);
        points.push_back(p2_points);
       
        cout << athlete[0].getName() << " : " << p1_points << " ";  
        cout << athlete[1].getName() << " : " << p2_points; 
        cout << "" << endl; 

    int random_num2;
    while (!(p1_points == point_to_win-1 && p2_points == point_to_win-1)) {
        srand (time(NULL)); 
        random_num2 = rand()%101; 
        random_num2 /= 100; 

        //first server gets only 1 serve at the begining of tiebreak
        if (p1_points == 0 && p2_points == 0) {
            if (server == athlete[0].getName()) {
                server = athlete[1].getName(); //server changing after first point 
                if (probability1 <= random_num2) {
                    p1_points++;
                } else {
                    p2_points++;
                }
            } else {
                server = athlete[0].getName();
                if (probability2 <= random_num2){
                    p2_points++;
                } else {
                    p1_points++; 
                }
            }

            points.push_back(p1_points);
            points.push_back(p2_points);

            cout << athlete[0].getName() << " : " << p1_points << " ";  
            cout << athlete[1].getName() << " : " << p2_points; 
            cout << "" << endl; 
            continue; 
        }

        for (int i = 0; i<2; i++) { //server gets two serves each
            if (server == athlete[0].getName()) {
                if (probability1 <= random_num2) {
                    p1_points++;
                } else {
                    p2_points++;
                }
            } else {
                if (probability2 <= random_num2){
                    p2_points++;
                } else {
                    p1_points++; 
                }
            }

            points.push_back(p1_points);
            points.push_back(p2_points);

            cout << athlete[0].getName() << " : " << p1_points << " ";  
            cout << athlete[1].getName() << " : " << p2_points; 
            cout << "" << endl; 

            if (p1_points == point_to_win) {
                return "p1"; 
            }
            if (p2_points == point_to_win) {
                return "p2";
            }

        }

        if (server == athlete[0].getName()){
            server = athlete[1].getName();
        } else {
            server = athlete[0].getName();
        }
    }
        
    int difference = 0; //as the score is 6-6    
    while (true) {
        srand (time(NULL)); 
        random_num2 = rand()%101; 
        random_num2 /= 100;

        for (int i = 0; i<2; i++) {
            if (server == athlete[0].getName()) {
                if (probability1 <= random_num2) {
                    p1_points++;
                } else {
                    p2_points++;
                }
            } else {
                if (probability2 <= random_num2){
                    p2_points++;
                } else {
                    p1_points++; 
                }
            }

            points.push_back(p1_points);
            points.push_back(p2_points);

            cout << athlete[0].getName() << " : " << p1_points << " ";  
            cout << athlete[1].getName() << " : " << p2_points; 
            cout << "" << endl; 

            difference = p1_points-p2_points; 
            if (difference == 2) {
                if (server == athlete[0].getName()){
                    server = athlete[1].getName();
                } else {
                    server = athlete[0].getName();
                }
                return "p1";
            } 
            difference = p2_points-p1_points;
            if (difference == 2) {
                if (server == athlete[0].getName()){
                    server = athlete[1].getName();
                } else {
                    server = athlete[0].getName();
                }
                return "p2"; 
            }

        }

    }

    //last server must be returned for the begining of first set (unless its the last set)
        
}

    void autonomousSimulation::first_serve() {

        cout << "Which player will serve first?" << endl;
        cout << "Enter '1' for " << athlete[0].getName() << endl;
        cout << "Enter '2' for " << athlete[1].getName() << endl;
        int choice;
        cin >> choice; 
        while(!(choice == 1 || choice == 2)) {
            system("clear");
            cout << "Which player will serve first?" << endl;
            cout << "Enter '1' for " << athlete[0].getName() << endl;
            cout << "Enter '2' for " << athlete[1].getName() << endl;
            cin >> choice; 
        }

        if (choice == 1) {
            first_server = athlete[0].getName(); 
        } else {
            first_server = athlete[1].getName(); 
        }

        system("clear");
        cout << "" << endl;
    }

    void autonomousSimulation::select_tournament() {

        system("clear");
        
        cout << "What tournament are the 2 atheletes competing in?" << endl;
        cout << "The choices are: Australian Open, Roland Garros (French Open), Wimbeldon, US Open or an ATP masters." << endl; 
        cout << "Please enter AO for Australian Open, RO for Roland Garros, WD for Wimbeldon, US for US Open or ATP for" << endl; 
        cout << "an ATP masters tournament." << endl; 
        cin >> tournament; 

        while (!(tournament == "AO" || tournament == "RO" || tournament == "WD" || tournament == "US" || tournament == "ATP")) {
            system("clear");
            cout << "What tournament are the 2 atheletes competing in?" << endl;
            cout << "The choices are: Australian Open, Roland Garros (French Open), Wimbeldon, US Open or an ATP masters." << endl; 
            cout << "Please enter AO for Australian Open, RO for Roland Garros, W for Wimbeldon, US for US Open or ATP for" << endl; 
            cout << "an ATP masters tournament." << endl; 
            cin >> tournament; 
        }

       if (tournament == "AO" || tournament == "RO" || tournament == "WD" || tournament == "US") {
        if (athlete[0].getGender() == 'M' && athlete[1].getGender() == 'M') {
            num_sets = 5; //Males game must play a best of 5
            sets2_win = 3; 
        } else {
            num_sets = 3; //Women's game or a Male v Female game must be a best of 3
            sets2_win = 2; 
        }
       } else {
        num_sets = 3; //ATP masters
        sets2_win = 2;
       } 

       cout << "" << endl;
       system("clear");

     }

    void autonomousSimulation::set_probabilty(){ //THIS FUNCTION WILL NEED TO BE CHANGED ONCE PYTHON SCRIPT IS DONE
            system("clear");

            if (probability1 == 0 && probability2 == 0 || probability1 == 1 && probability2 == 1) {
                cout << "Probabilities cannot be 0 and 0 or 1 and 1." << endl;
                cout << "" << endl; 
             }


            int state_prob1 = 0;
            while (!state_prob1) {
                cout << "What is " << athlete[0].getName() << "'s total points won (decimal form)?" << endl;
                cout << "The value must be between 0 and 1 inclusive." << endl; 
                cin >> probability1;

                if (probability1 < 0 || probability1 > 1) {
                    system("clear");
                    cout << "Invalid value entered. Valid inputs are between 0 and 1 inclusive. Try again." << endl;
                    continue;
                } else {
                    system("clear");
                    state_prob1 = 1;
                }

             }

              int state_prob2 = 0;
              while (!state_prob2) {
                cout << "What is " << athlete[1].getName() << "'s total points won (decimal form)?" << endl;
                cout << "The value must be between 0 and 1 inclusive." << endl;
                cin >> probability2;

                if (probability2 < 0 || probability2 > 1) {
                    system("clear");
                    cout << "Invalid 1st or 2nd serve return points. Valid inputs are between 0 and 1 inclusive. Try again." << endl;
                    continue;
                } else {
                    system("clear");
                    state_prob2 = 1;
                }

             }

             if (probability1 == 0 && probability2 == 0 || probability1 == 1 && probability2 == 1) {
                cout << "Probabilities cannot be 0 and 0 or 1 and 1." << endl;
                cout << "" << endl; 
                set_probabilty(); 
             }

      cout << endl; 
      system("clear"); 

    }

    //simulation of the singles match
    string autonomousSimulation::simulate_singlesMatch(){

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

        //current points (0, 15, 30, 40, Ad) for the player and opponent
        int player_point = 0;
        int opponent_point = 0;

        //establishes the score as 0-0 for the first set
        points.push_back(player_point);
        points.push_back(opponent_point);

        double cur_prob; //current winning probability (player who is serving)
    
        //the number of games that have been played in the match 
        int num_games = 1; 

        //keeps track of sets and resets the games variable if true
        int reset_set = false;

        //status of the set (whether it has completed)
        int status = false;

        //resets the number of games which have to be reached to win a set for each simulation
        games = 6; 

        //tiebreak result for player1 (string is player1) and player2 (string is p2)    
        string tiebreak_result; 

        sets_played = 0; 

        cout << "The autonomous simulation for the singles match will now begin." << endl;
 
        while (!state) {

            if (accelerate == false) {
                sleep(1);
            }

            if (player_point == 50) {
                cout << athlete[0].getName() << " : " << "Ad" << endl;
                cout << athlete[1].getName() << " : " << opponent_point << endl;
            } else if (opponent_point == 50) {
                cout << athlete[0].getName() << " : " << player_point << endl;
                cout << athlete[1].getName() << " : " << "Ad" << endl;
            } else {
                cout << athlete[0].getName() << " : " << player_point << endl;
                cout << athlete[1].getName() << " : " << opponent_point << endl;
            }
            cout << "" << endl; 

            //check if it is a new set 
          if (reset_set == true) {
            reset_set = false; 
            games = 6; 
          }

            //GO BACK TO - need to do num_games++ when each game
          if (first_server == athlete[0].getName()) {
             if (num_games%2 != 0) { //odd games 
                cur_prob = probability1; 
                cur_server = athlete[0].getName();
            } else {
                cur_prob = probability2;
                cur_server = athlete[1].getName();
            }
          } else {
             if (num_games%2 != 0) { //odd games 
                cur_prob = probability2; 
                cur_server = athlete[1].getName();
            } else {
                cur_prob = probability1;
                cur_server = athlete[0].getName();
            }
          }
          
            srand (time(NULL)); //The time(NULL) parameter will provide a seed based on the time on the computer.
            random_num = rand()%101; //using the seed, a random number is generated between 0 and 100
            random_num /= 100; //random number is now between 0 and 1
            
                if (cur_server == athlete[0].getName()) { //p1 is serving  
                    if (random_num <= cur_prob) { //p1 wins point on serve
                        num_point++;
                        num_pointsWon_player1++;

                        if (player_point == 0) {
                            player_point = 15; 
                            points.push_back(player_point);
                            points.push_back(opponent_point);
                            continue;
                        }

                        if (player_point == 15) {
                            player_point = 30; 
                            points.push_back(player_point);
                            points.push_back(opponent_point);
                            continue;
                        } 

                        if (player_point == 30) {
                            player_point = 40; 
                            points.push_back(player_point);
                            points.push_back(opponent_point);
                            continue;
                        }

                        if (player_point == 50 && opponent_point == 40) { //player wins the advantage 
                            player_games++;
                            player_point = 0;
                            opponent_point = 0;
                            num_games++;
                            points.push_back(player_point);
                            points.push_back(opponent_point);
                        }

                        if (player_point == 40 && opponent_point == 40) { //player gets the advantage
                            player_point = 50; //player gets the advantage 
                            points.push_back(player_point);
                            points.push_back(opponent_point);
                            continue;
                        }

                        if (player_point == 40 && opponent_point == 50) { //50 is Adv - opponent loses adv
                            opponent_point = 40; 
                            points.push_back(player_point);
                            points.push_back(opponent_point);
                            continue;
                        }

                        if (player_point == 40 && opponent_point != 40 || opponent_point != 50) {
                             player_games++;
                             player_point = 0;
                             opponent_point = 0;
                             num_games++;
                             points.push_back(player_point);
                             points.push_back(opponent_point);
                        } 

                    } else { //p2 wins point on p1 serve

                        num_point++;
                        num_pointsWon_player2++;
                    
                        if (opponent_point == 0) {
                            opponent_point = 15; 
                            points.push_back(player_point);
                            points.push_back(opponent_point);
                            continue;
                        }

                        if (opponent_point == 15) {
                            opponent_point = 30; 
                            points.push_back(player_point);
                            points.push_back(opponent_point);
                            continue;
                        }

                        if (opponent_point == 30) {
                            opponent_point = 40; 
                            points.push_back(player_point);
                            points.push_back(opponent_point);
                            continue;
                        }

                        if (player_point == 40 && opponent_point == 50) {
                            opponent_games++;
                            player_point = 0;
                            opponent_point = 0;
                            num_games++;
                            points.push_back(player_point);
                            points.push_back(opponent_point);
                        }

                        if (player_point == 40 && opponent_point == 40) { //player gets the advantage
                            opponent_point = 50; //player gets the advantage 
                            points.push_back(player_point);
                            points.push_back(opponent_point);
                        }

                        if (player_point == 50 && opponent_point == 40) { //50 is Adv - opponent loses adv
                            player_point = 40; 
                            points.push_back(player_point);
                            points.push_back(opponent_point);
                        }

                        if (opponent_point == 40 && player_point != 40 || player_point != 50) {
                             opponent_games++;
                             player_point = 0;
                             opponent_point = 0;
                             num_games++;
                             points.push_back(player_point);
                             points.push_back(opponent_point);
                        } 
                    }
                    
                } else { //p2 is serving 

                    if (random_num <= cur_prob) { //p2 wins point on serve
                        num_point++;
                        num_pointsWon_player2++;
                    
                        if (opponent_point == 0) {
                            opponent_point = 15; 
                            points.push_back(player_point);
                            points.push_back(opponent_point);
                            continue;
                        }

                        if (opponent_point == 15) {
                            opponent_point = 30; 
                            points.push_back(player_point);
                            points.push_back(opponent_point);
                            continue;
                        }

                        if (opponent_point == 30) {
                            opponent_point = 40; 
                            points.push_back(player_point);
                            points.push_back(opponent_point);
                            continue;
                        }

                        if (player_point == 40 && opponent_point == 50) {
                            opponent_games++;
                            player_point = 0;
                            opponent_point = 0;
                            num_games++;
                            points.push_back(player_point);
                            points.push_back(opponent_point);
                        }

                        if (player_point == 40 && opponent_point == 40) { //player gets the advantage
                            opponent_point = 50; //player gets the advantage 
                            points.push_back(player_point);
                            points.push_back(opponent_point);
                        }

                        if (player_point == 50 && opponent_point == 40) { //50 is Adv - opponent loses adv
                            player_point = 40; 
                            points.push_back(player_point);
                            points.push_back(opponent_point);
                        }

                        if (opponent_point == 40 && player_point != 40 || player_point != 50) {
                             opponent_games++;
                             player_point = 0;
                             opponent_point = 0;
                             num_games++;
                             points.push_back(player_point);
                             points.push_back(opponent_point);
                        } 
                        
                    } else { //p1 wins point on p2's serve

                        num_point++;
                        num_pointsWon_player1++;
                    
                        if (player_point == 0) {
                            player_point = 15; 
                            points.push_back(player_point);
                            points.push_back(opponent_point);
                            continue;
                        }

                        if (player_point == 15) {
                            player_point = 30; 
                            points.push_back(player_point);
                            points.push_back(opponent_point);
                            continue;
                        }

                        if (player_point == 30) {
                            player_point = 40; 
                            points.push_back(player_point);
                            points.push_back(opponent_point);
                            continue;
                        }

                        if (player_point == 50 && opponent_point == 40) { //player wins the advantage 
                            player_games++;
                            player_point = 0;
                            opponent_point = 0;
                            num_games++;
                            points.push_back(player_point);
                            points.push_back(opponent_point);
                        }

                        if (player_point == 40 && opponent_point == 40) { //player gets the advantage
                            player_point = 50; //player gets the advantage 
                            points.push_back(player_point);
                            points.push_back(opponent_point);
                            continue;
                        }

                        if (player_point == 40 && opponent_point == 50) { //50 is Adv - opponent loses adv
                            opponent_point = 40; 
                            points.push_back(player_point);
                            points.push_back(opponent_point);
                            continue;
                        }

                        if (player_point == 40 && opponent_point != 40 || opponent_point != 50) {
                             player_games++;
                             player_point = 0;
                             opponent_point = 0;
                             num_games++;
                             points.push_back(player_point);
                             points.push_back(opponent_point);
                        } 

                    }

                }

                    //tie break 
                    if (player_games == 6 && opponent_games == 6) {
                        if (tournament == "AO" || tournament == "RO" || tournament == "US" || tournament == "WD") {
                            if (athlete[0].getGender() == 'M' && athlete[1].getGender() == 'M') {
                                if (player_sets+opponent_sets == 5) {
                                    tiebreak_result = tiebreak(10); 
                                } else {
                                    tiebreak_result = tiebreak(7);
                                }
                            } else { //womens tiebreak 
                                if (player_sets+opponent_sets == 3) {
                                    //final set tiebreak 
                                    tiebreak_result = tiebreak(10);
                                } else {
                                    //normal tiebreak 
                                    tiebreak_result = tiebreak(7);
                                }
                            }
                        } else { //ATP tournament 
                            if (player_sets+opponent_sets == 3) {
                                    //final set tiebreak 
                                    tiebreak_result = tiebreak(10);
                                } else {
                                    //normal tiebreak 
                                    tiebreak_result = tiebreak(7);
                                }
                        }
                        if (tiebreak_result == "p1") {
                            player_sets++;
                        } else {
                            opponent_sets++; 
                        }
                        status = true; 
                    } 

                    //this will be the condition to go to a new function 
                    if (player_games == 5 && opponent_games == 5) {
                        //num sets -> see what set it is (final or not)
                        //if set = 3, or if set = 5 (go to tournament function which represents tie break)
                        games = 7;
                    }

                    //check if the set is won and then determines if the match is over (exits the loop)
                    if (player_games == 6 && opponent_games == 6) {
                        if (tiebreak_result == "p1") {
                            cout << athlete[0].getName() << " won the tiebreak and the set!" << endl; 
                            player_sets++;
                            status = true; 
                            //p1 won the tiebreak and set
                        } else {
                            cout << athlete[1].getName() << " won the tiebreak and the set!" << endl;
                            opponent_sets++;
                            status = true;
                            //p2 won the tiebreak and set
                        }
                    }  
                    
                    if (player_games == games && opponent_games != games) {
                        cout << athlete[0].getName() << " won the set!" << endl; 
                        player_sets++; 
                        status = true;
                        //p1 won the set
                    } 
                    
                    if (player_games != games && opponent_games == games) {
                        cout << athlete[1].getName() << " won the set!" << endl;
                        //p2 won the set 
                        opponent_sets++;
                        status = true;
                    }

                    if (player_sets == sets2_win) {
                        system("clear");
                        cout << "Game, set, match " << athlete[0].getName() << " wins!" << endl;
                        sets_played = opponent_sets + player_sets; 
                        if (sets_played == 2) {
                            two_set++;
                        } else if (sets_played == 3) {
                            three_set++; 
                        } else if (sets_played == 4) {
                            four_set++; 
                        } else {
                            five_set++;
                        }
                        num_pointsWon_player2 = num_point - num_pointsWon_player1; //calculates the number of points won by player2
                        cout << "" << endl;
                        return "p1";
                        state = 1;
                    } 
                    
                    if (opponent_sets == sets2_win) {
                        system("clear");
                        cout << "Game, set, match " << athlete[1].getName() << " wins!" << endl;
                        cout << "" << endl;
                        sets_played = opponent_sets + player_sets; 
                        if (sets_played == 2) {
                            two_set++;
                        } else if (sets_played == 3) {
                            three_set++; 
                        } else if (sets_played == 4) {
                            four_set++; 
                        } else {
                            five_set++;
                        }
                        num_pointsWon_player2 = num_point - num_pointsWon_player1; //calculates the number of points won by player2
                        cout << "" << endl;
                        return "p2"; 
                        state = 1;
                    }
                    
                    if (status == true) {
                            reset_set = true;
                            status = false; 
                            player_games = 0;
                            opponent_games = 0;
                            player_point = 0;
                            opponent_point = 0;
                            cout << "A new set will now begin." << endl;
                            cout << "" << endl;
                            continue;
                    }

                    if (player_games != games || opponent_games != games) {
                        cout << "Game." << endl;
                        if (player_games == opponent_games){ //equal games
                            num_games++; 
                            cout << "The set is tied at " << player_games << "-all" << endl;
                            cout << "" << endl;
                            continue;
                        } else if (player_games > opponent_games) { //p1 games > p2 games
                            num_games++;
                            cout << athlete[0].getName() << " leads with " << player_games << " games to " << opponent_games << endl;
                            cout << "" << endl;
                            continue;
                        } else { //p2 games > p1 games
                            num_games++;
                            cout << athlete[1].getName() << " leads with " << opponent_games << " games to " << player_games << endl;
                            cout << "" << endl;
                            continue; 
                        }
                    }
        }
        return "end"; 
    }        
       
    void autonomousSimulation::calculate_percent_pointsWon_player1(){
        Simulation::calculate_percent_pointsWon_player1();
    }

    void autonomousSimulation::calculate_percent_pointsWon_player2(){
        Simulation::calculate_percent_pointsWon_player2();
    }

    double autonomousSimulation::return_percent_pointsWon_player1(){
        double percentage = Simulation::return_percent_pointsWon_player1();
        return percentage;
    }

    double autonomousSimulation::return_percent_pointsWon_player2(){
        double percentage = Simulation::return_percent_pointsWon_player2();
        return percentage;
    }

    void autonomousSimulation::print_simulation_results(){
        Simulation::print_simulation_results();
    }

    void autonomousSimulation::select_run_time(){
        Simulation::select_run_time(); 
    }

    //default deconstructor
    autonomousSimulation::~autonomousSimulation(){}