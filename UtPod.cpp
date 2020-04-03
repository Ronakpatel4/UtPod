//
// Created by Ronak on 3/30/2020.
//

#include "UtPod.h"
#include "Song.h"

UtPod::UtPod() {
 memSize = MAX_MEMORY;
 songs = NULL;
}

UtPod::UtPod(int size) {
    if((size > MAX_MEMORY) || (size <= 0)){
        UtPod();
    }
    else{
        memSize = size;
    }
    songs = NULL;
}

int UtPod::addSong(Song const &s) {
    if(getRemainingMemory() == MAX_MEMORY){
        SongNode *temp = new SongNode;
        temp->s = s;
        temp->next = NULL;
        songs = temp;

        return SUCCESS;
    }


    if(getRemainingMemory() >= s.getSize()){
        SongNode *temp = new SongNode;
        temp->s = s;
        temp->next = songs;
        songs = temp;

        return SUCCESS;
    }
    return NO_MEMORY;
}

int UtPod::removeSong(Song const &s) {
    SongNode *temp = songs;
    SongNode *before = temp;
    while(temp != NULL){
        if(getRemainingMemory() == (MAX_MEMORY - temp->s.getSize())){
            songs =NULL;
            delete(temp);
            return SUCCESS;
        }

        if(temp->s == s){
            if(temp == songs){
                songs = temp->next;
                delete(temp);
                return SUCCESS;
            }
            before->next = temp->next;
            delete(temp);
            return SUCCESS;
        }
        before = temp;
        temp = temp->next;
    }
    return NO_MEMORY;
}

void UtPod::shuffle() {
    SongNode *temp = songs;
    temp->s.Swap(temp->next->s);

}

void UtPod::showSongList() {
    SongNode *temp = songs;
    if(getRemainingMemory() == MAX_MEMORY){
        cout << "No songs in list" << endl;
    }
    while(temp != NULL){
        cout << temp->s.getArtist() << ", " << temp->s.getTitle() << endl;
        temp = temp->next;
    }

}

void UtPod::sortSongList() {
    SongNode *temp = songs;
    Song buff;
    int n = 0;
    while(temp->next != NULL) {
        if (temp->s > temp->next->s) {
            buff = temp->s;
            temp->s = temp->next->s;
            temp->next->s = buff;
        }
        temp = temp->next;
    }


}

void UtPod::clearMemory() {

}

int UtPod::getRemainingMemory() {
    int left = MAX_MEMORY;
    SongNode *temp = songs;

    while(temp != NULL){
        left -= temp->s.getSize();
        temp = temp->next;
    }

    return left;
}

UtPod::~UtPod() {
clearMemory();
}
