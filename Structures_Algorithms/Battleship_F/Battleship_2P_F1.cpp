/* 
 * TITLE: Battleship (Two Player Edition)
 * DESCRIPTION:A Two Player Turn Based Game Where Each Player Strategically Places 
 *              Their Ships On A 8x8 Board And Attempts To Sink All Their Oppenents
 *              Ships First
 * AUTHOR: Martin Perina
 * CREATED ON: NetBeans 8.2 + c++ + STL Library
 * CLASS: 17c
 *  
 * FURTHER DETAILS: Can Be Found In Write Up
 * 
 */

#include <cstdlib>
#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include <list>
#include <deque> 
#include <bits/stdc++.h> 

#include "Battleship_hash.h"
#include "Battleship_AVLTree.h"

using namespace std;

//Player 1----------------------------------------------------------------------
list <string> row1_p1 = {"#","#","#","#","#","#","#","#","#"};  //each list is one row on the game board
list <string> row2_p1 = {"#","#","#","#","#","#","#","#","#"};
list <string> row3_p1 = {"#","#","#","#","#","#","#","#","#"};
list <string> row4_p1 = {"#","#","#","#","#","#","#","#","#"};
list <string> row5_p1 = {"#","#","#","#","#","#","#","#","#"};
list <string> row6_p1 = {"#","#","#","#","#","#","#","#","#"};
list <string> row7_p1 = {"#","#","#","#","#","#","#","#","#"};
list <string> row8_p1 = {"#","#","#","#","#","#","#","#","#"};
list <string> row9_p1 = {"#","#","#","#","#","#","#","#","#"};

pair <string, string> A_ship1_p1; //Air-Craft-Carrier (4 positions)
pair <string, string> A_ship2_p1; //each pair is one ship position
pair <string, string> A_ship3_p1;
pair <string, string> A_ship4_p1;

pair <string, string> D_ship1_p1; //Destroyer (3 positions)
pair <string, string> D_ship2_p1; 
pair <string, string> D_ship3_p1; 

pair <string, string> S_ship1_p1; //Submarine one (2 positions)
pair <string, string> S_ship2_p1;

pair <string, string> S2_ship1_p1; //Submarine two (1 positions)

int A_ship_H_p1 = 4;    //health of each ship
int D_ship_H_p1 = 3;
int S_ship_H_p1 = 2;
int S2_ship_H_p1= 1;

int ship_shunk_p1[4] = {1,2,3,4};   //array to be used by set
set<int> s1(ship_shunk_p1, ship_shunk_p1 + 4);  //set 
int p1_T = 10;                                  //total ship health

//list <string> choice_history_p1;
deque <string> choice_history_p1;     //Dequeue for each shot taken

void set_boats_p1();    //setting boats on board, initializes pairs
void printBoardL_p1();  //prints the board
string player_choice_p1(); //takes in player choice for where to shoot
string check_hit_p1(string); //checks if shot hits a shit
string if_hit_p1(string); //if hit will manipulate necessary variables
void check_sunk_p1();   //checks ship health to see if sunk
bool check_win_p1();    //checks total ship health to see if Player has won
void player_1_win();    //displays Player 1 Win message banner 



//Player 2----------------------------------------------------------------------
//everything for Player 2 is the same as player one but with different names 
list <string> row1_p2 = {"#","#","#","#","#","#","#","#","#"};
list <string> row2_p2 = {"#","#","#","#","#","#","#","#","#"};
list <string> row3_p2 = {"#","#","#","#","#","#","#","#","#"};
list <string> row4_p2 = {"#","#","#","#","#","#","#","#","#"};
list <string> row5_p2 = {"#","#","#","#","#","#","#","#","#"};
list <string> row6_p2 = {"#","#","#","#","#","#","#","#","#"};
list <string> row7_p2 = {"#","#","#","#","#","#","#","#","#"};
list <string> row8_p2 = {"#","#","#","#","#","#","#","#","#"};
list <string> row9_p2 = {"#","#","#","#","#","#","#","#","#"};

pair <string, string> A_ship1_p2; //Air-Craft-Carrier
pair <string, string> A_ship2_p2;
pair <string, string> A_ship3_p2;
pair <string, string> A_ship4_p2;

pair <string, string> D_ship1_p2; //Destroyer
pair <string, string> D_ship2_p2;
pair <string, string> D_ship3_p2;

pair <string, string> S_ship1_p2; //Submarine one
pair <string, string> S_ship2_p2;

pair <string, string> S2_ship1_p2; //Submarine two

int A_ship_H_p2 = 4;
int D_ship_H_p2 = 3;
int S_ship_H_p2 = 2;
int S2_ship_H_p2 =1;

int ship_shunk_p2[4] = {1,2,3,4};
set<int> s2(ship_shunk_p2, ship_shunk_p2 + 4);
int p2_T = 10;

//list <string> choice_history_p2;
deque <string> choice_history_p2;

void set_boats_p2();
void printBoardL_p2();
string player_choice_p2();
string check_hit_p2(string);
string if_hit_p2(string);
void check_sunk_p2();
bool check_win_p2();
void player_2_win();


