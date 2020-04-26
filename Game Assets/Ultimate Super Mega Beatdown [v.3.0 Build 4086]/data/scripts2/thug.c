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
        vName = "Garcia";
      } else if (iR >= 2 && iR < 4){ 
        vName = "Carol";
      } else if (iR >= 4 && iR < 6){ 
        vName = "Lesus";
      } else if (iR >= 6 && iR < 8){ 
        vName = "Rini";
      } else { 
        vName = "Ray";
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

	if (vAlias == vRName){ // If this entity doesn't have alias, it will use spawned entity's name.
        vAlias = vName;
      }

	if (vAlias == "Garcia"){ // If Garcia is spawned, his alias will be adjusted to his remap
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
      } else if (vAlias == "Ray"){ // If Ray is spawned, his alias will be adjusted to his remap
        if (iMap == 1 || iMap == 4){
          vAlias = "J";
        } else if (iMap == 2 || iMap == 5){
          vAlias = "Bred";
        } else if (iMap == 3 || iMap == 6){
          vAlias = "Zack";
        }
      } else if (vAlias == "Lesus"){ // If Lesus is spawned, his alias will be adjusted to his remap
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
          vAlias = "Hujan";
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

void RspawnU(float fX, float fY, float fZ)
{//Spawns random enemy next to caller.
// Spawned enemy has Upper ability
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
      int  iR = rand()%3 + 3;

	if (iR >= 0 && iR < 2){ 
        vName = "Joe";
      } else if (iR >= 2 && iR < 4){ 
        vName = "Angel";
      } else { 
        vName = "Donna";
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

	if (vAlias == vRName){ // If this entity doesn't have alias, it will use spawned entity's name.
        vAlias = vName;
      }

	if (vAlias == "Joe"){ // If Joe is spawned, his alias will be adjusted to his remap
	  if (iMap == 0){
          vAlias = "Elang";
        } else if (iMap == 1){
          vAlias = "Condor";
        } else if (iMap == 2){
          vAlias = "Hawk";
        } else if (iMap == 3){
          vAlias = "Eagle";
        } else if (iMap == 4){
          vAlias = "Rajawali";
        } else if (iMap == 5){
          vAlias = "Raven";
        }
      } else if (vAlias == "Donna"){ // If Donna is spawned, her alias will be adjusted to her remap
        if (iMap == 1 || iMap == 5){
          vAlias = "Althea";
        } else if (iMap == 2){
          vAlias = "Maria";
        } else if (iMap == 3){
          vAlias = "Reina";
        } else if (iMap == 4){
          vAlias = "Zora";
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

void Rspawn2(float fX, float fY, float fZ)
{//Spawns random enemy next to caller.
// Spawned enemy is hard enemy
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
      int  iR = rand()%4 + 4;

	if (iR >= 0 && iR < 2){ 
        vName = "Mary";
      } else if (iR >= 2 && iR < 4){ 
        vName = "Jhun";
      } else if (iR >= 4 && iR < 6){ 
        vName = "MayLee";
      } else { 
        vName = "Vanessa";
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

	if (vAlias == vRName){ // If this entity doesn't have alias, it will use spawned entity's name.
        vAlias = vName;
      }

	if (vAlias == "Jhun"){ // If Jhun is spawned, his alias will be adjusted to his remap
	  if (iMap == 1){
          vAlias = "Hakuyo";
        } else if (iMap == 2){
          vAlias = "Suicho";
        } else if (iMap == 3){
          vAlias = "Singa";
        } else if (iMap == 4){
          vAlias = "Tiger";
        } else if (iMap == 5){
          vAlias = "Macan";
        } 
      } else if (vAlias == "MayLee"){ // If MayLee is spawned, her alias will be adjusted to her remap
        if (iMap == 0){
          vAlias = "Maya";
        } else if (iMap == 1){
          vAlias = "Kelly";
        } else if (iMap == 2){
          vAlias = "Nina";
        } else if (iMap == 3){
          vAlias = "Jessy";
        } else if (iMap == 4){
          vAlias = "Lisa";
        } else if (iMap == 5){
          vAlias = "Betsy";
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

void RspawnD(float fX, float fY, float fZ)
{//Spawns random rolling drum next to caller.
// Spawned drum could be destructible or not
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
      int  iR = rand()%3 + 3;

	if (iR >= 0 && iR < 4){ 
        vName = "RollDrum";
      } else { 
        vName = "SDrum";
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

	if (vAlias == vRName){ // If this entity doesn't have alias, it will use spawned entity's name.
        vAlias = "Drum";
      }

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "name", vAlias); //Set alias.
	changeentityproperty(vSpawn, "map", iMap); //Set map.
	changeentityproperty(vSpawn, "maxhealth", iMHealth); //Set maximum health.
	changeentityproperty(vSpawn, "health", iHealth); //Set health.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.

	return vSpawn; //Return spawn.
}

void RspawnDM(float fX, float fY, float fZ)
{//Spawns random mirrored rolling drum next to caller.
// Spawned drum could be destructible or not
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
      int  iR = rand()%3 + 3;

	if (iR >= 0 && iR < 4){ 
        vName = "RDrumM";
      } else { 
        vName = "SDrumM";
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

	if (vAlias == vRName){ // If this entity doesn't have alias, it will use spawned entity's name.
        vAlias = "Drum";
      }

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "name", vAlias); //Set alias.
	changeentityproperty(vSpawn, "map", iMap); //Set map.
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

void move(int dx, int dz,int da)
{ // Moves entity freely or ignores obstacles
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

void anichange(void Ani)
{ // Animation changer
    void self = getlocalvar("self");

    changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
}

void dasher( float Vx, float Vy, float Vz )
{// Dash with desired speed!
    void self = getlocalvar("self");
    int dir = getentityproperty(self,"direction");

    if(dir==0){ // Facing left?
      Vx = -Vx ;
    }

    if( Vx!=NULL() && Vy!=NULL() && Vz!=NULL() ){
      changeentityproperty(self, "velocity", Vx, Vz, Vy); //Move!!
    }
}

void stop()
{// Stop enemy's movement!
    void self = getlocalvar("self");
    changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
}
