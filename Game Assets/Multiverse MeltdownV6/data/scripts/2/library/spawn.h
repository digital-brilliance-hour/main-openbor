//Library scripts for spawning

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

void spawn02(void vName, float fX, float fY, float fZ)
{
	//Spawns entity based on left screen edge
	//
	//vName: Model name of entity to be spawned in.
	//fX: X distance relative to left edge
	//fY: Y height from ground
      //fZ: Z location adjustment

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int Direction = getentityproperty(self, "direction");
        int XPos = openborvariant("xpos"); //Get screen edge's position
        int Screen = openborvariant("hResolution"); // Get screen width

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

   if (Direction == 0){ //Is entity facing left?                  
      fX = Screen-fX; //Reverse X direction to match facing and screen length
   }

      fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.

	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX + XPos, fZ, fY); //Set spawn location.
	return vSpawn; //Return spawn.
}

void spawn03(void vName, float fX, float fY, float fZ, int iDir)
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

	if (iDir == 1){  
	  changeentityproperty(vSpawn, "direction", iDirection); //Set direction
        } else if (iDir == -1){  
	  if (iDirection == 0){ 
	    changeentityproperty(vSpawn, "direction", 1); //Set direction
          } else {
	    changeentityproperty(vSpawn, "direction", 0); //Set direction
          }
        }
    
	return vSpawn; //Return spawn.
}

void spawn04(void vName, float fX, float fY, float fZ)
{
	//Spawns entity based on left screen edge and center of playing field
	//
	//vName: Model name of entity to be spawned in.
	//fX: X distance relative to left edge
	//fY: Y height from ground
      //fZ: Z location adjustment

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int Direction = getentityproperty(self, "direction");
        int XPos = openborvariant("xpos"); //Get screen edge's position
        int Screen = openborvariant("hResolution"); // Get screen width

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

   if (Direction == 0){ //Is entity facing left?                  
      fX = Screen-fX; //Reverse X direction to match facing and screen length
   }

      fZ = fZ+(openborvariant("PLAYER_MIN_Z") + openborvariant("PLAYER_MAX_Z") )/2 ;

	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX + XPos, fZ, fY); //Set spawn location.
	return vSpawn; //Return spawn.
}

void spawn05(void vName, float fX, float fY, float fZ)
{
	//Spawns entity based on left screen edge and z axis
	//
	//vName: Model name of entity to be spawned in.
	//fX: X distance relative to left edge
	//fY: Y height from ground
      //fZ: Z coordinate

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int Direction = getentityproperty(self, "direction");
        int XPos = openborvariant("xpos"); //Get screen edge's position
        int Screen = openborvariant("hResolution"); // Get screen width

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

   if (Direction == 0){ //Is entity facing left?                  
      fX = Screen-fX; //Reverse X direction to match facing and screen length
   }

	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX + XPos, fZ, fY); //Set spawn location.
	return vSpawn; //Return spawn
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

void shooter2(void vName, float fX, float fY, float fZ, float Vx, float Vy, float Vz)
{//Spawns projectile next to caller and move it with speed
 //vName: Model name of entity to be spawned in
 //fX: X location adjustment
 //fY: Y location adjustment
 //fZ: Z location adjustment
 //Vx: X speed
 //Vy: Y speed
 //Vz: Z speed

   void self = getlocalvar("self"); //Get calling entity
   int Direction = getentityproperty(self, "direction");
   void vSpawn; //Spawn object.
	
   vSpawn = spawn01(vName, fX, fY, fZ); //Spawn in projectile
   if (Direction == 0){ //Is entity facing left?                  
      Vx = -Vx; //Reverse Vx direction to match facing
   }

   changeentityproperty(vSpawn, "velocity", Vx, Vz, Vy);
//   changeentityproperty(vSpawn, "speed", Vx);
//   changeentityproperty(vSpawn, "owner", self);
   return vSpawn;
}

void shooter3(void vName, float fX, float fY, float fZ, float Vx, float Vy, float Vz, int Dir)
{//Spawns projectile next to caller and move it with speed
 //vName: Model name of entity to be spawned in
 //fX: X location adjustment
 //fY: Y location adjustment
 //fZ: Z location adjustment
 //Vx: X speed
 //Vy: Y speed
 //Vz: Z speed
 //Dir: Direction adjustment

   void self = getlocalvar("self"); //Get calling entity
   int Direction = getentityproperty(self, "direction");
   void vSpawn; //Spawn object.
	
   vSpawn = spawn01(vName, fX, fY, fZ); //Spawn in projectile
   if(Direction == 0){ //Is entity facing left?                  
      Vx = -Vx; //Reverse Vx direction to match facing
   }

   changeentityproperty(vSpawn, "velocity", Vx, Vz, Vy);

   if(Dir == 1){  
     changeentityproperty(vSpawn, "direction", Direction); //Set direction
   } else if(Dir == -1){  
     if(Direction == 0){ 
       changeentityproperty(vSpawn, "direction", 1); //Set direction
     } else {
       changeentityproperty(vSpawn, "direction", 0); //Set direction
     }
   }    
}

