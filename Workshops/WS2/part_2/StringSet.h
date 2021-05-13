/*
Name: Filipe Freitas
Student ID: 155737190
Workshop: Workshop 2 part 2
Seneca email: fda-cunha-de-freitas3@myseneca.ca
Date of completion: 2021-01-30
I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.
*/

#ifndef STRINGSET_H
#define STRINGSET_H
#include <string>

namespace sdds 
{
	class StringSet 
	{
		unsigned int m_noOf_record;
		std::string* m_file_name;

	public:
		void setEmpty();
		StringSet();
		~StringSet();
		StringSet(const char*);
		StringSet(StringSet&);
		StringSet(StringSet&&);
		StringSet& operator=(StringSet&);
		StringSet& operator=(StringSet&&);
		size_t size() const;
		std::string operator[](size_t index) const;
	};
}

#endif 
