#include "data/scripts/enemy.c"

void tele(float pos)
{
	void self=getlocalvar("self");
	void target=findtarget(self);
	float x=getentityproperty(target,"x");
	float z=getentityproperty(target,"z");
	if (getentityproperty(target,"direction")){
		x+=pos;
	}else{
		x-=pos;
	}
	changeentityproperty(self,"position",x,z);
}



