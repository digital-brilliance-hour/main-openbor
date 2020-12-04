void main() {
	
    int P1 = getplayerproperty(0, "entity");
    int P2 = getplayerproperty(1, "entity");
    void etime = getlocalvar("eTime");
    void edelay = getlocalvar("eDelay");
    int i = getlocalvar("iloop");
    void emoves = getlocalvar("emoves");
    void pmoves = getlocalvar("pmoves");
    void currtime = getlocalvar("currtime");
	if(emoves == NULL()) {
    	emoves = array(8);
    	setlocalvar("emoves", emoves);
    }
	if(pmoves == NULL()) {
    	pmoves = array(8);
    	setlocalvar("pmoves", pmoves);
    }
    if(i == NULL()){
    	if(emoves != NULL()) {
	    	free(emoves);
	    }
    	if(pmoves != NULL()) {
	    	free(pmoves);
	    }
    	setlocalvar("emoves", array(8));
    	setlocalvar("pmoves", array(8));
    	emoves = getlocalvar("emoves");
    	pmoves = getlocalvar("pmoves");
    	setlocalvar("iloop", 0);
    	i = getlocalvar("iloop");
    }
    int movelist = 6;
    void manimations = getlocalvar("manimations");
    if(manimations == NULL()){
	    manimations = array(8);
		set(manimations,0,openborconstant("ANI_FOLLOW10"));
		set(manimations,1,openborconstant("ANI_FOLLOW11"));
		set(manimations,2,openborconstant("ANI_FOLLOW12"));
		set(manimations,3,openborconstant("ANI_FOLLOW13"));
		set(manimations,4,openborconstant("ANI_FOLLOW14"));
		set(manimations,5,openborconstant("ANI_FOLLOW15"));
		set(manimations,6,openborconstant("ANI_FOLLOW16"));
		set(manimations,7,openborconstant("ANI_FOLLOW17"));
		setlocalvar("manimations", manimations);
    }
    void moves = getlocalvar("moves");
    if(moves == NULL()) {
    	moves = array(8);
    	set(moves, 0, "moveup");
    	set(moves, 1, "movedown");
    	set(moves, 2, "moveleft");
    	set(moves, 3, "moveright");
    	set(moves, 4, "attack");
    	set(moves, 5, "attack2");
    	set(moves, 6, "attack3");
    	set(moves, 7, "jump");
    	setlocalvar("moves", moves);
    }
    if(edelay == NULL()) {
		setlocalvar("eDelay", openborvariant("elapsed_time")+1500);
    }
    else {
    	if(openborvariant("elapsed_time") > edelay ) {
    		if(currtime == NULL()) {
    			setlocalvar("currtime", openborvariant("elapsed_time"));
    			currtime = getlocalvar("currtime");
    			srand(currtime);
    		}
		    if(etime == NULL()) {
				setlocalvar("eTime", openborvariant("elapsed_time")+450);
				//log("etime not set");
		    }
		    else {
		    	if(openborvariant("elapsed_time") >= etime ) {
		    		log("i: " + i + " . ");
			    	if (i < movelist) {
					    int follow = rand()%8;
					    if(follow < 0) {
					    	follow *= -1;
					    }
					    //log(follow);
					    add(emoves, i, follow);
					    //log("emove: " + get(emoves, i) + " | ");
				    	setlocalvar("emoves", emoves);
				    	spawnTextAni("simontext",240,1,136,get(manimations, follow),NULL(),NULL(),NULL());
				    	i++;
				    	setlocalvar("iloop", i);
					}
				    setlocalvar("eTime", NULL());
			    }
		    }

		    if(i == movelist){
		    	getInput();
		    }
		}
	}

    //log(etime + " | ");
    //log("elapsed: " + openborvariant("elapsed_time") + " | ");
    if(P1) {
    	changeentityproperty(P1, "health", getentityproperty(P1, "maxhealth"));
    }
    if(P2) {
    	changeentityproperty(P2, "health", getentityproperty(P2, "maxhealth"));

    }
}

