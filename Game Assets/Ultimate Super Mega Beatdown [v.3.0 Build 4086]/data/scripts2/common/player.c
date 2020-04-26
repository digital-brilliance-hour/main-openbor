void block(int Flag)
{
    void self = getlocalvar("self");
    changeentityproperty(self, "aiflag", "blocking", Flag);
}

void costSelf(int Damage)
{// Prevents hero from performing the animation if his/her health is less than Limit
    void self = getlocalvar("self");
    void mp = getentityproperty(self,"mp"); //Get entity's HP.
	int health;
	int v=mp - Damage;//v is the diff

/*	depost(0);
	clearSlam();*/	

	if(v>=0){
		changeentityproperty(self,"mp",v);
	}else{
		v=-v;
		health=getentityproperty(self,"health");
		if (health>v){
			changeentityproperty(self,"health",health-v);
			changeentityproperty(self,"mp",0);
		}else{
			 setidle(self);
		}
	}
}

void damageMp(int Damage)
{
/*
    void self = getlocalvar("self");
    void mp = getentityproperty(self,"mp"); //Get entity's HP.
	int health;
	int v=mp - Damage;//v is the diff
	if(v>=0){
		changeentityproperty(self,"mp",v);
	}else{
		//Mp is not enough!!
		sendMsg("Danger!!");
		v=-v*5;
		health=getentityproperty(self,"health");
		//if (health>v){
		changeentityproperty(self,"health",health-v);
		changeentityproperty(self,"mp",0);
		//}
	}*/
}
void fullMpAni(char ani)
{
    void self = getlocalvar("self");
    void mp = getentityproperty(self,"health"); //Get entity's HP.
	//void mph=getentityproperty(self,"maxmp");
	if (mp<=25){changeAni(ani);}
}
void sendMsg(char msg)
{
	//setglobalvar("msg",msg);
}
void incAtt()
{
	int c;
	int etime2 = openborvariant("elapsed_time");
	int etime=getlocalvar("etime");
	if (etime==NULL()){etime=0;}

	c = getlocalvar("lcounter");
	if ((etime2-etime)>230||(etime2-etime)<-230){
		c=0;
	}
	else{
		if (c!=NULL()){
			c++;
			if (c>3){
				//sendMsg("ChainBreak!!");
				changeAni("ANI_ATTACK3");
				c=0;
			}
		}
		else{
			c=1;
		}
	}
	setlocalvar("lcounter",c);
	setlocalvar("etime",etime2);
}
void makeInv(long invTime)
{
	void vSelf = getlocalvar("self");
	long iTime = openborvariant("elapsed_time");
	changeentityproperty(vSelf, "invincible", 1);
	changeentityproperty(vSelf, "invinctime", iTime + invTime);
}

