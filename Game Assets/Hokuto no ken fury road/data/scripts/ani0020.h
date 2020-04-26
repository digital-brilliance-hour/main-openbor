#include "data/scripts/ani0009.h"
#include "data/scripts/run0001.h"
#include "data/scripts/spawn01.c"


void Restart()
{
void p1 = getplayerproperty(0, "entity");
int p1lives = getplayerproperty(p1, "lives");
void p2 = getplayerproperty(1, "entity");
int p2lives = getplayerproperty(p2, "lives");


int i = 0;
void npc = NULL();
for ( i = 0; i < openborvariant("count_entities"); ++i ){
   void ent = getentity(i);

   if ( getentityproperty(ent,"exists") ) {
      void type = getentityproperty(ent,"type");

      if ( type == openborconstant("TYPE_NPC") ) {
         npc = ent;
         break;
      }
   }
}

  if(getentityproperty(npc, "exists") && p1 != NULL())
{
 changeplayerproperty(0, "lives", p1lives -1);
 }
 if(getentityproperty(npc, "exists") && p2 != NULL())
{
 changeplayerproperty(1, "lives", p2lives -1);
 }
}

void attack1(int RxMin, int RxMax, int Rz, void Ani)
{// Attack interruption with range check
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    int dir = getentityproperty(self, "direction");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx >= RxMin && Disx <= RxMax && Disz <= Rz && dir == 1) // Target within range on right facing?
      {
        performattack(self, openborconstant(Ani)); //Change the animation
      } else if( Disx >= -RxMax && Disx <= -RxMin && Disz <= Rz && dir == 0) // Target within range on left facing?
      {
        performattack(self, openborconstant(Ani)); //Change the animation
      }
    }
}







int ani0020(int iAni, int iTAni){
    
	/*
	ani0020
	Damon Vaughn Caskey
	Perform alternate animation if target is within range and in specified animation.

	iAni:	Alternate attack.
	iTAni:	Target animation.
	*/

    void vSelf      = getlocalvar("self");					//Caller.                                                         
    void vOpp       = findtarget(vSelf, iAni);				//Nearest target in range of alternate attack.
	
	if (vOpp)												//Found a target?
	{
		if(getentityproperty(vOpp, "animationID") == iTAni)	//Animation match?
		{
			ani0009(vSelf, iAni, 0);						//Perform alternate attack.
			return 1;										//Return 1.
		}
	}

	return 0;												//Return 0.
}

void bind(int null, float x, float z, float y, int dir){
	void self = getlocalvar("self");
	void opp = getentityproperty(self, "opponent");
	if(null == 1)
	{
		bindentity(opp, self, x, z, y, dir, 0);
	}
	else if(null == 0)
	{
		bindentity(opp, NULL());
	}
}

void forceanim(int anim){
	void self = getlocalvar("self");
	void opp = getentityproperty(self, "opponent");
	changeentityproperty(opp, "animation", anim);
}

void beidle()
{// Go to IDLE animation!
    void self = getlocalvar("self");

    setidle(self);
}

void block(int Flag)
{// Turns blocking status
    void self = getlocalvar("self");
    changeentityproperty(self, "aiflag", "blocking", Flag);
}

void degravity(int Ratio)
{// Changes antigravity effect
    void self = getlocalvar("self");
    changeentityproperty(self, "antigravity", Ratio);
}

void slamstart()
{ // Slam Starter
// Use finish after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL7")); // Slam Starter
   }
}

void slamstart2()
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL7")); // Slam Starter
   }
}

void slamstart3()
{ // Slam Starter
// Use finish after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL8")); // Slam Starter
   }
}

void slamstart4()
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL8")); // Slam Starter
   }
}

void slamstart5()
{ // Slam Starter
// Use finish after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL6")); // Slam Starter
   }
}

void slamstart6()
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL6")); // Slam Starter
   }
}

void position(int Frame, float dx, float dy, float dz, int face)
{ // Modify grabbed entity's position relative to grabber
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     updateframe(target, Frame);
     bindentity(target, self, dx, dz, dy, face, 0);
   }
}

void depost(int Gr)
{// Release grabbed entity
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     bindentity(target, NULL());

     if(Gr == 1)
     {
       int x = getentityproperty(target, "x");
       int z = getentityproperty(target, "z");
       changeentityproperty(target, "position", x, z, 0);
     }
   }
}

void antiwall(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if (Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);

   if(Hz > 0)
   {
     changeentityproperty(self, "position", x, z-Distz);
   }

   if(H > 0)
   {
     changeentityproperty(self, "position", x+Move);
   }
}

void antiwall2(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if (Direction == 0){ //Is entity facing left?                 
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);

   if(Hz > 0)
   {
     changeentityproperty(self, "position", x, z-Distz);
     changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
   }

   if(H > 0)
   {
     changeentityproperty(self, "position", x+Move);
     changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
   }
}

void finish(int Damage, int Type, int x, int y, int z, int Face)
{ // Damage as slam or throw finisher
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);
   int SDir = getentityproperty(target,"direction");
   int MDir;

   if(Face==0){ // Same facing?
       MDir = SDir;
   }

   if(Face==1){ // Opposite facing?

     if(SDir==0){ // Facing left?
       MDir = 1;
     } else { MDir = 0;}
   }

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int dir = getentityproperty(target,"direction"); //Get opponent's facing direction
     if(dir==0){ // Facing left?
       x = -x;
     }

     if(Type==1)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL")); // 1st Finisher
     }

     if(Type==2)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL9")); // 2nd Finisher
     }

     tossentity(target, y, x, z); // Toss opponent ;)
     changeentityproperty(target, "direction", MDir);
   }
}

void throw(int Damage, int Type, int x, int y, int z, int Face)
{ // Damage as throw finisher
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);
   int SDir = getentityproperty(target,"direction");
   int MDir;

   if(Face==0){ // Same facing?
       MDir = SDir;
   }

   if(Face==1){ // Opposite facing?

     if(SDir==0){ // Facing left?
       MDir = 1;
     } else { MDir = 0;}
   }

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int dir = getentityproperty(target,"direction"); //Get opponent's facing direction
     if(dir==0){ // Facing left?
       x = -x;
     }

     if(Type==1)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL5")); // 1st throw type
     }

     if(Type==2)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL9")); // 2nd throw type
     }

     if(Type==3)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_BURN")); // 3rd throw type
     }

     changeentityproperty(target, "attacking", 1);
     changeentityproperty(target, "damage_on_landing", Damage);
     changeentityproperty(target, "projectile", 1);
     changeentityproperty(target, "direction", MDir);
     tossentity(target, y, x, z); // Toss opponent ;)
   }
}

void stop()
{// Stop hero's movement!
    void self = getlocalvar("self");
    changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
}

void clearL()
{// Clears all local variables
     clearlocalvar();
}

void degravity(int Ratio)
{// Changes antigravity effect
    void self = getlocalvar("self");
    changeentityproperty(self, "antigravity", Ratio);
}

void dasher( float Vx, float Vy, float Vz )
{// Dash with desired speed!
    void self = getlocalvar("self");
    int dir = getentityproperty(self,"direction");

    if(dir==0){ // Facing left?
      Vx = -Vx ;
    }

    changeentityproperty(self, "velocity", Vx, Vz, Vy); //Move!
}

void shoot(void Shot, float dx, float dy, float dz)
{ // Shooting projectile
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   void vShot;

   if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
   }

   vShot = projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
   return vShot;
}

void keyflip()
{// Change hero's facing direction if left or right is pressed
    void self = getlocalvar("self");
    int iPIndex = getentityproperty(self,"playerindex"); //Get player index

    if (playerkeys(iPIndex, 0, "moveleft")){ // Left is pressed?
      changeentityproperty(self, "direction", 0); //Face left
    } else if (playerkeys(iPIndex, 0, "moveright")){ // Right is pressed?
      changeentityproperty(self, "direction", 1); //Face right
    }
}

void keyint(void Ani, int Frame, void Key, int Hflag, int Limit)
{// Change current animation if proper key is pressed or released provided HP is more than limit
    void self = getlocalvar("self");
    void Health = getentityproperty(self,"health");    
    int iPIndex = getentityproperty(self,"playerindex"); //Get player index
    void iRKey;

      if (Key=="U"){ //Up Required?
       iRKey = playerkeys(iPIndex, 0, "moveup"); // "Up"
	}

      if (Key=="D"){ //Down Required?
        iRKey = playerkeys(iPIndex, 0, "movedown"); // "Down"
	}

      if (Key=="J"){ //Jump Required?
        iRKey = playerkeys(iPIndex, 0, "jump"); // "Jump"
	}

      if (Key=="A"){ //Attack Required?
        iRKey = playerkeys(iPIndex, 0, "attack"); // "Attack"
	}

      if (Key=="S"){ //Special Required?
        iRKey = playerkeys(iPIndex, 0, "special"); // "Special"
	}

      if (Key=="A2"){ //Attack2 Required?
        iRKey = playerkeys(iPIndex, 0, "attack2"); // "Attack2"
	}

      if (Key=="UA"){ //Up and Attack Required?
        iRKey = playerkeys(iPIndex, 0, "moveup", "Attack"); // "Up" + "Attack"
	}

      if (Key=="DA"){ //Down and Attack Required?
        iRKey = playerkeys(iPIndex, 0, "movedown", "Attack"); // "Down" + "Attack"
	}

      if (Hflag==1){ //Not holding the button case?
        iRKey = !iRKey; //Take the opposite condition
	}

      if ((Health > Limit)&&iRKey){
        changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
        changeentityproperty(self, "animpos", Frame);

        if (Key=="UA"){ 
          // This is copy of dethrown
          changeentityproperty(self, "attacking", 0);
          changeentityproperty(self, "damage_on_landing", 0);
          changeentityproperty(self, "projectile", 0);
        }

        if (Key=="DA"){ 
          // This is copy of dethrown
          changeentityproperty(self, "attacking", 0);
          changeentityproperty(self, "damage_on_landing", 0);
          changeentityproperty(self, "projectile", 0);
        }
      }
}

void nograb(int Flag)
{// Turns grabbable status
    void self = getlocalvar("self");
    changeentityproperty(self, "nograb", Flag);
}

void antiwall(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if (Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);

   if(Hz > 0)
   {
     changeentityproperty(self, "position", x, z-Distz);
   }

   if(H > 0)
   {
     changeentityproperty(self, "position", x+Move);
   }
}

void anichange(void Ani)
{// Animation changer
    void self = getlocalvar("self");

    changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
}

void hurt(int Damage)
{ // Damage without altering opponent's animation + less damage if opponent has less health
// Mainly used for slams
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     void THealth = getentityproperty(target,"health"); //Get target's health
     if(THealth > Damage)
     {
       changeentityproperty(target, "health", THealth - Damage); //Damage target with desired damage
     } else {
       changeentityproperty(target, "health", 1); //Damage target with less damage
     }
   }
}

