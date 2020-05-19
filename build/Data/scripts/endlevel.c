#include "data/scripts/story/story_clear.c"
void main()
{
	clearStory();
	setglobalvar("zoomentity", NULL());

	void p;
	 int i, hp, num;
	 for(i=0; i<4; i++){
		 p = getplayerproperty(i, "entity");
		 hp = getentityproperty(p, "health");
		 num = i+1;
		 if(p){
			 if(getglobalvar("saved_health_"+num+"P") == NULL()){
			 	setglobalvar("saved_health_"+num+"P", hp);
			 }
		 }
	 } 
}
