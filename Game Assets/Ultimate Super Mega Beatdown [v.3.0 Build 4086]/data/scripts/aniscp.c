



void changeanitothrowbykey(void Key, int Hflag, int damage)
{ //Throws entity if a key combo is pressed during an animation
  //place this command a frame after the actual hit
  //V0.06 Matman
  void self = getlocalvar("self");
  void target = getentityproperty(self, "opponent");
  int Direction = getentityproperty(self, "direction");
  void Health = getentityproperty(target,"health");
  void iRKey = checkkeycombo(self, Key, Hflag);
  void cancon = 0;

   if (iRKey)
    {
     cancon = isinpainanimation(target);
     if (cancon == 1) //only throw enemy if he is in pain
     {

       if ((Health - damage) > 1)
       {
         changeentityproperty(target, "damage_on_landing", damage);
       }

       performattack(self, openborconstant("ANI_THROW"));
       if (Direction == 0){ //left
         tossentity(target, 4, 3, 0);
       } else { tossentity(target, 4, -3, 0); }
       changeentityproperty(target, "animation", openborconstant("ani_fall"));
       statusthrown(1, target);
       //throwenemy(10,10,0);
     }
   }
}


void changeanitothrowbykeydetailed(void throwani, void Key, int Hflag, int x, int y, int z)
{ //Throws entity if a key combo is pressed during an animation
  //place this command a frame after the actual hit
  //throwani: animation to use as throw
  //Key: key combo
  //hflag: key combo type
  //x,y,z: direction to throw. automatically takes account of direction for x
  //V0.04 Matman
  void self = getlocalvar("self");
  void target = getentityproperty(self, "opponent");
  int Direction = getentityproperty(self, "direction");
  void iRKey = checkkeycombo(self, Key, Hflag);
  void cancon = 0;

   if (iRKey)
    {
     cancon = isinpainanimation(target);
     if (cancon == 1) //only throw enemy if he is in pain
     {
       performattack(self, openborconstant(throwani));
       statusthrown(1, target);
       //changeentityproperty(target, "aiflag", "falling", 1);
       //changeentityproperty(target, "animation", openborconstant("ani_fall"));
       if (Direction == 0){ //left
         tossentity(target, y, x, z);
       } else { tossentity(target, y, -x, z); }

       //throwenemy(10,10,0);
     }
   }
}


void changeanitothrowifpain(void Ani, void targetani, int changedirection, int vx, int vy, int vz)
{// Change's self animation to throw enemy
// V0.04 Matman:
    void self = getlocalvar("self");
    void target = getentityproperty(self, "opponent");
    void Health = getentityproperty(self,"health");
    int Direction = getentityproperty(self, "direction");
    int cancon = 0;
    cancon = isinpainanimation(target);

    if ( cancon = 1 && Health > 0){
      statusthrown(1, target);
      //changeentityproperty(target, "animation", openborconstant(targetani)); //damage_on_landing
      //changeentityproperty(target, "aiflag", "falling", 1);
      //changeentityproperty(target, "damage_on_landing", 1); //when I use this the character get stuck while standing up.
      performattack(self, openborconstant(Ani));
      if (Direction == 0){ //left
        if (changedirection == 1) { changeentityproperty(self, "direction", 1); }
        tossentity(target, vy, vx, vz);
      } else {
        if (changedirection == 1) { changeentityproperty(self, "direction", 0); }
        tossentity(target, vy, -vx, vz);
        //tossentity(target, 4, -3, 0);
      }

      }
}


void enemypositionduringfall(float dx, float dy, float dz)
{ // Modify grabbed entity's position relative to grabber
 //V 0.03
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);
   void thealth = getentityproperty(target, "health");
   void aniID = 0;
   void canCont = 0;
   int direction = getentityproperty(self, "direction");
   float fx;
   float fy;
   float fz;

   //if(target==NULL())
   //{
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);

     canCont = isinfallanimation(target);

   //}
   if( target!=NULL() && thealth > 0 )
   {
     if (canCont==1)
     {

       //settextobj(0, 50, 30, 0, -1, "flop");

       //make sure it pushes the entity back
       if (direction == 1) { fx = getentityproperty(self, "x") + dx ; } else
       if (direction == 0) { fx = getentityproperty(self, "x") - dx ; }
       //updateframe(target, Frame);
        //Get X location and add adjustment.
       fy = dy + getentityproperty(self, "a"); //Get Y location and add adjustment.
       fz = dz + getentityproperty(self, "z"); //Get Z location and add adjustment.

       changeentityproperty(target, "position", fx, fz, fy);

     }
   }
}


void enemypositionduringfallx(float dx)
{
   //v 0.03  Matman
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);
   void thealth = getentityproperty(target, "health");
   void aniID = 0;
   void canCont = 0;
   int direction = getentityproperty(self, "direction");
   float fx;
   float fy;
   float fz;


   //if(target==NULL())
   //{
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
     canCont = isinfallanimation(target);


   //}
   if( target!=NULL() && thealth > 0 )
   {
     if (canCont==1 )
     {


       //make sure it pushes the entity back
       if (direction == 1) { fx = getentityproperty(self, "x") + dx ; } else
       if (direction == 0) { fx = getentityproperty(self, "x") - dx ; }
       //updateframe(target, Frame);
        //Get X location and add adjustment.
       fy = getentityproperty(target, "a"); //Get Y location and add adjustment.
       fz = getentityproperty(target, "z"); //Get Z location and add adjustment.

       changeentityproperty(target, "position", fx, fz, fy);

     }
   }
}


void enemypositionduringpain(float dx, float dy, float dz)
{ // Modify grabbed entity's position relative to grabber
 //V 0.2
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);
   void aniID = 0;
   void canCont = 0;
   int direction = getentityproperty(self, "direction");
   float fx;
   float fy;
   float fz;

   //if(target==NULL())
   //{
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);


     canCont = isinpainanimation(target);

   //}
   if( target!=NULL() )
   {
     if (canCont==1)
     {

       //settextobj(0, 50, 30, 0, -1, "flop");

       //make sure it pushes the entity back
       if (direction == 1) { fx = getentityproperty(self, "x") + dx ; } else
       if (direction == 0) { fx = getentityproperty(self, "x") - dx ; }
       //updateframe(target, Frame);
        //Get X location and add adjustment.
       fy = dy + getentityproperty(self, "a"); //Get Y location and add adjustment.
       fz = dz + getentityproperty(self, "z"); //Get Z location and add adjustment.

       changeentityproperty(target, "position", fx, fz, fy);

       //bindentity(target, self, dx, dz, dy, face, 0);
       //bindentity(target, NULL());
       //bindentity(self, NULL());
     }
   }
}


void enemypositionduringpainx(float dx)
{ // Modify grabbed entity's position relative to grabber
 //v 0.2
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);
   void aniID = 0;
   void canCont = 0;
   int direction = getentityproperty(self, "direction");
   float fx;
   float fy;
   float fz;


   //if(target==NULL())
   //{
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
     canCont = isinpainanimation(target);


   //}
   if( target!=NULL() )
   {
     if (canCont==1)
     {


       //make sure it pushes the entity back
       if (direction == 1) { fx = getentityproperty(self, "x") + dx ; } else
       if (direction == 0) { fx = getentityproperty(self, "x") - dx ; }
       //updateframe(target, Frame);
        //Get X location and add adjustment.
       fy = getentityproperty(target, "a"); //Get Y location and add adjustment.
       fz = getentityproperty(target, "z"); //Get Z location and add adjustment.

       changeentityproperty(target, "position", fx, fz, fy);

     }
   }
}


void tossentityduringfall(float x, float y, float z)
{
  // V 0.06
  void self = getlocalvar("self");
  void target = getentityproperty(self, "opponent");
  void thealth = getentityproperty(target, "health");
  int Direction = getentityproperty(self, "direction");
  void cancon = isinfallanimation(target);
  if (cancon == 1 && thealth > 0)
  {
      if ( self != NULL() && target != NULL()){
        if ( checkrange(self, target) ) { cancon = 1; } else { cancon = 0; }
      }
      //if ( thealth == 0 ) { cancon = 0; }
      //checkrange(entity, target, int animid)

      if (cancon == 1)
      {
        //log(" can toss during fall " +x+y+z);
        if (Direction == 0){ //left
             tossentity(target, y, x, z);
           } else { tossentity(target, y, -x, z); }
        statusthrown(1, target);
      }
  }
}


void tossentityduringfallnorange(float x, float y, float z)
{ //Tosses enemy if they are falling and does no range check.
  // V 0.03
  void self = getlocalvar("self");
  void target = getentityproperty(self, "opponent");
  //void thealth = getentityproperty(target, "health");
  int Direction = getentityproperty(self, "direction");
  void cancon = isinfallanimation(target);
  if (cancon == 1 )//&& thealth > 0)
  {

      if (cancon == 1)
      {
        //log(" can toss during fall " +x+y+z);
        if (Direction == 0){ //left
             tossentity(target, y, x, z);
           } else { tossentity(target, y, -x, z); }
        statusthrown(1, target);
      }
  }
}




void bounceofwall(int isTrue)
{// Checks if there is wall at defined distance
  // V 0.03
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if (Direction == 0){ //Is entity facing left?
     H = checkwall(x+10,z);
   }  else {
     H = checkwall(x-10,z);
   }
   /*
   if (checkwall(x,z-10) > 0) {
     Hz = 1;
   } else {
     if (checkwall(x,z+10) > 0) {
       Hz = -1;
     }
   }
   */
   if (H > 0)
   {
     if (Direction == 0){ //Is entity facing left?
         changeentityproperty(self, "direction", 1);
         tossentity(self, -1, 1.5, 0);
       }  else {
         changeentityproperty(self, "direction", 0);
         tossentity(self, 1, 1.5, 0);
       }
   }
   /*
   if (Hz > 0)
   {
     tossentity(self, 0, 1.5, -0.5);
   } else {
     if (Hz < 0)
     {
       tossentity(self, 0, 1.5, 0.5);
     }
   }
   */
}


