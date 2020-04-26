void velo001(float fX, float fZ, float fY){
	void vSelf = getlocalvar("self"); 
	if (getentityproperty(vSelf, "direction")==0){                  
		fX = -fX; 
	}changeentityproperty(vSelf, "velocity", fX, fZ, fY);
}void shoot(void Shot, float dx, float dy, float dz){
	void self = getlocalvar("self");
	int Direction = getentityproperty(self, "direction");
	int x = getentityproperty(self, "x");
	int y = getentityproperty(self, "a");
	int z = getentityproperty(self, "z");
	if (Direction == 0){            
		dx = -dx; 
	}projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
}void toss(void Bomb, float dx, float dy, float dz){
	void self = getlocalvar("self");
	int Direction = getentityproperty(self, "direction");
	int x = getentityproperty(self, "x");
	int y = getentityproperty(self, "a");
	int z = getentityproperty(self, "z");
	if (Direction == 0){           
		dx = -dx;
	}projectile(Bomb, x+dx, z+dz, y+dy, Direction, 0, 1, 0);
}void antiwall(int Dist, int Move, int Distz){
	void self = getlocalvar("self");
	int Direction = getentityproperty(self, "direction");
	int x = getentityproperty(self, "x");
	int z = getentityproperty(self, "z");
	float H;
	float Hz;
	if (Direction == 0){          
		Dist = -Dist;
		Move = -Move;
	}
	H = checkwall(x+Dist,z);
	Hz = checkwall(x+Dist,z+Distz);
	if(Hz > 0){
		changeentityproperty(self, "position", x, z-Distz);
	}if(H > 0){
		changeentityproperty(self, "position", x+Move, z);
	}
}void death(){
	void vSelf = getlocalvar("self"); 
	float fY = getentityproperty(vSelf, "a");
	if (fY > 1){
		changeentityproperty(vSelf, "animation", openborconstant("ANI_DIE3"));
	}
}void anti(){
	void self = getlocalvar("self");
	void target = getlocalvar("Target" + self);
	if(target==NULL()){
		bindentity(target, self, 0, 0, 0, 0, 0);
	}if(target!=NULL()){
		bindentity(target, NULL());
	}
}void hurt(int Damage, int AtNumber){
	void self = getlocalvar("self");
	void target = getlocalvar("Target" + self);
	if(target==NULL()){
		target = getentityproperty(self, "grabbing");
		setlocalvar("Target" + self, target);
	}
	if(target!=NULL()){
		if(AtNumber==0){
			damageentity(target, self, Damage, 0, openborconstant("ATK_NORMAL6")); 
		}if(AtNumber==1){
			damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL6")); 
		}if(AtNumber==7){
			damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL7")); 
		}if(AtNumber==8){
			damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL8"));
		}
	}
}void finish(int Damage, int Type, int x, int y, int z, int Face){
	void self = getlocalvar("self");
	void target = getlocalvar("Target" + self);
	int SDir = getentityproperty(target,"direction");
	int MDir;
	if(Face==0){
		MDir = SDir;
	}if(Face==1){
		if(SDir==0){ 
			MDir = 1;
		} else { MDir = 0;}
	}if(target==NULL()){
		target = getentityproperty(self, "grabbing");
		setlocalvar("Target" + self, target);
	}if(target!=NULL()){
		int dir = getentityproperty(target,"direction");
		if(dir==0){
			x = -x;
		}if(Type==0){
			damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL6")); 
		}if(Type==1){
			damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL6")); 
		}if(Type==2){
			damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL2")); 
		}if(Type==3){
			damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL3")); 
		}
		changeentityproperty(target, "direction", MDir);
		tossentity(target, y, x, z);
	}
}void depost(int Gr){
	void self = getlocalvar("self");
	void target = getlocalvar("Target" + self);
	if(target==NULL()){
		target = getentityproperty(self, "grabbing");
		setlocalvar("Target" + self, target);
	}if(target!=NULL()){
		bindentity(target, NULL());
		if(Gr == 1){
			int x = getentityproperty(target, "x");
			int z = getentityproperty(target, "z");
			changeentityproperty(target, "position", x, z, 0);
		}
	}
}void position(int Frame, float dx, float dy, float dz, int face){
	void self = getlocalvar("self");
	void target = getlocalvar("Target" + self);
	if(target==NULL()){
		target = getentityproperty(self, "grabbing");
		setlocalvar("Target" + self, target);
	}if(target!=NULL()){
		updateframe(target, Frame);
		bindentity(target, self, dx, dz, dy, face, 0);
	}
}void grabcheck(){
	void self = getlocalvar("self");
	void target = getentityproperty(self, "grabbing");
	if(target==NULL()){
		performattack(self, openborconstant("ANI_ATTACK2")); 
	}
}void ani001(void vAni, int iFrame){
	void vSelf = getlocalvar("self"); 
	changeentityproperty(vSelf, "animation", openborconstant(vAni)); 
	changeentityproperty(vSelf, "animpos", iFrame); 
}void clearL(){
	clearlocalvar();
}void targetL(float Vy, float dx, float dz){
	void self = getlocalvar("self");
	int dir = getentityproperty(self, "direction");
	float x = getentityproperty(self, "x");
	float z = getentityproperty(self, "z");
	if (dir == 0){
		dx = -dx;
	}
	setlocalvar("T"+self, findtarget(self));
	if( getlocalvar("T"+self) != NULL()){
		void target = getlocalvar("T"+self);
		float Tx = getentityproperty(target, "x");
		float Tz = getentityproperty(target, "z");
		if(Tx < x){
			changeentityproperty(self, "direction", 0);
		} else {
			changeentityproperty(self, "direction", 1);
		}
		x = x+dx;
		z = z+dz;
		setlocalvar("x"+self, (Tx-x)/(22*Vy));
		setlocalvar("z"+self, (Tz-z)/(22*Vy));
	} else {
		setlocalvar("z"+self, 0);
		setlocalvar("x"+self, 0);
	}
}void leap(float Vely){
	void self = getlocalvar("self");
	float Vx = getlocalvar("x"+self);
	float Vz = getlocalvar("z"+self);
	if( Vx!=NULL() && Vz!=NULL() ){
		tossentity(self, Vely, Vx, Vz);
	}
}void teletarget(int dx, int dy, int dz){
	void self = getlocalvar("self");
	int dir = getentityproperty(self, "direction");
	if(dir==0){
		dx = -dx ;
	}
	setlocalvar("T"+self, findtarget(self));
	if( getlocalvar("T"+self) != NULL()){
		void target = getlocalvar("T"+self);
		int Tx = getentityproperty(target, "x");
		int Tz = getentityproperty(target, "z");
		changeentityproperty(self, "position", Tx+dx, Tz+dz, dy); 
	} 
}void target(float Velx, float Velz){
	void self = getlocalvar("self");
	int dir = getentityproperty(self, "direction");
	float x = getentityproperty(self, "x");
	float z = getentityproperty(self, "z");
	setlocalvar("T"+self, findtarget(self));
	if( getlocalvar("T"+self) != NULL()){
		void target = getlocalvar("T"+self);
		float Tx = getentityproperty(target, "x");
		float Tz = getentityproperty(target, "z");
		float Disx = Tx - x;
		float Disz = Tz - z;
		if(Disx < 0){
			Disx = -Disx;
			changeentityproperty(self, "direction", 0);
		} else {
			changeentityproperty(self, "direction", 1);
		}
		if(Disz < 0){
			Disz = -Disz;
		}
		if(Disz < Disx)
		{
			if(Tx < x){
				setlocalvar("x"+self, -Velx);
			} else { setlocalvar("x"+self, Velx); }
			setlocalvar("z"+self, Velx*(Tz-z)/Disx);
		} else {
			if(Tz < z){
				setlocalvar("z"+self, -Velz);
			} else { setlocalvar("z"+self, Velz); }
			setlocalvar("x"+self, Velz*(Tx-x)/Disz);
		}
	} else {
		setlocalvar("z"+self, 0);
		if(dir==0){
			setlocalvar("x"+self, -Velx);
		} else { setlocalvar("x"+self, Velx); }
	}
}void spawn01(void vName, float fX, float fY, float fZ){
	void self = getlocalvar("self");
	void vSpawn;
	int  iDirection = getentityproperty(self, "direction");
	clearspawnentry(); 
	setspawnentry("name", vName); 
	if (iDirection == 0){
		fX = -fX;
	}fX = fX + getentityproperty(self, "x");
	fY = fY + getentityproperty(self, "a");
	fZ = fZ + getentityproperty(self, "z");
	vSpawn = spawn();
	changeentityproperty(vSpawn, "position", fX, fZ, fY); 
	changeentityproperty(vSpawn, "direction", iDirection); 
	return vSpawn; 
}void flipdir(){
	void self = getlocalvar("self");
	changeentityproperty(self, "direction", !getentityproperty(self, "direction"));
}void hurt3(int Damage, int set){
	void self = getlocalvar("self");
	if(set==0){
		void target = getlocalvar("Target" + self);
		if(target==NULL()){
			target = getentityproperty(self, "grabbing");
			setlocalvar("Target" + self, target);
		}if(target!=NULL()){
			void THealth = getentityproperty(target,"health"); 
			changeentityproperty(target, "health", THealth - Damage); 
		}
	}else if(set==1){
		void SHealth = getentityproperty(self,"health"); 
		changeentityproperty(self, "health", SHealth + Damage);
	}
}