void hurt2(int Damage)
{ // Damage without altering opponent's animation + less damage if opponent has less health
// Mainly used for slams
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int THealth = getentityproperty(target,"health"); //Get target's health
     int TAniPos = getentityproperty(target,"animpos"); //Get target's animation frame
     if(THealth > Damage)
     {
       damageentity(target, self, Damage, 0, openborconstant("ATK_NORMAL7")); // Damage target with desired damage
       updateframe(target, TAniPos);
     } else {
       int Damage2 = THealth - 1;
       damageentity(target, self, Damage2, 0, openborconstant("ATK_NORMAL7")); //Damage target with less damage
       updateframe(target, TAniPos);
     }
   }
}

void hurt3(int Damage)
{ // Damage without altering opponent's animation + less damage if opponent has less health
// Mainly used for slams
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int THealth = getentityproperty(target,"health"); //Get target's health
     int TAniPos = getentityproperty(target,"animpos"); //Get target's animation frame
     if(THealth > Damage)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL")); // Damage target with desired damage
       updateframe(target, TAniPos);
     } else {
       int Damage2 = THealth - 1;
       damageentity(target, self, Damage2, 1, openborconstant("ATK_NORMAL")); //Damage target with less damage
       updateframe(target, TAniPos);
     }
   }
}

void spawn01(void vName, float fX, float fY, float fZ)
{
	//spawn01 (Generic spawner)
	//Damon Vaughn Caskey
	//07/06/2007
	//
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
      //fY: Z location adjustment.

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iDirection = getentityproperty(self, "direction");

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

	if (iDirection == 0){ //Is entity facing left?                  
          fX = -fX; //Reverse X direction to match facing.
	}

      fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
      fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
      fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.
	
	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.
    
	return vSpawn; //Return spawn.
}

void spawner(void vName, float fX, float fY, float fZ)
{	//Spawns entity next to caller and set them as child.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
      //fY: Z location adjustment.

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	
	vSpawn = spawn01(vName, fX, fY, fZ); //Spawn in entity.

	changeentityproperty(vSpawn, "parent", self); //Set caller as parent.
    
	return vSpawn; //Return spawn.
}


void spawnbind(void Name, float dx, float dy, float dz)
{ // Spawn and bind other entity
   void self = getlocalvar("self");
   void Spawn;

   Spawn = spawn01(Name, dx, dy, 0);
   bindentity(Spawn, self, dx, dz, dy, 0, 0);
}

void adjustX()
{// Special script for Bao's Air Pressure
// It moves Bao right to enemy's head
    void self = getlocalvar("self");
    void target = getlocalvar("Target" + self);

    if(target==NULL())
    {
      target = getentityproperty(self, "opponent");
      setlocalvar("Target" + self, target);
    }

    if(target!=NULL())
    {
      int x = getentityproperty(target,"x"); //Get target's x coordinate
      int z = getentityproperty(target,"z"); //Get target's z coordinate

      changeentityproperty(self, "position", x, z, 0); //Grounding
    }
}

void entergrab()
{// Script to change jumping state to grabattacking state
// Used in air grabs
    void self = getlocalvar("self");

    changeentityproperty(self, "aiflag", "jumping", 0); // Disable jumping status
    changeentityproperty(self, "aiflag", "attacking", 1); // Enable attacking status

    changeentityproperty(self, "takeaction", "common_grabattack"); // Enters grabattack
}

void anti()
{ // Makes grabbed opponent slighty lifted to air
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     tossentity(target, 1, 0, 0); // Toss opponent a little ;)
   }
}

void grabcheckA(void Ani1, void Ani2, void Ani3)
{ // Hero's airgrab checker
// This script prevents hero from grabbing ground enemies, bikers, jetpacks, special enemies and non-enemy entities
//  Ani1 = Grab animation to play
//  Ani2 = Animation to play if hit enemy are bikers or jetpacks
//  Ani3 = Animation to play if hit opponent are not airborne enemies

    void self = getlocalvar("self");
    void target = getentityproperty(self, "opponent");

    if(target!=NULL()){

      if(getentityproperty(target, "a") > 0){
        int Check = checkgrab(target);

        if(Check == 0)
        { 
          changeentityproperty(self, "animation", openborconstant(Ani2));
        } else if(Check == 1){
          setlocalvar("Target" + self, target);
          changeentityproperty(self, "animation", openborconstant(Ani1));
        }
      } else {
        changeentityproperty(self, "animation", openborconstant(Ani3));
      }

    }
}

void grabcheckG(void Ani1, void Ani2, void Ani3)
{ // Hero's groundgrab checker
// This script prevents hero from grabbing airborne enemies, bikers, jetpacks, special enemies and non-enemy entities
//  Ani1 = Grab animation to play
//  Ani2 = Animation to play if hit enemy are bikers or jetpacks
//  Ani3 = Animation to play if hit opponent are not ground enemies

    void self = getlocalvar("self");
    void target = getentityproperty(self, "opponent");

    if(target!=NULL()){

      if(getentityproperty(target, "a") == 0){
        int Check = checkgrab(target);

        if(Check == 0)
        { 
          changeentityproperty(self, "animation", openborconstant(Ani2));
        } else if(Check == 1){
          setlocalvar("Target" + self, target);
          changeentityproperty(self, "animation", openborconstant(Ani1));
        }
      } else {
        changeentityproperty(self, "animation", openborconstant(Ani3));
      }

    }
}

void checkgrab(void target)
{ // Opponent Checker
// This script checks hero's current opponent. If he/she/it is biker, jetpack, special enemy or non-enemy entity this function returns 0
// Otherwise it returns 1.

    if(getentityproperty(target, "type") == openborconstant("TYPE_ENEMY")){
      char Tname = getentityproperty(target, "defaultname");

      if(Tname == "Badai" || Tname == "BikerL" || Tname == "BikerL1" || Tname == "BikerT" || Tname == "Rider" || Tname == "Rider2" )
      { // Normal Bikers
        return 0;
      } else if(Tname == "BikerS" || Tname == "Storm" || Tname == "BikerAT" || Tname == "Bikeman" || Tname == "BikeBoss" )
      { // Special Bikers
        return 0;
      } else if(Tname == "Biker" || Tname == "RiderB" || Tname == "BikerB" || Tname == "Rover" || Tname == "Candy" || Tname == "Button")
      { // Bonus Bikers, Candy & Dog
        return 0;
      } else if(Tname == "Skystar" || Tname == "Aerial" || Tname == "Raidi" || Tname == "Rockette" || Tname == "Jetpac" || Tname == "Rocket")
      { // Jetpacks
        return 0;
      } else {
        return 1;
      }
    } else {
      return 0;
    }
}

void riseattack(int Rx, int Rz, void Ani)
{// Riseattack with range check
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disx < 0){
        Disx = -Disx;
      }
      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx <= Rx && Disz <= Rz ) // Target within range?
      {
        if(Tx < x){
          changeentityproperty(self, "direction", 0);
        } else {
          changeentityproperty(self, "direction", 1);
        }
        changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
      } 
    }
}

void riseattack2(int Rx, int Rz, void Ani)
{// Riseattack with range check
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disx < 0){
        Disx = -Disx;
      }
      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx <= Rx && Disz <= Rz ) // Target within range?
      {
        changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
      } 
    }
}

int ani0020(int iAni, int iTAni){
    
	/*
	ani0020
	Damon Vaughn Caskey
	Perform alternate animation if target is within range and in specified animation.
	Realizar la animación alterna si el objetivo está dentro del rango y en la animación especificad
	iAni:	Alternate attack.
	iTAni:	Target animation.
	*/

    void vSelf      = getlocalvar("self");					//Caller.                                                         
    void vOpp       = findtarget(vSelf, iAni);				//Nearest target in range of alternate attack.
	
	if (vOpp)												//Found a target?
	{
		if(getentityproperty(vOpp, "animationID") == iTAni)	//Animation match?
		{
			ani0009(vSelf, iAni, 0);						//Perform alternate attack.
			return 1;										//Return 1.
		}
	}

	return 0;												//Return 0.
}

void bind(int null, float x, float z, float y, int dir){
	void self = getlocalvar("self");
	void opp = getentityproperty(self, "opponent");
	if(null == 1)
	{
		bindentity(opp, self, x, z, y, dir, 0);
	}
	else if(null == 0)
	{
		bindentity(opp, NULL());
	}
}





void forceanim(int anim){
	void self = getlocalvar("self");
	void opp = getentityproperty(self, "opponent");
	changeentityproperty(opp, "animation", anim);
}

void Join(int Flag)
{// Turns Join status
    changeopenborvariant("nojoin", Flag);
}

void beidle()
{// Go to IDLE animation!
    void self = getlocalvar("self");

    setidle(self);
}





void block(int Flag)
{// Turns blocking status
    void self = getlocalvar("self");
    changeentityproperty(self, "aiflag", "blocking", Flag);
}

void degravity(int Ratio)
{// Changes antigravity effect
    void self = getlocalvar("self");
    changeentityproperty(self, "antigravity", Ratio);
}

void slamstartando()
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL7")); // Slam Starter
   }
}
void slamstartharry()
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL36")); // Slam Starter
   }
}
void slamstart2()
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL")); // Slam Starter
   }
}

void slamstart3()
{ // Slam Starter
// Use finish after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL8")); // Slam Starter
   }
}

void slamstart4()
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL8")); // Slam Starter
   }
}

void slamstart5()
{ // Slam Starter
// Use finish after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL1")); // Slam Starter
   }
}

void slamstart6()
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL6")); // Slam Starter
   }
}

void slamstart9()
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL9")); // Slam Starter
   }
}


void slamstart10()
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL9")); // Slam Starter
   }
}



void position(int Frame, float dx, float dy, float dz, int face)
{ // Modify grabbed entity's position relative to grabber
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     updateframe(target, Frame);
     bindentity(target, self, dx, dz, dy, face, 0);
   }
}

void depost(int Gr)
{// Release grabbed entity
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     bindentity(target, NULL());

     if(Gr == 1)
     {
       int x = getentityproperty(target, "x");
       int z = getentityproperty(target, "z");
       changeentityproperty(target, "position", x, z, 0);
     }
   }
}

void finish(int Damage, int Type, int x, int y, int z, int Face)
{ // Damage as slam or throw finisher
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);
   int SDir = getentityproperty(target,"direction");
   int MDir;

   if(Face==0){ // Same facing?
       MDir = SDir;
   }

   if(Face==1){ // Opposite facing?

     if(SDir==0){ // Facing left?
       MDir = 1;
     } else { MDir = 0;}
   }

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int dir = getentityproperty(target,"direction"); //Get opponent's facing direction
     if(dir==0){ // Facing left?
       x = -x;
     }

	

     if(Type==1)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL")); // 1st Finisher
     }

     if(Type==2)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL3")); // 2nd Finisher
     }

	

     tossentity(target, y, x, z); // Toss opponent ;)
     changeentityproperty(target, "direction", MDir);
   }
}

