//Story System for OpenBOR
//Original by Volcanic; Modifications by CRxTRDude

//story_dialog.c
//character dialog system using text

#include "data/scripts/story/story_define.h"
#include "data/scripts/story/story_gender.c"
#include "data/scripts/common/playsnd.c"

void sendDialogMsg()
{
	//sendDialogMsg()
	//Parser for the dialog script text files.
	
	//acceptable 'name' strings:
	//_playsound 0 {file} - play sound effects.
	//_playmusic 0 {file} - rewrites and plays music
	//_quickpausemusic {var} - pauses music abruptly, but can be played back again.
	//_fadepausemusic {var} - fades and pauses music and can be played again.
	//
	
	void vSelf = getplayerproperty(0, "entity");
	if (vSelf==NULL()){vSelf=getplayerproperty(1, "entity");}
	if (vSelf==NULL()){vSelf=getplayerproperty(2, "entity");}
	if (vSelf==NULL()){vSelf=getplayerproperty(3, "entity");}
	void playername = getentityproperty(vSelf,"name");
	
	if (playername == "Kula" || playername == "Mandy") setindexedvar(story_playerGender,0);
	else setindexedvar(story_playerGender,1); 
	
	void	self	=	getlocalvar("self");
	void	filenumber	=	getlocalvar("fh");
	void	name	=	getfilestreamargument(filenumber,0,"string");
	void	dir		=	getfilestreamargument(filenumber,1,"int");
	void	tempmsg	=	getfilestreamargument(filenumber,2,"string");
	void	tempmsg2	=	getfilestreamargument(filenumber,3,"string");
	void	portrait		=	getfilestreamargument(filenumber,4,"string");
	void	message;
	void	message2;
	void	oldportrait;
	void	sound;
	void	portraitstring;
	void	back;
	
	if(tempmsg2==NULL()){
		tempmsg2="_";
	}
	
	message = genderParser(tempmsg);	
	message2 = genderParser(tempmsg2);
	
	//player detection
	void flagPlM1 = strinfirst(message, "%pl");
	void flagPlM2;
	
	//temporary strings	
	void	tempmsgA;
	void	tempmsgB;
	
	while (flagPlM1 != NULL() && flagPlM1 != "" && flagPlM1 != -1){
		int pos = strlength(message) - strlength(flagPlM1);
		tempmsgA = strleft(message,pos);
		tempmsgB = strright(message,pos+3);
		message = tempmsgA+playername+tempmsgB;
		flagPlM1 = strinfirst(message, "%pl");
	}
	
	if(message2 != NULL()){
		flagPlM2 = strinfirst(message2, "%pl");
		while (flagPlM2 != NULL() && flagPlM2 != "" && flagPlM2 != -1){
			int pos = strlength(message2) - strlength(flagPlM2);
			tempmsgA = strleft(message2,pos);
			tempmsgB = strright(message2,pos+3);
			message2 = tempmsgA+playername+tempmsgB;
			flagPlM2 = strinfirst(message2, "%pl");
		}
	}
	
	if (name=="end"){
		endStory();
	}else if(name=="_noskip"){
		setindexedvar(story_isDialogSkip,dir);
		filestreamnextline(filenumber);
		updateframe(self,0);		
	}
	else if(name=="_back"){
		if (dir){
			if(message != NULL()){
				setindexedvar(story_back, loadsprite("data/story/bgs/"+message));
				setindexedvar(story_backfile, back);
			}else shutdown(1,"STORY: _back 1 is empty. Check your dialog file.\n\n");	
		}else{
			setindexedvar(story_back, "_");
			setindexedvar(story_backfile, "_");
		}
		filestreamnextline(filenumber);
		updateframe(self,0);					
	}
//sound functions	
	else if(name=="_playsound"){
		playSound(message);
		filestreamnextline(filenumber);
		updateframe(self,0);
	}else if(name=="_playmusic"){
		playmusic(message,1);
		filestreamnextline(filenumber);
		updateframe(self,0);
	}else if(name=="_fadepausemusic"){
		fademusic(dir);
		filestreamnextline(filenumber);
		updateframe(self,0);
	}else if(name=="_quickpausemusic"){
		pausemusic(dir);
		filestreamnextline(filenumber);
		updateframe(self,0);
	}
//graphical functions
	else if(name=="_white"){
		setindexedvar(WHITE,1);
		filestreamnextline(filenumber);
		updateframe(self,0);
	}else if(name=="_normal"){
		setindexedvar(WHITE,-1);
		filestreamnextline(filenumber);
		updateframe(self,0);
	}
//dialog functions
	else if(name=="_speed"){
		setindexedvar(story_speed,dir);
		filestreamnextline(filenumber);
		updateframe(self,0);
	}
//rest of the functions
	else{
		if (name=="_player"){
			name = playername;
			oldportrait = portrait;
			if (portrait=="" || portrait==NULL() ||portrait=="_") portrait=playername;
			else {
				portraitstring = strinfirst(portrait,":");
				if (portraitstring != -1)	portrait=oldportrait;
				else portrait=playername+"_"+oldportrait; 	
			}
		} 	
		else if (portrait=="" || portrait==NULL() ||portrait=="_") portrait=name;
				
		if (dir==""||dir==NULL()){dir=0;}

		setindexedvar(story_msg1,message);
		if (message2!="" || message2!=NULL() || message2!="_"){
			setindexedvar(story_msg2,message2);
		}
		else{
			message2 = NULL();
			setindexedvar(story_msg2,message2);
		}
		setindexedvar(story_msgName,name);
		setindexedvar(story_msgPortrait,portrait);
		setindexedvar(story_dir,dir);
		setindexedvar(story_isDisplayDialog, 0);
		setindexedvar(story_state,0);
		setindexedvar(story_charlength, 0);
		setindexedvar(story_text,"");
		setindexedvar(story_dialinit,0);
		if (getindexedvar(story_speed)==NULL() || getindexedvar(story_speed)==10){
			setindexedvar(story_speed,NULL());
		}
		else if(getindexedvar(story_speed)==0)
		{
			setindexedvar(story_state,2);
		}
		setindexedvar(story_typing, 1);

		filestreamnextline(filenumber);
		setindexedvar(story_switch,1);
	}
}

void talk()
{
	void self = getlocalvar("self");
	char dialogname=getentityproperty(self,"name");

	setindexedvar(STORY_ENT,self);
	setindexedvar(PAUSE,0);
	if (dialogname!="story"){
		setlocalvar("fh",openfilestream("data/story/"+dialogname+".txt"));
		changeentityproperty(self, "animation", openborconstant("ANI_FREESPECIAL"));
		log("STORY: Loaded "+dialogname+".txt\n");
	} else shutdown(1,"STORY: Invalid filename. 'Story' entity should have an alias with the name\nof the story text file without the '.txt'\n\n");	
}

void endStory()
{
	//define the dialog text object indexes
	void txt_name = 0;
	void txt_msg1 = 1;
	void txt_msg2 = 2;
	
	//if there's no backfile then disable credit scroll screen
	if(!getindexedvar(story_backfile))
	{
		setindexedvar(PAUSE,0);
		setindexedvar(story_switch,NULL());
	}
	//clear the text objects
	cleartextobj(txt_name);
	cleartextobj(txt_msg1);
	cleartextobj(txt_msg2);
	setindexedvar(story_speed,NULL());
	setindexedvar(STORY_ENT,NULL());
	killentity(getlocalvar("self"));
}
