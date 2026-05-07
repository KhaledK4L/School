#include <iostream>
#include "email.h"
#include "mailbox.h"
#include <vector>
//
void show(std::vector<Email> box) {
    for (auto e : box) {
        std::cout << e << "\n";
    }
    std::cout << "\n";
}


int main() {

    std::vector<Email> cont;
    Email mail1("Alfred", "2018-5-6", "Labb1");
    Email mail3("Guru", "2022-11-18", "Labb1");
    Email mail2("Alfred", "2018-5-6", "Labb2");

    cont.push_back(mail1);
    cont.push_back(mail2);
    cont.push_back(mail3);

    mailBox mailbox(cont);


    show(mailbox.read());

    mailbox.write({ "Khaled", "2019-1-22", "Grade" });
    mailbox.write({ "Zabata", "2017-3-30", "Grade" });
    mailbox.write({ "Martin", "2014-1-22", "Assignment" });
    mailbox.write({ "Dido", "2019-1-22", "Response" });
    mailbox.write({ "Stan", "2005-12-24", "Merry Chrismtas" });

    show(mailbox.read());

    //mailbox.SortDate();
    //mailbox.SortSubject();
    mailbox.SortWho();
    show(mailbox.read());


    return 0;
}