void throw(int Damage, int Type, int x, int y, int z, int Face)
{ // Damage as throw finisher
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);
   int SDir = getentityproperty(target,"direction");
   int MDir;

   if(Face==0){ // Same facing?
       MDir = SDir;
   }

   if(Face==1){ // Opposite facing?

     if(SDir==0){ // Facing left?
       MDir = 1;
     } else { MDir = 0;}
   }

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int dir = getentityproperty(target,"direction"); //Get opponent's facing direction
     if(dir==0){ // Facing left?
       x = -x;
     }

     if(Type==1)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL7")); // 1st throw type
     }

     if(Type==2)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL9")); // 2nd throw type
     }

     if(Type==3)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL3")); // 3rd throw type
     }

     changeentityproperty(target, "attacking", 1);
     changeentityproperty(target, "damage_on_landing", Damage);
     changeentityproperty(target, "projectile", 1);
     changeentityproperty(target, "direction", MDir);
     tossentity(target, y, x, z); // Toss opponent ;)
   }
}

void throw2(int Damage, int Type, int x, int y, int z, int Face)
{ // Damage as throw finisher
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);
   int SDir = getentityproperty(target,"direction");
   int MDir;

   if(Face==0){ // Same facing?
       MDir = SDir;
   }

   if(Face==1){ // Opposite facing?

     if(SDir==0){ // Facing left?
       MDir = 1;
     } else { MDir = 0;}
   }

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int dir = getentityproperty(target,"direction"); //Get opponent's facing direction
     if(dir==0){ // Facing left?
       x = -x;
     }

     if(Type==1)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL9")); // 1st throw type
     }

     if(Type==2)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL9")); // 2nd throw type
     }

     if(Type==3)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_BURN")); // 3rd throw type
     }

     changeentityproperty(target, "attacking", 1);
     changeentityproperty(target, "damage_on_landing", Damage);
     changeentityproperty(target, "projectile", 1);
     changeentityproperty(target, "direction", MDir);
     tossentity(target, y, x, z); // Toss opponent ;)
   }
}

void antiwall(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if (Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);

   if(Hz > 0)
   {
     changeentityproperty(self, "position", x, z-Distz);
   }

   if(H > 0)
   {
     changeentityproperty(self, "position", x+Move);
   }
}

void antiwallg(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if(Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);

   if(Hz > y)
   {
     changeentityproperty(self, "position", x, z-Distz);
   }

   if(H > y)
   {
     changeentityproperty(self, "position", x+Move);
   }
}


void antiwall3(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if(Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);

   if(Hz > y)
   {
     changeentityproperty(self, "position", x, z-Distz);
   }

   if(H > y)
   {
     changeentityproperty(self, "position", x+Move);
   }
}








void throwbolo(int Damage, int Type, int x, int y, int z, int Face)
{ // Damage as throw finisher
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);
   int SDir = getentityproperty(target,"direction");
   int MDir;

   if(Face==0){ // Same facing?
       MDir = SDir;
   }

   if(Face==1){ // Opposite facing?

     if(SDir==0){ // Facing left?
       MDir = 1;
     } else { MDir = 0;}
   }

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int dir = getentityproperty(target,"direction"); //Get opponent's facing direction
     if(dir==0){ // Facing left?
       x = -x;
     }

     if(Type==1)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL1")); // 1st throw type
     }

     if(Type==2)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL9")); // 2nd throw type
     }

     if(Type==3)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL7")); // 3rd throw type
     }

     if(Type==4)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL3")); // 3rd throw type
     }

     changeentityproperty(target, "attacking", 1);
     changeentityproperty(target, "damage_on_landing", Damage);
     changeentityproperty(target, "projectile", 1);
     changeentityproperty(target, "direction", MDir);
     tossentity(target, y, x, z); // Toss opponent ;)
   }
}

void stop()
{// Stop hero's movement!
    void self = getlocalvar("self");
    changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
}

void clearL()
{// Clears all local variables
    clearlocalvar();
}

void degravity(int Ratio)
{// Changes antigravity effect
    void self = getlocalvar("self");
    changeentityproperty(self, "antigravity", Ratio);
}

void dasher( float Vx, float Vy, float Vz )
{// Dash with desired speed!
    void self = getlocalvar("self");
    int dir = getentityproperty(self,"direction");

    if(dir==0){ // Facing left?
      Vx = -Vx ;
    }

    changeentityproperty(self, "velocity", Vx, Vz, Vy); //Move!
}


void leaper( float Vx, float Vy, float Vz )
{// Leap with desired speed!
    void self = getlocalvar("self");
    int dir = getentityproperty(self,"direction");

    if(dir==0){ // Facing left?
      Vx = -Vx ;
    }

    tossentity(self, Vy, Vx, Vz); //Leap!
}


void shoot(void Shot, float dx, float dy, float dz)
{ // Shooting projectile
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   void vShot;

   if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
   }

   vShot = projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
   return vShot;
}

void keyflip()
{// Change hero's facing direction if left or right is pressed
    void self = getlocalvar("self");
    int iPIndex = getentityproperty(self,"playerindex"); //Get player index

    if (playerkeys(iPIndex, 0, "moveleft")){ // Left is pressed?
      changeentityproperty(self, "direction", 0); //Face left
    } else if (playerkeys(iPIndex, 0, "moveright")){ // Right is pressed?
      changeentityproperty(self, "direction", 1); //Face right
    }
}

void keyflip2()
{// Change hero's facing direction if left or right is pressed
    void self = getlocalvar("self");
    int Dir = getentityproperty(self, "direction");
	int iPIndex = getentityproperty(self,"playerindex"); //Get player index
	if (Dir == 0)
    { // left is pressed?
      changelevelproperty("cameraxoffset", -70); //Face left
    } else if (Dir == 1){ // right is pressed?
      changelevelproperty("cameraxoffset", 70); //Face right
    }
}      

void nograb(int Flag)
{// Turns grabbable status
    void self = getlocalvar("self");
    changeentityproperty(self, "nograb", Flag);
}

void antiwallg(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if (Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);

   if(Hz > 0)
   {
     changeentityproperty(self, "position", x, z-Distz);
   }

   if(H > 0)
   {
     changeentityproperty(self, "position", x+Move);
   }
}

void anichange(void Ani)
{// Animation changer
    void self = getlocalvar("self");

    changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
}

void hurt(int Damage)
{ // Damage without altering opponent's animation + less damage if opponent has less health
// Mainly used for slams
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     void THealth = getentityproperty(target,"health"); //Get target's health
     if(THealth > Damage)
     {
       changeentityproperty(target, "health", THealth - Damage); //Damage target with desired damage
     } else {
       changeentityproperty(target, "health", 1); //Damage target with less damage
     }
   }
}

void hurt2(int Damage)
{ // Damage without altering opponent's animation + less damage if opponent has less health
// Mainly used for slams
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int THealth = getentityproperty(target,"health"); //Get target's health
     int TAniPos = getentityproperty(target,"animpos"); //Get target's animation frame
     if(THealth > Damage)
     {
       damageentity(target, self, Damage, 0, openborconstant("ATK_NORMAL7")); // Damage target with desired damage
       updateframe(target, TAniPos);
     } else {
       int Damage2 = THealth - 1;
       damageentity(target, self, Damage2, 0, openborconstant("ATK_NORMAL7")); //Damage target with less damage
       updateframe(target, TAniPos);
     }
   }
}

void hurt3(int Damage)
{ // Damage without altering opponent's animation + less damage if opponent has less health
// Mainly used for slams
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int THealth = getentityproperty(target,"health"); //Get target's health
     int TAniPos = getentityproperty(target,"animpos"); //Get target's animation frame
     if(THealth > Damage)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL")); // Damage target with desired damage
       updateframe(target, TAniPos);
     } else {
       int Damage2 = THealth - 1;
       damageentity(target, self, Damage2, 1, openborconstant("ATK_NORMAL")); //Damage target with less damage
       updateframe(target, TAniPos);
     }
   }
}

void spawn01(void vName, float fX, float fY, float fZ)
{
	//spawn01 (Generic spawner)
	//Damon Vaughn Caskey
	//07/06/2007
	//
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
      //fY: Z location adjustment.

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iDirection = getentityproperty(self, "direction");

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

	if (iDirection == 0){ //Is entity facing left?                  
          fX = -fX; //Reverse X direction to match facing.
	}

      fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
      fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
      fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.
	
	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.
    
	return vSpawn; //Return spawn.
}

void spawnbind(void Name, float dx, float dy, float dz)
{ // Spawn and bind other entity
   void self = getlocalvar("self");
   void Spawn;

   Spawn = spawn01(Name, dx, dy, 0);
   bindentity(Spawn, self, dx, dz, dy, 0, 0);
}

void adjustX()
{// Special script for Bao's Air Pressure
// It moves Bao right to enemy's head
    void self = getlocalvar("self");
    void target = getlocalvar("Target" + self);

    if(target==NULL())
    {
      target = getentityproperty(self, "opponent");
      setlocalvar("Target" + self, target);
    }

    if(target!=NULL())
    {
      int x = getentityproperty(target,"x"); //Get target's x coordinate
      int z = getentityproperty(target,"z"); //Get target's z coordinate

      changeentityproperty(self, "position", x, z, 0); //Grounding
    }
}

void entergrab()
{// Script to change jumping state to grabattacking state
// Used in air grabs
    void self = getlocalvar("self");

    changeentityproperty(self, "aiflag", "jumping", 0); // Disable jumping status
    changeentityproperty(self, "aiflag", "attacking", 1); // Enable attacking status

    changeentityproperty(self, "takeaction", "common_grabattack"); // Enters grabattack
}

void anti()
{ // Makes grabbed opponent slighty lifted to air
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     tossentity(target, 1, 0, 0); // Toss opponent a little ;)
   }
}



void grabcheckA(void Ani1, void Ani2, void Ani3)
{ // Hero's airgrab checker
// This script prevents hero from grabbing ground enemies, bikers, jetpacks, special enemies and non-enemy entities
//  Ani1 = Grab animation to play
//  Ani2 = Animation to play if hit enemy are bikers or jetpacks
//  Ani3 = Animation to play if hit opponent are not airborne enemies

    void self = getlocalvar("self");
    void target = getentityproperty(self, "opponent");

    if(target!=NULL()){

      if(getentityproperty(target, "a") > 1){
        int Check = checkgrab(target);

        if(Check == 0)
        { 
          changeentityproperty(self, "animation", openborconstant(Ani2));
        } else if(Check == 1){
          setlocalvar("Target" + self, target);
          changeentityproperty(self, "animation", openborconstant(Ani1));
        }
      } else {
        changeentityproperty(self, "animation", openborconstant(Ani3));
      }

    }
}

void grabcheckG(void Ani1, void Ani2, void Ani3)
{ // Hero's groundgrab checker
// This script prevents hero from grabbing airborne enemies, bikers, jetpacks, special enemies and non-enemy entities
//  Ani1 = Grab animation to play
//  Ani2 = Animation to play if hit enemy are bikers or jetpacks
//  Ani3 = Animation to play if hit opponent are not ground enemies

    void self = getlocalvar("self");
    void target = getentityproperty(self, "opponent");

    if(target!=NULL()){

      if(getentityproperty(target, "a") == 0){
        int Check = checkgrab(target);

        if(Check == 0)
        { 
          changeentityproperty(self, "animation", openborconstant(Ani2));
        } else if(Check == 1){
          setlocalvar("Target" + self, target);
          changeentityproperty(self, "animation", openborconstant(Ani1));
        }
      } else {
        changeentityproperty(self, "animation", openborconstant(Ani3));
      }

    }
}


