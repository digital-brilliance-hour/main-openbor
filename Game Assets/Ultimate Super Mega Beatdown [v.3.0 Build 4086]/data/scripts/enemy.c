#include "data/scripts/common/commons.c"

void hardAtt(char ani)
{
	if (openborvariant("current_set")>0) {
		enterAtt(ani);
	}
}
void hardSet()
{
	if (openborvariant("current_set")>=2){
		void self=getlocalvar("self");
		void target=findtarget(self);
		if (getentityproperty(target,"animationid")==openborconstant("ANI_FALL")){
			changeentityproperty(self, "aimove",openborconstant("AIMOVE1_AVOID")+openborconstant("AIMOVE2_AVOID"));
		}else{
			if (getentityproperty(self,"direction")==getentityproperty(target,"direction")){
				changeentityproperty(self, "aimove", openborconstant("AIMOVE1_CHASE")+openborconstant("AIMOVE2_NORMAL"));
			}else{
				changeentityproperty(self, "aimove", openborconstant("AIMOVE1_NORMAL")+openborconstant("AIMOVE2_AVOID"));
			}
		}
	}
}

void moveSet()
{
	moveSetAni("ANI_FOLLOW4");
}

void moveSetAni(char ani)
{
	void self=getlocalvar("self");
	void target=findtarget(self);
	void aid=getentityproperty(target,"animationid");
	if (aid==openborconstant("ANI_FALL") ||aid==openborconstant("ANI_RISE"))
	{
		enterAtt(ani);
	}
}
