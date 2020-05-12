void lvup(int plIndex)
{
	void score=getplayerproperty(plIndex,"score");
	void ent=getplayerproperty(plIndex,"entity");
	int oldLevel=getglobalvar("level."+plIndex);
	int lv=getLevel(score);
	if (oldLevel==NULL()){oldLevel=1;}
	if (lv>oldLevel){
		setAbi2(plIndex,ent, lv-oldLevel);
		setglobalvar("level."+plIndex,lv);
		spawnLvup(ent);
	}
	setglobalvar("score"+plIndex,score);
}
void spawnLvup(void ent)
{
	clearspawnentry();
	setspawnentry("name", "levelup");
	void vSpawn=spawn();
	float fX =getentityproperty(ent, "x");
	float fY = getentityproperty(ent, "a");
	float fZ = getentityproperty(ent, "z");
	changeentityproperty(vSpawn, "position", fX, fZ, fY + 70);
}
void setLevel()
{
	void pindex	=	getentityproperty(getlocalvar("self"),"playerindex");
	void score	=	getplayerproperty(pindex,"score");
	int lv		=	getLevel(score);
	setAbi(pindex,getlocalvar("self"));
}

void setAbi2(void plIndex, void ent, int delta)
{
	changeentityproperty(ent,"maxhealth",getentityproperty(ent,"maxhealth")+10*delta);
	changeentityproperty(ent,"maxmp",getentityproperty(ent,"maxmp")+10*delta);
	changeentityproperty(ent,"health",getentityproperty(ent,"maxhealth"));
	changeentityproperty(ent,"mp",getentityproperty(ent,"maxmp"));
//	changeplayerproperty(plIndex, "spawnhealth", getentityproperty(ent,"maxhealth"));
//	changeplayerproperty(plIndex, "spawnmp", getentityproperty(ent,"maxmp"));
}
void setAbi(void plIndex,void ent)
{
	void score=getplayerproperty(plIndex,"score");
	void lv=getLevel(score);
	setAbi2(plIndex, ent, lv-1);
	setglobalvar("level."+plIndex,lv);
}
int getLevel(void score)
{
	int lv;
	if(score>190000){
		lv=20;
	}else if(score>171000){
		lv=19;
	}else if(score>153000){
		lv=18;
	}else if(score>136000){
		lv=17;
	}else if(score>120000){
		lv=16;
	}else if(score>105000){
		lv=15;
	}else if(score>91000){
		lv=14;
	}else if(score>78000){
		lv=13;
	}else if(score>66000){
		lv=12;
	}else if(score>55000){
		lv=11;
	}else if(score>45000){
		lv=10;
	}else if(score>36000){
		lv=9;
	}else if(score>28000){
		lv=8;
	}else if(score>21000){
		lv=7;
	}else if(score>15000){
		lv=6;
	}else if(score>10000){
		lv=5;
	}else if(score>6000){
		lv=4;
	}else if(score>3000){
		lv=3;
	}else if(score>1000){
		lv=2;
	}else{
		lv=1;
	}
	return lv;
}
void getPlLevel(int plIndex)
{
	void ent=getplayerproperty(plIndex,"entity");
	if (!ent){return;}else{}
	void score=getplayerproperty(plIndex,"score");
	setglobalvar("level."+plIndex,getLevel(score));
}
void changeLv(void pindex)
{
	lvup(pindex);
	void lv	=	getglobalvar("level."+pindex);
	if(lv==NULL())lv=1;
}

