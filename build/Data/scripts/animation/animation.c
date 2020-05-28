// SLAM - THROW //////////////////////////////////////////////////////////////////////////////

void slamstart()
{//Slam Starter for grab slams
//Use finish or throw after using this
	void self 	= getlocalvar("self");
	void target = getlocalvar("Target" + self);

	if(target==NULL())
	{
		target = getentityproperty(self, "grabbing");
		setlocalvar("Target" + self, target);
	}
	
	if(target!=NULL())
	{
		damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL7")); // Slam Starter
	}
}

void slamstart2()
{//Slam Starter for nongrab slams
//Use finish or throw after using this
	void self 	= getlocalvar("self");
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

void position(int Frame, float dx, float dy, float dz, int face)
{//Modify grabbed entity's position relative to grabber
//Use slamstart 1st before using this
	void self 	= getlocalvar("self");
	void target = getlocalvar("Target" + self);
	int THealth = getentityproperty(target,"health"); //Get opponents's health

	if(target==NULL())
	{
		target = getentityproperty(self, "grabbing");
		setlocalvar("Target" + self, target);
	}
	
	if(target!=NULL())
	{
		if(THealth <= 0)
		{
			depost(0);
			finish(0,0,-1,0,0,0);
			slammed(0);
		} else {
			updateframe(target, Frame);
			bindentity(target, self, dx, dz, dy, face, 0);
		}
	}
}

void depost(int Gr)
{//Release grabbed entity
	void self 	= getlocalvar("self");
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

void finish(int Damage, int Type, int x, int y, int z, int Face)
{//Damage as slam or throw finisher
	void self 	= getlocalvar("self");
	void target = getlocalvar("Target" + self);
	int SDir 	= getentityproperty(target,"direction");
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
			koCount();
		}

		if(Type==2)
		{
			damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL9")); // 2nd Finisher
			koCount();
		}

		if(Type==3)
		{
			damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL8")); // 3rd Finisher
			koCount();
		}

		changeentityproperty(target, "direction", MDir);
		changeentityproperty(target, "attacking", 1);
		changeentityproperty(target, "projectile", 1);
		tossentity(target, y, x, z); // Toss opponent
		
	}
}

void koCount()
{//Count each enemy killed, chaning your variable
//Specific counter to avoid engine didhit bug in slam/finish using damageentity and without damageonlanding
//The engine does not know who did the last hit if receive damage using damageentity
//This script is already in didhitscript by default in each player char, these is used only for slams that end with @cmd finish
	void self 		= getlocalvar("self");
	void target		= getentityproperty(self,"opponent");
	void pType		= getentityproperty(self,"type");
	void eType		= getentityproperty(target,"type");
	int iPIndex		= getentityproperty(self,"playerindex");
	int dead		= getentityproperty(target,"dead");
	int ko1 		= getglobalvar("ko1");
	int ko2 		= getglobalvar("ko2");
	int ko3 		= getglobalvar("ko3");
	int ko4 		= getglobalvar("ko4");
	
	if(dead == 1){
		if(pType == openborconstant("TYPE_PLAYER") && eType == openborconstant("TYPE_ENEMY")){
			if(iPIndex == 0){
				setglobalvar("ko1",ko1+1);
			}else if(iPIndex == 1){
				setglobalvar("ko2",ko2+1);
			}else if(iPIndex == 2){
				setglobalvar("ko3",ko3+1);
			}else if(iPIndex == 3){
				setglobalvar("ko4",ko4+1);
			}
		}
	}
}

void throw(int Damage, int Type, int Vx, int Vy, int Vz, int Face)
{//Damage as throw finisher
	void self 	= getlocalvar("self");
	void target = getlocalvar("Target" + self);
	int z 		= getentityproperty(self,"z");
	int SDir 	= getentityproperty(target,"direction");
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
			damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL9")); // 2nd throw type
		}

		if(Type==3)
		{
			damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL8")); // 3rd throw type
		}

			changeentityproperty(target, "attacking", 1);
			changeentityproperty(target, "damage_on_landing", Damage);
			changeentityproperty(target, "projectile", 1);
			changeentityproperty(target, "direction", MDir);

		if(z > (openborconstant("PLAYER_MIN_Z") + openborconstant("PLAYER_MAX_Z")) / 2 ) {
			Vz = -Vz ;
		}

			tossentity(target, Vy, Vx, Vz); // Toss opponent
	}
}

void grabend()
{//End grab jump and free enemy on the ground if no attack is performed (MAX)
	void self 	= getlocalvar("self");
	void target = getlocalvar("Target" + self);

	if(target==NULL())
	{
		target = getentityproperty(self, "grabbing");
		setlocalvar("Target" + self, target);
	}
	
	if(target!=NULL())
	{
		changeentityproperty(target,"damage_on_landing",0);
		changeentityproperty(target,"nograb",0);
		changeentityproperty(target,"aiflag","falling",0);
		changeentityproperty(target,"aiflag","drop",0);
		changeentityproperty(target,"aiflag","projectile",0);
		changeentityproperty(target,"takeaction", "common_attack_proc");
		executeanimation(target, openborconstant("ANI_IDLE"));
		setidle(target);
		depost(0);
	}
}

void fakeBind(int Dist)
{//Move grabbed entity together with grabber with defined distance
//Used ind the end of the vault animation if grabber is moved because hit wall/obstacle/platform/offscreen
//Changes grabbed position relative to grabber without use bindentity
	void self 		= getlocalvar("self");
	void target 	= getentityproperty(self, "grabbing");
	int Direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int Tx 			= getentityproperty(target, "x");
	int z 			= getentityproperty(self, "z");
	int Tz 			= getentityproperty(target, "z");
	
	if(Direction  == 1){
		if(Tx-x < Dist)
		{
			changeentityproperty(target,"position", x+Dist);
		}else if(Tx-x > Dist)
		{
			changeentityproperty(target,"position", x+Dist);
		}
	}
	
	if(Direction  == 0){
		if(x-Tx < Dist)
		{
			changeentityproperty(target,"position", x-Dist);
		}else if(x-Tx > Dist)
		{
			changeentityproperty(target,"position", x-Dist);
		}
	}
}

void antiwall(int Dist, int Move, int Distz)
{//Checks distance from the walls
//If near of the walls at defined distance, entity (Self/Grabbed) will be moved away with defined movement
	void self 		= getlocalvar("self");
	void target		= getentityproperty(self, "grabbing");
	int Direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int Tx 			= getentityproperty(target, "x");
	int z 			= getentityproperty(self, "z");
	int Tz 			= getentityproperty(target, "z");
	int subwall		= getentityproperty(self, "subject_to_wall");
	float W;
	float Wz;

	if(Direction == 0){ //Is entity facing left?                  
		Dist = -Dist;
		Move = -Move;
	}

	W 	= checkwall(x+Dist,z);
	Wz 	= checkwall(x+Dist,z+Distz);

	if(Wz){
		if(subwall == 1)
		{
			changeentityproperty(self, "position", x, z-Distz);
			changeentityproperty(target, "position", Tx, Tz-Distz);
		}
	}

	if(W){
		if(subwall == 1)
		{
			changeentityproperty(self, "position", x+Move);
			changeentityproperty(target, "position", Tx+Move);
		}
	}
}

