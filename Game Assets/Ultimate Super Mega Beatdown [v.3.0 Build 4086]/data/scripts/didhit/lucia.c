

void main()
{
	void self=getlocalvar("self");
	void tar=getlocalvar("damagetaker");
	if (getentityproperty(self,"animationid")==openborconstant("ANI_FREESPECIAL") && 
		getentityproperty(self,"animpos")>=8)
	{
		int vx;
		if (getentityproperty(self,"direction"))
		{
			vx=3;
		}else{
			vx=-3;
		}
		changeentityproperty(tar,"velocity",vx,0,-3);
	}
}


