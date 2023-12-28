#include <iostream>
#include <string>
#include "PlaylistNode.hpp"

using namespace std;

void PrintMenu(const string playlistTitle) {
   cout << endl << playlistTitle << " PLAYLIST MENU" << endl;
   cout << "a - Add song" << endl;
   cout << "d - Remove song" << endl;
   cout << "c - Change position of song" << endl;
   cout << "s - Output songs by specific artist" << endl;
   cout << "t - Output total time of playlist (in seconds)" << endl;
   cout << "o - Output full playlist" << endl;
   cout << "q - Quit" << endl << endl;
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
   
   PlaylistNode* currNode = headNode;
   PlaylistNode* tailNode = headNode;
   int length = 0; //Length of playlist
    //Sets tailNode to the tailNode in the playlist
   if(headNode != NULL && headNode->GetNext() != nullptr) {
      while(tailNode->GetNext() != nullptr) {
         tailNode = tailNode->GetNext();
         length++;
      }
   }
    
    //Adds song to the end of the playlist
   if(option == 'a') {
      cout << endl << "ADD SONG" << endl;
       string id, song, name, length;
      cout << "Enter song's unique ID:" << endl;
       getline(cin,id);
      cout << "Enter song's name:" << endl;
      getline(cin,song);
      cout << "Enter artist's name:" << endl;
      getline(cin,name);
      cout << "Enter song's length (in seconds):" << endl;
       getline(cin,length);
       int leg = stoi(length);
      PlaylistNode* newNode = new PlaylistNode(id, song, name, leg); //Creates new song as PlaylistNode
       tailNode->InsertAfter(newNode); //Adds new node to the end of the playlist
   }
    //Removes a song from the playlist by unique ID
   else if(option == 'd') {
      cout << endl << "REMOVE SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      string id;
      getline(cin,id);
      bool found = false;
      while(!found) {
         PlaylistNode* temp = currNode->GetNext(); //Retrieves next node
         if(temp->GetID() == id) {
            found = true;
            cout << "\"" << currNode->GetNext()->GetSongName() << "\" removed." << endl;
            currNode->SetNext(currNode->GetNext()->GetNext()); //Sets current node's next node to the node after the removed song
         }
          currNode = currNode->GetNext(); //Increments currNode
      }
   }
    //Moves a song to another position
   else if(option == 'c') {
      cout << endl << "CHANGE POSITION OF SONG" << endl;
      cout << "Enter song's current position:" << endl;
      int currPos;
       string currPosS;
       getline(cin,currPosS);
       currPos = stoi(currPosS);
      cout << "Enter new position for song:" << endl;
      int newPos;
       string newPosS;
      getline(cin,newPosS);
       newPos = stoi(newPosS);
      if(newPos < 1) {
         newPos = 1;
      } else if(newPos > length) {
         newPos = length;
      }
      //Insert after
      PlaylistNode* moveNode = headNode; //Node of the song that is going to be moved
      for(int i = 0; i < currPos-1; i++) {
         moveNode = moveNode->GetNext();
      }
      PlaylistNode* newNode = headNode; //Node of the song right before the position that the song will be moved to
      if(currPos > newPos) {
         for(int i = 0; i < newPos-1; i++) {
            newNode = newNode->GetNext();
         }
      } else {
         for(int i = 0; i < newPos; i++) {
            newNode = newNode->GetNext();
         }
      }
      cout << "\"" << (moveNode->GetNext())->GetSongName() << "\"" << " moved to position " << newPos << endl;
      PlaylistNode* temp = moveNode->GetNext(); //Sets temporary node to the node of the song being moved
      moveNode->SetNext(temp->GetNext()); //Sets the node before the song being moved to the song after the song being moved
       newNode->InsertAfter(temp); //Sets position of new node in the playlist
   }
   //Outputs all songs by a given artist
   else if(option == 's') {
      cout << endl << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
      cout << "Enter artist's name:";
      string name;
      getline(cin,name,'\n');
      int i = 0;
      cout << endl;
      while(currNode->GetNext() != nullptr) {
         i++;
         currNode = currNode->GetNext();
         if(currNode->GetArtistName() == name) {
            cout << endl;
            cout << i << "." << endl;
            currNode->PrintPlaylistNode(); //Prints out information each time song by artist is found
         }
      }
   }
   //Outputs total time of all songs in a playlist
   else if(option == 't') {
      cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
      cout << "Total time: ";
      int totalTime = 0;
      while(currNode->GetNext() != nullptr) { //Iterates through playlist and adds all of the seconds together
         currNode = currNode->GetNext();
         totalTime += currNode->GetSongLength();
      }
      cout << totalTime << " seconds" << endl;
   }
   //Outputs full playlist
   else if(option == 'o') {
      cout << endl << playlistTitle << " - OUTPUT FULL PLAYLIST";
      if(headNode != NULL && headNode->GetNext() != nullptr) {
         int i = 0;
         while(currNode->GetNext() != nullptr) {
             cout << endl;
            i++;
            cout << i << "." << endl;
            currNode = currNode->GetNext();
            currNode->PrintPlaylistNode();
         }
         return headNode; //Stops method by returning headNode
      }
      cout << endl << "Playlist is empty" << endl; //Prints only if playlist is empty
   }
   //Quits the program
   else if(option == 'q') {
      cout << endl;
   }
   //Valid character was not entered from menu
   else {
       cout << "Please enter valid character" << endl;
   }
   return headNode; //Ends method by returning headNode
   
}

int main() {
   
   PlaylistNode* headNode = new PlaylistNode(); //Beginning of playlist
   
   string playlistTitle;
   cout << "Enter playlist's title:" << endl;
   getline(cin,playlistTitle,'\n'); //Gets full line of text
   
   char userResponse;
   string uR;
    //Initial place for user to enter character
   PrintMenu(playlistTitle);
   cout << "Choose an option:";
   cin >> userResponse;
   cin.ignore(); //Ignores new line so that getline() can be used later on
   headNode = ExecuteMenu(userResponse, playlistTitle, headNode);
    //Executes until q is typed
   while(userResponse != 'q') {
      PrintMenu(playlistTitle);
      cout << "Choose an option:";
       cin >> userResponse;
       cin.ignore(); //Ignores new line so that getline() can be used later on
       headNode = ExecuteMenu(userResponse, playlistTitle, headNode); //Executes method
   }
   
   return 0;
}

