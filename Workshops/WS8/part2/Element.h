/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-03-26
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

#ifndef SDDS_ELEMENT_H
#define SDDS_ELEMENT_H

#include <iomanip>
#include <string>
#include <fstream>

extern const int FWC;
extern const int FWD;
extern const int FWP;

namespace sdds {

	struct Description 
	{
		unsigned code;
		std::string desc;
		bool load(std::ifstream& f) 
		{
			f >> code >> desc;
			return f.good();
		}

		void display(std::ostream& os) const 
		{
			os << std::setw(FWC) << code
				<< std::setw(FWD) << desc
				<< std::endl;
		}
	};

	struct Price 
	{
		unsigned code;
		double price;
		bool load(std::ifstream& f) 
		{
			f >> code >> price;
			return f.good();
		}

		void display(std::ostream& os) const
		{
			os << std::setw(FWC) << code << std::setw(FWP)
				<< price << std::endl;
		}
	};

	struct Product 
	{
		std::string m_desc{};
		double m_price{};
		int m_id{};
		static size_t idGenerator;
		static bool Trace;

		Product() 
		{
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "    DC [" << m_id << "]" << std::endl;
		}

		Product(const std::string& str, double p) 
		{
			this->m_desc = str;
			this->m_price = p;
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "     C [" << m_id << "]" << std::endl;
		}

		Product(const Product& other) 
		{
			this->m_desc = other.m_desc;
			this->m_price = other.m_price;
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "    CC [" << m_id
				<< "] from [" << other.m_id << "]"
				<< std::endl;
		}

		~Product() 
		{
			if (Product::Trace)
				std::cout << "    ~D [" << m_id << "]" << std::endl;
		}

		inline void validate() const
		{
			std::string msg = "*** Negative prices are invalid ***";
				if (m_price < 0) throw msg;
		}

		void display(std::ostream& os) const 
		{
			os << std::setw(FWD) << m_desc
				<< std::setw(FWP) << m_price
				<< std::endl;
		}
	};
}
#endif