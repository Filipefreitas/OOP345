// Name: Filipe da Cunha de Freitas
// Seneca Student ID: 155737190
// Seneca email: fda-cunha-de-freitas@gmyseneca.ca
// Date of completion: 2021-04-11
// Milestone 3
//
// I confirm that I am the only author of this file and the content was created entirely by me.

#include <iostream>
#include <string>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"
#include "Station.h"

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder()
{
	m_name = "default";
	m_product = "default";
	m_listItem = nullptr;
	m_widthField = 0u;
}

CustomerOrder::CustomerOrder(const std::string& str)
{
	sdds::Utilities util;
	auto more = true;
	size_t next_pos = 0;

	m_name = util.extractToken(str, next_pos, more);
	m_product = util.extractToken(str, next_pos, more);
	m_cntItem = 0;

	auto start_pos = next_pos;

	while (more)
	{
		util.extractToken(str, next_pos, more);
		m_cntItem++;
	}

	m_listItem = new ItemInfo * [m_cntItem];

	more = true;

	for (size_t i = 0; i < m_cntItem; i++)
	{
		m_listItem[i] = new ItemInfo(util.extractToken(str, start_pos, more));
	}

	if (util.getFieldWidth() > m_widthField)
		m_widthField = util.getFieldWidth();
}

CustomerOrder::CustomerOrder(CustomerOrder&)
{
	std::string err_mess = "A CustomerOrder object should not allow copy operations";
	throw err_mess;
}

CustomerOrder::CustomerOrder(CustomerOrder&& co) noexcept
{
	*this = std::move(co);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
{
	if (&src != this)
	{
		if (m_listItem)
			for (unsigned int i = 0; i < m_cntItem; i++)
				delete this->m_listItem[i];

		delete[] this->m_listItem;

		this->m_name = src.m_name;
		this->m_product = src.m_product;
		this->m_cntItem = src.m_cntItem;
		this->m_listItem = src.m_listItem;

		src.m_listItem = nullptr;
	}

	return *this;
}

CustomerOrder::~CustomerOrder()
{
	if (m_listItem)
		for (unsigned int i = 0; i < m_cntItem; i++)
			delete m_listItem[i];

	delete[] m_listItem;
	m_listItem = nullptr;
}

bool CustomerOrder::isItemFilled(const std::string& str) const
{
	for (unsigned int i = 0; i < m_cntItem; i++)
		if (m_listItem[i]->m_itemName == str)
			return m_listItem[i]->m_fillState;

	return true;
}

bool CustomerOrder::isFilled() const
{
	for (unsigned int i = 0; i < m_cntItem; i++)
	{
		if (!m_listItem[i]->m_fillState)
			return false;
	}
	return true;
}

void CustomerOrder::fillItem(sdds::Station& station, std::ostream& os)  const
{
	for (size_t i = 0; i < m_cntItem; i++) 
	{
		if (m_listItem[i]->m_itemName == station.getItemName() && m_listItem[i]->m_fillState == false)
		{
			m_listItem[i]->m_fillState = true;
			m_listItem[i]->m_serialNumber = station.getNextSerialNumber();
			station.updateQuantity();
			os <<  std::setw(m_widthField - 6) << std::right << (m_listItem[i]->m_fillState ? "Filled" : "Unable to fill") <<
				" " << this->m_name << ", " << this->m_product << " [" << m_listItem[i]->m_itemName << "]" << std::endl;
		}
	}	
}

void CustomerOrder::display(std::ostream& os) const
{
	os << m_name << " - " << m_product << std::endl;
	for (unsigned int i = 0; i < m_cntItem; i++)
	{
		os << "[" << std::setw(6) << std::right << std::setfill('0') << m_listItem[i]->m_serialNumber
			<< std::left << std::setfill(' ') << "] " << std::setw(m_widthField) << m_listItem[i]->m_itemName
			<< " - " << (m_listItem[i]->m_fillState ? "FILLED" : "TO BE FILLED") << std::endl;
	}
}