#import "data/scripts/library/spawn.h"
#import "data/scripts/library/basic.h"

void offscreenkill( float dx, int E )
{// Check position relative to screen. If enemy is offscreen, suicide!
//  dx : Distance to screen edge
//  E  : Edge selection, 0 = left, 1 = right

    void self = getlocalvar("self");
    int x = getentityproperty(self,"x"); //Get character's x coordinate
    int XPos = openborvariant("xpos"); //Get screen edge's position

    if( (x > XPos + 320 + dx) && (E == 1) ){ // Offscreen to the right?
      killentity(self); //Suicide!
    } else if( (x < XPos - dx) && (E == 0) ){ // Offscreen to the left?
      killentity(self); //Suicide!
    }
}

void spawnN(void Name, float dx, float dy, float dz, int Dir, char Summon)
{ // Spawn entity based on left screen edge with direction setting
   void self = getlocalvar("self");
   void Child = getglobalvar("S"+Summon);
   void Spawn;

   if(Child==NULL()){
     Spawn = spawn02(Name, dx, dy, dz);
     changeentityproperty(Spawn, "direction", Dir);
     setglobalvar("S"+Summon, "X");
   }
}
