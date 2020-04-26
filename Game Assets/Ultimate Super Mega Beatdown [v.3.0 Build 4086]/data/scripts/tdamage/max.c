void main()
{
	void self = getlocalvar("self");
	void att=getlocalvar("attacker");
	int iTyp = openborconstant("ATK_NORMAL");
	float fac=getentityproperty(self,"defense",iTyp,"factor");
	if (fac<1){
		int r = rand()%500+500;
		if (r <=(getlocalvar("damage")+10)*10){
			changeentityproperty(self,"defense",iTyp,1,1,1);
			changeentityproperty(self,"defense",openborconstant("ATK_BLAST"),1,1,1);
			changeentityproperty(self,"animation",openborconstant("ANI_PAIN"));
		}else{}
		changeentityproperty(self, "colourmap", 1);
		changeentityproperty(self, "maptime", 14 + openborvariant("elapsed_time"));
		damageentity(att, self, getlocalvar("damage")*(1.00 - fac), 1, openborconstant("ATK_NORMAL"));
	}
}
