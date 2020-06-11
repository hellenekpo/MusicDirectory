
#include "Album.h"

using namespace std;



Album::Album(const string& name, int year) : title(name), year(year) {}
ostream& operator << (ostream& os, const Album& theAlbum) {
    os << "Album title: " << theAlbum.title << "\nYear: " << theAlbum.year << endl;
    os << "This album has " << theAlbum.tracklist.size() << " songs\n";
    for (const Song* song: theAlbum.tracklist) {
        int count = 0;
        os << count << ": " << *(song) << endl;
    }
    return os;
}


const string& Album::getTitle() const {
    return title;
}

bool Album::addSong(Song& song) {
    for (const Song* currSong : tracklist) {
        if (&song == currSong)
            return false;
    }
    tracklist.push_back(&song);
    return true;
}
size_t Album::lengthOfCollection() const {
    return tracklist.size();
}
void Album::listSongs() const {
    for (const Song* song : tracklist) {
        cout << *song << endl;
    }
}
void Album:: playSong(int trackNumber) const {
    tracklist[trackNumber]->play();
}
