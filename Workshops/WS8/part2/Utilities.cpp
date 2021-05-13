/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-03-26
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) 
	{
		List<Product> priceList;
		for (size_t i = 0; i < desc.size(); ++i) 
		{
			for (size_t x = 0; x < price.size(); ++x) 
			{
				if (desc[i].code == price[x].code) 
				{
					Product* p = new Product(desc[i].desc, price[x].price);
					p->validate();
					priceList += p;
					delete p;
					p = { nullptr };
				}
			}
		}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) 
	{
		List<Product> priceList;
		for (size_t i = 0; i < desc.size(); ++i) 
		{
			for (size_t x = 0; x < price.size(); ++x) 
			{
				if (desc[i].code == price[x].code) 
				{
					std::unique_ptr<Product> p{new Product(desc[i].desc, price[x].price)};
					p->validate();
					priceList += p;
				}
			}
		}
		return priceList;
	}
}