void lvup(int plIndex)
{
	int oldLevel=getglobalvar("level."+plIndex);
	if (oldLevel==NULL()){oldLevel=1;}
	log(oldLevel + " | ");
	int lv=oldLevel+1;
	log(lv + " | ");
	setglobalvar("level."+plIndex,lv);
	log(getglobalvar("level."+plIndex));
}
int getLevel(int plIndex)
{
	int oldLevel=getglobalvar("level."+plIndex);
	if (oldLevel==NULL()){
		oldLevel=1;
		setglobalvar("level."+plIndex,oldLevel);
	}
	int lv;
	lv = getglobalvar("level."+plIndex);
	return lv;
}
void changeLv(void pindex, int lv)
{
	setglobalvar("level."+pindex, lv);
}

