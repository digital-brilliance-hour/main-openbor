void keyInt(void Ani, int Frame, void Key, int Hflag, int Limit)
{
	void self = getlocalvar("self");
	void tar=getentityproperty(self,"opponent");
	int ok;
	if (Hflag)
	{
		if(getentityproperty(tar,"exists") 
		&& !getentityproperty(tar,"dead") 
		&& getentityproperty(tar,"animationid")!=openborconstant("ANI_FALL")
		&& getentityproperty(tar,"animationid")!=openborconstant("ANI_RISE")
		&& getentityproperty(tar,"direction")!=getentityproperty(self,"direction")
		)
		{
			int dis_z=getentityproperty(tar,"z") - getentityproperty(self,"z");
			if (dis_z<0){dis_z=0;}else{}
			if (dis_z>15){return;}else{}
		}else{
			return;
		}
	}else{
	}

	int iPIndex = getentityproperty(self,"playerindex");
	void iRKey;

	if (Key=="U"){
		iRKey = playerkeys(iPIndex, 0, "moveup");
	}

	if (Key=="D"){
		iRKey = playerkeys(iPIndex, 0, "movedown");
	}

	if (Key=="F"){
		if (getentityproperty(self,"direction")==0){
			iRKey = playerkeys(iPIndex, 0, "moveleft");
		}else{
			iRKey = playerkeys(iPIndex, 0, "moveright");
		}
	}

	if (Key=="FJ"){
		if (getentityproperty(self,"direction")==0){
			iRKey = playerkeys(iPIndex, 0, "moveleft","jump");
		}else{
			iRKey = playerkeys(iPIndex, 0, "moveright","jump");
		}
	}


	if (Key=="B"){
		if (getentityproperty(self,"direction")==1){
			iRKey = playerkeys(iPIndex, 0, "moveleft");
		}else{
			iRKey = playerkeys(iPIndex, 0, "moveright");
		}
	}

	if (Key=="BJ"){ 
		if (getentityproperty(self,"direction")==1){
			iRKey = playerkeys(iPIndex, 0, "moveleft","jump");
		}else{
			iRKey = playerkeys(iPIndex, 0, "moveright","jump");
		}
	}

	if (Key=="J"){ 
		iRKey = playerkeys(iPIndex, 0, "jump");
	}

	if (Key=="A"){
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

	if (iRKey){
		changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
		changeentityproperty(self, "animpos", Frame);
	}
}


