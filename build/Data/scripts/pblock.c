void pblock()
{
	void self = getlocalvar("self");
	void other = getlocalvar("attacker");
 //	performattack(self, openborconstant("ANI_FOLLOW1")); //change according to whatever you need
	changeentityproperty(self, "aiflag", "invincible",1);
	changeentityproperty(self, "aiflag", "blink",1);
	changeentityproperty(self, "invinctime", openborvariant("elapsed_time")+400);

	changeentityproperty(other, "nextanim", getentityproperty(other, "nextanim")+30); //stun the target a bit

}

