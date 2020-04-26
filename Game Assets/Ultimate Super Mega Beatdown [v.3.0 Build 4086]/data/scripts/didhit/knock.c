void getAni()
{
	void ent = getlocalvar("self");
	return getentityproperty(ent,"animationID");
}
void hitEffect(void ani,void vName,int startframe,int endframe)
{
	int anipos=getentityproperty(getlocalvar("self"),"animpos");
	if(getAni() == openborconstant(ani) && anipos>=startframe && anipos<=endframe){
		void target=getlocalvar("damagetaker");
		void vSpawn;
		clearspawnentry();
		setspawnentry("name", vName);
		vSpawn = spawn();
		changeentityproperty(vSpawn, "parent", target);
		changeentityproperty(vSpawn, "speed", getglobalvar("eParm"));
		setglobalvar("eParm",NULL());
		bindentity(vSpawn, target, 0, 1, 6, 1, 0);
	}
}

void hitBack(char ani,int startframe,int endframe,float spd)
{
	eParm(spd);
	hitEffect(ani,"hitback",startframe,endframe);
}

void eParm(float value)
{
	setglobalvar("eParm",value);
}
