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
      int  iMHealth = getentityproperty(self,"maxhealth"); // Get caller's maximum health.
      int  iHealth = getentityproperty(self,"health"); // Get caller's health.
	int  iDirection = getentityproperty(self, "direction"); // Get caller's direction.
	int  iMap = getentityproperty(self, "map"); // Get caller's remap.
      int  iR = rand()%5 + 5;

	if (iR >= 0 && iR < 2){ 
        vName = "Bane";
      } else if (iR >= 3 && iR < 5){ 
        vName = "Thug1";
      } else if (iR >= 6 && iR < 8){ 
        vName = "raiden;
      } else if (iR >= 9 && iR < 10){ 
        vName = "thug1";
      } else {
	vName = "Bane";
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
	changeentityproperty(vSpawn, "maxhealth", iMHealth); //Set maximum health.
	changeentityproperty(vSpawn, "health", iHealth); //Set health.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.

	return vSpawn; //Return spawn.
}


void suicide()
{ // Suicide!!
    void self = getlocalvar("self");

    damageentity(self, self, 10000, 1, openborconstant("ATK_NORMAL"));
}

