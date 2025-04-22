#include "linked_list.h"
#include <iostream>



// initierar värdet och pekarna till nästa och föregående nod
linked_list::node::node(double value) { 
    this->value = value; 
    this->next = nullptr; 
    this->prev = nullptr; 
}



// initierar head och tail till nullptr 
linked_list::linked_list() {
    head = nullptr; 
    tail = nullptr;
} 


//kopierar värden från src till den nya listan, skapar en djup kopia av listan genom att iterera över varje nod i src och lägga till dess värde i den nya listan.
linked_list::linked_list(const linked_list &src) : head(nullptr), tail(nullptr) {
    node *current = src.head;  
while (current) { 
         
        push_back(current->value);  
        current = current->next;  
    } 
}
 
 //rensar minnet genom att ta bort alla noder i listan, en i taget tills listan är tom.
linked_list::~linked_list() { 
    while (!is_empty()) {
        pop_front(); 
    }
}


// kopierar värden från rhs till den aktuella listan
linked_list &linked_list::operator=(const linked_list &rhs) { 
    if (this != &rhs) { 
        
        while (!is_empty()) { 
            pop_front(); 
        }
        node *current = rhs.head; 
         
        while (current) { 
            
            push_back(current->value); 
            current = current->next; 
        }
    }
    return *this; 
}






// lägger till värdena från rhs i den aktuella listan
linked_list &linked_list::operator+=(const linked_list &rhs) { 
    node *current = rhs.head; 
    
    while (current) { 
        push_back(current->value); 
        current = current->next; 
    }
    return *this;
}





// Metod för att infoga ett värde på en specifik position i listan
void linked_list::push_front(double value) { 
    node *new_node = new node(value); 
    new_node->next = head;  
    if (head) head->prev = new_node; 
    head = new_node; 
    if (!tail) tail = head; 
}



// Metod för att infoga ett värde i slutet av listan
void linked_list::push_back(double value) { 
    node *new_node = new node(value); 
    new_node->prev = tail; 
    if (tail) tail->next = new_node;
    tail = new_node; 
    if (!head) head = tail;
}



// Metod för att infoga ett värde på en specifik position i listan
void linked_list::insert(double value, size_t pos) {
    if (pos == 0) {
        push_front(value);
        return;
    }
    if (pos >= size()) {
        push_back(value);
        return;
    }

    node* new_node = new node(value);
    node* current = head;

    for (size_t i = 0; i < pos - 1; ++i) {
        current = current->next;
    }

    new_node->next = current->next;
    new_node->prev = current;

    if (current->next) {
        current->next->prev = new_node;
    }

    current->next = new_node;

    if (new_node->next == nullptr) {
        tail = new_node;
    }
}





// Metod för att infoga ett värde på en specifik position i listan
double linked_list::front() const {
    if(head !=nullptr) {
        return head->value; 
    } else {
        return 0; 
    }

}


// Metod för att hämta värdet på den sista noden i listan
double linked_list::back() const {
    if(tail !=nullptr) {
        return tail->value; 
    } else {
        return 0; 
    }
}





// Metod för att hämta värdet på en specifik position i listan
double linked_list::at(size_t pos) const { 
    node *current = head; 
    size_t i =0;  
    while (current && i < pos) { 
        current = current->next; 
        i++; 
    }
    if (current  ) { 
        return current->value; 
    } else {
        return 0; 
    }
}




// Metod för att hämta storleken på listan
size_t linked_list::size() const {  
    size_t count = 0; 
    node *current = head;  
    while (current) { 
        count++;
        current = current->next;  
    }
    return count; 
}





// Metod för att kontrollera om listan är tom
bool linked_list::is_empty() const { 
    if (head == nullptr) { 
        return true; 
    } else {
        return false; 
    }
    
}





// Metod för att skriva ut listan
void linked_list::print() const { 
    node *current = head; 
    while (current) { 
        std::cout << current->value << " "; 
        current = current->next; 
    }
    //std::cout << std::endl;
}



// Metod för att skriva ut listan i omvänd ordning
void linked_list::print_reverse() const {
    node *current = tail; 
    while (current) {
        std::cout << current->value << " "; 
        current = current->prev; 
    }
    //std::cout << std::endl;
}




// Metod för att ta bort den första noden i listan och returnera dess värde
double linked_list::pop_front() { 
    if (!head) return 0; 
    double value = head->value; 
    node *temp = head; 
    head = head->next; 
    if (head) head->prev = nullptr; 
    else tail = nullptr; 
    delete temp; 
    return value; 
}

// Metod för att ta bort den sista noden i listan och returnera dess värde
double linked_list::pop_back() { 
    if (!tail) return 0;    
    double value = tail->value; 
    node *temp = tail; 
    tail = tail->prev; 
    if (tail) tail->next = nullptr; 
    else head = nullptr; 
    delete temp; 
    return value; 
}





// Metod för att ta bort en nod på en specifik position i listan
void linked_list::remove(size_t pos) { 
    if (pos >= size()) return; 
    if (pos == 0) { 
        pop_front();
        return; 
    }
    // om positionen är den sista noden, ta bort den sista noden
    node *current = head; 
    for (size_t i = 0; i < pos; ++i) { 
        current = current->next; 
    }
    if (current->prev) current->prev->next = current->next;
    if (current->next) current->next->prev = current->prev; 
    if (current == tail) tail = current->prev; 
    delete current; 
}
