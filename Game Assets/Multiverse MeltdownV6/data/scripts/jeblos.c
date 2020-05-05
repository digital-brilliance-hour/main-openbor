#import "data/scripts/library/spawn.h"
#import "data/scripts/fileEd.c"

void main()
{// Death script which deducts health if player falls to hole instead of losing life directly
    void self = getlocalvar("self");
    int y = getentityproperty(self,"a");
    int PIndex = getentityproperty(self,"playerindex");
    int PLives = getplayerproperty(PIndex,"lives");
    int HPs = getglobalvar(PIndex+"HPs");

    if(y < -120 && HPs){
      changeplayerproperty(PIndex, "lives", PLives+1);
    }
    if(PLives==1 && HPs==NULL()){
      Unlock(4,"Test.txt");
      spawnXT("TrKilled", 240, 0, 90, "Pipor", 957);
    }
}