void breakgrabchangeanibykeytoattack(void Ani, int Frame, void Key, int Hflag, int Limit)
{// Change current animation if proper key is pressed or released provided HP is more than limit
// V0.03
// Matman
    void self = getlocalvar("self");
    int Direction = getentityproperty(self, "direction");
    int iPIndex = getentityproperty(self,"playerindex"); //Get player index
    void iRKey = checkkeycombo(self, Key, Hflag);

    if (iRKey)
    {
      grabfree(1, self);
      changeanibykeytoattack(Ani,Frame,Key,Hflag,Limit);
    }
}


void changeanibykey(void Ani, int Frame, void Key, int Hflag, int Limit)
{// Change current animation if proper key is pressed or released provided HP is more than limit
// V0.02
// Matman
    void self = getlocalvar("self");
    void Health = getentityproperty(self,"health");
    int Direction = getentityproperty(self, "direction");
    int iPIndex = getentityproperty(self,"playerindex"); //Get player index
    void iRKey = checkkeycombo(self, Key, Hflag);

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


void changeanibykeydirection(void Ani, void Key, int Hflag, int Direction)
{// Change current animation if proper key is pressed and option to change direction
// V0.02
   void self = getlocalvar("self");
  void target = getentityproperty(self, "opponent");
  int Direction = getentityproperty(self, "direction");
  int iPIndex = getentityproperty(self,"playerindex"); //Get player index
  void iRKey = checkkeycombo(self, Key, Hflag);

   if (iRKey)
    {

     if (Direction == 0){ //left
       changeentityproperty(self, "direction", 1);
     } else {
        changeentityproperty(self, "direction", 0);
     }
     performattack(self, openborconstant(Ani));

   }

}


void changeanibykeytoattack(void Ani, int Frame, void Key, int Hflag, int Limit)
{// Change current animation if proper key is pressed or released provided HP is more than limit
// V0.02
// Matman
    void self = getlocalvar("self");
    void Health = getentityproperty(self,"health");
    int Direction = getentityproperty(self, "direction");
    int iPIndex = getentityproperty(self,"playerindex"); //Get player index
    void iRKey = checkkeycombo(self, Key, Hflag);

      if ((Health > Limit)&&iRKey){
        performattack(self, openborconstant(Ani));

      }
}


void changeanitoattackiffall(void Ani)
{// Force's change on current animation if enemy is falling
// V0.01 Matman:
    void self = getlocalvar("self");
    void target = getentityproperty(self, "opponent");
    void Health = getentityproperty(self,"health");
    int cancon = 0;
    cancon = isinfallanimation(target);

    if ( cancon = 1 && Health > 0){
      performattack(self, openborconstant(Ani));

      }
}


void changeanitoattackifpain(void Ani)
{// Force's change on current animation if enemy is in pain
// V0.01 Matman:
    void self = getlocalvar("self");
    void target = getentityproperty(self, "opponent");
    void Health = getentityproperty(self,"health");
    int cancon = 0;
    cancon = isinpainanimation(target);

    if ( cancon = 1 && Health > 0){
      performattack(self, openborconstant(Ani));

      }
}


void changeanitosselfbykeydetailedfall(void newani, void Key, int Hflag, float x, float y, float z)
{
  //place this command a frame after the actual hit
  //throwani: animation to use as throw
  //Key: key combo
  //hflag: key combo type
  //x,y,z: direction to throw self. automatically takes account of direction for x
  //V0.04 Matman
  void self = getlocalvar("self");
  void target = getentityproperty(self, "opponent");
  int Direction = getentityproperty(self, "direction");
  void thealth = getentityproperty(target, "health");
  void cancon = 0;

  void iRKey = checkkeycombo(self, Key, Hflag);

   if (iRKey)
    {
     cancon = isinfallanimation(target);
     if (cancon == 1 && thealth > 0) //only throw enemy is falling
     {
       performattack(self, openborconstant(newani));
       if (Direction == 0){ //left
         tossentity(self, y, x, z);
       } else { tossentity(self, y, -x, z); }
       if ( getentityproperty(self, "a") > 20)
         {
           changeentityproperty(self, "aiflag", "jumping", 1);
         }
     }
   }
}


void changedirectionbykey(void Key, void Hflag)
{
  //v 0.02
  void self = getlocalvar("self");
  int Direction = getentityproperty(self, "direction");
  void iRKey = checkkeycombo(self, Key, Hflag);

  if (iRKey)
  {
    if (Direction == 0){ //Is entity facing left?
        changeentityproperty(self, "direction", 1);
      } else {
        changeentityproperty(self, "direction", 0);
      }
  }


}


void entityincreasehealth(float amount)
{// increase current health amount, not max health.
// V0.01 Matman
    void self = getlocalvar("self");
    increasehealthforentity( self, amount );

}


void entityincreasespeed(float amount)
{// increase current speed amount.
// V0.02 Matman
    void self = getlocalvar("self");
    increasespeedforentity( self, amount );
    /*
    void cmp = getentityproperty(self,"speed");
    cmp = cmp + (amount);
    changeentityproperty(self, "speed", cmp);
    */
}




void freeself(int istrue)
{ // Kills entity without playing the death animation
// V0.01 Matman
   if (istrue == 1) {
     void self = getlocalvar("self");
     killentity(self);
   }

}


void spawnchildentity(void vName, float fX, float fY, float fZ, int iH)
{
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
      //fY: Z location adjustment.
      //iH: Spawn type.

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
        void Health = getentityproperty(self,"health");
	int  iDirection = getentityproperty(self, "direction"); // Get caller's direction.
	int  iMap = getentityproperty(self, "map"); // Get caller's remap.

        loadmodel(vName);

        clearspawnentry(); //Clear current spawn entry.
        setspawnentry("name", vName); //Acquire spawn entity by name.

	if (iDirection == 0){ //Is entity facing left?
          fX = -fX; ////Reverse X direction to match facing.
	}

      fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
      fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
      fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.

	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.

	if (iH == 0){ // For spawning AI control entity
	  changeentityproperty(vSpawn, "parent", self); //Set caller as parent.
      }
	if (iH == 1){ // For spawning dead fallen rider
        damageentity(vSpawn, self, 1000, 1, openborconstant("ATK_NORMAL"));
	  if (iDirection == 1){
          tossentity(vSpawn, 3, -1, 0);
        } else {tossentity(vSpawn, 3, 1, 0);}
      }
	if (iH == 2){ // For spawning motor
	  changeentityproperty(vSpawn, "map", iMap); //Set map.
      }
	return vSpawn; //Return spawn.
}


void spawnentity(void vName, float fX, float fY, float fZ, int iH)
{
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
        //fY: Z location adjustment.
        //iH: Spawn type.


	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
        void Health = getentityproperty(self,"health");
	int  iDirection = getentityproperty(self, "direction"); // Get caller's direction.
	int  iMap = getentityproperty(self, "map"); // Get caller's remap.

        loadmodel(vName);

	clearspawnentry(); //Clear current spawn entry.
        setspawnentry("name", vName); //Acquire spawn entity by name.

	if (iDirection == 0){ //Is entity facing left?
          fX = -fX; ////Reverse X direction to match facing.
	}

      fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
      fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
      fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.

	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.

	if (iH == 0){ // For spawning AI control entity
	  //changeentityproperty(vSpawn, "parent", self); //Set caller as parent.
      }
	if (iH == 1){ // For spawning dead fallen rider
        damageentity(vSpawn, self, 1000, 1, openborconstant("ATK_NORMAL"));
	  if (iDirection == 1){
          tossentity(vSpawn, 3, -1, 0);
        } else {tossentity(vSpawn, 3, 1, 0);}
      }
	if (iH == 2){ // For spawning motor
	  changeentityproperty(vSpawn, "map", iMap); //Set map.
      }
	return vSpawn; //Return spawn.
}


void spawnentitylesspercentage(void vName, float fX, float fY, float fZ, int iH, int lessthanprecentage)
{//Only spawns if health percentage is less that specified
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
      //fY: Z location adjustment.
      //iH: Spawn type.

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn;
        float spawnershealth = gethealthpercentageforentity(self);


	if (spawnershealth < lessthanprecentage )
	{
	  //settextobj(1, 100, 50, 0, -1, getentityproperty(self,"health"));
           vSpawn = spawnentity(vName,fX,fY,fZ,iH);
        }
	return vSpawn; //Return spawn.
}


void stopself(int i)
{// Stop enemy's movement!
 //Matman V 0.02

    void vSelf = getlocalvar("self");

    changeentityproperty(vSelf, "aiflag", "running", 0);
    changeentityproperty(vSelf, "animation", openborconstant("ANI_Idle"));
    changeentityproperty(vSelf, "velocity", 0, 0, 0);
}


void teleportbehindnearestenemy(int dx, int dy, int dz)
{// Targetting opponent then teleport to target
  // V 0.02
    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction");
    int enemdir = 0;

    if(dir==0){ // Facing left?
      dx = -dx ;
    }

    setlocalvar("T"+self, findtarget(self)); //Get nearest player
    void target = getlocalvar("T"+self);
    enemdir = getentityproperty(target, "direction");

    if( getlocalvar("T"+self) != NULL()){

      int Tx = getentityproperty(target, "x");
      int Tz = getentityproperty(target, "z");


      changeentityproperty(self, "position", Tx+dx, Tz+dz, dy); //Teleport to target!
      if (dir == 0)
      {
        if (Tx+dx > dx)
        {
          changeentityproperty(self, "direction", 1);
        } else
        {
          changeentityproperty(self, "direction", 0);
        }
      } else
      {
         if (Tx+dx > dx)
        {
          changeentityproperty(self, "direction", 0);
        } else
        {
          changeentityproperty(self, "direction", 1);
        }
      }
      //changeentityproperty(self, "direction", enemdir); //Teleport to target!
    }
}


void teleportinfrontnearestenemy(int dx, int dy, int dz)
{// Targetting opponent then teleport to target
 // V 0.02
    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction");
    int enemdir = 0;

    if(dir==1){ // Facing left?
      dx = -dx ;
    }

    setlocalvar("T"+self, findtarget(self)); //Get nearest player
    void target = getlocalvar("T"+self);
    enemdir = getentityproperty(target, "direction");

    if( getlocalvar("T"+self) != NULL()){

      int Tx = getentityproperty(target, "x");
      int Tz = getentityproperty(target, "z");

      if (enemdir==1)
      {
        enemdir = 0;
      } else
      if (enemdir==0)
      {
        enemdir = 1;
      }

      changeentityproperty(self, "position", Tx+dx, Tz+dz, dy); //Teleport to target!
      changeentityproperty(self, "direction", enemdir); //Teleport to target!
    }
}


void tossself(int changedirection, float x, float y, float z)
{
  // v 0.02
  void self = getlocalvar("self");
  int Direction = getentityproperty(self, "direction");
  if (Direction == 0)
  { //left
    tossentity(self, y, x, z);
    if ( changedirection = 1)
    {
      changeentityproperty(self, "direction", 1);
    }
  } else {
    tossentity(self, y, -x, z);
    if ( changedirection = 1)
    {
      changeentityproperty(self, "direction", 0);
    }
  }
}


void tossselfbykey(void Key, int Hflag, int changedirection, float x, float y, float z)
{ //Throws self if a key combo is pressed during an animation
  //V0.04 Matman
  void self = getlocalvar("self");
  int Direction = getentityproperty(self, "direction");
  int iPIndex = getentityproperty(self,"playerindex"); //Get player index
  void iRKey = checkkeycombo(self, Key, Hflag);

   if (iRKey)
    {
       if (Direction == 0){ //left
         tossentity(self, y, x, z);
         if ( changedirection = 1)
         {
           changeentityproperty(self, "direction", 1);
         }

       } else {
         tossentity(self, y, -x, z);
         if ( changedirection = 1)
         {
           changeentityproperty(self, "direction", 0);
         }
         if ( getentityproperty(self, "a") > 20)
         {
           changeentityproperty(self, "aiflag", "jumping", 1);
         }
       }
   }
}




void grabfree(int isTrue, void vself)
{// releases player and enemy grab state
  // V 0.02
   //void self = getlocalvar("self");
   void target = getentityproperty(vself, "opponent");
   //void target = getlocalvar("Target" + vself);

   if(target==NULL())
   {
     target = getentityproperty(vself, "grabbing");
     setlocalvar("Target" + vself, target);
   }
   if(target!=NULL())
   {
     bindentity(target, NULL());
     bindentity(vself, NULL());
     changeentityproperty(target, "aiflag", "idling", 1);
     changeentityproperty(target, "animation", openborconstant("ani_idle"));
     //performattack(target, openborconstant("ANI_IDLE"));
     //performattack(vself, openborconstant("ANI_IDLE"));
     /*
     if(Gr == 1)
     {
       int x = getentityproperty(target, "x");
       int z = getentityproperty(target, "z");
       changeentityproperty(target, "position", x, z, 0);
     }
     */
   }
}


void grabrelease(int Gr)
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


void throwenemy(int height, int speedx, int speedz)
{ //
// V0.01 Matman
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     tossentity(target, height, speedx, speedz);
   }

}




