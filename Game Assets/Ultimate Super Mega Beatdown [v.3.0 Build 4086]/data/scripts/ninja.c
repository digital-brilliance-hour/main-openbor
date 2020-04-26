#include "data/scripts/enemy.c"
void tele()
{
	void self=getlocalvar("self");
	void target=findtarget(self);
	float x=getentityproperty(target,"x");
	float z=getentityproperty(target,"z");
	if (getentityproperty(target,"direction")){
		x-=70;
	}else{
		x+=70;
	}
	changeentityproperty(self,"position",x,z);
}
