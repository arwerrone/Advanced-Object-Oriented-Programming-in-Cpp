#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <functional>
#include <list>
#include "SongCollection.h"

using namespace std;
namespace sdds {

	SongCollection::SongCollection(std::string file) {
		fstream fin(file);

		if (!fin) {
			throw "File not found!";
			return;
		}

		while (fin) {
			string line;
			string title, artist, album, year, length, price;
			Song ssong;

			getline(fin, line, '\n');

			title = line.substr(0, 25);
			title.erase(title.find_last_not_of(' ') + 1);
			title.erase(0, title.find_first_not_of(' '));
			line.erase(0, 25);

			artist = line.substr(0, 25);
			artist.erase(artist.find_last_not_of(' ') + 1);
			artist.erase(0, artist.find_first_not_of(' '));
			line.erase(0, 25);

			album = line.substr(0, 25);
			album.erase(album.find_last_not_of(' ') + 1);
			album.erase(0, album.find_first_not_of(' '));
			line.erase(0, 25);

			year = line.substr(0, 5);
			year.erase(year.find_last_not_of(' ') + 1);
			year.erase(0, year.find_first_not_of(' '));
			line.erase(0, 5);

			length = line.substr(0, 5);
			length.erase(length.find_last_not_of(' ') + 1);
			length.erase(0, length.find_first_not_of(' '));
			line.erase(0, 5);

			price = line.substr(0, 5);
			price.erase(price.find_last_not_of(' ') + 1);
			price.erase(0, price.find_first_not_of(' '));
			line.erase(0, 5);

			ssong.m_title = title;
			ssong.m_artist = artist;
			ssong.m_album = album;
			ssong.m_year = year;

			stringstream sLength(length);
			sLength >> ssong.m_lenght;
			int min = (ssong.m_lenght / 60);
			int sec = (ssong.m_lenght % 60);
			ssong.m_mins = to_string(min);
			ssong.m_secs = to_string(sec);

			stringstream sPrice(price);
			sPrice >> ssong.m_price;

			vsong.push_back(ssong);
		}
		vsong.pop_back();
	}

	void SongCollection::display(ostream& out) const {
		for_each(vsong.begin(), vsong.end(), [&](const Song& song){
			out << song << endl;
			});

		size_t totalTime = accumulate(vsong.begin(), vsong.end(), 0u, [&](size_t sum, const Song& ss) {
			return sum + ss.m_lenght;
			});
		out << setw(89) << setfill('-') << '\n' << setfill(' ');
		string total = "Total Listening Time: ";
		total += to_string(totalTime / 3600) + ":" + to_string((totalTime % 3600) / 60) + ":" + to_string(totalTime % 60);
		out << "|" << std::right << std::setw(85) << total << std::right << " |" << endl;
	}

	ostream& operator<<(ostream& out, const Song& theSong) {
		out << "| ";
		out << left << setw(20) << theSong.m_title << " | ";
		out << left << setw(15) << theSong.m_artist << " | ";
		out << left << setw(20) << theSong.m_album << " | ";
		out << right << setw(6) << theSong.m_year << " | ";
		out << theSong.m_mins << ":";
		out << setw(2) << setfill('0') << theSong.m_secs << setfill(' ') << " | ";
		out << theSong.m_price << " |";

		return out;
	}

	void SongCollection::sort(string name) {

		if (name == "title") {
			std::sort(vsong.begin(), vsong.end(), [](Song sa, Song sb) {
				return sa.m_title < sb.m_title;
				});
		}
		else if(name == "artist"){
			std::sort(vsong.begin(), vsong.end(), [](Song sa, Song sb) {
				return sa.m_artist < sb.m_artist;
				});
		}
		else if (name == "album") {
			std::sort(vsong.begin(), vsong.end(), [](Song sa, Song sb) {
				return sa.m_album < sb.m_album;
				});
		}
		else if (name == "length") {
			std::sort(vsong.begin(), vsong.end(), [](Song sa, Song sb) {
				return sa.m_lenght < sb.m_lenght;
				});
		}

	}

	void SongCollection::cleanAlbum() {
		for_each(vsong.begin(), vsong.end(), [](Song& ss) {
				if (ss.m_album == "[None]") {
					ss.m_album = "";
				}
			});

	}

	bool SongCollection::inCollection(std::string name) const {
		auto ok = find_if(vsong.begin(), vsong.end(), [&name](const Song& ss) {
			return ss.m_artist == name;
			});
		return ok != vsong.end();

	}

	std::list<Song> SongCollection::getSongsForArtist(std::string artist) const {
		auto ct = count_if(vsong.begin(), vsong.end(), [&artist](const Song& ss) {
			return ss.m_artist == artist;
			});

		list<Song>newList(ct);

		copy_if(vsong.begin(), vsong.end(), newList.begin(), [&artist](const Song& ss2) {
			return ss2.m_artist == artist;
			});

		return newList;
	}

}