/*
Name: Filipe Freitas
Student ID: 155737190
Workshop: Workshop 2 part 2
Seneca email: fda-cunha-de-freitas3@myseneca.ca
Date of completion: 2021-01-30
I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "StringSet.h"
using namespace std;

namespace sdds 
{
	StringSet::StringSet()
	{
		setEmpty();
	}

	StringSet::~StringSet()
	{
		delete[] m_file_name;
	}

	StringSet::StringSet(StringSet&& R)
	{
		operator=(move(R));
	}

	StringSet& StringSet::operator=(StringSet&& R)
	{
		if (this != &R) 
		{
			m_file_name = new string[R.m_file_name->length() + 1];
			delete[] m_file_name;
			m_file_name = R.m_file_name;
			R.m_file_name = nullptr;
			m_noOf_record = R.m_noOf_record;
			R.m_noOf_record = 0;
		}
		return *this;
	}

	StringSet::StringSet(const char* filename)
	{
		setEmpty();
		std::ifstream file;
		file.open(filename); 
		std::string temp;

		if (file)
		{
			while (!file.eof()) 
			{
				if (getline(file, temp, ' ')) 
				{
					++m_noOf_record;
				}
			}

			m_file_name = new std::string[m_noOf_record];
			file.close(); 
			file.open(filename);

			for (unsigned int i = 0; i < m_noOf_record; ++i)
			{
				getline(file, m_file_name[i], ' ');
			}
		}

		else 
		{
			std::cerr << "File not opened!" << std::endl;
			setEmpty();
		}
	}

	StringSet::StringSet(StringSet& obj)
	{
		setEmpty();
		*this = obj;
	}

	void StringSet::setEmpty()
	{
		m_file_name = nullptr;
		m_noOf_record = 0;
	}

	std::string StringSet::operator[](size_t index) const
	{
		std::string temp;
		if (index <= m_noOf_record && index >= 0)
		{
			if (m_file_name == nullptr)
			{
				temp = "";
			}
			else
			{
				temp = m_file_name[index];
			}
		}
		else
		{
			temp = "";
		}
		return temp;

	}

	StringSet& StringSet::operator=(StringSet& obj)
	{
		if (this != &obj)
		{
			delete[] m_file_name;
			m_noOf_record = obj.m_noOf_record;
			m_file_name = new std::string[m_noOf_record];

			for (unsigned i = 0; i < m_noOf_record; ++i) 
			{
				m_file_name[i] = obj.m_file_name[i];
			}
		}

		return *this;
	}

	size_t StringSet::size() const
	{
		return m_noOf_record;
	}
}