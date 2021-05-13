// Name: Filipe da Cunha de Freitas
// Seneca Student ID: 155737190
// Seneca email: fda-cunha-de-freitas@gmyseneca.ca
// Date of completion: 2021-03-28
// Milestone 2
//
// I confirm that I am the only author of this file and the content was created entirely by me.

#include <string>
#include <algorithm> 
#include "Utilities.h"

namespace sdds
{
	char Utilities::m_delimiter = ' ';

	void Utilities::setFieldWidth(size_t newWidth) 
	{
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const 
	{
		return m_widthField;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		std::string extractedToken = str.substr(next_pos);
		size_t pos = extractedToken.find(m_delimiter);
		if (pos != std::string::npos)
		{
			extractedToken = extractedToken.substr(0, pos);
			next_pos += pos + 1;
			if (extractedToken == "")
			{
				more = false;
				throw "There is not any token between delimiters";
			}
			more = true;
		}
		else
		{
			more = false;
		}

		if (extractedToken.length() > m_widthField)
			setFieldWidth(extractedToken.length());
		return extractedToken;		
	}

	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
}