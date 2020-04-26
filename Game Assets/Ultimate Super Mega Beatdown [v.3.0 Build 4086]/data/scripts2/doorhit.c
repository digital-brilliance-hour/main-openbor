void main()
{
    // Door's Damage script
    void self = getlocalvar("self");

    //Get all walls
    void Door1 = getglobalvar("1"+self);
    void Door2 = getglobalvar("2"+self);
    void Door3 = getglobalvar("3"+self);
    void Door4 = getglobalvar("4"+self);

    // Open all doors!!
    damageentity(Door1, Door1, 1000, 1, openborconstant("ATK_NORMAL10"));
    damageentity(Door2, Door2, 1000, 1, openborconstant("ATK_NORMAL10"));
    damageentity(Door3, Door3, 1000, 1, openborconstant("ATK_NORMAL10"));
    damageentity(Door4, Door4, 1000, 1, openborconstant("ATK_NORMAL10"));


//    damageentity(self, self, 1000, 1, openborconstant("ATK_NORMAL10"));
    changeentityproperty(self, "health", 0);
}