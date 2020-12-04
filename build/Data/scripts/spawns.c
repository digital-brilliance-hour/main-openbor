#include "data/scripts/animation/animation.c"
void spawn01(void vName, float fX, float fY, float fZ)
{
	//spawn01 (Generic spawner)
	//Damon Vaughn Caskey
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

void spawn02(void vName, float fX, float fY, float fZ, void Alias)
{
	//spawn02 (Generic spawner with alias)
	//Spawns entity next to caller.
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
        //fY: Z location adjustment.
	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iDirection = getentityproperty(self, "direction");

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name",vName); //Acquire spawn entity by name.
	if (iDirection == 0){ //Is entity facing left?                  
          fX = -fX; //Reverse X direction to match facing.
	}

      fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
      fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
      fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.
	
	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.
    	changeentityproperty(vSpawn, "name", Alias); //Set Alias to spawned entity
	return vSpawn; //Return spawn.
}

void spawnbind02(void Name, float dx, float dy, float dz)
{ // Spawn and bind other entity
   void self = getlocalvar("self");
   void frame = getentityproperty(self, "animpos");
   void Spawn;

   Spawn = spawn(Name, dx, dy, 0);
   bindentity(Spawn, self, dx, dz, dy, 0, 0);
   updateframe(Spawn, frame);
}

void damage_all_enemies(int damage, int drop, int stay, void atk_type)
{
 	int  iEntity;
    void vEntity;
    void self        = getlocalvar("self");
    int  iMax        = openborvariant("ent_max");
    int Def;
               
    for(iEntity=0; iEntity<iMax; iEntity++)
    {       
        vEntity = getentity(iEntity);
        Def = getentityproperty(vEntity, "defense", openborconstant("ATK_NORMAL50"));
		if(getentityproperty(vEntity, "type")==openborconstant("TYPE_enemy"))
		{		
		damageentity(vEntity,self,damage,drop,openborconstant(atk_type));
		changeentityproperty(vEntity, "staydown", "riseattack", stay);	
		}
	}	
}

void damage_all_players(int damage, int drop, int stay, void atk_type)
{
 	int  iEntity;
 	void p;
    void vEntity;
    void self        = getlocalvar("self");
    int  iMax        = openborvariant("ent_max");
    int Def;
               
    for(iEntity=0; iEntity<4; iEntity++)
    {       
        p = getplayerproperty(iEntity, "entity");
        if(p){
	        if("Travel"!=getentityproperty(p, "model")) {	
				damageentity(p,self,damage,drop,openborconstant(atk_type));
				changeentityproperty(p, "staydown", "riseattack", stay);	
	        }
        }
	}	
}
// Douglas Baldan / O Ilusionista
// version 1.0 - 20/08/2016
// Check stage type and change animation
void checkStageType (int sVal, void Ani)
{
	void vSelf = getlocalvar("self");
	int stageT = getglobalvar("stageType");
	
	 if(stageT==sVal){
       performattack(vSelf, openborconstant(Ani));
	   
	   
  	}
}

void changeName (void iName)
// Change entity name
// 24.09.2013 - Douglas Baldan - O Ilusionista
{
        void    vSelf   = getlocalvar("self");
        changeentityproperty(vSelf, "name", iName);
}

void unbind ()
// unbind entity
// 24.09.2013 - Douglas Baldan - O Ilusionista
{
void    vSelf   = getlocalvar("self");
bindentity(vSelf, NULL());
}


void spawnRandom(void vName,int vx, int vy )
// Spawn entity at random places
// 24.09.2013 - Douglas Baldan - O Ilusionista
// Based in Damon Caskey "spawn01" function, and you need that function to make it works.
// vx = maximum X position range
// vy = maximum Y position range
{
int Xr = rand()%vx;	// Random X pos
int Yr = rand()%vy;	// Random Y pos
clearspawnentry();
spawn01(vName,vx+Xr,vy+Yr,0);
}

void spawnRandomZ(void vName,int vx, int vy, int vz )
// Spawn entity at random places
// 24.09.2013 - Douglas Baldan - O Ilusionista
// Based in Damon Caskey "spawn01" function, and you need that function to make it works.
// vx = maximum X position range
// vy = maximum Y position range
// vz = maximum Z position range
{
int Xr = rand()%vx;	// Random X pos
int Yr = rand()%vy;	// Random Y pos
int Zr = rand()%vz;	// Random Z pos

spawn000(vName,Xr,Yr,Zr);
}

void spawnRandEnt(void vName1,void vName2,void vName3,void vName4,int vx, int vy, int vz )
// Spawn Random entities at random places
// 03/02/2014 - Douglas Baldan - O Ilusionista
{
// int Xr = rand()%vx;	// Random X pos
// int Yr = rand()%vy;	// Random Y pos
// int Zr = rand()%vz;	// Random Z pos

int Sr = rand()%4+4;

if(Sr == 0){
        spawn000(vName1,vx,vy,vz);
       }
	   
else if(Sr == 1){
        spawn000(vName2,vx,vy,vz);
       }
else if(Sr == 2){
        spawn000(vName3,vx,vy,vz);
       }
else {
        spawn000(vName4,vx,vy,vz);
       }

}

void spawnRandomZAnim(void vName,int vx, int vy, int vz, void ani )
// Spawn entity at random places
// 24.09.2013 - Douglas Baldan - O Ilusionista
{
int Xr = rand()%vx;	// Random X pos
int Yr = rand()%vy;	// Random Y pos
int Zr = rand()%vz;	// Random Z pos
void    self   = getlocalvar("self");
spawn000(vName,Xr,Yr,Zr);
changeentityproperty(self, "animation", openborconstant(ani));
}


void refill(int iValue)
//Refill the MP bar witht the desired value.
//Douglas Baldan
{
    void self = getlocalvar("self");
	void Health = getentityproperty(self,"health"); //get mp
    changeentityproperty(self, "health", Health+iValue);
}

void mpadd(int iValue)
//Refill the MP bar witht the desired value.
//Douglas Baldan
{
    void self = getlocalvar("self");
	void MPower = getentityproperty(self,"mp"); //get mp
    changeentityproperty(self, "mp", MPower+iValue);
}
	
void mpcost( int MCost)
{// Spend some life
    void self = getlocalvar("self");
    void MPower = getentityproperty(self,"mp"); //get mp
    changeentityproperty(self, "mp", MPower-MCost);//consume mp
}

void reinforcement (int Enemies,void vName, float fX, float fY, float fZ, void Ani, float Vx, float Vy, float Vz)
{
    void self = getlocalvar("self");
    int Enemy = openborvariant("count_enemies");

    if(Enemy < Enemies){
	spawnAni(vName, fX, fY,fZ,Ani,Vx,Vy,Vz);
	}
}

void reinforcementCheck (int Enemies, void Ani)
{
// Check how much enemies are on the screen and if it less than the desired, change caller animation
// Douglas Baldan - 28/09/2016
    void self = getlocalvar("self");
    int Enemy = openborvariant("count_enemies");

    if(Enemy < Enemies){
	performattack(self, openborconstant(Ani));
	}
}

void reinforcementCheckCamera (int Enemies, void Ani, int iCamera)
{
// Check how much enemies are on the screen + camera check and if it less than the desired, change caller animation
// Douglas Baldan - 01/08/2017
    void self = getlocalvar("self");
    int Enemy = openborvariant("count_enemies");
    int XPos = openborvariant("xpos"); //Get screen edge's position

    if(Enemy < Enemies && XPos >=iCamera){
	performattack(self, openborconstant(Ani));
	}
}

void stealthMode (int sValue)
// sets the Stealth ability
// Douglas Baldan - 04/11/2013
// http://www.brazilmugenteam.com]www.brazilmugenteam.com
{
void self = getlocalvar("self");
changeentityproperty(self, "stealth", sValue);

}

void lifeCheck (int iLife, void Ani)
// Check the life and change the animation if the life is lower than given value
// Douglas Baldan - 04/01/2014
{
     void self = getlocalvar("self");
     void Health = getentityproperty(self,"health");

      if(Health<=iLife)
      {
        changeentityproperty(self, "animation", openborconstant(Ani));
      }
	  
}

void maxZ (int iZ)	
{
// controls the subject to Max Z
// Douglas Baldan/O Ilusionista
void self = getlocalvar("self");
int z = getentityproperty(self,"z"); //Get character's z coordinate
changeentityproperty(self, "subject_to_maxz", iZ);
}

void minZ (int iZ)	
{
// controls the subject to Min Z
// Douglas Baldan/O Ilusionista
void self = getlocalvar("self");
int z = getentityproperty(self,"z"); //Get character's z coordinate
changeentityproperty(self, "subject_to_minz", iZ);
}	

void gravity (int iG)
{
// controls the subject to gravity
// Douglas Baldan/O Ilusionista
void self = getlocalvar("self");
changeentityproperty(self,"subject_to_gravity",iG);
}

void subjectWall (int iG)
{
// controls the subject to Wall
// Douglas Baldan/O Ilusionista
void self = getlocalvar("self");
changeentityproperty(self,"subject_to_wall",iG);
}

void subjectScreen (int iG)
{
// controls the subject to screen
// Douglas Baldan/O Ilusionista
void self = getlocalvar("self");
changeentityproperty(self,"subject_to_screen",iG);
}

void noplayerJoin (int iG)
{
// controls if other players can join the game or not
// 1 - players CAN NOT join, 0 play CAN join
// remember to set it 0 when you are done, or you will have a 1P only game.
// Douglas Baldan/O Ilusionista - 20/09/14
changeopenborvariant("nojoin", iG);
}


void layer (int iG)
{
// Sets the entity layer
// Douglas Baldan/O Ilusionista
void self = getlocalvar("self");
changeentityproperty(self,"setlayer",iG);
}

void bmtFriction(float fX, float fY, float fZ)
{
// Reduces the actual velocity, simulating friction.
// Douglas Baldan - 13/01/2014
// http://www.brazilmugenteam.com
void self = getlocalvar("self");
float Xvel = getentityproperty(self, "xdir");// x velocity
float Yvel = getentityproperty(self, "tossv");// y velocity
float Zvel = getentityproperty(self, "zdir");// z velocity
changeentityproperty(self, "velocity", Xvel/fX, Yvel/fY, Zvel/fZ);
}

void randomAnim(int iLimit, int iChance, void Ani)
{
      void self = getlocalvar("self");
      int r = rand()%iLimit;

		if(r > iChance){
			performattack(self, openborconstant(Ani));
		}
}

void spawn000(void vName, float fX, float fY, float fZ)
{
	//spawn01 (Generic spawner) without direction
	//Damon Vaughn Caskey
	//07/06/2007 -- Modified by Douglas Baldan/O Ilusionista
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

      fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
      fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
      fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.
	
	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
    
	return vSpawn; //Return spawn.
}

void spawnAni(void vName, float fX, float fY, float fZ, void Ani, float Vx, float Vy, float Vz)
{
	//spawnB (Generic spawner) + Specific animation + velocities
	//Damon Vaughn Caskey + Douglas Baldan
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
    performattack(vSpawn, openborconstant(Ani)); 
	changeentityproperty(vSpawn, "velocity", Vx, Vy, Vz);

	return vSpawn; //Return spawn.
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


void scrollcam(float xoff, float zoff, float spd) {
  if( openborvariant("in_level") ) {
    changelevelproperty("cameraxoffset", xoff); //X offset for camera
    changelevelproperty("camerazoffset", zoff); //Z offset for camera
    changelevelproperty("scrollspeed", spd); //Scrolling camera speed
  }
}



void spawnTextAni(void vName, float fX, float fY, float fZ, void Ani, float Vx, float Vy, float Vz)
{
	//spawnB (Generic spawner) + Specific animation + velocities
	//Damon Vaughn Caskey + Douglas Baldan
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
    loadmodel(vName); // name of the entity to be loaded

	clearspawnentry(); //Clear current spawn entry.
    setspawnentry("name", vName); //Acquire spawn entity by name.
    //setspawnentry("coords", 1,1,1); // set the position of the entity

      fX = openborvariant("xpos")+fX; //Get X location and add adjustment.
      //fY = openborvariant("ypos"); //Get Y location and add adjustment.
      fZ = openborvariant("ypos")+fZ; //Get Z location and add adjustment.
      log(fX);
	
	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	//changeentityproperty(vSpawn, "direction", 1); //Set direction.
    performattack(vSpawn, openborconstant(Ani)); 
	//changeentityproperty(vSpawn, "velocity", Vx, Vy, Vz);

	return vSpawn; //Return spawn.
}


