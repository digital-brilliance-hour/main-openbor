//Library scripts for 3D targetting
#import "data/scripts/library/basic.h"
#import "data/scripts/library/spawn.h"

void target(float Velx, float Velz, float dx, float dz, int Stop, int Flip)
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

      if(Flip == 1){
        if(Tx < x){
          changeentityproperty(self, "direction", 0);
        } else {
          changeentityproperty(self, "direction", 1);
        }
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

    setlocalvar("T"+self, NULL()); //Clears variable
}

void targetL(float Vy, float dx, float dz, int Flip)
{// Targetting opponent before performing targetted leap attack
// Vy = y Velocity
// dx = x added distance
// dz = z added distance

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

      if(Flip == 1){
        if(Tx < x){
          changeentityproperty(self, "direction", 0);
        } else {
          changeentityproperty(self, "direction", 1);
        }
      }

      x = x+dx;
      z = z+dz;
      setlocalvar("x"+self, (Tx-x)/(22*Vy));
      setlocalvar("z"+self, (Tz-z)/(22*Vy));

    } else {
      setlocalvar("z"+self, 0);
      setlocalvar("x"+self, 0);
    }

    setlocalvar("T"+self, NULL()); //Clears variable
}

void targetB(float Vy, float dx, float dy, float dz, int YFlag, int Flip)
{// Targetting opponent before dropping bomb
// Vy = y Velocity
// dx = x added distance
// dy = y added distance
// dz = z added distance

    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction");
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    float z = getentityproperty(self, "z");

    setlocalvar("T"+self, findtarget(self)); //Get nearest player

    if( getlocalvar("T"+self) != NULL()){
      void target = getlocalvar("T"+self);
      float Tx = getentityproperty(target, "x");
      float Ty;
      float Tz = getentityproperty(target, "z");
      float C1;
      float C2;
      float Sy = y + dy - Ty;

      if (YFlag == 1){
        Ty = getentityproperty(target, "a");
      } else {
        Ty = 0;
      }

      if (Sy < 0){ //Negative?
        Sy = -Sy; //Invert to positive
      }

      C1 = 0.5*(x-Tx)*(y+dy-Ty)/(22*Vy+Sy);
      C2 = 0.5*(z-Tz)*(y+dy-Ty)/(22*Vy+Sy);

      if(Flip == 1){
        if(Tx < x){
          changeentityproperty(self, "direction", 0);
        } else {
          changeentityproperty(self, "direction", 1);
        }
      }

      if (dir == 0){ //Is entity facing left? 
        dx = -dx; //Reverse X direction to match facing
      }

      x = x+dx-C1;
      z = z+dz-C2;
      setlocalvar("x"+self, (Tx-x)/(21*Vy));
      setlocalvar("z"+self, (Tz-z)/(21*Vy));

    } else {
      setlocalvar("z"+self, 0);
      setlocalvar("x"+self, 0);
    }

    setlocalvar("T"+self, NULL()); //Clears variable
}

void dash(int X, int Z)
{// Dash with previously attained speed!
    void self = getlocalvar("self");
    float Vx = getlocalvar("x"+self);
    float Vz = getlocalvar("z"+self);

    if( X==1 ){
      Vz = 0;
    } else if( Z==1 ){
      Vx = 0;
    }

    changeentityproperty(self, "velocity", Vx, Vz); //Move towards target!
}

void leap(float Vely)
{// Leap with previously attained speed!
    void self = getlocalvar("self");
    float Vx = getlocalvar("x"+self);
    float Vz = getlocalvar("z"+self);
    if( Vx!=NULL() && Vz!=NULL() ){
      tossentity(self, Vely, Vx, Vz); //Leap towards target!
    }
}

void shootT(void Shot, float dx, float dy, float dz)
{ // Shooting targetted projectile
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float Vx = getlocalvar("x"+self);
   float Vz = getlocalvar("z"+self);
   void vShot;

   if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
   }

   vShot = projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 0, 0);

   if( Vx!=NULL() && Vz!=NULL() ){
     changeentityproperty(vShot, "velocity", Vx, Vz);
     if (Vx < 0 && Direction == 1){ //Is projectile moving back?
       changeentityproperty(vShot, "direction", 0);
     } else if(Vx > 0 && Direction == 0){ //Is projectile moving back?
       changeentityproperty(vShot, "direction", 1);
     }
     if ( Vx < 0 ){ //Is Vx negative?
       Vx = -Vx;
     }
     changeentityproperty(vShot, "speed", Vx);
   }
}

