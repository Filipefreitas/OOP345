/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-02-20
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Collection.h"
#include "Collection.h"
#include "Book.h"
#include "Book.h"
#include "Movie.h"
#include "Movie.h"
#include "SpellChecker.h"
#include "SpellChecker.h"

using namespace sdds;

enum AppErrors
{
	CannotOpenFile = 1, // An input file cannot be opened
	BadArgumentCount = 2, // The application didn't receive anough parameters
};

// The observer function for adding books to the collection:
//   should be called every time a new book is added to the collection
void bookAddedObserver(const Collection<Book>& theCollection,
	const Book& theBook)
{
	std::cout << "Book \"" << theBook.title() << "\" added!\n";
}

// The observer function for adding movies to the collection:
//   should be called every time a new movie is added to the collection
void movieAddedObserver(const Collection<Movie>& theCollection,
	const Movie& theMovie)
{
	std::cout << "Movie \"" << theMovie.title()
		<< "\" added to collection \"" << theCollection.name()
		<< "\" (" << theCollection.size() << " items).\n";
}

// ws books.txt movies.txt file_missing.txt file_words.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Collection<sdds::Book> library("Bestsellers");
	if (argc == 5) 
	{
		std::ifstream file(argv[1]);
		std::string strLibrary;
		size_t cnt = 0;
		if (!file) 
		{
			std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
			return 1;
		}
		do 
		{
			std::getline(file, strLibrary);
			if (file) 
			{
				if (strLibrary[0] != '#') 
				{
					Book temp(strLibrary);
					library += temp;
					cnt++;
				}
			}
		} while (file && cnt < 4);


		library.setObserver(bookAddedObserver);

		do 
		{
			std::getline(file, strLibrary);
			if (file && strLibrary[0] != '#') 
			{
				library += Book(strLibrary);
			}
		} while (file);
		file.close();
	}
	else
	{
		std::cerr << "ERROR: Incorrect number of arguments.\n";
		exit(AppErrors::BadArgumentCount);
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	auto update = [usdToCadRate, gbpToCadRate](Book& src) 
	{
		if (src.country() == "US") 
		{
			src.price() *= usdToCadRate;
		}
		else if (src.country() == "UK" && src.year() <= 1999 && src.year() >= 1990) 
		{
			src.price() *= gbpToCadRate;
		}
	};

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	for (size_t i = 0; i < library.size(); ++i) 
	{
		update(library[i]);
	}

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n\n";

	Collection<Movie> theCollection("Action Movies");

	// Process the file
	Movie movies[5];
	if (argc > 2) 
	{
		std::ifstream file(argv[2]);
		if (!file) 
		{
			std::cerr << "ERROR: Cannot open file [" << argv[2] << "].\n";
			return 1;
		}
		std::string strMovies;
		int cnt = 0;
		do {
			std::getline(file, strMovies);
			if (file && strMovies[0] != '#') 
			{
				movies[cnt] = Movie(strMovies);
				cnt++;
			}
		} while (file);


	}

	std::cout << "-----------------------------------------\n";
	std::cout << "Testing addition and callback function\n";
	std::cout << "-----------------------------------------\n";
	if (argc > 2) 
	{
		// Add a few movies to collection; no observer is set
		((theCollection += movies[0]) += movies[1]) += movies[2];
		theCollection += movies[1];
		// add more movies; now we get a callback from the collection
		theCollection.setObserver(movieAddedObserver);
		theCollection += movies[3];
		theCollection += movies[3];
		theCollection += movies[4];
	}
	else 
	{
		std::cout << "** No movies in the Collection\n";
	}
	std::cout << "-----------------------------------------\n\n";
	
	std::cout << "-----------------------------------------\n";
	std::cout << "Testing exceptions and operator[]\n";
	std::cout << "-----------------------------------------\n";


	try 
	{
		for (auto i = 0u; i < 10; ++i)
			std::cout << theCollection[i];
	}
	catch (std::out_of_range& exception) 
	{
		std::cout << "** EXCEPTION: " << exception.what() << std::endl;
	}

	std::cout << "-----------------------------------------\n\n";
	std::cout << "-----------------------------------------\n";
	std::cout << "Testing the functor\n";
	std::cout << "-----------------------------------------\n";
	
	for (auto i = 3; i < argc; ++i)
	{
		try 
		{
            SpellChecker sp(argv[i]);
            for (auto j = 0u; j < library.size(); ++j)
                library[j].fixSpelling(sp);
            sp.showStatistics(std::cout);
			for (auto j = 0u; j < theCollection.size(); ++j)
				theCollection[j].fixSpelling(sp);
            sp.showStatistics(std::cout);
		}
		catch (const char* msg) 
		{
			std::cout << "** EXCEPTION: " << msg << std::endl;
		}
	}

	if (argc < 3) 
	{
		std::cout << "** Spellchecker is empty\n";
		std::cout << "-----------------------------------------\n";
	}
	std::cout << "\n";

	std::cout << "=========================================\n";
	std::cout << "Wrapping up this workshop\n";
	std::cout << "--------------- Movies ------------------\n";
	std::cout << theCollection;
	std::cout << "--------------- Books -------------------\n";
	std::cout << library;
	std::cout << "-----------------------------------------\n";
	std::cout << "Testing operator[] (the other overload)\n";
	std::cout << "-----------------------------------------\n";
	const Movie* aMovie = theCollection["Terminator 2"];
	if (aMovie == nullptr)
		std::cout << "** Movie Terminator 2 not in collection.\n";
	aMovie = theCollection["Dark Phoenix"];
	if (aMovie != nullptr)
		std::cout << "In this collection:\n" << *aMovie;
	std::cout << "-----------------------------------------\n\n";

	return 0;
}
