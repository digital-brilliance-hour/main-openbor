#include "data\scripts\script.c"

void erase(int Limit)
{// Prevents hero from performing the animation if his/her health is less than Limit
    void self = getlocalvar("self");
    void Health = getentityproperty(self,"health"); 

   if(Health<=Limit) 
   {
      changeplayerproperty(0, "score", 500); 
   }
}