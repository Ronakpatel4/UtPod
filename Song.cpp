//
// Created by Ronak on 3/29/2020.
//

#include "UtPod.h"
#include "Song.h"

Song::Song() {

}

Song::Song(string _title, string _artist, int _ssize) {
    title = _title;
    artist = _artist;
    ssize = _ssize;
}

void Song::setTitle(string _title) {
    title = _title;
}

void Song::setArtist(string _artist) {
    artist = _artist;

}

void Song::setSize(int _ssize) {
    ssize = _ssize;
}

string Song::getTitle() const {
    return title;
}

string Song::getArtist() const {
    return artist;
}

int Song::getSize() const {
    return ssize;
}


bool Song::operator ==(Song const &obj) {
        return ((this->title == obj.title) &&
                (this->artist == obj.artist) &&
                (this->ssize == obj.ssize));
}

bool Song::operator >(Song const &obj) {
    if(this->artist > obj.artist){
        return true;
    }

    if(this->artist == obj.artist){
        if(this->title > obj.title) {
            return true;
        }
    }

    if(this->artist == obj.artist){
        if(this->title == obj.title) {
            if(this->ssize > obj.ssize){
                return true;
            }
        }
    }
    return false;
}

bool Song::operator <(Song const &obj) {
    if(this->artist < obj.artist){
        return true;
    }

    if(this->artist == obj.artist){
        if(this->title < obj.title) {
            return true;
        }
    }

    if(this->artist == obj.artist){
        if(this->title == obj.title) {
            if(this->ssize < obj.ssize){
                return true;
            }
        }
    }

    return false;
}

void Song::Swap(Song &obj) {
    Song *temp = this;
    obj.artist = this->artist;
    obj.title = this-> title;
    *this = obj;
    obj = *temp;
}


Song::~Song() {
    cout << "debug - in destructor for "<< title <<endl;

}




