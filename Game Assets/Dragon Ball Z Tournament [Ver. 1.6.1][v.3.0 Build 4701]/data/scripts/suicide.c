void suicide()
{ // Suicide!!
    void self = getlocalvar("self");
    int health = getentityproperty(self,"health");

    if ( health > 0 ) damageentity(self,self,health,1,openborconstant("ATK_NORMAL")); //Suicide!
}