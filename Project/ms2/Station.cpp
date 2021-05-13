// Name: Filipe da Cunha de Freitas
// Seneca Student ID: 155737190
// Seneca email: fda-cunha-de-freitas@gmyseneca.ca
// Date of completion: 2021-03-28
// Milestone 2
//
// I confirm that I am the only author of this file and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include <algorithm> 
#include "Station.h"
#include "Utilities.h"

namespace sdds
{
	size_t Station::m_widthField = 0;
	int Station::id_generator = 0;
	Station::Station(const std::string& str) 
	{
		id_generator++;
		Utilities utility;
		size_t next_pos = 0;
		bool more = true;
		try 
		{
			item_handled = utility.extractToken(str, next_pos, more);
			if (m_widthField < utility.getFieldWidth()) 
			{
				m_widthField = utility.getFieldWidth();
			}
			serial = std::stoi(utility.extractToken(str, next_pos, more));
			current_items = std::stoi(utility.extractToken(str, next_pos, more));
			description = utility.extractToken(str, next_pos, more);
		}
		catch (std::string& message) 
		{
			std::cout << message;
		}
		id = id_generator;
	}
	const std::string& Station::getItemName() const 
	{
		return item_handled;
	}
	unsigned int Station::getNextSerialNumber()
	{
		return serial++;
	}

	size_t Station::getQuantity() const
	{
		return current_items;
	}
	
	void Station::updateQuantity() 
	{
		current_items--;
		if (current_items < 0) 
		{
			current_items = 0;
		}
	}
	void Station::display(std::ostream& os, bool full) const 
	{
		os << "[" << std::setw(3) << std::right << std::setfill('0') << id << "] ";
		os << "Item: " << std::setw(m_widthField) << std::left << std::setfill(' ') << item_handled;
		os << " [" << std::setw(6) << std::right << std::setfill('0') << serial << "]";
		if (full == false) 
		{
			os << std::endl;
		}
		else 
		{
			os << " Quantity: " << std::setw(m_widthField) << std::left << std::setfill(' ') << current_items;
			os << " Description: " << description << std::endl;
		}
	}
}