// Name: Filipe da Cunha de Freitas
// Seneca Student ID: 155737190
// Seneca email: fda-cunha-de-freitas@gmyseneca.ca
// Date of completion: 2021-04-11
// Milestone 3
//
// I confirm that I am the only author of this file and the content was created entirely by me.

#include "Workstation.h"

std::vector<CustomerOrder> pending = std::vector<CustomerOrder>();
std::vector<CustomerOrder> completed = std::vector<CustomerOrder>();
std::vector<CustomerOrder> incomplete = std::vector<CustomerOrder>();

void sdds::Workstation::fill(std::ostream& os) 
{
    if (!m_orders.empty()) {
        m_orders.begin()->fillItem(*this, os);
    }
}

bool check = false;
bool sdds::Workstation::attemptToMoveOrder() 
{

    if (!m_orders.empty()) 
    {
        if (m_pNextStation != nullptr)
        {

            if (m_orders.front().isItemFilled(getItemName()))
            {

                *m_pNextStation += std::move(m_orders.front());
                m_orders.erase(m_orders.begin());
            }
        }
        else
        {
            if (m_orders.front().isFilled())
            {
                completed.push_back( std::move(m_orders.front()));
                m_orders.erase(m_orders.begin());
            }
            else
            {
                if(check)
                {
                    incomplete.push_back( std::move(m_orders.front()));
                    m_orders.erase(m_orders.begin());
                    check = false;
                }
                else
                {
                    check = true;
                }
            }
        }
        return true;
    }
    else 
    {
        return false;
    }
}

void sdds::Workstation::setNextStation(sdds::Workstation* station) 
{
    m_pNextStation = station;
}

sdds::Workstation* sdds::Workstation::getNextStation() const 
{
    return m_pNextStation;
}

void sdds::Workstation::display(std::ostream& os) const 
{
    os << getItemName() << " --> ";

    if (m_pNextStation != nullptr) 
    {
        os << m_pNextStation->getItemName();
    }
    else 
    {
        os << "End of Line";
    }
}

sdds::Workstation& sdds::Workstation::operator+=(CustomerOrder&& newOrder) 
{
    m_orders.push_back(std::move(newOrder));
    return *this;
}

sdds::Workstation::Workstation(const std::string& name) : Station(name) 
{
}
