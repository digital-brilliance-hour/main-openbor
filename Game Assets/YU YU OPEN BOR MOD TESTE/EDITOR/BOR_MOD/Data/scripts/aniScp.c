



void breakgrabchangeanibykeytoattack(void Ani, int Frame, void Key, int Hflag, int Limit)
{// Change current animation if proper key is pressed or released provided HP is more than limit
// V0.01
// Matman: Update to handle direction changes.
    void self = getlocalvar("self");
    int Direction = getentityproperty(self, "direction");
    int iPIndex = getentityproperty(self,"playerindex"); //Get player index
    void iRKey;
    if (Direction == 0){ //Is entity facing left?
      iRKey = keypressmultileft(Key, iPIndex);
    } else
    if (Direction == 1){
      iRKey = keypressmultiright(Key, iPIndex);
    }
    if (iRKey)
    {
      grabfree(0);
      changeanibykeytoattack(Ani,Frame,Key,Hflag,Limit);
    }
}


void changeanibykeytoattack(void Ani, int Frame, void Key, int Hflag, int Limit)
{// Change current animation if proper key is pressed or released provided HP is more than limit
// V0.01
// Matman: Update to handle direction changes.
    void self = getlocalvar("self");
    void Health = getentityproperty(self,"health");
    int Direction = getentityproperty(self, "direction");
    int iPIndex = getentityproperty(self,"playerindex"); //Get player index
    void iRKey;
if (Direction == 0){ //Is entity facing left?
      iRKey = keypressmultileft(Key, iPIndex);
   }
else if (Direction == 1){
      iRKey = keypressmultiright(Key, iPIndex);
}

      if (Hflag==1){ //Not holding the button case?
        iRKey = !iRKey; //Take the opposite condition
	}

      if ((Health > Limit)&&iRKey){
        performattack(self, openborconstant(Ani));
        //changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
        //changeentityproperty(self, "animpos", Frame);

      //  if (Key=="UJ"){
          // This is copy of dethrown
         // changeentityproperty(self, "attacking", 0);
          //changeentityproperty(self, "damage_on_landing", 0);
         // changeentityproperty(self, "projectile", 0);
        //}
      }
}