int countaliveenemies(int istrue)
{ // Count how many alive enemies there are
// V0.01 Matman
   int cnt = 0;

   cnt = openborvariant("count_enemies");

   return cnt;

}


int countaliveplayers(int istrue)
{ // Count how many alive players there are
// V0.01 Matman
   int cnt = 0;
   cnt = openborvariant("count_players");
   return cnt;
}


void getdifficulty(int istrue)
{ // Get current difficulty setting
// V0.01 Matman
     int cnt = 0;
     cnt = openborvariant("current_set");
     return cnt;

}


int getheight(void entity)
{ // Get entities height
// V0.01 Matman
   int cnt = 0;
   if (entity != NULL())
   {
     cnt = getentityproperty(entity, "height");
     //getentityproperty({ent}, "height"); - Model level height setting.
     //getentityproperty({ent}, "animheight"); - Animation level height setting (current animation).
   }

   return cnt;

}


void isinfallanimation(void target)
{
  // v 0.1 Matman
   void aniID = getentityproperty(target, "animationid");
   void canCont = 0;

        if ( aniID == openborconstant("ANI_FALL")) { canCont = 1;} else
        if (aniID == openborconstant("ANI_FALL2")) { canCont = 1;} else
        if (aniID == openborconstant("ANI_FALL3")) { canCont = 1;} else
        if (aniID == openborconstant("ANI_FALL4")) { canCont = 1;} else
        if (aniID == openborconstant("ANI_FALL5")) { canCont = 1;} else
        if (aniID == openborconstant("ANI_FALL6")) { canCont = 1;} else
        if (aniID == openborconstant("ANI_FALL7")) { canCont = 1;} else
        if (aniID == openborconstant("ANI_FALL8")) { canCont = 1;} else
        if (aniID == openborconstant("ANI_FALL9")) { canCont = 1;} else
        if (aniID == openborconstant("ANI_FALL10")) { canCont = 1; }
        return canCont;
}


void isinpainanimation(void target)
{
  // v 0.2 Matman
   void aniID = getentityproperty(target, "animationid");
   void canCont = 0;

        if ( aniID == openborconstant("ANI_PAIN")) { canCont = 1;} else
        if (aniID == openborconstant("ANI_PAIN2")) { canCont = 1;} else
        if (aniID == openborconstant("ANI_PAIN3")) { canCont = 1;} else
        if (aniID == openborconstant("ANI_PAIN4")) { canCont = 1;} else
        if (aniID == openborconstant("ANI_PAIN5")) { canCont = 1;} else
        if (aniID == openborconstant("ANI_PAIN6")) { canCont = 1;} else
        if (aniID == openborconstant("ANI_PAIN7")) { canCont = 1;} else
        if (aniID == openborconstant("ANI_PAIN8")) { canCont = 1;} else
        if (aniID == openborconstant("ANI_PAIN9")) { canCont = 1;} else
        if (aniID == openborconstant("ANI_SHOCKPAIN")) { canCont = 1; } else
        if (aniID == openborconstant("ANI_BURNPAIN")) { canCont = 1; } else
        if (aniID == openborconstant("ANI_BLOCKPAIN")) { canCont = 1; }
        return canCont;
}


void keypressmultileft(void Key, int iPIndex)
{// returns a openbor key if succesful in-put was entered when facing left
//V0.01 MatMan
    void iRKey;
      //Direction
      if (Key=="U"){ //Up Required?
       iRKey = playerkeys(iPIndex, 0, "moveup"); // "Up"
	} else
        if (Key=="D"){ //Down Required?
          iRKey = playerkeys(iPIndex, 0, "movedown"); // "Down"
	} else
        if (Key=="B"){ //Backwards Required?
          iRKey = playerkeys(iPIndex, 0, "moveright");
	} else
        if (Key=="F"){ //Down Required?
          iRKey = playerkeys(iPIndex, 0, "moveleft");
	} else
      //Keys
        if (Key=="J"){ //Jump Required?
          iRKey = playerkeys(iPIndex, 0, "jump"); // "Jump"
	} else
        if (Key=="A"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "attack"); // "Attack"
        } else
	if (Key=="A2"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "attack2"); // "Attack"
        } else
	if (Key=="A3"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "attack3"); // "Attack"
        } else
	if (Key=="A4"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "attack4"); // "Attack"
	} else
        if (Key=="S"){ //Special Required?
          iRKey = playerkeys(iPIndex, 0, "special"); // "Special"
	}
      if (Key=="JS"){ //Special + jump Required?
        iRKey = playerkeys(iPIndex, 0, "special", "jump"); // "Special"
	}
      //Direction Plus Attack
      if (Key=="UA"){ //Up Attack Required?
        iRKey = playerkeys(iPIndex, 0, "moveup", "attack"); // "Up Attack"
	}
      if (Key=="DA"){
        iRKey = playerkeys(iPIndex, 0, "movedown", "attack"); // "Down Attack"
	}
      if (Key=="BA"){
        iRKey = playerkeys(iPIndex, 0, "moveright", "attack");
	}
      if (Key=="FA"){
        iRKey = playerkeys(iPIndex, 0, "moveleft", "attack");
	}
      //Direction Plus Jump
      if (Key=="UJ"){
        iRKey = playerkeys(iPIndex, 0, "moveup", "jump"); // "Up" + "Jump"
	}
      if (Key=="DJ"){
        iRKey = playerkeys(iPIndex, 0, "movedown", "jump"); // "Down" + "Jump"
	}
      if (Key=="BJ"){
        iRKey = playerkeys(iPIndex, 0, "moveright", "jump"); // "Back" + "Jump"
	}
      if (Key=="FJ"){
        iRKey = playerkeys(iPIndex, 0, "moveleft", "jump"); // "Forwad" + "Jump"
	}
      //Direction Plus Special
      if (Key=="US"){
        iRKey = playerkeys(iPIndex, 0, "moveup", "special"); // "Up" + "special"
	}
      if (Key=="DS"){
        iRKey = playerkeys(iPIndex, 0, "movedown", "special"); // "Down" + "special"
	}
      return iRKey;
}


