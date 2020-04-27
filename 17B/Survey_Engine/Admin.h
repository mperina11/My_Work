/* 
 * File:   Admin.h
 * Author: mperi
 *
 * Created on April 13, 2020, 2:39 PM
 */

#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include <list>
#include <vector>
#include <fstream> 

class Admin {
    
private:
    int choice; //menu choice
    int ans;    //survey answer
    std::ofstream outputFile; //write to file
    std::ifstream inputFile; //read from file
    std::string text_file;   //admin file
    std::string file_value;  //read val from file
    std::string input_usern, input_passwd, input_passwd_hash;  //input username and password
    std::string s_name, s_q, s_a1, s_a2, s_a3; //survey name, question, ans1,2,3
    std::string filename;   //name of file
        
    void create_survey();   //create a survey
    void simulate_taking_survey(); //simulate taking a survey
    
    void show_user_results();   //show results from survey
    void show_user_accounts();  //show all user accounts 
    
public:
    

    Admin();    
    virtual ~Admin();    

    void admin_menu();    //admin menu
    bool verify_admin();    //verify admin login


};

#endif /* ADMIN_H */

