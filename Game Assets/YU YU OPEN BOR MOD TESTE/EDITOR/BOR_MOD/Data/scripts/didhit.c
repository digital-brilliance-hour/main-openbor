void main()
{
    void t;
    void vself = getlocalvar("self");
    int r = getentityproperty(vself, "rush_count");

   if(r == 6)
   {
    setspawnentry("name", "sound");
    setspawnentry("coords", 87, 87, 0);
    t = spawn();
    }
   if(r == 11)
   {
    setspawnentry("name", "sound");
    setspawnentry("coords", 87, 87, 0);
    t = spawn();
    changeentityproperty(t, "animation", openborconstant("ANI_ATTACK1"));  

     }
   if(r == 18)
   {
    setspawnentry("name", "sound");
    setspawnentry("coords", 87, 87, 0);
    t = spawn();
    changeentityproperty(t, "animation", openborconstant("ANI_ATTACK2")); 
   }

   if(r == 26)
   {
    setspawnentry("name", "sound");
    setspawnentry("coords", 87, 87, 0);
    t = spawn();
    changeentityproperty(t, "animation", openborconstant("ANI_ATTACK3")); 

   }  
   if(r == 33)
   {
   setspawnentry("name", "sound");
    setspawnentry("coords", 87, 87, 0);
    t = spawn();
    changeentityproperty(t, "animation", openborconstant("ANI_JUMP")); 

   }
   if(r == 40)
   {
    setspawnentry("name", "sound");
    setspawnentry("coords", 87, 87, 0);
    t = spawn();
    changeentityproperty(t, "animation", openborconstant("ANI_SPECIAL")); 
   }



 if(r == 70)
   {
    setspawnentry("name", "sound");
    setspawnentry("coords", 87, 87, 0);
    t = spawn();
    changeentityproperty(t, "animation", openborconstant("ANI_FALL")); 
   }


   
      if(r == 99)
   {
    setspawnentry("name", "sound");
    setspawnentry("coords", 87, 87, 0);
    t = spawn();
    changeentityproperty(t, "animation", openborconstant("ANI_RUN")); 
   }


   
}




	