void keypressmultiright(void Key, int iPIndex)
{// returns a openbor key if succesful in-put was entered when facing right
//V0.01 MatMan
    void iRKey;
      //Direction
      if (Key=="U"){ //Up Required?
       iRKey = playerkeys(iPIndex, 0, "moveup"); // "Up"
	} else
        if (Key=="D"){ //Down Required?
          iRKey = playerkeys(iPIndex, 0, "movedown"); // "Down"
	} else
        if (Key=="B"){ //Backwards Required?
          iRKey = playerkeys(iPIndex, 0, "moveleft"); // "Backwards"
	} else
        if (Key=="F"){ //Down Required?
          iRKey = playerkeys(iPIndex, 0, "moveright"); // "Forward"
	} else
      //Keys
        if (Key=="J"){ //Jump Required?
          iRKey = playerkeys(iPIndex, 0, "jump"); // "Jump"
	} else
        if (Key=="A"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "attack"); // "Attack"
        } else
	if (Key=="A2"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "attack2"); // "Attack"
        } else
	if (Key=="A3"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "attack3"); // "Attack"
        } else
	if (Key=="A4"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "attack4"); // "Attack"
	} else
        if (Key=="S"){ //Special Required?
          iRKey = playerkeys(iPIndex, 0, "special"); // "Special"
	}
       if (Key=="JS"){ //Special Required?
        iRKey = playerkeys(iPIndex, 0, "special", "jump"); // "Special"
	}
      //Direction Plus Attack
      if (Key=="UA"){ //Up Attack Required?
        iRKey = playerkeys(iPIndex, 0, "moveup", "attack"); // "Up Attack"
	}
      if (Key=="DA"){
        iRKey = playerkeys(iPIndex, 0, "movedown", "attack"); // "Down Attack"
	}
      if (Key=="BA"){
        iRKey = playerkeys(iPIndex, 0, "moveleft", "attack"); // "Backwards"
	}
      if (Key=="FA"){
        iRKey = playerkeys(iPIndex, 0, "moveright", "attack"); // "Forward"
	}
      //Direction Plus Jump
      if (Key=="UJ"){
        iRKey = playerkeys(iPIndex, 0, "moveup", "jump"); // "Up" + "Jump"
	}
      if (Key=="DJ"){
        iRKey = playerkeys(iPIndex, 0, "movedown", "jump"); // "Down" + "Jump"
	}
      if (Key=="BJ"){
        iRKey = playerkeys(iPIndex, 0, "moveleft", "jump"); // "Back" + "Jump"
	}
      if (Key=="FJ"){
        iRKey = playerkeys(iPIndex, 0, "moveright", "jump"); // "Forwad" + "Jump"
	}
      //Direction Plus Special
      if (Key=="US"){
        iRKey = playerkeys(iPIndex, 0, "moveup", "special"); // "Up" + "special"
	}
      if (Key=="DS"){
        iRKey = playerkeys(iPIndex, 0, "movedown", "special"); // "Down" + "special"
	}
      return iRKey;
}


void statusthrown(int istrue, void target)
{
  //Set targets thrown status-
  //Istrue = 1 (is true)
  // Matman V 0.03
  if (istrue == 1)
  {
    changeentityproperty(target, "aiflag", "inpain", 0);
    changeentityproperty(target, "aiflag", "idling", 0);
    changeentityproperty(target, "aiflag", "falling", 1);
    changeentityproperty(target, "aiflag", "drop", 1);

    changeentityproperty(target, "attacking", 1);
    changeentityproperty(target, "projectile", 1);
  } else {
    changeentityproperty(target, "attacking", 0);
    changeentityproperty(target, "damage_on_landing", 0);
    changeentityproperty(target, "projectile", 0);
  }
}




void namefemalemedieval(int isTrue)
{
  int i = rand()%45;
  void s = "";
  if (i < 0 )
     {i=i+i+i;}


  if(i==0){s = "Alys";}  else
  if(i==1){s = "Ayleth";} else
  if(i==2){s = "Anastas";} else
  if(i==3){s = "Alianor";} else
  if(i==4){s = "Cedany";} else
  if(i==5){s = "Ellyn";} else
  if(i==6){s = "Helewys";} else
  if(i==7){s = "Malkyn";} else
  if(i==8){s = "Peronell";} else
  if(i==9){s = "Sybbyl";} else
  if(i==10){s = "Ysmay";} else
  if(i==11){s = "Thea";} else
  if(i==12){s = "Jacquelyn";} else
  if(i==13){s = "Countess Amelia";} else
  if(i==14){s = "Gloriana";} else
  if(i==15){s = "Good Queen Bess";} else
  if(i==16){s = "Catherine of Aragon";} else
  if(i==17){s = "Anne of Cleves";} else
  if(i==18){s = "Mary, Queen of Scots";} else
  if(i==19){s = "Mary of Guise";} else
  if(i==20){s = "Arabella";} else
  if(i==21){s = "Elizabeth";} else
  if(i==22){s = "Hildegard";} else
  if(i==23){s = "Brunhild";} else
  if(i==24){s = "Adelaide";} else
  if(i==25){s = "Alice";} else
  if(i==26){s = "Beatrix";} else
  if(i==27){s = "Cristiana";} else
  if(i==28){s = "Eleanor";} else
  if(i==29){s = "Emeline";} else
  if(i==30){s = "Isabel";} else
  if(i==31){s = "Juliana";} else
  if(i==32){s = "Margaret";} else
  if(i==33){s = "Matilda";} else
  if(i==34){s = "Mirabelle";} else
  if(i==35){s = "Rose";} else
  if(i==36){s = "Helena";} else
  if(i==37){s = "Guinevere";} else
  if(i==38){s = "Isolde";} else
  if(i==39){s = "Maerwynn";} else
  if(i==40){s = "Muriel";} else
  if(i==41){s = "Winifred";} else
  if(i==42){s = "Godiva";} else
  if(i==43){s = "Catrain";} else
  if(i==44){s = "Angmar";} else
  if(i==45){s = "Gussalen";}

  return s;
}


void namemalemedieval(int isTrue)
{
  int i = rand()%41;
  void s = "";

  if (i < 0 )
     {i=i+i+i;}


  if(i==0){s = "Ulric";}  else
  if(i==1){s = "Tybalt";} else
  if(i==2){s = "Borin";} else
  if(i==3){s = "Sadon";} else
  if(i==4){s = "Terrowin";} else
  if(i==5){s = "Rowan";} else
  if(i==6){s = "Forthwind";} else
  if(i==7){s = "Althalos";} else
  if(i==8){s = "Fendrel";} else
  if(i==9){s = "Brom";} else
  if(i==10){s = "Hadrian";} else
  if(i==11){s = "Crewe";} else
  if(i==12){s = "Walter De Bolbec";} else
  if(i==13){s = "Derwintwater";} else
  if(i==14){s = "Montagu";} else
  if(i==15){s = "John Fenwick of Wallington";} else
  if(i==16){s = "Oliver Cromwell";} else
  if(i==17){s = "Justice McKinnon";} else
  if(i==18){s = "Clifton Writingham";} else
  if(i==19){s = "Walter deGrey";} else
  if(i==20){s = "Roger de Mowbray";} else
  if(i==21){s = "Joseph Rowntree";} else
  if(i==22){s = "Geoffrey Chaucer";} else
  if(i==23){s = "William of Wykeham";} else
  if(i==24){s = "Francis Drake";} else
  if(i==25){s = "Simon de Montfort";} else
  if(i==26){s = "John of Gaunt";} else
  if(i==27){s = "William of Orange";} else
  if(i==28){s = "Cornwallis";} else
  if(i==29){s = "Edmund Cartwright";} else
  if(i==30){s = "Charles the Bald";} else
  if(i==31){s = "Benedict";} else
  if(i==32){s = "Gregory";} else
  if(i==33){s = "Peter";} else
  if(i==34){s = "Henry";} else
  if(i==35){s = "Frederick";} else
  if(i==36){s = "Walter";} else
  if(i==37){s = "Thomas";} else
  if(i==38){s = "Arthur";} else
  if(i==39){s = "Bryce";} else
  if(i==40){s = "Donald";} else
  if(i==41){s = "Leofrick";}

  return s;
}




void alterallstats(void aentity, int stage, int iDifficulty)
{
  //v 0.06 Matman
  if ( aentity != NULL() )
  {
    //Modify stats
    aentity = maxHealthByStage( aentity, stage, iDifficulty );
    aentity = increaseaggressionforentity( aentity, (iDifficulty+(stage/18)-1) );
    aentity = increasespeedforentity( aentity,(iDifficulty+(stage/40)-1) );

    aentity = increasetholdforentity( aentity, iDifficulty+(stage/14) );
    aentity = increaseblockoddsforentity( aentity, (iDifficulty+(stage/17)-1) );

    //void enemySpawnName = getentityproperty(aentity, "defaultname");
    //log(" enemySpawnName " + enemySpawnName);

    //aentity = increaseknockdowncountforentity( aentity,iDifficulty+(stage/6) );
    //aentity = setdefencepainfromattack( aentity, 40, openborconstant("ANI_ATTACK1"));
    //iChance = rand()%1000;
    //aentity = setriseTime(aentity, -5000);

    aentity = randomcolormap( aentity, 8 );


  }
  return aentity;
}


void checkkeycombo(void vSelf, void Key, int Hflag)
{
 void iRKey;
 int iPIndex = getentityproperty(vSelf,"playerindex");
 int Direction = getentityproperty(vSelf, "direction");
 if (Direction == 0){ //Is entity facing left?
      iRKey = keypressmultileft(Key, iPIndex);
   } else if (Direction == 1) {
      iRKey = keypressmultiright(Key, iPIndex);
   }
   if (Hflag==1){ //Not holding the button case?
        iRKey = !iRKey; //Take the opposite condition
	}
  return iRKey;
}


void decreasehealthforentity(void aentity, int amount)
{
// V0.02 Matman
    if (aentity != NULL())
    {
      void cmp = getentityproperty( aentity,"health" );
      cmp = cmp - amount;
      if (cmp < 1) {
        killentity(aentity);
      } else {
        changeentityproperty(aentity, "health", cmp);
      }
    }
}


void decreasempthenhealth(int amount)
{// Decrease current mp amount and if its less than 0 then decrease health. Not max Mp.
// V0.03
    void self = getlocalvar("self");
    void health = getentityproperty(self,"health");
    void cmp = getentityproperty(self,"mp");
    int ichance = 0;// rand()%45;
    int cancon = 1;
    cmp = cmp - amount;
    if (cmp <= 0)
    {
      health = health + (cmp / 2);
      changeentityproperty(self, "health", health);
      cmp = 0;
    }
    if (cmp < 10) {
      ichance = rand()%100;
      if ( ichance > 85 ) { cancon = 0 ;}
    }
    if ( cmp < 5 && health < 40)
    {
      ichance = rand()%100;
      if ( ichance > 10 ) { cancon = 0 ;}
    }
    changeentityproperty(self, "mp", cmp);
    if ( cancon == 0)
    {
      changeentityproperty(self, "aiflag", "idling", 0);			//Set idle flag.
      changeentityproperty(self, "animation", openborconstant("ani_cant")); //Change the animation
      //changeentityproperty(vEnt, "takeaction", "common_jump");	//Set jump action.
    }
}