void vaultStuck(int DistL, int DistW, int MoveZ)
{//Checks if the entity can be stucked between Left edge of the screen and any Wall at your right side
//If near of both at defined distance, entity (Self/Grabbed) will be moved away with defined movement
//Specific script for stages st1a/st3b/st6b when camera go down, used on Grab animation before Vault animation
	void self 		= getlocalvar("self");
	void target		= getentityproperty(self, "grabbing");
	int Direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int Tx 			= getentityproperty(target, "x");
	int z 			= getentityproperty(self, "z");
	int Tz 			= getentityproperty(target, "z");
	int XPos 		= openborvariant("xpos");
	int subscreen	= getentityproperty(self, "subject_to_screen");
	int subwall		= getentityproperty(self, "subject_to_wall");
	float L 		= (XPos);
	float W			= checkwall(x+DistW,z);
	
	if(Direction == 0){ //Is entity facing left?                  
		DistW = -DistW;
	}
	
	if(subscreen == 1 && subwall == 1){
		if(DistL > x - L){// Near from the left edge of the screen?
			if(W){// There is a wall near at right side?
				changeentityproperty(self, "position", x, z+MoveZ);// Move down in Z axis to gain more space
				changeentityproperty(target, "position", Tx, Tz+MoveZ);// Move down in Z axis to gain more space
			}
		}
	}
}

// MOVES //////////////////////////////////////////////////////////////////////////////

void moveX(int V)
{//Moves with random angle (NINJA)
//V : Base velocity
    int r = rand()%180;
    int Vx;
    int Vz;

    Vx = V*cos(r);
    Vz = V*sin(r);

    dasher(Vx,0,Vz);
}

void dash()
{// Dash with previously attained speed!
    void self 	= getlocalvar("self");
    float Vx 	= getlocalvar("x"+self);
    float Vz 	= getlocalvar("z"+self);
	
	if(Vx!=NULL() && Vz!=NULL()){
		changeentityproperty(self, "velocity", Vx, Vz); //Move towards target!
	}
}

void dasher( float Vx, float Vy, float Vz )
{// Dash with desired speed!
    void self 	= getlocalvar("self");
    int dir 	= getentityproperty(self,"direction");

    if(dir==0){ // Facing left?
		Vx = -Vx ;
    }

    changeentityproperty(self, "velocity", Vx, Vz, Vy); //Move!
}

void leap(float Vely)
{// Leap with previously attained speed!
    void self 	= getlocalvar("self");
    float Vx 	= getlocalvar("x"+self);
    float Vz 	= getlocalvar("z"+self);
	
	if(Vx!=NULL() && Vz!=NULL()){
		tossentity(self, Vely, Vx, Vz); //Leap towards target!
	}
}

void leaper(float Vx, float Vy, float Vz )
{// Leap with desired speed!
    void self 	= getlocalvar("self");
    int dir 	= getentityproperty(self,"direction");

    if(dir==0){ // Facing left?
		Vx = -Vx ;
    }

    tossentity(self, Vy, Vx, Vz); //Leap!
}

void leaperX(float Vx, float Vy, float Vz)
{// Leap with desired speed and random X/Z axis (SHIVA DODGE)
    void self 	= getlocalvar("self");
    int dir 	= getentityproperty(self,"direction");
	int iR1		= rand()%4;
	int iR2		= rand()%4;

	if(iR1 >= 0 && iR1 <= 2){
		Vx = -Vx;
    }
	
	if(iR2 >= 0 && iR2 <= 2){
		Vz = -Vz;
    }
	
    tossentity(self, Vy, Vx, Vz); //Leap!
}

void stop()
{// Stop movement!
    void self = getlocalvar("self");
	
    changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
}

void stop2()
{// Stop movement and changes speed to 0!
	void self = getlocalvar("self");

	changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
	changeentityproperty(self, "speed", 0, 0, 0); //Stop moving!
}

void target(float Velx, float Velz)
{// Targetting opponent before leaping or dashing. (REDUCED TARGET SCRIPT)
	void self 	= getlocalvar("self");
	int dir 	= getentityproperty(self, "direction"); // Get enemy's facing direction
	float x 	= getentityproperty(self, "x"); // Get enemy's x coordinate
	float z 	= getentityproperty(self, "z"); // Get enemy's z coordinate

    setlocalvar("T"+self, findtarget(self)); // Find target and put it in local variable

	if(getlocalvar("T"+self) != NULL()){ // Is there a target?
		void target = getlocalvar("T"+self);
		float Tx 	= getentityproperty(target, "x"); // Get target's x coordinate
		float Tz 	= getentityproperty(target, "z"); // Get target's z coordinate
		float Disx	= Tx - x; // Get x distance
		float Disz 	= Tz - z; // Get z distance

		if(Disx < 0){ // Negative Disx?
			Disx = -Disx; // Turn it to positive
			changeentityproperty(self, "direction", 0); // Face left
		} else {
			changeentityproperty(self, "direction", 1); // Face right
		}

		if(Disz < 0){ // Negative Disz?
			Disz = -Disz; // Turn it to positive
		}

		if(Disz < Disx) // Disx bigger than Disz?
		{
			if(Tx < x){ // Player is behind enemy?
				setlocalvar("x"+self, -Velx); // Turn Vx to negative
			} else { setlocalvar("x"+self, Velx); } // Use defined Vx

			setlocalvar("z"+self, Velx*(Tz-z)/Disx); // Calculate Vz then store value in local variable
		} else { // Disz bigger than Disx!
			if(Tz < z){ // Player is behind enemy?
				setlocalvar("z"+self, -Velz); // Turn Vz to negative
			} else { setlocalvar("z"+self, Velz); } // Use defined Vz

			setlocalvar("x"+self, Velz*(Tx-x)/Disz); // Calculate Vx then store value in local variable
		}

		} else { // No target at all!
			setlocalvar("z"+self, 0); // 0 velocity
		if(dir==0){ // Facing left?
			setlocalvar("x"+self, -Velx); // Negative velocity
		} else { setlocalvar("x"+self, Velx); } // Positive velocity
	}
}

