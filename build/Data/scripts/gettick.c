//Story System for OpenBOR
//Original by Volcanic; Modifications by CRxTRDude

//gettick.c
//function for time ticker. Used for this game only.
#define	GLOBAL_LASTTICK 0
long get_tick()
{
	long ret;
	long now=openborvariant("elapsed_time");
	long lasttime=getscriptvar(GLOBAL_LASTTICK);
	if (lasttime==NULL()){lasttime=0;}
	ret=now - lasttime;
	if (ret<0){
		ret=1;
	}
	return ret;
}
