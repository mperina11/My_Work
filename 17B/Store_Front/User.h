/* 
 * File:   User.h
 * Author: mperi
 *
 * Created on April 13, 2020, 2:39 PM
 */

#ifndef USER_H
#define USER_H
#include <string>
#include <iterator>
#include "Admin.h"

class User : public Admin{ //inherit from Admin
private:
    double Total;
    std::string name;
    int choice;
    
    void user_create_account(); //create account
    bool user_existing_account(); //existing user
   
public:    
    User();
    ~User();
    void customer_menu();  //customer menu
    void store_menu();  //store menu
    void listings();  //view product listing
    void view_cart();  //view cart and checkout
    void remove_cart(); //remove item from cart
    void checkout();    //checkout
    double get_Total(); //get total

};

#endif /* USER_H */

