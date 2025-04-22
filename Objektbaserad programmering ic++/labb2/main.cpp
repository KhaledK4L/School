#include "linked_list.h"
#include <iostream> 
#include <cstdlib> 

// Metod för att skriva ut listan i omvänd ordning
void print_list(linked_list l) { 
    l.print(); 
}

// Metod för att slå samman två sorterade listor
linked_list merge(linked_list &l1, linked_list &l2) {
    linked_list result; 
    while (!l1.is_empty() || !l2.is_empty()) { 
        if (l1.is_empty()) { 
            result.push_back(l2.pop_front()); 
        } else if (l2.is_empty()) { 
            result.push_back(l1.pop_front()); 
        } else { 
            result.push_back(l1.front() < l2.front() ? l1.pop_front() : l2.pop_front()); 
        }
    }
    return result;
}



// Kontrollerar om listan är sorterad
bool is_sorted(const linked_list& l) { 
    if (l.is_empty()) return true; 
    for (size_t i = 1; i < l.size(); i++) { 
        if (l.at(i - 1) > l.at(i)) return false; 
    }
    return true;
}




int main() {
    
    linked_list list1, list2; 
    for (int i = 0, val = 0; i < 10; ++i) { 
        val += rand() % 11; 
        list1.push_back(val); 
    }
    for (int i = 0, val = 0; i < 10; ++i) {
        val += rand() % 11; 
        list2.push_back(val); 
    }
    

    /*std::cout << "Första lista: "; list1.print();
    std::cout << "Andra lista: "; list2.print();*/


    if (list1.at(4) > list2.at(4)) { 
        list1.remove(4); 

        list2.remove(4); 
    }
    



    
    std::cout << "Första lista efter borttagning: ";
    list1.print();
    std::cout <<"\n====================\n" <<std::endl;
    linked_list list3 = list1.size() < list2.size() ? list1 : list2; 
    std::cout << "Andra lista efter borttagning: "; 
    list2.print();
    std::cout <<"\n====================\n" <<std::endl;
    
    list3.print_reverse(); 
    std::cout << "Den nya listan i omvänd ordning: ";
    list3.print_reverse();
    std::cout <<"\n====================\n" <<std::endl;
    
    for (int i = 0; i < 5; ++i) { 
        list1.pop_back();
        list1.push_front(list1.pop_back()); 
    }
    print_list(list1); 
    std::cout << "Listan efter att ha flyttat det sista elementet: "; 
    list1.print();
    std::cout <<"\n====================\n" <<std::endl;
    
    linked_list merged = merge(list1, list2);
    std::cout << "Slå samman listorna: ";
    merged.print(); 
    std::cout <<"\n====================\n" <<std::endl;
    
    //std::cout << "Merged List: "; merged.print();

    std::cout << "Merged List i omvänd ordning: "; 
    merged.print_reverse(); 
    std::cout <<"\n====================\n" <<std::endl;
    
    std::cout << "Är listan sorterad? " << (is_sorted(merged) ? "Ja" : "Nej") << std::endl; 
    return 0;
}
