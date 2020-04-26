void entityincreasespeed(float amount)
{// increase current speed amount.
// V0.02
    //This is the only real difference is that you force this method to call the entity that called this method with the getlocalvar("self");
    void self = getlocalvar("self");
    void cmp = getentityproperty(self,"speed");
    cmp = cmp + (amount);
    changeentityproperty(self, "speed", cmp);
}

void entityincreaseaggression(float amount)
{// increase current speed amount.
// V0.02
    //This is the only real difference is that you force this method to call the entity that called this method with the getlocalvar("self");
    void self = getlocalvar("self");
    void cmp = getentityproperty(self,"aggression");
    cmp = cmp + (amount);
    changeentityproperty(self, "aggression", cmp);
}

void makefast()
{// increase current speed amount.
// V0.02
    //This is the only real difference is that you force this method to call the entity that called this method with the getlocalvar("self");
    void self = getlocalvar("self");
    changeentityproperty(self, "speed", 50);
}

void makeangry()
{// increase current speed amount.
// V0.02
    //This is the only real difference is that you force this method to call the entity that called this method with the getlocalvar("self");
    void self = getlocalvar("self");
    changeentityproperty(self, "aggression", 50);
    changeentityproperty(self, "speed", 35);
}

void matrix()
{
    void self = getlocalvar("self");
    changeentityproperty(self, "antigravity", 2);
}

void antimatrix()
{
    void self = getlocalvar("self");
    changeentityproperty(self, "antigravity", -1);
}

void anger()
{
   void self=getlocalvar("self");
   int oph=getentityproperty(self, "health");
   if (oph>60)
   {
      changeentityproperty(self, "aggression",50);
   }else{
      changeentityproperty(self, "aggression",0);
   }
}

