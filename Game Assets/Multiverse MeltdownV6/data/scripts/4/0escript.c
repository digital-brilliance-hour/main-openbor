
void changemap(int iMap)
{// Change remap
    void self = getlocalvar("self");

    changeentityproperty(self, "map", iMap); //Change remap
}

void nograb(int Flag)
{// Turns grabbable status
    void self = getlocalvar("self");
    changeentityproperty(self, "nograb", Flag);
}

void platform(int Flag)
{// Turns subject to platform status
    void self = getlocalvar("self");
    changeentityproperty(self, "Subject_to_Platform", Flag);
}

void block(int Flag)
{// Turns blocking status
    void self = getlocalvar("self");
    changeentityproperty(self, "aiflag", "blocking", Flag);
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

void degravity(int Ratio)
{// Changes antigravity effect
    void self = getlocalvar("self");
    changeentityproperty(self, "antigravity", Ratio);
}

void clearL()
{ // Clears all local variables
     clearlocalvar();
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

void shooter(void Shot, float dx, float dy, float dz, float Vx, float Vy, float Vz)
{ // Shooting projectile with speed control
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   void vShot;

   if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
   }

   vShot = projectile(Shot, x+dx, z+dz, y+dy, Direction, 1, 0, 0);
   changeentityproperty(vShot, "velocity", Vx, Vz, Vy);
   changeentityproperty(vShot, "speed", Vx);
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

void attack1(int RxMin, int RxMax, int RyMin, int RyMax, void Ani)
{// Attack interruption with range check
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    int dir = getentityproperty(self, "direction");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Ty = getentityproperty(target, "a");
      float Disx = Tx - x;
      float Disy = Ty - y;

      if( Disx >= RxMin && Disx <= RxMax && Disy >= RyMin && Disy <= RyMax && dir == 1) // Target within range on right facing?
      {
        performattack(self, openborconstant(Ani)); //Change the animation
      } else if( Disx >= -RxMax && Disx <= -RxMin && Disy >= RyMin && Disy <= RyMax && dir == 0) // Target within range on left facing?
      {
        performattack(self, openborconstant(Ani)); //Change the animation
      }
    }
}

void target0(float Velx, float Vely, float Tx, float Ty, float dx, float dy, void Vel)
{// Basic Targetting certain coordinate before dashing
// Velx = Desired x Velocity
// Vely = Desired y Velocity
// Tx = target x coordinate
// Ty = target y coordinate
// dx = x added distance
// dy = y added distance
// Vel = Desired output

    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction");
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    float Vx;
    float Vy;

    if(Tx < x){
      changeentityproperty(self, "direction", 0);
    } else {
      changeentityproperty(self, "direction", 1);
    }

    x = x+dx;
    y = y+dy;
    float Disx = Tx - x;
    float Disy = Ty - y;

//Set both distance as positive value
    if(Disx < 0){
      Disx = -Disx;
    }

    if(Disy < 0){
      Disy = -Disy;
    }

// Calculate velocity for targetting
    if(Disy < Disx)
    {
      if(Tx < x){
        Vx = -Velx;
      } else { Vx = Velx; }

      Vy = Velx*(Ty-y)/Disx;
    } else {
      if(Ty < y){
        Vy = -Vely;
      } else { Vy = Vely; }

      Vx = Vely*(Tx-x)/Disy;
    }

    if(Vel == "x"){
      return Vx;
    }
    if(Vel == "y"){
      return Vy;
    }
}

void target1(void Target, float Velx, float Vely, float dx, float dy, int Stop, void Vel)
{// Targetting certain entity before dashing
// Target = Targetted entity
// Velx = Desired x Velocity
// Vely = Desired y Velocity
// dx = x added distance
// dy = y added distance
// Stop = flag to stop moving if there's no target

    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction");
    float x = getentityproperty(self, "x");
    float y = getentityproperty(self, "a");
    float Vx;
    float Vy;

    if (dir == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
    }

    if( Target != NULL()){
      float Tx = getentityproperty(Target, "x");
      float Ty = getentityproperty(Target, "a");

      Vx = target0(Velx, Vely, Tx, Ty, dx, dy, "x");
      Vy = target0(Velx, Vely, Tx, Ty, dx, dy, "y");
    } else {
      if(Stop == 1)
      {
        Vy = 0;
        Vx = 0;
      } else {
        Vy = 0;
        if(dir==0){
          Vx = -Velx;
        } else { Vx = Velx; }
      }
    }

    if(Vel == "x"){
      return Vx;
    }
    if(Vel == "y"){
      return Vy;
    }
}

void target(float Velx, float Vely, float dx, float dy, int Stop)
{// Targetting opponent before leaping or dashing.
// Velx = x Velocity
// Vely = y Velocity
// dx = x added distance
// dy = y added distance
// Stop = flag to stop moving if no target is found

    void self = getlocalvar("self");

    setlocalvar("T"+self, findtarget(self)); //Get nearest player

    void target = getlocalvar("T"+self);
    setlocalvar("x"+self, target1(target, Velx, Vely, dx, dy, Stop, "x") );
    setlocalvar("y"+self, target1(target, Velx, Vely, dx, dy, Stop, "y") );
    setlocalvar("T"+self, NULL()); //Clears variable
}

void dash()
{// Dash with previously attained speed!
    void self = getlocalvar("self");
    float Vx = getlocalvar("x"+self);
    float Vy = getlocalvar("y"+self);
    if( Vx!=NULL() && Vy!=NULL() ){
      changeentityproperty(self, "velocity", Vx, 0, Vy); //Move towards target!
    }
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

void shoot2(void Shot, float dx, float dy)
{ // Shooting targetted projectile
   void self = getlocalvar("self");
   float Vx = getlocalvar("x"+self);
   float Vy = getlocalvar("y"+self);
   void vShot;

   if( Vx!=NULL() && Vy!=NULL() ){
     vShot = shooter2(Shot, dx, dy, Vx, Vy);
     changeentityproperty(vShot, "velocity", Vx, 0, 2*Vy); //Move projectile towards target!
   }
}

void shooter2(void Shot, float dx, float dy, float Vx, float Vy)
{ // Shooting special projectile with speed control
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   void vShot;

   if (Direction == 0){ //Is entity facing left?                  
      Vx = -Vx; //Reverse Vx direction to match facing
   }

   vShot = spawn01(Shot, dx, dy, 0);
   changeentityproperty(vShot, "velocity", Vx, 0, Vy);

   return vShot;
}

void move(int dx, int dz,int da)
{ // Moves entity freely and ignores obstacles
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
{// Clears all local variables
     clearlocalvar();
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

      if (Hflag==1){ //Not holding the button case?
        iRKey = !iRKey; //Take the opposite condition
	}

      if ((Health > Limit)&&iRKey){
        changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
        changeentityproperty(self, "animpos", Frame);
      }
}

void keyflip()
{// Change hero's facing direction if left or right is pressed
    void self = getlocalvar("self");
    int iPIndex = getentityproperty(self,"playerindex"); //Get player index

    if (playerkeys(iPIndex, 0, "moveleft")){ // Left is pressed?
      changeentityproperty(self, "direction", 0); //Face left
    } else if (playerkeys(iPIndex, 0, "moveright")){ // Right is pressed?
      changeentityproperty(self, "direction", 1); //Face right
    }
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
   //fY: Y location adjustment.
      //fZ: Z location adjustment.

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

void bind(int null, float x, float z, float y, int dir){
	void self = getlocalvar("self");
	void opp = getentityproperty(self, "opponent");
	if(null == 1)
	{
		bindentity(opp, self, x, z, y, dir, 0);
	}
	else if(null == 0)
	{
		bindentity(opp, NULL());
	}
}

void forceanim(int anim){
	void self = getlocalvar("self");
	void opp = getentityproperty(self, "opponent");
	changeentityproperty(opp, "animation", openborconstant(anim));
}

void throw(int Damage, int Type, int x, int y, int z, int Face)
{ // Damage as throw finisher
   void self = getlocalvar("self");
   void target = getentityproperty(self, "opponent");

   if(target!=NULL())
   {
     int SDir = getentityproperty(target,"direction"); //Get opponent's facing direction
     int MDir;

     if(Face==0){ // Same facing?
         MDir = SDir;
     } else if(Face==1){ // Opposite facing?

       if(SDir==0){ // Facing left?
         MDir = 1;
       } else { MDir = 0;}
     }

     if(SDir==0){ // Facing left?
       x = -x;
     }

     if(Type==1)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL")); // 1st throw type
     } else if(Type==2)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL2")); // 2nd throw type
     }

     changeentityproperty(target, "attacking", 1);
     changeentityproperty(target, "damage_on_landing", Damage);
     changeentityproperty(target, "projectile", 1);
     changeentityproperty(target, "direction", MDir);
     tossentity(target, y, x, z); // Toss opponent ;)
   }
}

void flip()
{// Flip to opposite direction
    void self = getlocalvar("self");
    int dir = getentityproperty(self,"direction");

    if(dir==0){ // Facing left?
      changeentityproperty(self, "direction", 1);
    } else {
      changeentityproperty(self, "direction", 0);
    }
}

void fileread(void Path)
{// Read values from file defined with Path then store each value in each entity variable
      void self = getlocalvar("self");
      void file = openfilestream(Path, 1);
      void vLoad;
      int i = 0;

      if( file != -1 ){
        setfilestreamposition(file, 0);
        vLoad = getfilestreamargument(file, 0, "string");

        while(vLoad != "#End"){
          setentityvar(self, i, vLoad);
          i = i + 1;
          filestreamnextline(file);
          vLoad = getfilestreamargument(file, 0, "string");
        }

        if(vLoad == "#End"){
          setentityvar(self, i, vLoad);
          closefilestream(file);
        }
        return 1;
      } else {
        return -1;
      }
}

void fileedit(void Path, char Name, void Value)
{// Read values from entity variables, find the one matching with Name then change the value in next line
      void self = getlocalvar("self");
      int Check = fileread(Path);
      int i;
      void vLoad;

      if(Check==1){
        i = 0;
        vLoad = getentityvar(self, i);

        while(vLoad != Name && vLoad != "#End" && vLoad != NULL()){
          i = i + 1;
          vLoad = getentityvar(self, i);
        }

        if(vLoad == Name){
          i = i + 1;
          vLoad = getentityvar(self, i);
          setentityvar(self, i, Value);
        }
      }
}

void filewrite(void Path)
{// Read values from entity variables then write them to a file by name Path
// Must use fileread function first
      void self = getlocalvar("self");
      int i = 0;
      void vLoad = getentityvar(self, i);

      if(vLoad){
        void file = createfilestream();
        filestreamappend(file, vLoad, 1);

        while(vLoad != "#End" && vLoad != NULL()){
          i = i + 1;
          vLoad = getentityvar(self, i);
          filestreamappend(file, vLoad, 0);
        }

        savefilestream(file, Path);
        closefilestream(file);
      }
}

void writedefault(void Path)
{// Writes file by name Path with default values
// Used when there's no file to start with
      void file = createfilestream();
      filestreamappend(file, 11, 1);
      filestreamappend(file, 22, 0);
      filestreamappend(file, 33, 0);
      filestreamappend(file, 44, 0);
      filestreamappend(file, "Lock", 0);
      filestreamappend(file, 8, 0);
      filestreamappend(file, 55, 0);
      filestreamappend(file, "Rise", 0);
      filestreamappend(file, 127, 0);
      filestreamappend(file, "Rise2", 0);
      filestreamappend(file, 85, 0);
      filestreamappend(file, "Rise3", 0);
      filestreamappend(file, 77, 0);
      filestreamappend(file, "Rise4", 0);
      filestreamappend(file, 55257, 0);
      filestreamappend(file, "Rise5", 0);
      filestreamappend(file, 1207, 0);
      filestreamappend(file, "#End", 0);

      savefilestream(file, Path);
      closefilestream(file);
}

int load_unlocked_model(char modelname)
{
    int models_cached = openborvariant("models_cached");
    int i = 0;

    for ( i = 0; i < models_cached; ++i ) {
        char model = getmodelproperty(i,2);

        if ( model == modelname ) {
	    if (getmodelproperty(i,4)!=1) {
	      loadmodel(modelname);
	      changemodelproperty(i,4,1);
	    }
            return;
        }
    }
}

void Unlock(int Flag, void Path)
{ // Unlocks certain character based on flag and write the status on file named Path
// 1: Unlocks RASH
// 2: Unlocks ZITZ
// 3: Unlocks PIMPLE
    void file = openfilestream(Path, 1);
    char Code;
    int Value;


    if(Flag == 1){
      Code = "Rise";
      Value = 1;
    } else if(Flag == 2){
      Code = "Rise2";
      Value = 2;
    } else if(Flag == 3){
      Code = "Rise3";
      Value = 3;
    } else if(Flag == 4){
      Code = "Rise4";
      Value = 4;
    } else if(Flag == 5){
      Code = "Rise5";
      Value = 5;
    }

    if(file == -1){
      writedefault(Path);
    }

    fileedit(Path, Code, Value);
    filewrite(Path);
}

void suicide()
{ // Suicide!!
    void self = getlocalvar("self");

    killentity(self); //Suicide!
}
