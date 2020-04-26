void makein(float amount)
{// increase current speed amount.
// V0.02
    //This is the only real difference is that you force this method to call the entity that called this method with the getlocalvar("self");
    void self = getlocalvar("self");
    void cmp = getentityproperty(self,"invincitime");
    cmp = cmp + (amount);
    changeentityproperty(self, "invincitime", cmp);
}
