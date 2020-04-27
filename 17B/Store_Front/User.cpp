/* 
 * File:   User.cpp
 * Author: mperi
 * 
 * Created on April 13, 2020, 2:39 PM
 */
#include <iostream>
#include "User.h"
#include <fstream> 
#include <string>
#include <algorithm>
#include "sha256.h"

using namespace std;

User::User() {    
//   
}

User::~User() {
    //delete User;   
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
    text_file = "ACCOUNTS/" + usern + ".txt"; //creates new user file
    outputFile.open(text_file);
    passwd_hash = sha256(passwd);   //hashes password with SHA256
        
    outputFile<<usern<<endl;
    outputFile<<passwd_hash<<endl; //write to file
    
    //adds user to user accounts list
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

void User::customer_menu() {  
    bool state = true;
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
                store_menu();
            }
            else {
                //
            }
            break;
    }
    
    } while(state);
}

void User::store_menu(){   
    bool state = true;
    do {
    std::cout<<"Store Menu"<<std::endl;
    std::cout<<"0: Logout"<<std::endl;
    std::cout<<"1: View/Select Product"<<std::endl;    
    std::cout<<"2: View Cart/Checkout"<<std::endl;    
    std::cin>>choice;
    
    switch(choice) {
        case 0: //exit
            state = false;
            break;
        case 1:                 //list and add to cart
            listings();
            break;
        case 2:       
            view_cart();    //view cart and remove from cart and checkout     
            break;        
    }
    
    } while(state);
}


void User::listings() { //view product listing
    std::cout<<std::endl<<"Product Listings"<<std::endl;

    string ss, file_v, usern;
    ifstream inputFile;
    inputFile.open("PRODUCTS/products.txt");
    for(int i=1; i<10; i++) {
        getline(inputFile,file_v);
        cout<<i<<": "<<file_v<<endl;
    }    
    
    int sentinel;
    do {
    cout<<"You can add a product to your cart by entering its #"<<endl;
    cout<<"You can exit by entering -1"<<endl;
    cin>>sentinel;
   
    
    if(sentinel>0){
         cout<<"Enter username: ";
        cin>>usern;
        usern = "CARTS/" + usern + ".txt";
        ofstream outFile;
        outFile.open(usern, std::ios::app);
        
        for(int i=1; i<10; i++) {
            getline(inputFile,file_v);
            if(sentinel == i){
                outFile<<file_v<<endl;                                    
            }            
        } 
    }
    
    cout<<endl;
    } while (sentinel != -1);
}  

void User::view_cart() { //view cart and checkout
    std::cout<<std::endl<<"Items in Cart"<<std::endl;
    ifstream inputFile;
    string file_v, usern;
    int i=1;
    double total=0;
    double d_token;
    string token;
    string delimiter = ":";
    
    cout<<"Enter username: ";
    cin>>usern;            
    usern="CARTS/" + usern + ".txt";
    inputFile.open(usern);
    
    for(int i=0; i<10; i++) {
    getline(inputFile,file_v);
    cout<< " $" << file_v  <<endl;  
    token = file_v.substr(0, file_v.find(delimiter));
    d_token = atof(token.c_str());
    total += d_token;
    }
    
    cout<<"Total: $"<<total<<endl<<endl;
    
    int c;
    cout<<"To remove item from cart enter 1:"<<endl;
    cout<<"To checkout enter 2:"<<endl;
    cout<<"To exit cart enter -1:"<<endl;
    cin>>c;
    
    switch(c){
        case 1:
            remove_cart();
            break;
            
        case 2:
            checkout();
            break;
            
        default:
            break;
            
    }
    
}

 void User::remove_cart() {
    int s;
    std::string ss;
    do {
    std::cout<<"To exit enter -1"<<endl;    
    std::cout<<"Choose product to remove by number: ";
    std::cin>>s;
    if (s>0) {
     
    std::cout<<"Removed: "<<ss<<std::endl<<endl;
    }
 } while (s != -1);
 } 
 
 void User::checkout() {
     string credit_card, exp_date, code_back, name_on_card;
     string b_city, b_state, b_street, b_zip_code;
     string s_city, s_state, s_street, s_zip_code;
     
     cout<<"Enter your credit card number: ";
     cin>>credit_card;
     cout<<"Enter credit card expiration date: ";
     cin>>exp_date;
     cout<<"Enter 3 digit security code (on back): ";
     cin>>code_back;
     cout<<"Enter the full name on card: ";
     std::cin.ignore();
     getline(std::cin, name_on_card);
     
     
     cout<<endl<<"Billing address"<<endl<<endl;
     cout<<"City: ";
     cin>>b_city;
     cout<<"State: ";
     cin>>b_state;
     cout<<"Street address: ";
     std::cin.ignore();
     getline(std::cin, b_street);
     cout<<"zipcode: ";
     cin>>b_zip_code;
     
     string s;
     cout<<"Is your shipping address the same as your billing address? Y/N: ";
     cin>>s;
     
     if(s=="y" || s=="Y"){
         s_city = b_city;
         s_state = b_state;
         s_street = b_street;
         s_zip_code = b_zip_code;         
     }
     else {
          cout<<endl<<"Shipping address"<<endl<<endl;
     cout<<"City: ";
     cin>>s_city;
     cout<<"State: ";
     cin>>s_state;
     cout<<"Street address: ";
     std::cin.ignore();
     getline(std::cin, s_street);
     cout<<"zipcode: ";
     cin>>s_zip_code;
     }
     
     string confirm;
     cout<<endl<<"Your total is: $"<<get_Total()<<endl;
     cout<<"Confirm your purchase: Y/N: "; 
     cin>>confirm;
     
     if(confirm=="y" || confirm=="Y"){
         cout<<endl<<"Thank you, your order is being processed"<<endl<<endl;
         //process order 
     }
     else {
         cout <<"Order canceled"<<endl;
         //delete info and exit
     }
     
 }
    
 double User::get_Total() {
    ifstream inputFile;
    int i=1;
    double total=0;
    double d_token;
    string token, file_v;
    string delimiter = ":";
    
    for(int i=0; i<10; i++) {
    inputFile>>file_v;
    cout<< " $" << file_v  <<endl;  
    token = file_v.substr(0, file_v.find(delimiter));
    d_token = atof(token.c_str());
    total += d_token;
    }
    
    Total = total;
    return Total;
 }