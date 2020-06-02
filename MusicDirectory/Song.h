#ifndef SONG_H
#define SONG_H


#include "Artist.h"
#include <iostream>
#include <vector>
#include <string>


class Artist;


class Verse {
    friend std::ostream& operator<< (std::ostream& os, const Verse& theVerse) {
        os << theVerse.lyrics << std::endl;
        return os;
    }
public:
    Verse(const std::string& lyrics) : lyrics(lyrics) {}
private:
    std::string lyrics;
};


class Song {
    friend std::ostream& operator << (std::ostream& os, const Song& theSong);
public:
    Song(const std::string& title);
    bool setArtist(const Artist& theArtist);
    bool setFeatArtist(const Artist& theArtist);
    const std::string& getTitle() const;
    void play() const;
    
    
private:
    const Artist* artist;
    const Artist* featuredArtist;
    std::vector<Verse*> verses;
    std::string title;
    std::vector<Song*> tracklist;
};

#endif