void checkgrab(void target)
{ // Opponent Checker
// This script checks hero's current opponent. If he/she/it is biker, jetpack, special enemy or non-enemy entity this function returns 0
// Otherwise it returns 1.

    if(getentityproperty(target, "type") == openborconstant("TYPE_ENEMY")){
      char Tname = getentityproperty(target, "defaultname");

      if(Tname == "bolo" || Tname == "bolo2" || Tname == "abobo" || Tname == "mibobo" || Tname == "mibobo2" || Tname == "chin" || Tname == "bigb" || Tname == "gordon" || Tname == "sheen" || Tname == "Abore" || Tname == "Bolo5"|| Tname == "hxbobo" )
      { // Normal Bikers
        return 0;
      } else if(Tname == "oharra" || Tname == "oharra2" || Tname == "abore" || Tname == "burnov" || Tname == "burnov2" || Tname == "Bolo5" )
      { // Special Bikers
        return 0;
      } else if(Tname == "abore2" || Tname == "chin2" || Tname == "abobo2" || Tname == "abobo3" || Tname == "chin3" || Tname == "burnov3")
      { // Bonus Bikers, Candy & Dog
        return 0;
      } else if(Tname == "burnov4" || Tname == "burnov5" || Tname == "burnov6" || Tname == "burnov7" || Tname == "chin4" || Tname == "chin5")
      { // Jetpacks
        return 0;
      } else {
        return 1;
      }
    } else {
      return 0;
    }
}
void riseattack(int Rx, int Rz, void Ani)
{// Riseattack with range check
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disx < 0){
        Disx = -Disx;
      }
      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx <= Rx && Disz <= Rz ) // Target within range?
      {
        if(Tx < x){
          changeentityproperty(self, "direction", 0);
        } else {
          changeentityproperty(self, "direction", 1);
        }
        changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
      } 
    }
}








void attack1g(int RxMin, int RxMax, int Rz, void Ani)
{// Attack interruption with range check
    void self = getlocalvar("self");
    void target = getentityproperty(self, "grabbing");
	
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    
	int dir = getentityproperty(self, "direction");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx >= RxMin && Disx <= RxMax && Disz <= Rz && dir == 1) // Target within range on right facing?
      {
        performattack(self, openborconstant(Ani)); //Change the animation
      } else if( Disx >= -RxMax && Disx <= -RxMin && Disz <= Rz && dir == 0) // Target within range on left facing?
      {
        performattack(self, openborconstant(Ani)); //Change the animation
      }
    }
}





void antiwall4(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if(Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);

   if(Hz >= y)
   {
     changeentityproperty(self, "position", x, z-Distz);
     changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
     changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW37"));
   }

   if(H >= y)
   {
     changeentityproperty(self, "position", x+Move);
     changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
     changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW37"));
   }
}



void hurt4(int Damage)
{ // Damage without altering opponent's animation + less damage if opponent has less health
// Mainly used for slams
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     void THealth = getentityproperty(target,"health"); //Get target's health
     if(THealth > Damage)
     {
       changeentityproperty(target, "health", THealth - Damage); //Damage target with desired damage
     } else {
       changeentityproperty(target, "health", 1); //Damage target with less damage
     }
   }
}


void attack1(int RxMin, int RxMax, int Rz, void Ani)
{// Attack interruption with range check
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    
	int dir = getentityproperty(self, "direction");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");
     
	float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx >= RxMin && Disx <= RxMax && Disz <= Rz && dir == 1) // Target within range on right facing?
      {
        performattack(self, openborconstant(Ani)); //Change the animation
      } else if( Disx >= -RxMax && Disx <= -RxMin && Disz <= Rz && dir == 0) // Target within range on left facing?
      {
        performattack(self, openborconstant(Ani)); //Change the animation
      }
    }
}


void attack2(int RxMin, int RxMax, int RaMin, int RaMax, int RzMin, int RzMax, void Ani)
{// Attack interruption with range A check
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float a = getentityproperty(self, "a");
    int dir = getentityproperty(self, "direction");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Ta = getentityproperty(target, "a");
      float Tz = getentityproperty(target, "z");
	float Disx = Tx - x;
      float Disz = Ta - a;



      if( Disx >= RxMin && Disx <= RxMax && Disz >= RaMin && Disz <= RaMax && Disz >= RzMin && Disz <= RzMax && dir == 1) // Target within range on right facing?
      {
        performattack(self, openborconstant(Ani)); //Change the animation
      } else if( Disx >= -RxMax && Disx <= -RxMin && Disz >= RaMin && Disz <= RaMax && Disz >= RzMin && Disz <= RzMax && dir == 0) // Target within range on left facing?
      {
        performattack(self, openborconstant(Ani)); //Change the animation
      }
    }
}


void antiwall5(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if(Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);

   if(Hz >= y)
   {
     changeentityproperty(self, "position", x, z-Distz);
     changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
     changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW36"));
   }

   if(H >= y)
   {
     changeentityproperty(self, "position", x+Move);
     changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
     changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW36"));
   }
}






void clearGrab()
{// Clears local variables used for grabbing
   void self = getlocalvar("self");
   setlocalvar("Target" + self, NULL());
}









void riseattack2(int Rx, int Rz, float Velx, float Velz, void Ani)
{// Riseattack with range check + targetting
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disx < 0){
        Disx = -Disx;
      }
      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx <= Rx && Disz <= Rz ) // Target within range?
      {
        if(Tx < x){
          changeentityproperty(self, "direction", 0);
        } else {
          changeentityproperty(self, "direction", 1);
        }

        if(Disz < Disx)
        {
          if(Tx < x){
            setlocalvar("x"+self, -Velx);
          } else { setlocalvar("x"+self, Velx); }

          setlocalvar("z"+self, Velx*(Tz-z)/Disx);
        } else {
          if(Tz < z){
            setlocalvar("z"+self, -Velz);
          } else { setlocalvar("z"+self, Velz); }

          setlocalvar("x"+self, Velz*(Tx-x)/Disz);
        }
        changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
      }
    }
}







void conditionalflip2()
{ // Flipping based on currently grabbed enemy
   void self = getlocalvar("self");
   void target = getentityproperty(self, "opponent");

   if(target)
   {
     int Direction = getentityproperty(self, "direction");
     int TDir = getentityproperty(target, "direction");

     if(TDir == 0 && Direction == 0){             
       changeentityproperty(self, "direction", 1);
     } else if(TDir == 1 && Direction == 1){
       changeentityproperty(self, "direction", 0);
     }
   }
}





void conditionalflip()
{ // Flipping based on currently grabbed enemy
   void self = getlocalvar("self");
   void target = getentityproperty(self, "opponent");

   if(target)
   {
     int Direction = getentityproperty(self, "direction");
     int TDir = getentityproperty(target, "direction");

     if(TDir == 0 && Direction == 0){             
       changeentityproperty(self, "direction", 1);
     } else if(TDir == 1 && Direction == 1){
       changeentityproperty(self, "direction", 0);
     }
   }
}

void flip()
{// Turns around
    void self = getlocalvar("self");
    int Direction = getentityproperty(self, "direction");

    if (Direction == 0){ //Is entity facing left?                  
      changeentityproperty(self, "direction", 1);
    } else {
      changeentityproperty(self, "direction", 0);
    }
}



void target(float Velx, float Velz, float dx, float dz, int Stop)
{// Targetting opponent before leaping or dashing.
// Velx = x Velocity
// Velz = z Velocity
// dx = x added distance
// dz = z added distance
// Stop = flag to stop moving if no target is found

    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    if (dir == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
    }

    setlocalvar("T"+self, findtarget(self)); //Get nearest player

    if( getlocalvar("T"+self) != NULL()){
      void target = getlocalvar("T"+self);
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");

      if(Tx < x){
        changeentityproperty(self, "direction", 0);
      } else {
        changeentityproperty(self, "direction", 1);
      }

      x = x+dx;
      z = z+dz;
      float Disx = Tx - x;
      float Disz = Tz - z;

//Set both distance as positive value
      if(Disx < 0){
        Disx = -Disx;
      }

      if(Disz < 0){
        Disz = -Disz;
      }

// Calculate velocity for targetting
      if(Disz < Disx)
      {
        if(Tx < x){
          setlocalvar("x"+self, -Velx);
        } else { setlocalvar("x"+self, Velx); }

        setlocalvar("z"+self, Velx*(Tz-z)/Disx);
      } else {
        if(Tz < z){
          setlocalvar("z"+self, -Velz);
        } else { setlocalvar("z"+self, Velz); }

        setlocalvar("x"+self, Velz*(Tx-x)/Disz);
      }

    } else {
      if(Stop == 1)
      {
        setlocalvar("z"+self, 0);
        setlocalvar("x"+self, 0);
      } else {
        setlocalvar("z"+self, 0);
        if(dir==0){
          setlocalvar("x"+self, -Velx);
        } else { setlocalvar("x"+self, Velx); }
      }
    }
}

void targetL(float Vy, float dx, float dz)
{// Targetting opponent before performing targetted leap attack
// Vy = y Velocity
// dx = x added distance
// dz = z added distance

    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    if (dir == 0){ //Is entity facing left? 
      dx = -dx; //Reverse X direction to match facing
    }

    setlocalvar("T"+self, findtarget(self)); //Get nearest player

    if( getlocalvar("T"+self) != NULL()){
      void target = getlocalvar("T"+self);
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");

      if(Tx < x){
        changeentityproperty(self, "direction", 0);
      } else {
        changeentityproperty(self, "direction", 1);
      }

      x = x+dx;
      z = z+dz;
      setlocalvar("x"+self, (Tx-x)/(22*Vy));
      setlocalvar("z"+self, (Tz-z)/(22*Vy));

    } else {
      setlocalvar("z"+self, 0);
      setlocalvar("x"+self, 0);
    }
}



void grabfree(int isTrue, void vself)
{// releases player and enemy grab state
  // V 0.02
   //void self = getlocalvar("self");
   void target = getentityproperty(vself, "opponent");
   //void target = getlocalvar("Target" + vself);

   if(target==NULL())
   {
     target = getentityproperty(vself, "grabbing");
     setlocalvar("Target" + vself, target);
   }
   if(target!=NULL())
   {
     bindentity(target, NULL());
     bindentity(vself, NULL());
     changeentityproperty(target, "aiflag", "idling", 1);
     changeentityproperty(target, "animation", openborconstant("ani_idle"));
     //performattack(target, openborconstant("ANI_IDLE"));
     //performattack(vself, openborconstant("ANI_IDLE"));
     /*
     if(Gr == 1)
     {
       int x = getentityproperty(target, "x");
       int z = getentityproperty(target, "z");
       changeentityproperty(target, "position", x, z, 0);
     }
     */
   }
}


void grabrelease(int Gr)
{// Release grabbed entity
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     bindentity(target, NULL());

     if(Gr == 1)
     {
       int x = getentityproperty(target, "x");
       int z = getentityproperty(target, "z");
       changeentityproperty(target, "position", x, z, 0);
     }
   }
}

