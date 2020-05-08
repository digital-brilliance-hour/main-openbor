#include "data/scripts/levelup/lvup.c"
void set()
{
	void pindex	=	getentityproperty(getlocalvar("self"),"playerindex");
	void score	=	getplayerproperty(pindex,"score");
	int lv		=	getLevel(score);
	setAbi(pindex,getlocalvar("self"));
	settextobj(pindex,73+120*pindex, 259, 0, 1, "LVL"+lv);
}
