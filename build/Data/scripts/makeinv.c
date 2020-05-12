void makeInv(long invTime)
{
	void vSelf = getlocalvar("self");
	long iTime = openborvariant("elapsed_time");
	changeentityproperty(vSelf, "invincible", 1);
	changeentityproperty(vSelf, "invinctime", iTime + invTime);
}

