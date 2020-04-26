void grabFree()
{
	void self=getlocalvar("self");
	void target=getentityproperty(self,"opponent");
	changeentityproperty(self,"aiflag","idling",1);
	changeentityproperty(target,"aiflag","idling",1);
	bindentity(target,NULL());
	bindentity(self,NULL());
	//changeentityproperty(target,"takeaction","idling",1);
	if (target!=NULL()){damageentity(target,self,0,0,openborconstant("ATK_NORMAL"));}
}
/*
void grabFree2(char ani)
{
	void self=getlocalvar("self");
	void target=getentityproperty(self,"opponent");
	changeentityproperty(self,"aiflag","idling",1);
	changeentityproperty(target,"aiflag","idling",1);
	bindentity(target,NULL());
	bindentity(self,NULL());
	//enterAtt(ani);
	changeentityproperty(self,"animation",ani);
	//changeentityproperty(target,"takeaction","idling",1);
	if (target!=NULL()){damageentity(target,self,0,0,openborconstant("ATK_NORMAL"));}
	enterAtt(ani);
}*/

