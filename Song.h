//
// Created by Ronak on 3/29/2020.
//

#include <string>
#include <iostream>

using namespace std;

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H



class Song{
    private:
        string title;
        string artist;
        int ssize;

    public:
        Song();
        Song(string title, string artist, int ssize);
        void setTitle(string _title);
        void setArtist(string _artist);
        void setSize(int _ssize);
        string getTitle() const;
        string getArtist() const;
        int getSize() const;
        void Swap(Song &obj);

        bool operator ==(Song const &obj);
        bool operator >(Song const &obj);
        bool operator <(Song const &obj);

        ~Song();
};

#endif