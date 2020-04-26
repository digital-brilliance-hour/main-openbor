void lock()
{
	void self = getlocalvar("self");
	void target = getlocalvar("Target" + self);
	if(target==NULL())
	{
		target = getentityproperty(self, "grabbing");
		if (target==NULL()){
			target = getentityproperty(self, "opponent");
		}
		setlocalvar("Target" + self, target);
	}
}


void slamStart()
{ 
	void self = getlocalvar("self");
	void target = getlocalvar("Target" + self);
	//*********************************
	//changeentityproperty(self, "aiflag", "jumping", 0); // Disable jumping status
   	//changeentityproperty(self, "aiflag", "attacking", 1); // Enable attacking status
   	//changeentityproperty(self, "takeaction", "common_grabattack"); // Enters grabattack
	//*********************************
	if(target==NULL())
	{
		//setidle(self);//Target lost.Normally it's impossible!
	}else{
		damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL7"));
	}
}

void position(int Frame, float dx, float dy, float dz, int face)
{ // Modify grabbed entity's position relative to grabber
	void self = getlocalvar("self");
	void target = getlocalvar("Target" + self);

	if(target==NULL())
	{
		//setidle(self);//Target lost.Normally it's impossible!
	}
	else
	{
		updateframe(target, Frame);
		bindentity(target, self, dx, dz, dy, face, 0);
	}
}

void depost(int Gr)
{// Release grabbed entity
	void self = getlocalvar("self");
	void target = getlocalvar("Target" + self);

	if(target==NULL())
	{
		//setidle(self);//Target lost.Normally it's impossible!
	}else{
		bindentity(target, NULL());
		if(Gr == 1)
		{
			int x = getentityproperty(target, "x");
			int z = getentityproperty(target, "z");
			changeentityproperty(target, "position", x, z, 0);
		}
	}
}

void clearSlam()
{
	void self = getlocalvar("self");
	void target = getlocalvar("Target" + self);

	if(target!=NULL())
	{
		setlocalvar("Target"+self,NULL());
	}
}

void finish(int Damage, int x, int y, int z, int Face)
{ // Damage as slam or throw finisher
	void self = getlocalvar("self");
	void target = getlocalvar("Target" + self);
	int SDir = getentityproperty(target,"direction");
	int MDir;

	if(Face==0){ // Same facing?
		MDir = SDir;
	}

	if(Face==1){ // Opposite facing?
		if(SDir==0){ // Facing left?
			MDir = 1;
		} else{ 
			MDir = 0;
		}
	}

	if(target==NULL())
	{
		setidle(self);//Target lost.Normally it's impossible!
	}else{
		int dir = getentityproperty(target,"direction"); //Get opponent's facing direction
		if(dir==0){ // Facing left?
			x = -x;
		}
		damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL")); 
		tossentity(target, y, x, z); // Toss opponent ;)
		changeentityproperty(target, "direction", MDir);
		//changeentityproperty(target, "health", 100);
	}
}


void throw(int Damage, int x, int y, int z, int Face)
{ // Damage as throw finisher
	void self = getlocalvar("self");
	void target = getlocalvar("Target" + self);
	int SDir = getentityproperty(target,"direction");
	int MDir;

	if(Face==0){ // Same facing?
		MDir = SDir;
	}

	if(Face==1){ // Opposite facing?
		if(SDir==0){ // Facing left?
			MDir = 1;
		} else { MDir = 0;}
	}

	if(target==NULL())
	{
		setidle(self);
	}else{
		int dir = getentityproperty(target,"direction"); //Get opponent's facing direction
		if(dir==0){ // Facing left?
		x = -x;
	}
	damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL")); // 1st throw type
	changeentityproperty(target, "attacking", 1);
	changeentityproperty(target, "damage_on_landing", Damage);
	changeentityproperty(target, "projectile", 1);
	changeentityproperty(target, "direction", MDir);
	tossentity(target, y, x, z); // Toss opponent ;)
   }
}

void antiWall(int Dist, int Move, int Distz)
{
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if (Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);

   if(Hz > 0)
   {
     changeentityproperty(self, "position", x, z-Distz);
   }

   if(H > 0)
   {
     changeentityproperty(self, "position", x+Move);
   }
}

void hurt(int damage)
{ 
	hurt2(damage,0);
}

void hurt2(int damage,int is_live)
{
	void self = getlocalvar("self");
	void target = getlocalvar("Target" + self);
	
	float x,z;
	x=getentityproperty(self,"x");
	z=getentityproperty(self,"z");
	if (checkhole(x,z)){
		depost(0);
		clearSlam();
		return;
	}
	x=getentityproperty(target,"x");
	z=getentityproperty(target,"z");
	if (checkhole(x,z)){
		depost(0);
		clearSlam();
		return;
	}

	if(target!=NULL()){
		int damage2;
		int THealth = getentityproperty(target,"health");
		int TAniPos = getentityproperty(target,"animpos");
		if (is_live==1){
			if(THealth > damage){
				damage2=damage;
			}else{
				damage2 = THealth - 1;
			}
		}else{
			damage2=damage;
		}
		damageentity(target, self, damage2, 1, openborconstant("ATK_NORMAL7"));
		updateframe(target, TAniPos);
	}
}