//Both -------------------------------------------------------------------------
list <string> X = {"X"};    //list to hold "X"
void start();               //starts the game 
void print_row_list(list <string>); //prints list (used to print game board)
void update_X();    //removes "#" from list X and puts in "X" 
void ex_Board();    //displays a blank example board with coordinates 
void player_health(); //calculates total health left for each player
int temp;   //temporarily holds max health

// FOR FINAL
void recursion_S(); //Recursive Sort
void hashing();     //Hashing 
void tree();        //Tree
void graph();       //Graph
//----Needed for above functions
void bubbleSort(int arr[], int );
void printArray(int arr[], int );
void addEdge(vector<int> adj[], int, int) ;
void printGraph(vector<int> adj[], int);
int C[7] = {0,0,0,0,0,0,0};

// Main-------------------------------------------------------------------------
int main(int argc, char** argv) {
    //for each pair
    //first = row
    //second = column       
    
            //you can set the positions manually here and comment out the
            //set_boats functions if desired
    //Player 1 ship positions           //Player 2 ship positions
//    A_ship1_p1.first   = "0";           A_ship1_p2.first   = "8";    
//    A_ship1_p1.second  = "0";           A_ship1_p2.second  = "8";   
//    A_ship2_p1.first   = "0";           A_ship2_p2.first   = "7"; 
//    A_ship2_p1.second  = "1";           A_ship2_p2.second  = "8";
//    A_ship3_p1.first   = "0";           A_ship3_p2.first   = "6";  
//    A_ship3_p1.second  = "2";           A_ship3_p2.second  = "8";               
//    A_ship4_p1.first   = "0";           A_ship4_p2.first   = "5";  
//    A_ship4_p1.second  = "3";           A_ship4_p2.second  = "8";                       
//    
//    D_ship1_p1.first   = "0";           D_ship1_p2.first   = "5";                    
//    D_ship1_p1.second  = "4";           D_ship1_p2.second  = "5";
//    D_ship2_p1.first   = "1";           D_ship2_p2.first   = "5"; 
//    D_ship2_p1.second  = "4";           D_ship2_p2.second  = "6";
//    D_ship3_p1.first   = "2";           D_ship3_p2.first   = "6"; 
//    D_ship3_p1.second  = "4";           D_ship3_p2.second  = "6";
//    
//    S_ship1_p1.first   = "7";           S_ship1_p2.first   = "3";
//    S_ship1_p1.second  = "0";           S_ship1_p2.second  = "0";
//    S_ship2_p1.first   = "7";           S_ship2_p2.first   = "3"; 
//    S_ship2_p1.second  = "1";           S_ship2_p2.second  = "1"; 
//    
//    S2_ship1_p1.first  = "8";           S2_ship1_p2.first  = "2";     
//    S2_ship1_p1.second = "3";           S2_ship1_p2.second = "3";       
    
    //control game loop
    bool state_p1 = true; 
    bool state_p2 = true; 
    
    
//    start();    //start menu    
//    set_boats_p1(); //setting boats P1
//    cout<<endl<<endl;
//    set_boats_p2(); //setting boats P2
//    cout<<endl<<endl<<"Now the game begins!"<<endl;
//    do {
//        //system("clear");
//        cout<<endl<<endl;
//        
//        //Player 1 Turn
//        cout<<endl<<"Player 1 Turn"<<endl;
//        printBoardL_p2();      
//        cout<<if_hit_p2(check_hit_p2(player_choice_p2()));
//        check_sunk_p2();
//        state_p2 = check_win_p2();
//        
//        if (state_p2 != false){        //if P1 won skip P2 turn
//        
//        cout<<endl<<endl;
//        
//        //Player 2 Turn
//        cout<<endl<<"Player 2 Turn"<<endl;
//        printBoardL_p1();      
//        cout<<if_hit_p1(check_hit_p1(player_choice_p1()));
//        check_sunk_p1();
//        state_p1 = check_win_p1();
//        }
//        cout<<endl;
//        player_health();
//        cout<<endl;
//    
//    } while(state_p1 == true && state_p2 == true);
//    
//    if (state_p2 == false) { //if P1 won
//        player_1_win();
//    }
//    if (state_p1 == false) { //if P2 won
//        player_2_win();
//    }    

    int choice;    
    int i=0;
    
    cout<<"1. Recursion"<<endl;
    cout<<"2. Recursive Sorts"<<endl;
    cout<<"3. Hashing"<<endl;
    cout<<"4. Trees"<<endl;
    cout<<"5. Graphs"<<endl;
    
    do {
    cout<<"Choose a #: ";
    cin>>choice;     
    C[i] = choice;
    switch(choice){
        case 1:     //Recursion
            //recursion();
            break;  
        case 2:     //Recursive Sort
            recursion_S();
            break;
        case 3:     //Hashing
            hashing();
            break;
        case 4:     //Trees
            tree();
            break;
        case 5:     //Graphs
            graph();
            break;
        default:    //exit
            cout<<"exit"<<endl;
            break;
    }
    i++;
    } while(choice<=5 && choice>=1);
    
    return 0; //exit peacefully 
}
// End Main --------------------------------------------------------------------

