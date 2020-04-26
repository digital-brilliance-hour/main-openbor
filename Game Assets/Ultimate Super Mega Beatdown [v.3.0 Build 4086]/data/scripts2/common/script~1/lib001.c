void ani001(void vAni1, int iFrame, int iCmd, int iMPCost, int iHPCost, float fMinX, float fMaxX, float fMinZ, float fMaxZ, float fMinY, float fMaxY){

	//ani001
	//Damon Vaughn Caskey
	//05/11/2007
	//
	//Switch calling entity to new animation and frame if player command, HP, MP, and range requirements are met.
	//
	//vAni1: Desired animation.
	//iFrame: Desired frame.
	//iCmd: Required player command.
	//iMPCost: Minimum (and to be consumed) MP.
	//iHPCost: Minimum (and to be consumed) HP.
	//fMinX: Minimum X range.
	//fMaxX: Maximim X range.
	//fMinZ: Minimum Z range.
	//fMaxZ: Maximum Z range.
	//fMaxY: Minimum Y range.
	//fMaxY: Maximum Y range.

    void vSelf = getlocalvar("self"); //Get calling entity. 
    void vTarget = findtarget(vSelf); //Get nearest hostle entity to caller.
	int iMP = getentityproperty(vSelf, "mp"); //Caller's current MP.
	int iHP = getentityproperty(vSelf, "health"); //Caller's current HP.
    float fX = getentityproperty(vSelf, "x"); //X position of caller.
    float fY = getentityproperty(vSelf, "a"); //Y position of caller.
    float fZ = getentityproperty(vSelf, "z"); //Z position of caller.
	float fTX = getentityproperty(vTarget, "x"); //X position of nearest hostile entity to caller.
    float fTY = getentityproperty(vTarget, "a"); //Y position of nearest hostile entity to caller.
    float fTZ = getentityproperty(vTarget, "z"); //Z position of nearest hostile entity to caller.
        
    if(iCmd){ //If command requirement provided, evaluate.
                  
        if(keyd001(getentityproperty(vSelf, "playerindex"), 0, vSelf) != iCmd) { //Does command match?
			
			return; //Exit.
		
		} 
        
    }         
    
	if (!(iRan001(fX, fTX, fMinX, fMaxX))){ //Not within X range?
        
		return; //Exit.
            
    }
        
	if (!(iRan001(fZ, fTZ, fMinZ, fMaxZ))){ //Not within Z range?
        
		return; //Exit.
            
    }
    
	if (!(iRan001(fY, fTY, fMinY, fMaxY))){ //Not within Y range?
        
		return; //Exit.
            
    }
           
	if ((iMPCost) || (iHPCost)){ //Cost requirement provided?
        
		if (iMP >= iMPCost && iHP > iHPCost){ //Evaluate MP/HP costs against available supply.
		    	  
			changeentityproperty(vSelf, "mp", iMP - iMPCost); //Subtract MP cost from caller's MP.
			changeentityproperty(vSelf, "health", iHP - iHPCost); //Subtract HP cost from  caller's HP.                              	
	
		}else{  		                   	      
                                            
			return; //Exit.
        
		}                                            

	}
	
	changeentityproperty(vSelf, "animation", openborconstant(vAni1)); //Switch to desired animation.
	changeentityproperty(vSelf, "animpos", iFrame); //Switch to desired frame.
        
}

void ani002(void vAni, int iFrame, void vReqVar, void vReqVal){
    
    //ani002
    //Damon Vaughn Caskey
	//06/20/2007
	//
	//Switches calling entity to new animation and frame if variable meets condition.
	//
	//vAni1: Desired animation.
	//iFrame: Desired frame.
	//vReq: Required animation ID.
     
    void vSelf = getlocalvar("self"); //Get calling entity
    void vVal = getlocalvar(vReqVar + vSelf); //Get persistent variable.
            
    if (vVal == vReqVal){ 
             
       changeentityproperty(vSelf, "animation", openborconstant(vAni)); //Switch to desired animation.
       changeentityproperty(vSelf, "animpos", iFrame); //Switch to desired frame.
    
    }
   
}

