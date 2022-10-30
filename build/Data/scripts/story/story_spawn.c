void spawnDialog(char vName)
{
	void self = getlocalvar("self");
	clearspawnentry();
	setspawnentry("name", "story");
	void vSpawn=spawn();
	changeentityproperty(vSpawn, "name", vName);
	return vSpawn;
}
void noControl(void swi)
{
	int i,ent;
	for (i=0;i<3;i++)
	{
		ent=getplayerproperty(i,"ent");
		if(ent)changeentityproperty(ent,"noaicontrol",swi);
	}
}