// Player 1 --------------------------------------------------------------------
void set_boats_p1(){ 
    cout<<endl<<endl<<endl<<endl<<endl; //display game instructions 
    cout<<"The game board is 9x9 (Row 0-8 and Col 0-8)"<<endl;
    cout<<"Each spot is one coordinate: Row & Column"<<endl;
    cout<<"Each boat coordinate needs to be an adjacent spot"<<endl;
    cout<<"(No Diagonals and No Overlapping Coordinates!)"<<endl;
    cout<<endl<<"Press [ENTER] to continue...";
    cin.ignore(); 
    
    string r, c;    //take input for row and col
    cout<<endl<<endl;       //instructions on boats
    cout<<"Player 1 Choose where to place your boats, Player 2 please advert your eyes"<<endl;
    cout<<"Boats: "<<endl;
    cout<<"\tAircraft Carrier [3 spots]"<<endl;
    cout<<"\tDestroyer        [2 spots]"<<endl;
    cout<<"\tSubmarine        [2 spots]"<<endl;
    cout<<"\tSubmarine Two    [2 spots]"<<endl;
   
   
    ex_Board();
    cout<<endl<<"Press [ENTER] to continue...";
    cin.ignore(); 
    
    cout<<"Now it is time to place your boats Player 1"<<endl;  //take P1 input for positions 
    cout<<"You may refer back the the example board to plan your placements"<<endl;
    cout<<"Example for Aircraft Carrier: (0,0) (1,0) (1,1)"<<endl;
    
    cout<<"Spot One: Aircraft Carrier (ROW): "; //Aircraft Carrier 
    cin>>r;
    cout<<"Spot One: Aircraft Carrier (COL): ";
    cin>>c;
    A_ship1_p1.first = r;
    A_ship1_p1.second = c;
    cout<<"Spot Two: Aircraft Carrier (ROW): ";
    cin>>r;
    cout<<"Spot Two: Aircraft Carrier (COL): ";
    cin>>c;
    A_ship2_p1.first = r;
    A_ship2_p1.second = c;
    cout<<"Spot Three: Aircraft Carrier (ROW): ";
    cin>>r;
    cout<<"Spot Three: Aircraft Carrier (COL): ";
    cin>>c;
    A_ship3_p1.first = r;
    A_ship3_p1.second = c;
    cout<<"Spot Four: Aircraft Carrier (ROW): ";
    cin>>r;
    cout<<"Spot Four: Aircraft Carrier (COL): ";
    cin>>c;
    A_ship4_p1.first = r;
    A_ship4_p1.second = c;
    
    cout<<"Spot One: Destroyer (ROW): "; //Destroyer
    cin>>r;
    cout<<"Spot One: Destroyer (COL): ";
    cin>>c;
    D_ship1_p1.first = r;
    D_ship1_p1.second = c;
    cout<<"Spot Two: Destroyer (ROW): ";
    cin>>r;
    cout<<"Spot Two: Destroyer (COL): ";
    cin>>c;
    D_ship2_p1.first = r;
    D_ship2_p1.second = c;
    cout<<"Spot Three: Destroyer (ROW): ";
    cin>>r;
    cout<<"Spot Three: Destroyer (COL): ";
    cin>>c;
    D_ship3_p1.first = r;
    D_ship3_p1.second = c;
    
    cout<<"Spot One: Submarine (ROW): "; //Submarine
    cin>>r;
    cout<<"Spot One: Submarine (COL): ";
    cin>>c;
    S_ship1_p1.first = r;
    S_ship1_p1.second = c;
    cout<<"Spot Two: Submarine (ROW): ";
    cin>>r;
    cout<<"Spot Two: Submarine (COL): ";
    cin>>c;
    S_ship2_p1.first = r;
    S_ship2_p1.second = c;
    
    cout<<"Spot One: Submarine Two (ROW): "; //Submarine Two
    cin>>r;
    cout<<"Spot One: Submarine Two (COL): ";
    cin>>c;
    S2_ship1_p1.first = r;
    S2_ship1_p1.second = c;
//    cout<<"Spot Two: Submarine Two (ROW): ";
//    cin>>r;
//    cout<<"Spot Two: Submarine Two (COL): ";
//    cin>>c;
//    S2_ship2_p1.first = r;
//    S2_ship2_p1.second = c;
}

