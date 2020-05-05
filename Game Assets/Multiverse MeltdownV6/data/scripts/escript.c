
void changemap(int iMap)
{// Change remap
    void self = getlocalvar("self");

    changeentityproperty(self, "map", iMap); //Change remap
}

void clearL()
{ // Clears all local variables
     clearlocalvar();
}

void nograb(int Flag)
{// Turns grabbable status
    void self = getlocalvar("self");
    changeentityproperty(self, "nograb", Flag);
}

void platform(int Flag)
{// Turns subject to platform status
    void self = getlocalvar("self");
    changeentityproperty(self, "Subject_to_Platform", Flag);
}

void block(int Flag)
{// Turns blocking status
    void self = getlocalvar("self");
    changeentityproperty(self, "aiflag", "blocking", Flag);
}

void anichange(void Ani)
{ // Animation changer
    void self = getlocalvar("self");

    changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
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
    }
}

void degravity(int Ratio)
{// Changes antigravity effect
    void self = getlocalvar("self");
    changeentityproperty(self, "antigravity", Ratio);
}

void clearL()
{ // Clears all local variables
     clearlocalvar();
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

void spawner2(void vName, float fX, float fY, float fZ)
{//Spawns entity next to caller with same remap as spawner's.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
      //fY: Z location adjustment.

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iMap = getentityproperty(self, "map");
	
	vSpawn = spawn01(vName, fX, fY, fZ); //Spawn in entity.

	changeentityproperty(vSpawn, "map", iMap); //Use same remap as spawner's.
    
	return vSpawn; //Return spawn.
}

void shoot(void Shot, float dx, float dy, float dz)
{ // Shooting projectile
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");

   if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
   }

   projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
}

void shooter(void Shot, float dx, float dy, float dz, float Vx, float Vy, float Vz)
{ // Shooting projectile with speed control
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   void vShot;

   if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
   }

   vShot = projectile(Shot, x+dx, z+dz, y+dy, Direction, 1, 0, 0);
   changeentityproperty(vShot, "velocity", Vx, Vz, Vy);
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

void leap(float Vely)
{// Leap with previously attained speed!
    void self = getlocalvar("self");
    float Vx = getlocalvar("x"+self);
    float Vz = getlocalvar("z"+self);
    if( Vx!=NULL() && Vz!=NULL() ){
      tossentity(self, Vely, Vx, Vz); //Leap towards target!
    }
}

void shootD(void vName, float fX, float fY, float fZ, float Vx, float Vy, float Vz)
{//Spawns projectile next to caller. Used for shooting diving projectiles.
 //vName: Model name of entity to be spawned in.
 //fX: X location adjustment.
 //fZ: Y location adjustment.
 //fY: Z location adjustment.
 //Vx: X speed.
 //Vy: Dive speed.
 //Vz: Z speed.

   void self = getlocalvar("self"); //Get calling entity.
   int Direction = getentityproperty(self, "direction");
   void vSpawn; //Spawn object.
	
   vSpawn = spawn01(vName, fX, fY, fZ); //Spawn in projectile.
   if (Direction == 0){ //Is entity facing left?                  
      Vx = -Vx; //Reverse Vx direction to match facing
   }

   changeentityproperty(vSpawn, "velocity", Vx, Vz, Vy);
   changeentityproperty(vSpawn, "speed", Vx);

   return vSpawn; //Return spawn.
}

void stop()
{// Stop enemy's movement!
    void self = getlocalvar("self");
    changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
}

void attack1(int RxMin, int RxMax, int RyMin, int RyMax, void Ani)
{// Attack interruption with range check
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    int dir = getentityproperty(self, "direction");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Ty = getentityproperty(target, "a");
      float Disx = Tx - x;
      float Disy = Ty - y;

      if( Disx >= RxMin && Disx <= RxMax && Disy >= RyMin && Disy <= RyMax && dir == 1) // Target within range on right facing?
      {
        performattack(self, openborconstant(Ani)); //Change the animation
      } else if( Disx >= -RxMax && Disx <= -RxMin && Disy >= RyMin && Disy <= RyMax && dir == 0) // Target within range on left facing?
      {
        performattack(self, openborconstant(Ani)); //Change the animation
      }
    }
}

void target0(float Velx, float Vely, float Tx, float Ty, float dx, float dy, void Vel)
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

    if(Tx < x){
      changeentityproperty(self, "direction", 0);
    } else {
      changeentityproperty(self, "direction", 1);
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

void target1(void Target, float Velx, float Vely, float dx, float dy, int Stop, void Vel)
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

      Vx = target0(Velx, Vely, Tx, Ty, dx, dy, "x");
      Vy = target0(Velx, Vely, Tx, Ty, dx, dy, "y");
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

void target(float Velx, float Vely, float dx, float dy, int Stop)
{// Targetting opponent before leaping or dashing.
// Velx = x Velocity
// Vely = y Velocity
// dx = x added distance
// dy = y added distance
// Stop = flag to stop moving if no target is found

    void self = getlocalvar("self");

    setlocalvar("T"+self, findtarget(self)); //Get nearest player

    void target = getlocalvar("T"+self);
    setlocalvar("x"+self, target1(target, Velx, Vely, dx, dy, Stop, "x") );
    setlocalvar("y"+self, target1(target, Velx, Vely, dx, dy, Stop, "y") );
    setlocalvar("T"+self, NULL()); //Clears variable
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

    setlocalvar("T"+self, NULL()); //Clears variable
}

void dash()
{// Dash with previously attained speed!
    void self = getlocalvar("self");
    float Vx = getlocalvar("x"+self);
    float Vy = getlocalvar("y"+self);
    if( Vx!=NULL() && Vy!=NULL() ){
      changeentityproperty(self, "velocity", Vx, 0, Vy); //Move towards target!
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

void shooter2(void Shot, float dx, float dy, float Vx, float Vy)
{ // Shooting special projectile with speed control
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   void vShot;

   if (Direction == 0){ //Is entity facing left?                  
      Vx = -Vx; //Reverse Vx direction to match facing
   }

   vShot = spawn01(Shot, dx, dy, 0);
   changeentityproperty(vShot, "velocity", Vx, 0, Vy);

   return vShot;
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