void attackoff()
{// Cancels attack if targetted player is fallen on ground
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player

    if(target!=NULL()){
      void PAnim = getentityproperty(target, "animationID");
	if(PAnim == openborconstant("ANI_fall"))
      if(PAnim == openborconstant("ANI_rise")){
        setidle(self, openborconstant("ANI_backwalk"));
      }
    }
}

void attackoff2()
{// Cancels attack if targetted player is fallen on ground
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player

    if(target!=NULL()){
      void EAnim = getentityproperty(target, "animationID");
	if(EAnim == openborconstant("ANI_fall"))
      if(EAnim == openborconstant("ANI_fall1"))
	
	if(EAnim == openborconstant("ANI_attack1"))
	if(EAnim == openborconstant("ANI_fall2"))
	if(EAnim == openborconstant("ANI_pain"))
	if(EAnim == openborconstant("ANI_pain2"))
	if(EAnim == openborconstant("ANI_spawn"))
	if(EAnim == openborconstant("ANI_follow1"))
	if(EAnim == openborconstant("ANI_follow2"))
	if(EAnim == openborconstant("ANI_follow3"))
	if(EAnim == openborconstant("ANI_follow4"))
	if(EAnim == openborconstant("ANI_follow5"))
	if(EAnim == openborconstant("ANI_follow6"))
	if(EAnim == openborconstant("ANI_follow7"))
	if(EAnim == openborconstant("ANI_rise")){
        changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW2"));
      }
    }
}


void attackoff3(void Ani)
{// Cancels attack if targetted player is fallen on ground
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    int Dir = getentityproperty(self,"direction");
    int TDir = getentityproperty(target,"direction");
   
    if(target!=NULL()){
      void PAnim = getentityproperty(target, "animationID");

      if(PAnim == openborconstant("ANI_follow24") || PAnim == openborconstant("ANI_follow24") || PAnim == openborconstant("ANI_follow24") || PAnim == openborconstant("ANI_follow21") || PAnim == openborconstant("ANI_follow21") || PAnim == openborconstant("ANI_follow21") && Dir == TDir){
        performattack(self, openborconstant(Ani)); //Change the animation
      }
    }
}

void attackoff4(void Ani)
{// Cancels attack if targetted player is fallen on ground
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    int Dir = getentityproperty(self,"direction");
    int Dir = getentityproperty(target,"direction");

    if(target!=NULL()){
      void EAnim = getentityproperty(target, "animationID");

      if(EAnim == openborconstant("ANI_fall") || EAnim == openborconstant("ANI_fall1") || EAnim == openborconstant("ANI_attack1") || EAnim == openborconstant("ANI_attack2") || EAnim == openborconstant("ANI_fall3") || EAnim == openborconstant("ANI_fall2") && Dir == Dir){
        performattack(self, openborconstant(Ani)); //Change the animation
      }
    }
}

void attackoff5(void Ani)
{// Cancels attack if targetted player is fallen on ground
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    int Dir = getentityproperty(self,"direction");
    int Dir = getentityproperty(target,"direction");

    if(target!=NULL()){
  
	void PAnim = getentityproperty(target, "animationID");
      if(PAnim == openborconstant("ANI_fall") || PAnim == openborconstant("ANI_fall1") || PAnim == openborconstant("ANI_rise") || PAnim == openborconstant("ANI_riseattack") || PAnim == openborconstant("ANI_fall3") || PAnim == openborconstant("ANI_fall2") && Dir == Dir){
        performattack(self, openborconstant(Ani)); //Change the animation
      }
    }
}
void backstabber(void Ani , int RxMin, int RxMax, int Rz, int Flag)
{// Checks closest enemy's animation & range for Shannon's backstab
// If it's accepted, change animation
// Ani   : Animation to change to
// RxMin : Minimum x range
// RxMax : Maximum x range
// Rz    : z range
// Flag  : 0 = facing direction not necessary, 1 = facing direction must same, -1 = facing direction must be opposite

/*Originally smartbomb by
    Damon Vaughn Caskey
    07152008*/

    void self = getlocalvar("self");			//Caller.
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    int dir = getentityproperty(self, "direction");
    void vEntity;                                       //Target entity placeholder.
    int  iEntity;                                       //Entity enumeration holder.
    int  iType;                                         //Entity type.
    int  iMax      = openborvariant("ent_max");         //Entity count.
    int iHP;

     //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iType   = getentityproperty(vEntity, "type"); //Get target type.
      iHP   = getentityproperty(vEntity, "health"); //Get health

      //PLAYER type?
      if (iType == openborconstant("TYPE_PLAYER") && iHP > 0){
        float Tx = getentityproperty(vEntity, "x");
	float Tz = getentityproperty(vEntity, "z");
        int Edir = getentityproperty(vEntity, "direction");

        float Disx = Tx - x;
        float Disz = Tz - z;

        if(Disz < 0){
          Disz = -Disz;
        }

        if(Disx >= RxMin && Disx <= RxMax && Disz <= Rz && dir == 1){
          if((Flag == 1 && Edir == 1) || Flag == 0){
            changeentityproperty(self, "opponent", vEntity);
            performattack(self, openborconstant(Ani));
          }
     } else if(Disx >= -RxMax && Disx <= -RxMin && Disz <= Rz && dir == 0){
          if((Flag == 1 && Edir == 0) || Flag == 0){
            changeentityproperty(self, "opponent", vEntity);
            performattack(self, openborconstant(Ani));
          }
        }
      }
    }
}










void targetPos(float Vy, int Tx, int Tz)
{// Targetting certain position before leaping there
//  Vy : Leaping speed
//  Tx : Leaping destination x coordinate
//  Tz : Leaping destination z coordinate
// Used with 'leap' or 'toss2'
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x"); // Get entity's x coordinate
    float z = getentityproperty(self, "z"); // Get entity's z coordinate

    if(Tx < x){
      changeentityproperty(self, "direction", 0); // Face left 
    } else {
      changeentityproperty(self, "direction", 1); // Face right
    }
    setlocalvar("x"+self, (Tx-x)/(20*Vy)); // Calculate Vx then store value in local variable
    setlocalvar("z"+self, (Tz-z)/(20*Vy)); // Calculate Vz then store value in local variable
} 



void antiwallw(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if(Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);

   if(Hz >= y)
   {
     changeentityproperty(self, "position", x, z-Distz);
     changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
     changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW38"));
   }

   if(H >= y)
   {
     changeentityproperty(self, "position", x+Move);
     changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
     changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW38"));
   }
}

void antiwallx(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if(Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);

   if(Hz >= y)
   {
     changeentityproperty(self, "position", x, z-Distz);
     changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
     changeentityproperty(self, "animation", openborconstant("ANI_idle"));
   }

   if(H >= y)
   {
     changeentityproperty(self, "position", x+Move);
     changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
     changeentityproperty(self, "animation", openborconstant("ANI_backwalk"));
   }
}


void dirspeed()
{ // Match facing direction with x velocity
    void self = getlocalvar("self");
    float Vx = getentityproperty(self, "xdir");

    if (Vx < 0){
      changeentityproperty(self, "direction", 0); //Face left!
    } else if (Vx > 0){
      changeentityproperty(self, "direction", 1); //Face right!
    }
}




void killIfDead(){
	void self = getlocalvar("self");
	int  Health = getentityproperty(self, "health");
	log("Health : " + Health);
      if (Health <= 10){
        killentity(self);
      }
	
}





void startSecondAttack(){

	void vEnt = getlocalvar("self");
	void aniID = openborconstant("ANI_grabattack2");
	performattack(vEnt, aniID, 1);
	
}


void looper(int Frame, int Limit)
{// Loops current animation
    void self = getlocalvar("self");
    void loop = getlocalvar("Loop" + self);

    if(loop==NULL()){ // Localvar empty?
      setlocalvar("Loop" + self, 0);
      loop = 0;
    }
   
    if(loop < Limit){ // loops reach limit?
      setlocalvar("Loop" + self, loop+1); // Increment number of loops
      updateframe(self, Frame); //Change frame
    } else if(loop==Limit){ // loops reach limit?
      setlocalvar("Loop" + self, NULL());
    }
}
void set_hold_time(int p, char key, int value) {
    int key_flag = playerkeys(p,0,key);

    if ( value == NULL() ) {
        if ( key_flag ) setglobalvar("__"+p+"_"+key+"", openborvariant("elapsed_time"));
    } else {
        setglobalvar("__"+p+"_"+key+"", value);
    }
}
void fatal(){
    void self = getlocalvar("self");
    void vAniID = getentityproperty(self,"animationID");
    void target = getentityproperty(self,"opponent");
    void iType;
    int THealth;

    if(self == openborconstant("ANI_idle")){
      THealth = getentityproperty(target, "health");
      iType   = getentityproperty(target, "type");

      if(THealth == 0 && iType == openborconstant("TYPE_ENEMY")){
        setentityvar(self, 0, "Kill");
      }
    }
}


void slamstart11()
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL13")); // Slam Starter
   }
}

void suicide()
{ // Suicide!!
    void self = getlocalvar("self");

    killentity(self); //Suicide!
}

void slamstart13()
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 0, openborconstant("ATK_NORMAL24")); // Slam Starter
   }
}



void slamstart14()
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 0, openborconstant("ATK_NORMAL10")); // Slam Starter
   }
}




void riseattack4(int Rx, int Rz, void Ani)
{// Riseattack with range check
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    int Dir = getentityproperty(self,"direction");
    int TDir = getentityproperty(target,"direction");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disx < 0){
        Disx = -Disx;
      }
      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx <= Rx && Disz <= Rz && Dir == TDir) // Target within range?
      {
        changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
      } 
    }
}


void riseattack5(int Rx, int Rz, void Ani)
{// Riseattack with range check
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    int Dir = getentityproperty(self,"direction");
    int TDir = getentityproperty(target,"direction");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disx > 0){
        Disx = -Disx;
      }
      if(Disz > 0){
        Disz = -Disz;
      }

      if( Disx <= Rx && Disz <= Rz && Dir >= TDir) // Target within range?
      {
        changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
      } 
    }
}



void hpcost( int HCost)
{// Spend some life
    void self = getlocalvar("self");
    void Life = getentityproperty(self,"health"); //get health
if (Life > HCost){ //Does the entity have enough health?
       changeentityproperty(self, "health", Life-HCost);//consume health

	} 
}



void scrollcam(float xoff, float zoff, float spd, int reset) {
  if( openborvariant("in_level") ) {
    if ( reset > 0 ) {
        setlocalvar("stored_xoff",NULL());
        setlocalvar("stored_zoff",NULL());
	return;
    }
    if ( getlocalvar("stored_xoff") == NULL() ) {
        setlocalvar("stored_xoff",getlevelproperty("cameraxoffset"));
        setlocalvar("stored_zoff",getlevelproperty("camerazoffset"));
    }

    if ( spd == NULL() ) spd = 1;
    changelevelproperty("scrollspeed", spd); //Scrolling camera speed
    changelevelproperty("cameraxoffset", xoff); //X offset for camera
    changelevelproperty("camerazoffset", zoff); //Z offset for camera
  }

  return;
}

