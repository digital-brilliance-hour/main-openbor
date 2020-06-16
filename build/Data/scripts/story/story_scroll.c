//story_scroll.c
//functions for text and image scrolling
//
//original by Volcanic
//modification by CRxTRDude

#include "data/scripts/story/story_screen.c"

int max=10;
char initBack="back1";
void line,space;

//scrollText(textfile, linecount, spacing, background, speed)
//creates scrolling text.

void scrollText(char txtfile,int linecount,int spacing,char back,float spd)
{	
	max=linecount*spacing;
	
	line = linecount;
	space = spacing;
	
	void init = getlocalvar("inited");
	//void added = getlocalvar("lineadded");

	initBack=back;
	
	int cr=getlocalvar("cr_file");
	float ll_oldtick=getlocalvar("oldtick");
	float ll_tick=openborvariant("elapsed_time");
	float ll_offset;
	long scr=getSpriteScreen();
	
	void back = getindexedvar(story_back);

	if (!back){
		if (initBack!=""){
			setindexedvar(story_back, loadsprite("data/story/bgs/"+initBack));
			setindexedvar(story_backfile, back);
		}
	}

	if (!ll_oldtick){ll_oldtick=ll_tick;}
	if (!cr){
		cr=openfilestream("data/story/"+txtfile);
		setlocalvar("cr_file",cr);
	}
	ll_offset=ll_tick - ll_oldtick;
	if (ll_offset<=0.9){ll_offset=1;}

	if (!init)
	{
		initLine();
		init = 1;
		setlocalvar("inited",init);
		log("done!\n");
	}else{
		if (!getlocalvar("end")){
			addLine(cr);
		}
		drawLine(cr,(ll_offset*spd));
		setlocalvar("oldtick",ll_tick);
		drawSpriteScreen();
	}
}

void initLine()
{
	int i;
	log("Initializing ... ");	
	for (i=0;i<line;i++)
	{
		setlocalvar("line"+i,"_");
		setlocalvar("line"+i+"_y",0);
	}
}

void addLine(int cr)
{
	char linea;
	long old_back;
	int i,font,y;
	float x;
	
	for (i=0;i<line;i++)
	{
		linea=getlocalvar("line"+i);
		if (!linea){
			//There's a string present?
			log("Adding line"+i+" ... ");
			linea=getfilestreamargument(cr,0,"string");
			font=getfilestreamargument(cr,1,"int");
			x=getfilestreamargument(cr,2,"float");
			if(!x){
				//This defines the distance of fonts in the text in their
				//specific font.
				//
				//You can place additional font numbers here as well, especially
				//if you want to place more fonts.
				if(font==1)
				{
					x=res_x*0.25;
				}else{
					x=res_x*0.10;
				}
			}
			if (font==-1)
			{
				old_back=getindexedvar(story_back);
				if(old_back){free(old_back);}
				setindexedvar(story_back, loadsprite("data/story/bgs/"+linea));
			}else{
				setlocalvar("line"+i,linea);
				setlocalvar("font"+i,font);
				setlocalvar("x"+i,x);	
				setlocalvar("line"+i+"_y",(res_y)+(max*i));
			}

			if (linea=="___")
			{
				setlocalvar("end",1);
				log("Final break detected.\n");
				return;
			}else{
				filestreamnextline(cr);
				log("line"+i+" Added.\n");
			}
		}
	}
}

void drawLine(int cr,float ll_offset)
{
	char linea,lineb;
	int i,y,font,x;
	int del;
	 
	long scr=getglobalvar("scr");
	void back=getindexedvar(story_back);
	clearscreen(scr);
	/*if(!back)
	{
		drawboxtoscreen(scr,0,0,res_x,res_y,0,0);
	}else{
		drawspritetoscreen(back,scr,0,0);
	}*/
	
	for (i=0;i<line;i++)
	{
		linea=getlocalvar("line"+i);
		if (linea){
			y=getlocalvar("line"+i+"_y");
			font=getlocalvar("font"+i);
			x=getlocalvar("x"+i);
			del = (res_y*0.1)*-1;
			
			if(!font){font=0;}
			if(!x){x=res_x;}
			setdrawmethod(NULL(),1,256,256,0,0,0,0);			
			drawstringtoscreen(scr,x,y,font,linea);
			setdrawmethod(NULL(),0,256,256,0,0,0,0);			
			if (y<del){
				if (linea=="___") jumptobranch("",1);
				setlocalvar("line"+i,NULL());
				setlocalvar("line"+i+"_y",NULL());
			}else{
				if (!openborvariant("game_paused")) setlocalvar("line"+i+"_y",y-ll_offset);
			}
		}
	}
}


// scrollPicture(back, spd, storypic, picheight)
// creates a scrolling picture

void scrollPicture(char back,float spd,char storypic,long picheight)
{	
	float ll_offset;
	long scroll_scr=getglobalvar("scr");
	void pic=getlocalvar("story.pic");
	void posy=getlocalvar("story.posy");
	void storyback=getindexedvar(story_back);
	float ll_oldtick=getlocalvar("oldtick");
	float ll_tick=openborvariant("elapsed_time");
	void init_y = getlocalvar("init.y");

	if (!scroll_scr){
		scroll_scr=allocscreen(res_x,res_y);
		setglobalvar("scr",scroll_scr);
	}
	
	clearscreen(scroll_scr);
	
	if(!init_y){
		posy=res_y;
		init_y = 1;
		setlocalvar("init.y", init_y);
	}
	
	if (!storyback){
		storyback=loadsprite("data/story/bgs/"+back);
		
		setindexedvar(story_back,storyback);
		
		setindexedvar(story_backfile,back);
	}
	if(!pic){
		pic=loadsprite("data/story/scroll/"+storypic);
		setlocalvar("story.pic",pic);
	}

	if (!ll_oldtick){ll_oldtick=ll_tick;}
	ll_offset=ll_tick - ll_oldtick;
	if (ll_offset<=0.9){ll_offset=1;}
	if (posy == 0){
		// there's a bug where once the speed goes up too much
		// it becomes 0, to fix that, make a negative of the
		// speed value to make it go further.
		// note that the game will not proceed if !posy<-picheight.
		posy = spd * -1;
	}
	else{
		posy -= ll_offset*spd;
	}

	//debug purposes:
	//log("ll_offset = "+ll_offset+"\n");	
	//log("posy = "+posy+"\n");

	void i;
	if(back)
		drawspritetoscreen(storyback,scroll_scr,0,0);
	if(pic)
		drawspritetoscreen(pic,scroll_scr,0,posy);

	setlocalvar("oldtick",ll_tick);
	setlocalvar("story.posy",posy);
	drawscreen(scroll_scr,0,0,1000,0);

	if (posy<-picheight)
	{
		jumptobranch("",1);
	}
}