void ani003(void vAni, int iFrame, int iRepReq){
    
    //ani003
    //Damon Vaughn Caskey
	//06/20/2007
	//
	//Switches calling entity to new animation and frame if loop number condition is met.
	//
	//vAni1: Desired animation.
	//iFrame: Desired frame.
	//iRepReq: Required loopcount.
     
    void vSelf = getlocalvar("self"); //Get calling entity
    void iRep = getlocalvar("iLoops" + vSelf); //Get number of loops run so far.
	
    if (iRep){ //Because of the odd way BOR script works, we have to establish the variable first, then increment it.

	   iRep = ++iRep; //Loop count variable exists, count up by 1.
		    
	}else{

       iRep = 1.0; //Loop count variable does not exist. Create it using dummy value.

	}

	if (iRep < ++iRepReq){ //Is loop count lower then desired number of loops?

	   changeentityproperty(vSelf, "animation", openborconstant(vAni)); //Switch to desired animation.
       changeentityproperty(vSelf, "animpos", iFrame); //Switch to desired frame.

	}else{ //Loop count reached.

	   iRep = 0.0; //Populate variable with Null() to clean it (In BOR script, this erases variable).

	}

	setlocalvar("iLoops" + vSelf, iRep); //Set global variable.
   
}

void ani004(void vAni, int iFrame){
    
    //ani004
    //Damon Vaughn Caskey 
    //
    //Loops between given frames until caller falls below 1 height. Primarly for juggle falls to turn off bbox when landing. 
    //
    //vAni: Desired animation.
    //iFrame: Desired frame.
     
    void vSelf = getlocalvar("self"); //Get calling entity
    float fY = getentityproperty(vSelf, "a"); //Get Y location.
    float fBase = getentityproperty(vSelf, "base"); //Get base height.
        
    if (fY > 1 || fBase < 0){ //Are we still in air or over a pit?
       
       changeentityproperty(vSelf, "animation", openborconstant(vAni)); //Switch to desired animation. 
       changeentityproperty(vSelf, "animpos", iFrame); //Switch to desired frame.
    
    }
           
}

void boun001(int iYMin, void vAni){

    //boun001
	//Damon Vaughn caskey
	//05/11/2007
	//
    //Bounce calling entity upon reaching given height.
    //
    //iYmin: Height entity must fall to before "bouncing".
    //vAni: Animation to play during bounce.
    
    void vSelf = getlocalvar("self"); //Get self.
          
    if (getentityproperty(vSelf, "a") > iYMin ) { return; } //No need to go further, exit script. 
               
    if (vAni){ changeentityproperty(vSelf, "animation", openborconstant(vAni)); } //Set animation.
                   
    jump001(2, -2, 0); //Bounce effect.

}

void dama001(int iTarget, void vType, int iForce, int iDrop, float fY, float fX, float fZ){

    //dama001
    //Damon Vaughn Caskey
    //06/28/2007
    //
    //Toss target entity.
    //
	//iTarget: Desired target. 0 = Last entity hit, 1 = Current opponent, 2 = Current hold victum, 3 = Nearest target.
    //fY, fX, fZ: Vertical, horizontal, and depth distance respectively.

    void vSelf = getlocalvar("self"); //Get calling entity.
    void vTarget = vTar001(iTarget, vSelf); //Target to toss.

	if (iDrop > 2 && getentityproperty(vSelf, "a") > 0){ //iDrop more then 2 and opponent off the ground?

		toss001(vTarget, 0.05, 0, 0); //Lift target a tiny bit to force a fall when damage is applied.

	}
        
	damageentity(vTarget, vSelf, iForce, iDrop, openborconstant(vType)); //Apply damage.

	if ((fX) || (fY) || (fZ)){ //Is a distance adjustmnt requested?
				
		toss001(vTarget, fY, fX, fZ); //Toss entity.
			
	}

}

