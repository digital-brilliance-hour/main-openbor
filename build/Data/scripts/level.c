void main()
{
   setglobalvar("zoomentity", NULL());

	 void p;
	 int i, hp, mp, lv, num, stage, maxhp, newhp;
	for(i=0; i<4; i++){
		 p = getplayerproperty(i, "entity");
		num = i+1;
		 if(p){
			stage = openborvariant("current_stage");
			if(stage % 3 != 0) {
				 hp = getglobalvar("saved_health_"+num+"P");
				if(hp > 0){
					maxhp = getentityproperty(p, "maxhealth");
					newhp = maxhp/2;
					changeentityproperty(p, "health", hp+newhp);
				 }
	 		}
			if("Travel"!=getentityproperty(p, "model")) {
				if(getglobalvar("maxmp_"+num+"P") == NULL()){
					if(getentityproperty(p, "maxmp") < 1) {
						changeentityproperty(p, "maxmp",100);
						setglobalvar("maxmp_"+num+"P", 100);
					}
					else {
						setglobalvar("maxmp_"+num+"P", getentityproperty(p, "maxmp"));
					}
				}
				else {
					mp = getentityproperty(p, "maxmp");
					changeentityproperty(p, "maxmp",getglobalvar("maxmp_"+num+"P"));
				}
				
				changeentityproperty(p, "mp",0);
			}
	 	}
	} 
}