void gethealthpercentageforallplayers(int isTrue)
{
// V0.01 Matman
// Returns the total health percentage of all alive human controlled players

    int totalpercentage = 0;
    int alveplayers = 0;

    void P1 = getplayerproperty(0, "entity"); //Get Player 1
    void P2 = getplayerproperty(1, "entity"); //Get Player 2
    void P3 = getplayerproperty(2, "entity"); //Get Player 3
    void P4 = getplayerproperty(3, "entity"); //Get Player 4

    int p1Health = 0;
    int p2Health = 0;
    int p3Health = 0;
    int p4Health = 0;
    int p1MaxHealth = 0;
    int p2MaxHealth = 0;
    int p3MaxHealth = 0;
    int p4MaxHealth = 0;

    int totalhealth = 0;

    if ( P1 != NULL() ) {
      alveplayers++ ;
      p1Health = getentityproperty( P1,"health" );
      p1MaxHealth = getentityproperty( P1,"maxhealth" );
    }
    if ( P2 != NULL() ) {
      alveplayers++ ;
      p2Health = getentityproperty( P2,"health" );
      p2MaxHealth = getentityproperty( P2,"maxhealth" );
    }
    if ( P3 != NULL() ) {
      alveplayers++ ;
      p3Health = getentityproperty( P3,"health" );
      p3MaxHealth = getentityproperty( P3,"maxhealth" );
    }
    if ( P4 != NULL() ) {
      alveplayers++ ;
      p4Health = getentityproperty( P4,"health" );
      p4MaxHealth = getentityproperty( P4,"maxhealth" );
    }

    //float health = getentityproperty(aentity,"health");
    //float mxhealth = getentityproperty(aentity,"maxhealth");
    totalhealth = ((p1Health+p2Health+p3Health+p4Health)*(alveplayers*100))/(p1MaxHealth+p2MaxHealth+p3MaxHealth+p4MaxHealth);
    //log("--total per " + totalhealth);
    return totalhealth;
}


void gethealthpercentageforentity(void aentity)
{
// V0.03
    int rval = 0;
    if(aentity==NULL()){
      rval = 0;
    } else
    {
      float health = getentityproperty(aentity,"health");
      float mxhealth = getentityproperty(aentity,"maxhealth");
      float totalhealth = (health*100)/mxhealth;
      rval = totalhealth;
    }
    return rval;
}


void increaseaggressionforentity(void aentity,int amount)
{// increase current aggression.
// V0.01
    //void self = getlocalvar("self");
    void cmp = getentityproperty(aentity,"aggression");
    cmp = cmp + amount;
    changeentityproperty(aentity, "aggression", cmp);
    return aentity;
}


void increaseblockoddsforentity(void aentity,int amount)
{
// V0.02
    if ( aentity != NULL() )
    {
      void cmp = getentityproperty(aentity,"blockodds");
      cmp = cmp + amount;
      changeentityproperty(aentity, "blockodds", cmp);
    }
    return aentity;
}


void increaseescapecountforentity(void aentity,int amount)
{
// V0.01
    if ( aentity != NULL() )
    {
      void cmp = getentityproperty(aentity,"escapecount");
      cmp = cmp + amount;
      changeentityproperty(aentity, "escapecount", cmp);
    }
    return aentity;
}


void increasegrabforceforentity(void aentity,int amount)
{
// V0.02
    //void self = getlocalvar("self");
     if ( aentity != NULL() )
    {
      void cmp = getentityproperty(aentity,"grabforce");
      cmp = cmp + amount;
      changeentityproperty(aentity, "grabforce", cmp);
    }
    return aentity;
}


 void increaseguardpointsforentity(void aentity,int amount)
{// increase current guardpoints.
// V0.01
    //void self = getlocalvar("self");
    void cmp = getentityproperty(aentity,"guardpoints");
    //void cmp1 = getentityproperty(aentity,"maxguardpoints");
    cmp = cmp + amount;
    changeentityproperty(aentity, "guardpoints", cmp);
    return aentity;
}


void increasehealthforentity(void aentity,int amount)
{// increase current health amount. Not max health.
// V0.01
    //void self = getlocalvar("self");
    void cmp = getentityproperty(aentity,"health");
    cmp = cmp + amount;
    changeentityproperty(aentity, "health", cmp);
    return aentity;
}


void increaseknockdowncountforentity(void aentity,int amount)
{
// V0.01

    //void cmp = getentityproperty(aentity,"knockdowncount");
    //cmp = cmp + amount;
    //changeentityproperty(aentity, "knockdowncount", cmp);
    return aentity;
}


void increasemaxhealthforentity(void aentity,int amount)
{// increase current health amount. Not max health.
// V0.01 Matman
    //void self = getlocalvar("self");
    void cmp = getentityproperty(aentity,"health");

    cmp = cmp + amount;
    changeentityproperty(aentity, "maxhealth",cmp);
    changeentityproperty(aentity, "health", cmp);
    return aentity;
}


void increasemaxmpforentity(void aentity,int amount)
{// increase current max mp amount.
// V0.01 Matman
    //void self = getlocalvar("self");
    void cmp = getentityproperty(aentity,"maxmp");

    cmp = cmp + amount;
    changeentityproperty(aentity, "maxmp",cmp);
    changeentityproperty(aentity, "mp", cmp);
    return aentity;
}


void increasespeedforentity(void aentity,float amount)
{// increase current speed amount.
// V0.03
    //Speed only increases walking speed.
    //Use Edelay to increase everything
    if ( aentity != NULL() )
    {
      if ( amount != 0 )
      {
        void cmp = getentityproperty(aentity,"speed");
        cmp = cmp + (amount * 0.1);
        changeentityproperty(aentity, "speed", cmp);
      }
    }
    return aentity;
}


void increasetholdforentity(void aentity,int amount)
{
// V0.01
    if ( aentity != NULL() )
    {
      void cmp = getentityproperty(aentity,"thold");
      cmp = cmp + amount;
      changeentityproperty(aentity, "thold", cmp);
    }
    return aentity;
}


void multiplyaggressionforentity(void aentity,int amount)
{// increase current aggression amount.
// V0.01
    //void self = getlocalvar("self");
    void cmp = getentityproperty(aentity,"aggression");
    cmp = cmp * amount;
    changeentityproperty(aentity, "aggression", cmp);
    return aentity;
}


void multiplyhealthforentity(void entity,float amount)
{// increase current health amount.
// V0.01
    //void self = getlocalvar("self");
    void cmp = getentityproperty(entity,"health");
    cmp = cmp * amount;
    changeentityproperty(entity, "health", cmp);
    return entity;
}


void multiplymaxhealthforentity(void entity,float amount,int includehealth)
{// increase current health amount.
//aentity: the passed entity
//amount: the * value
//includehealth: 1 = update normal health to new max health
// V0.01
    //void self = getlocalvar("self");
    void cmp = getentityproperty(entity,"maxhealth");
    cmp = cmp * amount;
    changeentityproperty(entity, "maxhealth", cmp);
    if (includehealth == 1) {changeentityproperty(entity, "health", cmp);}
    return entity;
}


void randomcolormap(void aentity,int maxmapcount)
{
  // V0.01
  if ( aentity != NULL() )
  {
    int i = rand()%maxmapcount;
    if (i < 0 )
       {i=i+i+i;}
    changeentityproperty(aentity, "map", i);
  }
  return aentity;
}


void setaliasforentity(void aentity,void newalias)
{
// V0.01
    //openBor doesn't support this yet
    changeentityproperty(aentity, "name", newalias);
    return aentity;
}


void setdefencepainfromattack(void aentity, float amount, int anitype)
{
  // V 0.01
  // Set's amount of damage that is required for an attack to cause the pain animation.
  //doesn't work here
  if ( aentity != NULL() )
  {
    float 	fFac 	= getentityproperty(aentity, "defense", anitype, "factor"		);  	//Get factor.
    log("     fFac " + fFac);
    int 	iPai 	= getentityproperty(aentity, "defense", anitype, "pain"            	);  	//Get pain.
    log(" iPai " + iPai);
    float 	fKno 	= getentityproperty(aentity, "defense", anitype, "knockdown"       	);  	//Get knockdown.
    log(" fKno " + fKno);
    int 	fBpo 	= getentityproperty(aentity, "defense", anitype, "blockpower"      	);  	//Get block power.
    log(" fBpo " + fBpo);
    int 	iThr 	= getentityproperty(aentity, "defense", anitype, "blockthreshold"	);  	//Get threshold.
    log(" iThr " + iThr);
    float 	fRai	= getentityproperty(aentity, "defense", anitype, "blockratio"      	);	//Get block ratio.
    log(" fRai " + fRai);
    int 	iBty	= getentityproperty(aentity, "defense", anitype, "blocktype"       	);  	//Get block type.
    log(" iBty " + iBty);
    iPai = amount;
    log(" changed " + changeentityproperty(aentity, "defense", anitype, fFac, iPai, fKno, fBpo, iThr, fRai, iBty, 0) );
    //log(" changed " + changeentityproperty(aentity, "defense", anitype, fBpo, fRai, iThr, iBty, fFac, fKno, iPai, 0) );
    //log(" changed " + changeentityproperty(aentity, "defense", anitype, "pain", iPai) );

  }
  return aentity;
}




void buyhealth(int amount)
{
  //v0.06
  void vSelf  = getlocalvar("self");
  void target = getentityproperty(vSelf, "opponent");
  int cost = 150;

  void P1 = getplayerproperty(0, "entity"); //Get Player 1
  void P2 = getplayerproperty(1, "entity"); //Get Player 2
  void P3 = getplayerproperty(2, "entity"); //Get Player 3
  void P4 = getplayerproperty(3, "entity"); //Get Player 4

  void Health = getentityproperty(target,"maxhealth");

  int maxhealth = 0;
  int moneyamount = 0;
  int canbuy = 0;
    if (target == P1)
    { maxhealth = getvmaxhealth(0);
      moneyamount = getvscore(0); } else
    if (target == P2)
    { maxhealth = getvmaxhealth(1);
      moneyamount = getvscore(1); } else
    if (target == P3)
    { maxhealth = getvmaxhealth(2);
      moneyamount = getvscore(2); } else
    if (target == P4)
    { maxhealth = getvmaxhealth(3);
      moneyamount = getvscore(3); }

  if ( moneyamount - cost > 0){ canbuy = 1; }

  if ( amount > 0 )
  {
    if (canbuy == 1)
    {
    if (target == P1)
    { setvmaxhealth(0,maxhealth+amount);
      setvscore(0,moneyamount-cost); } else
    if (target == P2)
    { setvmaxhealth(1,maxhealth+amount);
      setvscore(1,moneyamount-cost); } else
    if (target == P3)
    { setvmaxhealth(2,maxhealth+amount);
      setvscore(2,moneyamount-cost); } else
    if (target == P4)
    { setvmaxhealth(3,maxhealth+amount);
      setvscore(3,moneyamount-cost);  }
    increasemaxhealthforentity( target, (amount*5) );
    drawstring(200, 136, 1, "Added Maximum Health: " + (maxhealth*5) );
    } else {
      drawstring(200, 136, 1, "Not Enough Gold!" );
    }

  } else {
    //drawstring(200, 136, 1, "Player Max health at " + (Health+(maxhealth*5)) );
    drawstring(200, 136, 1, "Added Maximum Health: " + (maxhealth*5) );
    drawstring(200, 146, 1, "Cost: " +  cost );
    drawstring(200, 156, 1, "Gold: " + moneyamount );
  }
}


