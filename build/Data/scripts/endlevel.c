#include "data/scripts/story/story_clear.c"
void main()
{
	clearStory();
	setglobalvar("zoomentity", NULL());

	void p;
	 int i, hp, maxhp, mp, num;
	 for(i=0; i<4; i++){
		 p = getplayerproperty(i, "entity");
		 hp = getentityproperty(p, "health");
		 maxhp = getentityproperty(p, "maxhealth");
		 num = i+1;
		 if(p){
			setglobalvar("saved_health_"+num+"P", hp);
			if(getentityproperty(p, "maxmp") < 1) {
				setglobalvar("maxmp_"+num+"P", 100);
			}
			else {
				setglobalvar("maxmp_"+num+"P", getentityproperty(p, "maxmp"));
			}
			setglobalvar("offense_"+num+"P", getentityproperty(p,"offense",openborconstant("ATK_NORMAL")));

			setglobalvar("defense_"+num+"P", getentityproperty(p,"defense",openborconstant("ATK_NORMAL")));

			setglobalvar("maxhealth_"+num+"P", getentityproperty(p, "maxhealth"));


		 }
	 } 
}
