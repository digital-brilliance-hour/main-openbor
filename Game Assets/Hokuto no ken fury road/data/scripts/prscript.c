//Script for player's and enemy's projectiles
//Also used by entities with simple effects

#include "data/scripts/library/spawn.h"
#include "data/scripts/library/basic.h"

void dirspeed()
{ // Match facing direction with x velocity
    void self = getlocalvar("self");
    float Vx = getentityproperty(self, "xdir");

    if (Vx < 0){
      changeentityproperty(self, "direction", 0); //Face left!
    } else if (Vx > 0){
      changeentityproperty(self, "direction", 1); //Face right!
    }
}

void groundkill()
{// Check altitude. If projectile is on ground, suicide!
    void self = getlocalvar("self");
    int x = getentityproperty(self,"x");
    int z = getentityproperty(self,"z");
    int y = getentityproperty(self,"a");

    int H = checkhole(x,z,y-100);

    if( y <= 1 && H != 1){ // On ground but not on hole?
      killentity(self); //Suicide!
    }
}

void groundchange(void Ani)
{// Check altitude. If projectile is on ground, change animation!
    void self = getlocalvar("self");
    int x = getentityproperty(self,"x");
    int z = getentityproperty(self,"z");
    int y = getentityproperty(self,"a");

    int H = checkhole(x,z,y-100);

    if( y <= 1 && H != 1){ // On ground but not on hole?
      changeentityproperty(self, "animation", openborconstant(Ani));
    }
}

void basechange(void Ani)
{// Check altitude. If bomb is on base, change animation!

    void self = getlocalvar("self");
    int y = getentityproperty(self,"a"); //Get bomb's altitude
    int b = getentityproperty(self, "base"); //Get base

    if( y <= 1+b ){ // On base?
      performattack(self, openborconstant(Ani)); //Change the animation
    }
}

void attack0(void Ani)
{// Attack interruption
    void self = getlocalvar("self");

    performattack(self, openborconstant(Ani)); //Attack!
}

void givescore(int Add)
{// Gives parent score
    void self = getlocalvar("self");
    void target = getentityproperty(self, "opponent");

    if(target!=NULL()){
      void Def = getentityvar(target, 7);

      if(Def!=1){
        void Parent = getentityproperty(self,"parent");
        int iPIndex = getentityproperty(Parent,"playerindex");
        int PScore = getplayerproperty(iPIndex, "score");

        changeplayerproperty(iPIndex, "score", PScore+Add);
      }
    }
}

void shooterX(void Shot, float dx, float dy, float Vx, float Vy, int Dir)
{ // Shooting special projectile with speed and direction
//Projectile's direction is adjusted to current direction and current remap

   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int Map = getentityproperty(self, "map");
   void vShot;
   int JDir;

   if (Direction == 0){ //Is entity facing left?                  
     Vx = -Vx; //Reverse Vx direction to match facing
   }

   if (Dir == 0){                 
     JDir = Direction;
   } else if (Dir == 1){
     if (Direction == 0){                 
       JDir = 1;
     } else { JDir = 0; }
   }

   vShot = shooter(Shot, dx, dy, Vx, Vy);
   changeentityproperty(vShot, "direction", JDir);
   changeentityproperty(vShot, "map", Map);
}

