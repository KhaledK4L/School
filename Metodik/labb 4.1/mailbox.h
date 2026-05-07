#ifndef MAILBOX_H
#define MAILBOX_H

#include <iostream>
#include <vector>
#include "email.h"
class mailBox {
private:
    std::vector<Email> emailContainer;
    
public:
    mailBox(std::size_t n); //konstruktör med storlek
    mailBox(std::vector<Email> emailContainer); 
    ~mailBox();//destruktör

    std::vector<Email>& SortWho(); //sortera efter avsändare
    std::vector<Email>& SortDate();//sortera efter datum
    std::vector<Email>& SortSubject();//sortera efter ämne

    void write(Email msg);//lägg till email i mailbox 
    std::vector<Email> read();//läs email från mailbox
};
#endif