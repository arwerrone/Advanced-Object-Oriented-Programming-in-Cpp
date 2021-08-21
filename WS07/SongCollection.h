#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

namespace sdds {

	struct Song {
		std::string m_artist{};
		std::string m_title{};
		std::string m_album{};
		std::string m_year{};
		double m_price{};
		size_t m_lenght{};
		std::string m_mins{};
		std::string m_secs{};
	};

	class SongCollection {
		std::vector<Song> vsong;
	public:
		SongCollection(std::string file);
		void display(std::ostream& out) const;
		void sort(std::string name);
		void cleanAlbum();
		bool inCollection(std::string name) const;
		std::list<Song> getSongsForArtist(std::string artist) const;

	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);

}

#endif