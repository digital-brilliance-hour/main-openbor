//Story System for OpenBOR
//Original by Volcanic; Modifications by CRxTRDude

//story_define.h
//header for the story engine

//Please reserve indexes 25-49 for the story system since this uses
//indexed variables.
//
//Note that you need to define maxindexedvars to a more larger value
//or modify the indexes so that it you can accomodate the story system
//along with your own indexed variables.

#ifndef STORY_DEFINED

#define STORY_DEFINED                     1
    
#define	WHITE 25					//For the white flash
#define	story_switch 26	//Switch for use with the story

#define	PAUSE 27				//Pausing
#define	STORY_ENT 28		//The story entity

//dialog system
#define story_msg1	29	//messages, first line
#define story_msg2	30	//messages, second line
#define story_msgName	31	//the name of the character speaking
#define story_msgPortrait	32	//portrait of the character speaking
#define story_dir	33	//direction of the character speaking.
#define story_isDisplayDialog 34 //just a compensatory flag for the text object.
#define story_playerGender 35	//gender of the player.

//scroll system's background vars and background file vars.
#define story_backfile 36
#define story_backfile2 37
#define story_backfile3 38

#define story_back 39
#define story_back2 40
#define story_back3 41

#define story_isDialogSkip 42

#define story_typing 43
#define story_charlength 44
#define story_text 45
#define story_state 46
#define story_timer 47
#define story_dialinit 48
#define story_speed 49

//resolution variables
#define	res_x	openborvariant("hResolution")
#define	res_y	openborvariant("vResolution")

#endif