void printBoardL_p1() { 
    cout << "   0|1|2|3|4|5|6|7|8" << endl;
    for(int i=0; i<9; i++)  //column loop
    {
        for(int j=0; j<10; j++)  //row loop
        {
            if(j==0)
            {
                cout << i << "  " ; //print row number and spaces before new row
            }            
            if(j!=9)
            {
                if(i==0 && j==0){ //print row1 list
                    //cout<<"1";
                    print_row_list(row1_p1);
                }
                if(i==1 && j==0){ //print row12 list
                    print_row_list(row2_p1);
                }
                if(i==2 && j==0){ //print row3 list
                    print_row_list(row3_p1);
                }
                if(i==3 && j==0){ //print row4 list
                    print_row_list(row4_p1);
                }
                if(i==4 && j==0){ //print row5 list
                    print_row_list(row5_p1);
                }
                if(i==5 && j==0){ //print row6 list
                    print_row_list(row6_p1);
                }
                if(i==6 && j==0){ //print row7 list
                    print_row_list(row7_p1);
                }
                if(i==7 && j==0){ //print row8 list
                    print_row_list(row8_p1);
                }
                if(i==8 && j==0){ //print row9 list
                    print_row_list(row9_p1);
                }
            }
        }
    cout << endl; //new line at end of column
    }
    cout << endl;
    
    
}

string player_choice_p1() {
    
    string A, r, c;
    bool state;
    
    do {
        state = false;
        cout<<"Enter row: ";
        cin>>r;
        cout<<"Enter col: ";
        cin>>c;
        A = r + ":" + c;  

        for (auto i = choice_history_p1.begin(); i != choice_history_p1.end(); ++i) { //check if already hit
            if (*i == A) { 
                cout<<endl<<"Already Hit, Try Again"<<endl;
                state = true;
                //i--; 
            }     
        }
    
    } while(state); //loop until new (not previously fired upon) spot is entered
    
    choice_history_p1.push_back(A);
    //print_row_list(choice_history);
    return A;    
}

string check_hit_p1(string input) {
    string delimiter = ":";
    string R, C;   
    R = input.substr(0, input.find(delimiter)); //parse string to get row
    C = input.substr(2, input.find(delimiter));//to get col
    
    //check against each ship spot (coordinate)
    if        (A_ship1_p1.first == R && A_ship1_p1.second == C ){
        input = R + ":" + C;
        A_ship_H_p1--;
    }
       else if(A_ship2_p1.first == R && A_ship2_p1.second == C){
        input = R + ":" + C;
        A_ship_H_p1--;
    }
       else if(A_ship3_p1.first == R && A_ship3_p1.second == C){
        input = R + ":" + C;
        A_ship_H_p1--;
    }
       else if(A_ship4_p1.first == R && A_ship4_p1.second == C){
        input = R + ":" + C;
        A_ship_H_p1--;
    }
       else if(D_ship1_p1.first == R && D_ship1_p1.second == C){
        input = R + ":" + C;
        D_ship_H_p1--;
    }
       else if(D_ship2_p1.first == R && D_ship2_p1.second == C){
        input = R + ":" + C;
        D_ship_H_p1--;
    }
       else if(D_ship3_p1.first == R && D_ship3_p1.second == C){
        input = R + ":" + C;
        D_ship_H_p1--;
    }
       else if(S_ship1_p1.first == R && S_ship1_p1.second == C){
        input = R + ":" + C;
        S_ship_H_p1--;
    }
       else if(S_ship2_p1.first == R && S_ship2_p1.second == C){
        input = R + ":" + C;
        S_ship_H_p1--;
    }
       else if(S2_ship1_p1.first == R && S2_ship1_p1.second == C){
        input = R + ":" + C;
        S2_ship_H_p1--;
    }
//       else if(S2_ship2_p1.first == R && S2_ship2_p1.second == C){
//        input = R + ":" + C;
//        S2_ship_H_p1--;
//    }
    else {
        input = "MISS";
    }


    return input; //return MISS if miss or coordinates if hit
}

string if_hit_p1(string input) {
    string A;
    if (input == "MISS"){ ///skip to end
        A = "\n" + input;
    }
    else {
    string delimiter = ":";
    string R, C;   
    R = input.substr(0, input.find(delimiter)); //parse again
    C = input.substr(2, input.find(delimiter));
    
    list <string> :: iterator it0 = row1_p1.begin(); //initialize iterator to beginning of each list
    list <string> :: iterator it1 = row2_p1.begin();
    list <string> :: iterator it2 = row3_p1.begin();
    list <string> :: iterator it3 = row4_p1.begin();
    list <string> :: iterator it4 = row5_p1.begin();
    list <string> :: iterator it5 = row6_p1.begin();
    list <string> :: iterator it6 = row7_p1.begin();
    list <string> :: iterator it7 = row8_p1.begin();
    list <string> :: iterator it8 = row9_p1.begin();
    
    list <string> :: iterator itX = X.begin(); //initialize iterator for list X to beginning 
    
    stringstream tempR(R); //convert string to integer
    stringstream tempC(C);
    int RR, CC;
    tempR>>RR; //are now integers
    tempC>>CC;
    
    //finds correct row and swaps appropraite position based on col for an X
    if          (RR == 0) {   //row 0
        advance(it0, CC);
        std::swap(*it0, *itX);     //insert X for hit in the spot 
    }
        else if (RR == 1) { //row 1
        advance(it1, CC);
        std::swap(*it1, *itX);
    }
        else if (RR == 2) { //row 1
        advance(it2, CC);
        std::swap(*it2, *itX);
    }
        else if (RR == 3) { //row 1
        advance(it3, CC);
        std::swap(*it3, *itX);
    }
        else if (RR == 4) { //row 1
        advance(it4, CC);
        std::swap(*it4, *itX);
    }
        else if (RR == 5) { //row 1
        advance(it5, CC);
        std::swap(*it5, *itX);
    }
        else if (RR == 6) { //row 1
        advance(it6, CC);
        std::swap(*it6, *itX);
    }
        else if (RR == 7) { //row 1
        advance(it7, CC);
        std::swap(*it7, *itX);
    }
        else if (RR == 8) { //row 1
        advance(it8, CC);
        std::swap(*it8, *itX);
    }
    
    update_X();
    A = "\nHIT !!!";
    }
    
    return A; //return a HIT if hit or MISS if miss
}

