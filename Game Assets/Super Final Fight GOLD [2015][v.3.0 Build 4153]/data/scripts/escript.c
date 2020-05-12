
void nograb(int Flag)
{// Turns grabbable status
    void self = getlocalvar("self");
    changeentityproperty(self, "nograb", Flag);
}

void block(int Flag)
{// Turns blocking status
    void self = getlocalvar("self");
    changeentityproperty(self, "aiflag", "blocking", Flag);
}

void hurt2(int Damage)
{ // Damage without altering opponent's animation + less damage if opponent has less health
// Mainly used for slams
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     void THealth = getentityproperty(target,"health"); //Get target's health
     if(THealth > Damage)
     {
       changeentityproperty(target, "health", THealth - Damage); //Damage target with desired damage
     } else {
       changeentityproperty(target, "health", 1); //Damage target with less damage
     }
   }
}

void anichange(void Ani)
{ // Animation changer
    void self = getlocalvar("self");

    changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
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

void grabcheck()
{// Prevents enemy from performing the slam if he/she's not grabbing anyone
   void self = getlocalvar("self");
   void target = getentityproperty(self, "grabbing");

   if(target==NULL())
   {
//     setidle(self); //Don't perform the slam.
     performattack(self, openborconstant("ANI_IDLE")); //Don't perform the slam.
   }
}

void grabcheck2()
{// Prevents enemy from performing the slam if he/she doesn't have any target
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     performattack(self, openborconstant("ANI_IDLE")); //Don't perform the slam.
   }
}


void slamstart() // Slam Starter for Cody/Guy grabbackward
{ // Slam Starter
// Use finish after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL4")); // Slam Starter
   }
}

void slamstart2() // Slam Starter for haggar grabbackward
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL5")); // Slam Starter
   }
}

void slamstart3() // Slam Starter for haggar grabforward
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL6")); // Slam Starter
   }
}

void slamstart4() // Slam Starter for haggar grabup/grabdown
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL7")); // Slam Starter
   }
}

void slamstart5() // Slam Starter for haggar special throws
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL8")); // Slam Starter
   }
}

void slamstart6() // Slam Starter for dean grabbackward/grabdown
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL9")); // Slam Starter
   }
}

void slamstart7() // Slam Starter for dean grabforward/grabup
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL10")); // Slam Starter
   }
}

void position(int Frame, float dx, float dy, float dz, int face)
{ // Modify grabbed entity's position relative to grabber
// Use slamstart 1st before using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     updateframe(target, Frame);
     bindentity(target, self, dx, dz, dy, face, 0);
   }
}

void depost(int Gr)
{// Release grabbed entity
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     bindentity(target, NULL());

     if(Gr == 1)
     {
       int x = getentityproperty(target, "x");
       int z = getentityproperty(target, "z");
       changeentityproperty(target, "position", x, z, 0);
     }
   }
}

void antiwall(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if (Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);

   if(Hz > 0)
   {
     changeentityproperty(self, "position", x, z-Distz);
   }

   if(H > 0)
   {
     changeentityproperty(self, "position", x+Move);
   }
}

void finish(int Damage, int Type, int x, int y, int z, int Face)
{ // Damage as slam finisher
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);
   int SDir = getentityproperty(target,"direction");
   int MDir;

   if(Face==0){ // Same facing?
       MDir = SDir;
   }

   if(Face==1){ // Opposite facing?

     if(SDir==0){ // Facing left?
       MDir = 1;
     } else { MDir = 0;}
   }

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int dir = getentityproperty(target,"direction"); //Get opponent's facing direction
     if(dir==0){ // Facing left?
       x = -x;
     }

     if(Type==1)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL")); // 1st Finisher
     }

     if(Type==2)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL2")); // 2nd Finisher
     }

     tossentity(target, y, x, z); // Toss opponent ;)
     changeentityproperty(target, "direction", MDir);
   }
}

void throw(int Damage, int Type, int Vx, int Vy, int Vz, int Face)
{ // Damage as throw finisher
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);
   int z = getentityproperty(self,"z");
   int SDir = getentityproperty(target,"direction");
   int MDir;

   if(Face==0){ // Same facing?
       MDir = SDir;
   }

   if(Face==1){ // Opposite facing?

     if(SDir==0){ // Facing left?
       MDir = 1;
     } else { MDir = 0;}
   }

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int dir = getentityproperty(target,"direction"); //Get opponent's facing direction
     if(dir==0){ // Facing left?
       Vx = -Vx;
     }

     if(Type==1)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL")); // 1st throw type
     }

     if(Type==2)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL2")); // 2nd throw type
     }

     if(Type==3)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL3")); // 3rd throw type
     }

     changeentityproperty(target, "attacking", 1);
     changeentityproperty(target, "damage_on_landing", Damage);
     changeentityproperty(target, "projectile", 1);
     changeentityproperty(target, "direction", MDir);

     if(z > (openborconstant("PLAYER_MIN_Z") + openborconstant("PLAYER_MAX_Z")) / 2 ) {
       Vz = -Vz ;
     }

     tossentity(target, Vy, Vx, Vz); // Toss opponent ;)
   }
}

