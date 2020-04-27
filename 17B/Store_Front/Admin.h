/* 
 * File:   Admin.h
 * Author: mperi
 *
 * Created on April 13, 2020, 2:39 PM
 */

#ifndef ADMIN_H
#define ADMIN_H
#include <string>

class Admin {
private:
    int choice;
    std::string usern, passwd, text_file, file_value, input_usern, input_passwd;
    
    void show_user_accounts();  //show user accounts
    void admin_add_product();   //add new product
    void admin_remove_product(); //remove product
    void admin_listings();  //view product listing
    void admin_order_status();  //view order status

public: 
    Admin();    
    virtual ~Admin();    //desctructor
    void admin_menu();    //admin menu
    bool verify_admin();    //verify admin login
};

#endif /* ADMIN_H */