void check_sunk_p1(){ 
    if (A_ship_H_p1 == 0) {
        cout<<endl<<"Aircraft Carrier sunk!"; //display ship sunk if zero health
        ship_shunk_p1[0] = 0;   //update array of ship health (used by set)
    }
    if (D_ship_H_p1 == 0) {
        cout<<endl<<"Destroyer sunk!";
        ship_shunk_p1[1] = 0;
    }
    if (S_ship_H_p1 == 0) {
        cout<<endl<<"Submarine sunk!";
        ship_shunk_p1[2] = 0;
    }
    if (S2_ship_H_p1 == 0) {
        cout<<endl<<"Submarine Two sunk!";
        ship_shunk_p1[3] = 0;
    }
}

bool check_win_p1() {
    int sum;
    bool state = true;
    
    sum=A_ship_H_p1+D_ship_H_p1+S_ship_H_p1+S2_ship_H_p1; //check if player has won
    if (sum == 0) {
        state = false;
    }
    return state;
}

void player_1_win(){
    cout<<endl<<endl;
    cout<<" _____ _                         __    _    _ _              "<<endl;
    cout<<"| ___ \\ |                       /  |  | |  | (_)            "<<endl; 
    cout<<"| |_/ / | __ _ _   _  ___ _ __  `| |  | |  | |_ _ __         "<<endl;
    cout<<"|  __/| |/ _` | | | |/ _ \\ '__|  | |  | |/\\| | | '_ \\     "<<endl;
    cout<<"| |   | | (_| | |_| |  __/ |    _| |_ \\  /\\  / | | | |     "<<endl;
    cout<<"\\_|   |_|\\__,_|\\__, |\\___|_|    \\___/  \\/  \\/|_|_| |_|"<<endl;
    cout<<"                __/ |                                        "<<endl;
    cout<<"               |___/                                         "<<endl;
    cout<<endl<<"End of Game"<<endl;
    cout<<"Thanks for playing . . . Goodbye"<<endl<<endl;
    
}
// End Player 1 ----------------------------------------------------------------

// Player 2 --------------------------------------------------------------------
//everything for Player 2 is the same as player one but with different names 
void set_boats_p2(){
     string r, c;
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"Player 2 Choose where to place your boats, Player 1 please advert your eyes"<<endl;
    cout<<"Boats: "<<endl;
    cout<<"\tAircraft Carrier [3 spots]"<<endl;
    cout<<"\tDestroyer        [2 spots]"<<endl;
    cout<<"\tSubmarine        [2 spots]"<<endl;
    cout<<"\tSubmarine Two    [2 spots]"<<endl;
    
    ex_Board();
    cout<<endl<<"Press [ENTER] to continue...";
    cin.ignore(); 
    
    cout<<"Now it is time to place your boats Player 2"<<endl;
    cout<<"You may refer back the the example board to plan your placements"<<endl;
    cout<<"Example for Aircraft Carrier: (0,0) (1,0) (1,1)"<<endl;
    
    cout<<"Spot One: Aircraft Carrier (ROW): "; //Aircraft Carrier 
    cin>>r;
    cout<<"Spot One: Aircraft Carrier (COL): ";
    cin>>c;
    A_ship1_p2.first = r;
    A_ship1_p2.second = c;
    cout<<"Spot Two: Aircraft Carrier (ROW): ";
    cin>>r;
    cout<<"Spot Two: Aircraft Carrier (COL): ";
    cin>>c;
    A_ship2_p2.first = r;
    A_ship2_p2.second = c;
    cout<<"Spot Three: Aircraft Carrier (ROW): ";
    cin>>r;
    cout<<"Spot Three: Aircraft Carrier (COL): ";
    cin>>c;
    A_ship3_p2.first = r;
    A_ship3_p2.second = c;
    cout<<"Spot Four: Aircraft Carrier (ROW): ";
    cin>>r;
    cout<<"Spot Four: Aircraft Carrier (COL): ";
    cin>>c;
    A_ship4_p2.first = r;
    A_ship4_p2.second = c;
    
    cout<<"Spot One: Destroyer (ROW): "; //Destroyer
    cin>>r;
    cout<<"Spot One: Destroyer (COL): ";
    cin>>c;
    D_ship1_p2.first = r;
    D_ship1_p2.second = c;
    cout<<"Spot Two: Destroyer (ROW): ";
    cin>>r;
    cout<<"Spot Two: Destroyer (COL): ";
    cin>>c;
    D_ship2_p2.first = r;
    D_ship2_p2.second = c;
    cout<<"Spot Three: Destroyer (ROW): ";
    cin>>r;
    cout<<"Spot Three: Destroyer (COL): ";
    cin>>c;
    D_ship3_p2.first = r;
    D_ship3_p2.second = c;
    
    cout<<"Spot One: Submarine (ROW): "; //Submarine
    cin>>r;
    cout<<"Spot One: Submarine (COL): ";
    cin>>c;
    S_ship1_p2.first = r;
    S_ship1_p2.second = c;
    cout<<"Spot Two: Submarine (ROW): ";
    cin>>r;
    cout<<"Spot Two: Submarine (COL): ";
    cin>>c;
    S_ship2_p2.first = r;
    S_ship2_p2.second = c;
    
    cout<<"Spot One: Submarine Two (ROW): "; //Submarine Two
    cin>>r;
    cout<<"Spot One: Submarine Two (COL): ";
    cin>>c;
    S2_ship1_p2.first = r;
    S2_ship1_p2.second = c;
//    cout<<"Spot Two: Submarine Two (ROW): ";
//    cin>>r;
//    cout<<"Spot Two: Submarine Two (COL): ";
//    cin>>c;
//    S2_ship2_p2.first = r;
//    S2_ship2_p2.second = c;
}

