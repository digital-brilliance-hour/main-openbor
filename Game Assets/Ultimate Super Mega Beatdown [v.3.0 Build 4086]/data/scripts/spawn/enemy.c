void main()
{
	void c=openborvariant("count_players");
	void self=getlocalvar("self");
	void mh=getentityproperty(self,"maxhealth");
	mh+=(mh*(c - 1)*0.45 + (c - 1)*20);
	changeentityproperty(self,"maxhealth",mh);
	changeentityproperty(self,"health",mh);

	int level=openborvariant("current_set");
	float spd=getentityproperty((self),"speed");
	int aggset=-40;
	if (level>0)
	{
		if (level==1){
			spd+=0.1;
			aggset+=30 + c*12;
		}else{
			spd+=0.2;
			aggset+=80 + c*15;
		}
	}
	spd+=(c-1)*0.04;
	changeentityproperty(self,"speed",spd);
	changeentityproperty(self,"aggression",aggset);
}
