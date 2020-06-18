#include "data/scripts/levelup/lvup.c"
void main()
{
   setglobalvar("zoomentity", NULL());

	 void p;
	 int i, hp, mp, lv, num, stage, maxhp, newhp, score;
	for(i=0; i<4; i++){
		 p = getplayerproperty(i, "entity");
		num = i+1;
		 if(p){
		 	score=getplayerproperty(i,"score");
		 	changeentityproperty(p, "maxhealth", getglobalvar("maxhealth_"+num+"P"));
			stage = openborvariant("current_stage");
			if(stage % 3 != 0) {
				hp = getglobalvar("saved_health_"+num+"P");
				if(hp >= 0){
					maxhp = getentityproperty(p, "maxhealth");
					newhp = maxhp/2;
					changeentityproperty(p, "health", hp+newhp);
				}
	 		}
	 		else {
	 			changeentityproperty(p, "health", getglobalvar("maxhealth_"+num+"P"));
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

				changeentityproperty(p,"offense",openborconstant("ATK_NORMAL"),getglobalvar("offense_"+num+"P"));
				changeentityproperty(p,"defense",openborconstant("ATK_NORMAL"),getglobalvar("defense_"+num+"P"));
				log(getglobalvar("offense_"+num+"P"));
			}
	 	}
	} 
}
