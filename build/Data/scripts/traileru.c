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

void show_enemy_health()
{
	int i,facing, cd, hp, maxhealth, barsize;
	void spr;
	float a, z, x, ratio;
	int elapsed_time = openborvariant("elapsed_time");
	int lifespan,alpha;

	int  iEntity;
	void vEntity;
	void self        = getlocalvar("self");
	int  iMax        = openborvariant("ent_max");
	int Def;
	         
	for(iEntity=0; iEntity<iMax; iEntity++)
	{     
          vEntity = getentity(iEntity);
          if(getentityproperty(vEntity, "type")==openborconstant("TYPE_enemy"))
          {   
          	spr = getglobalvar("enemy_"+getentityproperty(vEntity, "name")+iEntity+".s");

          	if(spr)
			{
				cd = getglobalvar("enemy_"+getentityproperty(vEntity, "name")+iEntity+".c");
				lifespan=getglobalvar("enemy_"+getentityproperty(vEntity, "name")+iEntity+".lifespan");
				alpha=getglobalvar("enemy_"+getentityproperty(vEntity, "name")+iEntity+".alpha");
				int color=getglobalvar("enemy_"+getentityproperty(vEntity, "name")+iEntity+".color");
				if(elapsed_time-cd>=lifespan || cd-elapsed_time>=lifespan) 
				{
					setglobalvar("enemy_"+getentityproperty(vEntity, "name")+iEntity+".s", NULL());
				}
				else
				{
					x = getglobalvar("enemy_"+getentityproperty(vEntity, "name")+iEntity+".x");
					z = getglobalvar("enemy_"+getentityproperty(vEntity, "name")+iEntity+".z");
					a = getglobalvar("enemy_"+getentityproperty(vEntity, "name")+iEntity+".a");
					facing = getglobalvar("enemy_"+getentityproperty(vEntity, "name")+iEntity+".f");
					hp = getentityproperty(vEntity,"health");
					maxhealth = getentityproperty(vEntity,"maxhealth");
					ratio = getentityproperty(vEntity, "health")*100/getentityproperty(vEntity,"maxhealth");
					barsize = 50 * ratio;
					//entity,flag,scalex, int scaley, int flipx, int flipy, int shiftx, int alpha, int remap, int fillcolor, int rotate, int fliprotate, int transparencybg, void* colourmap);
					if (color==0){
						setdrawmethod(NULL(), 1, 256, 256, facing, 0, 0,alpha, 0,color ,0,0,0,getglobalvar("enemy_"+getentityproperty(vEntity, "name")+iEntity+".colormap"));
						//drawstring(2,180,1,getglobalvar("trailer"+i+".colormap"));
						//setdrawmethod(NULL(), 1, 256, 256, facing, 0, 0,alpha, 0,color ,0,0,0,1);
					}else{
						setdrawmethod(NULL(), 1, 256, 256, facing, 0, 0,alpha, 0,color ,0,0,0,NULL());
					}
					drawbox(x-openborvariant("xpos")-1, z-a-openborvariant("ypos")+1, barsize/100, 10, 9998, rgbcolor(0,0,0), 6);
					if(ratio <= 25) {
						drawbox(x-openborvariant("xpos"), z-a-openborvariant("ypos"), barsize/100, 10, 9999, rgbcolor(255,0,0), 0);
					
					}
					else {
						drawbox(x-openborvariant("xpos"), z-a-openborvariant("ypos"), barsize/100, 10, 9999, rgbcolor(0,255,255), 0);
					
					}
        			drawstring(x-openborvariant("xpos"), z-a-openborvariant("ypos")+13, 0, getentityproperty(vEntity, "name"));
					//drawsprite(spr, x-openborvariant("xpos"), z-a-openborvariant("ypos"), z-i, 0);
					//setdrawmethod(NULL(), 0, 256, 256, 0, 0, 0, 0, 0);
				}
			}
          }
	}
}
