#include "data/scripts/script.c"

void main()
{ // Suicide!!
    void self = getlocalvar("self");
    spawn01("noner", 0, 0, 0);
    damageentity(self, self, 10000, 1, openborconstant("ATK_NORMAL"));
}