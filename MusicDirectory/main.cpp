//Hellen Ekpo

//
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <map>
#include <set>
#include <fstream>

#include "Fan.h"
#include "Artist.h"
#include "Song.h"
#include "RecordLabel.h"
#include "Album.h"
#include "Playlist.h"


using namespace std;

void commands(vector<Person*>& people, vector<Song*>& songs, vector<Album*>& albums,
              vector<RecordLabel*>& recordLabels, vector<Playlist*>& playlist) {
    bool stop = false;
    while (!stop) {
        cout << "Welcome to this Music Directory Program! Enter 'c' to print commands\n";
        string command;
        cin >> command;
        if (command == "c") {
            cout << "To make a new Fan, please enter 'f' following the name and "
            << "their introduction. If you want to see the current "
            << "fan(s) please enter 'printf'.\nTo make a new Artist please enter 'art' "
            << "following their name, go to introduction, and adlib. If you want to see the current "
            << "artist(s), please enter 'printart'.\nTo make "
            << "a new Album please enter 'al' following the title of the album "
            << "and the year it came out. If you want to see the current album(s), please enter 'printal'. "
            << "\nTo mske a new Record Label, please enter 'rl' following the name and the year founded. "
            << "If you want to see the current record label(s), please enter 'printrl'.\nTo make a new Song, "
            << "please enter 's' following the name of the song. If you want to see the current song(s), "
            << "please enter 'prints'.\nTo make a new Playlist, please enter 'pl' following the name of the "
            << "playlist, and the genre. If you eant to see the current playlist(s), please esnter 'printpl'"
            << "\nTo exit, please enter 'exit'\n";
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
            for (size_t i = 0; i < title.size(); ++i) {
                if (i != 0 && ('Z' > title[i]) && 'A' < title[i]) {
                    title.insert(i, " ");
                    ++i;
                    //cout << title[i];
                }
            }
            if (commandnext == "al" || commandnext == "rl") {
                cin >> num;
                if (commandnext == "al") {
                    Album* newAlbum =  new Album(title, num);
                    albums.push_back(newAlbum);
                    cout << "New Album: " << title << endl << "Released: "
                    << num << "\nsuccessfullly added to the directory.\n";
                }
                else {
                    RecordLabel* newRL = new RecordLabel(title, num);
                    recordLabels.push_back(newRL);
                    cout << "New Record Label: " << title << endl << "Founded: "
                    << num << "\nsuccessfully added to the directory.\n";
                }
            }
            else {
                if (commandnext == "s") {
                    Song* newSong = new Song(title);
                    songs.push_back(newSong);
                    cout << "New Song: " << title << "\nsuccessfully added to the directoy.\n";
                }
                else {
                    if (commandnext == "f" || commandnext == "pl" || commandnext == "art") {
                        cin >> info1;
                        for (size_t i = 0; i < info1.size(); ++i) {
                            if (i != 0 && ('Z' > info1[i]) && 'A' < info1[i]) {
                                info1.insert(i, " ");
                                ++i;
                                //cout << info1[i];
                            }
                        }
                        if (commandnext == "f") {
                            Fan* newFan = new Fan(title, info1);
                            people.push_back(newFan);
                            cout << "New Fan: " << title << "\nsuccessfully added to the directory.\n";
                        }
                        else if (commandnext == "pl") {
                            Playlist* newPlay = new Playlist(title, info1);
                            playlist.push_back(newPlay);
                            cout << "New Playlist: " << title << endl << "Genre: "
                            << info1 << "\nsuccessfully added to the directory.\n";
            
                        }
                        else if (commandnext == "art") {
                            cin >> info2;
                            Artist* newArt = new Artist(title, info1, info2);
                            people.push_back(newArt);
                            cout << "New Artist: " << title << "\nsuccessfully added to the directory.\n";
                        }
                    }
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
    ofstream ofs;
    ofs.open("fileinfo.txt");
    if (!ofs) {
        cerr << "Couldn't open the file!\n";
    }
    cout << "Writing Songs onto file...\n";
    ofs << "Songs\n";
    for (const Song* song : songs) {
        ofs << song->getTitle() << "\n";
    }
//    Fan* Hellen = new Fan("Hellen", "I am from Houston, Texas!");
//    cout << *Hellen;
//    Artist* TylerTheCreator = new Artist("Tyler, The Creator", "What's good", "Aiyyo");
//    TylerTheCreator->introduce();
    
    
}
