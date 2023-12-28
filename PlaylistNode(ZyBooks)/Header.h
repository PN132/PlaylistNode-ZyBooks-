//
//  Header.h
//  PlaylistNode(ZyBooks)
//
//  Created by paige on 11/3/23.
//

#ifndef Header_h
#define Header_h

/*
 
 8.19 LAB*: Program: Playlist
 You will be building a linked list. Make sure to keep track of both the head and tail nodes.
 Worked on: 10/23/23 - 11/3/23
 Class: COMP-200
 
 ----------------------------------------------------------------------------------------------------------------

 Step 1: Create three files to submit and build the PlaylistNode class.
 PlaylistNode.h - Class declaration
 PlaylistNode.cpp - Class definition
 main.cpp - main() function
 Build the PlaylistNode class per the following specifications. Note: Some functions can initially be function stubs (empty functions), to be completed in later steps.

 Private data members
 string uniqueID - Initialized to "none" in default constructor
 string songName - Initialized to "none" in default constructor
 string artistName - Initialized to "none" in default constructor
 int songLength - Initialized to 0 in default constructor
 PlaylistNode* nextNodePtr - Initialized to 0 in default constructor
 Default constructor (1 pt)
 Parameterized constructor (1 pt)
 Public member functions
 GetID() - Accessor
 GetSongName() - Accessor
 GetArtistName() - Accessor
 GetSongLength() - Accessor
 GetNext() - Accessor
 InsertAfter(PlaylistNode* nodePtr) - Mutator (1 pt)
 SetNext(PlaylistNode* nodePtr) - Mutator (1 pt)
 PrintPlaylistNode() - Outputs uniqueID, songname, artistName, and songLength based on the format example below.
 Ex. of PrintPlaylistNode output:

 Unique ID: S123
 Song Name: Peg
 Artist Name: Steely Dan
 Song Length (in seconds): 237
 
 ----------------------------------------------------------------------------------------------------------------
 
 Step 2: In main(), prompt the user for the title of the playlist. (1 pt)
 Ex:

 Enter playlist's title:
 JAMZ
 
 ----------------------------------------------------------------------------------------------------------------

 Step 3: Implement the PrintMenu() function. (1 pt)
 PrintMenu() takes the playlist title as a parameter and outputs a menu of options to manipulate the playlist.

 Ex:

 JAMZ PLAYLIST MENU
 a - Add song
 d - Remove song
 c - Change position of song
 s - Output songs by specific artist
 t - Output total time of playlist (in seconds)
 o - Output full playlist
 q - Quit
 
 ----------------------------------------------------------------------------------------------------------------

 Step 4: Implement the ExecuteMenu() function. (1 pt)
 ExecuteMenu() takes 3 parameters: a character representing the user's choice, a playlist title, and the pointer to the head node of a playlist. ExecuteMenu() performs the menu options (described below) according to the user's choice and returns the pointer to the head node of the playlist.

 ----------------------------------------------------------------------------------------------------------------

 Step 5: In main(), call PrintMenu() and prompt for the user's choice of menu options. (1 pt)
 Each option is represented by a single character. If an invalid character is entered, continue to prompt for a valid choice. When a valid option is entered, execute the option by calling ExecuteMenu(). Then, print the menu, and prompt for a new option. Continue until the user enters 'q'. Hint: Implement Quit before implementing other options.

 Ex:

 JAMZ PLAYLIST MENU
 a - Add song
 d - Remove song
 c - Change position of song
 s - Output songs by specific artist
 t - Output total time of playlist (in seconds)
 o - Output full playlist
 q - Quit

 Choose an option:
 
 ----------------------------------------------------------------------------------------------------------------

 Step 6: Implement "Output full playlist" menu option in ExecuteMenu(). (3 pts)
 If the list is empty, output: Playlist is empty

 Ex:

 JAMZ - OUTPUT FULL PLAYLIST
 1.
 Unique ID: SD123
 Song Name: Peg
 Artist Name: Steely Dan
 Song Length (in seconds): 237

 2.
 Unique ID: JJ234
 Song Name: All For You
 Artist Name: Janet Jackson
 Song Length (in seconds): 391

 3.
 Unique ID: J345
 Song Name: Canned Heat
 Artist Name: Jamiroquai
 Song Length (in seconds): 330

 4.
 Unique ID: JJ456
 Song Name: Black Eagle
 Artist Name: Janet Jackson
 Song Length (in seconds): 197

 5.
 Unique ID: SD567
 Song Name: I Got The News
 Artist Name: Steely Dan
 Song Length (in seconds): 306
 
 ----------------------------------------------------------------------------------------------------------------

 Step 7: Implement the "Add song" menu option in ExecuteMenu(). (2 pts)
 New additions are added to the end of the list.

 Ex:

 ADD SONG
 Enter song's unique ID:
 SD123
 Enter song's name:
 Peg
 Enter artist's name:
 Steely Dan
 Enter song's length (in seconds):
 237
 
 ----------------------------------------------------------------------------------------------------------------

 Step 8: Implement the "Remove song" menu option in ExecuteMenu(). (4 pts)
 Prompt the user for the unique ID of the song to be removed.

 Ex:

 REMOVE SONG
 Enter song's unique ID:
 JJ234
 "All For You" removed.
 
 ----------------------------------------------------------------------------------------------------------------

 Step 9: Implement the "Change position of song" menu option in ExecuteMenu().
 Prompt the user for the current position of the song and the desired new position. Valid new positions are 1 - n (the number of nodes). If the user enters a new position that is less than 1, move the node to the position 1 (immediately after the head). If the user enters a new position greater than n, move the node to position n (the tail). 6 cases will be tested:

 Moving the head node (1 pt)
 Moving the tail node (1 pt)
 Moving a node to the head (1 pt)
 Moving a node to the tail (1 pt)
 Moving a node up the list (1 pt)
 Moving a node down the list (1 pt)
 Ex:

 CHANGE POSITION OF SONG
 Enter song's current position:
 3
 Enter new position for song:
 2
 "Canned Heat" moved to position 2
 
 ----------------------------------------------------------------------------------------------------------------

 Step 10: Implement the "Output songs by specific artist" menu option in ExecuteMenu(). (2 pt)
 Prompt the user for the artist's name, and output the node's information, starting with the node's current position.

 Ex:

 OUTPUT SONGS BY SPECIFIC ARTIST
 Enter artist's name:
 Janet Jackson

 2.
 Unique ID: JJ234
 Song Name: All For You
 Artist Name: Janet Jackson
 Song Length (in seconds): 391

 4.
 Unique ID: JJ456
 Song Name: Black Eagle
 Artist Name: Janet Jackson
 Song Length (in seconds): 197
 
 ----------------------------------------------------------------------------------------------------------------

 Step 11: Implement the "Output total time of playlist" menu option in ExecuteMenu(). (2 pts)
 Output the sum of the time of the playlist's songs (in seconds).

 Ex:

 OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)
 Total time: 1461 seconds
 
 */


#endif /* Header_h */
