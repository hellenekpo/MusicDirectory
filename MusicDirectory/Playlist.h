#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>
#include <iostream>
#include "Song.h"

class Playlist {
    friend std::ostream & operator << (std::ostream & os, const Playlist& thePlaylist);
public:
    Playlist(const std::string& title, const std::string& genre);
    bool removeSong(const Song& song);
    bool addSong(Song& song);
    virtual const std::string& getTitle() const = 0;
    size_t lengthOfCollection() const;
    void listSongs() const;
    void playSong(int trackNumber) const;
private:
    std::string genre;
    std::string title;
    std::vector<Song*> tracklist;
    
};

#endif
