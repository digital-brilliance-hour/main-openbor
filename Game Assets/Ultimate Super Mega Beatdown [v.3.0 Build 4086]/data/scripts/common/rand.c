void randBranch(int p,char ani1,char ani2)
{
	void self = getlocalvar("self");
	int r = rand()%500+500;
	if (r <=p*10){
		enterAtt(ani1); 
	}else{
		if (ani2!=""){enterAtt(ani2);}
	}
}