void keyCheck()
{
	/*void self = getlocalvar("self");
	int iPIndex = getentityproperty(self,"playerindex"); //Get player index
	int iRKey = playerkeys(iPIndex, 0, "attack"); // "Special"
	setlocalvar("flashKey",iRKey);*/
	
}

void counter()
{
	/*int iRKey = getlocalvar("flashKey"); // "Special"
	if (!iRKey){
		void self = getlocalvar("self");
		int iPIndex = getentityproperty(self,"playerindex"); //Get player index
		int iRKey = playerkeys(iPIndex, 0, "attack");
		if (iRKey){
			sendMsg("Counter!");
			int hp=getentityproperty(self,"health");
			//***************
			int damage=getglobalvar(self+"damage");
			//***************
			changeentityproperty(self,"health",hp+damage);

			changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW4")); //Change the animation
			//call();
		}
	}*/
}

void keyInt(void Ani, int Frame, void Key, int Hflag, int Limit)
{
    void self = getlocalvar("self");
    int iPIndex = getentityproperty(self,"playerindex");
    void iRKey;

	if (Key=="U"){
		iRKey = playerkeys(iPIndex, 0, "moveup");
	}

	if (Key=="D"){
		iRKey = playerkeys(iPIndex, 0, "movedown");
	}

	if (Key=="F"){ //Up Required?
		if (getentityproperty(self,"direction")==0){
			iRKey = playerkeys(iPIndex, 0, "moveleft");
		}else{
			iRKey = playerkeys(iPIndex, 0, "moveright");
		}
	}

	if (Key=="FJ"){ //Up Required?
		if (getentityproperty(self,"direction")==0){
			iRKey = playerkeys(iPIndex, 0, "moveleft","jump");
		}else{
			iRKey = playerkeys(iPIndex, 0, "moveright","jump");
		}
	}


	if (Key=="B"){ //Up Required?
		if (getentityproperty(self,"direction")==1){
			iRKey = playerkeys(iPIndex, 0, "moveleft");
		}else{
			iRKey = playerkeys(iPIndex, 0, "moveright");
		}
	}

	if (Key=="BJ"){ //Up Required?
		if (getentityproperty(self,"direction")==1){
			iRKey = playerkeys(iPIndex, 0, "moveleft","jump");
		}else{
			iRKey = playerkeys(iPIndex, 0, "moveright","jump");
		}
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

	if (Key=="UJ"){ //Up and Jump Required?
		iRKey = playerkeys(iPIndex, 0, "moveup", "jump"); // "Up" + "Jump"
	}

	if (Hflag==1){ //Not holding the button case?
		iRKey = !iRKey; //Take the opposite condition
	}

	if (iRKey){
		changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
		changeentityproperty(self, "animpos", Frame);
	}
}


//void keyflip()
//{// Change hero's facing direction if left or right is pressed
//    void self = getlocalvar("self");
//    int iPIndex = getentityproperty(self,"playerindex"); //Get player index
//
//    if (playerkeys(iPIndex, 0, "moveleft")){ // Left is pressed?
//      changeentityproperty(self, "direction", 0); //Face left
//    } else if (playerkeys(iPIndex, 0, "moveright")){ // Right is pressed?
//      changeentityproperty(self, "direction", 1); //Face right
//    }
//}

void keyMove(float V)
{// Move hero if direction button is pressed
      void self = getlocalvar("self");
      int iPIndex = getentityproperty(self,"playerindex"); //Get player index
	float xdir = 0;
	float zdir = 0;

      if (playerkeys(iPIndex, 0, "moveleft")){// Left is pressed?
	  xdir = -V;
	} else if(playerkeys(iPIndex, 0, "moveright")){// Right is pressed?
	  xdir = V;
      }

	//if(playerkeys(iPIndex, 0, "moveup")){// Up is pressed?
	//  zdir = -V/2;
	//} else if(playerkeys(iPIndex, 0, "movedown")){// Down is pressed?
	//  zdir = V/2;
 //     }

	changeentityproperty(self, "velocity", xdir, zdir);
}

