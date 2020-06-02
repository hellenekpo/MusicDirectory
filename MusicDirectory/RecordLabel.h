#ifndef RECORDLABEL_H
#define RECORDLABEL_H

#include <map>
#include <iostream>
#include <string>

class Artist;


class RecordLabel {
    friend std::ostream& operator << (std::ostream& os, const RecordLabel& theRecord);
public:
    RecordLabel(const std::string& name, int yearFounded);
    bool signArtist(Artist& theArtist, int year);
    bool terminateContract(Artist& theArtist);
    const std::string& getName() const;
    void pastArtists() const;
private:
    std::map<Artist*, std::map<int, bool>> history;
    std::string name;
    int yearFounded;
    
};

#endif
