void velo001(float fX, float fZ, float fY)
{
	void vSelf = getlocalvar("self"); 
	if (getentityproperty(vSelf, "direction")==0)
	{
	fX = -fX; 
	}
	changeentityproperty(vSelf, "velocity", fX, fZ, fY);
}

void shoot(void Shot, float dx, float dy, float dz)
{
	void self = getlocalvar("self");
	int Direction = getentityproperty(self, "direction");
	int x = getentityproperty(self, "x");
	int y = getentityproperty(self, "a");
	int z = getentityproperty(self, "z");
	int Map = getentityproperty(self, "map");
	if (Direction == 0)
		{
		dx = -dx;
		}
	projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 0, Map);
}

void toss(void Bomb, float dx, float dy, float dz)
{ 
	void self = getlocalvar("self");
	int Direction = getentityproperty(self, "direction");
	int x = getentityproperty(self, "x");
	int y = getentityproperty(self, "a");
	int z = getentityproperty(self, "z");
	int Map = getentityproperty(self, "map");
	if (Direction == 0)
		{
		dx = -dx;
		}
	projectile(Bomb, x+dx, z+dz, y+dy, Direction, 0, 1, Map);
}

void antiwall(int Dist, int Move, int Distz)
{
	void self = getlocalvar("self");
	int Direction = getentityproperty(self, "direction");
	int x = getentityproperty(self, "x");
	int z = getentityproperty(self, "z");
	float H;
	float Hz;
	if (Direction == 0)
		{
		Dist = -Dist; 
		Move = -Move; 
		}
	H = checkwall(x+Dist,z);
	Hz = checkwall(x+Dist,z+Distz);
	if(Hz > 0)
		{
		changeentityproperty(self, "position", x, z-Distz);
		}
		if(H > 0)
		{
		changeentityproperty(self, "position", x+Move, z);
		}
}

void death()
{
	void vSelf = getlocalvar("self"); 
	float fY = getentityproperty(vSelf, "a"); 
	if (fY > 1)
	{
	changeentityproperty(vSelf, "animation", openborconstant("ANI_DIE3"));
	}
}