void getInput() {

	int correctSFX = loadsample("data/sounds/correct.wav");
	int errorSFX = loadsample("data/sounds/error.wav");
	int winSFX = loadsample("data/sounds/fantastic.wav");
	int loseSFX = loadsample("data/sounds/youlose.wav");
    int P1 = getplayerproperty(0, "entity");
    int P2 = getplayerproperty(1, "entity");
    void etime = getlocalvar("eTime");
    void edelay = getlocalvar("eDelay");
    int j = getlocalvar("jloop");
    int x = getlocalvar("xloop");
    int numcorrect = getlocalvar("numcorrect");
    int numwrong = getlocalvar("numwrong");
    void emoves = getlocalvar("emoves");
    void pmoves = getlocalvar("pmoves");
    if(numcorrect == NULL()){
    	setlocalvar("numcorrect", 0);
    	numcorrect = getlocalvar("numcorrect");
    }
    if(numwrong == NULL()){
    	setlocalvar("numwrong", 0);
    	numwrong = getlocalvar("numwrong");
    }
    if(j == NULL()){
    	setlocalvar("jloop", 0);
    	j = getlocalvar("jloop");
    }
    if(x == NULL()){
    	setlocalvar("xloop", 0);
    	x = getlocalvar("xloop");
    }
    int movelist = 6;
    void moves = getlocalvar("moves");
    if(moves == NULL()) {
    	moves = array(8);
    	set(moves, 0, "moveup");
    	set(moves, 1, "movedown");
    	set(moves, 2, "moveleft");
    	set(moves, 3, "moveright");
    	set(moves, 4, "attack");
    	set(moves, 5, "attack2");
    	set(moves, 6, "attack3");
    	set(moves, 7, "jump");
    	setlocalvar("moves", moves);
    }
    if(x < movelist) {
	    if(j == 0) {
	    	int keypressed = getplayerproperty(0, "newkeys");
	    	if(keypressed > 0) {
	    		//log("x: " + x + " | ");
	    		//log("move: " + get(moves, get(emoves, x)) + " | ");
		    	int pressed = playerkeys(0, 0, get(moves, get(emoves, x)));
		    	//log("is pressed: " + pressed + " | ");
		    	if(pressed > 0) {
        			playsample(correctSFX, 0, 128, 128, 100, 0);
		    		log("correct");
		    		numcorrect++;
		    		setlocalvar("numcorrect", numcorrect);
			    	x++;
			    	setlocalvar("xloop", x);
		    	}
		    	else {
        			playsample(errorSFX, 0, 128, 128, 100, 0);
		    		log("incorrect");
		    		numwrong++;
		    		setlocalvar("numwrong", numwrong);
		    		setlocalvar("xloop", movelist);
		    	}
		    	setlocalvar("jloop", NULL());
		    }
	    }
	}
	else {
		if(numcorrect == movelist){
			killent("draven", P1);
        	playsample(winSFX, 0, 128, 128, 100, 0);
			jumptobranch("", 1);
		}
		else {
			//damageplayer("draven", P1, 10);
        	playsample(loseSFX, 0, 128, 128, 100, 0);
			setlocalvar("xloop", 0);
			setlocalvar("jloop", 0);
			setlocalvar("numcorrect", 0);
			setlocalvar("numwrong", 0);
			setlocalvar("iloop", NULL());
		}
	}
}


void spawnTextAni(void vName, float fX, float fY, float fZ, void Ani, float Vx, float Vy, float Vz)
{
	//spawnB (Generic spawner) + Specific animation + velocities
	//Damon Vaughn Caskey + Douglas Baldan
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
    loadmodel(vName); // name of the entity to be loaded

	clearspawnentry(); //Clear current spawn entry.
    setspawnentry("name", vName); //Acquire spawn entity by name.
    //setspawnentry("coords", 1,1,1); // set the position of the entity

      fX = openborvariant("xpos")+fX; //Get X location and add adjustment.
      //fY = openborvariant("ypos"); //Get Y location and add adjustment.
      fZ = openborvariant("ypos")+fZ; //Get Z location and add adjustment.
      log(fX);
	
	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	//changeentityproperty(vSpawn, "direction", 1); //Set direction.
    performattack(vSpawn, openborconstant(Ani)); 
	//changeentityproperty(vSpawn, "velocity", Vx, Vy, Vz);

	return vSpawn; //Return spawn.
}

void killent(char target_name, int other)
{// kill specific enemy
//Kevin Epps dec-03-2020
  int i;
  for (i = 0; i < openborvariant("count_entities"); ++i)
  {
      void ent = getentity(i);
    if ( getentityproperty(ent, "exists") ) {
        if ( getentityproperty(ent,"model") == target_name) {
	        int maxhp = getentityproperty(ent, "maxhealth");
	        damageentity(ent, other, maxhp);
	        continue;
        }
    } else continue;
  }
  return;
}


void damageplayer(char target_name, int pent, int amount)
{// damageplayer
//Kevin Epps dec-03-2020
  int i;
  for (i = 0; i < openborvariant("count_entities"); ++i)
  {
      void ent = getentity(i);
    if ( getentityproperty(ent, "exists") ) {
        if ( getentityproperty(ent,"model") == target_name) {
	        int maxhp = getentityproperty(ent, "maxhealth");
	        damageentity(pent, ent, amount);
	        continue;
        }
    } else continue;
  }
  return;
}