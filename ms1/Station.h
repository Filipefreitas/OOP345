// Name: Filipe da Cunha de Freitas
// Seneca Student ID: 155737190
// Seneca email: fda-cunha-de-freitas@gmyseneca.ca
// Date of completion: 2021-03-21
//
// I confirm that I am the only author of this file and the content was created entirely by me.

#ifndef STATION_H
#define STATION_H

#include <string>

namespace sdds
{
	class Station
	{
		int id = 0;
		std::string item_handled = "";
		std::string description = "";
		int serial = 0;
		int current_items = 0;
		static size_t m_widthField;
		static int id_generator;
	public:
		Station(const std::string&);
		const std::string& getItemName() const;
		unsigned int getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}
#endif 

