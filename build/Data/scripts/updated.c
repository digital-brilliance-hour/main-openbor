#include "data/scripts/common/constants.h"
#include "data/scripts/story/story_define.h"
#include "data/scripts/story.c"
#include "data/scripts/gettick.c"
#include "data/scripts/story/story_screen.c"


void main()
{
	mainLoop();
}

void mainLoop()
{ 
  void bckground = getglobalvar("bckground");
	if(SYS_INLEVEL)
	{
		inLevelLoop();
    void counter = getlocalvar("counter"); 
    void logocounter = getlocalvar("logocounter");
    void gameovercounter = getlocalvar("gameovercounter");
    void stagecompletecounter = getlocalvar("stagecompletecounter");
    void titlecounter = getlocalvar("titlecounter");
    void titlemcounter = getlocalvar("titlemcounter");
    void hofcounter = getlocalvar("hofcounter");
    if (counter!="0"){
    setlocalvar("counter",0); 
    }
    if (logocounter!="0"){
    setlocalvar("logocounter",0); 
    }
    if (gameovercounter!="0"){
    setlocalvar("gameovercounter",0); 
    }
    if (titlecounter!="0"){
    setlocalvar("titlecounter",0); 
    }
    if (titlemcounter!="0"){
    setlocalvar("titlemcounter",0); 
    }
    if (hofcounter!="0"){
    setlocalvar("hofcounter",0); 
    }
    if (stagecompletecounter!="0"){
    setlocalvar("stagecompletecounter",0);
    }
	}
	if (SYS_SCENE == "data/scenes/intro.txt"){
    
    void titlecounter = getlocalvar("titlecounter");
    if (titlecounter!="0"){
    setlocalvar("titlecounter",0); 
    }
		/*if(SYS_INMENU) {
			void background = loadsprite("data/bgs/title.png");
			drawsprite(background, 0, 0, 0, 0);
		}
		else if(SYS_INTITLE) {
			void background = loadsprite("data/bgs/title.png");
			drawsprite(background, 0, 0, 0, 0);

		}
		if(SYS_INMENU || SYS_INTITLE){
			drawstring(110,40,3,"Story System EdItIon");
			drawstring(124,212,0,"CRxTRDude 2014");
		}*/
	}
  if (SYS_SCENE == "data/scenes/logo.txt"){
    void titlecounter = getlocalvar("titlecounter");
    if (titlecounter!="0"){
    setlocalvar("titlecounter",0); 
    }
    void titlemcounter = getlocalvar("titlemcounter");
    if (titlemcounter!="0"){
    setlocalvar("titlemcounter",0); 
    }
      /*void logocounter = getlocalvar("logocounter"); 
      while(logocounter!=1)
      {
        void subent;
        loadmodel("kc-logo"); // name of the entity to be loaded
        void scr  = getSpriteScreen();
        void back=loadsprite("data/sprites/logo-sprite.png");
        clearspawnentry(); // clean the spawn entry
        setspawnentry("name", "kc-logo"); // define the entity to be spawn
        setspawnentry("coords", 0,0,-1); // set the position of the entity
        subent=spawn();  //  spawn the entity
        changeentityproperty(subent, "position", 0,0,-1); //for safe, set again the position
        drawspritetoscreen(back,scr,0,0);
        logocounter = setlocalvar("logocounter",1); // turn on the variable, blocking a new spawn to be made
      }*/
  }

  if(SYS_INTITLE) {
    void titlemcounter = getlocalvar("titlemcounter"); 
    while(titlemcounter!=1)
    {
      titleMusic();
      titlemcounter = setlocalvar("titlemcounter",1);
    }
  }
  if(SYS_INMENU) {
    void titlemcounter = getlocalvar("titlemcounter");
    if (titlemcounter!="0"){
    setlocalvar("titlemcounter",0); 
    }

  }

  if(SYS_INMENU || SYS_INTITLE){
    void counter = getlocalvar("counter"); 
    if (counter!="0"){
    setlocalvar("counter",0); 
    }
    void hofcounter = getlocalvar("hofcounter");
    if (hofcounter!="0"){
    setlocalvar("hofcounter",0); 
    }
    void logocounter = getlocalvar("logocounter"); 
    if (logocounter!="0"){
    setlocalvar("logocounter",0); 
    }
     void titlecounter = getlocalvar("titlecounter"); 
      while(titlecounter!=1)
      {
        void subent, subent2; 
        int iValid = getentityproperty(bckground, "exists");
        if(iValid){
          killentity(bckground);
        }
        
        loadmodel("titleanimation"); // name of the entity to be loaded
        clearspawnentry(); // clean the spawn entry
        setspawnentry("name", "titleanimation"); // define the entity to be spawn
        setspawnentry("coords", 1,1,-1000); // set the position of the entity
        subent=spawn();  //  spawn the entity
        setglobalvar("bckground", subent);
        changeentityproperty(subent, "position", 1,1,-1000); //for safe, set again the position


        /*loadmodel("monkanimation"); // name of the entity to be loaded
        clearspawnentry(); // clean the spawn entry
        setspawnentry("name", "monkanimation"); // define the entity to be spawn
        setspawnentry("coords", -216,1,-1000); // set the position of the entity
        subent=spawn();  //  spawn the entity
        changeentityproperty(subent, "position", -216,1,-1000); //for safe, set again the position*/

        loadmodel("titlesprite"); // name of the entity to be loaded
        clearspawnentry(); // clean the spawn entry
        setspawnentry("name", "titlesprite"); // define the entity to be spawn
        setspawnentry("coords", 26,30,-1); // set the position of the entity
        subent2=spawn();  //  spawn the entity
        changeentityproperty(subent2, "position", 26,30,-1); //for safe, set again the position
        titlecounter = setlocalvar("titlecounter",1); // turn on the variable, blocking a new spawn to be made
      }

  }

  if(openborvariant("in_showcomplete") == 1) {
    void titlecounter = getlocalvar("titlecounter");
    if (titlecounter!="0"){
    setlocalvar("titlecounter",0); 
    }
    void hofcounter = getlocalvar("hofcounter");
    if (hofcounter!="0"){
    setlocalvar("hofcounter",0); 
    }
    void titlemcounter = getlocalvar("titlemcounter");
    if (titlemcounter!="0"){
    setlocalvar("titlemcounter",0); 
    }
    void stagecompletecounter = getlocalvar("stagecompletecounter"); 
      while(stagecompletecounter!=1)
      {
        void subent;
        loadmodel("nightskyanimation"); // name of the entity to be loaded
        clearspawnentry(); // clean the spawn entry
        setspawnentry("name", "nightskyanimation"); // define the entity to be spawn
        setspawnentry("coords", -1,0,-1); // set the position of the entity
        subent=spawn();  //  spawn the entity
        changeentityproperty(subent, "position", 1,1,-1); //for safe, set again the position
        setglobalvar("bckground", subent);
        stagecompletecounter = setlocalvar("stagecompletecounter",1); // turn on the variable, blocking a new spawn to be made
      }
  }

  if(openborvariant("in_halloffamescreen")==1){
    void titlecounter = getlocalvar("titlecounter");
    if (titlecounter!="0"){
    setlocalvar("titlecounter",0); 
    }
    void titlemcounter = getlocalvar("titlemcounter");
    if (titlemcounter!="0"){
    setlocalvar("titlemcounter",0); 
    }
    void hofcounter = getlocalvar("hofcounter"); 
    log(hofcounter);
      while(hofcounter!=1)
      {
        highScoreMusic();
        void subent;
        loadmodel("waterfallanimation"); // name of the entity to be loaded
        clearspawnentry(); // clean the spawn entry
        setspawnentry("name", "waterfallanimation"); // define the entity to be spawn
        setspawnentry("coords", -1,0,-1); // set the position of the entity
        subent=spawn();  //  spawn the entity
        changeentityproperty(subent, "position", 1,1,-1); //for safe, set again the position
        setglobalvar("bckground", subent);
        hofcounter = setlocalvar("hofcounter",1); // turn on the variable, blocking a new spawn to be made
      }
  }

  if(openborvariant("in_gameoverscreen") == 1) {
    void titlecounter = getlocalvar("titlecounter");
    if (titlecounter!="0"){
    setlocalvar("titlecounter",0); 
    }
    void hofcounter = getlocalvar("hofcounter");
    if (hofcounter!="0"){
    setlocalvar("hofcounter",0); 
    }
    void titlemcounter = getlocalvar("titlemcounter");
    if (titlemcounter!="0"){
    setlocalvar("titlemcounter",0); 
    }
    void gameovercounter = getlocalvar("gameovercounter"); 
      while(gameovercounter!=1)
      {
        void subent;
        loadmodel("monkanimation"); // name of the entity to be loaded
        clearspawnentry(); // clean the spawn entry
        setspawnentry("name", "monkanimation"); // define the entity to be spawn
        setspawnentry("coords", -216,1,-1000); // set the position of the entity
        subent=spawn();  //  spawn the entity
        changeentityproperty(subent, "position", -216,1,-1000); //for safe, set again the position
        setglobalvar("bckground", subent);
        gameovercounter = setlocalvar("gameovercounter",1); // turn on the variable, blocking a new spawn to be made
      }
  }

	if(openborvariant("in_selectscreen")==1){
      void titlemcounter = getlocalvar("titlemcounter");
      if (titlemcounter!="0"){
      setlocalvar("titlemcounter",0); 
      }
      void titlecounter = getlocalvar("titlecounter");
      if (titlecounter!="0"){
      setlocalvar("titlecounter",0); 
      }
      int models_cached = openborvariant("models_cached");
      int i = 0;
      int C = getglobalvar("Load");
      void counter = getlocalvar("counter"); 
      while(counter!=1)
      {
        void subent, subent2;
        loadmodel("selectanimation"); // name of the entity to be loaded
        clearspawnentry(); // clean the spawn entry
        setspawnentry("name", "selectanimation"); // define the entity to be spawn
        setspawnentry("coords", 1,1,-1); // set the position of the entity
        subent=spawn();  //  spawn the entity
        changeentityproperty(subent, "position", 1,1,-1); //for safe, set again the position
        setglobalvar("bckground", subent);

        loadmodel("selectsprite"); // name of the entity to be loaded
        clearspawnentry(); // clean the spawn entry
        setspawnentry("name", "selectsprite"); // define the entity to be spawn
        setspawnentry("coords", 22,20,-1); // set the position of the entity
        subent2=spawn();  //  spawn the entity
        changeentityproperty(subent2, "position", 22,20,-1); //for safe, set again the position
        counter = setlocalvar("counter",1); // turn on the variable, blocking a new spawn to be made
      }

      
    } else if(openborvariant("in_menuscreen")==1){
      setindexedvar(0, NULL());
    }
}

