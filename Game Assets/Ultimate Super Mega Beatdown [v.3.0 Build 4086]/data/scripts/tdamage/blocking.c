void main()
{
	
	void self = getlocalvar("self");
	float fac=getentityproperty(self,"defense",openborconstant("ATK_NORMAL"),"factor");
	if (fac<1)
	{
		changeentityproperty(self, "colourmap", 1);
		changeentityproperty(self, "maptime", 10 + openborvariant("elapsed_time"));
		changeentityproperty(self, "velocity", 0, 0, 0);
		performattack(self,openborconstant("ANI_ATTACK4"),0);
		changeentityproperty(self,"defense",openborconstant("ATK_ATTACK1"),1,1,1);
		changeentityproperty(self,"defense",openborconstant("ATK_BLAST"),1,1,1);
	}else{}
}
