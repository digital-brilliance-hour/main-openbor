void Rspawn(float fX, float fY, float fZ)
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
      int  iR = rand()%2 + 2;

   if (iR >= 0 && iR < 2){ 
        vName = "Blackheart_E";
      } else if (iR >= 1 && iR < 3){ 
        vName = "Spiderman_E";
      } else if (iR >= 2 && iR < 4){ 
        vName = "Blackheart_E";
      } else { 
        vName = "Spiderman_E";
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
   changeentityproperty(vSpawn, "health", 1200); //Set health.
   changeentityproperty(vSpawn, "direction", iDirection); //Set direction.

   return vSpawn; //Return spawn.
}




void Rspawn2(float fX, float fY, float fZ)
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
      int  iR = rand()%2 + 2;

   if (iR >= 0 && iR < 2){ 
        vName = "Cyclops_E";
      } else if (iR >= 1 && iR < 3){ 
        vName = "Amingo_E";
      } else if (iR >= 2 && iR < 4){ 
        vName = "Cyclops_E";
      } else { 
        vName = "Amingo_E";
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
   changeentityproperty(vSpawn, "health", 1200); //Set health.
   changeentityproperty(vSpawn, "direction", iDirection); //Set direction.

   return vSpawn; //Return spawn.
}




void Rspawn3(float fX, float fY, float fZ)
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
      int  iR = rand()%2 + 2;

   if (iR >= 0 && iR < 2){ 
        vName = "Strong_E";
      } else if (iR >= 1 && iR < 3){ 
        vName = "Colossus_E";
      } else if (iR >= 2 && iR < 4){ 
        vName = "Doctor_Doom_E";
      } else { 
        vName = "Strong_E";
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
   changeentityproperty(vSpawn, "health", 1200); //Set health.
   changeentityproperty(vSpawn, "direction", iDirection); //Set direction.

   return vSpawn; //Return spawn.
}

void Rspawn4(float fX, float fY, float fZ)
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
      int  iR = rand()%5 + 5;

   if (iR >= 0 && iR < 2){ 
        vName = "yankee";
      } else if (iR >= 2 && iR < 4){ 
        vName = "electra";
      } else if (iR >= 4 && iR < 6){ 
        vName = "eagle";
      } else if (iR >= 6 && iR < 8) { 
        vName = "raiden";
      } else { 
        vName = "poison";
      }