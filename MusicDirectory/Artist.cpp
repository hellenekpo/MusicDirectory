#include "Artist.h"

using namespace std;

ostream& operator << (ostream& os, const Artist& theArtist) {
    os << "Artist name: " << theArtist.name << endl;
    os << "Albums: ";
    for (Album* album : theArtist.albums) {
        os << album;
        //os << *(album);
    }
    return os;
}

ostream& operator << (ostream& os, const Person& thePerson) {
    os << "name: " << thePerson.name << endl;
    return os;
}

const string& Person:: getName() const {
    return name;
}

const string& Artist:: getName() const {
    return Person::getName();
}
Artist::Artist(const string& name, const string& intro, const string& adlib) : Person(name, intro, false), adlib(adlib) {}

void Artist::introduce() const {
    cout << intro;
}

bool Person:: isPersonFan() const {
    return isFan;
}

bool Artist::addAlbum(Album& album) {
    for (const Album* currAlbum : albums) {
        if (&album == currAlbum)
            return false;
    }
    albums.push_back(&album);
    return true;
    
}
bool Artist::addHistory(RecordLabel& recordLabel) {
    for (auto record : history) {
        if (record.first == &recordLabel) {
            return false;
        }
    }
    history[&recordLabel] = true;
    return true;
    
}
bool Artist::leaveLabel(RecordLabel& recordLabel) {
    for (auto record : history) {
        if (record.first == &recordLabel) {
            cout << name << " has left " << recordLabel.getName();
            history[&recordLabel] = false;
            return true;
        }
    }
    return false;
}
bool Artist::addFeatsong(Song& song) {
    for(const Song* currSong : featSongs) {
        if (&song == currSong)
            return false;
    }
    featSongs.push_back(&song);
    return true;
}
size_t Artist::numberofAlbums() const {
    return albums.size();
}
void Artist::printAlbumNames() const {
    for (const Album* album : albums) {
        cout << album->getTitle() << endl;
    }
}

void Artist::printAlbumsForDebate(int amount) const {
    int count = 0;
    vector<int> curralbums;
    cout << " of the greatest album";
    if (amount > 1) cout << "s!";
    else cout << "!";
    for (int i = 0; i < amount; ++i) {
        if (count == amount) return;
        cout << albums[i]->getTitle() << endl;
    }
}
bool Artist::addfeatSong(Song& song) {
    for (const Song* currSong : featSongs) {
        if (&song == currSong)
            return false;
    }
    featSongs.push_back(&song);
    return true;
}

const string& Artist::getAdlib() const {
    return adlib;
}
