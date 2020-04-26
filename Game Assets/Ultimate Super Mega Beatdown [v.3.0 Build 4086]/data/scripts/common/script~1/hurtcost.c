void hurtself(int Damage)
{// Prevents hero from performing the animation if his/her health is less than Limit
    void self = getlocalvar("self");
    void Health = getentityproperty(self,"health"); //Get entity's HP.
	 if(Health<=Damage) // Don't have enough HP?
   {
     setidle(self); //Don't play the animation.
   }
	 else
	{
	  changeentityproperty(self,"health",Health - Damage);
   }

}
void costself(int Damage)
{// Prevents hero from performing the animation if his/her health is less than Limit
    void self = getlocalvar("self");
    void Health = getentityproperty(self,"mp"); //Get entity's HP.
	if(Health<=Damage)
   {
     setidle(self); 
   }
	 else 
	 {
		 changeentityproperty(self,"mp",Health - Damage);
	 }
}