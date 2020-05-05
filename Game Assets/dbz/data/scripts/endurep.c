void main()
{// Endure script (to prevent entity from death)
// Except in freespecial animation
    void self = getlocalvar("self"); //Get calling entity.
    int HP = getentityproperty(self, "health");
    void vAniID = getentityproperty(self,"animationID"); //Get current animation ID
    int Damage = getlocalvar("damage"); //Get received damage

    if(HP <= Damage && HP <= 5 && vAniID != openborconstant("ANI_FREESPECIAL")){
      changeentityproperty(self, "health", 1);
    }
}