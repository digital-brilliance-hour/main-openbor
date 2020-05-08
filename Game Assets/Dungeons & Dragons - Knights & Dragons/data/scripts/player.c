#import "data/scripts/levelup/lvup.c"
#import "data/scripts/pblock.c"

/* 
 * MUGEN-styled velSet
 * dirFree: if defined, applies left/right movement
 * instead back/front
 * created by Don Drago
 */
void velSet (float x, float y, float z, void dirFree) {
    void self = getlocalvar("self");	
	int side = 1;
	
	if(dirFree == NULL()) {
		side = (getentityproperty(self, "direction")== 0) ? (-1) : (1);		
	}
	
	x = x*side;
	
	changeentityproperty(self, "velocity", x, z, y);
}


/* 
 * stores X velocity in a local var,
 * to be retrieved by retrieveXvel()
 * created by Don Drago
 */
void storeXvel() {
	void self = getlocalvar("self");
	int side = (getentityproperty(self, "direction")== 0) ? (-1) : (1);

	setlocalvar("xVel" + self, getentityproperty(self,"xdir")*side);
}

/* 
 * retrieves X velocity in a local var,
 * stored by storeXvel()
 * created by Don Drago
 */
float retrieveXvel() {
	void self = getlocalvar("self");
	return getlocalvar("xVel" + self);
}