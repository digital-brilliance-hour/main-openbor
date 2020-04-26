#include "data/scripts2/Random/webber.c"

void spawner(void vName, float fX, float fY, float fZ)
{//Spawns item next to caller.
//
//vName: Spawned object
//fX   : X location adjustment.
//fZ   : Y location adjustment.
//fY   : Z location adjustment.

	void self = getlocalvar("self"); //Get calling entity.
	int  iDirection = getentityproperty(self, "direction");
	void vSpawn; //Spawn object.

	if (iDirection == 0){ //Is entity facing left?                  
          fX = -fX; //Reverse X direction to match facing.
	}

      fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
      fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
      fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.
	
	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.

	return vSpawn; //Return spawn.
}

void Ispawn(void vName, float fX, float fY, float fZ)
{//Spawns item next to caller.
//
//vName: Spawned item
//fX   : X speed.
//fZ   : Y speed.
//fY   : Z speed.

	void vSpawn = spawner(vName, 0, 0, 0); //Spawn object.

	changeentityproperty(vSpawn, "direction", 1); //Set direction.
      tossentity(vSpawn, fY, fX,fZ); // Toss item.

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