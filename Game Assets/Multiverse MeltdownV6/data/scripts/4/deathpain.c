void main()
{// Deals damage to spawner on death
    void self = getlocalvar("self"); //Get calling entity.
    void Par = getentityvar(self,1);

    if(Par){
      damageentity(Par, self, 100, 0, openborconstant("ATK_NORMAL"));     
    }
}