void restore_scrollcam(float spd) {
  if( openborvariant("in_level") ) {
    if ( spd == NULL() ) spd = 1;
    if ( getlocalvar("stored_xoff") != NULL() && getlocalvar("stored_zoff") != NULL() ) {
    	changelevelproperty("scrollspeed", spd); //Scrolling camera speed
    	changelevelproperty("cameraxoffset", getlocalvar("stored_xoff")); //X offset for camera
    	changelevelproperty("camerazoffset", getlocalvar("stored_zoff")); //Z offset for camera
    }
  }

  return;
}



void slamstart15()
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL5")); // Slam Starter
   }


}


void slamstart()
{ // Slam Starter
// Use finish after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL")); // Slam Starter
   }
   
}

void throw3(int Damage, int Type, int x, int y, int z, int Face)
{ // Damage as throw finisher
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);
   int SDir = getentityproperty(target,"direction");
   int MDir;

   if(Face==0){ // Same facing?
       MDir = SDir;
   }

   if(Face==1){ // Opposite facing?

     if(SDir==0){ // Facing left?
       MDir = 1;
     } else { MDir = 0;}
   }

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int dir = getentityproperty(target,"direction"); //Get opponent's facing direction
     if(dir==0){ // Facing left?
       x = -x;
     }

     if(Type==1)
     {
       damageentity(target, self, 0, 0, openborconstant("ATK_NORMAL5")); // 1st throw type
     }

     

     changeentityproperty(target, "attacking", 1);
     changeentityproperty(target, "damage_on_landing", Damage);
     changeentityproperty(target, "projectile", 1);
     changeentityproperty(target, "direction", MDir);
     tossentity(target, y, x, z); // Toss opponent ;)
   }
}


void spawnM(void Name, float dx, float dy, float dz)
{ // Spawn certain entity and matches its map with own's map
   void self = getlocalvar("self");
   int map = getentityproperty(self,"map");
   void Spawn;

   Spawn = spawn01(Name, dx, dy, dz);
   changeentityproperty(Spawn, "map", 4);
}

void spawnM2(void Name, float dx, float dy, float dz)
{ // Spawn certain entity and matches its map with own's map
   void self = getlocalvar("self");
   int map = getentityproperty(self,"map");
   void Spawn;

   Spawn = spawn01(Name, dx, dy, dz);
   changeentityproperty(Spawn, "map", 1);
}

void cancelgrab()
        {// Check grabbed opponent's name
        // If it's forbidden to grab him/her, revert to IDLE
           void self = getlocalvar("self");
           void target = getlocalvar("Target" + self);

           if(target==NULL())
           {
             target = getentityproperty(self, "opponent");
             setlocalvar("Target" + self, target);
           }
           if(target!=NULL())
           {
             char Tname = getentityproperty(target, "defaultname");
             char iType = getentityproperty(target, "type");

             if(Tname == "Car" || Tname == "Car2" || Tname == "Car3" || Tname == "Car4" || Tname == "Car5" || Tname == "cartel" || Tname == "door" || Tname == "door0" || Tname == "bottle" || Tname == "ninja" || Tname == "AABOBO3" || Tname == "Duke" || Tname == "Kikucho" || Tname == "gw" || Tname == "Lindaln" || Tname == "Lindan" || Tname == "Linda" || Tname == "Lindal" || 

Tname == "Abobo" || Tname == "Bolon" || Tname == "Lindal2" || Tname == "SChin" || Tname == "Matrix4" || Tname == "Matrix3" || Tname == "Matrix2" || Tname == "Linda4" || Tname == "vidrio" || Tname == "Harry" || Tname == "Mibobo" || Tname == "Burnovx22" || Tname == "fonola" || Tname == "punk" || iType == openborconstant

("TYPE_OBSTACLE") || iType ==openborconstant("TYPE_ITEM"))
             {
                 changeentityproperty(self, "animation", openborconstant("ANI_attack3"));
             }
           }
        }

void cancelgrab2()
        {// Check grabbed opponent's name
        // If it's forbidden to grab him/her, revert to IDLE
           void self = getlocalvar("self");
           void target = getlocalvar("Target" + self);

           if(target==NULL())
           {
             target = getentityproperty(self, "opponent");
             setlocalvar("Target" + self, target);
           }
           if(target!=NULL())
           {
             char Tname = getentityproperty(target, "defaultname");
             char iType = getentityproperty(target, "type");

             if(Tname == "Car" || Tname == "Car2" || Tname == "Car3" || Tname == "Car4" || Tname == "Car5" || Tname == "cartel" || Tname == "door" || Tname == "door0" || Tname == "bottle" || Tname == "ninja" || Tname == "AABOBO3" || Tname == "bottle" || Tname == "Kikucho" || Tname == "gw" || Tname == "Lindaln" || Tname == "Lindan" || Tname == "Linda" || Tname == "Lindal" || 

Tname == "Abobo" || Tname == "Bolon" || Tname == "Lindal2" || Tname == "SChin" || Tname == "Matrix4" || Tname == "Matrix3" || Tname == "Matrix2" || Tname == "vidrio" || Tname == "Linda4" || Tname == "Harry" || Tname == "Mibobo" || Tname == "Burnovx22" || Tname == "punk" || iType == openborconstant

("TYPE_OBSTACLE") || iType ==openborconstant("TYPE_ITEM"))
             {
                 changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW10"));
             }
           
        


if(Tname == "fonola" || Tname == "punk" || iType == openborconstant

("TYPE_OBSTACLE") || iType ==openborconstant("TYPE_ITEM"))
             {
                 changeentityproperty(self, "animation", openborconstant("ANI_idle"));
             }
           }
        }



void cancelgrab3()
        {// Check grabbed opponent's name
        // If it's forbidden to grab him/her, revert to IDLE
           void self = getlocalvar("self");
           void target = getlocalvar("Target" + self);

           if(target==NULL())
           {
             target = getentityproperty(self, "opponent");
             setlocalvar("Target" + self, target);
           }
           if(target!=NULL())
           {
             char Tname = getentityproperty(target, "defaultname");
             char iType = getentityproperty(target, "type");

             if(Tname == "bazooka_item" || Tname == "bazooka_item" || Tname == "bazooka_item" || Tname == "bazooka_item" || Tname == "bazooka_item" || Tname == "cartel" || Tname == "door" || Tname == "door0" || Tname == "bottle" || Tname == "ninja" || Tname == "AABOBO3" || Tname == "Duke" || Tname == "Kikucho" || Tname == "gw" || Tname == "Lindaln" || Tname == "Lindan" || Tname == "Linda" || Tname == "Lindal" || Tname == "punk" || iType == openborconstant

("TYPE_OBSTACLE") || iType ==openborconstant("TYPE_ITEM"))
             {
                 setidle(self, openborconstant("ANI_IDLE"));
             }
           }
        }


void spawn06(void vName, float fX, float fY, float fZ)
{
	//Spawns entity based on left screen edge and z axis
	//Auto adjust with camera's position
	//vName: Model name of entity to be spawned in.
	//fX: X distance relative to left edge
	//fY: Y height from ground
      //fZ: Z coordinate

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int Direction = getentityproperty(self, "direction");
        int XPos = openborvariant("xpos"); //Get screen edge's position
        int YPos = openborvariant("ypos"); // Get camera position
        int Screen = openborvariant("hResolution"); // Get screen width

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

   if (Direction == 0){ //Is entity facing left?                  
      fX = Screen-fX; //Reverse X direction to match facing and screen length
   }

	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX + XPos, fZ + YPos, fY); //Set spawn location.
	return vSpawn; //Return spawn
}


void basechange2()
{// Check altitude. If bomb is on base, change animation!

    void self = getlocalvar("self");
    int y = getentityproperty(self,"a"); //Get bomb's altitude
    int b = getentityproperty(self, "base"); //Get base

    if( y >= 55+b ){ 
      damageentity(self, self, 20, 1, openborconstant("ATK_NORMAL24"));
    }
}


void basechange()
{// Check altitude. If bomb is on base, change animation!

    void self = getlocalvar("self");
    int y = getentityproperty(self,"a"); //Get bomb's altitude
    int b = getentityproperty(self, "base"); //Get base

    if( y >= 140+b ){ 
      damageentity(self, self, 20, 1, openborconstant("ATK_NORMAL24"));
    }
}
void basechange3()
{// Check altitude. If bomb is on base, change animation!

    void self = getlocalvar("self");
    int y = getentityproperty(self,"a"); //Get bomb's altitude
    int b = getentityproperty(self, "base"); //Get base

    if( y >= 100+b ){ 
      damageentity(self, self, 20, 1, openborconstant("ATK_NORMAL2"));
    }
}


void basechange4()
{// Check altitude. If bomb is on base, change animation!

    void self = getlocalvar("self");
    int y = getentityproperty(self,"a"); //Get bomb's altitude
    int b = getentityproperty(self, "base"); //Get base
    //if( y >= 360+b ){
    if( y >= 200+b ){ 
      changeentityproperty(self, "animation", openborconstant("ANI_follow21"));
      //damageentity(self, self, 0, 0, openborconstant("ATK_NORMAL8"));
    }
}

void basechange5()
{// Check altitude. If bomb is on base, change animation!

    void self = getlocalvar("self");
    int y = getentityproperty(self,"a"); //Get bomb's altitude
    int b = getentityproperty(self, "base"); //Get base

    if( y >= 390+b ){ 
      changeentityproperty(self, "animation", openborconstant("ANI_follow22"));
      //damageentity(self, self, 0, 0, openborconstant("ATK_NORMAL8"));
    }
}
void paus0001(int iToggle, int iTime){

    /*
    paus0001
    Damon Vaughn Caskey
    11022009
    Pause or unpause action for all entities except self.
    */

    void vSelf      = getlocalvar("self");                  //Caller    
    int  iETime     = openborvariant("elapsed_time");       //Current time.
    int  iMax       = openborvariant("ent_max");            //Entity count.
    int  iEntity;                                           //Loop counter.
    void vEntity;                                           //Target entity.

    for(iEntity=0; iEntity<iMax; iEntity++)
    {    
        vEntity = getentity(iEntity);                                       //Get target entity from current loop.        
        
        if (vEntity != vSelf)                                               //Not Self?
        {
            changeentityproperty(vEntity, "frozen", iToggle);               //Toggle frozen.
            changeentityproperty(vEntity, "freezetime", iETime + iTime);    //Toggle frozen time.
        }
    }    
}

void grabcheck()
{// Prevents enemy from performing the slam if he/she's not grabbing anyone
   void self = getlocalvar("self");
   void target = getentityproperty(self, "grabbing");

   if(target==NULL())
   {
//     setidle(self); //Don't perform the slam.
     performattack(self, openborconstant("ANI_IDLE")); //Don't perform the slam.
   }
}

void grabcheck2()
{// Prevents enemy from performing the slam if he/she doesn't have any target
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     performattack(self, openborconstant("ANI_IDLE")); //Don't perform the slam.
   }
}

void DeControl(int P, int Flag)
{// Activates or deactivates control for defined player
// P : Player index starting from 0
// Flag : Control flag
    int Player = getplayerproperty(P, "entity");

    if (Player != NULL()){
      changeentityproperty(Player,"noaicontrol",Flag);
    }
}

void slamstart25()
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 0, openborconstant("ATK_NORMAL25")); // Slam Starter
   }
}


