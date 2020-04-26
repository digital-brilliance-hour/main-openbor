void choose(float fX, float fY, float fZ)
{//Spawns random enemy next to caller.
//
//fX: X location adjustment.
//fZ: Y location adjustment.
//fY: Z location adjustment.

   void self = getlocalvar("self"); //Get calling entity.
   void vSpawn; //Spawn object.
   void vName; //Spawn object's name.
      void vRName = getentityproperty(self,"defaultname"); // Get caller's real name.
      void vAlias = getentityproperty(self,"name"); // Get caller's alias.
      void Health = getentityproperty(self,"health"); // Get caller's health.
   int  iDirection = getentityproperty(self, "direction"); // Get caller's direction.
   int  iMap = getentityproperty(self, "map"); // Get caller's remap.
	char npc = getglobalvar("npc");

   	if (npc == "Juggernaut2") { 
        vName = "Juggernaut2";
	} else if (npc == "Cable2") { 
        vName = "Cable2";
	} else if (npc == "Sentinel2") { 
        vName = "Sentinel2";
	} else if (npc == "Akuma2") { 
        vName = "Akuma2";
	} else { 
        vName = "nothing";
      	} 

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
   changeentityproperty(vSpawn, "map", iMap); //Set map.
   changeentityproperty(vSpawn, "parent", self);
   changeentityproperty(vSpawn, "health", 12000); //Set health.
   changeentityproperty(vSpawn, "direction", iDirection); //Set direction.

   return vSpawn; //Return spawn.
}