void printBoardL_p2() {
    cout << "   0|1|2|3|4|5|6|7|8" << endl;
    for(int i=0; i<9; i++)  //column loop
    {
        for(int j=0; j<10; j++)  //row loop
        {
            if(j==0)
            {
                cout << i << "  " ; //print row number and spaces before new row
            }            
            if(j!=9)
            {
                if(i==0 && j==0){ //print row1 list
                    //cout<<"1";
                    print_row_list(row1_p2);
                }
                if(i==1 && j==0){ //print row12 list
                    print_row_list(row2_p2);
                }
                if(i==2 && j==0){ //print row3 list
                    print_row_list(row3_p2);
                }
                if(i==3 && j==0){ //print row4 list
                    print_row_list(row4_p2);
                }
                if(i==4 && j==0){ //print row5 list
                    print_row_list(row5_p2);
                }
                if(i==5 && j==0){ //print row6 list
                    print_row_list(row6_p2);
                }
                if(i==6 && j==0){ //print row7 list
                    print_row_list(row7_p2);
                }
                if(i==7 && j==0){ //print row8 list
                    print_row_list(row8_p2);
                }
                if(i==8 && j==0){ //print row9 list
                    print_row_list(row9_p2);
                }
            }
        }
    cout << endl; //new line at end of column
    }
    cout << endl;  
}

string player_choice_p2() {
    
    string A, r, c;
    bool state;
    
    do {
        state = false;
        cout<<"Enter row: ";
        cin>>r;
        cout<<"Enter col: ";
        cin>>c;
        A = r + ":" + c;  

        for (auto i = choice_history_p2.begin(); i != choice_history_p2.end(); ++i) { 
            if (*i == A) { 
                cout<<endl<<"Already Hit, Try Again"<<endl;
                state = true;
                //i--; 
            }     
        }
    
    } while(state);
    
    choice_history_p2.push_back(A);
    //print_row_list(choice_history);
    return A;    
}

string check_hit_p2(string input) {
    string delimiter = ":";
    string R, C;   
    R = input.substr(0, input.find(delimiter));
    C = input.substr(2, input.find(delimiter));
    
    
    if        (A_ship1_p2.first == R && A_ship1_p2.second == C ){
        input = R + ":" + C;
        A_ship_H_p2--;
    }
       else if(A_ship2_p2.first == R && A_ship2_p2.second == C){
        input = R + ":" + C;
        A_ship_H_p2--;
    }
       else if(A_ship3_p2.first == R && A_ship3_p2.second == C){
        input = R + ":" + C;
        A_ship_H_p2--;
    }
       else if(D_ship1_p2.first == R && D_ship1_p2.second == C){
        input = R + ":" + C;
        D_ship_H_p2--;
    }
       else if(D_ship2_p2.first == R && D_ship2_p2.second == C){
        input = R + ":" + C;
        D_ship_H_p2--;
    }
       else if(S_ship1_p2.first == R && S_ship1_p2.second == C){
        input = R + ":" + C;
        S_ship_H_p2--;
    }
       else if(S_ship2_p2.first == R && S_ship2_p2.second == C){
        input = R + ":" + C;
        S_ship_H_p2--;
    }
       else if(S2_ship1_p2.first == R && S2_ship1_p2.second == C){
        input = R + ":" + C;
        S2_ship_H_p2--;
    }
//       else if(S2_ship2_p2.first == R && S2_ship2_p2.second == C){
//        input = R + ":" + C;
//        S2_ship_H_p2--;
//    }
    else {
        input = "MISS";
    }


    return input;
}

