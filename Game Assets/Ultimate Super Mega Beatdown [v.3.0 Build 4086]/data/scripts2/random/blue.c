void Blueman()
{//Spawns random enemy next to caller.
   void self = getlocalvar("self"); //Get calling entity.
   void vSpawn; //Spawn object.
   void vName; //Spawn object's name.
      void vRName = getentityproperty(self,"defaultname"); // Get caller's real name.
      void Health = getentityproperty(self,"health"); // Get caller's health.
      vName = "Bluefire";

   clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

      void target = getentityproperty(self, "opponent");
      int fX = getentityproperty(target, "x"); 
      int fY = getentityproperty(target, "a"); 
      int fZ = getentityproperty(target, "z"); 
   
   vSpawn = spawn(); //Spawn in entity.

   changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
   changeentityproperty(vSpawn, "health", 120); //Set health.

   return vSpawn; //Return spawn.
}

