void blockingStart()
{
	if (!getlocalvar("bReady")){return;}else{}
	void self=getlocalvar("self");
	int iPIndex = getentityproperty(self,"playerindex");
	int key;
	
	if (getentityproperty(self,"direction"))
	{
		key = playerkeys(iPIndex, 0, "moveright");
	}else{
		key = playerkeys(iPIndex, 0, "moveleft");
	}

	if (key)
	{
		int iTyp = openborconstant("ATK_NORMAL");
		float fac=getentityproperty(self,"defense",iTyp,"factor");
		changeentityproperty(self,"defense",openborconstant("ATK_NORMAL"),0,999,0);
		changeentityproperty(self,"defense",openborconstant("ATK_BLAST"),0,999,0);
		setlocalvar("blocking",1);
	}
}
void blockingEnd()
{
	void self = getlocalvar("self");
	if (!getlocalvar("blocking")){return;}else{}
	changeentityproperty(self,"defense",openborconstant("ATK_NORMAL"),1,1,1);
	changeentityproperty(self,"defense",openborconstant("ATK_BLAST"),1,1,1);
	setlocalvar("blocking",0);
	bReady(0);
}
void bReady(int value)
{
	setlocalvar("bReady",value);
}

