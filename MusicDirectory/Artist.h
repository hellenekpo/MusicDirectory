#ifndef ARTIST_H
#define ARTIST_H

#include "Album.h"
#include "Song.h"
#include "RecordLabel.h"

#include <string>
#include <vector>
#include <map>
#include <iostream>



class Album;
class Song;



class Person {
    friend std::ostream& operator << (std::ostream& os, const Person& thePerson);
public:
    Person(const std::string& name, const std::string& intro, bool isFan) : name(name), intro(intro), isFan(isFan) {}
    virtual const std::string& getName() const = 0;
    bool isPersonFan() const;
protected:
    std::string name;
    std::string intro;
    bool isFan;
    
};

class Artist : public Person {
    friend std::ostream& operator << (std::ostream& os, const Artist& theArtist);
public:
    Artist(const std::string& name, const std::string& intro, const std::string& adlib);
    
    void introduce() const;
    const std::string& getName() const;
    bool addAlbum(Album& album);
    bool addHistory(RecordLabel& recordLabel);
    bool leaveLabel(RecordLabel& recordLabel);
    bool addFeatsong(Song& song);
    size_t numberofAlbums() const;
    void printAlbumNames() const;
    
    void printAlbumsForDebate(int amount) const;
    bool addfeatSong(Song& song);
    
    const std::string& getAdlib() const;
private:
    std::map<RecordLabel*, bool> history;
    std::vector<Album*> albums;
    std::vector<Song*> featSongs;
    std::string adlib;
};

#endif
