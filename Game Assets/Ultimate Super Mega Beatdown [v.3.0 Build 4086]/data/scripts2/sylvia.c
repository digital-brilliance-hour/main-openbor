#include "data\scripts\script.c"

void zoom( float Vx, float Vy, float Vz )
{// Dash with desired speed!
    void self = getlocalvar("self");
    int dir = getentityproperty(self,"direction");

    if(dir==0){ // Facing left?
      Vx = -Vx ;
    }

    changeentityproperty(self, "velocity", Vx, Vz, Vy); //Move!
}


void teleport()
{// Dash with desired speed!
    void self = getlocalvar("self");
    changeentityproperty(self, "weapon", 1); 
}

