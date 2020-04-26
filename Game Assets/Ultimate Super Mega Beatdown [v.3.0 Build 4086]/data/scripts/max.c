#include "data/scripts/common/commons.c"
#include "data/scripts/common/spawn.c"

void death()
{
	int stageNum=openborvariant("current_level");
	if (stageNum>=18){
		spawn02("MaxN4");
	}
}

void spawnMax()
{
	int stageNum=openborvariant("current_level");
	if (stageNum==3){
		spawn02("MaxN1");
	}
	if (stageNum==5){
		spawn02("MaxN2");
	}
	if (stageNum==14){
		spawn02("MaxN3");
	}
}

void checkMax()
{
	void vSelf = getplayerproperty(0, "entity");
	void vName = getentityproperty(vSelf,"name");
	void self = getlocalvar("self");
	if (vName=="Max"){
		killentity(self);
	}else{}
}







