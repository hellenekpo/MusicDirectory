#ifndef FAN_H
#define FAN_H


#include <iostream>
#include <string>
#include "Artist.h"
#include "Playlist.h"





class Fan : public Person {
    friend std::ostream& operator << (std::ostream& os, const Fan& theFan);
public:
    Fan(const std::string& name, const std::string& intro);
    bool addToPlaylist(Song& song);
    bool removeFromPlaylist(const Song& song);
    void debate(const Fan& otherFan) const;
    void listSongsPlaylist() const;
    void listenToPlaylist(int trackNumber);
    const std::string& getName() const;
private:
    Playlist* playlist;
    Artist* favoriteArtist;
    
};

#endif