void getSpriteScreen()
{
  long scr=getglobalvar("scr");
  if (!scr){
    scr=allocscreen(res_x,res_y);
    setglobalvar("scr",scr);
  }
  return scr;
}

void highScoreMusic()
{
  void bg = "data/music/halloffame.ogg";
  playmusic(bg, 1);

}

void titleMusic()
{
  void bg = "data/music/title.ogg";
  playmusic(bg, 1);

}

void inLevelLoop()
{
	turnWhite();
	storySystem();
}

void oncreate()
{
    int C = fileskim("Rise");
    setglobalvar("Load", C);

    setindexedvar(1, 0);
}

void fileskim(char Line)
{
      void file = openfilestream("Test.txt", 1);
      void vLoad;

      if(file != -1){
        setfilestreamposition(file, 0);
        vLoad = getfilestreamargument(file, 0, "string");

        while(vLoad != Line && vLoad != "#End"){
          filestreamnextline(file);
          vLoad = getfilestreamargument(file, 0, "string");         
        }
        if( vLoad == Line ){
          filestreamnextline(file);
          vLoad = getfilestreamargument(file, 0, "int");
          return vLoad;

          closefilestream(file);
        } else if(vLoad == "#End"){
          closefilestream(file);
          return 0;
        }
      } else {
        return 0;
      }
}