void buymp(int amount)
{
  //v0.07
  void vSelf  = getlocalvar("self");
  void target = getentityproperty(vSelf, "opponent");
  int cost = 175;

  void P1 = getplayerproperty(0, "entity"); //Get Player 1
  void P2 = getplayerproperty(1, "entity"); //Get Player 2
  void P3 = getplayerproperty(2, "entity"); //Get Player 3
  void P4 = getplayerproperty(3, "entity"); //Get Player 4

  void Health = getentityproperty(target,"maxhealth");

  int maxMP = 0;
  int moneyamount = 0;
  int canbuy = 0;
    if (target == P1)
    { maxMP = getvmp(0);
      moneyamount = getvscore(0); } else
    if (target == P2)
    { maxMP = getvmp(1);
      moneyamount = getvscore(1); } else
    if (target == P3)
    { maxMP = getvmp(2);
      moneyamount = getvscore(2); } else
    if (target == P4)
    { maxMP = getvmp(3);
      moneyamount = getvscore(3); }

  if ( moneyamount - cost > 0){ canbuy = 1; }

  if ( amount > 0 )
  {
    if (canbuy == 1)
    {
    if (target == P1)
    { setvmp(0,maxMP+amount);
      setvscore(0,moneyamount-cost); } else
    if (target == P2)
    { setvmp(1,maxMP+amount);
      setvscore(1,moneyamount-cost); } else
    if (target == P3)
    { setvmp(2,maxMP+amount);
      setvscore(2,moneyamount-cost); } else
    if (target == P4)
    { setvmp(3,maxMP+amount);
      setvscore(3,moneyamount-cost);  }
    increasemaxmpforentity( target, (amount*5) );
    drawstring(200, 136, 1, "Added Maximum Mp: " + (maxMP*5) );
    } else {
      drawstring(200, 136, 1, "Not Enough Gold!" );
    }

  } else {
    //drawstring(200, 136, 1, "Player Max health at " + (Health+(maxhealth*5)) );
    drawstring(200, 136, 1, "Added Maximum Mp: " + (maxMP*5) );
    drawstring(200, 146, 1, "Cost: " +  cost );
    drawstring(200, 156, 1, "Gold: " + moneyamount );
  }
}


void buyspeed(int amount)
{
  //v0.07
  void vSelf  = getlocalvar("self");
  void target = getentityproperty(vSelf, "opponent");
  int cost = 5500;

  void P1 = getplayerproperty(0, "entity"); //Get Player 1
  void P2 = getplayerproperty(1, "entity"); //Get Player 2
  void P3 = getplayerproperty(2, "entity"); //Get Player 3
  void P4 = getplayerproperty(3, "entity"); //Get Player 4

  void Health = getentityproperty(target,"speed");

  int maxspeed = 0;
  int moneyamount = 0;
  int canbuy = 0;
    if (target == P1)
    { maxspeed = getvspeed(0);
      moneyamount = getvscore(0); } else
    if (target == P2)
    { maxspeed = getvspeed(1);
      moneyamount = getvscore(1); } else
    if (target == P3)
    { maxspeed = getvspeed(2);
      moneyamount = getvscore(2); } else
    if (target == P4)
    { maxspeed = getvspeed(3);
      moneyamount = getvscore(3); }

  if ( moneyamount - cost > 0){ canbuy = 1; }

  if ( amount > 0 )
  {
    if (canbuy == 1)
    {
    if (target == P1)
    { setvspeed(0,maxspeed+amount);
      setvscore(0,moneyamount-cost); } else
    if (target == P2)
    { setvspeed(1,maxspeed+amount);
      setvscore(1,moneyamount-cost); } else
    if (target == P3)
    { setvspeed(2,maxspeed+amount);
      setvscore(2,moneyamount-cost); } else
    if (target == P4)
    { setvspeed(3,maxspeed+amount);
      setvscore(3,moneyamount-cost);  }
    increasespeedforentity( target, (maxspeed-1) );
    drawstring(200, 136, 1, "Added Maximum Speed: " + (maxspeed-1) );
    } else {
      drawstring(200, 136, 1, "Not Enough Gold!" );
    }

  } else {
    drawstring(200, 136, 1, "Added Maximum Speed: " + (maxspeed-1) );
    drawstring(200, 146, 1, "Cost: " +  cost );
    drawstring(200, 156, 1, "Gold: " + moneyamount );
  }
}


void getaliasviaspawnname(void spawnedname)
{
  //Check male names
  if ( spawnedname == "devo" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "kuse" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "kush" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "dhalsie" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "dhalsih" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "juggere" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "juggerh" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "capcome" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "capcomh" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "sase" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "sash" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "talbaie" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "talbaih" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "marue" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "maruh" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "specter" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "axle" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "axlh" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "banee" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "baneh" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "sdioe" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "nchaosh" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "solt" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "hondae" ) { spawnedname = namemalemedieval(1); }else
  if ( spawnedname == "hondah" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "kene" ) { spawnedname = namemalemedieval(1); }else
  if ( spawnedname == "kenh" ) { spawnedname = namemalemedieval(1); } else
  


  //Check female names
  if ( spawnedname == "taoe" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "taoh" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "rubyhre" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "rubyhrh" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "sonia" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "casne" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "casnh" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "roomie" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "roomih" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "bdamee" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "bdameh" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "irohah" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "darke" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "darkh" ) { spawnedname = namefemalemedieval(1); }


  return spawnedname;
}


void maxHealthByStage(void entity, int istage,int iDifficulty)
{
  // v0.02 Matman
  void cmp = getentityproperty(entity,"maxhealth");

  int z = cmp/2;
  int r = rand()%z;
  int d = (cmp * iDifficulty) / 2 + (istage * 2);
  //drawstring(150, 150, 0, r);
  //int r =
  cmp = cmp + d + r;
  changeentityproperty(entity, "maxhealth", cmp);
  changeentityproperty(entity, "health", cmp);
  return entity;

}


void randomallboss(int isTrue)
{
  int i = rand()%4;
  void s = "";

  if (i < 0 )
     {i=i+i+i;}

  if(i==0){s = "sdioe";}        else
  if(i==1){s = "irohah";} else
  if(i==2){s = "nchaosh";} else
  if(i==3){s = "solt";}

  if (s == "")
  {s = randomallboss(1);}

  return s;
}


void randomallhealthitems(int isTrue)
{
  int i = rand()%4;
  void s = "";

  if (i < 0 )
     {i=i+i+i;}

  if(i==0){s = "apple";}        else
  if(i==1){s = "chicken";} else
  if(i==2){s = "pork";} else
  if(i==3){s = "fish";}

  if (s == "")
  {s = randomallhealthitems(1);}

  return s;
}


void randomallminbosshard(int isTrue)
{
  int i = rand()%7;
  void s = "";

  if (i < 0 )
     {i=i+i+i;}

  if(i==0){s = "kush";}        else
  if(i==1){s = "juggerh";} else
  if(i==2){s = "sash";} else
  if(i==3){s = "equake";} else
  if(i==4){s = "baneh";} else
  if(i==5){s = "bdameh";}else
  if(i==6){s = "hondah";}


  if (s == "")
  {s = randomallminbosshard(1);}

  return s;
}


void randomallminbossnormal(int isTrue)
{
  int i = rand()%7;
  void s = "";

  if (i < 0 )
     {i=i+i+i;}

  if(i==0){s = "kuse";}        else
  if(i==1){s = "juggere";} else
  if(i==2){s = "sase";} else
  if(i==3){s = "equake";} else
  if(i==4){s = "banee";} else
  if(i==5){s = "bdamee";}else
  if(i==6){s = "hondae";}

  if (s == "")
  {s = randomallminbossnormal(1);}

  return s;
}