void enemypositionduringpain(float dx, float dy, float dz)
{ // Modify grabbed entity's position relative to grabber
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
     aniID = getentityproperty(target, "animationid");

     //drawstring(100, 100, 0, aniID);
     //drawstring(int x, int y, int font#, text);
     if (aniID == 4)
     {
      canCont = 1;
      //settextobj(1, 100, 50, 0, -1, "5");
     } else
     if (aniID == 69)
     {
      canCont = 1;
      //settextobj(1, 150, 50, 0, -1, "69");
     } else
     if (aniID == 70)
     {
      canCont = 1;
      //settextobj(1, 150, 50, 0, -1, "70");
     } else
     if (aniID == 71)
     {
      canCont = 1;
      //settextobj(1, 150, 50, 0, -1, "71");
     }

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
     aniID = getentityproperty(target, "animationid");

     if (aniID == 4)
     {
      canCont = 1;
     } else
     if (aniID == 69)
     {
      canCont = 1;
     } else
     if (aniID == 70)
     {
      canCont = 1;
     } else
     if (aniID == 71)
     {
      canCont = 1;
     }

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




void changeanibykey(void Ani, int Frame, void Key, int Hflag, int Limit)
{// Change current animation if proper key is pressed or released provided HP is more than limit
// V0.01
// Matman: Update to handle direction changes.
    void self = getlocalvar("self");
    void Health = getentityproperty(self,"health");    
    int Direction = getentityproperty(self, "direction");
    int iPIndex = getentityproperty(self,"playerindex"); //Get player index
    void iRKey;
if (Direction == 0){ //Is entity facing left?
      iRKey = keypressmultileft(Key, iPIndex);
   }
else if (Direction == 1){
      iRKey = keypressmultiright(Key, iPIndex);
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


void teleportbehindnearestenemy(int dx, int dy, int dz)
{// Targetting opponent then teleport to target
    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction");
    int enemdir = 0;

    if(dir==0){ // Facing left?
      dx = -dx ;
    }

    setlocalvar("T"+self, findtarget(self)); //Get nearest player

    if( getlocalvar("T"+self) != NULL()){
      void target = getlocalvar("T"+self);
      int Tx = getentityproperty(target, "x");
      int Tz = getentityproperty(target, "z");
      enemdir = getentityproperty(target, "direction");

      changeentityproperty(self, "position", Tx+dx, Tz+dz, dy); //Teleport to target!
      changeentityproperty(self, "direction", enemdir); //Teleport to target!
    }
}


void teleportinfrontnearestenemy(int dx, int dy, int dz)
{// Targetting opponent then teleport to target
    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction");
    int enemdir = 0;

    if(dir==1){ // Facing left?
      dx = -dx ;
    }

    setlocalvar("T"+self, findtarget(self)); //Get nearest player

    if( getlocalvar("T"+self) != NULL()){
      void target = getlocalvar("T"+self);
      int Tx = getentityproperty(target, "x");
      int Tz = getentityproperty(target, "z");
      enemdir = getentityproperty(target, "direction");
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




void grabfree(int isTrue)
{// releases player and enemy grab state
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
     bindentity(self, NULL());

     //setidle(target);
     //setidle(self);
     //changeentityproperty(target, "animationid", "ANI_IDLE", 1);
     //changeentityproperty(target, "aiflag", "idle", 1); // Disable jumping status
     
          changeentityproperty(self, "aiflag", "common_grab", 0);
     changeentityproperty(self, "aiflag", "idling", 1);


     changeentityproperty(target, "aiflag", "common_grabbed", 0);
     changeentityproperty(target, "aiflag", "idling", 1);

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
{ // Kills entity without playing the death animation
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
   if (istrue == 1) {
     void self = getlocalvar("self");

     cnt = openborvariant("count_enemies");

   }
   return cnt;

}


int countaliveplayers(int istrue)
{ // Count how many alive players there are
// V0.01 Matman
   int cnt = 0;
   if (istrue == 1) {
     void self = getlocalvar("self");
     cnt = openborvariant("count_players");
   }
   return cnt;
}


void getdifficulty(int istrue)
{ // Get current difficulty setting
// V0.01 Matman
   if (istrue == 1) {
     void self = getlocalvar("self");
     int cnt = 0;
     cnt = openborvariant("current_set");
     return cnt;
   }

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




void gethealthpercentageforentity(void aentity)
{
// V0.02
    float health = getentityproperty(aentity,"health");
    float mxhealth = getentityproperty(aentity,"maxhealth");
    float totalhealth = (health*100)/mxhealth;
    return totalhealth;
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
{// increase current aggression amount.
// V0.01

    void cmp = getentityproperty(aentity,"knockdowncount");
    cmp = cmp + amount;
    changeentityproperty(aentity, "knockdowncount", cmp);
    return aentity;
}


void increasespeedforentity(void aentity,float amount)
{// increase current speed amount.
// V0.02
    //openBor doesn't support this yet
    void cmp = getentityproperty(aentity,"speed");
    cmp = cmp + (amount * 0.1);
    changeentityproperty(aentity, "speed", cmp);
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


void setaliasforentity(void aentity,void newalias)
{
// V0.01
    //openBor doesn't support this yet
    changeentityproperty(aentity, "name", newalias);
    return aentity;
}




void getaliasviaspawnname(void spawnedname)
{
  //Check male names
  if ( spawnedname == "devo" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "kusaregedoe" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "kusaregedoh" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "dhalsime" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "dhalsimh" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "juggernaute" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "juggernauth" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "capcome" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "capcomh" ) { spawnedname = namemalemedieval(1); } else
  //Check female names
  if ( spawnedname == "taoe" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "taoh" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "rubyhrte" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "rubyhrth" ) { spawnedname = namefemalemedieval(1); }

  return spawnedname;
}


void randomcreator(int maxEnemy, int stage, int forceDifficulty)
{
// V0.04
// MaxEnemy : Max allowed enemies on stage at any time
// Stage : Spawn characters according to stage number
// forceDifficulty : Spawn characters according to Forced Difficulty setting
    //Get games difficulty
    int iDifficulty = 1;
    int iPlayerCnt = 1;
    int iEnemyCnt = 0;
    if (forceDifficulty > 0) { iDifficulty = forceDifficulty; }
    //Count the amount of active players on the stage.
    iPlayerCnt = countaliveplayers(1);
    //Count the amount of active enemies on the stage.
    iEnemyCnt = countaliveenemies(1);
    //Increase maxEnemy by the amount of players alive and difficulty
    maxEnemy = maxEnemy + iPlayerCnt + iDifficulty;
    if (iEnemyCnt <  maxEnemy)
    {
      void enemySpawnName = "";
      void aentity = "";
      //Detect what stage to select a random name from and also check for difficulty.
      if (stage == 1)
      {
        if (iDifficulty == 1) { enemySpawnName = randomlvl1normal(1); } else
        if (iDifficulty == 2) { enemySpawnName = randomlvl1hard(1); } else
           { enemySpawnName = randomlvl1hard(1); }
      }
      //Create entity
      if (enemySpawnName != "")
      {
        //loadmodel(enemySpawnName);
        aentity = spawnentity(enemySpawnName,0,0,0,0);
        //Modify stats
        aentity = multiplymaxhealthforentity(aentity,iDifficulty,1);
        aentity = multiplyaggressionforentity(aentity,iDifficulty);
        aentity = increasespeedforentity(aentity,iDifficulty);
        aentity = setaliasforentity(aentity,getaliasviaspawnname(enemySpawnName));
        //aentity = increaseknockdowncountforentity(aentity,iDifficulty);
        decreasehealth(1);
      }
    }

}


void randomlvl1hard(int isTrue)
{
  int i = rand()%6;
  void s = "";

  if (i < 0 )
     {i=i+i+i;}

  if(i==0){s = "devo";}        else
  if(i==1){s = "talbainh";} else
  if(i==2){s = "dhalsimh";} else
  if(i==3){s = "taoh";} else
  if(i==4){s = "capcomh";} else
  if(i==5){s = "rubyhrth";}

  return s;
}


void randomlvl1normal(int isTrue)
{
  int i = rand()%6;
  void s = "";

  if (i < 0 )
     {i=i+i+i;}

  if(i==0){s = "devo";}        else
  if(i==1){s = "talbaine";} else
  if(i==2){s = "dhalsime";} else
  if(i==3){s = "taoe";} else
  if(i==4){s = "capcome";} else
  if(i==5){s = "rubyhrte";}

  return s;
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

//#|edited by openBor Stats v 0.41

