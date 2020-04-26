void main()
{
	int player = getlocalvar("player");
	void self = getplayerproperty(player, "ent");
	int animation = getentityproperty(self, "animation");
	//float a = getentityproperty(self, "a");
	//float base = getentityproperty(self, "base");*/
	int playkeys = getplayerproperty(player, "playkeys");
	int jumpflag = 0;
	
	if(playerkeys(player, 1, "special")){
		jumpflag = openborconstant("FLAG_SPECIAL");
		if(animation == openborconstant("ANI_PAIN")){
			changeplayerproperty(player, "playkeys", playkeys - jumpflag);
		}
	}
}