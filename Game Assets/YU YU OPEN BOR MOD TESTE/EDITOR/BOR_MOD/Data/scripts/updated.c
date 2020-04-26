



void main ()
{

	if(openborvariant("in_titlescreen")||openborvariant("in_menuscreen")||openborvariant("in_selectscreen"))
	{
		inTitleLoop(1);
	}
 
}















void inTitleLoop(int distitle)
{
	void clearCount,ptitle;
	

		if(distitle)
		{
			clearCount=getglobalvar("clearCount");
                        if(clearCount==NULL()){ // clearCount empty?
                          setglobalvar("clearCount", 0);
                          clearCount = 0;
                        } 

			if(clearCount<=10)
			{
			    drawstring(335,258,0,"Guima Brothers Creations");
			    drawstring(18,258,0,"ver 1.3 - Rafhot - 2014");
			    ptitle=clearCount;
		            drawstring(212,258,1,"Unlocked "+ptitle);
			} else
			{
			    drawstring(18,258,0,"All Secret Characters Unlocked!");				
			}

		}
}