void deat001(void vTarget){

	//deat001
	//Damon Vaughn Caskey
	//07/14/2007
	//
	//Changes color map to "death" color and clears any variables that might be associated with target.
    //
    //vTarget: Target entity.          
	
	changeentityproperty(vTarget, "map", 1); //Switch to "death" color map.
		
	killentity(getlocalvar("vDumm001" + vTarget)); //Destroy any dummy entity.

	setlocalvar("head" + vTarget, 0); //Clear head entity variable.
	setlocalvar("vSpawn" + vTarget, 0); //Clear last spawn variable.
	setlocalvar("iMap" + vTarget, 0); //Clear remap variable.
	setlocalvar("iLoops" + vTarget, 0); //Clear loop count variable.
	setlocalvar("vDumm001" + vTarget, 0); //Clear dummy entity local variable.
	setlocalvar("iAni" + vTarget, 0); //Clear animation ID variable.
		
	setglobalvar("vTarget" + vTarget, 0); //Clear last target variable.
	setglobalvar("vTargetDir" + vTarget, 0); //Clear target direction global variable.
	setglobalvar("fPX" + vTarget, 0); //Clear parent synch X variable.
	setglobalvar("fPY" + vTarget, 0); //Clear parent synch Y variable.
	setglobalvar("fPZ" + vTarget, 0); //Clear parent synch Z variable.
	
}

void deat002(void vTarget){

	void vSelf = getlocalvar("self"); //Calling entity.

	deat001(vTar001(vTarget, vSelf));

}

void effe002(int iEffectMap, int iPain, int iFall){
	
	//effe002
	//Damon Vaughn Caskey
	//
	//07/21/2007
	//
	//Syncronizes location of special effect entity with parent entity while remaping parent.

    void vSelf = getlocalvar("self"); //Calling entity.
    void vParent = getentityproperty(vSelf, "parent"); //Parent entity.
    int iMap = getentityproperty(vParent, "map"); //Parent's current color map.
    int iOGMap = getlocalvar("map" + vParent); //Parents orginal color map.
    int iAniID = getentityproperty(vParent,"animationID"); //Parent's current animation ID.
    
    if(iAniID != iPain && iAniID != iFall){ //Not in iPain or iFall?
                       
         changeentityproperty(vParent, "map", iOGMap); //Change parent to orginal map.
         killentity(vSelf); //Destroy caller.
             
    }else{ //In iPain or iFall.
                 
         if(iEffectMap != iMap){ //Not using effect map?        
    
              setlocalvar("map" + vParent, iMap); //Store parent's orginal map.
              changeentityproperty(vParent, "map", iEffectMap); //Change parent to effect map.      
                                  
        }
    
	}
    
    float fX = getentityproperty(vParent, "x"); //Parent X location.
    float fY = getentityproperty(vParent, "a"); //Parent Y location.
	float fZ = getentityproperty(vParent, "z"); //Parent Z location.

    changeentityproperty(vSelf, "position", fX, fZ+1, fY + 30);

}

void jump001(float fY, float fX, float fZ){
	
	//jump001
	//Damon Vaughn Caskey
	//05/08/2007
	//
	//Replicates jumpframe effect.
	//
	//fY: Jumpheight.
	//fX: Horizontal distance.
	//fZ: Z axis distance.

	void vSelf = getlocalvar("self"); //Get calling entity

	toss001(vSelf, fY, fX, fZ); //Call toss001.

}

void jump002(){
	
	//jump002
	//Damon Vaughn Caskey
	//06/29/2007
	//
	//In conjunction with ani003, provides "flight" path according to number of reps. Designed primary for Hanzou's Ninpo Korin Kazan move.
	
	void vSelf = getlocalvar("self"); //Get calling entity
	int iRep = getlocalvar("iLoops" + vSelf); //Get number of loops run so far.
    float fX = 0;
    float fY = 0;
    float fZ = 0;
    
    if(iRep <= 3){
    
       fY = -1.5;
       fX = 3;         
                
    }else if(iRep > 3 && iRep <= 6){
    
       fY = -0.5;
       fX = 3.5;

    }else if(iRep > 6 && iRep < 9){
    
       fY = 0.07;
       fX = 3.5;
    
    }else{
        
       fY = 1;
       fX = 3;
    
    }        

	toss001(vSelf, fY, fX, fZ); //Call toss001.

}

