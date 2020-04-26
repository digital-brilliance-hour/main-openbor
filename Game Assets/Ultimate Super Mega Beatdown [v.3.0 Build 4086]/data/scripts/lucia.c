#include "data/scripts/common/spawn.c"
#include "data/scripts/common/slam.c"
#include "data/scripts/common/commons.c"
#include "data/scripts/common/key.c"
#include "data/scripts/common/player.c"
void moveEnemy(int dis)
{
	void self=getlocalvar("self");
	void tar=getentityproperty(self,"grabbing");
	if (tar!=NULL())
	{
		float ex;
		if (getentityproperty(self,"direction"))
		{
			ex=getentityproperty(tar,"x")-dis;
		}else{
			ex=getentityproperty(tar,"x")+dis;
		}
		if (checkwall(ex,getentityproperty(tar,"z")))
		{
			damageentity(tar, self, 15, 1, openborconstant("ATK_NORMAL"));
		}else{
			changeentityproperty(tar,"position",ex);
		}
	}
}
void backAni(char ani)
{
	void self=getlocalvar("self");
	void tar=getentityproperty(self,"grabbing");
	if (tar!=NULL())
	{
		if (getentityproperty(self,"direction")==getentityproperty(tar,"direction"))
		{changeAni(ani);}
	}
}

