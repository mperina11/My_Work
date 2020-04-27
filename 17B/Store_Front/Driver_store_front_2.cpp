/* 
 * File:   Driver_store_front_2.cpp
 * Author: mperi
 *
 * Created on April 19, 2020, 9:16 AM
 */

#include <cstdlib>
#include <iostream>
#include "Admin.h"
#include "User.h"

using namespace std;


int main() {
    Admin* A = new Admin;
    User* U = new User;
    int choice;
    
    while(true){
        std::cout<<"Welcome to Store Front"<<std::endl; //main menu .
        std::cout<<"0: exit"<<std::endl;
        std::cout<<"1: customer"<<std::endl;
        std::cout<<"2: admin"<<std::endl;
        std::cin>>choice;    

        if(choice==0){
            std::cout<<"Exiting . . . Goodbye"; //exit
            exit(0);
        }
        if(choice==1){
            U->customer_menu(); //customer menu
            
        }
        if(choice==2){
            if(A->verify_admin()){    //login/verify admin                             
                A->admin_menu();      //admin menu
                
            }
            else {
                //
            }
            
    }
  }
    
    delete []A; //delete objects
    delete []U;
    return 0;
}

