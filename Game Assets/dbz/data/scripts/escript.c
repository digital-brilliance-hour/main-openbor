void shoot(void shot, float dx, float dy, float dz)
{ // Shooting projectile
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");

   if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; ////Reverse X direction to match facing
   }

   projectile(shot, x+dx, z+dz, y+dy, Direction, 0, 0);
}

void toss(void Bomb, float dx, float dy, float dz)
{ // Tossing bomb
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");

   if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; ////Reverse X direction to match facing
   }

   projectile(Bomb, x+dx, z+dz, y+dy, Direction, 0, 1);
}

void flipdir()
{
    void self = getlocalvar("self");
    changeentityproperty(self, "direction", !getentityproperty(self, "direction"));
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
          fX = -fX; ////Reverse X direction to match facing.
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
{   //Spawns entity next to caller and give same remap to it.
   //
   //vName: Model name of entity to be spawned in.
   //fX: X location adjustment.
   //fZ: Y location adjustment.
      //fY: Z location adjustment.

   void self = getlocalvar("self"); //Get calling entity.
   void map = getentityproperty(self, "map");
   void vSpawn; //Spawn object.
   
   vSpawn = spawn01(vName, fX, fY, fZ); //Spawn in entity.

   changeentityproperty(vSpawn, "map", map); //Give spawned entity same remap
    
   return vSpawn; //Return spawn.
}

void spawnbind(void Name, float dx, float dy, float dz, int Dir, int Flag)
{ // Spawn entity and bind it
   void self = getlocalvar("self");
   void Spawn;

   Spawn = spawn01(Name, dx, dy, dz);
   bindentity(Spawn, self, dx, dz, dy, Dir, Flag);
}

void Rspawn(float fX, float fY, float fZ)
{
	//Spawns entity next to caller.
	//
	//fX: X location adjustment.
	//fZ: Y location adjustment.
      //fY: Z location adjustment.

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	void vName; //Spawn object's name.
      void vRName = getentityproperty(self,"defaultname"); // Get caller's real name.
      void vAlias = getentityproperty(self,"name"); // Get caller's alias.
      int  iMHealth = getentityproperty(self,"maxhealth"); // Get caller's maximum health.
      int  iHealth = getentityproperty(self,"health"); // Get caller's health.
	int  iDirection = getentityproperty(self, "direction"); // Get caller's direction.
	int  iMap = getentityproperty(self, "map"); // Get caller's remap.
      int  iR = rand()%20 + 20;

	if (iR >= 0 && iR < 8){ 
        vName = "footsw";
      } else if (iR >= 8 && iR < 16){ 
        vName = "bigmouse";
      } else if (iR >= 16 && iR < 24){ 
        vName = "foot4a";
      } else if (iR >= 24 && iR < 32){ 
        vName = "robot";
      } else { 
        vName = "footaxe";
      }

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

	if (iDirection == 0){ //Is entity facing left?                  
          fX = -fX; ////Reverse X direction to match facing.
	}

      fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
      fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
      fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.
	
	vSpawn = spawn(); //Spawn in entity.

	if (vAlias == vRName){ // If this entity doesn't have alias, it will use spawned entity's name.
        vAlias = vName;
      }

	if (vAlias == "punk"){ // If Garcia is spawned, his alias will be adjusted to his remap
	  if (iMap == 1){
          vAlias = "Joseph";
        } else if (iMap == 2){
          vAlias = "Brash";
        } else if (iMap == 3){
          vAlias = "B.T";
        } else if (iMap == 4){
          vAlias = "Surger";
        } else if (iMap == 5){
          vAlias = "Jonathan";
        } else if (iMap == 6){
          vAlias = "Julio";
        }
      } else if (vAlias == "rot"){ // If Ray is spawned, his alias will be adjusted to his remap
        if (iMap == 1 || iMap == 4){
          vAlias = "J";
        } else if (iMap == 2 || iMap == 5){
          vAlias = "Bred";
        } else if (iMap == 3 || iMap == 6){
          vAlias = "Zack";
        }
      } else if (vAlias == "heel"){ // If Lesus is spawned, his alias will be adjusted to his remap
	  if (iMap == 1){
          vAlias = "Frost";
        } else if (iMap == 2){
          vAlias = "Hail";
        } else if (iMap == 3){
          vAlias = "Tempest";
        } else if (iMap == 4){
          vAlias = "Rain";
        } else if (iMap == 5){
          vAlias = "Calm";
        } else if (iMap == 6){
          vAlias = "Tornado";
        }
      }

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "name", vAlias); //Set alias.
	changeentityproperty(vSpawn, "map", iMap); //Set map.
	changeentityproperty(vSpawn, "maxhealth", iMHealth); //Set maximum health.
	changeentityproperty(vSpawn, "health", iHealth); //Set health.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.

	return vSpawn; //Return spawn.
}

void velo001(float fX, float fZ, float fY){
     
    //velo001
	//Damon Vaughn Caskey
	//05/06/2007
	//
	//Replicates movement effect.
	//
	//fX: X axis speed.
	//fZ: Z axis speed.
	//fY: Y axis speed.
	
	void vSelf = getlocalvar("self"); //Get calling entity.
	
	if (getentityproperty(vSelf, "direction")==0)
        {                  
           fX = -fX; ////Reverse X direction to match facing.
        }        
           changeentityproperty(vSelf, "velocity", fX, fZ, fY); //Apply movement. 

}

void change_candamage(char typeSeq){
	int byte = getTypeByte(typeSeq);
	changeentityproperty(getlocalvar("self"), "candamage", byte);
}

int getTypeByte(char typeSeq){
	void fullStr = typeSeq;
	void remainder = strinfirst(fullStr, " ");
	void currentParam;
	int type = 0;
	while(remainder != NULL() && remainder != "" && remainder != -1){
		int pos = strlength(fullStr) - strlength(remainder);
		currentParam = strleft(fullStr, pos);
		
		type += typeFromString(currentParam);

		fullStr = strright(remainder, 1);
		remainder = strinfirst(fullStr, " ");
	}
	return type;
}

int typeFromString(char typeSeq){
	switch(typeSeq){
		case "all":
			return openborconstant("TYPE_PLAYER") + openborconstant("TYPE_NPC") + openborconstant("TYPE_ENEMY") + openborconstant("TYPE_OBSTACLE");
		case "pl":
		case "player:"
			return openborconstant("TYPE_PLAYER");
			break;
		case "npc":
			return openborconstant("TYPE_NPC");
			break;
		case "en":
		case "enemy":
			return openborconstant("TYPE_ENEMY");
			break;
		case "pl|npc":
			return openborconstant("TYPE_PLAYER") + openborconstant("TYPE_NPC");
			break;
		case "obstacle":
			return openborconstant("TYPE_OBSTACLE");
		default:
			return 0;
	}
}
