#ifndef EMAIL_H
#define EMAIL_H
#include <string>
#include <iostream>


class Email {
private:
    std::string who;
    std::string date;
    std::string subject;

public:
    Email(std::string name, std::string date, std::string subject);
    ~Email();

    friend std::ostream& operator<< (std::ostream& os, const Email& obj);

    friend struct CompWhoDateSubject;
    friend struct CompDateWhoSubject;
    friend struct CompSubjectWhoDate;
};



#endif