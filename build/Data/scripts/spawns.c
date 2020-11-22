#include "data/scripts/animation/animation.c"
void spawn01(void vName, float fX, float fY, float fZ)
{
	//spawn01 (Generic spawner)
	//Damon Vaughn Caskey
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

void spawnbind(void Name, float dx, float dy, float dz)
{ // Spawn and bind other entity
   void self = getlocalvar("self");
   void Spawn;

   Spawn = spawn01(Name, dx, dy, 0);
   bindentity(Spawn, self, dx, dz, dy, 0, 0);
}

void spawn02(void vName, float fX, float fY, float fZ, void Alias)
{
	//spawn02 (Generic spawner with alias)
	//Spawns entity next to caller.
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
        //fY: Z location adjustment.
	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iDirection = getentityproperty(self, "direction");

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name",vName); //Acquire spawn entity by name.
	if (iDirection == 0){ //Is entity facing left?                  
          fX = -fX; //Reverse X direction to match facing.
	}

      fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
      fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
      fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.
	
	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.
    	changeentityproperty(vSpawn, "name", Alias); //Set Alias to spawned entity
	return vSpawn; //Return spawn.
}

void spawnbind02(void Name, float dx, float dy, float dz)
{ // Spawn and bind other entity
   void self = getlocalvar("self");
   void frame = getentityproperty(self, "animpos");
   void Spawn;

   Spawn = spawn(Name, dx, dy, 0);
   bindentity(Spawn, self, dx, dz, dy, 0, 0);
   updateframe(Spawn, frame);
}

void damage_all_enemies(int damage, int drop, int stay, void atk_type)
{
 	int  iEntity;
    void vEntity;
    void self        = getlocalvar("self");
    int  iMax        = openborvariant("ent_max");
    int Def;
               
    for(iEntity=0; iEntity<iMax; iEntity++)
    {       
        vEntity = getentity(iEntity);
        Def = getentityproperty(vEntity, "defense", openborconstant("ATK_NORMAL50"));
		if(getentityproperty(vEntity, "type")==openborconstant("TYPE_enemy"))
		{		
		damageentity(vEntity,self,damage,drop,openborconstant(atk_type));
		changeentityproperty(vEntity, "staydown", "riseattack", stay);	
		}
	}	
}

void damage_all_players(int damage, int drop, int stay, void atk_type)
{
 	int  iEntity;
 	void p;
    void vEntity;
    void self        = getlocalvar("self");
    int  iMax        = openborvariant("ent_max");
    int Def;
               
    for(iEntity=0; iEntity<4; iEntity++)
    {       
        p = getplayerproperty(iEntity, "entity");
        if(p){
	        if("Travel"!=getentityproperty(p, "model")) {	
				damageentity(p,self,damage,drop,openborconstant(atk_type));
				changeentityproperty(p, "staydown", "riseattack", stay);	
	        }
        }
	}	
}
