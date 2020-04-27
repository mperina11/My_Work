/* 
 * File:   Admin.cpp
 * Author: mperi
 * 
 * Created on April 13, 2020, 2:39 PM
 */

#include "Admin.h"
#include "sha256.h"

#include <iostream> 
#include <fstream> 
#include <string>
#include <stdio.h>


using namespace std;

//private -----------------------------------------------------------------------

void Admin::create_survey() {
         //writing to file
            
    std::cout<<"Enter Survey name (one word or use underscores): ";
    std::cin.ignore();
    getline(std::cin, s_name);
    text_file = "SURVEYS/" + s_name + ".txt";
    outputFile.open(text_file);
    
    std::cout<<"Enter Question: ";
    getline(std::cin, s_q);
    s_q = "Q: " + s_q;
    outputFile<<s_q<<std::endl;
    
    std::cout<<"Enter Answer 1: ";
    getline(std::cin, s_a1);
    s_a1 = "1: " + s_a1;
    outputFile<<s_a1<<std::endl;
    
    std::cout<<"Enter Answer 2: ";
    getline(std::cin, s_a2);
    s_a2 = "2: " + s_a2;
    outputFile<<s_a2<<std::endl;
    
    std::cout<<"Enter Answer 3: ";
    getline(std::cin, s_a3);
    s_a3 = "3: " + s_a3;
    outputFile<<s_a3<<std::endl;
    
    
    outputFile.close();
    cout<<endl<<"done writing"<<endl<<endl;
}

void Admin::simulate_taking_survey() {
    
    cout<<"Enter name of survey: ";
    cin>>filename;    
    filename = "SURVEYS/" + filename + ".txt";
    inputFile.open(filename);
    cout<<endl;
    
    //inputFile>>file_v; //Q
    getline(inputFile,file_value);
    cout<<file_value<<endl;
    
    //inputFile>>file_v; //Ans1
    getline(inputFile,file_value);
    cout<<file_value<<endl;
    
    //inputFile>>file_v; //Ans2
    getline(inputFile,file_value);
    cout<<file_value<<endl;
    
    //inputFile>>file_v; //Ans3
    getline(inputFile,file_value);
    cout<<file_value<<endl;
    
    cout<<"Choose Answer by #: ";
    cin>>ans;
    

}

void Admin::show_user_results() {
    cout<<"Enter Survey Name: ";
    cin>>filename;
    filename = "RESULTS/" + filename + "_results.txt";
    inputFile.open(filename);
    
    inputFile>>file_value;
    cout<<file_value<<endl;
    
}

void Admin::show_user_accounts() {
    filename = "ACCOUNTS_N/account_names.txt";    
    inputFile.open(filename);
    
    cout<<endl<<"List of Accounts:"<<endl;
    
    inputFile>>file_value;
    cout<<file_value<<endl;
    
    inputFile>>file_value;
    cout<<file_value<<endl;
    
    inputFile>>file_value;
    cout<<file_value<<endl;
    
    inputFile>>file_value;
    cout<<file_value<<endl;

}
    


//public -----------------------------------------------------------------------

Admin::Admin(){
    text_file = "ADMIN/admin.txt";   
}
Admin::~Admin() {
    //delete []Admin;
}

void Admin::admin_menu() {
    std::cout<<"Admin Menu"<<std::endl;
    std::cout<<"0: Logout"<<std::endl;
    std::cout<<"1: View User Accounts"<<std::endl;
    std::cout<<"2: Create a Survey"<<std::endl;
    std::cout<<"3: Simulate Taking Survey"<<std::endl;
    std::cout<<"4: View Results"<<std::endl;
    std::cin>>choice;
    
    while (choice != 0) {
    switch(choice) {
        case 0: //exit
            //exit(0);
            break;
        case 1: // view user accounts
            show_user_accounts();
            break;             
        case 2: // create and remove questions
           create_survey();
            break;
        case 3: //simlutae taking survey
            simulate_taking_survey();
            break;
        case 4: // view results
          show_user_results();
            break;    
    }
    std::cout<<"Admin Menu"<<std::endl;
    std::cout<<"0: Logout"<<std::endl;
    std::cout<<"1: View/Modify Accounts"<<std::endl;
    std::cout<<"2: Create and Remove Questions"<<std::endl;
    std::cout<<"3: Simulate Taking Survey"<<std::endl;
    std::cout<<"4: View Results"<<std::endl;
    std::cin>>choice;
}
}


bool Admin::verify_admin() {
    
    bool state = false;
    bool state_u = false;
    bool state_p = false;
    
    for (int i=0; i<5; i++) {        
        std::cout<<"Enter Username: ";
        std::cin>>input_usern;
        std::cout<<"Enter Password: ";
        std::cin>>input_passwd;
        input_passwd_hash = sha256(input_passwd);
        
        inputFile.open(text_file);
        inputFile>>file_value;    
        if (input_usern == file_value){ //username check
            state_u = true;
        }
        else {
        }    
    
        inputFile>>file_value;
        if (input_passwd_hash == file_value){    //passwd check
            state_p = true;
        }
        else {
            //
        }    
        
        if (state_u == true && state_p == true) {
            state = true;
            std::cout<<std::endl<<"Access Granted"<<std::endl<<std::endl;
            break;
        }
        else {
            state = false;
            std::cout<<"Username or Password is incorrect"<<std::endl<<std::endl;
        }
        if (i == 4) {
            std::cout<<std::endl<<"Timed out . . ."<<std::endl<<std::endl;
        }
    }
        
    inputFile.close();
    
    return state;
}

