/*
Name: Filipe da Cunha de Freitas
Student ID: 155737190
Date: 2021-03-21
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#include <functional>
#include <iomanip>
#include <fstream>
#include <numeric>
#include "SongCollection.h"

using namespace std;

namespace sdds {
	string& SongCollection::trim(string& token) 
	{
		if (!token.empty()) 
		{
			token.erase(0, token.find_first_not_of(' '));
			token.erase(token.find_last_not_of(' ') + 1);
		}
		return token;
	}

	SongCollection::SongCollection(string fileName) 
	{
		std::ifstream file(fileName);
		if (!file) 
		{
			throw "Invalid file name.";
			return;
		}
		while (file)
		{
			Song song;
			string line;
			getline(file, line);
			if (file) 
			{
				trim(song._title = line.substr(0, 25));
				trim(song._artist = line.substr(25, 25));
				trim(song._album = line.substr(50, 25));
				try {
					song._year = stoi(line.substr(75, 5));
				}
				catch (...) {
					song._year = 0;
				}
				song._length = stoi(line.substr(80, 5));
				song.m_price = stod(line.substr(85, 5));
				_collection.push_back(song);
			}
		}
		file.close();
	}

	void SongCollection::display(std::ostream& out) const 
	{
		for_each(_collection.begin(), _collection.end(), [&out](const Song & song) 
		{
			out << song << endl;
		});
	
		size_t sumTime = accumulate(_collection.begin(), _collection.end(), 0u, [](const size_t& sumLength, const Song& song) 
		
		{
			return sumLength + song._length;
		});
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "| ";
		out.width(77);
		out << "Total Listening Time: "
			<< sumTime / 3600 << ":" << (sumTime - (sumTime / 3600) * 3600) / 60
			<< ":"
			<< sumTime % 60;
		out << " |" << endl;
	}

	void SongCollection::sort(string column) 
	{
		if (column == "title") 
		{
			::sort(_collection.begin(), _collection.end(), [](const Song& front, const Song& after) 
				{
					return front._title < after._title;
				});
		}
		else if (column == "album")
		{
			::sort(_collection.begin(), _collection.end(), [](const Song& front, const Song& after) 
			{
				return front._album < after._album;
			});
		}
		else if (column == "length") 
		{
			::sort(_collection.begin(), _collection.end(), [](const Song& front, const Song& after) 
			{
				return front._length < after._length;
			});
		}
	}

	ostream& operator<<(ostream& out, const Song& src) 
	{
		out << "| ";
		out << left << setw(20) << src._title;
		out << " | ";
		out << left << setw(15) << src._artist;
		out << " | ";
		out << left << setw(20) << src._album;
		out << " | ";
		if (src._year > 0)
			out << right << setw(6) << src._year;
		else
			out << right << setw(6) << ' ';
		out << " | ";
		out << src._length / 60 << ":";
		out << right << setw(2) << setfill('0') << src._length % 60 << setfill(' ');
		out << " | ";
		out << src.m_price;
		out << " |";
		return out;
	}

	void SongCollection::cleanAlbum() 
	{
		for_each(_collection.begin(), _collection.end(), [](Song& song) { song._album = song._album == "[None]" ? "" : song._album; });
	}

	bool SongCollection::inCollection(string artist) const 
	{
		auto valid = find_if(_collection.begin(), _collection.end(), [&artist](const Song& song) {return song._artist == artist; });
		return valid != _collection.end();
	}
	::list<Song> SongCollection::getSongsForArtist(string artist) const 
	{
		auto count = count_if(_collection.begin(), _collection.end(), [&artist](const Song& song) 
		{
			return song._artist == artist;
		});

		list<Song>listed(count);
		
		copy_if(_collection.begin(), _collection.end(), listed.begin(), [&artist](const Song& song) 
		{
			return song._artist == artist;
		});

		return listed;
	}
}