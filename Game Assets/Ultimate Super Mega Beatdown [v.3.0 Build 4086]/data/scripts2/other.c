void changeanibykeytoattackforself(void Ani, int Frame, void Key, int Hflag, int Limit)
{// Change current animation if proper key is pressed or released provided HP is more than limit
// V0.07
// Matman
    void self = getlocalvar("self");
    if ( checkent(self) == 1 ) {
      changeanibykeytoattack(self, Ani, Frame, Key, Hflag, Limit);
    }
}


void changeanibykeytoattackoffwallself(void Ani, void Key)
{// Change current animation if proper key is pressed and entity is by a wall
// V0.02
// Matman
    void self = getlocalvar("self");
    if ( checkent(self) == 1 ) {
       //Until openborvariant("hresolution") works will need to hard code the width
       //480x272
       if (  openborvariant("xpos")+20 > getentityproperty(self, "x")
         ||  openborvariant("xpos")+460-20 < getentityproperty(self, "x")
         || getentityproperty(self, "direction") == 0 &&  checkwall( getentityproperty(self, "x")+20, getentityproperty(self, "z") ) > getentityproperty(self, "a")
         || getentityproperty(self, "direction") == 1 &&  checkwall( getentityproperty(self, "x")-20, getentityproperty(self, "z") ) > getentityproperty(self, "a")
          )
       {
         changeanibykeytoattack(self, Ani, 0, Key, 0, 0);
       }
    }
}