void sendMsg()
{
	int index=getlocalvar("fh");
	char name=getfilestreamargument(index, 0, "string");
	if (name=="end"||name==""||name==NULL()){
		setglobalvar("msg2",NULL());
		killentity(getlocalvar("self"));
	}
	else
	{
		char pro=getfilestreamargument(index, 1, "string");
		setglobalvar("msgName",name);
		if (pro=="" || pro==NULL()){pro=name;}
		setglobalvar("msgPro",pro);
		setglobalvar("msgTicker2",0);
		setglobalvar("msg2",getfilestreamargument(index, 2, "string"));
		setglobalvar("msg22",getfilestreamargument(index, 3, "string"));
		filestreamnextline(index);
	}
}

void talk()
{
	void vSelf = getplayerproperty(0, "entity");
	void vName = getentityproperty(vSelf,"name");
	void self = getlocalvar("self");
	//char folder=getglobalvar("storyB");
	char folder=getentityproperty(self,"name");
	//char folder=getentityproperty(self,"name");
	if (folder==NULL()){folder=openborvariant("current_level");}
	//setlocalvar("fh",openfilestream("data/story/"+folder+"/"+vName+".txt"));
	setlocalvar("fh",openfilestream("data/story/"+folder+".txt"));
	setglobalvar("storyB",NULL());
	changeentityproperty(self, "animation", openborconstant("ANI_FREESPECIAL")); 
}

void playBgm(char bgm){
	playmusic(bgm, 1);
}
