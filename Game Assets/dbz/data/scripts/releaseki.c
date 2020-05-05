void main(){ //Release attack3 button
	void self = getlocalvar("self");
	void iPIndex = getentityproperty(self, "playerindex");
	void vAniID = getentityproperty(self, "animationid");
	int iAttack3R = getplayerproperty(iPIndex, 2, "attack3");
	
	if(vAniID = openborconstant("ANI_FOLLOW1")){
		if(iAttack3R){
		//	changeentityproperty(self, "aiflag", "idling", 0);
			performattack(self, openborconstant("ANI_FOLLOW2"));
		}
	}
}