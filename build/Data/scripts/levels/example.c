void main() {
	
    int P1 = getplayerproperty(0, "entity");
    int P2 = getplayerproperty(1, "entity");
    if(P1) {
    	int key = getplayerproperty(0, "releasekeys");
    	//log(key);
    	int pressed = playerkeys(0, 0, "attack");
    	if(pressed > 0) {
    		jumptobranch("", 1);
    	}
    }
    if(P2) {
        int key = getplayerproperty(1, "releasekeys");       
        int pressed = playerkeys(1, 0, "attack");        
        if(pressed > 0) {            
            jumptobranch("", 1);        
        }    

    }
}