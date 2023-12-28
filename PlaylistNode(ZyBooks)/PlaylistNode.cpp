//
//  PlaylistNode.cpp
//  PlaylistNode(ZyBooks)
//
//  Created by paige on 10/25/23.
//

#include "PlaylistNode.hpp"

//Prints ID, name, artist, and length of song
//this-> refers to the variable of referenced object
void PlaylistNode::PrintPlaylistNode() {
   cout << "Unique ID: " << this->uniqueID << endl;
   cout << "Song Name: " << this->songName << endl;
   cout << "Artist Name: " << this->artistName << endl;
   cout << "Song Length (in seconds): " << this->songLength << endl;
}

//Inserts nodePtr in referenced object and next object
void PlaylistNode::InsertAfter(PlaylistNode* nodePtr) {
   PlaylistNode* temp = this->GetNext(); // RO --> 3
   this->SetNext(nodePtr); // RO --> nodePtr
   nodePtr->SetNext(temp); // RO --> nodePtr --> 3
}

//Inserts nodePtr as nextNodePtr of referenced object
void PlaylistNode::SetNext(PlaylistNode* nodePtr) {
   this->nextNodePtr = nodePtr;
}
