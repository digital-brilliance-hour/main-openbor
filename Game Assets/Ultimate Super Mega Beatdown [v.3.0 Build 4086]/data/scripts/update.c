#include "data/scripts/traileru.c"
void main()
{
	afterImg();
	story();
	displayOk();
	disSelect();
}
void displayOk()
{
	void ticker=getglobalvar("ticker");
	void dis=getglobalvar("dis");
	long currentTime=openborvariant("elapsed_time");
	if (ticker==NULL()){ticker=0;}
	if (dis==NULL()){dis=0;}
	if ((currentTime - ticker)>80 || ( ticker -currentTime)>80){
		if (dis==0 || dis==NULL()){
			dis=1;
		}else{
			dis=0;
		}
		ticker=currentTime;
		setglobalvar("ticker",ticker);
		setglobalvar("dis",dis);
	}

	if (dis){
		showOk(0,2);
		showOk(1,82);
		showOk(2,162);
		showOk(3,242);
	}	
}
void showOk(int ind,float x)
{
	void ent= getplayerproperty(ind, "ent");
	if (ent){
		void mp=getentityproperty(ent,"mp");
		void mph=getentityproperty(ent,"maxmp");
		if (mph==mp){
			drawstring(x,20,1,"OK");
		}
	}
}
void story()
{
	void name,pro;
	char msgn;
	char msg =getglobalvar("msg2");
	if (msg!="" && msg!=NULL()){
		
		name=getglobalvar("msgName");
		pro=getglobalvar("msgPro");
		drawstring(70, 180, 2, name);
		drawstring(90, 194, 2, msg);
		msgn =getglobalvar("msg22");

		drawbox(10,170,300,60,440,27,1);
		if (msgn=="" && msgn==NULL()){}
		else{
			drawstring(90, 208, 2, msgn);
		}

		void spr=getglobalvar(pro);
		if (spr==NULL()){
			spr=loadsprite("data/story/pro/"+pro+".gif");
			setglobalvar(pro,spr);
		}else{
		}
		
		drawsprite(spr, 20, 180, 441, 0);
		//free(spr);
	}
}
void disSelect()
{
	if (getglobalvar("selects"))
	{
		drawbox(10,70,300,100,440,27,1);
		drawstring(20, 80, 1, getglobalvar("select_msg"));
		if (getglobalvar("select_ind"))
		{
			drawbox(20,105,280,20,440,29,0);
		}else{
			drawbox(20,125,280,20,440,29,0);
		}
		drawstring(20,110,2,getglobalvar("branch1_msg"));
		drawstring(20,130,2,getglobalvar("branch2_msg"));
	}
}