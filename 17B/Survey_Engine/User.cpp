/* 
 * File:   User.cpp
 * Author: mperi
 * 
 * Created on April 13, 2020, 2:39 PM
 */
#include "User.h"
#include "sha256.h"

#include <iostream>
#include <fstream> 
#include <string>
#include <algorithm>


using namespace std;


//private -----------------------------------------------------------------------

User::User() {
    //
}

User::~User() {
    //
}

void User::user_create_account() {
     //writing to file
    ofstream outputFile, outFile_a;
    string usern, passwd, text_file;    
    string passwd_hash;
            
    cout<<"Enter username: ";
    cin>>usern;
    if(usern != "admin"){
    cout<<"Enter password: ";
    cin>>passwd;
    text_file = "ACCOUNTS/" + usern + ".txt";
    outputFile.open(text_file);
    passwd_hash = sha256(passwd);
        
    outputFile<<usern<<endl;
    outputFile<<passwd_hash<<endl;
    
    outFile_a.open("ACCOUNTS_N/account_names.txt", std::ios::app); //to append
    outFile_a<<endl<<usern;
    
    outFile_a.close();
    outputFile.close();
    cout<<"Done creating"<<endl<<endl;
    }
    else {
        cout<<endl<<"Error: Cannot attempt login as admin!"<<endl<<endl;
    }   
}

bool User::user_existing_account() {
    
    //reading from file
    ifstream inputFile;
    string file_value, input_usern, input_passwd, text_file;
    string input_passwd_hash;
    
    bool state = false;
    bool state_u = false;
    bool state_p = false;
    
    for (int i=0; i<5; i++) {        
        cout<<"Enter Username: ";
        cin>>input_usern;
        if(input_usern != "admin"){
        cout<<"Enter Password: ";
        cin>>input_passwd;
        input_passwd_hash = sha256(input_passwd);
    
        text_file = "ACCOUNTS/" + input_usern + ".txt";    
        inputFile.open(text_file);
    
        inputFile>>file_value;    
        if (input_usern == file_value){
            state_u = true;
        }
        else {
            //
        }    
    
        inputFile>>file_value;        
        if (input_passwd_hash == file_value){
            state_p = true;
        }
        else {
            //
        }    
        
        if (state_u == true && state_p == true) {
            state = true;
            cout<<endl<<"Access Granted"<<endl<<endl;
            break;
        }
        else {
            state = false;
            cout<<"Username or Password is incorrect"<<endl<<endl;
        }
        if (i == 4) {
            cout<<endl<<"Timed out . . ."<<endl<<endl;
        }
    } else { //admin error
            cout<<endl<<"Error: Cannot attempt login as admin!"<<endl<<endl;
    }
    } 
        
    inputFile.close();
    
    return state;
    
}

void User::survey_menu() {
     bool state = true;
     int choice;
     
    do {
    std::cout<<"Store Menu"<<std::endl;
    std::cout<<"0: Logout"<<std::endl;
    std::cout<<"1: Take Survey"<<std::endl;    
    std::cin>>choice;
    
    switch(choice) {
        case 0: //exit
            state = false;
            break;
        case 1:                 //take survey
            take_survey();            
            break;                        
    }
    
    } while(state);
}

void User::take_survey() {
     ifstream inputFile;
    ofstream outResults;
    string filename, filenameR;
    string file_v;
    int ans;
    
    cout<<"Enter name of survey: ";
    cin>>filename;    
    filenameR = "RESULTS/" + filename + "_results.txt";
    filename = "SURVEYS/" + filename + ".txt";
    inputFile.open(filename);
    cout<<endl;
    
    //inputFile>>file_v; //Q
    getline(inputFile,file_v);
    cout<<file_v<<endl;
    
    //inputFile>>file_v; //Ans1
    getline(inputFile,file_v);
    cout<<file_v<<endl;
    
    //inputFile>>file_v; //Ans2
    getline(inputFile,file_v);
    cout<<file_v<<endl;
    
    //inputFile>>file_v; //Ans3
    getline(inputFile,file_v);
    cout<<file_v<<endl;
    
    cout<<"Choose Answer by #: ";
    cin>>ans;
    
    outResults.open(filenameR); //out result/ans    
    outResults<<ans;
}



//public -----------------------------------------------------------------------

void User::user_menu() {
    bool state = true;
    int choice;
    
    do {
    std::cout<<"Customer Menu"<<std::endl;
    std::cout<<"0: exit"<<std::endl;
    std::cout<<"1: Create account"<<std::endl;    
    std::cout<<"2: Log in"<<std::endl;    
    std::cin>>choice;
    
    switch(choice) {
        case 0: //exit
            state = false;
            break;
        case 1:
            user_create_account();
            break;
        case 2:            
            if(user_existing_account()){
                survey_menu();
            }
            else {
                //
            }
            break;
    }
    
    } while(state);
}