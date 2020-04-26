#include "data/scripts/enemy.c"
#include "data/scripts/common/target.c"
#include "data/scripts/common/shoot.c"
#include "data/scripts/common/spawn.c"
#include "data/scripts/common/rand.c"
#include "data/scripts/common/boss.c"

void tele()
{
	void self = getlocalvar("self");
	int minz,maxz,center;
	minz=openborconstant("PLAYER_MIN_Z");
	maxz=openborconstant("PLAYER_MAX_Z");
	center=(maxz - minz)/2;
	int Tx = rand()%160+160 + openborvariant("xpos");
	int Tz = rand()%center+center+minz;
	changeentityproperty(self,"position",Tx,Tz,0);
}

void hide(int s)
{
	//entity,flag,scalex, int scaley, int flipx, int flipy, int shiftx, int alpha, int remap, int fillcolor, int rotate, int fliprotate, int transparencybg, void* colourmap);
	if (s)
	{
		setdrawmethod(getlocalvar("self"), 1, 0, 0,0,0,0,0,0,0,0,0,0,getentityproperty(getlocalvar("self"),"colourmap"));
	}else{
		setdrawmethod(getlocalvar("self"), 1, 256, 256,0,0,0,0,0,0,0,0,0,getentityproperty(getlocalvar("self"),"colourmap"));
	}
}