void revolver( float Ax, float Ay, int C )
{// Revolve with speed change
// For none type
    void self = getlocalvar("self");
    float Vx = getentityproperty(self,"xdir");
    float Vy = getentityproperty(self,"tossv");
    float Nx;
    float Ny;

    if( C==0 ){
      if(Vx > 0 && Vy == 0){
        Nx = Vx + Ax;
        Ny = 2*Vx + Ay;
      } else if(Vx > 0 && Vy > 0){
        Nx = 0;
        Ny = Vy + Ay;
      } else if(Vx == 0 && Vy > 0){
        Nx = -0.5*Vy - Ax;
        Ny = Vy + Ay;
      } else if(Vx < 0 && Vy > 0){
        Nx = Vx - Ax;
        Ny = 0;
      } else if(Vx < 0 && Vy == 0){
        Nx = Vx - Ax;
        Ny = 2*Vx - Ay;
      } else if(Vx < 0 && Vy < 0){
        Nx = 0;
        Ny = Vy - Ay;
      } else if(Vx == 0 && Vy < 0){
        Nx = -0.5*Vy + Ax;
        Ny = Vy - Ay;
      } else if(Vx > 0 && Vy < 0){
        Nx = Vx + Ax;
        Ny = 0;
      }
    } else if( C==1 ){
      if(Vx > 0 && Vy == 0){
        Nx = Vx + Ax;
        Ny = -2*Vx - Ay;
      } else if(Vx > 0 && Vy < 0){
        Nx = 0;
        Ny = Vy - Ay;
      } else if(Vx == 0 && Vy < 0){
        Nx = 0.5*Vy - Ax;
        Ny = Vy - Ay;
      } else if(Vx < 0 && Vy < 0){
        Nx = Vx - Ax;
        Ny = 0;
      } else if(Vx < 0 && Vy == 0){
        Nx = Vx - Ax;
        Ny = -2*Vx + Ay;
      } else if(Vx < 0 && Vy > 0){
        Nx = 0;
        Ny = Vy + Ay;
      } else if(Vx == 0 && Vy > 0){
        Nx = 0.5*Vy + Ax;
        Ny = Vy + Ay;
      } else if(Vx > 0 && Vy > 0){
        Nx = Vx + Ax;
        Ny = 0;
      }
    }

    changeentityproperty(self, "velocity", Nx, 0, Ny); //Revolve!
}

void revolverE( float Ax, float Ay, int C )
{// Revolve with speed change
// For enemy type
    void self = getlocalvar("self");
    float Vx = getentityproperty(self,"xdir");
    float Vy = getentityproperty(self,"tossv");
    float Nx;
    float Ny;

    if( C==0 ){
      if(Vx > 0 && Vy == 0){
        Nx = Vx + Ax;
        Ny = Vx + Ay;
      } else if(Vx > 0 && Vy > 0){
        Nx = 0;
        Ny = Vy + Ay;
      } else if(Vx == 0 && Vy > 0){
        Nx = -Vy - Ax;
        Ny = Vy + Ay;
      } else if(Vx < 0 && Vy > 0){
        Nx = Vx - Ax;
        Ny = 0;
      } else if(Vx < 0 && Vy == 0){
        Nx = Vx - Ax;
        Ny = Vx - Ay;
      } else if(Vx < 0 && Vy < 0){
        Nx = 0;
        Ny = Vy - Ay;
      } else if(Vx == 0 && Vy < 0){
        Nx = -Vy + Ax;
        Ny = Vy - Ay;
      } else if(Vx > 0 && Vy < 0){
        Nx = Vx + Ax;
        Ny = 0;
      }
    } else if( C==1 ){
      if(Vx > 0 && Vy == 0){
        Nx = Vx + Ax;
        Ny = -Vx - Ay;
      } else if(Vx > 0 && Vy < 0){
        Nx = 0;
        Ny = Vy - Ay;
      } else if(Vx == 0 && Vy < 0){
        Nx = Vy - Ax;
        Ny = Vy - Ay;
      } else if(Vx < 0 && Vy < 0){
        Nx = Vx - Ax;
        Ny = 0;
      } else if(Vx < 0 && Vy == 0){
        Nx = Vx - Ax;
        Ny = -Vx + Ay;
      } else if(Vx < 0 && Vy > 0){
        Nx = 0;
        Ny = Vy + Ay;
      } else if(Vx == 0 && Vy > 0){
        Nx = Vy + Ax;
        Ny = Vy + Ay;
      } else if(Vx > 0 && Vy > 0){
        Nx = Vx + Ax;
        Ny = 0;
      }
    }

    changeentityproperty(self, "velocity", Nx, 0, Ny); //Revolve!
}
