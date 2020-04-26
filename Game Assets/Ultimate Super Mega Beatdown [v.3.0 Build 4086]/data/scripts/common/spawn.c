
void spawnEntity(void vName, float fX, float fY, float fZ,int map,int pos)
{
	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iDirection = getentityproperty(self, "direction");

	clearspawnentry(); //Clear current spawn entry.
	setspawnentry("name", vName); //Acquire spawn entity by name.
	
	
	if (pos==0){
		if (iDirection == 0){ //Is entity facing left?                  
			fX = -fX; //Reverse X direction to match facing.
		}
		fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
		fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
		fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.
	}else{
		iDirection=1;
		fX=fX+openborvariant("xpos");
		fY=fY+openborvariant("ypos");
	}
	vSpawn = spawn(); //Spawn in entity.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.
	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "parent", self); //Set caller as parent.


	if (map>0){
		changeentityproperty(vSpawn, "map", map);
	}

	return vSpawn; //Return spawn.
}

void spawn01(void vName, float fX, float fY, float fZ)
{
	return spawnEntity(vName, fX, fY, fZ,0,0); //Spawn in entity.
}

void spawn02(void vName)
{
	return spawnEntity(vName, 0, 0, 0,0,1); //Spawn in entity.
}
