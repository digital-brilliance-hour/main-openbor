void main()
{
	if (getglobalvar("selects"))
	{
		int iPlIndex = getlocalvar("player");
		int select_ind=getglobalvar("select_ind");
		if (select_ind==NULL()){select_ind=0;}
		if ((playerkeys(iPlIndex, 1, "movedown")) || (playerkeys(iPlIndex, 1, "moveup")))
		{
			setglobalvar("select_ind",!select_ind);
		}
		if (playerkeys(iPlIndex, 1, "attack")){
			if(select_ind)
			{
				jumptobranch(getglobalvar("branch1"),1);
			}else{
				jumptobranch(getglobalvar("branch2"),1);
			}
			setglobalvar("selectes",0);
		}
	}
}