void spawnlimiter(int Limit)
{// Prevents an enemy from performing an animation if there are too many enemies alive.
 // Viper Snake - 6/16/2015
    void self = getlocalvar("self");
    int spawnMAX = openborvariant("count_enemies"); //How many enemies?
    int y = getentityproperty(self,"a"); //Get entity's altitude
    int b = getentityproperty(self, "base"); //Get entity's base

   if(spawnMAX>=Limit) //Enemy limit reached?
   {
     if(y > b) // Mid air?
     {
       changeentityproperty(self, "animation", openborconstant("ANI_jump") );
     } else{
       setidle(self); //Don't play the animation
     }
   }
}



void spawnEnemy(float dx, float dy, float dz)
{ // Spawn enemy from door
    void self = getlocalvar("self");
    char Name = getentityproperty(self,"name");
    int HP = getentityproperty(self,"health");
    int Map = getentityproperty(self,"map");
    void vSpawn;

    vSpawn = spawn01(Name, dx, dy, dz);
    changeentityproperty(vSpawn, "health", HP);
    changeentityproperty(vSpawn, "map", Map);
    setentityvar(vSpawn, 6, 1);
}

void dropEnemy(float dx, float dy, float dz)
{ // Drops enemy
    void self = getlocalvar("self");
    char Name = getentityproperty(self,"name");
    int HP = getentityproperty(self,"health");
    void vSpawn;

    vSpawn = spawn01(Name, dx, dy, dz);
    changeentityproperty(vSpawn, "health", HP);
    setentityvar(vSpawn, 6, 4);
}

void antiwallx1(int Dist, void Ani)
{// Checks if there is wall at defined distance
// If there is wall, entity will change animation
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float H;

   if(Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
   }

   H = checkwall(x+Dist,z);

   if(H >= y)

   {
     changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
     changeentityproperty(self, "animation", openborconstant(Ani));
   }
}


void falldelay (void Ani, int Frame, int fDist)
{// Delayed animation change while falling off a platform.
 // Viper Snake - 3/5/2015
    void self = getlocalvar("self");
    int a = getentityproperty(self,"a"); //Get entity's altitude
    int b = getentityproperty(self, "base"); //Get entity's base	

     if(a > b + fDist){
	performattack(self, openborconstant(Ani)); //Change the animation
	changeentityproperty(self, "animpos", Frame);
	}
}

void edge(){
    void self = getlocalvar("self");
    int Dir = getentityproperty(self, "direction");
    int x = getentityproperty(self, "x");
    int y = getentityproperty(self, "a");
    int z = getentityproperty(self, "z");
    int Wall = checkwall(x, z);
    int C = 20;
    int WallC;

    if(Wall>0){ // on a platform
      if(Dir==0){
        WallC = checkwall(x+C, z);
      } else {
        WallC = checkwall(x-C, z);
      } 

      if(WallC < y){
	changeentityproperty(self, "animation", openborconstant("ANI_follow15"));
      }
    }
}



void edge2(){
    void self = getlocalvar("self");
    int Dir = getentityproperty(self, "direction");
    int x = getentityproperty(self, "x");
    int y = getentityproperty(self, "a");
    int z = getentityproperty(self, "z");
    int Wall = checkwall(x, z);
    int C = 5;
    int C2 = 50;
    int WallC;

    
      if(Wall>0){ // on a platform
      if(Dir==1){
        WallC = checkwall(x+C, z);
      } else {
        WallC = checkwall(x-C, z);
      }       

      

      if(WallC < y){
	changeentityproperty(self, "animation", openborconstant("ANI_walkoff"));
      } 
   }
}



void door(){
    void self = getlocalvar("self");
    void P1 = getplayerproperty(0, "entity");
    void P2 = getplayerproperty(1, "entity");
    int Play = openborvariant("count_players");
    int x = getentityproperty(self,"x");
    int z = getentityproperty(self,"z");
    int Dir = getentityproperty(self,"direction");

    if(Play==1 && (P1 || P2)){
      int Px;
      int Pz;

      if(P1){
        Px = getentityproperty(P1,"x");
        Pz = getentityproperty(P1,"z");
      } else if(P2){
        Px = getentityproperty(P2,"x");
        Pz = getentityproperty(P2,"z");
      }

      if(Pz <= z-10 && Pz >= z-15){
        if(Dir==0 && Px <= x){
          changeentityproperty(self, "animation", openborconstant("ANI_follow2"));
        } else if(Dir==1 && Px >= x){
          changeentityproperty(self, "animation", openborconstant("ANI_follow2"));
        }
      }
    } else if(Play==2 && P1 && P2){
      int P1x = getentityproperty(P1,"x");
      int P1z = getentityproperty(P1,"z");
      int P2x = getentityproperty(P2,"x");
      int P2z = getentityproperty(P2,"z");

      if(P1z <= z-10 && P1z >= z-15 && P2z <= z-10 && P2z >= z-15){
        if(Dir==0 && P1x <= x+5 && P2x <= x+5){
          changeentityproperty(self, "animation", openborconstant("ANI_follow2"));
        } else if(Dir==1 && P1x >= x+5 && P2x >= x+5){
          changeentityproperty(self, "animation", openborconstant("ANI_follow2"));
        }
      }
    }
}

void teletarget(int dx, int dy, int dz)
{// Targetting opponent then teleport to target
    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction");

    if(dir==0){ // Facing left?
      dx = -dx ;
    }

    setlocalvar("T"+self, findtarget(self)); //Get nearest player

    if( getlocalvar("T"+self) != NULL()){
      void target = getlocalvar("T"+self);
      int Tx = getentityproperty(target, "x");
      int Tz = getentityproperty(target, "z");

      changeentityproperty(self, "position", Tx+dx, Tz+dz, dy); //Teleport to target!
    } 
}

void slamstart12()
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL16")); // Slam Starter
   }
}



void conditionalflip3()
{ // Flipping based on currently grabbed enemy
   void self = getlocalvar("self");
   void target = getentityproperty(self, "opponent");

   if(target)
   {
     int Direction = getentityproperty(self, "direction");
     int TDir = getentityproperty(target, "direction");

     if(TDir == 1 && Direction == 1){             
       changeentityproperty(self, "direction", 0);
     } else if(TDir == 0 && Direction == 0){
       changeentityproperty(self, "direction", 1);
     }
   }
}



void attackoff3(void Ani)
{// Cancels attack if targetted player is fallen on ground
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    int Dir = getentityproperty(self,"direction");
    int TDir = getentityproperty(target,"direction");
   
    if(target!=NULL()){
      void PAnim = getentityproperty(target, "animationID");

      if(PAnim == openborconstant("ANI_follow24") || PAnim == openborconstant("ANI_follow24") || PAnim == openborconstant("ANI_follow24") || PAnim == openborconstant("ANI_follow21") || PAnim == openborconstant("ANI_follow21") || PAnim == openborconstant("ANI_follow21") && Dir == TDir){
        performattack(self, openborconstant(Ani)); //Change the animation
      }
    }
}
void riseattack3(int Rx, int Rz, void Ani)
{// Riseattack with range check
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    int Dir = getentityproperty(self,"direction");
    int TDir = getentityproperty(target,"direction");
    int b = getentityproperty(self, "base");
    int tb = getentityproperty(target, "base");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disx < 0){
        Disx = -Disx;
      }
      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx <= Rx && Disz <= Rz && b == tb && Dir == TDir) // Target within range?
      {
        changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
      } 
    }
}

void kickreact(int RxMin, int RxMax, int Ry, int Rz, void EAni)
{// Cambio de animación si el oponente cercano está pateando
// RxMin : Minimum x range
// RxMax : Maximum x range
// Ry : Altitude difference
// Rz : Z range
// EAni : Enemy's animation to change to
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    float z = getentityproperty(self, "z");
    int dir = getentityproperty(self, "direction");
    void target = findtarget(self); //Obtener el oponente más cercano

    if(target!=NULL()){
      void PAnim = getentityproperty(target, "animationID");
      float Tx = getentityproperty(target, "x");
      float Ty = getentityproperty(target, "a");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disy = Ty - y;
      float Disz = Tz - z;

      if(Disy < 0){
        Disy = -Disy;
      }

      if(Disz < 0){
        Disz = -Disz;
      }

      if(PAnim == openborconstant("ANI_follow24") || PAnim == openborconstant("ANI_follow24") || PAnim == openborconstant("ANI_follow21") || PAnim == openborconstant("ANI_follow21") || PAnim == openborconstant("ANI_follow21") || PAnim == openborconstant("ANI_follow21") || PAnim == openborconstant("ANI_follow21") || PAnim == openborconstant("ANI_follow21")){
        if( Disx >= RxMin && Disx <= RxMax && Disy <= Ry && Disz <= Rz && dir == 1){
          performattack(self, openborconstant(EAni)); //Change the animation
        } else if(Disx >= -RxMax && Disx <= -RxMin && Disy <= Ry && Disz <= Rz && dir == 0){
          performattack(self, openborconstant(EAni)); //Change the animation
        }
      }
    }
}
void attackoff4(void Ani)
{// Cancela el ataque si el jugador objetivo está caído en tierra
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    int Dir = getentityproperty(self,"direction");
    int TDir = getentityproperty(target,"direction");
   
    if(target!=NULL()){
      void PAnim = getentityproperty(target, "animationID");

      if(PAnim == openborconstant("ANI_FOLLOW8") || PAnim == openborconstant("ANI_FOLLOW8") || PAnim == openborconstant("ANI_idle") || PAnim == openborconstant("ANI_walk") || PAnim == openborconstant("ANI_FOLLOW8") || PAnim == openborconstant("ANI_fall3") || PAnim == openborconstant("ANI_fall3") || PAnim == openborconstant("ANI_rise") && Dir == TDir){
        performattack(self, openborconstant(Ani)); //Change the animation
      }
    }
}

void kickreact1(int RxMin, int RxMax, int Ry, int Rz, void EAni)
{// Cambio de animación si el oponente cercano está pateando
// RxMin : Minimum x range
// RxMax : Maximum x range
// Ry : Altitude difference
// Rz : Z range
// EAni : Enemy's animation to change to
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    float z = getentityproperty(self, "z");
    int dir = getentityproperty(self, "direction");
    void target = findtarget(self); //Obtener el oponente más cercano

    if(target!=NULL()){
      void PAnim = getentityproperty(target, "animationID");
      float Tx = getentityproperty(target, "x");
      float Ty = getentityproperty(target, "a");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disy = Ty - y;
      float Disz = Tz - z;

      if(Disy < 0){
        Disy = -Disy;
      }

      if(Disz < 0){
        Disz = -Disz;
      }

      if(PAnim == openborconstant("ANI_idle") || PAnim == openborconstant("ANI_walk") || PAnim == openborconstant("ANI_backwalk") || PAnim == openborconstant("ANI_follow21") || PAnim == openborconstant("ANI_follow21") || PAnim == openborconstant("ANI_rise") || PAnim == openborconstant("ANI_rise") || PAnim == openborconstant("ANI_follow21")){
        if( Disx >= RxMin && Disx <= RxMax && Disy <= Ry && Disz <= Rz && dir == 1){
          performattack(self, openborconstant(EAni)); //Change the animation
        } else if(Disx >= -RxMax && Disx <= -RxMin && Disy <= Ry && Disz <= Rz && dir == 0){
          performattack(self, openborconstant(EAni)); //Change the animation
        }
      }
    }
}

