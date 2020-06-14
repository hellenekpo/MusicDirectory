#include "Fan.h"

using namespace std;

ostream& operator << (ostream& os, const Fan& theFan) {
    os << "Hello! My name is " << theFan.name << " and " << theFan.intro << endl;
    if (theFan.favoriteArtist != nullptr) {
        os << "My favorite artist is " << theFan.favoriteArtist->getName() << ".";
    }
    return os;
}

const string& Fan:: getName() const {
    return Person::getName();
}

Fan::Fan(const string& name, const string& intro) : Person(name, intro, true), playlist(nullptr), favoriteArtist(nullptr) {}

bool Fan::addToPlaylist(Song& song) {
    return playlist->addSong(song);
}
bool Fan::removeFromPlaylist(const Song& song) {
    return playlist->removeSong(song);
}
void Fan::debate(const Fan& otherFan) const {
    cout << name << ": Yo, I think " << favoriteArtist->getName() << " is the greatest of all time!\n";
    cout << otherFan.name << ": What are you talking about? " << otherFan.favoriteArtist->getName() << " has ";
    int num;
    cin >> num;
    while (num >= otherFan.favoriteArtist->numberofAlbums()) {
        cout << "This artist doesn't have that many albums. Try again. \n";
        cin >> num;
    }
    cout << num;
    otherFan.favoriteArtist->printAlbumsForDebate(num);
    cout << name << ": You're right. ";
    if (num == 1) cout << "That's a really good album.\n";
    else cout << "Those are really good albums.\n";
}

void Fan::listSongsPlaylist() const {
    if (playlist->lengthOfCollection() == 0) {
        cout << "There are no songs in my playlist!\n";
        return;
    }
    else if (playlist->lengthOfCollection() == 1) {
        cout << "Here is the song in my playlist!\n";
    }
    else {
        cout << "Here are the songs in my playlist!\n";
    }
    playlist->listSongs();
}
void Fan::listenToPlaylist(int trackNumber) {
    if (trackNumber > playlist->lengthOfCollection()) {
        cout << "This playlist doesn't have that many songs!\n";
        return;
    }
    cout << "Playing track " << trackNumber << ".";
    playlist->playSong(trackNumber);
}
