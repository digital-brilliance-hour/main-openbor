#include "data/scripts/trailer.h"

void afterimg()
{
	int k, facing, cd;
	void spr;
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
		for(k=1; k<=trailermax; k++)
		{
			if(getglobalvar("trailer"+k+".s")==NULL())
			{
				setglobalvar("trailer"+k+".s", spr);
				setglobalvar("trailer"+k+".x", x);
				setglobalvar("trailer"+k+".z", z);
				setglobalvar("trailer"+k+".a", a);
				setglobalvar("trailer"+k+".f", facing);
				setglobalvar("trailer"+k+".c", elapsed_time );
				setglobalvar("trailer"+k+".colormap",getentityproperty(ent, "colourmap"));
				break;
			}
		}
	}
}

void getani()
{
	void ent = getlocalvar("self");
	return getentityproperty(ent,"animationID");
}