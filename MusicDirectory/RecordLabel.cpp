


#include "RecordLabel.h"
#include "Artist.h"

class Artist;
using namespace std;



ostream& operator << (ostream& os, const RecordLabel& theRecord) {
    os << theRecord.name << ": We were founded " << theRecord.yearFounded << ".\n";
    os << "Here are the artist currently signed to our label:\n";
    for (auto artist : theRecord.history) {
        for (auto info : artist.second) {
            if (info.second == true) {
                os << artist.first->getName() << ": signed " << info.first;
            }
        }
    }
    return os;
}

RecordLabel::RecordLabel(const string& name, int yearFounded) : name(name), yearFounded(yearFounded) {}
bool RecordLabel::signArtist(Artist& theArtist, int year) {
    for (auto artist : history) {
        if (artist.first == &theArtist) {
            cout << "Artist year has been updated!\n";
            artist.second[year] = true;
            return true;
            
        }
    }
    cout << "Artist: " << theArtist.getName() << " has successfully signed to " <<
    name << "!\n";
    history[&theArtist][year] = true;
    return theArtist.addHistory(*this);
}

bool RecordLabel::terminateContract(Artist& theArtist) {
    for (auto artist : history) {
        if (artist.first == &theArtist) {
            return theArtist.leaveLabel(*this);
        }
    }
    return false;
}
const string& RecordLabel::getName() const {
    return name;
}

void RecordLabel::pastArtists() const {
    for (auto artist : history) {
        for (auto info : artist.second) {
            if (info.second == false) {
                cout << artist.first->getName() << ": signed " << info.first;
            }
        }
    }
}
