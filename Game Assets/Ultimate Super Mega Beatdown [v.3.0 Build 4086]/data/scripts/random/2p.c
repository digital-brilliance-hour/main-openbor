void coolo()
{//Spawns random enemy next to caller.
//
//fX: X location adjustment.
//fZ: Y location adjustment.
//fY: Z location adjustment.

   void self = getlocalvar("self"); //Get calling entity.
   void vSpawn; //Spawn object.
   void vName; //Spawn object's name.
   void target = getlocalvar(self, "opponent"); //Get calling entity.
      void vRName = getentityproperty(self,"defaultname"); // Get caller's real name.
      int XX = getentityproperty(self,"defaultname"); // Get caller's real name.
      void vAlias = getentityproperty(self,"name"); // Get caller's alias.
      void Health = getentityproperty(self,"health"); // Get caller's health.
   int  iDirection = getentityproperty(self, "direction"); // Get caller's direction.
   int  iMap = getentityproperty(self, "map"); // Get caller's remap.
      int  iR = rand()%5 + 5;

   if (iR >= 0 && iR < 2){ 
        vName = "XX";
      } else if (iR >= 2 && iR < 4){ 
        vName = "XX";
      } else if (iR >= 4 && iR < 6){ 
        vName = "XX";
      } else if (iR >= 6 && iR < 8) { 
        vName = "XX";
      } else { 
        vName = "XX";
      }

      clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.
   
   vSpawn = spawn(); //Spawn in entity.

   changeentityproperty(vSpawn, "map", iMap); //Set map.
   changeentityproperty(vSpawn, "health", 120); //Set health.
   changeentityproperty(vSpawn, "direction", iDirection); //Set direction.

   return vSpawn; //Return spawn.
}


void land()
{// Lands with land animation
    void self = getlocalvar("self");
    void Health = getentityproperty(self,"health"); //Get enemy's health
    int LandId = openborconstant("ANI_LAND");

    if(Health > 0){
      performattack(self, LandId);
    } else {
      damageentity(self, self, 1000, 1, openborconstant("ATK_NORMAL")); // Suicide
    }
}
