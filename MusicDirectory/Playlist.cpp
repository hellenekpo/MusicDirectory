
#include "Playlist.h"


using namespace std;


ostream & operator << (ostream & os, const Playlist& thePlaylist) {
    os << "Playlist title: " << thePlaylist.title << "\nGenre: " << thePlaylist.genre << endl;
    os << "This playlist has " << thePlaylist.tracklist.size() << " songs\n";
    for (const Song* song : thePlaylist.tracklist) {
        int count = 0;
        os << count << ": " << *(song);
    }
    return os;
}
Playlist::Playlist(const string& title, const string& genre) : title(title), genre(genre) {}

bool Playlist::removeSong(const Song& song) {
    for(size_t i = 0; i < tracklist.size(); ++i) {
        if (tracklist[i] == &song) {
            cout << "Removing " << song.getTitle() << "...\n";
            swap(tracklist[i], tracklist[tracklist.size()-1]);
            tracklist.pop_back();
            return true;
        }
    }
    cout << "Error: Song " << song.getTitle() << " isn't apart of this playlist!\n";
    return false;
}


const string& Playlist:: getTitle() const {
    return title;
}

bool Playlist::addSong(Song& song) {
    for (const Song* currSong : tracklist) {
        if (&song == currSong)
            return false;
    }
    tracklist.push_back(&song);
    return true;
}
size_t Playlist::lengthOfCollection() const {
    return tracklist.size();
}
void Playlist::listSongs() const {
    for (const Song* song : tracklist) {
        cout << *song << endl;
    }
}
void Playlist:: playSong(int trackNumber) const {
    tracklist[trackNumber]->play();
}
