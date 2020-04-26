void main()
{// Endure script (to prevent entity from death)
    void self = getlocalvar("self"); //Get calling entity.
    int HP = getentityproperty(self, "health");
    int Damage = getlocalvar("damage"); //Get received damage

    if(HP <= Damage && HP <= 5){
      changeentityproperty(self, "health", 1);
    }
}