void randomcreator(int maxEnemy, int stage, int forceDifficulty, int EnemyType)
{
// V0.19
// MaxEnemy : Max allowed enemies on stage at any time
// Stage : Spawn characters according to stage number
// forceDifficulty : Spawn characters according to Forced Difficulty setting
// EnemyType : Types of enemy, 1 = normal, 2 = Mini Boss, 3 = Boss.
    //Get games difficulty
    int iDifficulty = getvdifficulty(1);
    int iPlayerCnt = 1;
    int iEnemyCnt = 0;
    int iChance = 0;
    int allplrhealth = gethealthpercentageforallplayers(1);
    void vSelf      = getlocalvar("self");
    if (stage == -1) { stage = getvchaptercomplete(1) ;}

    if (forceDifficulty > 0) { iDifficulty = forceDifficulty; }
    //Adjust difficulty to how all players are doing at the moment
    if (allplrhealth == 100) {
      iChance = rand()%100;
      if ( iChance > 92) { iDifficulty++; }
    }
      //If all players are above 50%
    else
    if (allplrhealth > 50) {
      iChance = rand()%100;
      if ( iChance > 98) {
        iDifficulty++;}
    }
      //If all players are belowe 40%
    else
      if (allplrhealth < 40) {
        iChance = rand()%100;
        if ( iChance > 25) {
          iDifficulty--; }
      }
    //Give a random chance to make it more difficult
    iChance = rand()%100;
    if ( iChance > 95) { iDifficulty++; }
    //Count the amount of active players on the stage.
    iPlayerCnt = countaliveplayers(1);
    //Count the amount of active enemies on the stage.
    iEnemyCnt = countaliveenemies(1);

    maxEnemy = maxEnemy + iPlayerCnt + iDifficulty;

    if ( iEnemyCnt <  maxEnemy )
    {
      void enemySpawnName = "";
      void aentity = "";
      //Detect Type of enemy to select a random name from and also check for difficulty.
      if ( EnemyType == 1 )
      {
        if ( iDifficulty % 2 == 0 )
          { enemySpawnName = randomlvl1hard(1); } //Even
        else
          { enemySpawnName = randomlvl1normal(1); } //Odd
      }
      if ( EnemyType == 2 )
      {
        if ( iDifficulty % 2 == 0 )
          { enemySpawnName = randomallminbosshard(1); } //Even
        else
          { enemySpawnName = randomallminbossnormal(1); } //Odd
      }
      if ( EnemyType == 3 )
      {
         enemySpawnName = randomallboss(1);
      }
      //Create entity
      if ( enemySpawnName != "" )
      {
        spawnentity("lsmok",0,0,0,0); //This might cause problems
        aentity = spawnentity( enemySpawnName,0,0,0,0 );

        if ( aentity != NULL() )
        {
          aentity = setaliasforentity( aentity, getaliasviaspawnname(enemySpawnName) );
          aentity = alterallstats(aentity, stage, iDifficulty );
          decreasehealthforentity( vSelf,1 );
        }
      }
    }

}


void randomlvl1hard(int isTrue)
{
  int i = rand()%14;
  void s = "";

  if (i < 0 )
     {i=i+i+i;}

  if(i==0){s = "devo";}        else
  if(i==1){s = "talbaih";} else
  if(i==2){s = "dhalsih";} else
  if(i==3){s = "taoh";} else
  if(i==4){s = "capcomh";} else
  if(i==5){s = "rubyhrh";} else
  if(i==6){s = "sonia";} else
  if(i==7){s = "casnh";} else
  if(i==8){s = "maruh";} else
  if(i==9){s = "specter";} else
  if(i==10){s = "roomih";} else
  if(i==11){s = "axlh";} else
  if(i==12){s = "darkh";} else
  if(i==13){s = "kenh";}


  if (s=="") {s = randomlvl1hard(1);}

  return s;
}


void randomlvl1normal(int isTrue)
{
  int i = rand()%14;
  void s = "";

  if (i < 0 )
     {i=i+i+i;}

  if(i==0){s = "devo";}        else
  if(i==1){s = "talbaie";} else
  if(i==2){s = "dhalsie";} else
  if(i==3){s = "taoe";} else
  if(i==4){s = "capcome";} else
  if(i==5){s = "rubyhre";} else
  if(i==6){s = "sonia";}else
  if(i==7){s = "casne";} else
  if(i==8){s = "marue";} else
  if(i==9){s = "specter";} else
  if(i==10){s = "roomie";} else
  if(i==11){s = "axle";} else
  if(i==12){s = "darke";}else
  if(i==13){s = "kene";}
  


  if ( s=="" ) { s = randomlvl1normal(1); }
  return s;
}


void respawnplayer(int t)
{ //Make sure that this command starts after frame one in the spawn animation
  //V0.03
  void vSelf  = getlocalvar("self");

  void P1 = getplayerproperty(0, "entity"); //Get Player 1
  void P2 = getplayerproperty(1, "entity"); //Get Player 2
  void P3 = getplayerproperty(2, "entity"); //Get Player 3
  void P4 = getplayerproperty(3, "entity"); //Get Player 4

  int maxhealth = 0;
  int maxMP = 0;
  void speed = 0;
        if (vSelf == P1)
        { maxhealth = getvmaxhealth(0);
          maxMP = getvmp(0);
          speed = getvspeed(0);
        } else
        if (vSelf == P2)
        { maxhealth = getvmaxhealth(1);
          maxMP = getvmp(1);
          speed = getvspeed(1);
        } else
        if (vSelf == P3)
        { maxhealth = getvmaxhealth(2);
          maxMP = getvmp(2);
          speed = getvspeed(2);
        } else
        if (vSelf == P4)
        { maxhealth = getvmaxhealth(3);
          maxMP = getvmp(3);
          speed = getvspeed(3);
        }

   increasemaxhealthforentity( vSelf, (maxhealth*5) );
   increasemaxmpforentity( vSelf, (maxMP*5) );
   //increasespeedforentity( vSelf, speed-1);
   //increaseedelayforentity( vSelf, speed-1);
   //int hh = getentityproperty( vSelf, "maxhealth" );
   //log (" player max health on spawn " + maxhealth + ":");
}


void settingsload(int t)
{
  //v 1.05
  //void file = openfilestream("mixmasters/save.txt", 1);
  //void file = openfilestream("save.txt", 1); //doesn't work
  void file = openfilestream("bor/save.txt", 1);
  //If File doesn't exists then create a new one.
  if ( file == -1 ) {

    file = settingssave(2);

  }
  setfilestreamposition(file, 0);
  //Difficulty
  void vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(0,vMatch);
  //Chapter Completed
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(1,vMatch);
  //Player 1 health
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(2,vMatch);
  //Player 2 health
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(3,vMatch);
  //Player 3 health
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(4,vMatch);
  //Player 4 health
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(5,vMatch);
  //Player 1 score
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(6,vMatch);
  //Player 2 score
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(7,vMatch);
  //Player 3 score
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(8,vMatch);
  //Player 4 score
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(9,vMatch);
  //Player 1 mp
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(10,vMatch);
  //Player 2 mp
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(11,vMatch);
  //Player 3 mp
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(12,vMatch);
  //Player 4 mp
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(13,vMatch);
  //Player 1 Speed
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(14,vMatch);
  //Player 2 Speed
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(15,vMatch);
  //Player 3 Speed
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(16,vMatch);
  //Player 4 Speed
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(17,vMatch);
  //Chapter Completed 1
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(18,vMatch);
  //Chapter Completed 2
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(19,vMatch);
  //Chapter Completed 3
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(20,vMatch);
  //Chapter Completed 4
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(21,vMatch);
  //Chapter Completed 5
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(22,vMatch);
  //Chapter Completed 6
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(23,vMatch);
  //Chapter Completed 7
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(24,vMatch);
  //Chapter Completed 8
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(25,vMatch);
  //Chapter Completed 9
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(26,vMatch);

}


void settingssave(int t)
{
  //V0.04
  void file = createfilestream();
  if (t == 2) //use default settings
  {
    //Difficulty
    filestreamappend(file, "1", 1);   //the 1 at the end is nb to make sure it starts on the first line.
    //Chapter Completed
    filestreamappend(file, "1", 0);
    //Player 1 health
    filestreamappend(file, "1", 0);
    //Player 2 health
    filestreamappend(file, "1", 0);
    //Player 3 health
    filestreamappend(file, "1", 0);
    //Player 4 health
    filestreamappend(file, "1", 0);
    //Player 1 score
    filestreamappend(file, "1", 0);
    //Player 2 score
    filestreamappend(file, "1", 0);
    //Player 3 score
    filestreamappend(file, "1", 0);
    //Player 4 score
    filestreamappend(file, "1", 0);
    //Player 1 mp
    filestreamappend(file, "1", 0);
    //Player 2 mp
    filestreamappend(file, "1", 0);
    //Player 3 mp
    filestreamappend(file, "1", 0);
    //Player 4 mp
    filestreamappend(file, "1", 0);
    //Player 1 speed
    filestreamappend(file, "1", 0);
    //Player 2 speed
    filestreamappend(file, "1", 0);
    //Player 3 speed
    filestreamappend(file, "1", 0);
    //Player 4 speed
    filestreamappend(file, "1", 0);
    //Chapter Completed 1
    filestreamappend(file, "1", 0);
    //Chapter Completed 2
    filestreamappend(file, "1", 0);
    //Chapter Completed 3
    filestreamappend(file, "1", 0);
    //Chapter Completed 4
    filestreamappend(file, "1", 0);
    //Chapter Completed 5
    filestreamappend(file, "1", 0);
    //Chapter Completed 6
    filestreamappend(file, "1", 0);
    //Chapter Completed 7
    filestreamappend(file, "1", 0);
    //Chapter Completed 8
    filestreamappend(file, "1", 0);
    //Chapter Completed 9
    filestreamappend(file, "1", 0);
  } else {
    //Difficulty
    filestreamappend(file, getvdifficulty(1), 1);   //the 1 at the end is nb to make sure it starts on the first line.
    //Chapter Completed
    filestreamappend(file, getvchaptercomplete(1), 0);
    //Player 1 health
    filestreamappend(file, getvmaxhealth(0), 0);
    //Player 2 health
    filestreamappend(file, getvmaxhealth(1), 0);
    //Player 3 health
    filestreamappend(file, getvmaxhealth(2), 0);
    //Player 4 health
    filestreamappend(file, getvmaxhealth(3), 0);
    //Player 1 score
    filestreamappend(file, getvscore(0), 0);
    //Player 2 score
    filestreamappend(file, getvscore(1), 0);
    //Player 3 score
    filestreamappend(file, getvscore(2), 0);
    //Player 4 score
    filestreamappend(file, getvscore(3), 0);
    //Player 1 mp
    filestreamappend(file, getvmp(0), 0);
    //Player 2 mp
    filestreamappend(file, getvmp(1), 0);
    //Player 3 mp
    filestreamappend(file, getvmp(2), 0);
    //Player 4 mp
    filestreamappend(file, getvmp(3), 0);
    //Player 1 mp
    filestreamappend(file, getvspeed(0), 0);
    //Player 2 mp
    filestreamappend(file, getvspeed(1), 0);
    //Player 3 mp
    filestreamappend(file, getvspeed(2), 0);
    //Player 4 mp
    filestreamappend(file, getvspeed(3), 0);
    //Chapter Completed 1
    filestreamappend(file, getvstagecomp(1), 0);
    //Chapter Completed 2
    filestreamappend(file, getvstagecomp(2), 0);
    //Chapter Completed 3
    filestreamappend(file, getvstagecomp(3), 0);
    //Chapter Completed 4
    filestreamappend(file, getvstagecomp(4), 0);
    //Chapter Completed 5
    filestreamappend(file, getvstagecomp(5), 0);
    //Chapter Completed 6
    filestreamappend(file, getvstagecomp(6), 0);
    //Chapter Completed 7
    filestreamappend(file, getvstagecomp(7), 0);
    //Chapter Completed 8
    filestreamappend(file, getvstagecomp(8), 0);
    //Chapter Completed 9
    filestreamappend(file, getvstagecomp(9), 0);

  }
  savefilestream(file, "save.txt");
  return file;


}




