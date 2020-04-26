#include "data/scripts/trailer.h"
#include "data/scripts/com/draw0001.h"
#include "data/scripts/scr/debug.c"
#include "data/scripts/scr/gui.c"
#include "data/scripts/scr/charged.c"


void main()
{  //Tested for Crash
   void ent = getlocalvar("self");
   void chargedup = 0;
   if ( checkent(ent) == 1 ) {
     void AniID = getentityproperty(ent,"animationID");
     if ( getentityvar(ent, 4) != NULL() )
     {
       chargedup = getentityvar(ent, 4);
     }
     if ( chargedup == 1)
     {
       if ( chargedshouldreset(ent) == 1 )
       {
         disablecharge(ent);
       }
     }
    //dogui(ent);
    //debugaiflags(ent);

    if(
           AniID == openborconstant("ANI_FREESPECIAL")
        || AniID == openborconstant("ANI_FREESPECIAL2")
        || AniID == openborconstant("ANI_FREESPECIAL3")
        || AniID == openborconstant("ANI_FREESPECIAL4")
        || AniID == openborconstant("ANI_FREESPECIAL5")
        || AniID == openborconstant("ANI_FREESPECIAL6")
        || AniID == openborconstant("ANI_FREESPECIAL7")
        || AniID == openborconstant("ANI_FREESPECIAL8")
        || chargedup == 1
	    ){
	    
	    //if (   //getindexedvar(27) == NULL() ||
            //     getindexedvar(27) == 1) {
            //}
              doani();
            }
   }
}

void doani()
{
  	int i, j, k;
	void spr;
	int facing, cd;
	float a, z, x;

	void ent = getlocalvar("self");
	int elapsed_time = openborvariant("elapsed_time");


	if(elapsed_time%trailerd==0)
	{
		spr = getentityproperty(ent, "sprite");
		x = getentityproperty(ent, "x");
		z = getentityproperty(ent, "z");
		a = getentityproperty(ent, "a");
		facing = !getentityproperty(ent, "direction");
		for(k=1; k<=trailermax; k++) //find an empty trailer slot
		{
			if(getglobalvar("trailer"+k+".s")==NULL())
			{
				setglobalvar("trailer"+k+".s", spr);
				setglobalvar("trailer"+k+".x", x);
				setglobalvar("trailer"+k+".z", z);
				setglobalvar("trailer"+k+".a", a);
				setglobalvar("trailer"+k+".f", facing);
				setglobalvar("trailer"+k+".c", trailerc*trailerd);
				setglobalvar("trailer"+k+".colormap",getentityproperty(ent, "colourmap"));
				break;
			}
		}
	}
}