void spikeh4er(int RxMin, int RxMax, int Rz, int RyMin, int RyMax)
{
    void self = getlocalvar("self");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    float y = getentityproperty(self, "a");

    void vEntity;                                       //Target entity placeholder.
    void vAniID;
    int  iEntity;                                       //Entity enumeration holder.
    int  iType;                                         //Entity name.
    int  iMax      = openborvariant("ent_max");         //Entity count.

    float Tx;
    float Tz;
    float Ty;
    float Disx;
    float Disz;
    float Disy;

    //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iType   = getentityproperty(vEntity, "type");
      vAniID  = getentityproperty(vEntity,"animationID");

      if(iType == openborconstant("TYPE_ENEMY")){
        if(vAniID == openborconstant("ANI_FOLLOW5") || vAniID == openborconstant("ANI_PAIN34") || vAniID == openborconstant("ANI_FALL3") || vAniID == openborconstant("ANI_FALL9")
        || vAniID == openborconstant("ANI_FALL4") || vAniID == openborconstant("ANI_FALL5") || vAniID == openborconstant("ANI_FALL6") || vAniID == openborconstant("ANI_FALL7")
        || vAniID == openborconstant("ANI_FALL12") || vAniID == openborconstant("ANI_FALL14") || vAniID == openborconstant("ANI_FALL17")){
          Tx = getentityproperty(vEntity, "x");
          Tz = getentityproperty(vEntity, "z");
          Ty = getentityproperty(vEntity, "a");
          Disx = Tx - x;
          Disz = Tz - z;
          Disy = Ty - y;


          if(Disx >= RxMin && Disx <= RxMax && Disz >= -Rz && Disz <= Rz && Disy >= RyMin && Disy <= RyMax){
            changeentityproperty(vEntity, "direction", 1);
            changeentityproperty(vEntity, "animation", openborconstant("ANI_idle"));
          }
        }
      }
    }
}
void clearb()
{// Clears all local variables
     clearglobalvar();
}


void spawnbind2(void Name1, void Name2, float dx, float dy, float dz)
{ // Spawn and bind other entity
   void P1 = getplayerproperty(0, "entity");
   void P2 = getplayerproperty(1, "entity");
   void vAniID1 = getentityproperty(P1,"animationID");
   void vAniID2 = getentityproperty(P2,"animationID");
   void Spawn;

   if(P1 && vAniID1 == openborconstant("ANI_follow70") || vAniID1 == openborconstant("ANI_RESPAWN") || vAniID1 == openborconstant("ANI_FREESPECIAL26") || vAniID1 == openborconstant("ANI_FREESPECIAL27") || vAniID1 == openborconstant("ANI_FREESPECIAL28") || vAniID1 == openborconstant("ANI_FREESPECIAL29") || vAniID1 == openborconstant("ANI_FREESPECIAL30") || vAniID1 == openborconstant("ANI_FREESPECIAL31") || vAniID1 == openborconstant("ANI_FREESPECIAL32") || vAniID1 == openborconstant("ANI_FREESPECIAL33") || vAniID1 == openborconstant("ANI_FREESPECIAL34")){
     Spawn = spawn01(Name1, dx, dy, 0);
     bindentity(Spawn, P1, dx, dz, dy, 0, 0);
   }

   if(P2 && vAniID2 == openborconstant("ANI_SPAWN") || vAniID2 == openborconstant("ANI_RESPAWN") || vAniID2 == openborconstant("ANI_FREESPECIAL26") || vAniID2 == openborconstant("ANI_FREESPECIAL27") || vAniID2 == openborconstant("ANI_FREESPECIAL28") || vAniID2 == openborconstant("ANI_FREESPECIAL29") || vAniID2 == openborconstant("ANI_FREESPECIAL30") || vAniID2 == openborconstant("ANI_FREESPECIAL31") || vAniID2 == openborconstant("ANI_FREESPECIAL32") || vAniID2 == openborconstant("ANI_FREESPECIAL33") || vAniID2 == openborconstant("ANI_FREESPECIAL34")){
     Spawn = spawn01(Name2, dx, dy, 0);
     bindentity(Spawn, P2, dx, dz, dy, 0, 0);
   }
}

void elevadorup(void Ani)
{// Check altitude. If bomb is on base, change animation!

    void self = getlocalvar("self");
    int y = getentityproperty(self,"a"); //Get bomb's altitude
    int b = getentityproperty(self, "base"); //Get base
    
    int y = 120;
    //int altitudeC;
	
      
if(y > 120){
	changeentityproperty(self, "animation", openborconstant("ANI_follow2"));
      }
}  
    




void elevadordown(void Ani)
{// Check altitude. If bomb is on base, change animation!

    void self = getlocalvar("self");
    int y = getentityproperty(self,"a"); //Get bomb's altitude
    int b = getentityproperty(self, "base"); //Get base

    if( b >= 70+y ){ // On base?
      performattack(self, openborconstant(Ani)); //Change the animation
    }
}

void dash2(float Vy)
{// Dash with previously attained speed + flying speed
// Used by Jetpacks to prevent diving to ground and to fly back up
    void self = getlocalvar("self");
    float Vx = getlocalvar("x"+self);
    float Vz = getlocalvar("z"+self);
    if( Vx!=NULL() && Vz!=NULL() ){
      changeentityproperty(self, "velocity", Vx, Vz, Vy); //Move towards target!
    }
}

void dodgeleapz( float Vx, float Vy, float Vz )
{// Dodge by leaping up or down depending on z location
    void self = getlocalvar("self");
    int z = getentityproperty(self, "z");
    int dir = getentityproperty(self,"direction");

    if(dir==0){ // Facing left?
      Vx = -Vx ;
    }

    if(z > (openborconstant("PLAYER_MIN_Z") + openborconstant("PLAYER_MAX_Z")) / 2 ) {
      Vz = -Vz ;
    }

    if( Vx!=NULL() && Vy!=NULL() && Vz!=NULL() ){
      tossentity(self, Vy, Vx, Vz); //Dodge and leap away!
    }
}

void target2(float Velx, float Velz, float dx, float dz, int Stop)
{// Targetting opponent before leaping or dashing move horizontal.
// Velx = x Velocity
// Velz = z Velocity
// dx = x added distance
// dz = z added distance
// Stop = flag to stop moving if no target is found

    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    if (dir == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
    }

    setlocalvar("T"+self, findtarget(self)); //Get nearest player

    if( getlocalvar("T"+self) != NULL()){
      void target = getlocalvar("T"+self);
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");


      x = x+dx;
      z = z+dz;
      float Disx = Tx - x;
      float Disz = Tz - z;

//Set both distance as positive value
      if(Disx < 0){
        Disx = -Disx;
      }

      if(Disz < 0){
        Disz = -Disz;
      }

// Calculate velocity for targetting
      if(Disz < Disx)
      {
        if(Tx < x){
          setlocalvar("x"+self, -Velx);
        } else { setlocalvar("x"+self, Velx); }

  //      setlocalvar("z"+self, Velx*(Tz-z)/Disx);
      } else {
        if(Tz < z){
          setlocalvar("z"+self, -Velz);
        } else { setlocalvar("z"+self, Velz); }

        setlocalvar("x"+self, Velz*(Tx-x)/Disz);
      }

    } else {
      if(Stop == 1)
      {
        setlocalvar("z"+self, 0);
        setlocalvar("x"+self, 0);
      } else {
        setlocalvar("z"+self, 0);
        if(dir==0){
          setlocalvar("x"+self, -Velx);
        } else { setlocalvar("x"+self, Velx); }
      }
    }
}
void spawn02(void vName, float fX, float fY, float fZ)
{	//Spawns entity based on left screen edge
	//vName: Model name of entity to be spawned in.
	//fX: X distance relative to left edge
	//fY: Y height from ground
        //fZ: Z location adjustment

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
        int XPos = openborvariant("xpos"); //Get screen edge's x position
        int YPos = openborvariant("ypos"); //Get screen edge's y position

	clearspawnentry(); //Clear current spawn entry.
        setspawnentry("name", vName); //Acquire spawn entity by name.

	vSpawn = spawn(); //Spawn in entity.
	changeentityproperty(vSpawn, "position", fX + XPos, fZ + YPos, fY); //Set spawn location.
	return vSpawn; //Return spawn.
}

void countani(void Ani, void vType, float nr)
{ // Spawns entity until number is >
  // example @cmd countani "ANI_FOLLOW1" "count_enemies" 1  
     void self = getlocalvar("self");
     int ene = openborvariant(vType);
     void Spawn;
     if(ene <= nr){
     changeentityproperty(self, "animation", openborconstant(Ani));
     }
}

void wallhit2(int Dist, void Ani)
{// Checks if there is wall/platform at defined distance change animation
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int z = getentityproperty(self, "z");
   float H; float Hy;

   if(Direction == 0){ //Is entity facing left?                 
      Dist = -Dist; //Reverse Dist to match facing
   }

   H = checkwall(x+Dist,z);
   Hy = checkplatformbelow(x+Dist,z, 5000);

   if(H > 0 || Hy){
     changeentityproperty(self, "animation", openborconstant(Ani));
   }
}


void spawnAnimap(void Name, float dx, float dy, float dz, void Ani)
{ // spawn entity with same map chosse animation
	void self = getlocalvar("self");
	void Spawn;
	int iMap = getentityproperty(self,"map");
	Spawn = spawn01(Name, dx, dy, 0);
	changeentityproperty(Spawn, "map", iMap);
	performattack(Spawn, openborconstant(Ani));
}

void teleonscreen(float dx, void Ani)
{// Teleport on screen
//  dx : Distance to screen edge

    void self = getlocalvar("self");
    int x = getentityproperty(self,"x");
    int XPos = openborvariant("xpos");
    void player = getplayerproperty(0,"entity");
    float px = getentityproperty(player, "x");
    float pz = getentityproperty(player, "z");


    if(x > XPos + 320 + dx){ // Offscreen to the right?
      changeentityproperty(self, "position", px, pz);
      performattack(self, openborconstant(Ani));
    } else if(x < XPos - dx){ // Offscreen to the left?
      changeentityproperty(self, "position", px, pz);
      performattack(self, openborconstant(Ani));
    }
}

void damage(int hp,char ani)
{
		void self=getlocalvar("self");
		void target = getlocalvar("Target" + self);

           if(target==NULL())
           {
             target = getentityproperty(self, "opponent");
             setlocalvar("Target" + self, target);
           }
		if (getentityproperty(self,"health")<=(getentityproperty(self,"maxhealth")*hp/100))
		{
		changeentityproperty(self,"animation",openborconstant(ani));
		}
}

void subminz(int minz)
{// Set's subject to minz
    void self = getlocalvar("self");
    changeentityproperty(self, "subject_to_minz", minz);
}

void submaxz(int maxz)
{// Set's subject to minz
    void self = getlocalvar("self");
    changeentityproperty(self, "subject_to_maxz", maxz);
}


