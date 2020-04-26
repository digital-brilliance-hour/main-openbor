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

void mpcost( int MCost)
{// Spend some MP
    void self = getlocalvar("self");
    void MPower = getentityproperty(self,"mp"); //get mp
    changeentityproperty(self, "mp", MPower-MCost);//consume mp
}

void tosser(void Bomb, float dx, float dy, float dz, float Vx, float Vy, float Vz)
{ // Tossing bomb with desired speed
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   void Shot;

   if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
   }

   Shot = projectile(Bomb, x+dx, z+dz, y+dy, Direction, 0, 1, 0);
   tossentity(Shot, Vy, Vx, Vz);
   changeentityproperty(Shot, "speed", Vx); 
}

void block(int Flag)
{// Turns blocking status
    void self = getlocalvar("self");
    changeentityproperty(self, "aiflag", "blocking", Flag);
}

void move(int dx, int dz,int da)
{ // Moves entity freely and ignores obstacles
    void self = getlocalvar("self");
    int x = getentityproperty(self,"x"); //Get character's x coordinate
    int z = getentityproperty(self,"z"); //Get character's z coordinate
    int a = getentityproperty(self,"a"); //Get character's a coordinate
    int dir = getentityproperty(self,"direction"); //Get character's facing direction

     if(dir==0){ // Facing left?
      changeentityproperty(self, "position", x-dx, z+dz, a+da); //Move
     }
     else if(dir==1){ // Facing right?
      changeentityproperty(self, "position", x+dx, z+dz, a+da); //Move
     }
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

void mpcost( int Cost)
{// Spend some MP
    void self = getlocalvar("self");
    void MP = getentityproperty(self,"mp");

    changeentityproperty(self, "mp", MP-Cost); //Spend!
}

void limiter(int Limit)
{// Prevents hero from performing the animation if his/her MP is less than Limit
    void self = getlocalvar("self");
    void MP = getentityproperty(self,"mp"); //Get entity's MP.

   if(MP<=Limit) // Don't have enough MP?
   {
     setidle(self); //Don't play the animation.
   }
}

void clearL()
{// Clears all local variables
     clearlocalvar();
}

void keyint(void Ani, int Frame, void Key, int Hflag)
{// Change current animation if proper key is pressed or released
    void self = getlocalvar("self");
    int Dir = getentityproperty(self, "direction");   
    int iPIndex = getentityproperty(self,"playerindex"); //Get player index
    void iRKey;

      if (Key=="U"){ //Up Required?
        iRKey = playerkeys(iPIndex, 0, "moveup"); // "Up"
	} else if (Key=="D"){ //Down Required?
        iRKey = playerkeys(iPIndex, 0, "movedown"); // "Down"
	} else if (Key=="L"){ //Left Required?
        iRKey = playerkeys(iPIndex, 0, "moveleft"); // "Left"
	} else if (Key=="R"){ //Right Required?
        iRKey = playerkeys(iPIndex, 0, "moveright"); // "Right"
	} else if (Key=="F"){ //Forward Required?
          if (Dir == 0){ // Facing Left?
            iRKey = playerkeys(iPIndex, 0, "moveleft"); // "Left"
          } else { // Facing Right
            iRKey = playerkeys(iPIndex, 0, "moveright"); // "Right"
          }
        } else if (Key=="B"){ //Back Required?
          if (Dir == 1){ // Facing Right?
            iRKey = playerkeys(iPIndex, 0, "moveleft"); // "Left"
          } else { // Facing Left
            iRKey = playerkeys(iPIndex, 0, "moveright"); // "Right"
          }
        } else if (Key=="J"){ //Jump Required?
        iRKey = playerkeys(iPIndex, 0, "jump"); // "Jump"
	} else if (Key=="A"){ //Attack Required?
        iRKey = playerkeys(iPIndex, 0, "attack"); // "Attack"
	} else if (Key=="A2"){ //Attack2 Required?
        iRKey = playerkeys(iPIndex, 0, "attack2"); // "Attack2"
	} else if (Key=="S"){ //Special Required?
        iRKey = playerkeys(iPIndex, 0, "special"); // "Special"
	} else if (Key=="A3"){ //Attack4 Required?
        iRKey = playerkeys(iPIndex, 0, "attack3"); // "Attack3"
	} else if (Key=="A4"){
	iRKey = playerkeys(iPIndex, 0, "attack4"); // "Attack4"
	}

      if (Hflag==1){ //Not holding the button case?
        iRKey = !iRKey; //Take the opposite condition
	}

      if (iRKey){
//        performattack(self, openborconstant(Ani));
//        updateframe(self, Frame);
        changeentityproperty(self, "animation", openborconstant(Ani),2);
        changeentityproperty(self, "animpos", Frame);
      }
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

void shooter(void Shot, float dx, float dy, float dz, float Vx, float Vy, float Vz)
{ // Shooting projectile with speed control
   void vShot = shoot(Shot, dx, dy, dz);

   changeentityproperty(vShot, "velocity", Vx, Vz, Vy);
   changeentityproperty(vShot, "speed", Vx);
}

void keyshoot(void Shot, float dx, float dy, float dz, float Vx, float Vz)
{ // Shooting projectile with key based speed control
    void self = getlocalvar("self");
    int iPIndex = getentityproperty(self,"playerindex"); //Get player index
    void vShot = shoot(Shot, dx, dy, dz);

    if (playerkeys(iPIndex, 0, "moveup")){
      changeentityproperty(vShot, "velocity", Vx, -Vz);
    } else if (playerkeys(iPIndex, 0, "movedown")){
      changeentityproperty(vShot, "velocity", Vx, Vz);
    } else {
      changeentityproperty(vShot, "velocity", Vx, 0);
    }
    changeentityproperty(vShot, "speed", Vx);
}

void toss(void Bomb, float dx, float dy, float dz)
{ // Tossing bomb
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");

   if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
   }

   projectile(Bomb, x+dx, z+dz, y+dy, Direction, 0, 1, 0);
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
	//fY: Y location adjustment.
      //fZ: Z location adjustment.

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

void spawnbind(void Name, float dx, float dy, float dz, int iDir,int iBind)
{ // Spawn and bind other entity
   void self = getlocalvar("self");
   void Spawn;

   Spawn = spawn01(Name, dx, dy, 0);
   bindentity(Spawn, self, dx, dz, dy, iDir, iBind);
}

void shooter2(void Shot, float dx, float dy, float dz, float Vx, float Vy, float Vz)
{ // Shooting special projectile with speed control
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   void vShot;

   if (Direction == 0){ //Is entity facing left?                  
      Vx = -Vx; //Reverse Vx direction to match facing
   }

   vShot = spawn01(Shot, dx, dy, dz);
   changeentityproperty(vShot, "velocity", Vx, Vz, Vy);
   return vShot;
}

void keyfly(float V)
{// Move hero if direction button is pressed
      void self = getlocalvar("self");
      int iPIndex = getentityproperty(self,"playerindex"); //Get player index
      int a = getentityproperty(self,"a"); //Get player's altitude
   float xdir = 0;
   float ydir = 0;

      if (playerkeys(iPIndex, 0, "moveleft")){// Left is pressed?
     xdir = -V;
   } else if(playerkeys(iPIndex, 0, "moveright")){// Right is pressed?
     xdir = V;
      }

   if(playerkeys(iPIndex, 0, "moveup") && (a <= 360)){// Up is pressed?
     ydir = V;
   } else if(playerkeys(iPIndex, 0, "movedown") && (a >= 0)){// Down is pressed?
     ydir = -V;
      }

   changeentityproperty(self, "velocity", xdir, 0, ydir);
}

void degravity(int Ratio)
{// Changes antigravity effect
    void self = getlocalvar("self");
    changeentityproperty(self, "antigravity", Ratio);
}

void beidle()
{// Go to IDLE animation!
    void self = getlocalvar("self");

    setidle(self, openborconstant("ANI_IDLE"));
}

void target0(float Velx, float Vely, float Tx, float Ty, float dx, float dy, void Vel, int Flip)
{// Basic Targetting certain coordinate before dashing
// Velx = Desired x Velocity
// Vely = Desired y Velocity
// Tx = target x coordinate
// Ty = target y coordinate
// dx = x added distance
// dy = y added distance
// Vel = Desired output

    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction");
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    float Vx;
    float Vy;

    if(Flip == 1){
      if(Tx < x){
        changeentityproperty(self, "direction", 0);
      } else {
        changeentityproperty(self, "direction", 1);
      }
    }

    x = x+dx;
    y = y+dy;
    float Disx = Tx - x;
    float Disy = Ty - y;

//Set both distance as positive value
    if(Disx < 0){
      Disx = -Disx;
    }

    if(Disy < 0){
      Disy = -Disy;
    }

// Calculate velocity for targetting
    if(Disy < Disx)
    {
      if(Tx < x){
        Vx = -Velx;
      } else { Vx = Velx; }

      Vy = Velx*(Ty-y)/Disx;
    } else {
      if(Ty < y){
        Vy = -Vely;
      } else { Vy = Vely; }

      Vx = Vely*(Tx-x)/Disy;
    }

    if(Vel == "x"){
      return Vx;
    }
    if(Vel == "y"){
      return Vy;
    }
}

void target1(void Target, float Velx, float Vely, float dx, float dy, int Stop, void Vel, int Flip)
{// Targetting certain entity before dashing
// Target = Targetted entity
// Velx = Desired x Velocity
// Vely = Desired y Velocity
// dx = x added distance
// dy = y added distance
// Stop = flag to stop moving if there's no target

    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction");
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    float Vx;
    float Vy;

    if (dir == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
    }

    if( Target != NULL()){
      float Tx = getentityproperty(Target, "x");
      float Ty = getentityproperty(Target, "a");

      Vx = target0(Velx, Vely, Tx, Ty, dx, dy, "x", Flip);
      Vy = target0(Velx, Vely, Tx, Ty, dx, dy, "y", Flip);
    } else {
      if(Stop == 1)
      {
        Vy = 0;
        Vx = 0;
      } else {
        Vy = 0;
        if(dir==0){
          Vx = -Velx;
        } else { Vx = Velx; }
      }
    }

    if(Vel == "x"){
      return Vx;
    }
    if(Vel == "y"){
      return Vy;
    }
}

void target0T(float Time, float Tx, float Ty, float dx, float dy, void Vel, int Flip)
{// Basic Targetting certain coordinate before dashing
// Produced velocity will be required speed to get to target within specified time
// Time = specified time
// Tx = target x coordinate
// Ty = target y coordinate
// dx = x added distance
// dy = y added distance
// Vel = Desired output

    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction");
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    float Vx;
    float Vy;

    if(Flip == 1){
      if(Tx < x){
        changeentityproperty(self, "direction", 0);
      } else {
        changeentityproperty(self, "direction", 1);
      }
    }

    x = x+dx;
    y = y+dy;
// Calculate velocity for targetting

    Vx = (Tx-x)/Time;
    Vy = (Ty-y)/Time;

    if(Vel == "x"){
      return Vx;
    }
    if(Vel == "y"){
      return Vy;
    }
}

void target1T(void Target, float Time, float dx, float dy, void Vel, int Flip)
{// Targetting certain entity before dashing
// Produced velocity will be required speed to get to target within specified time
// Target = Targetted entity
// Time = Specified time
// dx = x added distance
// dy = y added distance

    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction");
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    float Vx;
    float Vy;

    if (dir == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
    }

    if( Target != NULL()){
      float Tx = getentityproperty(Target, "x");
      float Ty = getentityproperty(Target, "a");

      Vx = target0T(Time, Tx, Ty, dx, dy, "x", Flip);
      Vy = target0T(Time, Tx, Ty, dx, dy, "y", Flip);
    } else {
      Vy = 0;
      Vx = 0;
    }

    if(Vel == "x"){
      return Vx;
    }
    if(Vel == "y"){
      return Vy;
    }
}

void target(float Velx, float Vely, float dx, float dy, int Stop, int Flip)
{// Targetting opponent before leaping or dashing.
// Velx = x Velocity
// Vely = y Velocity
// dx = x added distance
// dy = y added distance
// Stop = flag to stop moving if no target is found

    void self = getlocalvar("self");

    setlocalvar("T"+self, findtarget(self)); //Get nearest player

    void target = getlocalvar("T"+self);
    setlocalvar("x"+self, target1(target, Velx, Vely, dx, dy, Stop, "x", Flip) );
    setlocalvar("y"+self, target1(target, Velx, Vely, dx, dy, Stop, "y", Flip) );
    setlocalvar("T"+self, NULL()); //Clears variable
}

void targetT(float Time, float dx, float dy, int Flip)
{// Targetting opponent before leaping or dashing.
// Time = specified time
// dx = x added distance
// dy = y added distance

    void self = getlocalvar("self");

    setlocalvar("T"+self, findtarget(self)); //Get nearest player

    void target = getlocalvar("T"+self);
    setlocalvar("x"+self, target1T(target, Time, dx, dy, "x", Flip) );
    setlocalvar("y"+self, target1T(target, Time, dx, dy, "y", Flip) );
    setlocalvar("T"+self, NULL()); //Clears variable
}

void targetB(float Time, float dx, float dy, int Flip)
{// Targetting opponent before tossing bomb
// Time = specified time
// dx = x added distance
// dy = y added distance
// Flip = flip flag

    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction");
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    float Vx;

    setlocalvar("T"+self, findtarget(self)); //Get nearest target
    void Target = getlocalvar("T"+self);

    if( Target != NULL()){
      float Tx = getentityproperty(Target, "x");
      float Ty = getentityproperty(Target, "a");
      float C;
      float Sy = y + dy - Ty;

      if (Sy < 0){ //Negative?
        Sy = -Sy; //Invert to positive
      }

      C = 0.5*(x-Tx)*(y+dy-Ty)/(Time+Sy);

      if (dir == 0){ //Is entity facing left?                  
        dx = -dx; //Reverse X direction to match facing
      }

      Vx = target0T(Time, Tx, Ty, dx-C, 0, "x", Flip);

    } else {
      Vx = 0;
    }

    setlocalvar("x"+self, Vx );
    setlocalvar("T"+self, NULL()); //Clears variable
}

void dash(int X, int Y)
{// Dash with previously attained speed!
    void self = getlocalvar("self");
    float Vx = getlocalvar("x"+self);
    float Vy = getlocalvar("y"+self);

    if( X==1 ){
      Vy = 0;
    } else if( Y==1 ){
      Vx = 0;
    }

    changeentityproperty(self, "velocity", Vx, 0, Vy);
}

void leap(float Vely)
{// Leap with previously attained speed!
    void self = getlocalvar("self");
    float Vx = getlocalvar("x"+self);
    if( Vx!=NULL() ){
      tossentity(self, Vely, Vx); //Leap towards target!
    }
}

void shoot2(void Shot, float dx, float dy)
{ // Shooting targetted projectile
   void self = getlocalvar("self");
   float Vx = getlocalvar("x"+self);
   float Vy = getlocalvar("y"+self);
   void vShot;

   if( Vx!=NULL() && Vy!=NULL() ){
     vShot = shooter2(Shot, dx, dy, Vx, Vy);
     changeentityproperty(vShot, "velocity", Vx, 0, 2*Vy); //Move projectile towards target!
   }
}

void toss2(void Shot, float dx, float dy, float Vy)
{ // Tossing targetted bombs
   void self = getlocalvar("self");
   float Vx = getlocalvar("x"+self);
   int Direction = getentityproperty(self, "direction");

   if (Direction == 0){ //Is entity facing left?                  
      Vx = -Vx; //Reverse Vx direction to match facing
   }

   if( Vx!=NULL() && Vy!=NULL() ){
     tosser2(Shot, dx, dy, Vx, Vy);
   }
}

void tosser2(void Bomb, float dx, float dy, float Vx, float Vy)
{ // Tossing special bomb with desired speed
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   void Shot;

   if (Direction == 0){ //Is entity facing left?                  
      Vx = -Vx; //Reverse Vx direction to match facing
   }

   Shot = spawn01(Bomb, dx, dy, 0);
   tossentity(Shot, Vy, Vx);
   changeentityproperty(Shot, "owner", self);
   return Shot;
}

void suicide()
{ // Suicide!!
    void self = getlocalvar("self");

    killentity(self); //Suicide!
}

void clearL()
{ // Clears all local variables
     clearlocalvar();
}

void bmtcenter()
{	 // centers the entity on the screen		
	 // O Ilusionista - 06/10/2014
        void self = getlocalvar("self"); //Get calling entity.
	 int Screen = openborvariant("hResolution")/2; // Get screen width divided by 2
        int XPos = openborvariant("xpos"); // Get camera x position
        int Width = openborvariant("PLAYER_MIN_Z")+(openborvariant("PLAYER_MAX_Z") - openborvariant("PLAYER_MIN_Z"))/2; // Get playable area size center
        changeentityproperty(self, "position", Screen+XPos, Width+1, 0);

}

void damage_all_enemies(int damage, int drop, void atk_type)
{
 	int  iEntity; 
        void vEntity;
        void self        = getlocalvar("self");
        int  iMax        = openborvariant("count_entities");   

        for(iEntity=0; iEntity<iMax; iEntity++)
        {
        vEntity = getentity(iEntity);
		float x = getentityproperty(vEntity, "x") - openborvariant("xpos");
		float a = getentityproperty(vEntity, "a");
		float z = getentityproperty(vEntity, "z");
		void Spawn;
		if(getentityproperty(vEntity, "type")==openborconstant("TYPE_enemy"))
		{
		
		clearspawnentry();
        setspawnentry("name", "flash");
        setspawnentry("coords", x, z+1, a+30);
        spawn();
        clearspawnentry();
		damageentity(vEntity,self,damage,drop,openborconstant(atk_type));
		
		}
	}
}

void attack0(void Ani)
{// Attack interruption
    void self = getlocalvar("self");

    performattack(self, openborconstant(Ani)); //Attack!
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
      updateframe(self, Frame); //Change frame
      setlocalvar("Loop" + self, loop+1); // Increment number of loops
    } else if(loop==Limit){ // loops reach limit?
      setlocalvar("Loop" + self, NULL());
    }
}

void flip()
{// Flip to opposite direction
    void self = getlocalvar("self");
    int dir = getentityproperty(self,"direction");

    if(dir==0){ // Facing left?
      changeentityproperty(self, "direction", 1);
    } else {
      changeentityproperty(self, "direction", 0);
    }
}

void randSound(char s1,char s2,char s3)
{
   int r = rand()%300;
   char sound;
   if (r<=-100)
   {
      sound=s1;
   }else if(r<=100){
      sound=s2;
   }else{
      sound=s3;
   }
   playSound("data/sounds/"+sound);
}
void randSound2(char s1,char s2,char s3,char s4,char s5,char s6)
{
   int      r      =   rand()%300+300;
   char   sound   =   "";

   if (r<100){
      sound=s1;
   }else if(r<200){
      sound=s2;
   }else if(r<300){
      sound=s3;
   }else if(r<400){
      sound=s4;
   }else if(r<500){
      sound=s5;
   }else if(r<600){
      sound=s6;
   }
   playSound("data/sounds/"+sound);
}
void playSound(void file)
{
   if(!file||file==""){return;}else{}
   int sfx=loadsample(file);
   playsample(sfx, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
}
