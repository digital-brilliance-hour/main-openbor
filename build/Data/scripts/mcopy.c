void main()
{
	void old = getlocalvar("old");
	void self = getlocalvar("self");
	changeentityproperty(self, "maxhealth", getentityproperty(old, "maxhealth"));
	changeentityproperty(self, "health", getentityproperty(old, "health"));
	changeentityproperty(self, "maxmp", getentityproperty(old, "maxmp"));
	changeentityproperty(self, "mp", getentityproperty(old, "mp"));
}

