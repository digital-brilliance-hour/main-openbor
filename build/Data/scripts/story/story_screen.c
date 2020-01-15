#include "data/scripts/story/story_define.h"

void getSpriteScreen()
{
	long scr=getglobalvar("scr");
	if (!scr){
		scr=allocscreen(res_x,res_y);
		setglobalvar("scr",scr);
	}
	return scr;
}
void getDialogScreen()
{
	long dialogscr=getglobalvar("dialogscr");
	if (!dialogscr){
		dialogscr=allocscreen(res_x,res_y);
		setglobalvar("dialogscr",dialogscr);
	}
	return dialogscr;
}
void clearSpriteScreen()
{
	long scr=getglobalvar("scr");
	if(scr)clearscreen(scr);
}
void clearDialogScreen()
{
	long dialogscr=getglobalvar("dialogscr");
	if(dialogscr)clearscreen(dialogscr);
}
void drawSpriteScreen()
{
	long scr=getglobalvar("scr");
	// draw screen first
	if(scr)drawscreen(scr,0,0,1100,0);
}
void drawDialogScreen()
{
	long dialogscr=getglobalvar("dialogscr");
	// draw dialog second
	if(dialogscr)drawscreen(dialogscr,0,0,1500,0);
}
