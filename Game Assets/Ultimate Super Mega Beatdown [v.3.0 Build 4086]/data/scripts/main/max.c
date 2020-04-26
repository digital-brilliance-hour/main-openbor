
#include "data/scripts/afterimg.c"

void main()
{

	//************************************
	//gen_tail_d(self固定,动画,map(老版本为0),起始帧,终止帧,生成间隔(毫秒),影子存活周期(毫秒),Alpha的方法(0-6),填充方法(0为实体残影,>0为纯色残影,代表颜色号)
	/*gen_tail_d(getlocalvar("self"),"ANI_WALK",0,0,3,50,100,6,1);
	gen_*/tail_d(getlocalvar("self"),"ANI_WALK",0,4,9,50,100,6,0);

	
}


