#include "data/scripts/trailer.h"
void show_enemy_health()
{
	show_enemy_health2(0);
}
void show_enemy_health2(int tm)
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

	int  iEntity;
	void vEntity;
	int  iMax        = openborvariant("ent_max");
	int Def;
	    
	if (trailerd==NULL()){trailerd=10;}
	if (alpha==NULL()){alpha=6;}
	if (lifespan==NULL() || lifespan<=0){lifespan=90;}
	if (color==NULL()){color=0;}
	//***************************************
	//if (tm || (elapsed_time%trailerd==0))
	//{
		//***************************************
		spr = getentityproperty(ent, "sprite");
		x = getentityproperty(ent, "x");
		z = getentityproperty(ent, "z");
		a = getentityproperty(ent, "a");
		facing = !getentityproperty(ent, "direction");
     
		for(iEntity=0; iEntity<iMax; iEntity++)
		{ 
			vEntity = getentity(iEntity);
			if(ent == vEntity) 
			{
				if(getglobalvar("enemy_"+getentityproperty(vEntity, "name")+iEntity+".s")==NULL())
				{
					setglobalvar("enemy_"+getentityproperty(vEntity, "name")+iEntity+".s", spr);
					setglobalvar("enemy_"+getentityproperty(vEntity, "name")+iEntity+".x", x);
					setglobalvar("enemy_"+getentityproperty(vEntity, "name")+iEntity+".z", z);
					setglobalvar("enemy_"+getentityproperty(vEntity, "name")+iEntity+".a", a);
					setglobalvar("enemy_"+getentityproperty(vEntity, "name")+iEntity+".f", facing);
					setglobalvar("enemy_"+getentityproperty(vEntity, "name")+iEntity+".c", elapsed_time );
					setglobalvar("enemy_"+getentityproperty(vEntity, "name")+iEntity+".color",color);
					setglobalvar("enemy_"+getentityproperty(vEntity, "name")+iEntity+".alpha",alpha);
					setglobalvar("enemy_"+getentityproperty(vEntity, "name")+iEntity+".lifespan",lifespan);
					//**********New Version Supported****************************************

					if (getlocalvar("colormap")==-1)
					{
						setglobalvar("enemy_"+getentityproperty(vEntity, "name")+iEntity+".colormap",getentityproperty(ent, "colourmap"));
					}else{
						cmap=getentityproperty(ent, "map");
						changeentityproperty(ent, "colourmap", getlocalvar("colormap")); 
						setglobalvar("enemy_"+getentityproperty(vEntity, "name")+iEntity+".colormap",getentityproperty(ent, "colourmap"));
						changeentityproperty(ent, "map",cmap);
					}
					//***********************************************************************
					break;
				}
			}
		}
	//}
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
		show_enemy_health();
	}
}
void gen_tail(char ani)
{
	void ent=getlocalvar("self");
	gen_tail_d(ent,ani,0,0,999,10,30,6,0);
}

void tail(int color,int lifespan,int alpha,int colourmap)
{
	setlocalvar("interval",20);
	setlocalvar("alpha",alpha);
	setlocalvar("lifespan",lifespan);
	setlocalvar("color",color);
	setlocalvar("colormap",colourmap);
	show_enemy_health2(1);
}
