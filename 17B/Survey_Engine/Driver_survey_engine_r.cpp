/* 
 * File:   Driver_survey_engine_r.cpp
 * Author: mperi
 *
 * Created on April 21, 2020, 2:16 PM
 */

#include <cstdlib>
#include <iostream>

#include "Admin.h"
#include "User.h"

using namespace std;

int main() {

    Admin* A = new Admin; //new objects .
    User* U = new User;
    int choice;
    
    while(true){
        std::cout<<"Welcome to the Survey Engine"<<std::endl; //main menu
        std::cout<<"0: exit"<<std::endl;
        std::cout<<"1: customer"<<std::endl;
        std::cout<<"2: admin"<<std::endl;
        std::cin>>choice;    

        if(choice==0){
            std::cout<<"Exiting . . . Goodbye"; //exit
            exit(0);
        }
        if(choice==1){
            U->user_menu(); //user menu
            
        }
        if(choice==2){
            if(A->verify_admin()){    //login and verify admin         
                A->admin_menu();    //admin menu
                
            }
            else {
                //
            }
            
    }
  }
    
    A->~Admin(); //delete objects 
    U->~User();
    return 0;
}

