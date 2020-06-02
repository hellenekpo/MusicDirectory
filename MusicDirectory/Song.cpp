#include "Song.h"


using namespace std;


ostream& operator << (ostream& os, const Song& theSong) {
    os << "Title:" << theSong.title << "by " << theSong.artist->getName();
    if (theSong.featuredArtist != nullptr) {
        os << "featuring " << theSong.featuredArtist->getName();
    }
    return os;
}

Song::Song(const string& title): title(title), artist(nullptr), featuredArtist(nullptr) {}
bool Song::setArtist(const Artist& theArtist) {
    if (artist == nullptr) {
        artist = &theArtist;
        return true;
    }
    return false;
    
}
bool Song::setFeatArtist(const Artist& theArtist) {
    if (featuredArtist == nullptr) {
        featuredArtist = &theArtist;
        return true;
    }
    return false;
    
}
const string& Song::getTitle() const {
    return title;
}
void Song::play() const {
    for(size_t i = 0; i < verses.size(); ++i) {
        if (i % 2 == 0) {
            cout << artist->getAdlib() << endl;
            cout << *(verses[i]);
        }
        else {
            cout << featuredArtist->getAdlib() << endl;
            cout << *(verses[i]);
        }
    }
}

