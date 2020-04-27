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

using namespace std;

//private -----------------------------------------------------------------------

void Admin::show_user_accounts() {
    ifstream inputFile;
    string filename, file_v;
    filename = "ACCOUNTS_N/account_names.txt";    
    inputFile.open(filename);
    
    cout<<endl<<"List of Accounts:"<<endl;
    
    inputFile>>file_v;
    cout<<file_v<<endl;
    
    inputFile>>file_v;
    cout<<file_v<<endl;
    
    inputFile>>file_v;
    cout<<file_v<<endl;
    
    inputFile>>file_v;
    cout<<file_v<<endl;
}

void Admin::admin_add_product() { //add & remove products
    std::string name, price, push_b;
    std::cout<<std::endl<<"Add Products"<<std::endl;    
    std::cout<<"Enter product name: ";
    std::cin.ignore();
    getline(std::cin, name);
    std::cout<<"Enter product price: ";
    std::cin>>price;
    std::cout<<std::endl;
    price = price + ": ";
    push_b = price + name;
    //products.push_back(push_b);
    
    ofstream outFile;
    outFile.open("PRODUCTS/products.txt", std::ios::app); //to append
    outFile<<endl<<push_b;
    
}

void Admin::admin_remove_product() {
    
    std::string ss, file_v;
    std::cout<<"Choose product to remove by number: ";
    std::cin>>ss;
        
    ifstream inputFile;
    inputFile.open("PRODUCTS/products.txt");
    for(int i=0; i<10; i++) {
    inputFile>>file_v;
        if (file_v == ss) {
            //delete line
            cout<<"Removed: "<<ss<<std::endl;
        }
    }
}

void Admin::admin_listings() { //display product listings
    std::cout<<std::endl<<"Product Listings"<<std::endl;
    std::string ss, file_v;
    ifstream inputFile;
    inputFile.open("PRODUCTS/products.txt");
    for(int i=0; i<10; i++) {
        getline(inputFile,file_v);
        cout<<endl<<file_v<<endl;

    }    
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
    std::cout<<"1: View/Modify Accounts"<<std::endl;
    std::cout<<"2: Create Product Listing"<<std::endl;
    std::cout<<"3: Remove Product Listing"<<std::endl;
    std::cout<<"4: View Listing"<<std::endl;
   // std::cout<<"5: View Order Statuses"<<std::endl;
    std::cin>>choice;
    
    while (choice != 0) {
    switch(choice) {
        case 0: //exit
            std::cout<<"Return";
            //exit(0);
            break;
        case 1: // view/modify accounts
            show_user_accounts();
            break;             
        case 2: // create product listing
            admin_add_product();
            break;
        case 3: //remove product
            admin_remove_product();
            break;
        case 4: // view listing
            admin_listings();            
            break;    
//        case 5: // view order statuses
//            admin_order_status();
//            break;
    }
    std::cout<<"Admin Menu"<<std::endl;
    std::cout<<"0: Logout"<<std::endl;
    std::cout<<"1: View/Modify Accounts"<<std::endl;
    std::cout<<"2: Create Product Listing"<<std::endl;
    std::cout<<"3: Remove Product Listing"<<std::endl;
    std::cout<<"4: View Listing"<<std::endl;
   // std::cout<<"5: View Order Statuses"<<std::endl;
    std::cin>>choice;
}
}


bool Admin::verify_admin() {
    
    std::ifstream inputFile;
    std::string input_passwd_hash; //passwd input hashed
    
    
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
            //cout<<"U: check"<<endl;
            state_u = true;
        }
        else {
            //cout<<"U:  fail"<<endl;
        }    
    
        inputFile>>file_value;
        if (input_passwd_hash == file_value){    //passwd check
            //cout<<"P: check"<<endl;
            state_p = true;
        }
        else {
        //cout<<"P:  fail"<<endl;
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