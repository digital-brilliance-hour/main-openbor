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
        int XPos = openborvariant("xpos"); //Get screen edge's position

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

      fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.

	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX + XPos, fZ, fY); //Set spawn location.
	return vSpawn; //Return spawn.
}

void shooter2(void vName, float fX, float fY, float fZ, float Vx, float Vy, float Vz)
{//Spawns projectile next to caller
 //vName: Model name of entity to be spawned in
 //fX: X location adjustment
 //fZ: Y location adjustment
 //fY: Z location adjustment
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
   changeentityproperty(vSpawn, "speed", Vx);
   changeentityproperty(vSpawn, "owner", self);
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

   if (Direction == 0){ //Is entity facing left?                  
      Vx = -Vx; //Reverse Vx direction to match facing
   }

   vShot = shoot(Shot, dx, dy, dz);
   changeentityproperty(vShot, "velocity", Vx, Vz, Vy);
//   changeentityproperty(vShot, "speed", Vx);
   if (Vx < 0 && Direction == 1){ //Is projectile moving back?
     changeentityproperty(vShot, "direction", 0);
   } else if(Vx > 0 && Direction == 0){ //Is projectile moving back?
     changeentityproperty(vShot, "direction", 1);
   }
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

void shooter2X(void vName, float fX, float fY, float fZ, float Vx, float Vy, float Vz)
{//Spawns projectile next to caller
 //vName: Model name of entity to be spawned in
 //fX: X location adjustment
 //fZ: Y location adjustment
 //fY: Z location adjustment
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
}

void spawnA(void vName, float fX, float fY, float fZ, char Alias)
{//Spawns entity next to caller
 //vName: Model name of entity to be spawned in
 //fX: X location adjustment
 //fZ: Y location adjustment
 //fY: Z location adjustment
 //Alias: Name/alias of the spawned entity

   void self = getlocalvar("self"); //Get calling entity
   void vSpawn; //Spawn object.
	
   vSpawn = spawn01(vName, fX, fY, fZ);
   changeentityproperty(vSpawn, "name", Alias);
}