void displaystagecompleted(int stage)
{
  // V 0.02
  int cnt = 0;
  cnt =  getvstagecomp(stage);
  void vself = getlocalvar("self");
  if ( vself != NULL())
  {
    int height = 80; //getheight(vself);
    int x = getentityproperty(vself,"x");
    int xscr = openborvariant("xpos");
    int z = getentityproperty(vself,"z");
    //log( " x " + x + " z " + z + " xscr " + xscr);
    if ( x!= NULL() && z != NULL() )
    {
      drawstring((x-xscr), 100, 1, cnt );
    }
  }
}


int getvchaptercomplete(int isTrue)
{

  void s = getindexedvar(1);
  //void s = getlocalvar("chap");
  //void s = getglobalvar("chap");


  if ( s > 0 ) { s = s; } else
  {
    settingsload(1);
    s = getindexedvar(1);
  }

  return s;


}


int getvdifficulty(int isTrue)
{
  //s = getglobalvar("Diff");
  void s = getindexedvar(0);
  //s = getscriptvar();
  //s = getlocalvar("Diff");

  if ( s > 0 ) { s = s; } else
  {
    settingsload(1);
    s = getindexedvar(0);
  }


  return s;


}


void getvmaxhealth(int plr)
{
  int val = 0;
  if (plr ==0)
  { val = getindexedvar(2); } else
  if (plr ==1)
  { val = getindexedvar(3); } else
  if (plr ==2)
  { val = getindexedvar(4); } else
  if (plr ==3)
  { val = getindexedvar(5); }

  if ( val > 0 ) { val = val; } else
  {
    settingsload(1);
    val = getvmaxhealth(plr);
  }

  return val;
}


void getvmp(int plr)
{
  int val = 0;
  if (plr ==0)
  { val = getindexedvar(10); } else
  if (plr ==1)
  { val = getindexedvar(11); } else
  if (plr ==2)
  { val = getindexedvar(12); } else
  if (plr ==3)
  { val = getindexedvar(13); }

  if ( val > 0 ) { val = val; } else
  {
    settingsload(1);
    val = getvmp(plr);
  }

  return val;
}


void getvscore(int plr)
{
  int val = 0;
  if (plr ==0)
  { val = getindexedvar(6); } else
  if (plr ==1)
  { val = getindexedvar(7); } else
  if (plr ==2)
  { val = getindexedvar(8); } else
  if (plr ==3)
  { val = getindexedvar(9); }

  if ( val > 0 ) { val = val; } else
  {
    settingsload(1);
    val = getvscore(plr);
  }

  return val;
}


void getvspeed(int plr)
{
  int val = 0;
  if (plr ==0)
  { val = getindexedvar(14); } else
  if (plr ==1)
  { val = getindexedvar(15); } else
  if (plr ==2)
  { val = getindexedvar(16); } else
  if (plr ==3)
  { val = getindexedvar(17); }

  if ( val > 0 ) { val = val; } else
  {
    settingsload(1);
    val = getvspeed(plr);
  }

  return val;
}


void getvstagecomp(int stage)
{
  int val = 0;
  if (stage ==1)
  { val = getindexedvar(18); } else
  if (stage ==2)
  { val = getindexedvar(19); } else
  if (stage ==3)
  { val = getindexedvar(20); } else
  if (stage ==4)
  { val = getindexedvar(21); }  else
  if (stage ==5)
  { val = getindexedvar(22); }  else
  if (stage ==6)
  { val = getindexedvar(23); }  else
  if (stage ==7)
  { val = getindexedvar(24); }  else
  if (stage ==8)
  { val = getindexedvar(25); }  else
  if (stage ==9)
  { val = getindexedvar(26); }

  if ( val > 0 ) { val = val; } else
  {
    settingsload(1);
    val = getvstagecomp(stage);
  }

  return val;
}


int setvchaptercomplete(int val)
{

  setindexedvar(1,val);

}


void setvdifficulty(int zDiff)
{
  int i = getvdifficulty(1);

  if(i==1){drawstring(200, 136, 1, "Difficulty set to Normal");} else
  if(i==2){drawstring(200, 136, 1, "Difficulty set to Hard");} else
  if(i > 2){drawstring(200, 136, 1, "Difficulty set to Harder " + i);}

  if (zDiff == 1) { //Increase difficulty
    setindexedvar( 0, i + 1 );
  } else
  if (zDiff == 0) { //Decrease difficulty
    if (i > 1)
    {
      setindexedvar( 0, i -1 );
    }

  }
  //setglobalvar("Diff", "2");
  //setindexedvar(0,zDiff);
  //setscriptvar(0, "2");
  //setlocalvar("Diff", 2);
  //void s = getlocalvar("Diff"); //doing it this way work fine
  //drawstring(200, 156, 1, getdifficulty(1)); //calling the method doesn't work


}


void setvmaxhealth(int plr, int value)
{
  if (plr == 0)
  { setindexedvar(2,value); } else
  if (plr == 1)
  { setindexedvar(3,value); } else
  if (plr == 2)
  { setindexedvar(4,value); } else
  if (plr == 3)
  { setindexedvar(5,value); }

}


void setvmp(int plr, int value)
{
  if (plr == 0)
  { setindexedvar(10,value); } else
  if (plr == 1)
  { setindexedvar(11,value); } else
  if (plr == 2)
  { setindexedvar(12,value); } else
  if (plr == 3)
  { setindexedvar(13,value); }

}


void setvscore(int plr, int value)
{
  if (plr == 0)
  { setindexedvar(6,value); } else
  if (plr == 1)
  { setindexedvar(7,value); } else
  if (plr == 2)
  { setindexedvar(8,value); } else
  if (plr == 3)
  { setindexedvar(9,value); }

}


void setvspeed(int plr, int value)
{
  if (plr == 0)
  { setindexedvar(14,value); } else
  if (plr == 1)
  { setindexedvar(15,value); } else
  if (plr == 2)
  { setindexedvar(16,value); } else
  if (plr == 3)
  { setindexedvar(17,value); }

}


void setvstagecomp(int stage, int value)
{
  if (stage == 1)
  { setindexedvar(18,value); } else
  if (stage == 2)
  { setindexedvar(19,value); } else
  if (stage == 3)
  { setindexedvar(20,value); } else
  if (stage == 4)
  { setindexedvar(21,value); } else
  if (stage == 5)
  { setindexedvar(22,value); } else
  if (stage == 6)
  { setindexedvar(23,value); } else
  if (stage == 7)
  { setindexedvar(24,value); } else
  if (stage == 8)
  { setindexedvar(25,value); } else
  if (stage == 9)
  { setindexedvar(26,value); }

}




void shootentitybomb(void Shot, float dx, float dy, float dz)
{ // Shooting projectile
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");

   if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; ////Reverse X direction to match facing
   }
//entity * projectile(char *name, float x, float z, float a, int direction, int type, int ptype, int map)
   projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 1, 0);
}


void shootentityknife(void Shot, float dx, float dy, float dz)
{ // Shooting projectile
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");

   if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; ////Reverse X direction to match facing
   }
//entity * projectile(char *name, float x, float z, float a, int direction, int type, int ptype, int map)
   projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
}


void shootentityknifedirection(void Shot, float dx, float dy, float dz, int changedirection)
{ // Shooting projectile
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   if (changedirection == 1)
   {
     if (Direction == 1){
       dx = -dx;
       Direction = 0;
     } else {
       Direction = 1;
     }
   } else {
     if (Direction == 0){
       dx = -dx;
     }
   }
//entity * projectile(char *name, float x, float z, float a, int direction, int type, int ptype, int map)
   projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
}




void decreasehealth(int amount)
{// increase current mp amount. Not max Mp.
// V0.01
    void self = getlocalvar("self");
    void cmp = getentityproperty(self,"health");
    cmp = cmp - amount;
    if (cmp <= 0) {
      killentity(self);
    } else {
    changeentityproperty(self, "health", cmp);
    }
}


void decreasemp(int amount)
{// Decrease current mp amount. Not max Mp.
// V0.01
    void self = getlocalvar("self");
    void cmp = getentityproperty(self,"mp");
    cmp = cmp - amount;
    changeentityproperty(self, "mp", cmp);
}


void decreasempthenhealth(int amount)
{// Decrease current mp amount and if its less than 0 then decrease health. Not max Mp.
// V0.01
    void self = getlocalvar("self");
    void health = getentityproperty(self,"health");
    void cmp = getentityproperty(self,"mp");
    cmp = cmp - amount;
    if (cmp <= 0)
    {
      health = health + (cmp / 2);
      cmp = 0;
    }
    changeentityproperty(self, "mp", cmp);
    changeentityproperty(self, "health", health);
}


void increasehealth(int amount)
{// increase current mp amount. Not max Mp.
// V0.01
    void self = getlocalvar("self");
    void cmp = getentityproperty(self,"health");
    cmp = cmp + amount;
    changeentityproperty(self, "health", cmp);
}


void increasemp(int amount)
{// increase current mp amount. Not max Mp.
// V0.01
    void self = getlocalvar("self");
    void cmp = getentityproperty(self,"mp");
    cmp = cmp + amount;
    changeentityproperty(self, "mp", cmp);
}


void setslowmotion(int istrue)
{ // set slow motion status
// V0.01 Matman
  changeopenborvariant("slowmotion", istrue);

}


void subjecttogravity(int isfalse)
{// change gravity setting
// V0.01
    void self = getlocalvar("self");
    changeentityproperty(self, "subject_to_gravity", isfalse);
}

//#|edited by openBor Stats v 0.48

