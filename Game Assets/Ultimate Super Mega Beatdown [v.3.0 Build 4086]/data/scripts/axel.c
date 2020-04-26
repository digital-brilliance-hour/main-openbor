#include "data/scripts/common/spawn.c"
#include "data/scripts/common/key.c"
#include "data/scripts/common/shoot.c"
#include "data/scripts/common/commons.c"
#include "data/scripts/common/slam.c"
#include "data/scripts/common/player.c"



void call()
{
	//int r = rand()%500+500;
	////**************8%possiblility*******************
	//if (r <=80){
		spawn01 ("SFire", 30 ,190 ,30);
		spawn01 ("SFire", -60, 1180, 0);
		spawn01 ("SFire", -20, 200, -30);
		spawn01 ("SFire" ,100 , 1190, -30);
		spawn01 ("SFire", -45, 1010, 10);
		spawn01 ("SFire" ,30 ,520, -25);
		spawn01 ("SFire", 110, 390, 15);
		spawn01 ("SFire" ,-80, 780, -30);
		spawn01 ("SFire" ,55, 1190, 0);
		spawn01 ("SFire" ,-80 ,630 ,0);
	//}
}

