//Library scripts for basic functions

void layer(int layer)
{// Set's enemy's layer
    void self = getlocalvar("self");
    changeentityproperty(self, "setlayer", layer);
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

void suicide()
{ // Suicide!!
    void self = getlocalvar("self");

    killentity(self); //Suicide!
}

void degravity(int Ratio)
{// Changes antigravity effect
    void self = getlocalvar("self");
    changeentityproperty(self, "antigravity", Ratio);
}

void move(int dx, int dz, int da)
{ // Moves entity freely or ignores obstacles
    void self = getlocalvar("self");
    int x = getentityproperty(self,"x"); //Get character's x coordinate
    int z = getentityproperty(self,"z"); //Get character's z coordinate
    int a = getentityproperty(self,"a"); //Get character's a coordinate
    int dir = getentityproperty(self,"direction"); //Get character's facing direction

     if(dir==0){ // Facing left?
      changeentityproperty(self, "position", x-dx, z+dz, a+da); //Move
     }
     else if(dir==1){ // Facing right?
      changeentityproperty(self, "position", x+dx, z+dz, a+da); //Move
     }
}

void clearL()
{ // Clears all local variables
     clearlocalvar();
}

void floater( int Time )
{// Floats in Time centiseconds
    void self = getlocalvar("self");
    int eTime = openborvariant("elapsed_time");

    changeentityproperty(self, "tosstime", eTime + Time*2);
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
      setlocalvar("Loop" + self, loop+1); // Increment number of loops
      updateframe(self, Frame); //Change frame
    } else if(loop==Limit){ // loops reach limit?
      setlocalvar("Loop" + self, NULL());
    }
}

void flip()
{// Turns around
    void self = getlocalvar("self");
    int Direction = getentityproperty(self, "direction");

    if (Direction == 0){ //Is entity facing left?                  
      changeentityproperty(self, "direction", 1);
    } else {
      changeentityproperty(self, "direction", 0);
    }
}

void beidle()
{// Go to IDLE animation!
    void self = getlocalvar("self");

    setidle(self, openborconstant("ANI_IDLE"));
}

void stealth(int Value)
{ // Change stealth value
   void self = getlocalvar("self");

   changeentityproperty(self, "stealth", Value);
}

void block(int Flag)
{// Turns blocking status
    void self = getlocalvar("self");
    changeentityproperty(self, "aiflag", "blocking", Flag);
}

void attack0(void Ani)
{// Attack interruption
    void self = getlocalvar("self");

    performattack(self, openborconstant(Ani)); //Attack!
}

void attack1(int RxMin, int RxMax, int Rz, void Ani)
{// Attack interruption with range check
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    int dir = getentityproperty(self, "direction");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx >= RxMin && Disx <= RxMax && Disz <= Rz && dir == 1) // Target within range on right facing?
      {
        performattack(self, openborconstant(Ani)); //Change the animation
      } else if( Disx >= -RxMax && Disx <= -RxMin && Disz <= Rz && dir == 0) // Target within range on left facing?
      {
        performattack(self, openborconstant(Ani)); //Change the animation
      }
    }
}
