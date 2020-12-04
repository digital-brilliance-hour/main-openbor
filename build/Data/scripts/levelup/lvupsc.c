#include "data/scripts/levelup/lvup.c"
void changeLv(void pindex)
{
	lvup(pindex);
	void lv	=	getglobalvar("level."+pindex);
	if(lv==NULL())lv=1;
	settextobj(pindex,73+120*pindex,259,0,1,"LVL"+lv);
}
