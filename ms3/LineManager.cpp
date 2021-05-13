// Name: Filipe da Cunha de Freitas
// Seneca Student ID: 155737190
// Seneca email: fda-cunha-de-freitas@gmyseneca.ca
// Date of completion: 2021-04-11
// Milestone 3
//
// I confirm that I am the only author of this file and the content was created entirely by me.

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "LineManager.h"
#include "Workstation.h"
#include "Utilities.h"

sdds::LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
{    
    std::ifstream infile(file);
    std::string line;
    
    int count = 0;
    bool firsItem = true;
    m_cntCustomerOrder = pending.size();

    while (std::getline(infile, line)) 
    {
        std::string::size_type pos = line.find('|');
        for (size_t item = 0; item < stations.size(); ++item)
        {
            if (stations.at(item)->getItemName() == line.substr(0, pos)) 
            {
                if (pos != std::string::npos) 
                {
                    for (size_t linkItem = 0; linkItem < stations.size(); ++linkItem)
                    {
                        if (stations.at(linkItem)->getItemName() == line.substr(pos + 1)) 
                        {
                            stations.at(item)->setNextStation(stations.at(linkItem));
                            activeLine.push_back(std::move(stations.at(item)));
                        }
                    }
                }
                else 
                {
                    activeLine.push_back(std::move(stations.at(item)));
                }
            }
        }
        for (size_t item = 0; item < activeLine.size(); ++item)
        {
            for (size_t linkItem = 0; linkItem < activeLine.size(); ++linkItem)
            {
                if (activeLine.at(linkItem)->getNextStation() != nullptr) 
                {
                    if (activeLine.at(item)->getItemName() == activeLine.at(linkItem)->getNextStation()->getItemName()) 
                    {
                        firsItem = false;
                    }
                }
            }
            if (firsItem) 
            {
                m_firstStation = activeLine.at(item);
            }
            firsItem = true;
        }
        count++;
    }
 }

void sdds::LineManager::linkStations() 
{
    std::vector<Workstation*> reOrderLine;
    Workstation* actualStation = m_firstStation;
    while (actualStation != nullptr) 
    {
        reOrderLine.push_back(actualStation);
        actualStation = actualStation->getNextStation();
    }
    activeLine = reOrderLine;
}

int countV = 1;
bool sdds::LineManager::run(std::ostream& os) 
{
    bool done = false;

    os << "Line Manager Iteration: " << countV << "\n";
    countV++;
    if (!pending.empty()) 
    { 
        *activeLine.front() += std::move(pending.front());
        pending.erase(pending.begin());
    }

    for (auto &i : activeLine) 
    {
        try 
        {
            i->fill(os);
        }
        catch (std::string err) 
        {

            std::cout << std::endl << err << std::endl;
            throw std::string("Not enough inventory available");
        }
    }
    
    for (auto &j : activeLine)
    {

        if (!j->attemptToMoveOrder()){

}   }

    if (completed.size() + incomplete.size() == m_cntCustomerOrder)
    {
        done = true;
    }

    for (auto &j : incomplete)
    {
        j.display(std::cout);
    }
    return done;
}

void sdds::LineManager::display(std::ostream& os) const
{
    for (size_t item = 0; item < activeLine.size(); ++item)
    {
        activeLine.at(item)->display(os);
        os << "\n";
    }
 }