void target2(float Velx, float Velz, float dx, float dz, int Stop)
{// Targetting opponent before leaping or dashing. (ORIGINAL TARGET SCRIPT)
 // Velx = x Velocity
 // Velz = z Velocity
 // dx = x added distance
 // dz = z added distance
 // Stop = flag to stop moving if no target is found

	void self 	= getlocalvar("self");
	int dir 	= getentityproperty(self, "direction");
	float x 	= getentityproperty(self, "x");
	float z 	= getentityproperty(self, "z");

	if(dir == 0){ //Is entity facing left?                  
		dx = -dx; //Reverse X direction to match facing
	}

	setlocalvar("T"+self, findtarget(self)); //Get nearest player

	if(getlocalvar("T"+self) != NULL()){
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
		if(Disz < Disx){
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
		if(Stop == 1){
			setlocalvar("z"+self, 0);
			setlocalvar("x"+self, 0);
		} else { setlocalvar("z"+self, 0);
			if(dir==0){
				setlocalvar("x"+self, -Velx);
			} else { setlocalvar("x"+self, Velx); }
		}
	}
}

void clearL()
{// Clears all local variables
    clearlocalvar();
}

// KEYS //////////////////////////////////////////////////////////////////////////////

void keymove(float V)
{// Move hero if direction button is pressed
	void self 	= getlocalvar("self");
	int iPIndex = getentityproperty(self,"playerindex"); //Get player index
	float xdir 	= 0;
	float zdir 	= 0;

    if(playerkeys(iPIndex, 0, "moveleft")){// Left is pressed?
		xdir = -V;
	}else if(playerkeys(iPIndex, 0, "moveright")){// Right is pressed?
		xdir = V;
    }

	if(playerkeys(iPIndex, 0, "moveup")){// Up is pressed?
		zdir = -V/2;
	} else if(playerkeys(iPIndex, 0, "movedown")){// Down is pressed?
		zdir = V/2;
    }

	changeentityproperty(self, "velocity", xdir, zdir);
}

void copyMove()
{// Copy previously attained xDir/zDir
    void self 	= getlocalvar("self");
    float xdir 	= getentityproperty(self,"xdir");
    float zdir 	= getentityproperty(self,"zdir");
	
	clearlocalvar();
	setlocalvar("xVel", xdir);
	setlocalvar("zVel", zdir);
}

void pasteMove()
{// Paste previously attained xDir/zDir
    void self 	= getlocalvar("self");
    float Vx 	= getlocalvar("xVel");
    float Vz 	= getlocalvar("zVel");
	
	if(Vx!=NULL() && Vz!=NULL()){
		changeentityproperty(self, "velocity", Vx, Vz); //Move towards target!
	}
}

void keymoveX(float V)
{// Move hero if direction button is pressed in X axis only
	void self 	= getlocalvar("self");
	int iPIndex = getentityproperty(self,"playerindex"); //Get player index
	float xdir 	= 0;
	float zdir 	= getentityproperty(self,"zdir");

    if(playerkeys(iPIndex, 0, "moveleft")){// Left is pressed?
		xdir = -V;
	}else if(playerkeys(iPIndex, 0, "moveright")){// Right is pressed?
		xdir = V;
    }
	
	changeentityproperty(self, "velocity", xdir, zdir);
}

void keymoveZ(float V)
{// Move hero if direction button is pressed in Z axis only
	void self 	= getlocalvar("self");
	int iPIndex = getentityproperty(self,"playerindex"); //Get player index
	float xdir 	= getentityproperty(self,"xdir");
	float zdir 	= 0;

	if(playerkeys(iPIndex, 0, "moveup")){// Up is pressed?
		zdir = -V/2;
	}else if(playerkeys(iPIndex, 0, "movedown")){// Down is pressed?
		zdir = V/2;
	}

	changeentityproperty(self, "velocity", xdir, zdir);
}

void keyVel()
{// Change X velocity if defined button is pressed
	void self 	= getlocalvar("self");
	int iPIndex = getentityproperty(self,"playerindex"); //Get player index
	int dir 	= getentityproperty(self,"direction");
	float xdir 	= getentityproperty(self,"xdir");
	float zdir 	= 0;

	if(dir == 0){
		if(playerkeys(iPIndex, 0, "moveleft")){// Left is pressed?
			xdir = xdir*2;
		}else if(playerkeys(iPIndex, 0, "moveright")){// Right is pressed?
			xdir = xdir/2;
		}
	}else if(dir == 1){
		if(playerkeys(iPIndex, 0, "moveleft")){// Left is pressed?
			xdir = xdir/2;
		}else if(playerkeys(iPIndex, 0, "moveright")){// Right is pressed?
			xdir = xdir*2;
		}
	}

	changeentityproperty(self, "velocity", xdir, zdir);
}

void keyflip()
{// Change hero's facing direction if left or right is pressed
	void self 	= getlocalvar("self");
	int iPIndex = getentityproperty(self,"playerindex"); //Get player index

	if(playerkeys(iPIndex, 0, "moveleft")){ // Left is pressed?
		changeentityproperty(self, "direction", 0); //Face left
	}else if(playerkeys(iPIndex, 0, "moveright")){ // Right is pressed?
		changeentityproperty(self, "direction", 1); //Face right
	}
}

// SPAWN - SHOOT///////////////////////////////////////////////////////////////////////////

void spawn01(void vName, float fX, float fY, float fZ)
{	//spawn01 (Generic spawner)
	//Damon Vaughn Caskey
	//07/06/2007
	//
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
    //fY: Z location adjustment.

	void self 		= getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iDirection = getentityproperty(self, "direction");

	clearspawnentry(); //Clear current spawn entry.
    setspawnentry("name", vName); //Acquire spawn entity by name.

	if(iDirection == 0){ //Is entity facing left?                  
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

void spawn04(void vName, float fX, float fY, float fZ)
{
	//Spawns entity based on left screen edge and center of playing field
	//
	//vName: Model name of entity to be spawned in.
	//fX: X distance relative to left edge
	//fY: Y height from ground
      //fZ: Z location adjustment

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int Direction = getentityproperty(self, "direction");
        int XPos = openborvariant("xpos"); //Get screen edge's position
        int Screen = openborvariant("hResolution"); // Get screen width

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

   if (Direction == 0){ //Is entity facing left?                  
      fX = Screen-fX; //Reverse X direction to match facing and screen length
   }

      fZ = fZ+(openborvariant("PLAYER_MIN_Z") + openborvariant("PLAYER_MAX_Z") )/2 ;

	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX + XPos, fZ, fY); //Set spawn location.
	return vSpawn; //Return spawn.
}

void spawn08(void vName, float fX, float fY, float fZ)
{	//spawn01 (Generic spawner)
	//Damon Vaughn Caskey
	//07/06/2007
	//
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
    //fY: Z location adjustment.

	void self 		= getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iDirection = getentityproperty(self, "direction");

	clearspawnentry(); //Clear current spawn entry.
    setspawnentry("name", vName); //Acquire spawn entity by name.

	if(iDirection == 0){ //Is entity facing left?                  
        fX = -fX; //Reverse X direction to match facing.
	}

	
    fX = fX; //Get X location and add adjustment.
    fY = fY; //Get Y location and add adjustment.
    fZ = fZ; //Get Z location and add adjustment.
	
	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.
    return vSpawn; //Return spawn.
}

void spawner2(void vName, float fX, float fY, float fZ, float count)
{	//Spawns entity next to caller with same remap as spawner's. (ALL DODGE ENTITY SHADOWS)
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
    //fY: Z location adjustment.

	void self 	= getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iMap 	= getentityproperty(self, "map");

	vSpawn = spawn01(vName, fX, fY, fZ); //Spawn in entity.

	changeentityproperty(vSpawn, "map", iMap); //Use same remap as spawner's.
	changeentityproperty(vSpawn, "lifespancountdown", count);

	return vSpawn; //Return spawn.
}

void removeWall(int ID)
{// Remove defined wall by ID

    changelevelproperty("wall", ID, "x", 9999, "z", 9999, "depth", 0, "height", 0);
}

void shoot(void Shot, float dx, float dy, float dz)
{// Shooting projectile
	void self 		= getlocalvar("self");
	int Direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int y 			= getentityproperty(self, "a");
	int z 			= getentityproperty(self, "z");
	void vShot;

	if(Direction == 0){ //Is entity facing left?                  
		dx = -dx; //Reverse X direction to match facing
	}

	vShot = projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
	changeentityproperty(vShot, "parent", self);
	changeentityproperty(vShot, "subject_to_platform", 0);
	return vShot;
}

void shooter(void Shot, float dx, float dy, float dz, float Vx, float Vy, float Vz)
{// Shooting projectile with speed control
	void vShot = shoot(Shot, dx, dy, dz);

	changeentityproperty(vShot, "velocity", Vx, Vz, Vy);
	changeentityproperty(vShot, "speed", Vx);
}

void shooterB(void Shot, float dx, float dy, float dz)
{// Shooting and bind projectile
	void self = getlocalvar("self");
	void vShot = shoot(Shot, dx, dy, dz);

	bindentity(vShot, self, dx, dz, dy, 0, 0);
}

void shootAnim(void Shot, void Ani, float dx, float dy, float dz, float Vx, float Vy, float Vz)
{// Shooting special projectile with speed control and defined animation (JACK SPAWN KNIFE)
	void self 		= getlocalvar("self");
	int Direction 	= getentityproperty(self, "direction");
	void vShot;

	if (Direction == 0){ //Is entity facing left?                  
		Vx = -Vx; //Reverse Vx direction to match facing
	}

	vShot = spawn01(Shot, dx, dy, dz);
	changeentityproperty(vShot, "velocity", Vx, Vz, Vy);
	changeentityproperty(vShot, "animation", openborconstant(Ani));
}

void throweap(float dx, float dy, float dz, float Vx, float Vy, float Vz)
{// Throw holding weapon with speed control
	void self 	= getlocalvar("self");
	void weapon = getentityproperty(self, "weapnum");
	void vShot 	= shoot(weapon, dx, dy, dz);

	changeentityproperty(vShot, "velocity", Vx, Vz, Vy);
	changeentityproperty(vShot, "speed", Vx);
}

void tosser3(void Bomb, float dx, float dy, float dz, float Vx, float Vy, float Vz)
{// Tossing bomb with desired speed and base 0 (SIGNAL BOTTLE)
	void self 		= getlocalvar("self");
	int Direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int y 			= getentityproperty(self, "a");
	int z 			= getentityproperty(self, "z");
	void Shot;

	if(Direction == 0){ //Is entity facing left?                  
		dx = -dx; //Reverse X direction to match facing
	}

	Shot = projectile(Bomb, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
	tossentity(Shot, Vy, Vx, Vz);
	changeentityproperty(Shot, "speed", Vx);
	changeentityproperty(Shot, "projectile", 0); 
	changeentityproperty(Shot, "base", 0);
	changeentityproperty(Shot, "parent", self);
	return Shot;
}

void tosser4(void vName, float fX, float fY, float fZ, float fVx, float fVy, float fVz)
{//Spawns entity next to caller and toss it with certain speed (ITEM DROP)
	void self 		= getlocalvar("self"); //Get calling entity.
	int Direction 	= getentityproperty(self, "direction");
	void vSpawn; //Spawn object.

	vSpawn = spawn01(vName, fX, fY, fZ); //Spawn in entity.

	if(Direction == 0){ //Is entity facing left?                  
		fVx = -fVx; //Reverse fVx direction to match facing
	}

	tossentity(vSpawn, fVy, fVx, fVz); //Toss entity.

	return vSpawn; //Return spawn.
}

void tosser5(void Bomb, float dx, float dy, float dz, float Vx, float Vy, float Vz, int B)
{// Tossing bomb with desired speed and basechange (NINJA JUMP STAR)
	void self 		= getlocalvar("self");
	int Direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int y 			= getentityproperty(self, "a");
	int z 			= getentityproperty(self, "z");
	void Shot;

	if(Direction == 0){ //Is entity facing left?                  
		dx = -dx; //Reverse X direction to match facing
	}

	Shot = projectile(Bomb, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
	tossentity(Shot, Vy, Vx, Vz);
	changeentityproperty(Shot, "speed", Vx);
	changeentityproperty(Shot, "projectile", 0); 
	changeentityproperty(Shot, "base", B);
	changeentityproperty(Shot, "parent", self);
	changeentityproperty(Shot, "subject_to_platform", 0);
	return Shot;
}

void tosser6(void vName, void Alias, int Map, float fX, float fY, float fZ, float fVx, float fVy, float fVz)
{//Spawns entity next to caller and toss it with certain speed, alias and map (DONOVAN MANHOLE, SIGNAL GATE)
	void self 		= getlocalvar("self"); //Get calling entity.
	void vAlias 	= getentityproperty(self,"name"); // Get caller's alias.
	int iMap 		= getentityproperty(self,"map"); // Get caller's alias.
	int Direction 	= getentityproperty(self, "direction");
	void vSpawn; //Spawn object.

	vSpawn = spawn01(vName, fX, fY, fZ); //Spawn in entity.

	if(Direction == 0){ //Is entity facing left?                  
		fVx = -fVx; //Reverse fVx direction to match facing
	}

	changeentityproperty(vSpawn, "name", Alias); //Set alias.
	changeentityproperty(vSpawn, "map", Map); //Set map.
	tossentity(vSpawn, fVy, fVx, fVz); //Toss entity.

	return vSpawn; //Return spawn.
}

void tosserTX(void Bomb, float dx, float dy, float dz, float Vy, float Vz, int Cost)
{// Tossing bomb with desired Z/Y speed, targetted X speed and base 0 (BIKER BOMB)
	void self 		= getlocalvar("self");
	void target 	= findtarget(self);
	int Direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int y 			= getentityproperty(self, "a");
	int z 			= getentityproperty(self, "z");
	int Tx 			= getentityproperty(target, "x");
	float xVel;
	void Shot;
	
	xVel = Tx - x;

	if(Direction == 0){ //Is entity facing left?                  
		dx = -dx; //Reverse X direction to match facing
		xVel = -xVel;
	}

	Shot = projectile(Bomb, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
	tossentity(Shot, Vy, xVel/500, Vz);
	changeentityproperty(Shot, "speed", xVel/500);
	changeentityproperty(Shot, "projectile", 0); 
	changeentityproperty(Shot, "base", 0);
	changeentityproperty(Shot, "parent", self);
	hpcost(Cost);
}

void spawnbind(void Name, float dx, float dy, float dz)
{// Spawn and bind other entity
	void self = getlocalvar("self");
	void vSpawn;

	vSpawn = spawn01(Name, dx, dy, 0);

	bindentity(vSpawn, self, dx, dz, dy, 0, 0);
	changeentityproperty(vSpawn, "parent", self); //Set caller as parent.

	return vSpawn; //Return vSpawn.
}

void spawnbindM(void Name, float dx, float dy, float dz)
{// Spawn and bind other entity
// Apply same palette to spawned entity
	void self = getlocalvar("self");
	int iMap = getentityproperty(self,"map"); // Get caller's palette
	void vSpawn;

	vSpawn = spawn01(Name, dx, dy, 0);

	bindentity(vSpawn, self, dx, dz, dy, 0, 0);
	changeentityproperty(vSpawn, "parent", self); //Set caller as parent.
	changeentityproperty(vSpawn, "map", iMap);

	return vSpawn; //Return vSpawn.
}

void spawnbind2(void Name, float dx, float dy, float dz, int Dir, int Flag)
{// Spawn and bind other entity
// Has more parameters to set
	void self = getlocalvar("self");
	void vSpawn;

	vSpawn = spawn01(Name, dx, dy, dz);

	bindentity(vSpawn, self, dx, dz, dy, Dir, Flag);
	changeentityproperty(vSpawn, "parent", self); //Set caller as parent.

	return vSpawn; //Return vSpawn.
}

void spawnscreen(void Name, float fX, float fY, float fZ)
{//Spawn entity at specific location relative to XPos and YPos
	void self 	= getlocalvar("self"); //Get calling entity.
    int XPos 	= openborvariant("xpos");
	int YPos 	= openborvariant("ypos");
	void vSpawn; //Spawn object.

    fX = fX + XPos; // Changes position relative to XPos
	fY = fY + YPos; // Changes position relative to YPos
	
	vSpawn = spawn08(Name, 0, 0, 0);
	
	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
    
	return vSpawn; //Return vSpawn.
}

void spawnparent(void Name, float dx, float dy, float dz)
{// Spawn and set to Parent
	void self = getlocalvar("self");
	void vSpawn;

	vSpawn = spawn01(Name, dx, dy, dz);
	changeentityproperty(vSpawn, "parent", self); //Set caller as parent.
	changeentityproperty(vSpawn, "velocity", 0,0,0);
	changeentityproperty(vSpawn, "speed", 0);

	return vSpawn; //Return vSpawn.
}

void spawnplace(void Name, float dx, float dy, float dz)
{// Spawn and set to Parent
	void self = getlocalvar("self");
	void vSpawn;

	vSpawn = spawn01(Name, dx, dy, dz);
	changeentityproperty(vSpawn, "parent", self); //Set caller as parent.
	//changeentityproperty(vSpawn, "position", dx, dz, dy);

	return vSpawn; //Return vSpawn.
}

void spawnAliasP(void Name, void Alias, float dx, float dy, float dz)
{// Spawn and set Alias/Parent (VEHELITS) 
	void self = getlocalvar("self");
	void vSpawn;

	vSpawn = spawn01(Name, dx, dy, dz);

	changeentityproperty(vSpawn, "name", Alias); //Set alias.
	changeentityproperty(vSpawn, "parent", self); //Set caller as parent.

	return vSpawn; //Return vSpawn.
}

void spawnChosen(void Name, void Ani, int dx, int dy, int dz, int iDirection)
{//Spawn blink cursor in select screen if chosen
	void self 	= getlocalvar("self");
	void vSpawn;
		
	clearspawnentry(); //Clear current spawn entry.
	setspawnentry("name", Name); //Acquire spawn entity by name.

	vSpawn = spawn();	

	changeentityproperty(vSpawn, "position", dx, dz, dy); //Set spawn location.
	changeentityproperty(vSpawn, "direction", iDirection); //Set spawn direction.
	changeentityproperty(vSpawn, "animation", openborconstant(Ani)); //Set spawn location.

	return vSpawn; //Return vSpawn.
}

void Rain(void vName, float fX, float fY, float fZ, float Sx, float Vx, float Vy)
{//Spawns other entity in random spot relative to screen edge and move it with defined speed
 //vName: Model name of entity to be spawned in
 //fX: X deviation relative to screen edge
 //fY: Starting altitude
 //fZ: Z deviation relative from center of playing field
 //Sx: x offset
 //Vx: X speed
 //Vy: Y speed

   void self = getlocalvar("self"); //Get calling entity
   int Direction = getentityproperty(self, "direction");
   int Screen = openborvariant("hResolution"); // Get screen width
   void vSpawn; int iDX; int iDZ;

   if(Direction == 0){ //Is entity facing left?                  
     Vx = -Vx; //Reverse Vx direction to match facing  
   }

   if(fX!=0){
     iDX = rand()%fX+Screen*0.5;
   } else {
     iDX = 0;
   }

   if(fZ!=0){
     iDZ = rand()%fZ;
   } else {
     iDZ = 0;
   }

   vSpawn = spawn04(vName, iDX+Sx, fY, iDZ); //Spawn in entity
   changeentityproperty(vSpawn, "velocity", Vx, 0, Vy);
   changeentityproperty(vSpawn, "direction", Direction);
}

// CHANGERS///////////////////////////////////////////////////////////////////////////

void anichange(void Ani)
{// Animation changer
	void self = getlocalvar("self");

    changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
}

void aniexec(void Ani)
{// Animation executor
	void self = getlocalvar("self");

    executeanimation(self, openborconstant(Ani), 1);
}

void grabIdle()
{//Set idle if grabbing status is NULL
	void self 	= getlocalvar("self");
	void target = getentityproperty(self, "grabbing");
	void vAniID = getentityproperty(self, "animationID");

	if(target == NULL())
	{
		setidle(self);
	}
}

void performatk(void Ani)
{// Animation executor
	void self = getlocalvar("self");

    performattack(self, openborconstant(Ani), 1);
}

void takeact(void action)
{// Takeaction status changer
	void self = getlocalvar("self");

    changeentityproperty(self, "takeaction", action);
}

void anichangeMORE(void Ani, int Count) 
{// Animation changer with =/+ ENEMY count (ST7B ELEVATOR)
	void self 	= getlocalvar("self");
	int eCount 	= openborvariant("count_enemies");

	if(eCount >= Count)
	{
		anichange(Ani);
	}
}

void anichangeLESS(void Ani, int Count) 
{// Animation changer with =/- ENEMY count (ST7B ELEVATOR)
	void self 	= getlocalvar("self");
	int eCount 	= openborvariant("count_enemies");

	if(eCount <= Count)
	{
		anichange(Ani);
	}
}

void anichangeHP(void Ani, int Limit)
{// Animation executor
	void self 	= getlocalvar("self");
	void Health = getentityproperty(self, "health");
	
	if(Health <= Limit){
		executeanimation(self, openborconstant(Ani), 1);
	}
}

void basechange(int B)
{// Base changer
	void self = getlocalvar("self");

	changeentityproperty(self, "base", B);
}

void degravity(int Ratio)
{// Changes antigravity effect
	void self = getlocalvar("self");

	changeentityproperty(self, "antigravity", Ratio);
}

void setlayer(int layer)
{// Changes layer
	void self = getlocalvar("self");

	changeentityproperty(self, "setlayer", layer);
}

void offscreen(int Value)
{// Changes layer
	void self = getlocalvar("self");

	changeentityproperty(self, "offscreenkill", Value);
}

void block(int Flag)
{// Turns blocking status
	void self = getlocalvar("self");

	if(Flag == 1)
	{
		changeentityproperty(self, "aiflag", "blocking", 1);
		changeentityproperty(self, "takeaction", "common_block");
	} else {
		changeentityproperty(self, "aiflag", "blocking", 0);
	}
}

void jump(int Flag)
{// Turns jumping status
	void self = getlocalvar("self");

	if(Flag == 1)
	{
		changeentityproperty(self, "aiflag", "jumping", 1);
		changeentityproperty(self, "takeaction", "common_jump");
	} else {
		changeentityproperty(self, "aiflag", "jumping", 0);
	}
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

void looperKey(void Key, int Frame)
{// Loops defined frame if defined key is held
	void self 	= getlocalvar("self");
	int iPIndex = getentityproperty(self,"playerindex");

	if(playerkeys(iPIndex, 0, Key)){
		updateframe(self, Frame);
	}
}

void aniKey(void Key, void Ani)
{// Execute defined animation if defined key is held
	void self 	= getlocalvar("self");
	void dModel	= getentityproperty(self,"defaultmodel");
	void vModel	= getentityproperty(self,"model");
	int iPIndex = getentityproperty(self,"playerindex");

	if(playerkeys(iPIndex, 0, Key) && vModel == dModel){
		executeanimation(self, openborconstant(Ani));
	}
}

void geidle()
{// Change Grabbing Target to IDLE animation!
	void self 	= getlocalvar("self");
	void target	= getentityproperty(self,"grabbing");

	setidle(target, openborconstant("ANI_IDLE"));
}

void wall(int Flag)
{// Turns subject's to wall status
	void self = getlocalvar("self");

	changeentityproperty(self, "Subject_to_Wall", Flag);
}

void minz(int Flag)
{// Turns subject's to minZ status
	void self = getlocalvar("self");

	changeentityproperty(self, "Subject_to_MinZ", Flag);
}

void zeroWait()
{//Change stage "Wait" to 0 to spawn next group

	changeopenborvariant("waiting", 0);
}

void reseTime()
{//Reset game time to 99

	changeopenborvariant("game_time", 39900);
}

void autoLife(int iHealth)
{//Recover defined health for all players automatically
	void player1 = getplayerproperty(0, "entity");
	void player2 = getplayerproperty(1, "entity");
	void player3 = getplayerproperty(2, "entity");
	void player4 = getplayerproperty(3, "entity");
	int iHealth1 = getentityproperty(player1, "health");
	int iHealth2 = getentityproperty(player2, "health");
	int iHealth3 = getentityproperty(player3, "health");
	int iHealth4 = getentityproperty(player4, "health");

	changeentityproperty(player1, "health", iHealth1+iHealth);
	changeentityproperty(player2, "health", iHealth2+iHealth);
	changeentityproperty(player3, "health", iHealth3+iHealth);
	changeentityproperty(player4, "health", iHealth4+iHealth);
}

// HURTS///////////////////////////////////////////////////////////////////////////

void offscreenkill(float dx, int E)
{// Check position relative to screen. If enemy is offscreen, suicide!
//	dx : Distance to screen edge
//	E  : Edge selection, 0 = left, 1 = right
	void self 	= getlocalvar("self");
	int x 		= getentityproperty(self,"x"); //Get character's x coordinate
	int XPos 	= openborvariant("xpos"); //Get screen edge's position

	if((x > XPos + 480 + dx) && (E == 1)){ // Offscreen to the right?
		killentity(self); //Suicide!
	} else if((x < XPos - dx) && (E == 0)){ // Offscreen to the left?
		killentity(self); //Suicide!
	}
}

void offscreenhurt(float dx, int Damage, int Force, int E)
{// Check position relative to screen. If enemy is offscreen, hurt self with defined damage and force!
//	dx : Distance to screen edge
//	E  : Edge selection, 0 = left, 1 = right
	void self 	= getlocalvar("self");
	int x 		= getentityproperty(self,"x"); //Get character's x coordinate
	int XPos 	= openborvariant("xpos"); //Get screen edge's position

	if((x > XPos + 480 + dx) && (E == 1)){ // Offscreen to the right?
		damageentity(self, self, Damage, Force, openborconstant("ATK_NORMAL")); // Slam damage is inserted here
	} else if((x < XPos - dx) && (E == 0)){ // Offscreen to the left?
		damageentity(self, self, Damage, Force, openborconstant("ATK_NORMAL")); // Slam damage is inserted here
	}
}

void hurtself(int Damage)
{// Hurt self without toss 
	void self = getlocalvar("self");

	damageentity(self, self, Damage, 0, openborconstant("ATK_NORMAL")); // Slam damage is inserted here
}

void hurtselfHP(int Limit)
{// Hurt self with minimum HP% check and always max health damage(PARTICLE SUICIDE)
	void self 	= getlocalvar("self");
	int mHealth = getentityproperty(self,"maxhealth"); //Get entity's health
	int Health 	= getentityproperty(self,"health"); //Get entity's health

	if(Health <= mHealth*Limit/100)
	{
		damageentity(self, self, mHealth, 0, openborconstant("ATK_NORMAL")); // Slam damage is inserted here
	}
}

void slammed(int Damage)
{// Hurt self to death
	void self = getlocalvar("self");

	damageentity(self, self, Damage, 1, openborconstant("ATK_NORMAL")); // Slam damage is inserted here
	tossentity(self, 2, 0, 0);
}

void riseX()
{// Random rise or riseattack
	void self 	= getlocalvar("self");
	int iR 		= rand()%4;
	 
	if (iR >= 0 && iR <= 4){
		changeentityproperty(self, "animation", openborconstant("ANI_RISEATTACK"));
	}
}

void cancel(int RxMin, int RxMax, int RyMin, int RyMax, int RzMin, int RzMax, void Ani)
{// Attack interruption with range check
	void self 	= getlocalvar("self");
	void target = findtarget(self); //Get nearest player
	float x 	= getentityproperty(self, "x");
	float y 	= getentityproperty(self, "y");
	float z 	= getentityproperty(self, "z");
	int dir 	= getentityproperty(self, "direction");

	if(target!=NULL()){
		float Tx = getentityproperty(target, "x");
		float Ty = getentityproperty(target, "y");
		float Tz = getentityproperty(target, "z");
		float Disx = Tx - x;
		float Disy = Ty - y;
		float Disz = Tz - z;

		if(Disx >= RxMin && Disx <= RxMax && Disy >= RyMin && Disy <= RyMax && Disz >= RzMin && Disz <= RzMax && dir == 1) // Target within range on right facing?
		{
			executeanimation(self, openborconstant(Ani), 1); //Change the animation
		} else if(Disx >= -RxMax && Disx <= -RxMin && Disy >= RyMin && Disy <= RyMax && Disz >= -RzMax && Disz <= -RzMin && dir == 0) // Target within range on left facing?
		{
			executeanimation(self, openborconstant(Ani), 1); //Change the animation
		}
	}
}

void cancelmp(int RxMin, int RxMax, int RyMin, int RyMax, int Limit, void Ani)
{// Enemy attack interruption with range and MP check
	void self 	= getlocalvar("self");
	void target = findtarget(self); //Get nearest player
	float x 	= getentityproperty(self, "x");
	float y 	= getentityproperty(self, "y");
	int MP		= getentityproperty(self, "mp"); //Get entity's MP
	int dir 	= getentityproperty(self, "direction");

	if(target!=NULL()){
		float Tx = getentityproperty(target, "x");
		float Ty = getentityproperty(target, "y");
		float Disx = Tx - x;
		float Disy = Ty - y;

		if(Disx >= RxMin && Disx <= RxMax && Disy >= RyMin && Disy <= RyMax && dir == 1 && MP >= Limit) // Target within range on right facing?
		{
			mpcost(Limit);
			executeanimation(self, openborconstant(Ani), 1); //Change the animation
		} else if(Disx >= -RxMax && Disx <= -RxMin && Disy >= RyMin && Disy <= RyMax && dir == 0 && MP >= Limit) // Target within range on left facing?
		{
			mpcost(Limit);
			executeanimation(self, openborconstant(Ani), 1); //Change the animation
		}
	}
}

void cancelmpX(int RxMin, int RxMax, int RyMin, int RyMax, int Limit, void Ani)
{// Enemy RANDOM attack interruption with range and MP check
    void self 	= getlocalvar("self");
	void target = findtarget(self); //Get nearest player
	float x 	= getentityproperty(self, "x");
	float y 	= getentityproperty(self, "y");
	int MP 		= getentityproperty(self, "mp"); //Get entity's MP
    int dir 	= getentityproperty(self, "direction");
	int iR 		= rand()%4;

    if(target!=NULL()){
		float Tx = getentityproperty(target, "x");
		float Ty = getentityproperty(target, "y");
		float Disx = Tx - x;
		float Disy = Ty - y;
 	
	if(iR >= 0 && iR <= 3){
		if(Disx >= RxMin && Disx <= RxMax && Disy >= RyMin && Disy <= RyMax && dir == 1 && MP >= Limit) // Target within range on right facing?
			{
				mpcost(Limit);
				executeanimation(self, openborconstant(Ani), 1); //Change the animation
			} else if(Disx >= -RxMax && Disx <= -RxMin && Disy >= RyMin && Disy <= RyMax && dir == 0 && MP >= Limit) // Target within range on left facing?
			{
				mpcost(Limit);
				executeanimation(self, openborconstant(Ani), 1); //Change the animation
			}
		}
    }
}

void cancelmpHit(int RxMin, int RxMax, int RyMin, int RyMax, int Limit, void Ani)
{// Enemy attack interruption with range, MP and didhit check (ENEMY RAGE CANCEL)
	void self 	= getlocalvar("self");
	void target = findtarget(self); //Get nearest player
	float x 	= getentityproperty(self, "x");
	float y 	= getentityproperty(self, "y");
	int MP		= getentityproperty(self, "mp"); //Get entity's MP
	int dir 	= getentityproperty(self, "direction");
	int Hit		= getentityproperty(self, "animhits");

	if(target!=NULL()){
		float Tx = getentityproperty(target, "x");
		float Ty = getentityproperty(target, "y");
		float Disx = Tx - x;
		float Disy = Ty - y;

		if(Disx >= RxMin && Disx <= RxMax && Disy >= RyMin && Disy <= RyMax && dir == 1 && MP >= Limit && Hit >= 1) // Target within range on right facing?
		{
			mpcost(Limit);
			changeentityproperty(self, "velocity", 0, 0, 0);
			executeanimation(self, openborconstant(Ani), 1); //Change the animation
		} else if(Disx >= -RxMax && Disx <= -RxMin && Disy >= RyMin && Disy <= RyMax && dir == 0 && MP >= Limit && Hit >= 1) // Target within range on left facing?
		{
			mpcost(Limit);
			changeentityproperty(self, "velocity", 0, 0, 0);
			executeanimation(self, openborconstant(Ani), 1); //Change the animation
		}
	}
}

void cancelfall(void Ani)
{// Cancel Player Throw or Slam Fall if defined button is pressed
    void self	= getlocalvar("self");
    int Health 	= getentityproperty(self,"health");
	int iPIndex = getentityproperty(self,"playerindex");
		
	if(Health >= 1){
		if(playerkeys(iPIndex, 0, "jump") && playerkeys(iPIndex, 0, "moveup")){
			executeanimation(self, openborconstant(Ani), 1);
		}
	}
}

void cancelfallX(void Ani)
{// Cancel Enemy Throw or Slam Fall RANDOMLY
    void self 	= getlocalvar("self");
  	int Health 	= getentityproperty(self,"health");
	int iR 		= rand()%4;
	
	if(Health >= 1){
		if(iR >= 0 && iR <= 3){
			executeanimation(self, openborconstant(Ani), 1);
		}
	}
}

void cancelfallE(void Ani)
{// Cancel Enemy Throw or Slam Fall (JET FALL)
	void self 	= getlocalvar("self");
	int Health 	= getentityproperty(self,"health");

	if(Health >= 1)
	{
		executeanimation(self, openborconstant(Ani), 1);
	}
}

void landsafe()
{//Alternate safe landing with script
	void self = getlocalvar("self");

	changeentityproperty(self,"damage_on_landing",0);
	changeentityproperty(self,"nograb",0);
	changeentityproperty(self,"aiflag","falling",0);
	changeentityproperty(self,"aiflag","jumping",1);
	changeentityproperty(self,"aiflag","drop",0);
	changeentityproperty(self,"aiflag","projectile",0);
	changeentityproperty(self,"takeaction", "common_jump");
}

void landframe()
{//Alternate landframe with script to avoid performattack/landframe bug
 //Loops previous frame only
 //Used in any animation thats have normal landframe bug
	void self 	= getlocalvar("self");
	int Frame	= getentityproperty(self,"animpos");
	int Height	= getentityproperty(self,"y");

	if(Height >= 1){
		updateframe(self, Frame-1);
	}
}

void flip()
{// Flip to opposite direction
	void self 	= getlocalvar("self");
	int dir 	= getentityproperty(self,"direction");

	if(dir==0){ // Facing left?
		changeentityproperty(self, "direction", 1);
	} else {
		changeentityproperty(self, "direction", 0);
	}
}

void flipX()
{// Flip to opposite direction randomly (JET LANDSAFE)
    void self 	= getlocalvar("self");
    int dir 	= getentityproperty(self,"direction");
	int iR 		= rand()%4;

	if(iR >= 0 && iR <= 2){
		changeentityproperty(self, "direction", 1);
    } else if(iR >= 3 && iR <= 4){
		changeentityproperty(self, "direction", 0);
    }
}

void hpcost(int Cost)
{// Spend some Health
	void self 	= getlocalvar("self");
	int Health	= getentityproperty(self,"health"); //Get entity's Health

	changeentityproperty(self, "health", Health-Cost); //Spend!
}

void mpcost(int Cost)
{// Spend some MP
	void self 	= getlocalvar("self");
	int MP 		= getentityproperty(self,"mp"); //Get entity's MP

	changeentityproperty(self, "mp", MP-Cost); //Spend!
}

void addmp(int Add)
{// Add some MP (MRX RELOAD)
	void self 	= getlocalvar("self");
	int MP 		= getentityproperty(self,"mp");

	changeentityproperty(self, "mp", MP+Add); //Recharge!
}

void suicideP()
{// Suicide if your caller is a Parent and if are dead
	void self 	= getlocalvar("self");
	void target = getlocalvar("Target" + self);
	int THealth = getentityproperty(target, "health");
	
	if(target==NULL())
	{
		target = getentityproperty(self, "parent");
		setlocalvar("Target" + self, target);
	}
	
	if(target!=NULL()){
		if(THealth <= 0)
		{
			killentity(self);
		}
	}
}

void suicide()
{// Suicide!!
	void self = getlocalvar("self");

	killentity(self); //Suicide!
}

void SmartHurt(float Damage, int Knock, int Tipe, int Arah)
{/*
    Originally smartbomb by
    Damon Vaughn Caskey
    07152008

    Hurt effect which hits all enemies
    
    Damage: how much damage enemies will take
    Knock: how much knockdown power enemies will take
    Tipe: which damage type enemies will take
    */
    void vSelf     = getlocalvar("self");             //Caller.
    void vEntity;                                     //Target entity placeholder.
    int  iEntity;                                     //Entity enumeration holder.
    int  iType;                                       //Entity type.
    int  iAnim;                                       //Entity animation.
    int  iDir;                                       //Entity direction.
    int  iHealth;                                       //Entity health.
    int  iMax      = openborvariant("count_entities");  //Entity count.

     //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){    
        vEntity = getentity(iEntity);                 //Get target entity from current loop.
        iType   = getentityproperty(vEntity, "type"); //Get target type.
        iHealth = getentityproperty(vEntity, "health");
        iAnim   = getentityproperty(vEntity,"animationID");

	if(iType == openborconstant("TYPE_ENEMY") && iHealth > 0){ // enemy type?
	  if(iAnim != openborconstant("ANI_SPAWN") && iAnim != openborconstant("ANI_FOLLOW1") && iAnim != openborconstant("ANI_FOLLOW2")){ // not in forbidden animations?
            int Dir = getentityproperty(vSelf, "direction");

	    if(Arah == -1){
	      if(Dir == 1){
	        iDir = 0;
	      } else { iDir = 1; }
	    } else {
	      iDir = Dir;
	    }

	    changeentityproperty(vEntity, "position", NULL(), NULL(), 0);

	    if(Tipe == 7){
	      damageentity(vEntity, vEntity, Damage, Knock, openborconstant("ATK_NORMAL7"));
  	    } else if(Tipe == 6){
  	      damageentity(vEntity, vEntity, Damage, Knock, openborconstant("ATK_NORMAL6"));
	    } else if(Tipe == 5){
	      damageentity(vEntity, vEntity, Damage, Knock, openborconstant("ATK_NORMAL5"));
	    } else if(Tipe == 4){
	      damageentity(vEntity, vEntity, Damage, Knock, openborconstant("ATK_NORMAL4"));
	    } else if(Tipe == 3){
	      damageentity(vEntity, vEntity, Damage, Knock, openborconstant("ATK_NORMAL3"));
	    } else if(Tipe == 2){
	      damageentity(vEntity, vEntity, Damage, Knock, openborconstant("ATK_NORMAL2"));
	    } else {
	      damageentity(vEntity, vEntity, Damage, Knock, openborconstant("ATK_NORMAL"));
	    }
	    changeentityproperty(vEntity, "direction", iDir);
          }
	}
    }
}

void SmartLamp(void Ent)
{/*
    Places lamp or spotlight FX on enemies    
    Ent: Name of entity to be spawned as lamp
    */
    void vEntity;                                     //Target entity placeholder.
    int  iEntity;                                     //Entity enumeration holder.
    int  iType;                                       //Entity type.
    int  iAnim;                                       //Entity animation.
    int  iDir;                                       //Entity type.
    int  iMax      = openborvariant("count_entities");  //Entity count.
    int  iHealth;                                       //Entity health.
    void Lampu; int iEx; int iEz;

     //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){    
        vEntity = getentity(iEntity);                 //Get target entity from current loop.
        iType   = getentityproperty(vEntity, "type"); //Get target type.
        iHealth = getentityproperty(vEntity, "health");
        iAnim   = getentityproperty(vEntity,"animationID");

	if(iType == openborconstant("TYPE_ENEMY") && iHealth > 0){ // enemy type?
	  if(iAnim != openborconstant("ANI_SPAWN") && iAnim != openborconstant("ANI_FOLLOW1") && iAnim != openborconstant("ANI_FOLLOW2")){ // not in forbidden animations?
	    void self = getlocalvar("self");
	    int iMap = getentityproperty(self,"map");

            iEx = getentityproperty(vEntity,"x");
            iEz = getentityproperty(vEntity,"z");

	    Lampu = spawn01(Ent, 0, 0, 0);

	    changeentityproperty(Lampu, "position", iEx, iEz, 0);
	    changeentityproperty(Lampu, "map", iMap);
          }
	}
    }
}

void SmartDrops(void Ent, int Alt, int Vx, int Vy)
{/*
    Drops something on enemies    
    Ent: Name of entity to be dropped
    Vx : x velocity
    Vy : y velocity
    */
    void vEntity;                                     //Target entity placeholder.
    int  iEntity;                                     //Entity enumeration holder.
    int  iType;                                       //Entity type.
    int  iAnim;                                       //Entity animation.
    int  iDir;                                       //Entity type.
    int  iMax      = openborvariant("count_entities");  //Entity count.
    int  iHealth;                                       //Entity health.
    void Drop; int iEx; int iEz; int xDist;

     //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){    
        vEntity = getentity(iEntity);                 //Get target entity from current loop.
        iType   = getentityproperty(vEntity, "type"); //Get target type.
        iHealth = getentityproperty(vEntity, "health");
        iAnim   = getentityproperty(vEntity,"animationID");

	if(iType == openborconstant("TYPE_ENEMY") && iHealth > 0){ // enemy type?
	  if(iAnim != openborconstant("ANI_SPAWN") && iAnim != openborconstant("ANI_FOLLOW1") && iAnim != openborconstant("ANI_FOLLOW2")){ // not in forbidden animations?
	    void self = getlocalvar("self");
	    int Dir = getentityproperty(self,"direction");

            iEx = getentityproperty(vEntity,"x");
            iEz = getentityproperty(vEntity,"z");

	    if(Vy < 0){     
	      Vy = -Vy; //Reverse Vy direction to make it positive  
	    }

	    xDist = 2*Vx*Alt/Vy;

	    if(Dir == 0){ //Is entity facing left?                  
	      xDist = -xDist; //Reverse Vx direction to match facing       
	      Vx = -Vx; //Reverse Vx direction to match facing  
	    }

	    Drop = spawn01(Ent, 0, 0, 0);

	    changeentityproperty(Drop, "position", iEx-xDist, iEz, Alt);
	    changeentityproperty(Drop, "velocity", Vx, 0, -Vy);
          }
	}
    }
}


void KillAllEnt(char Name)
{/*
    Kills all entities with defined alias 
  
    Name: Name of entity to be killed
    */

    void vEntity;                                       //Target entity placeholder.
    int  iEntity;                                       //Entity enumeration holder.
    char iName;                                         //Entity Name.
    int  iMax      = openborvariant("count_entities");  //Entity count.

    //Enumerate and loop through entity collection.
    for(iEntity=0; iEntity<iMax; iEntity++){
      vEntity = getentity(iEntity);                 //Get target entity from current loop.
      iName   = getentityproperty(vEntity, "name"); //Get target name.
      
      if(iName == Name){ //Same alias?
        killentity(vEntity);
      }
    }
}

// EFFECTS///////////////////////////////////////////////////////////////////////////

void sampleplay(void path, int loop)
{// Play defined sample
	void self 	= getlocalvar("self");
	void sample = loadsample(path);

	playsample(openborconstant(sample), 0, 120, 120, 100, loop);
}

void sampleplayN(void path, void name, int loop)
{//Play defined sample if an entity have the specified NAME(ALIAS, NOT DEFAULT NAME)
	void self 	= getlocalvar("self");
	void vName 	= getentityproperty(self, "name");
	void sample = loadsample(path);

	if(vName == name){
		playsample(openborconstant(sample), 0, 120, 120, 100, loop);
	}
}

void musicPlay(void path, int loop)
{//Play defined music
	void self = getlocalvar("self");

	playmusic(path, loop);
}

void shivaMusicX()
{//Play random musics
	void music1 = "data/music/shiva1.ogg";
	void music2 = "data/music/shiva2.ogg";
	void music;
	int  iR 	= rand()%99;

	if(iR >= 0 && iR <= 98){
		music = music2;
	}else{
		music = music1;
	}
		
	playmusic(music, 1);
}

void sampleX(void path1, void path2, int loop)
{//Play two random samples (ST1C THUNDER)
	void self 	 = getlocalvar("self");
	void sample1 = loadsample(path1);
	void sample2 = loadsample(path2);
	void sample;
	int  iR 	 = rand()%4;

	if(iR >= 0 && iR <= 3){
		sample = sample1;
	}else{
		sample = sample2;
	}
		
	playsample(openborconstant(sample), 0, 120, 120, 100, loop);
}
void GoStealth()
{//Stealth Cloak activated
void self = getlocalvar("self");
changeentityproperty(self, "stealth", 1);
changedrawmethod(self, "alpha", 6);
changedrawmethod(self, "channelr", 0);
changedrawmethod(self, "channelg", 64);
changedrawmethod(self, "channelb", 0);
//changedrawmethod(self, "gfxshadow", 0);
}