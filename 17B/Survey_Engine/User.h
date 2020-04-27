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
#include <list>
#include "Admin.h"

class User : public Admin{ //inherit from Admin
    
private:
    void user_create_account(); //create new account
    bool user_existing_account();   //have existing account
    void survey_menu(); //show survey menu
    void take_survey(); //take a survey

public:    
    User();
    ~User();
    
    void user_menu(); //show user menu


};

#endif /* USER_H */