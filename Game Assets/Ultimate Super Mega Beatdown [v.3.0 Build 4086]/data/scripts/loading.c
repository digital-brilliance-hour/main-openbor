void main()
{
	void	s;
	void	value	=	getlocalvar("value");
	void	max		=	getlocalvar("max");
	if(max==1){
		return;
	}else{}

	void percent=value*100/max;
	percent%=++percent;
	void dot=percent%3;
	if(dot==0)
		s=".";
	else if(dot==1)
		s="..";
	else
		s="...";

	drawstring(160,90,3,"LOADING MODELS");
	drawstring(165,123,3,percent+"% COMPLETE"+s);
	drawbox(0,260,480,3,11,rgbcolor(0,122,133),0);
	drawbox(0,260,percent*480*0.01,3,15,rgbcolor(0,233,233),0);
}