string if_hit_p2(string input) {
    string A;
    if (input == "MISS"){
        A = "\n" + input;
    }
    else {
    string delimiter = ":";
    string R, C;   
    R = input.substr(0, input.find(delimiter));
    C = input.substr(2, input.find(delimiter));
    
    list <string> :: iterator it0 = row1_p2.begin();
    list <string> :: iterator it1 = row2_p2.begin();
    list <string> :: iterator it2 = row3_p2.begin();
    list <string> :: iterator it3 = row4_p2.begin();
    list <string> :: iterator it4 = row5_p2.begin();
    list <string> :: iterator it5 = row6_p2.begin();
    list <string> :: iterator it6 = row7_p2.begin();
    list <string> :: iterator it7 = row8_p2.begin();
    list <string> :: iterator it8 = row9_p2.begin();
    
    list <string> :: iterator itX = X.begin();
    
    stringstream tempR(R);
    stringstream tempC(C);
    int RR, CC;
    tempR>>RR;
    tempC>>CC;
    
           
    if          (RR == 0) {   //row 0
        advance(it0, CC);
        std::swap(*it0, *itX);     //insert X for hit in the spot 
    }
        else if (RR == 1) { //row 1
        advance(it1, CC);
        std::swap(*it1, *itX);
    }
        else if (RR == 2) { //row 1
        advance(it2, CC);
        std::swap(*it2, *itX);
    }
        else if (RR == 3) { //row 1
        advance(it3, CC);
        std::swap(*it3, *itX);
    }
        else if (RR == 4) { //row 1
        advance(it4, CC);
        std::swap(*it4, *itX);
    }
        else if (RR == 5) { //row 1
        advance(it5, CC);
        std::swap(*it5, *itX);
    }
        else if (RR == 6) { //row 1
        advance(it6, CC);
        std::swap(*it6, *itX);
    }
        else if (RR == 7) { //row 1
        advance(it7, CC);
        std::swap(*it7, *itX);
    }
        else if (RR == 8) { //row 1
        advance(it8, CC);
        std::swap(*it8, *itX);
    }
    
    update_X();
    A = "\nHIT !!!";
    }
    
    return A;
}

void check_sunk_p2(){
    if (A_ship_H_p2 == 0) {
        cout<<endl<<"Aircraft Carrier sunk!";
        ship_shunk_p1[0] = 0;
    }
    if (D_ship_H_p2 == 0) {
        cout<<endl<<"Destroyer sunk!";
        ship_shunk_p1[1] = 0;
    }
    if (S_ship_H_p2 == 0) {
        cout<<endl<<"Submarine sunk!";
        ship_shunk_p1[2] = 0;
    }
    if (S2_ship_H_p2 == 0) {
        cout<<endl<<"Submarine Two sunk!";
        ship_shunk_p1[3] = 0;
    }
}

bool check_win_p2() {
    int sum;
    bool state = true;
    
    sum=A_ship_H_p2+D_ship_H_p2+S_ship_H_p2+S2_ship_H_p2;
    if (sum == 0) {
        state = false;
    }
    return state;
}

void player_2_win(){
    cout<<endl<<endl;
    cout<<" _____ _                         _____   _    _ _        "<<endl;
    cout<<"| ___ \\ |                       / __  \\ | |  | (_)       "<<endl; 
    cout<<"| |_/ / | __ _ _   _  ___ _ __  `' / /' | |  | |_ _ __   "<<endl;
    cout<<"|  __/| |/ _` | | | |/ _ \\ '__|   / /   | |/\\| | | '_ \\  "<<endl;
    cout<<"| |   | | (_| | |_| |  __/ |    ./ /___ \\  /\\  / | | | | "<<endl;
    cout<<"\\_|   |_|\\__,_|\\__, |\\___|_|    \\_____/  \\/  \\/|_|_| |_| "<<endl;
    cout<<"                __/ |                                    "<<endl;
    cout<<"               |___/                                     "<<endl;
    cout<<endl<<"End of Game"<<endl;
    cout<<"Thanks for playing . . . Goodbye"<<endl<<endl;

    
}
// End Player 2 ----------------------------------------------------------------

//Both--------------------------------------------------------------------------
void start() {
    cout<<endl;
    cout<<"Welcome to . . . "<<endl<<endl;
    
    cout<<" ______       _   _   _           _     _        "<<endl;
    cout<<" | ___ \\     | | | | | |         | |   (_)       "<<endl; 
    cout<<" | |_/ / __ _| |_| |_| | ___  ___| |__  _ _ __   "<<endl;
    cout<<" | ___ \\/ _` | __| __| |/ _ \\/ __| '_ \\| | '_ \\  "<<endl;
    cout<<" | |_/ / (_| | |_| |_| |  __/\\__ \\ | | | | |_) | "<<endl;
    cout<<" \\____/ \\__,_|\\__|\\__|_|\\___||___/_| |_|_| .__/  "<<endl;
    cout<<"                                         | |     "<<endl;
    cout<<"                                         |_|     "<<endl;
    cout<<"This is a two player turn based game"<<endl<<endl;
    cout<<"   Player 1  &  Player 2"<<endl;
    cout<<endl<<"Press [ENTER] to continue...";
    cin.ignore();
    system("clear");
}

