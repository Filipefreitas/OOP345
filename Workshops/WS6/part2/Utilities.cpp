/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-03-06
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/
#include "Utilities.h"

namespace sdds {
    Vehicle *createInstance(std::istream &in) 
    {
        Vehicle *ptr = nullptr;
        std::string temp;
        getline(in, temp);
        temp.erase(0, temp.find_first_not_of(' '));
        std::stringstream line(temp);
        if (!temp.empty()) 
        {
            if (temp[0] == 'c' || temp[0] == 'C') 
            {
                ptr = new Car(line);
            } 
            else if(temp[0] == 'r' || temp[0] == 'R') 
            {
                ptr = new Racecar(line);
            }
            else 
            {
                std::string tag{};
                getline(line, tag, ',');
                throw "Unrecognized record type: [" + tag + "]";
            }
        } 
        else
        {
            ptr = nullptr;
        }
        return ptr;
    }
}