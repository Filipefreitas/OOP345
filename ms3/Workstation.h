// Name: Filipe da Cunha de Freitas
// Seneca Student ID: 155737190
// Seneca email: fda-cunha-de-freitas@gmyseneca.ca
// Date of completion: 2021-04-11
// Milestone 3
//
// I confirm that I am the only author of this file and the content was created entirely by me.

#ifndef WORKSTATION_H
#define WORKSTATION_H

#include <ostream>
#include "CustomerOrder.h"
#include "Station.h"
#include <vector>
#include <deque>
extern std::vector<CustomerOrder> pending;
extern std::vector<CustomerOrder> completed;
extern std::vector<CustomerOrder> incomplete;

namespace sdds 
{
    class Workstation : public Station
    {
    private:
        Workstation* m_pNextStation = nullptr;
        std::vector<CustomerOrder> m_orders;
    public:
        explicit Workstation(const std::string& name);
        void fill(std::ostream &os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation* station);
        void display(std::ostream& os) const;
        Workstation* getNextStation() const;
        Workstation& operator+=(CustomerOrder&& newOrder);
        Workstation& operator=(const Workstation&) = delete;
    };
}

#endif
