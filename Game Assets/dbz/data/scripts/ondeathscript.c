void main(){
	void vSelf = getlocalvar("self");
	
	int iECnt = openborvariant("count_entities");
	int iEnt;
	void vEnt;
	
	for(iEnt=0; iEnt<iECnt; iEnt++) {
		vEnt= getentity(iEnt);
		if(!getentityproperty(vEnt,"exists")) continue;
		if(getentityproperty(vEnt, "parent") == vSelf) killentity(vEnt);
		
	}
}