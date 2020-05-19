void main()
{
   setglobalvar("zoomentity", NULL());

	 void p;
	 int i, hp, num, stage, maxhp, newhp;
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
	 	}
	}  
}