void tossT(void Bomb, float dx, float dy, float dz, float Vy)
{ // Tossing targetted bomb
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float Vx = getlocalvar("x"+self)/2;
   float Vz = getlocalvar("z"+self)/2;
   void vShot;

   if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
   }

   vShot = projectile(Bomb, x+dx, z+dz, y+dy, Direction, 0, 1, 0);

   if( Vx!=NULL() && Vz!=NULL() ){
     tossentity(vShot, Vy, Vx, Vz); //Toss projectile towards target!
     if (Vx < 0 && Direction == 1){ //Is projectile moving back?
       changeentityproperty(vShot, "direction", 0);
     } else if(Vx > 0 && Direction == 0){ //Is projectile moving back?
       changeentityproperty(vShot, "direction", 1);
     }
     if ( Vx < 0 ){ //Is Vx negative?
       Vx = -Vx;
     }
     changeentityproperty(vShot, "speed", Vx);
   }
}

void shoot2T(void vName, float fX, float fY, float fZ, float Vy)
{//Shoot special targetted projectile
 //vName: Model name of entity to be spawned in
 //fX: X location adjustment
 //fZ: Y location adjustment
 //fY: Z location adjustment

   void self = getlocalvar("self"); //Get calling entity
   int Direction = getentityproperty(self, "direction");
   float Vx = getlocalvar("x"+self);
   float Vz = getlocalvar("z"+self);
   if (Direction == 0){ //Is entity facing left?                  
     Vx = -Vx; //Reverse Vx direction to match facing
   }
	
   shooter2(vName, fX, fY, fZ, Vx*0.5, Vy, Vz); //Shoot
}

void targetTele()
{// Target opponent for teleport action

    void self = getlocalvar("self");
    setlocalvar("T"+self, findtarget(self)); //Get nearest player

    if( getlocalvar("T"+self) != NULL()){
      void target = getlocalvar("T"+self);
      float Tx = getentityproperty(target, "x");
      float Ty = getentityproperty(target, "a");
      float Tz = getentityproperty(target, "z");
      setlocalvar("Tx"+self, Tx);
      setlocalvar("Ty"+self, Ty);
      setlocalvar("Tz"+self, Tz);
    }

    setlocalvar("T"+self, NULL()); //Clears variable
}

void Teletarget(float dx, float dy, float dz, int YFlag)
{// Teleport self right at target's position
// dx = x added distance
// dy = y added distance
// dz = z added distance
// YFlag = Flag to control if altitude is taken or not

    void self = getlocalvar("self");
    int Direction = getentityproperty(self, "direction");
    float Tx = getlocalvar("Tx"+self);
    float Ty;
    float Tz = getlocalvar("Tz"+self);
    void vSpawn;

    if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
    }
    if (YFlag == 1){ //Altitude is taken?                  
      Ty = getlocalvar("Ty"+self);
    } else { //Altitude is taken?                  
      Ty = 0;
    }

    if(Tx!= NULL() && Ty!= NULL() && Tz!= NULL()){
      changeentityproperty(self, "position", Tx+dx, Tz+dz, Ty+dy);
    }
}

void spawnT(void Name, float dx, float dy, float dz, int YFlag)
{// Spawn entity right at target's position
// Name = Entity to be spawned
// dx = x added distance
// dy = y added distance
// dz = z added distance
// YFlag = Flag to control if altitude is taken or not

    void self = getlocalvar("self");
    int Direction = getentityproperty(self, "direction");
    float Tx = getlocalvar("Tx"+self);
    float Ty;
    float Tz = getlocalvar("Tz"+self);
    void vSpawn;

    if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
    }
    if (YFlag == 1){ //Altitude is taken?                  
      Ty = getlocalvar("Ty"+self);
    } else { //Altitude is taken?                  
      Ty = 0;
    }

    if(Tx!= NULL() && Ty!= NULL() && Tz!= NULL()){
      vSpawn = spawn01(Name, 0, dy, 0);
      changeentityproperty(vSpawn, "position", Tx+dx, Tz+dz, Ty+dy);
      changeentityproperty(vSpawn, "direction", Direction);
    }
}

void dashX(float X, float Z, float Vy)
{// Dash with previously attained speed + defined speed
    void self = getlocalvar("self");
    int Direction = getentityproperty(self, "direction");
    float Vx;
    float Vz;

    if( X==0 ){
      float Vx = getlocalvar("x"+self);
      Vz = Z;
    } else if( Z==0 ){
      Vx = X;
      float Vz = getlocalvar("z"+self);
    }

    if (Direction == 0){ //Is entity facing left?                  
      Vx = -Vx; //Reverse X direction to match facing
    }

    changeentityproperty(self, "velocity", Vx, Vz, Vy);
}
