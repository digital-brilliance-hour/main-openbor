void selectBranch(char ba ,char bb)
{
	int num=openborvariant("count_enemies");
	if (num<=1){
		setglobalvar("selectBranch",1);
		setglobalvar("selected",0);
		setglobalvar("BranchA",ba);
		setglobalvar("BranchB",bb);
		setglobalvar("inSelect",0);
		void self=getlocalvar("self");
		damageentity(self,self,100,1,openborconstant("ATK_NORMAL"));
	}
}
