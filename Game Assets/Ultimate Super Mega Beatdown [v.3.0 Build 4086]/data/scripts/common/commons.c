void enterAtt(char ani)
{
	void self=getlocalvar("self");
	changeentityproperty(self,"aiflag","idling",0);
	changeentityproperty(self,"aiflag", "attacking", 1);
	changeentityproperty(self,"takeaction", "common_attack_proc");
	changeentityproperty(self,"animation", openborconstant(ani));
}

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

void keyint(void Ani, int Frame, void Key, int Hflag, int Limit)
{// Change current animation if proper key is pressed or released provided HP is more than limit
    void self = getlocalvar("self");
    void Health = getentityproperty(self,"health");    
    int iPIndex = getentityproperty(self,"playerindex"); //Get player index
    void iRKey;

      if (Key=="U"){ //Up Required?
       iRKey = playerkeys(iPIndex, 0, "moveup"); // "Up"
	}

      if (Key=="D"){ //Down Required?
        iRKey = playerkeys(iPIndex, 0, "movedown"); // "Down"
	}

      if (Key=="J"){ //Jump Required?
        iRKey = playerkeys(iPIndex, 0, "jump"); // "Jump"
	}

      if (Key=="A"){ //Attack Required?
        iRKey = playerkeys(iPIndex, 0, "attack"); // "Attack"
	}

      if (Key=="S"){ //Special Required?
        iRKey = playerkeys(iPIndex, 0, "special"); // "Special"
	}

      if (Key=="A2"){ //Attack2 Required?
        iRKey = playerkeys(iPIndex, 0, "attack2"); // "Attack2"
	}

      if (Key=="UJ"){ //Up and Jump Required?
        iRKey = playerkeys(iPIndex, 0, "moveup", "jump"); // "Up" + "Jump"
	}

      if (Hflag==1){ //Not holding the button case?
        iRKey = !iRKey; //Take the opposite condition
	}

      if ((Health > Limit)&&iRKey){
        changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
        changeentityproperty(self, "animpos", Frame);

        if (Key=="UJ"){ 
          // This is copy of dethrown
          changeentityproperty(self, "attacking", 0);
          changeentityproperty(self, "damage_on_landing", 0);
          changeentityproperty(self, "projectile", 0);
        }
      }
}
