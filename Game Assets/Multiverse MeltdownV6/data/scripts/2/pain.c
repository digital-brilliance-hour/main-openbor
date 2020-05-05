void main()
{// Takes own damage to give it to spawner
    void self = getlocalvar("self"); //Get calling entity.
    int Damage = getlocalvar("damage"); //Get received damage
    void Par = getentityvar(self,1);

    if(Par){
      damageentity(Par, self, Damage, 0, openborconstant("ATK_NORMAL"));     
    }
}