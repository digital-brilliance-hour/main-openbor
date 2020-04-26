void flip()
{
	void self=getlocalvar("self");
	changeentityproperty(self,"direction", !getentityproperty(self,"direction")); 
}

void looper(int Frame, int Limit)
{// Loops current animation
    void self = getlocalvar("self");
    void loop = getlocalvar("Loop" + self);

    if(loop==NULL()){ // Localvar empty?
      setlocalvar("Loop" + self, 0);
      loop = 0;
    } 
   
    if(loop < Limit){ // loops reach limit?
		updateframe(self, Frame); //Change frame
		setlocalvar("Loop" + self, loop+1); // Increment number of loops
	}
}

void changeAni(char ani)
{
	void self = getlocalvar("self");
	changeentityproperty(self, "animation", openborconstant(ani));
	//changeentityproperty(self, "animpos", 0);
}

void clearL()
{ // Clears all local variables Except the counter,for chainBreak
	int etime=getlocalvar("etime");
	int c = getlocalvar("lcounter");
	clearlocalvar();
	setlocalvar("lcounter",c);
	setlocalvar("etime",etime);
}
void beidle()
{// Go to IDLE animation!
    void self = getlocalvar("self");
    setidle(self);
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

void leaper( float Vx, float Vy, float Vz )
{// Leap with desired speed!
    void self = getlocalvar("self");
    int dir = getentityproperty(self,"direction");
    if(dir==0){ // Facing left?
      Vx = -Vx ;
    }
    tossentity(self, Vy, Vx, Vz); //Leap!
}

void stop()
{// Stop enemy's movement!
    void self = getlocalvar("self");
    changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
}


