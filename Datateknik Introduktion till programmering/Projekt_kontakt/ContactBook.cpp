#include "ContactBook.h"
#include <fstream>
#include <regex>
#include <algorithm>
#include <vector>


ContactBook::ContactBook() {
    loadFromFile();
}



ContactBook::~ContactBook() {
    saveToFile();
}



void ContactBook::saveToFile() {
    std::ofstream file((fileName)); 
    if (!file) {
        std::cout << "Fel: Det gick inte att öppna filen för att spara." << std::endl;
        return;
    }


    for (const auto& contact : contacts) {
        file << contact.förNamn << "\n" 
             << contact.efterNamn << "\n" 
             << contact.telefon << "\n" 
             << contact.address << "\n" 
             << contact.post << "\n" 
             << contact.födelsdag << "\n" 
             << contact.antackning << "\n\n";
    }

    file.close();
    std::cout << "Kontakter har sparats till " << fileName << "!" << std::endl;
}

   
    void ContactBook::loadFromFile() {
    std::ifstream file(fileName); 
    if (!file) return; 


    contacts.clear(); 
    Contact contact; 
    std::string line; 
    int lineCount = 0; 


        
    while (std::getline(file, line)) {
        if (line.empty()) {
            
            contacts.push_back(contact); 
            contact = Contact(); 
            lineCount = 0; 
        } else {
            
            switch (lineCount) {
                case 0: contact.förNamn = line; break;
                case 1: contact.efterNamn = line; break;
                case 2: contact.telefon = line; break;
                case 3: contact.address = line; break;
                case 4: contact.post = line; break;
                case 5: contact.födelsdag = line; break;
                case 6: contact.antackning = line; break;
            }
            lineCount++; 
        }
    }


    if (lineCount > 0) {
        contacts.push_back(contact);
    }

    file.close();
}

bool ContactBook::validatePost(const std::string &post)
{
     //hämtad från https://stackoverflow.com/questions/16200965/regular-expression-validate-gmail-addresses
    const std::regex postPattern("^[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,}$");
    return std::regex_match(post, postPattern);
    //slut hjälp
}

//hämtad ifrån https://stackoverflow.com/questions/273141/regex-for-numbers-only
bool ContactBook::validateTelfone(const std::string& telefon) {
    return std::all_of(telefon.begin(), telefon.end(), ::isdigit);
} //slut hjälp


bool ContactBook::validateDate(const std::string& date) {
    //hämtad ifrån https://www.regular-expressions.info/
    const std::regex datePattern("^\\d{4}-\\d{2}-\\d{2}$");
    return std::regex_match(date, datePattern);
} // slut hjälp


void ContactBook::addContact() {
    Contact contact;
    std::cout << "Ange förnamn: ";
    std::cin >> contact.förNamn;
    std::cout << "Ange efternamn: ";
    std::cin >> contact.efterNamn;

    do {
        std::cout << "Ange telefonesnummer: ";
        std::cin >> contact.telefon;
        if (!validateTelfone(contact.telefon)) {
            std::cout << "Ogiltigt telefonnummer. Ange endast siffror!." << std::endl;
        }
    } while (!validateTelfone(contact.telefon));

    std::cout << "Ange address: ";
    std::cin.ignore();
    std::getline(std::cin, contact.address);

    do {
        std::cout << "Ange E-post: ";
        std::cin >> contact.post;
        if (!validatePost(contact.post)) {
            std::cout << "Ogiltigt E-post. Försök igen med rätt E-post!." << std::endl;
        }
    } while (!validatePost(contact.post));

    do {
        std::cout << "Ange födelsdag (YYYY-MM-DD): ";
        std::cin >> contact.födelsdag;
        if (!validateDate(contact.födelsdag)) {
            std::cout << "Ogiltigt datumformat. Använd YYYY-MM-DD." << std::endl;
        }
    } while (!validateDate(contact.födelsdag));

    std::cout << "Ange ytterligare Antackningar: ";
    std::cin.ignore();
    std::getline(std::cin, contact.antackning);

    contacts.push_back(contact);
    std::cout << "Kontakten har lagts till!" << std::endl;
}


void ContactBook::listContacts() const {
    if (contacts.empty()) {
        std::cout << "Inga kontakter hittades." << std::endl;
        return;
    }

    for (const auto& contact : contacts) {
        contact.display();
    }
}

void ContactBook::searchContact(const std::string& query) const {
    std::string lowerQuery = query;
    std::transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(), ::tolower);

    bool found = false;

    for (const auto& contact : contacts) {

        std::vector<std::string> searchableFields = {
            contact.förNamn,
            contact.efterNamn,
            contact.address,
            contact.post,
            contact.telefon,
            contact.födelsdag,
            contact.antackning
        };

        for (auto& field : searchableFields) {
            std::string lowerField = field;
            std::transform(lowerField.begin(), lowerField.end(), lowerField.begin(), ::tolower);


            if (lowerField.find(lowerQuery) != std::string::npos) {
                contact.display();
                found = true;
                break; 
            }
        }
    }

    if (!found) {
        std::cout << "Inga matchande kontakter hittades." << std::endl;
    }
}



void ContactBook::deleteContact(const std::string& telefon) {
    bool contactFound = false;

    auto it = std::remove_if(contacts.begin(), contacts.end(), [&telefon, &contactFound](const Contact& c) {
        if (c.telefon == telefon) {
            contactFound = true;
            return true; 
        }
        return false; 
    });

    if (contactFound) {
        contacts.erase(it, contacts.end()); 
        saveToFile(); 
        std::cout << "Kontakten har tagits bort!" << std::endl;
    } else {
        std::cout << "Ingen kontakt hittades med det telefonnumret." << std::endl;
    }
}