#include "data/scripts/toad.c"


void main()
{// Changes animation based on rush count.
    void self = getlocalvar("self");
    int rush = getentityproperty(self, "rush_count");
    int anim= getentityproperty(self, "animationid");

     if (rush > 2){
       if (anim != openborconstant("ANI_FREESPECIAL") ){
         changeentityproperty(self, "animation", openborconstant("ANI_FREESPECIAL") );
       }
     }
}




