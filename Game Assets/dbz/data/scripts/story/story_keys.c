#include "data/scripts/story/story_define.h"

void storyKeys()
{
	//for scrolling
	if(getglobalvar("scr") && getindexedvar(story_backfile)!=NULL() && (playerkeys(0, 1, "start")))
	{
		jumptobranch("",1);
	}
	//for dialog
	dialogSkip();
}

void dialogSkip()
{
	if(getindexedvar(story_switch))
	{
		void ent=getindexedvar(STORY_ENT);
		void noskip=getindexedvar(story_isDialogSkip);
		if(ent)
		{
			if(playerkeys(0,0,"attack")){
				if (!getindexedvar(story_typing)){             
					setindexedvar(story_isDisplayDialog, 0);
					updateframe(ent,0);
				}
				else{
					void typing = getindexedvar(story_typing);
					typing = 0;
					setindexedvar (story_typing, typing);
				}
			}
			else if(playerkeys(0,0,"attack2") && !noskip)
			{
				if(!getindexedvar(story_backfile))
				{
					setindexedvar(story_switch,NULL());
					disableText();
				}
				setindexedvar(STORY_ENT,NULL());
				killentity(ent);
			}
		}
	}
}

void disableText()
{
	void txt_name = 0;
	void txt_msg1 = 1;
	void txt_msg2 = 2;
	cleartextobj(txt_name);
	cleartextobj(txt_msg1);
	cleartextobj(txt_msg2);
}