#include "data/scripts/trailer.h"
void afterImg()
{
	int i,facing, cd;
	void spr;
	float a, z, x;
	int elapsed_time = openborvariant("elapsed_time");
	int lifespan,alpha;

	for(i=1; i<=trailermax; i++)
	{
		spr = getglobalvar("trailer"+i+".s");
		if(spr)
		{
			cd = getglobalvar("trailer"+i+".c");
			lifespan=getglobalvar("trailer"+i+".lifespan");
			alpha=getglobalvar("trailer"+i+".alpha");
			int color=getglobalvar("trailer"+i+".color");

			if(elapsed_time-cd>=lifespan || cd-elapsed_time>=lifespan) 
			{
				setglobalvar("trailer"+i+".s", NULL());
			}
			else
			{
				x = getglobalvar("trailer"+i+".x");
				z = getglobalvar("trailer"+i+".z");
				a = getglobalvar("trailer"+i+".a");
				facing = getglobalvar("trailer"+i+".f");
				//entity,flag,scalex, int scaley, int flipx, int flipy, int shiftx, int alpha, int remap, int fillcolor, int rotate, int fliprotate, int transparencybg, void* colourmap);
				if (color==0){
					setdrawmethod(NULL(), 1, 256, 256, facing, 0, 0,alpha, 0,color ,0,0,0,getglobalvar("trailer"+i+".colormap"));
					//drawstring(2,180,1,getglobalvar("trailer"+i+".colormap"));
					//setdrawmethod(NULL(), 1, 256, 256, facing, 0, 0,alpha, 0,color ,0,0,0,1);
				}else{
					setdrawmethod(NULL(), 1, 256, 256, facing, 0, 0,alpha, 0,color ,0,0,0,NULL());
				}

				drawsprite(spr, x-openborvariant("xpos"), z-a-openborvariant("ypos"), z-i, 0);
				setdrawmethod(NULL(), 0, 256, 256, 0, 0, 0, 0, 0);
			}
		}
	}
}
