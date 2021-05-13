/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-03-21
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <functional>
#include <list>

using namespace std;

namespace sdds 
{
	struct Song 
	{
		string _artist{};
		string _title{};
		string _album{};
		double m_price{};
		size_t _year{};
		size_t _length{};
	};
	class SongCollection 
	{
		vector<Song> _collection;
	public:
		explicit SongCollection(string file);
		void display(std::ostream& out) const;
		void sort(string);
		void cleanAlbum();
		[[nodiscard]] bool inCollection(string) const;
		[[nodiscard]] ::list<Song> getSongsForArtist(string) const;
		string& trim(string& token);
	};
	ostream& operator<<(ostream& out, const Song& src);
}
#endif