int keyd001(int iIndex, int iNewKey, void vSelf){
     
     //keyd001
     //Damon Vaughn Caskey
     //05/13/2007
     //
     //Wrapper for players keys function, returns integer based on key pressed.
     //
     //iIndex: Player index for key press.
     //iNewKey: New key press or "holding".
     //vSelf: Target entity. 
          
     if (getentityproperty(vSelf, "direction")==1 && (playerkeys(iIndex,iNewKey, "moveright"))){
     
          return 10; //"Forward" (facing right).

     }else if (getentityproperty(vSelf, "direction")==0 && (playerkeys(iIndex,iNewKey, "moveleft"))){
     
          return 10; //"Forward" (facing left).
          
     }else if (getentityproperty(vSelf, "direction")==1 && (playerkeys(iIndex,iNewKey, "moveleft"))){
     
          return 11; //"Back" (facing right).

     }else if (getentityproperty(vSelf, "direction")==0 && (playerkeys(iIndex,iNewKey, "moveright"))){
     
          return 11; //"Back" (facing left).
          
     }else if (playerkeys(iIndex,iNewKey, "moveleft")){
                                   
          return 1; //Left.
     
     }else if (playerkeys(iIndex,iNewKey, "moveright")){
     
          return 2; //Right.
                    
     }else if (playerkeys(iIndex,iNewKey, "moveup")){
     
          return 3; //Up.
                    
     }else if (playerkeys(iIndex,iNewKey, "movedown")){
     
          return 4; //Down.
                    
     }else if (playerkeys(iIndex,iNewKey, "esc")){
     
          return 5; //Escape.
                    
     }else if (playerkeys(iIndex,iNewKey, "start")){
     
          return 6; //Start.
                    
     }else if (playerkeys(iIndex,iNewKey, "special")){
     
          return 7; //Special.
                    
     }else if (playerkeys(iIndex,iNewKey, "jump")){
     
          return 8; //Jump.
                    
     }else if (playerkeys(iIndex,iNewKey, "attack")){
     
          return 9; //Attack 1.
                    
     }
     
}

void loc001(void vSync, void vTarget, float fX, float fY, float fZ, int iDirection){
    
    //loc001
	//Damon Vaughn Caskey
	//04/20/2007
	//
	//Syncronizes location of entity to second entity.
	//
	//vSync: Entity to sync.
	//vTarget: Entity to sync to.
	//fX: X distance adjustment.
	//fZ: Y distance adjustment.
    //fY: Z distance adjustment.
    //iDirection: Desired direction of sync (0 same as target, 1 = Opposing target, 2 = left, 3 = right)
	
    int iDir = getentityproperty(vTarget, "direction");
         
    if (iDir == 0){ //Target facing left?
             
         fX = -fX; //-fXP; //Reverse horizontal adjustment. 
             
    }
    
	if (!(fX)){

		fX = 0.0;
	
	}

	if (!(fY)){

		fX = 0.0;
	
	}

	if (!(fZ)){

		fX = 0.0;
	
	}

    fX = fX + getentityproperty(vTarget, "x"); //Get target entity X location.
    fY = fY + getentityproperty(vTarget, "a"); //Get target entity Y location.
    fZ = fZ + getentityproperty(vTarget, "z"); //Get target entity Z location.
               
    if (iDirection == 1){ //Direction setting 1 (Opposing target)?
	
		if (iDir){ //Facing left?

			iDirection = 0; //Force right facing.

		}else{ //Facing right?

			iDirection = 1; //Force left facing.

		}

	}else if (iDirection == 2){ //Direction setting 2 (left)?

		iDirection = 1; //Force left facing.

	}else if (iDirection == 3){ //Direction setting 3 (right)?

		iDirection = 0; //Force right facing.

	}else if (iDirection == 0 || !(iDirection)){ //Direction setting 0 (same as target)?

		iDirection = iDir; //Force facing same as target.
	
	}
    
    //changeentityproperty(vSync, "direction", iDirection); //Adjust sync entity direction.   
    changeentityproperty(vSync, "position", fX, fZ, fY); //Adjust sync entity location.
    

}

int iRan001(float fLoc1, float fLoc2, float fMin, float fMax){

	//iRange
	//Damon Vaughn Caskey
	//08/07/2007
	//Returns 1 if distance between two locations falls within Minimum and Maximum range.
	//
	//fLoc1: First entity.
	//fLoc2: Second entity.
	//fMin: Minumum range value.
	//fMax: maximum range value.

	int fDis = fLoc1 - fLoc2;

	if ((fMin) || (fMax)){ //Min or max range provided?
            
		if(fDis > fMin && fDis < fMax){ //Are entities within minimum and maximum range?
        
			return 1; //Return 1.
            
		}else{

			return 0; //Return 0.

		}
    
	}else{ //Within range or ranges simply not provided.

		return 1;  //Return 1.

	}

}

