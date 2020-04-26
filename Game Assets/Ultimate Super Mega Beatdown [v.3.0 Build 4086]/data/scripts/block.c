void main()
{
	void self = getlocalvar("self");
	/*int dir = getentityproperty(self,"direction");
	int Vx=-4;
	int x;
	if(dir==0){ 
		Vx = -Vx ;
	}
	x=getentityproperty(self,"x")+Vx;
	int z=getentityproperty(self,"z");
	int a=getentityproperty(self,"a");
	changeentityproperty(self,"position",x,z,a);*/
	changeentityproperty(self,"mp",getentityproperty(self,"mp") - 1);
	changeentityproperty(self,"animation",openborconstant("ANI_FREESPECIAL3"));
	
}