void move(int dx, int dz,int da)
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

void changemap(int iMap)
{// Change remap
    void self = getlocalvar("self");

    changeentityproperty(self, "map", iMap); //Change remap
}

void degravity(int Ratio)
{// Changes antigravity effect
    void self = getlocalvar("self");
    changeentityproperty(self, "antigravity", Ratio);
}

void thrown()
{// Sets thrown status
    void self = getlocalvar("self");
    void Health = getentityproperty(self,"health"); //Get enemy's health

    if(Health > 0){
      changeentityproperty(self, "attacking", 1);
      changeentityproperty(self, "projectile", 1);
    } else {
      changeentityproperty(self, "animation", openborconstant("ANI_FALL")); //Use normal fall
    }
}

void dethrown()
{// Disables thrown status
    void self = getlocalvar("self");

    changeentityproperty(self, "attacking", 0);
    changeentityproperty(self, "damage_on_landing", 0);
    changeentityproperty(self, "projectile", 0);
}

void land()
{// Lands with land animation
    void self = getlocalvar("self");
    void Health = getentityproperty(self,"health"); //Get enemy's health
    int LandId = openborconstant("ANI_LAND");

    if(Health > 0){
      performattack(self, LandId);
    } else {
      damageentity(self, self, 1000, 1, openborconstant("ATK_NORMAL")); // Suicide
    }
}

void clearL()
{ // Clears all local variables
     clearlocalvar();
}

void slammed(int Damage)
{ // Hurt self
    void self = getlocalvar("self");
    void Health = getentityproperty(self,"health"); //Get entity's health
    if(Health >= Damage){
      damageentity(self, self, Damage, 1, openborconstant("ATK_NORMAL2")); // Damage is inserted here
    } else if(Health > 0 && Health < Damage){
      damageentity(self, self, Health, 1, openborconstant("ATK_NORMAL2")); // Damage self to death
    } 
    tossentity(self, 2, 0, 0);
}

void spawn01(void vName, float fX, float fY, float fZ)
{
	//spawn01 (Generic spawner)
	//Damon Vaughn Caskey
	//07/06/2007
	//
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
      //fY: Z location adjustment.

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iDirection = getentityproperty(self, "direction");

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

	if (iDirection == 0){ //Is entity facing left?                  
          fX = -fX; //Reverse X direction to match facing.
	}

      fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
      fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
      fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.
	
	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.
    
	return vSpawn; //Return spawn.
}

void spawner(void vName, float fX, float fY, float fZ)
{	//Spawns entity next to caller and set them as child.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
      //fY: Z location adjustment.

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	
	vSpawn = spawn01(vName, fX, fY, fZ); //Spawn in entity.

	changeentityproperty(vSpawn, "parent", self); //Set caller as parent.
    
	return vSpawn; //Return spawn.
}

void spawner2(void vName, float fX, float fY, float fZ)
{//Spawns entity next to caller with same remap as spawner's.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
      //fY: Z location adjustment.

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iMap = getentityproperty(self, "map");
	
	vSpawn = spawn01(vName, fX, fY, fZ); //Spawn in entity.

	changeentityproperty(vSpawn, "map", iMap); //Use same remap as spawner's.
    
	return vSpawn; //Return spawn.
}

void shoot(void Shot, float dx, float dy, float dz)
{ // Shooting projectile
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");

   if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
   }

   projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
}

void shoot2(void Shot, float dx, float dy, float dz)
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
     changeentityproperty(vShot, "velocity", Vx, Vz); //Move projectile towards target!
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

void toss(void Bomb, float dx, float dy, float dz)
{ // Tossing bomb
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");

   if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
   }

   projectile(Bomb, x+dx, z+dz, y+dy, Direction, 0, 1, 0);
}

void toss2(void Bomb, float dx, float dy, float dz, float Vy)
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

void tosser(void Bomb, float dx, float dy, float dz, float Vx, float Vy, float Vz)
{ // Tossing bomb with desired speed
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   void Shot;

   if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
   }

   Shot = projectile(Bomb, x+dx, z+dz, y+dy, Direction, 0, 1, 0);
   tossentity(Shot, Vy, Vx, Vz);
   changeentityproperty(Shot, "speed", Vx); 
}

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
{// Dash with previously attained speed!
    void self = getlocalvar("self");
    float Vx = getlocalvar("x"+self);
    float Vz = getlocalvar("z"+self);
    if( Vx!=NULL() && Vz!=NULL() ){
      changeentityproperty(self, "velocity", Vx, Vz); //Move towards target!
    }
}

