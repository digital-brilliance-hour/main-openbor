#include "data/scripts/trailer.h"

void main()
{
	int i, j, k;
	void spr;
	int facing, cd;
	float a, z, x;

	for(i=1; i<=trailermax; i++)
	{
		spr = getglobalvar("trailer"+i+".s");
		if(spr)
		{
			cd = getglobalvar("trailer"+i+".c");
			if(!cd) 
			{
				setglobalvar("trailer"+i+".c", NULL());
				setglobalvar("trailer"+i+".s", NULL());
				setglobalvar("trailer"+i+".x", NULL());
				setglobalvar("trailer"+i+".z", NULL());
				setglobalvar("trailer"+i+".a", NULL());
			}
			else
			{
				if(openborvariant("game_paused")==0)
				{
					setglobalvar("trailer"+i+".c", cd-1);
				}
				x = getglobalvar("trailer"+i+".x");
				z = getglobalvar("trailer"+i+".z");
				a = getglobalvar("trailer"+i+".a");
				facing = getglobalvar("trailer"+i+".f");

				setdrawmethod(NULL(), 1, 256, 256, facing, 0, 0, 6, 0);
				drawsprite(spr, x-openborvariant("xpos"), z-a-openborvariant("ypos"), z-i, 0);
				setdrawmethod(NULL(), 0, 256, 256, 0, 0, 0, 0, 0, 0);
			}
		}
	}
}

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
