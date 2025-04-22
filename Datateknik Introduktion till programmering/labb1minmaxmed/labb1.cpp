
/*
#! c/c++
#Filnamn: labbminmaxmed, labb1.cpp
#Skrivet av: Khaled Hamza
#Skapat datum: 2024-11-23
#Ändrad senaste: 2024-11-26
#Kurs: datateknik introduktion till programmering
#Handledare: Nayeb Maleki and Jan-Erik Jonsson.
#Beskrivning: Detta program tar emot maximlt och minimalt värde sedan skriver ut summan och medelvärdet.
*/

#include <iostream>


int main() 
{

    int value, minimala, maximala, antal= 0, sum= 0;   
    

     std::cout<< "Skriv in den maximala och minimala och avsluta med enter och ctrl + D" <<std::endl;
    
    
    while (std::cin >> value)
    {
        sum+=value; 
        antal++; 

      
        if(antal == 1) {
           minimala = maximala = value;
        }

        if ( maximala < value){

            maximala = value;
        }

        if ( minimala > value )
        {
            minimala = value;   
        }
        

    }
    if(antal>0){
        std::cout << "maximala = "  << maximala << std::endl;
        std::cout << "minimala = " << minimala << std::endl;
        std::cout << "summan = " <<  maximala + minimala << std::endl;
        std::cout << "medelvärdet = " << static_cast<double>(sum)/antal << std::endl;
         } else {
            std::cout << "Inget värde inmatat." << std::endl;
            return 0;
        }
}