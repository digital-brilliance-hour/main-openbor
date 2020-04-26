void main()
{
	void self=getlocalvar("self");
	if (getentityproperty(self,"animationid")==7)
	{
		if (getentityproperty(self,"direction"))
		{
			knockback(getlocalvar("damagetaker"), 25);
		}else{
			knockback(getlocalvar("damagetaker"), -25);
		}
	}
}
void knockback(void other, float spd)
{
	float x=getentityproperty(other,"x");
	float z=getentityproperty(other,"z");
	x+=spd;
	if (checkwall(x,z)<=0){
		changeentityproperty(other,"position",x);
	}
}

