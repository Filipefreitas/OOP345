/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-04-01
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

// Workshop 9 - Multi-Threading
// SecureData.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 
{
	void converter(char* t, char key, int n, const Cryptor& c) 
	{
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}
	
	SecureData::SecureData(const char* file, char key, ostream* pOfs) 
	{
		ofs = pOfs;

		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") + string(file) + string(" ***\n");

		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file " << file << " into memory (null byte added)\n";
		encoded = false;

		code(key);
		*ofs << "Data encrypted in memory\n";
	}


	SecureData::~SecureData() 
	{
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const 
	{
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key) 
	{
		const int num = 4;
		int eachSection = this->nbytes / 4;
		thread t[num];

		for (size_t i = 0; i < num; i++) 
		{
			t[i] = thread(bind(converter, text + i * eachSection, key, (i < num - 1 ? eachSection : nbytes - eachSection * i), Cryptor())); 
		}

		for (size_t i = 0; i < num; i++) 
		{
			t[i].join();
		}
		encoded = !encoded;
	}

	void SecureData::backup(const char* file) 
	{
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			std::ofstream ofs(file, std::ofstream::binary);
			ofs.write(text, nbytes);
			ofs.close();
		}
	}

	void SecureData::restore(const char* file, char key) 
	{
		std::ifstream ifs(file, std::ifstream::binary);
		text = new char[nbytes + 1];
		ifs.read(text, nbytes);
		text[nbytes] = '\0';
		*ofs << "\n" << nbytes << " bytes copied from binary file "  << file << " into memory.\n";
		encoded = true;
		code(key);
		*ofs << "Data decrypted in memory\n\n";
	}


	std::ostream& operator<<(std::ostream& os, const SecureData& sd) 
	{
		sd.display(os);
		return os;
	}
}