void shooter4(void vName, float fX, float fY, float fZ, float Vx, float Vy, float Vz, int Edge)
{//Spawns projectile relative to screen edge and move it with speed
 //vName: Model name of entity to be spawned in
 //fX: X location relative to screen edge
 //fY: Y location relative to ground
 //fZ: Z location relative to center of playing field
 //Vx: X speed
 //Vy: Y speed
 //Vz: Z speed

   void self = getlocalvar("self"); //Get calling entity
   int Direction = getentityproperty(self, "direction");
   void vSpawn; //Spawn object.
	
   vSpawn = spawn04(vName, fX, fY, fZ, Edge); //Spawn in projectile
   if (Direction == 0){ //Is entity facing left?                  
      Vx = -Vx; //Reverse Vx direction to match facing
   }

   changeentityproperty(vSpawn, "velocity", Vx, Vz, Vy);
   changeentityproperty(vSpawn, "direction", Direction);
//   changeentityproperty(vSpawn, "speed", Vx);
//   changeentityproperty(vSpawn, "owner", self);
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
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   void vShot;
   int Dx = Vx;

   if (Direction == 0){ //Is entity facing left?                  
      Dx = -Dx; //Reverse Dx direction to match facing
   }

   vShot = shoot(Shot, dx, dy, dz);
   changeentityproperty(vShot, "velocity", Dx, Vz, Vy);
   changeentityproperty(vShot, "speed", Vx);
/*   if (Vx < 0 && Direction == 1){ //Is projectile moving back?
     changeentityproperty(vShot, "direction", 0);
   } else if(Vx > 0 && Direction == 0){ //Is projectile moving back?
     changeentityproperty(vShot, "direction", 1);
   }*/
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

void spawnM(void Name, float dx, float dy, float dz)
{ // Spawn certain entity and matches its map with own's map
   void self = getlocalvar("self");
   int map = getentityproperty(self,"map");
   void Spawn;

   Spawn = spawn01(Name, dx, dy, dz);
   changeentityproperty(Spawn, "map", map);
}

void spawner(void Name, float dx, float dy, float dz)
{ // Spawn certain entity and set self as its parent
   void self = getlocalvar("self");
   void Spawn;

   Spawn = spawn01(Name, dx, dy, dz);
   changeentityproperty(Spawn, "parent", self);
}

void spawnA(void vName, float fX, float fY, float fZ, char Alias)
{//Spawns entity next to caller with defined name
 //vName: Model name of entity to be spawned in
 //fX: X location adjustment
 //fY: Y location adjustment
 //fZ: Z location adjustment
 //Alias: Name/alias of the spawned entity
   void vSpawn; //Spawn object.
	
   vSpawn = spawn01(vName, fX, fY, fZ);
   changeentityproperty(vSpawn, "name", Alias);
}

void spawnXT(void vName, float fX, float fY, float fZ, void Code, int Value)
{//Spawns entity with spawn06 only if defined global variable is not set
 //vName: Model name of entity to be spawned in
 //fX: X location adjustment
 //fY: Y location adjustment
 //fZ: Z location adjustment
 //Code: Global variable to check
 //Value: Value to compare
    int K = getglobalvar(Code);

    if(K!=Value){
      spawn06(vName, fX, fY, fZ);
      setglobalvar(Code, Value);
    }
}

void spawnBind(void Name, float dx, float dy, float dz, int Dir, int Flag)
{ // Spawn entity and bind it
   void self = getlocalvar("self");
   void Spawn;

   Spawn = spawn01(Name, dx, dy, dz);
   bindentity(Spawn, self, dx, dz, dy, Dir, Flag);
}

void spawnBind2(void Name, float dx, float dy, float dz, int Dir, int Flag, int Num)
{ // Spawn entity, bind it and store each other
   void self = getlocalvar("self");
   void Spawn;

   Spawn = spawn01(Name, dx, dy, dz);
   bindentity(Spawn, self, dx, dz, dy, Dir, Flag);
   setentityvar(self, Num, Spawn);
   setentityvar(Spawn, Num, self);

   return Spawn; //Return spawn
}

void spawnChild(void Name, float dx, float dy, float dz, int Dir, int Flag, int Num)
{ // Spawn entity and store each other
   void self = getlocalvar("self");
   int x = getentityproperty(self, "x");
   void Spawn;

   Spawn = spawn01(Name, dx, dy, dz);
   changeentityproperty(Spawn, "direction", Dir);

   if(Flag==1){
     changeentityproperty(Spawn, "position", x+dx);     
   }

   setentityvar(self, Num, Spawn);
   setentityvar(Spawn, Num, self);

   return Spawn; //Return spawn
}

void Rspawn4(void vName, float fX, float fY, float fZ, float Vx, float Vz)
{//Spawns other entity in random spot relative to screen edge and move it with random speed
 //vName: Model name of entity to be spawned in
 //fX: X deviation relative to screen edge
 //fY: Starting altitude
 //fZ: Z deviation relative from center of playing field
 //Vx: X speed deviation
 //Vz: Z speed deviation

   void self = getlocalvar("self"); //Get calling entity
   int Direction = getentityproperty(self, "direction");
   int Screen = openborvariant("hResolution"); // Get screen width
   void vSpawn; int iDX; int iDZ; float iVX; float iVZ;

   if(fX!=0){
     iDX = rand()%fX+Screen*0.5;
   } else {
     iDX = 0;
   }

   if(fZ!=0){
     iDZ = rand()%fZ;
   } else {
     iDZ = 0;
   }

   if(Vx!=0){
     iVX = rand()%(10*Vx)*0.1;
   } else {
     iVX = 0;
   }

   if(Vz!=0){
     iVZ = rand()%(10*Vz)*0.1;
   } else {
     iVZ = 0;
   }

   vSpawn = spawn04(vName, iDX, fY, iDZ, Screen); //Spawn in entity
   changeentityproperty(vSpawn, "velocity", iVX, iVZ);
   changeentityproperty(vSpawn, "direction", Direction);
}

void Rain(void vName, float fX, float fY, float fZ, float Sx, float Vx, float Vy)
{//Spawns other entity in random spot relative to screen edge and move it with random speed
 //vName: Model name of entity to be spawned in
 //fX: X deviation relative to screen edge
 //fY: Starting altitude
 //fZ: Z deviation relative from center of playing field
 //Vx: X speed
 //Vy: Y speed

   void self = getlocalvar("self"); //Get calling entity
   int Direction = getentityproperty(self, "direction");
   int Screen = openborvariant("hResolution"); // Get screen width
   void vSpawn; int iDX; int iDZ;

   if(Direction == 0){ //Is entity facing left?                  
      Vx = -Vx; //Reverse Vx direction to match facing  
   }

   if(fX!=0){
     iDX = rand()%fX+Screen*0.5;
   } else {
     iDX = 0;
   }

   if(fZ!=0){
     iDZ = rand()%fZ;
   } else {
     iDZ = 0;
   }

   vSpawn = spawn04(vName, iDX+Sx, fY, iDZ, Screen); //Spawn in entity
   changeentityproperty(vSpawn, "velocity", Vx, 0, Vy);
   changeentityproperty(vSpawn, "direction", Direction);
}

void Rspawn1(void vName, float fX, float fY, float fZ, float Rx, float Rz, float Vx, float Vy, float Vz)
{//Spawns other entity in random spot relative to screen edge and move it with random speed
 //vName: Model name of entity to be spawned in
 //fX: X deviation relative to screen edge
 //fZ: Z deviation relative to center of playing field
 //Rx: Maximum x deviation
 //Rz: Maximum z deviation
 //Vx: X speed
 //Vz: Z speed

   void self = getlocalvar("self"); //Get calling entity
   int Direction = getentityproperty(self, "direction");
   int Screen = openborvariant("hResolution"); // Get screen width
   void vSpawn; int iDX; int iDZ;

   if(Rx!=0){
     iDX = rand()%Rx+fX;
   } else {
     iDX = 0;
   }

   if(Rz!=0){
     iDZ = rand()%Rz+fZ;
   } else {
     iDZ = 0;
   }

   if(Direction==0){
     Vx = -Vx;
   }

   vSpawn = spawn04(vName, iDX, fY, iDZ, Screen); //Spawn in entity
   changeentityproperty(vSpawn, "velocity", Vx, Vz, Vy);
   changeentityproperty(vSpawn, "direction", Direction);

   return vSpawn; //Return spawn
}
