#include	"data/scripts/enemy.c"
void spawnB(void vName, float fX, float fY, float fZ,float Vx,float Vz)
{
	void vSpawn;
	void self = getlocalvar("self");
	int  iDirection = getentityproperty(self, "direction");

	clearspawnentry();
	setspawnentry("name", vName);


	if (iDirection == 0){
		fX = -fX;
	}

	fX = fX + getentityproperty(self, "x");
	fY = fY + getentityproperty(self, "a");
	fZ = fZ + getentityproperty(self, "z");

	vSpawn = spawn();
	changeentityproperty(vSpawn, "direction", iDirection);
	changeentityproperty(vSpawn, "position", fX, fZ, fY);
	changeentityproperty(vSpawn, "parent", self);
	changeentityproperty(vSpawn, "velocity", Vx, Vz,0);
	return vSpawn;
}

void tosser(void Bomb, float dx, float dy, float dz, float Vx, float Vy, float Vz)
{ // Tossing bomb with desired speed
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   void Shot;

   if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
   }

   Shot = projectile(Bomb, x+dx, z+dz, y+dy, Direction, 0, 1, 0);
   tossentity(Shot, Vy, Vx, Vz);
   changeentityproperty(Shot, "speed", Vx); 
}

void ready()
{
	int num=openborvariant("count_enemies");
	if (num<=1){
		playmusic("data/music/boss3.bor");
		changeAni("ANI_FOLLOW1");
	}
}

void spawnC(void vName, float fX)
{
	void self = getlocalvar("self");
	void vSpawn;
	void target=findtarget(self);
	int  iDirection = getentityproperty(self, "direction");

	clearspawnentry();
	setspawnentry("name", vName);
	
	if (iDirection == 0){fX = -fX;}
	fX = fX + getentityproperty(self, "x");
	void fZ = getentityproperty(target, "z");
	
	vSpawn = spawn();
	changeentityproperty(vSpawn, "position", fX, fZ, 0);
	return vSpawn;
}



