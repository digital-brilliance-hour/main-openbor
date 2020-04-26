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
      int  iR = rand()%8 + 8;

   if (iR > 0 && 2 > iR){ 
        vName = "LeiAkuma";
      } else if (iR > 1 && 3 > iR) { 
        vName = "LeiAxe";
      } else if (iR > 2 && 4 > iR) { 
        vName = "LeiBarrel";
      } else if (iR > 3 && 5 > iR) { 
        vName = "LeiBomb";
      } else if (iR > 4 && 6 > iR) { 
        vName = "LeiBomb";
      } else if (iR > 5 && 7 > iR) { 
        vName = "LeiHammer";
      } else if (iR > 6 && 8 > iR) { 
        vName = "LeiKnife";
      } else if (iR > 7 && 9 > iR) { 
        vName = "LeiPan";
      } else if (iR > 8 && 10 > iR) { 
        vName = "LeiPanda";
      } else if (iR > 9 && 11 > iR) { 
        vName = "LeiPinkBomb";
      } else if (iR > 10 && 12 > iR) { 
        vName = "LeiPinksi";
      } else if (iR > 11 && 13 > iR) { 
        vName = "LeiRang";
      } else if (iR > 12 && 14 > iR) { 
        vName = "LeiSpikey";
      } else if (iR > 13 && 15 > iR) { 
        vName = "LeiStar";
      } else if (iR > 14 && 16 > iR) { 
        vName = "LeiRang";
      } else { 
        vName = "LeiStone";
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
   changeentityproperty(vSpawn, "health", 160); //Set health.
   changeentityproperty(vSpawn, "direction", iDirection); //Set direction.

   return vSpawn; //Return spawn.
}
