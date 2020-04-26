void randBranch(int p,char ani1,char ani2)
{
	void self = getlocalvar("self");
	int r = rand()%500+500;
	if (r <=p*10){
		changeentityproperty(self, "animation", openborconstant(ani1)); 
	}else{
		if (ani2!=""){changeentityproperty(self, "animation", openborconstant(ani2));}
	}
}