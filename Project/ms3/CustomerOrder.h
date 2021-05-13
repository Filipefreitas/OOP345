// Name: Filipe da Cunha de Freitas
// Seneca Student ID: 155737190
// Seneca email: fda-cunha-de-freitas@gmyseneca.ca
// Date of completion: 2021-04-11
// Milestone 3
//
// I confirm that I am the only author of this file and the content was created entirely by me.

#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

#include <utility>
#include "Station.h"

struct ItemInfo
{
    std::string m_itemName;
    unsigned int m_serialNumber{0};
    bool m_fillState{false};

    ItemInfo(std::string src) : m_itemName(std::move(src)) {};
};

class CustomerOrder
{
    std::string m_name;
    std::string m_product;

    ItemInfo** m_listItem{};
    static size_t m_widthField;

public:
    unsigned int m_cntItem{};

    CustomerOrder();
    explicit CustomerOrder(const std::string&);
    CustomerOrder(CustomerOrder&);
    CustomerOrder& operator=(CustomerOrder&) = delete;
    CustomerOrder(CustomerOrder&&) noexcept;   
    CustomerOrder& operator=(CustomerOrder&&) noexcept; 
    ~CustomerOrder();

    bool isItemFilled(const std::string&) const;
    bool isFilled() const;
    void fillItem(sdds::Station& station, std::ostream&) const; 
    void display(std::ostream& os) const;
};

#endif 