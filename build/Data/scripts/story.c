//Story System for OpenBOR
//Original by Volcanic; Modifications by CRxTRDude

//story.c
//the main displaying logic for the story system.

#include "data/scripts/story/story_screen.c"
#include "data/scripts/common/commons.c"
#include "data/scripts/common/playsnd.c"

//gcd function for aspect ratio. Thanks to 
//Jack at StackOverflow for this code.
//http://stackoverflow.com/questions/19738919/gcd-function-for-c
int gcd (int a, int b) {
    int temp;
    while (b != 0)
    {
        temp = a % b;

        a = b;
        b = temp;
    }
    return a;
}

//storySystem()
//main function to draw dialogs

void storySystem()
{
	//This only works if the story_switch indexed var is set to 1.
	//use the story_switch indexed var for detecting if the story
	//is applied.
	if(getindexedvar(story_switch))
	{
		//grabbed from the dialog script vars        
		void name	=	getindexedvar(story_msgName);
		void portrait	=	getindexedvar(story_msgPortrait);
		void dir	=	getindexedvar(story_dir);
		
		char msg	=	getindexedvar(story_msg1);
		char msgn	=	getindexedvar(story_msg2);
		char name	=	getindexedvar(story_msgName);		
		
		//grabbed from the scroll script vars
		void backf	=	getindexedvar(story_backfile);
		void backf2	=	getindexedvar(story_backfile2);
		void backf3	=	getindexedvar(story_backfile3);

		void back	=	getindexedvar(story_back);
		void back2	=	getindexedvar(story_back2);
		void back3	=	getindexedvar(story_back3);

		//Local Variables
		//for this script only.		
		void spr	=	getlocalvar("story."+portrait); // Single sprite
		void sprites = getlocalvar("story.array."+portrait); // Array of sprites
		
		void ctc	=	getlocalvar("story.ctc");
		void ctc1	=	getlocalvar("story.ctc1");
		void ctc_x = getlocalvar("story.ctc_x");
		void ctc_y = getlocalvar("story.ctc_y");
		
		void frame_x = getlocalvar("story.frame_x"); 
		void frame_y = getlocalvar("story.frame_y"); 
		void frame_w = getlocalvar("story.frame_w");
		void frame_h = getlocalvar("story.frame_h"); 
		void frame_color = getlocalvar("story.frame_color");

		//define how many sprites are in the sprite array.
		int numberOfSprites = sprites ? size(sprites) : 0;
		
		//The text object indexes. Since indexing in text objects is
		//dissimilar to indexed variables, you don't have to worry
		//about this.
		void txt_name = 0;
		void txt_msg1 = 1;
		void txt_msg2 = 2;
		
		//Variables to make the system resolution independent.		
		void ar_gcd = gcd(res_x, res_y);
		void ar_x	= res_x/ar_gcd;
		void ar_y = res_y/ar_gcd;
		
		void x		=	0;
		void y		= 0; 
		
		//Variables for the screens.
		void scr	=	getSpriteScreen();
		void dialogscr = getDialogScreen();
		void istextdisplayed = getindexedvar(story_isDisplayDialog);
		
		clearSpriteScreen();
		clearDialogScreen();
		
		if(name==NULL())return;

		//Initialize Vars*
		if(dir==NULL())dir=0;
		
		if (!sprites){
			sprites = array(1);
			log("Allocating sprite : " + portrait + " ...\n");
			
			void filename;
			void fullStr = portrait;
			void resteStr = strinfirst(fullStr, ":"); //use colon as separator

			if(resteStr == NULL() || resteStr == "" || resteStr == -1){
			//Solo sprites
				if(!spr){
					spr=loadsprite("data/story/portrait/"+portrait);
					if (spr == NULL()) shutdown (1, "STORY: File not found '"+spr+"\n\n");
					setlocalvar("story."+portrait, spr);
				}
				set(sprites, numberOfSprites, spr);
				log("Sprite allocated : " + spr + "\n");
				
			}else {
			//Array of sprites
				while(resteStr != NULL() && resteStr != "" && resteStr != -1){
					int pos = strlength(fullStr) - strlength(resteStr);
					filename = strleft(fullStr, pos);
					spr = getlocalvar("story."+filename); //similar to story.portrait
					if (!spr){
						spr = loadsprite("data/story/portrait/"+filename);
						setlocalvar("story."+filename, spr);
					}
					set(sprites, numberOfSprites, spr);
					log("Sprite allocated : " + filename + "\n");
					fullStr = strright(resteStr, 1);
					resteStr = strinfirst(fullStr, ":");
					numberOfSprites++;
				}
			}
			setlocalvar("story.array."+portrait, sprites);
		}
		
		if (!ctc_y){
			//Define the frame
			//First determine if it's either 4:3 or not.
			//Else we use a more smaller version on
			//other aspect ratios.
			if ((ar_x == 4) && (ar_y == 3)){
				frame_x = res_x*0.02;
				frame_y = res_y*0.45;
				frame_w = res_x - ((frame_x*2)-1);
				frame_h = 60;
			}
			else{ 
				frame_x = res_x*0.2;
				frame_y = res_y*0.45;
				frame_w = res_x - ((frame_x*2)-1);
				frame_h = 60;
			}
			setlocalvar("story.frame_x",frame_x);
			setlocalvar("story.frame_y",frame_y);
			setlocalvar("story.frame_w",frame_w);
			setlocalvar("story.frame_h",frame_h);			
			
			//Define the click to continue sprite (the arrow icon
			//at the bottom of the text box).
			
			ctc=loadsprite("data/story/sprites/story_ctc");
			ctc1=loadsprite("data/story/sprites/story_ctc1");
			ctc_x = (frame_x + frame_w) - 21;
			ctc_y = (frame_y + frame_h) - 13;
			setlocalvar("story.ctc",ctc);
			setlocalvar("story.ctc1",ctc1);
			setlocalvar("story.ctc_x",ctc_x);
			setlocalvar("story.ctc_y",ctc_y);
		}
		if(!back){
			if (backf!=NULL()){
				back=loadsprite(backf);
				setindexedvar(story_back,back);
			}
			if (backf2!=NULL()){
				back2=loadsprite(backf2);
				setindexedvar(story_back2,back2);
			}
			if (backf3!=NULL()){
				back3=loadsprite(backf3);
				setindexedvar(story_back3,back3);
			}
		}
		
		if (dir){
			frame_color = rgbcolor(210,91,91);
			setlocalvar("story.frame_color",frame_color);
		}else{
			frame_color = rgbcolor(91,107,210);
			setlocalvar("story.frame_color",frame_color);
		}
		
//Start drawing here.		
		
		//Draw Alpha Background*
		drawbox(0,0,res_x,res_y,1000,0,6);
		
		//Draw Background*
		if(back2==NULL()){
			if(back)drawspritetoscreen(back,scr,0,0);
		}else{
			//drawboxtoscreen(scr,0,0,480,272,0);
			if(back)drawspritetoscreen(back,scr,0,0);
			setdrawmethod(NULL(),1,256,256,0,0,0,1);
			if(back)drawspritetoscreen(back2,scr,0,0);
			if(back)drawspritetoscreen(back3,scr,0,0);
			setdrawmethod(NULL(),0,256,256,0,0,0,0);
		}

		//Draw Sprite*
		
		//calculate the resolution before applying.
				
		if(dir) x=res_x*0.96;
		else 	x=res_x*0.03;
		
		changedrawmethod(NULL(), "channelg", 220);
		changedrawmethod(NULL(), "channelr", 220);
		changedrawmethod(NULL(), "channelb", 220);
		
		setdrawmethod(NULL(),1,256,256,dir,0,0,0,0);
							
		int yOffset;
		if(numberOfSprites == 0){
			// for solo sprites.
			if(spr){
				y = res_y - getgfxproperty(spr,"height");
				drawspritetoscreen(spr,scr,res_x,y);
			}
			
		} else {
			// for array of sprites
			int xOffset = 0;

			int i;
			for(i=numberOfSprites-1; i>=0; i--){
				spr = get(sprites, i);
				y = res_y - getgfxproperty(spr,"height");
				drawspritetoscreen(spr, scr, x+xOffset, y);
				
				//You can adjust the spacing of the chars when
				//displaying multiple sprites here. Default is
				//0.45, which is enough for two sprites on
				//the resolution of 320x240 on sprites with height no
				//less than 240 px high.
				
				if(dir) xOffset -= getgfxproperty(spr,"width")*0.4;
				else xOffset += getgfxproperty(spr,"width")*0.4;
			}
		}
		setdrawmethod(NULL(),0,256,256,0,0,0,0,0);
		
		drawSpriteScreen();
		
		//if(getlocalvar("story.array."+portrait)){
		//	free(getlocalvar("story.array."+portrait));
		//	setlocalvar("story.array."+portrait, NULL());
		//}

//Renders for the sprite ends here, proceeding to frame and text.		
		
		//Draw Frame here*
		drawbox(frame_x,frame_y,frame_w,frame_h,1200,frame_color,6);
		
		//Draw Click-to-Continue sprite*
		if(!getindexedvar(story_typing)){
	 		setdrawmethod(NULL(),1,256,256,0,0,0,6);
	
			if(openborvariant("elapsed_time")%120/60==1){
				drawspritetoscreen(ctc,dialogscr,ctc_x,ctc_y);
			}else{
				drawspritetoscreen(ctc1,dialogscr,ctc_x,ctc_y);
			}
			setdrawmethod(NULL(),0,256,256,0,0,0,0);
		}
		
		//Draw Text For Dialog *		
		if(!istextdisplayed){
			settextobj(txt_name,frame_x+5,frame_y+5,1,1300,name);		
			
			void typing = getindexedvar(story_typing);
			void fin;
			void char_length;
			float len;
			void charspeed = 120;
			void current_msg;
			void current_txtobj;
			void incr;
			void speed;
			void tick_var;
			void delta;
			void blip;       
			
			if (getindexedvar(story_speed) != NULL()){
				speed = getindexedvar(story_speed); 
			}
			else{
				speed = 20;
			}
			      
			if(getindexedvar(story_typing))
			{
				if (!getindexedvar(story_dialinit)){
					incr = 0;
					cleartextobj(txt_msg1);
					cleartextobj(txt_msg2);
					setindexedvar(story_timer, 0);
					setglobalvar("story_oldtick",openborvariant("elapsed_time"));
					setindexedvar(story_dialinit,1);
				}
				//1 - set length appropriately
				if (getindexedvar(story_state)==0){
					current_msg = msg;
					current_txtobj = txt_msg1;
				}
				else if (getindexedvar(story_state)==1){
					current_msg = msgn;
					current_txtobj = txt_msg2;
				}
				len = strlength(current_msg);
				//2 - type off the appropriate line
				if (getindexedvar(story_charlength) < len){
					if (getindexedvar(story_timer) < speed)
					{
						tick_var = getglobalvar("story_oldtick");
						delta = openborvariant("elapsed_time")-tick_var;
						setglobalvar("story_oldtick",openborvariant("elapsed_time"));
						//log("delta="+delta+"\n");
						incr = getindexedvar(story_timer)+delta;
						if (setindexedvar(story_timer, incr)){
							incr = 0;
						}
						//log(getindexedvar(story_timer)+"\n");
					}
					else if (getindexedvar(story_timer) >= speed)             
					{
						//Start of beeping function. Comment to disable.
						if (speed > 1)
						{	
							if (getchar(current_msg,getindexedvar(story_charlength)) != "_")
							{
								playSound("data/sounds/blipmale.wav");
							}
						}
						if (getchar(current_msg,getindexedvar(story_charlength)) != "_") {}
						switch(getchar(current_msg,getindexedvar(story_charlength)))
						{
							//left
							case "<":
								break;
							//right
							case ">":
								break;
							//up
							case "{":
								break;
							//down
							case "}":
								break;
							//attack
							case "|":
								break;
							//freespecial
							case "$":
								break;
							//jump
							case "~":
								break;
							//special
							case "@":
								break;
							//freespecial2
							case "&":
								break;
							//freespecial3
							case "^":
								break;
							default:
								fin = getindexedvar(story_text) + getchar(current_msg,getindexedvar(story_charlength));
								break;
						}if (getindexedvar(story_state)==0){
							settextobj(txt_msg1,frame_x+15,frame_y+20,0,1300,getindexedvar(story_text));
						}
						else if (getindexedvar(story_state)==1){
							settextobj(txt_msg2,frame_x+15,frame_y+32,0,1300,getindexedvar(story_text));
						}
						if(setindexedvar(story_text,fin)){
							fin = ""; 
						}
						char_length = (getindexedvar(story_charlength))+1;
						if (setindexedvar(story_charlength,char_length)){
							char_length = 0;
						}
						setindexedvar(story_timer, 0);       
					}  
				}
				//3 - switch the state once the line has been finished
				else if (getindexedvar(story_charlength) >= len){
					if (getindexedvar(story_state)==0){
						if (msgn!=NULL()){
							settextobj(txt_msg1,frame_x+15,frame_y+20,0,1300,msg);
							setindexedvar(story_text,"");
							setindexedvar(story_charlength,0);
							setindexedvar(story_state,1);
						}
						else{
							cleartextobj(txt_msg2);
							setindexedvar(story_state,2);
						}
					}
					else if (getindexedvar(story_state)==1){
						setindexedvar(story_state,2);
					}
					else{
						setindexedvar(story_text,"");
						setindexedvar(story_typing,0);
					}
				}
			}
			else{
					settextobj(txt_msg1,frame_x+15,frame_y+20,0,1300,msg);
					if (msgn!=NULL()){
						settextobj(txt_msg2,frame_x+15,frame_y+32,0,1300,msgn);
					}
					else{
						cleartextobj(txt_msg2);
					}
					istextdisplayed = 1;
					setindexedvar(story_isDisplayDialog, istextdisplayed);
			 }	
		}
		drawDialogScreen();
	}		
//Note that there's no cleartextobj commands in this
//script other than to detect if there is message2
//in a text file, this is because it is handled
//in the story_key.c which is the one that handles
//key capture.
}

//Transferred turnWhite into story.c to unclutter the
//updated.c as well as easing the installation process.

void turnWhite()
{
	void dir=getindexedvar(WHITE);
	
	if(!dir){return;}else{}

	void tick=get_tick();
	void w=getglobalvar("white.alpha");
	if(!w)
	{
		if(dir==1) w=0;
		else w=256;
	}
	
	if(dir==1) w+=tick*0.8;
	else w-=tick*0.8;

	if(dir==1)
	{
		if(w>255)w=255;
	}else{
		if(w<0)w=0;
	}
	setglobalvar("white.alpha",w);
	drawbox(0,0,res_x,res_y,900,rgbcolor(w,w,w),1);
}