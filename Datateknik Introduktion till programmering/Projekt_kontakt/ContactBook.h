#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include "Contact.h"
#include <vector>
#include <string>

class ContactBook {
private:
    std::vector<Contact> contacts; 
    const std::string fileName = "Contacts_lista.txt"; 

public:
   
    void saveToFile(); 
    void loadFromFile(); 

    
    bool validatePost(const std::string& post); 
    bool validateTelfone(const std::string& telefon); 
    bool validateDate(const std::string& date); 

public:
    
    ContactBook(); 
    ~ContactBook(); 

    
    void addContact(); 
    void listContacts() const; 
    void searchContact(const std::string &query) const; 
    void deleteContact(const std::string& telefon); 
};

#endif
