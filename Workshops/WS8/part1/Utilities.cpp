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
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (size_t i = 0; i < desc.size(); ++i) 
		{
			for (size_t x = 0; x < price.size(); ++x) 
			{
				if (desc[i].code == price[x].code) 
				{
					Product* p = new Product(desc[i].desc, price[x].price);
					p->validate();
					priceList += p;
					delete p;	// deallocate p
				}
			}
		}

		return priceList;
	}
}