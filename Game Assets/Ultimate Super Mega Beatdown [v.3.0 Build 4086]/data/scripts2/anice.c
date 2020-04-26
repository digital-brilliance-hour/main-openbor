void changeAni(char ani)
{
	void self = getlocalvar("self");
	changeentityproperty(self, "animation", openborconstant(ani));
}