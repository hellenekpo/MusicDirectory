//Hellen Ekpo

//
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <map>
#include <set>

#include "Fan.h"
#include "Artist.h"
#include "Song.h"
#include "RecordLabel.h"
#include "Album.h"
#include "Playlist.h"


using namespace std;

void commands(vector<Person*>& people, vector<Song*>& songs, vector<Album*>& albums, vector<RecordLabel*>& recordLabels, vector<Playlist*>& playlist) {
    bool stop = false;
    while (!stop) {
        cout << "Welcome to this Music Program! Enter 'c' to print commands\n";
        string command;
        cin >> command;
        if (command == "c") {
            cout << "To make a new Fan, please enter 'f' following the name and their introdction.\nTo make a new Artist please enter 'ar' following thier name, go to introduction, and adlib.\nTo make a new Album please enter 'al' following the title of the album and the year it came out.\nTo mske a new Record Label, please enter 'rl' following the name and the year founded.\nTo make a new Song, please enter 's' following the name of the song.\nTo make a new Playlist, please enter 'pl' following the name of the playlist, and the genre.\nTo exit, please enter 'exit'\n";
        }
        string commandnext;
        cin >> commandnext;
        if (commandnext == "exit") {
            stop = true;
        }
        else {
            string title, info1, info2;
            int num;
            cin >> title;
            if (commandnext == "al" || commandnext == "rl") {
                cin >> num;
                if (commandnext == "al") {
                    Album* newAlbum =  new Album(title, num);
                    albums.push_back(newAlbum);
                }
                else {
                    RecordLabel* newRL = new RecordLabel(title, num);
                    recordLabels.push_back(newRL);
                }
            }
            else {
                if (commandnext == "ar") {
                    cin >> info1 >> info2;
                }
            }
        }
        //cout << commandnext << ' ' << title << ' ' << num << endl;
    }
    cout << "Thank you for using this program!\n";
}

int main() {
    vector<Person*> people;
    vector<Song*> songs;
    vector<Album*> albums;
    vector<RecordLabel*> recordLabels;
    vector<Playlist*> playlists;
    commands(people, songs, albums, recordLabels, playlists);
//    Fan* Hellen = new Fan("Hellen", "I am from Houston, Texas!");
//    cout << *Hellen;
//    Artist* TylerTheCreator = new Artist("Tyler, The Creator", "What's good", "Aiyyo");
//    TylerTheCreator->introduce();
    
    
}