void rema001(int iMap){
     
    //rema001
	//Damon Vaughn Caskey
	//07/14/2007
	//
	//Changes color map as desired.
	//
	//iMap: Desired color map.
     
     void vSelf = getlocalvar("self"); //Get calling entity.     

     setlocalvar("iMap" + vSelf, getentityproperty(vSelf,"map")); //Record current map.
     
     changeentityproperty(vSelf, "map", iMap); //Switch to desired color map.
     
}

void rema002(){
     
    //rema001
	//Damon Vaughn Caskey
	//07/14/2007
	//
	//Changes color map to last recorded remap.
	
     void vSelf = getlocalvar("self"); //Get calling entity.     
     changeentityproperty(vSelf, "map", getlocalvar("iMap" + vSelf)); //Switch to last color map.
     
}

 
void soun001(void vSample, int iPriority, int iLvolume, int iRvolume, int iSpeed, int iLoop){
 
     //soun001
     //Damon Vaughn Caskey
     //08/07/2007
     //
     //Plays sound sample.
     //
     //vSample: Sound sample constant.
     //iPriority: Play priority (0).
     //lVolume: Left volume (120).
     //rVolume: Right volume (120).
     //iSpeed: Speed of play (100).
     //iLoop: Loop setting (1 = loop).     
 
     playsample(openborconstant(vSample), iPriority, iLvolume, iRvolume, iSpeed, iLoop);
     
}

void soun002(){ 

    int iTest = loadsample("data/sounds/voic022.wav","bor.pak");
    
    playsample(iTest, 0, 120, 120, 100, 0);
    
}

void spawn001(void vName, void vAlias, int iMap, float fX, float fY, float fZ, int iAdjust){

	//spawn001
	//Damon Vaughn Caskey
	//07/06/2007
	//
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//vAlias: Alias name given to spawned entity.
	//iMap: Color remap of spawned entity.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
    //fY: Z location adjustment.

	void vSelf = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iDirection = getentityproperty(vSelf, "direction")

	clearspawnentry(); //Clear current spawn entry.
    setspawnentry("name", vName); //Aquire spawn entity by name.

	if (iDirection == 0){ //Is entity facing right?                  
     
         fX = -fX; ////Reverse X direction to match facing.
		     
	}
    
	if (iAdjust == 1){ //If requested, set global variables for persistent subentity location syncronization adjustment.
       
       setglobalvar("fXA" + vSelf, fX); //X adjustment.
       setglobalvar("fYA" + vSelf, fY); //Y adjustment.
       setglobalvar("fZA" + vSelf, fZ); //Z adjustment.
 
    }

	fX = fX + getentityproperty(vSelf, "x"); //Get X location and add adjustment.
    fY = fY + getentityproperty(vSelf, "a"); //Get Y location and add adjustment.
    fZ = fZ + getentityproperty(vSelf, "z"); //Get Z location and add adjustment.
	
	setspawnentry("alias", vAlias); //Set alias.
	setspawnentry("map", iMap); //Set color remap.
	
	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "parent", vSelf); //Set caller as parent.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.
    
    setlocalvar(vAlias + vSelf, vSpawn); //Store spawned entity in persistent local variable.
	return vSpawn; //Return spawn.

}

void spawn002(void vName, void vAlias, int iMap, float fX, float fY, float fZ, float fYJ, float fXJ, float fZJ){
     
    //spawn002
	//Damon Vaughn Caskey
	//07/14/2007
	//
	//Spawns desired entity, then kills it. Intended for decapitation and lost body parts.
	//
	//vName: Spawn model name.
	//iMap: Desired starting remap of spawn.
	//fX: Starting X location adjustment.
	//fY: Starting Y location adjustment.
	//fZ: Starting Z location adjustment.
	//fYJ: Y flight distance.
	//fXJ: X flight distance.
	//fZJ: Z flight distance.
         
     void vSelf = getlocalvar("self"); //Get calling entity.
     int iHP = getentityproperty(vSelf, "health"); //Get caller's current HP.
     
	 void vSpawn = spawn001(vName, vAlias, iMap, fX, fY, fZ, 0); //Spawn entity to be killed with appropriate adjustments.
     
	 damageentity(vSpawn, vSpawn, 10000000, 1, openborconstant("ATK_NORMAL")); //Kill spawned entity (No, killentity() won't work here).
     toss001(vSpawn, fYJ, fXJ, fZJ); //Call toss001.	 
     
}

