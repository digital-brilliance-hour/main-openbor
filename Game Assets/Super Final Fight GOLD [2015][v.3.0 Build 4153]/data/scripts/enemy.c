
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

void keyint(void Ani, int Frame, void Key, int Hflag, int Limit)
{// Change current animation if proper key is pressed or released provided MP is more than limit

    void self = getlocalvar("self");
    void Health = getentityproperty(self,"health");
    void MP = getentityproperty(self,"mp");
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

        if (Key=="A3"){ //Attack3 Required?
          iRKey = playerkeys(iPIndex, 0, "attack3"); // "Attack3"
	}

        if (Key=="A4"){ //Attack4 Required?
          iRKey = playerkeys(iPIndex, 0, "attack4"); // "Attack4"
	}

        if (Hflag==1){ //Not holding the button case?
          iRKey = !iRKey; //Take the opposite condition
	}

      if ((MP > Limit) && iRKey){
        changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
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

void spawn02(void vName, float fX, float fY, float fZ)
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
