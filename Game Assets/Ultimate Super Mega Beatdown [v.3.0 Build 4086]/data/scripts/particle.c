void move()
{
	
	void self=getlocalvar("self");
	void tar=findtarget(self);
	if(tar!=NULL()){
	char ani="ANI_FOLLOW1";
	int aniid=getentityproperty(tar,"animationid");
	if (aniid==openborconstant("ANI_FALL")||aniid==openborconstant("ANI_RISE"))
	{}else
	{
		if (checkrange(self,tar,openborconstant("ANI_ATTACK1")))
		{
			ani="ANI_ATTACK1";
		}else if(checkrange(self,tar,openborconstant("ANI_ATTACK2")))
		{
			ani="ANI_ATTACK2";
		}
	}

	changeentityproperty(self,"aiflag","idling",0);
	changeentityproperty(self,"aiflag","attacking", 1);
	changeentityproperty(self,"takeaction", "common_attack_proc");
	changeentityproperty(self,"animation", openborconstant(ani));
	}
}

void targetL(float Vy, float dx, float dz)
{

	void self = getlocalvar("self");
	void target = findtarget(self);
	if( target != NULL())
	{
		int dir = getentityproperty(self, "direction");
		float Tx,Tz;
		float x = getentityproperty(self, "x");
		float z = getentityproperty(self, "z");
		if (dir == 0){
			dx = -dx;
		}else{}
		if ((rand()%100+100)<50)
		{
			Tx = getentityproperty(target, "x");
			Tz = getentityproperty(target, "z");

			if(Tx < x){
				changeentityproperty(self, "direction", 0);
			} else {
				changeentityproperty(self, "direction", 1);
			}

		}else{
			int minz,maxz,center;
			minz=openborconstant("PLAYER_MIN_Z");
			maxz=openborconstant("PLAYER_MAX_Z");
			center=(maxz - minz)/2;
			Tx = rand()%160+160 + openborvariant("xpos");
			Tz = rand()%center+center+minz;
		}

		x = x+dx;
		z = z+dz;
		setlocalvar("x"+self, (Tx-x)/(22*Vy));
		setlocalvar("z"+self, (Tz-z)/(22*Vy));

	} else {
		setlocalvar("z"+self, 0);
		setlocalvar("x"+self, 0);
	}
}

void leap(float Vely)
{
    void self = getlocalvar("self");
    float Vx = getlocalvar("x"+self);
    float Vz = getlocalvar("z"+self);
    if( Vx!=NULL() && Vz!=NULL() ){
      tossentity(self, Vely, Vx, Vz);
    }
}


