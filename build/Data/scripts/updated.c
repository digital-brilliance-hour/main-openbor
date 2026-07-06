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
void bckground = getglobalvar("bckground");  
void bckground2 = getglobalvar("bckground2");

	if(SYS_INLEVEL)
	{
		inLevelLoop();
    void titlecounter = getlocalvar("titlecounter");    
    void titlemcounter = getlocalvar("titlemcounter");    
    if (titlecounter!="0"){    
         setlocalvar("titlecounter",0);     
    }    
    if (titlemcounter!="0"){    
         setlocalvar("titlemcounter",0);     
    }
	}
else if (SYS_SCENE == "data/scenes/intro.txt"){  
}  
if (SYS_SCENE == "data/scenes/logo.txt"){  
}
  
if(SYS_INTITLE) {    
     void titlemcounter = getlocalvar("titlemcounter");     
     while(titlemcounter!=1)    {      
          //titleMusic();      
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
     void titlecounter = getlocalvar("titlecounter");  
     while(titlecounter!=1)      {        
          void subent;       
          int iValid = getentityproperty(bckground, "exists");        
          if(iValid){          
               killentity(bckground);        
          }                 

          loadmodel("titleanimation"); // name of the entity to be loaded        
          clearspawnentry(); // clean the spawn entry        
           setspawnentry("name", "titleanimation"); // define the entity to be spawn        
           setspawnentry("coords", 313,152,-1000); // set the position of the entity       
           subent=spawn();  //  spawn the entity        
           setglobalvar("bckground", subent);        
           changeentityproperty(subent, "position", 313,102,-1000); //for safe, set again the position               
           titlecounter = setlocalvar("titlecounter",1); // turn on the variable, blocking a new spawn to be made      
     }
  
}  
else {    
     setlocalvar("titlecounter",0);  
}
  
if(SYS_INTITLE) {      
     void Title1 = getglobalvar("Title1");      
     void mainTitle;
      
     mainTitle = Title1;      
     drawsprite(mainTitle, 0, 0, -2);      
     changedrawmethod(NULL(), "alpha", 0);
  
}
  
if(SYS_INMENU) {      
     void Title1 = getglobalvar("Title1");      
     void Title2 = getglobalvar("Title2");      
     void mainTitle;      
     void blackMask; 
      
     mainTitle = Title1;      
     //drawsprite(mainTitle, 0, 0, -2);      
     //changedrawmethod(NULL(), "alpha", 0);
      
     blackMask = Title2;      
     drawsprite(blackMask, 0, 0, -1);      
     changedrawmethod(NULL(), "alpha", 6);
  
}


	//else if (SYS_SCENE != "intro.txt"){
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
	//}

  if(openborvariant("in_halloffamescreen")==1){
    //highScoreMusic();
  }

	if(openborvariant("in_selectscreen")==1){
      int models_cached = openborvariant("models_cached");
      int i = 0;
      int C = getglobalvar("Load");

      for( i = 0; i < models_cached; ++i ) {
        char model = getmodelproperty(i,2);

        if( model == "Royce" && C != 39 ) {
            changemodelproperty(i,4,0);
            return;
        }
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