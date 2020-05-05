void bind(int null, float x, float z, float y, int dir){
	void self = getlocalvar("self");
	void opp = getentityproperty(self, "attacker");
	if(null == 1)
	{
		bindentity(opp, self, x, z, y, dir, 0);
	}
	else if(null == 0)
	{
		bindentity(opp, NULL());
	}
}

void forceanim(int anim){
	void self = getlocalvar("self");
	void opp = getentityproperty(self, "attacker");
	changeentityproperty(opp, "animation", anim);
}