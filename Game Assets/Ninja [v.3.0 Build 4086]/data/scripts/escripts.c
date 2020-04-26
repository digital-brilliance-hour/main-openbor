void degravity(int Ratio)
{// Changes antigravity effect
    void self = getlocalvar("self");
    changeentityproperty(self, "antigravity", Ratio);
}

void dasher( float Vx, float Vy, float Vz )
{// Dash with desired speed!
    void self = getlocalvar("self");
    int dir = getentityproperty(self,"direction");

    if(dir==0){ // Facing left?
      Vx = -Vx ;
    }

    changeentityproperty(self, "velocity", Vx, Vz, Vy); //Move!
}

void stop()
{// Stop enemy's movement!
    void self = getlocalvar("self");
    changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
}

void KazuyaRandom()
{
    int SFX1 = loadsample("data/sounds/kmatk1.wav");
    int SFX2 = loadsample("data/sounds/kmatk2.wav");
    int SFX3 = loadsample("data/sounds/kmatk3.wav");
    int SFX4 = loadsample("data/sounds/kmatk4.wav");
    int i = rand()%2 + 2; // i is now a random number between 0 and 4, inclusive
    if (i == 0) // sound is played if i=3
    {
       playsample(SFX1, 0, 120, 120, 100, 0);
    }
    else if (i == 1) // this sound is played if i=4
    {
       playsample(SFX2, 0, 120, 120, 100, 0);
    }
    else if (i == 2) // this sound is played if i=4
    {
       playsample(SFX3, 0, 120, 120, 100, 0);
    }
    else if (i == 3) // this sound is played if i=4
    {
       playsample(SFX4, 0, 120, 120, 100, 0);
    }
    // if i=4, no sound is played at all
}

void teletarget(int dx, int dy, int dz)
{// Targetting opponent then teleport to target
    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction");

    if(dir==0){ // Facing left?
      dx = -dx ;
    }

    setlocalvar("T"+self, findtarget(self)); //Get nearest player

    if( getlocalvar("T"+self) != NULL()){
      void target = getlocalvar("T"+self);
      int Tx = getentityproperty(target, "x");
      int Tz = getentityproperty(target, "z");

      changeentityproperty(self, "position", Tx+dx, Tz+dz, dy); //Teleport to target!
    } 
}


void bind(int null, float x, float y, float z, int dir){
	void self = getlocalvar("self");
	void opp = getentityproperty(self, "opponent");
	if(null == 1)
	{
		bindentity(opp, self, x, y, z, dir, 0);
	}
	else if(null == 0)
	{
		bindentity(opp, NULL());
	}
}

void forceanim(int anim){
	void self = getlocalvar("self");
	void opp = getentityproperty(self, "opponent");
	changeentityproperty(opp, "animation", anim);

}