void sync002(void vSyncSet, float fX, float fY, float fZ, int iDirection){
    
    //sync002
	//Damon Vaughn Caskey
	//06/20/2007
	//
	//Syncronizes target with caller's location.
	//
	//iSync: Sync target setting (see vTar001 function).
	//fX: X distance adjustment (from caller).
	//fZ: Y distance adjustment (from caller).
    //fY: Z distance adjustment (from caller).
    //iDirection: Direction adjustment (see loc001 function).
    
    void vSelf = getlocalvar("self"); //Get calling entity
    void vSync = vTar001(vSyncSet, vSelf); //Get appropriate target.
    
    loc001(vSync, vSelf, fX, fY, fZ, iDirection); //Call loc001 function to perform location sync.       
    
}

void sync003(void vAni, int iFrame){
    
    //sync003
	//Damon Vaughn Caskey
	//07/14/2007
	//
	//Syncronizes callers last spanwed entity with desired animation frame.
	//
	//vAni: Desired animation.
	//iFrame: Desired frame.
        
    void vSelf = getlocalvar("self"); //Get calling entity.
    void vTarget = getlocalvar("vSpawn" + vSelf); //Get last spawned entity.
           
    //changeentityproperty(vTarget, "animation", openborconstant(vAni)); //Switch to desired animation.
    changeentityproperty(vTarget, "animpos", iFrame); //Switch to desired frame.
    
}

void sync004(void vName, int iStatus, int iTarget, float fX, float fY, float fZ, int iDirection){

	//sync004
	//Damon Vaughn Caskey
	//08/02/2007
	//
	//Starts or stops persistent syncing of target entity to caller.
	//
	//iTarget: Synching target, see below.
	//iStatus: Start or stop synching.
	//iDirection: Desired direction of sync target (0 same as caller, 1 = Opposing calller, 2 = left, 3 = right)
	//fX: X location adjustment.
	//fZ: Y location adjustment.
    //fY: Z location adjustment.

	void vSelf = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
		
	if (!(iStatus)){
				
		vSpawn = spawn001(vName, vName, 0, fX, fY, fZ, 1); //Spawn entity.

		setlocalvar(vName + vSelf, vSpawn);
		setglobalvar("vTarget" + vSelf, vTar001(iTarget, vSelf)); //Store target entity as global variable.    
		setglobalvar("vTargetDir" + vSelf, iDirection); //Store desired direction as global variable.    

	}else{

		killentity(getlocalvar(vName + vSelf)); //Destroy entity.
		
		setlocalvar(vName + vSelf,0); //Clear spawned entity persistent local variable.
		setglobalvar("fXA" + vSelf, 0); //Clear X location global variable.
		setglobalvar("fYA" + vSelf, 0); //Clear Y location global variable.
		setglobalvar("fZA" + vSelf, 0); //Clear Z location global variable.
		setglobalvar("vTarget" + vSelf, 0); //Clear target global variable.    
        setglobalvar("vTargetDir" + vSelf, 0); //Clear target direction global variable.    

	}

}

void sync005(void vTar, float fX, float fY, float fZ, int iDirection){
    
    //sync002
	//Damon Vaughn Caskey
	//06/20/2007
	//
	//Syncronizes caller with with target.
	//
	//iSync: Sync target setting (see vTar001 function).
	//fX: X distance adjustment (from caller).
	//fZ: Y distance adjustment (from caller).
    //fY: Z distance adjustment (from caller).
    //iDirection: Direction adjustment (see loc001 function).
    
    void vSelf = getlocalvar("self"); //Get calling entity
    void vSync = vTar001(vTar, vSelf); //Get appropriate target.
    
    loc001(vSelf, vSync, fX, fY, fZ, iDirection); //Call loc001 function to perform location sync.       
    
}

