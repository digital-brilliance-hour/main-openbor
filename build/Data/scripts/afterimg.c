#include "data/scripts/trailer.h"
void afterimg()
{
	afterimg2(0);
}
void afterimg2(int tm)
{
	int k, facing, cd;
	void cmap;
	void spr;
	float a, z, x;
	void ent = getlocalvar("self");
	int elapsed_time = openborvariant("elapsed_time");
	//***************************************
	int trailerd=getlocalvar("interval");
	int alpha=getlocalvar("alpha");
	int lifespan=getlocalvar("lifespan");
	int	color=getlocalvar("color");
	//***************************************
	if (trailerd==NULL()){trailerd=10;}
	if (alpha==NULL()){alpha=6;}
	if (lifespan==NULL() || lifespan<=0){lifespan=30;}
	if (color==NULL()){color=0;}
	//***************************************
	if (tm || (elapsed_time%trailerd==0))
	{
		//***************************************
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
				setglobalvar("trailer"+k+".c", elapsed_time );
				setglobalvar("trailer"+k+".color",color);
				setglobalvar("trailer"+k+".alpha",alpha);
				setglobalvar("trailer"+k+".lifespan",lifespan);
				//**********New Version Supported****************************************

				if (getlocalvar("colormap")==-1)
				{
					setglobalvar("trailer"+k+".colormap",getentityproperty(ent, "colourmap"));
				}else{
					cmap=getentityproperty(ent, "map");
					changeentityproperty(ent, "colourmap", getlocalvar("colormap")); 
					setglobalvar("trailer"+k+".colormap",getentityproperty(ent, "colourmap"));
					changeentityproperty(ent, "map",cmap);
				}
				//***********************************************************************
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

void gen_tail_d(void ent,char ani,int color,int startframe,int endframe,int interval,int lifespan,int alpha,int colourmap)
{
	void AniID = getani();
	int anipos=getentityproperty(ent,"animpos");
	
	if(AniID == openborconstant(ani) && anipos>=startframe && anipos<=endframe){
		//***********************************
		setlocalvar("interval",interval);//The interval that the 2 tails are generated
		setlocalvar("alpha",alpha);
		setlocalvar("lifespan",lifespan);
		setlocalvar("color",color);
		setlocalvar("colormap",colourmap);
		//***********************************
		afterimg();
	}
}
void gen_tail(char ani)
{
	void ent=getlocalvar("self");
	gen_tail_d(ent,ani,0,0,999,2,1,6,0);
}

void tail(int color,int lifespan,int alpha,int colourmap)
{
	setlocalvar("interval",20);
	setlocalvar("alpha",alpha);
	setlocalvar("lifespan",lifespan);
	setlocalvar("color",color);
	setlocalvar("colormap",colourmap);
	afterimg2(1);
}
