#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include <vector>
#include "Song.h"


class Song;

class Album  {
    friend std::ostream& operator << (std::ostream& os, const Album& theAlbum);
public:
    Album(const std::string& name, int year);
    bool addSong(Song& song);
    const std::string& getTitle() const;
    size_t lengthOfCollection() const;
    void listSongs() const;
    void playSong(int trackNumber) const;
private:
    int year;
    std::string title;
    std::vector<Song*> tracklist;
};

#endif
