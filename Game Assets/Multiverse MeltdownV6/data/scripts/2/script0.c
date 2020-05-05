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

void clearL()
{// Clears all local variables
     clearlocalvar();
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

      if (Hflag==1){ //Not holding the button case?
        iRKey = !iRKey; //Take the opposite condition
	}

      if ((Health > Limit)&&iRKey){
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

   if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
   }

   projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
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
	changeentityproperty(opp, "animation", openborconstant(anim));
}

void throw(int Damage, int Type, int x, int y, int z, int Face)
{ // Damage as throw finisher
   void self = getlocalvar("self");
   void target = getentityproperty(self, "opponent");

   if(target!=NULL())
   {
     int SDir = getentityproperty(target,"direction"); //Get opponent's facing direction
     int MDir;

     if(Face==0){ // Same facing?
         MDir = SDir;
     } else if(Face==1){ // Opposite facing?

       if(SDir==0){ // Facing left?
         MDir = 1;
       } else { MDir = 0;}
     }

     if(SDir==0){ // Facing left?
       x = -x;
     }

     if(Type==1)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL")); // 1st throw type
     } else if(Type==2)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL2")); // 2nd throw type
     }

     changeentityproperty(target, "attacking", 1);
     changeentityproperty(target, "damage_on_landing", Damage);
     changeentityproperty(target, "projectile", 1);
     changeentityproperty(target, "direction", MDir);
     tossentity(target, y, x, z); // Toss opponent ;)
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