void print_row_list(list <string> A) {    
    list <string> :: iterator it; 
    for(it = A.begin(); it != A.end(); ++it) { //iterator from beginning to end and output each element
        cout << *it << " "; 
    }
}

void update_X() {
    X.remove("#"); //find all "#" and remove (there should only be one)
    X.push_front("X");    //input a new "X"
}

void ex_Board(){
    cout<<endl<<endl;
    cout<<"This is what the game board looks like"<<endl;
    cout << "   0|1|2|3|4|5|6|7|8" << endl;
    for(int i=0; i<9; i++)  //column loop
    {
        for(int j=0; j<10; j++)  //row loop
        {
            if(j==0)
            {
                cout << i << "  " ; //print row number and spaces before new row
            }
            if(j!=9)
            {
                cout << "# ";
            }
        }
    cout << endl; //new line at end of column
    }
    cout << endl; 
}

void player_health(){
    //p1
    if(s1.count(1)){ //subtract from total health if element is found in ship health array
        p1_T -= 3;
    }
    if(s1.count(2)){
        p1_T -= 2;
    }
    if(s1.count(3)){
        p1_T -= 2;
    }
    if(s1.count(4)){
        p1_T -= 2;
    }
    
    //p2
    if(s2.count(1)){
        p1_T -= 3;
    }
    if(s2.count(2)){
        p1_T -= 2;
    }
    if(s2.count(3)){
        p1_T -= 2;
    }
    if(s2.count(4)){
        p1_T -= 2;
    }
    
    temp = max(p1_T, p2_T);         //max between the two player total health
    if(p1_T == temp){               //output who has more health
        cout<<"Player 1 has more health";
    }
    
    if(p2_T == temp){
        cout<<"Player 2 has more health";
    }
}

//FOR FINAL --------------------------------------------------------------------
void tree(){
    //insert health of ships (out of order) into a tree T
    AVLTree T;
    T.root = T.insert(T.root, S_ship_H_p1);  //2
    T.root = T.insert(T.root, A_ship_H_p1);  //4
    T.root = T.insert(T.root, S2_ship_H_p1); //1
    T.root = T.insert(T.root, D_ship_H_p1);  //3
    T.display(T.root,1); //display tree after balancing
}

void hashing() { //use hashing for ship health
  int a[] = {1, 2, 3, 4}; 
  int n = sizeof(a)/sizeof(a[0]); 
  
  Hash h(7);   // 7 is count of buckets in hash table               
  for (int i = 0; i < n; i++)  
    h.insertItem(a[i]);   
  
  h.displayHash(); 
}


void bubbleSort(int arr[], int n) { //Needed for recurions_S
 
    if (n == 1) {
        return; 
    }
  
    for (int i=0; i<n-1; i++) 
        if (arr[i] > arr[i+1]) 
            swap(arr[i], arr[i+1]); 
    
    bubbleSort(arr, n-1); 
} 
  
void printArray(int arr[], int n) { //Needed for recurions_S
    for (int i=0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

void recursion_S (){    //use recursion to sort through each position on the grid
    int arr[] = {81,82,83,84,85,86,87,88,
                 0,1,2,3,4,5,6,7,8,
                 61,62,63,64,65,66,67,68,                 
                 21,22,23,24,25,26,27,28,
                 41,42,43,44,45,46,47,48,
                 11,12,13,14,15,16,17,18,
                 51,52,53,54,55,56,57,58,
                 71,72,73,74,75,76,77,78,
                 31,32,33,34,35,36,37,38}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printf("Unsorted array : \n"); 
    printArray(arr, n); 
    bubbleSort(arr, n); 
    printf("Sorted array : \n"); 
    printArray(arr, n); 
}

void addEdge(vector<int> adj[], int u, int v) { //Needed for graph
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
  
void printGraph(vector<int> adj[], int V) { //Needed for graph
    for (int v = 0; v < V; ++v) { 
        cout << "\n Adjacency list of vertex "
             << v << "\n head "; 
        for (auto x : adj[v]) 
           cout << "-> " << x; 
        printf("\n"); 
    } 
} 

void graph() { //use graph to represent choice history after game
    int V = 5; 
    vector<int> adj[V]; 
    addEdge(adj, 0, C[0]); 
    addEdge(adj, 0, C[1]); 
    addEdge(adj, 1, C[2]); 
    addEdge(adj, 1, C[3]); 
    addEdge(adj, 1, C[4]); 
    addEdge(adj, 2, C[5]); 
    addEdge(adj, 3, C[6]); 
    printGraph(adj, V); 
}
    
//End Both----------------------------------------------------------------------