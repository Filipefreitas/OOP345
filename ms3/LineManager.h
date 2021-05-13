// Name: Filipe da Cunha de Freitas
// Seneca Student ID: 155737190
// Seneca email: fda-cunha-de-freitas@gmyseneca.ca
// Date of completion: 2021-04-11
// Milestone 3
//
// I confirm that I am the only author of this file and the content was created entirely by me.

#ifndef LINEMANAGER_H
#define LINEMANAGER_H
#include <vector>
#include "Workstation.h"

namespace sdds 
{
    class LineManager 
    {
        std::vector<Workstation*> activeLine;
        size_t m_cntCustomerOrder;
        Workstation* m_firstStation;

    public:
        explicit LineManager(const std::string& file, const std::vector<Workstation*>& stations);
        void display(std::ostream& os) const;
        void linkStations();
        bool run(std::ostream& os);
    };
}

#endif 
