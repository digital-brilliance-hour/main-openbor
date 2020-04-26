#include "data/scripts/common/commons.c"
void target(float Velx, float Velz, float dx, float dz, int Stop)
{// Targetting opponent before leaping or dashing.
// Velx = x Velocity
// Velz = z Velocity
// dx = x added distance
// dz = z added distance
// Stop = flag to stop moving if no target is found

    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    if (dir == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
    }

    setlocalvar("T"+self, findtarget(self)); //Get nearest player

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
      float Disx = Tx - x;
      float Disz = Tz - z;

//Set both distance as positive value
      if(Disx < 0){
        Disx = -Disx;
      }

      if(Disz < 0){
        Disz = -Disz;
      }

// Calculate velocity for targetting
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
      if(Stop == 1)
      {
        setlocalvar("z"+self, 0);
        setlocalvar("x"+self, 0);
      } else {
        setlocalvar("z"+self, 0);
        if(dir==0){
          setlocalvar("x"+self, -Velx);
        } else { setlocalvar("x"+self, Velx); }
      }
    }
}


void targetL(float Vy, float dx, float dz)
{
	void self = getlocalvar("self");
	void target=findtarget(self);

	int dir = getentityproperty(self, "direction");
	float x = getentityproperty(self, "x");
	float z = getentityproperty(self, "z");
	if (dir == 0){
		dx = -dx;
	}else{}
	
	if( target != NULL()){
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
}

void dash()
{
    void self = getlocalvar("self");
    float Vx = getlocalvar("x"+self);
    float Vz = getlocalvar("z"+self);
    if( Vx!=NULL() && Vz!=NULL() ){
      changeentityproperty(self, "velocity", Vx, Vz);
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
