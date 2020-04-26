void selectBranch(char msg,char branch1,char branch2,char branch1_msg,char branch2_msg)
{
	int num=openborvariant("count_enemies");
	if (num<=1){
		setglobalvar("select_ind",1);
		setglobalvar("branch1",branch1);
		setglobalvar("branch2",branch2);
		setglobalvar("branch1_msg",branch1_msg);
		setglobalvar("branch2_msg",branch2_msg);
		setglobalvar("selects",1);
		setglobalvar("select_msg",msg);
		changeentityproperty(getlocalvar("self"),"animation",openborconstant("ANI_IDLE"));
	}
}


