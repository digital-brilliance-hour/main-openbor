void main()
{
	void	s;
	void	value	=	getlocalvar("value");
	void	max		=	getlocalvar("max");
	if(max==1){
		return;
	}else{}

	void percent=value*99/max;
	percent%=++percent;

	void dot=percent%3;
	if(dot==0)
		s=".";
	else if(dot==1)
		s="..";
	else
		s="...";

	drawstring(176,210,0,"Loading "+percent);
	drawstring(241,210,0,"% Complete"+s);
	drawbox(177,228,126,10,11,rgbcolor(200,0,0),0);
	drawbox(177,228,percent*126*0.01,10,15,rgbcolor(200,200,0),0);
}