void sync006(){

	void vSelf = getlocalvar("self");
    void vParent = getentityproperty(vSelf, "parent");
	void vTarget = getglobalvar("vTarget" + vParent);
    int iDirection = getglobalvar("vTargetDir" + vParent);
		
    float fX = getglobalvar("fXA" + vParent); //Get X synch adjustment.
    float fY = getglobalvar("fYA" + vParent); //Get Y synch adjustment.
    float fZ = getglobalvar("fZA" + vParent); //Get Z synch adjustment.	
               
    loc001(vSelf, vParent, fX, fY, fZ, iDirection); //Sync self with parent.
    loc001(vTarget, vParent, fZ, fY, fZ, iDirection); //Sync target with parent including adjustments.

}


void vTar001(void vTarget, void vSelf){
	
	//vTar001
	//Damon Vaughn Caskey
	//08/02/2007
	//
	//Returns target entity handle from desired source.
	//
	//itarget: Desired target source.
	//vSelf: Entity searching for target.

	if (!(vTarget)){ //Self.

		return vSelf; //Return "self".
	
	}else if (vTarget == 1){//Current opponent.
		
		return getentityproperty(vSelf, "opponent"); //Get current opponent. 

	}else if (vTarget == 2){ //Current hold victum.

		return getentityproperty(vSelf, "grabbing"); //Get entity vSelf is holding.

	}else if (vTarget == 3){ //Nearest hostile entity.

		return findtarget(vSelf); 
		
    }else if (vTarget == 4){ //Caller's parent.

		return getentityproperty(vSelf, "parent");

	}else{ //Variable.

		return getlocalvar(vTarget + vSelf); //Get and return variable matching caller and vTarget.

	}

}

void toss001(void vTarget, float fY, float fX, float fZ){

    //toss001
    //Damon Vaughn Caskey
    //06/28/2007
    //
    //Toss target entity.
    //
	//vTarget: Entity to toss.
	//fY, fX, fZ: Vertical, horizontal, and depth distance respectively.
    
	if (getentityproperty(vTarget, "direction") == 0){ //Facing left?
		
		fX = -fX; //Reverse horizontal adjustment.
	
	} 
    
	tossentity(vTarget, fY, fX, fZ); //Perform toss action on target.
    
}

void toss002(void vTarget, float fY, float fX, float fZ){

    //toss001
    //Damon Vaughn Caskey
    //06/28/2007
    //
    //Determine target of caller and toss.
    //
	//vTarget: Entity or target set.
	//fY, fX, fZ: Vertical, horizontal, and depth distance respectively.
    
	void vSelf = getlocalvar("self"); //Get calling entity.

	toss001(vTar001(vTarget,vSelf), fY, fX, fZ); //Activate toss function with target.
    
}

void var001(void vName, void vValue){

	void vSelf = getlocalvar("self"); //Get calling entity.

	setlocalvar(vName + vSelf, vValue);	

}

void velo001(float fX, float fZ, float fY){
     
    //velo001
	//Damon Vaughn Caskey
	//05/06/2007
	//
	//Replicates movement effect.
	//
	//fX: X axis speed.
	//fZ: Z axis speed.
	//fY: Y axis speed.
	
	void vSelf = getlocalvar("self"); //Get calling entity.
	
	if (getentityproperty(vSelf, "direction")==0){ //Is entity facing right?                  
     
         fX = -fX; ////Reverse X direction to match facing.
         
    }         
	
	changeentityproperty(vSelf, "velocity", fX, fZ, fY); //Apply movement.

}

void weap001(int iWep){
 
    //weap001
	//Damon Vaughn Caskey
	//06/30/2007
    //Sets callers weapon model.
    //
    //iWep: Desired weapon model index.
     
     void vSelf = getlocalvar("self"); //Get calling entity.
     int iMap = getentityproperty(vSelf, "map"); //Get current remap.
     
     if ((iWep) && (iMap)){ //If requested model is not default and a remap is being used, record remap.
     
        setlocalvar("iMap" + vSelf, iMap); 
          
     } 
     
     changeentityproperty(vSelf, "weapon", iWep, 0); //Switch to desired model.
     changeentityproperty(vSelf, "map", getlocalvar("iMap" + vSelf)); //Defeat weapon remap bug by forcing a switch back to remap.
     
}

