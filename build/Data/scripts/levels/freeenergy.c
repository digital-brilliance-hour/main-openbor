void main() {
	
    int P1 = getplayerproperty(0, "entity");
    int P2 = getplayerproperty(1, "entity");
    if(P1) {
    	changeentityproperty(P1, "health", getentityproperty(P1, "maxhealth"));
    }
    if(P2) {
    	changeentityproperty(P2, "health", getentityproperty(P2, "maxhealth"));

    }
}