void dash2(float Vy)
{// Dash with previously attained speed + flying speed
// Used by Jetpacks to prevent diving to ground and to fly back up
    void self = getlocalvar("self");
    float Vx = getlocalvar("x"+self);
    float Vz = getlocalvar("z"+self);
    if( Vx!=NULL() && Vz!=NULL() ){
      changeentityproperty(self, "velocity", Vx, Vz, Vy); //Move towards target!
    }
}

void dash3(float Vx, float Vy)
{// Dash with previously attained z speed + defined x and y speed
// Used by Jetpacks to continue moving after diving
    void self = getlocalvar("self");
    int dir = getentityproperty(self,"direction");
    float Vz = getlocalvar("z"+self);

    if(dir==0){ // Facing left?
      Vx = -Vx ;
    }

    if( Vz!=NULL() ){
      changeentityproperty(self, "velocity", Vx, Vz, Vy); //Move!
    }
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

void dodgez( float Vx, float Vy, float Vz )
{// Dodge by moving up or down depending on z location
    void self = getlocalvar("self");
    int z = getentityproperty(self, "z");
    int dir = getentityproperty(self,"direction");

    if(dir==0){ // Facing left?
      Vx = -Vx ;
    }

    if(z > (openborconstant("PLAYER_MIN_Z") + openborconstant("PLAYER_MAX_Z")) / 2 ) {
      Vz = -Vz ;
    }

    if( Vx!=NULL() && Vy!=NULL() && Vz!=NULL() ){
      changeentityproperty(self, "velocity", Vx, Vz, Vy); //Dodge away!
    }
}

void dodgeleapz( float Vx, float Vy, float Vz )
{// Dodge by leaping up or down depending on z location
    void self = getlocalvar("self");
    int z = getentityproperty(self, "z");
    int dir = getentityproperty(self,"direction");

    if(dir==0){ // Facing left?
      Vx = -Vx ;
    }

    if(z > (openborconstant("PLAYER_MIN_Z") + openborconstant("PLAYER_MAX_Z")) / 2 ) {
      Vz = -Vz ;
    }

    if( Vx!=NULL() && Vy!=NULL() && Vz!=NULL() ){
      tossentity(self, Vy, Vx, Vz); //Dodge and leap away!
    }
}

void teledodgez( float dx, float dy, float dz )
{// Dodge by teleporting up or down depending on z location
    void self = getlocalvar("self");
    int x = getentityproperty(self,"x"); //Get character's x coordinate
    int z = getentityproperty(self,"z"); //Get character's z coordinate
    int a = getentityproperty(self,"a"); //Get character's a coordinate
    int dir = getentityproperty(self,"direction"); //Get character's facing direction
    float H;
    int FZ;

    if(z > (openborconstant("PLAYER_MIN_Z") + openborconstant("PLAYER_MAX_Z")) / 2 ) {
      dz = -dz ;
    }
    FZ = z+dz;

    if(dir==0){ // Facing left?
      dx = -dx ;
    }

    if((z + dz) > openborconstant("PLAYER_MAX_Z")) {
      FZ = openborconstant("PLAYER_MAX_Z");
    } else if((z + dz) < openborconstant("PLAYER_MIN_Z")) {
      FZ = openborconstant("PLAYER_MIN_Z");
    }

    H = checkwall(x+dx,FZ);

    if(H > 0){ // Is there a wall on teleport destination?
      dx = -dx ;
    }

    changeentityproperty(self, "position", x+dx, FZ, a+dy); //Teleport away!
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

void leap(float Vely)
{// Leap with previously attained speed!
    void self = getlocalvar("self");
    float Vx = getlocalvar("x"+self);
    float Vz = getlocalvar("z"+self);
    if( Vx!=NULL() && Vz!=NULL() ){
      tossentity(self, Vely, Vx, Vz); //Leap towards target!
    }
}

void stop()
{// Stop enemy's movement!
    void self = getlocalvar("self");
    changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
}

void riseattack(int Rx, int Rz, void Ani)
{// Riseattack with range check
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disx < 0){
        Disx = -Disx;
      }
      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx <= Rx && Disz <= Rz ) // Target within range?
      {
        if(Tx < x){
          changeentityproperty(self, "direction", 0);
        } else {
          changeentityproperty(self, "direction", 1);
        }
        changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
      } 
    }
}

void riseattack2(int Rx, int Rz, float Velx, float Velz, void Ani)
{// Riseattack with range check + targetting
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disx < 0){
        Disx = -Disx;
      }
      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx <= Rx && Disz <= Rz ) // Target within range?
      {
        if(Tx < x){
          changeentityproperty(self, "direction", 0);
        } else {
          changeentityproperty(self, "direction", 1);
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
        changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
      }
    }
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

