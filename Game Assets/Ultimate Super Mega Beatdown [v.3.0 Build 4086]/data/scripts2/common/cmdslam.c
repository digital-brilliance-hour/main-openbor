#include "data/scripts/common/slam.c"

void lockR(int Rx, int Rz,int Ra,char ani1,char ani2)
{

	void self=getlocalvar("self");
	void target=getlocalvar("Target"+self);
	if (target==NULL()){
		target=findTarget01(Rx,Rz,Ra);
		if (target!=NULL()){
			setlocalvar("Target" + self, target);
			if (ani1!=""){
				changeAni(ani1);
			}
		}else{
			if (ani2!=""){
				changeAni(ani2);
			}
		}
	}
}

void lockRE(int Rx, int Rz,int Ra,char ani1,char ani2)
{

	void self=getlocalvar("self");
	void target=getlocalvar("Target"+self);
	if (target==NULL()){
		target=findTarget02(Rx,Rz,Ra);
		if (target!=NULL()){
			setlocalvar("Target" + self, target);
			if (ani1!=""){
				changeAni(ani1);
			}
		}else{
			if (ani2!=""){
				changeAni(ani2);
			}
		}
	}
}


void airFree(char Ani)
{
	void self=getlocalvar("self");
	void target = getlocalvar("Target"+self); 
	
	if(target!=NULL()){
		changeentityproperty(self, "animation", openborconstant(Ani));
	}
}

int isInRange(void self,int dir,void target,int Rx, int Rz,int Ra,float x,float z,float a)
{
	float Tx = getentityproperty(target, "x");
	float Tz = getentityproperty(target, "z");
	float Ta = getentityproperty(target, "a");
	float Disx;
	float Disz = Tz - z;
	float Disa = Ta - a;

	if (dir==0){
		Disx = x - Tx;
	}else{
		Disx = Tx - x;
	}

	if(Disz < 0){
		Disz = -Disz;
	}
	if(Disa < 0){
		Disa = -Disa;
	}
	
	if( Disx <= Rx && Disx>0 && Disz <= Rz && Disa<=Ra)
	{
		setlocalvar("Target" + self, target);
		return 1;
	}else{
		return 0;
	}
}

void findTarget01(int Rx, int Rz,int Ra)
{
	int iECnt = openborvariant("ent_max");
	int iEnt;
	void vEnt;
	void self = getlocalvar("self");
	float x = getentityproperty(self, "x");
	float z = getentityproperty(self, "z");
	float a = getentityproperty(self, "a");
	int dir=getentityproperty(self,"direction");
	for(iEnt=0; iEnt<iECnt; iEnt++)
	{
		vEnt = getentity(iEnt);
		if (
		getentityproperty(vEnt,"type")==openborconstant("TYPE_ENEMY")
		&& getentityproperty(vEnt,"exists")
		&& !getentityproperty(vEnt,"dead")
		&& vEnt
		&& getentityproperty(vEnt,"animationid")!=openborconstant("ANI_RISE")
		){
			if (isInRange(self,dir,vEnt,Rx,Rz,Ra,x,z,a)){
				return vEnt;
			}
		}
	}
	return NULL();
}

void findTarget02(int Rx, int Rz,int Ra)
{
	int iECnt = openborvariant("ent_max");
	int iEnt;
	
	void self = getlocalvar("self");
	void vEnt=findtarget(self);
	float x = getentityproperty(self, "x");
	float z = getentityproperty(self, "z");
	float a = getentityproperty(self, "a");
	int dir=getentityproperty(self,"direction");

	if (
	getentityproperty(vEnt,"type")==openborconstant("TYPE_PLAYER")
	&& getentityproperty(vEnt,"exists")
	&& !getentityproperty(vEnt,"dead")
	&& vEnt
	&& getentityproperty(vEnt,"animationid")!=openborconstant("ANI_RISE")
	&& getentityproperty(vEnt, "a")>0
	)
	{
		if (isInRange(self,dir,vEnt,Rx,Rz,Ra,x,z,a)){
			return vEnt;
		}
	}
	return NULL();
}

