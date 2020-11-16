#include "data/scripts/common/constants.h"
#include "data/scripts/story/story_define.h"
#include "data/scripts/story.c"
#include "data/scripts/gettick.c"

void main()
{
	mainLoop();
}

void mainLoop()
{
	if(SYS_INLEVEL)
	{
		inLevelLoop();
    void counter = getlocalvar("counter"); 
    if (counter!="0"){
    setlocalvar("counter",0); 
    }
	}
	else if (SYS_SCENE != "intro.txt"){
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

  if(openborvariant("in_halloffamescreen")==1){
    //highScoreMusic();
  }

	if(openborvariant("in_selectscreen")==1){
      int models_cached = openborvariant("models_cached");
      int i = 0;
      int C = getglobalvar("Load");
      void counter = getlocalvar("counter"); 
      while(counter!=1)
      {
        void subent;
        loadmodel("selectanimation"); // name of the entity to be loaded
        clearspawnentry(); // clean the spawn entry
        setspawnentry("name", "selectanimation"); // define the entity to be spawn
        setspawnentry("coords", -1,0,-1); // set the position of the entity
        subent=spawn();  //  spawn the entity
        changeentityproperty(subent, "position", -84,0,-1); //for safe, set again the position
        counter = setlocalvar("counter",1); // turn on the variable, blocking a new spawn to be made
      }

      
    } else if(openborvariant("in_menuscreen")==1){
      setindexedvar(0, NULL());
    }
}

void highScoreMusic()
{
  void bg = "data/music/highscore.bor";
  //playmusic(bg, 1);

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