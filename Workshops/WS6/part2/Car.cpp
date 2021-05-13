/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-03-06
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#include <cctype>
#include <iostream>
#include <iomanip>
#include "Car.h"

namespace sdds {

    Car::Car(std::istream &fin) 
    {
        std::string tag;
        std::string speed;
        std::string condition;
        bool digital = true;
        getline(fin, tag, ',');
        getline(fin, m_maker, ',');
        getline(fin, condition, ',');
        getline(fin, speed, ',');

        m_maker.erase(0, m_maker.find_first_not_of(' '));
        m_maker.erase(m_maker.find_last_not_of(' ')+1);
        condition.erase(0, condition.find_first_not_of(' '));
        condition.erase(condition.find_last_not_of(' ')+1);
        speed.erase(0, speed.find_first_not_of(' '));
        speed.erase(speed.find_last_not_of(' ')+1);

        if(condition.empty() || condition[0] == ' ')
        {
            m_condition = 'n';
        } 
        else if(condition[0] == 'n' || condition[0] == 'u' || condition[0] == 'b')
        {
            m_condition = condition[0];
        } 
        else
        {
            std::string err = "Invalid record!";
            throw err;
        }

        for(int tmp : speed)
        {
            if(tmp < 48 || tmp > 57)
            {
                digital = false;
                break;
            }
        }
        if(digital) 
        {
            m_topSpeed = std::stod(speed);
        } 
        else
        {
            std::string err = "Invalid record!";
            throw err;
        }
    }

    std::string Car::condition() const 
    {
        std::string con;
        switch (m_condition) 
        {
            case 'n':
                con.assign("new");
                break;
            case 'u':
                con.assign("used");
                break;
            case 'b':
                con.assign("broken");
                break;
        }
        return con;
    }

    double Car::topSpeed() const 
    {
        return m_topSpeed;
    }

    void Car::display(std::ostream &out) const 
    {
        out << "| ";
        out << std::right << std::setw(10) << m_maker << " | ";
        out << std::left << std::setw(6) << condition() << " | ";
        out << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed();
        out << " |";
    }


}
