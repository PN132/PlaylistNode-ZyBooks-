//
//  PlaylistNode.hpp
//  PlaylistNode(ZyBooks)
//
//  Created by paige on 10/25/23.
//

#ifndef PlaylistNode_hpp
#define PlaylistNode_hpp

#include <stdio.h>

#include <iostream>

using namespace std;

using namespace std;

class PlaylistNode {
   private:
      string uniqueID;
      string songName;
      string artistName;
      int songLength;
      PlaylistNode* nextNodePtr; //Points to next node in the playlist
      
   public:
        //Default constructor
      PlaylistNode() {
         uniqueID = "none";
         songName = "none";
         artistName = "none";
         songLength = 0;
         nextNodePtr = nullptr;
      };
        //Parameterized constructor
      PlaylistNode(string uID, string sn, string an, int sl) {
         uniqueID = uID;
         songName = sn;
         artistName = an;
         songLength = sl;
         nextNodePtr = nullptr;
      };
        //Getter methods
      string GetID() const {return uniqueID;};
      string GetSongName() const {return songName;};
      string GetArtistName() const {return artistName;};
      int GetSongLength() const {return songLength;};
      PlaylistNode* GetNext() {return nextNodePtr;};
        //Logic methods 
      void InsertAfter(PlaylistNode* nodePtr);
      void SetNext(PlaylistNode* nodePtr);
      void PrintPlaylistNode();
   
};

#endif /* PlaylistNode_hpp */
