//Story System for OpenBOR
//Original by Volcanic; Modifications by CRxTRDude

//story_clear.c
//Function to clear the variables as the level
//ends.

//Call clearStory(); in endlevel.c so that this function
//can clear the variables, especially the global vars that
//could not be converted to indexed vars just yet.

#include "data/scripts/story/story_define.h"

void clearStory()
{
	long scr=getglobalvar("scr");
	void pic=getglobalvar("story.pic");
	if (scr){
		free(scr);
		setglobalvar("scr",NULL());
	}

	scr=getindexedvar(story_back);
	if (scr){
		free(scr);
		setindexedvar(story_back,NULL());
	}

	scr=getindexedvar(story_back2);
	if (scr){
		free(scr);
		setindexedvar(story_back2,NULL());
	}

	scr=getindexedvar(story_back3);
	if (scr){
		free(scr);
		setindexedvar(story_back3,NULL());
	}

	if(pic){
		free(pic);
		setglobalvar("story.pic",NULL());
	}

	setindexedvar(story_switch,0);
	setglobalvar("story.posy",NULL());
	setindexedvar(story_backfile,NULL());
	setindexedvar(story_backfile2,NULL());
	setindexedvar(story_backfile3,NULL());
	setglobalvar("oldtick",NULL());
	setindexedvar(story_switch,NULL());
	setindexedvar(story_msg1,NULL());
	setindexedvar(story_msg2,NULL());
	setindexedvar(story_msgName,NULL());
	setindexedvar(story_msgPortrait,NULL());
	setindexedvar(WHITE,NULL());
	setglobalvar("white.alpha",NULL());
}
