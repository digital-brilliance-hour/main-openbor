void do_npc_special(void self)
{
   int x = getentityproperty(self, "x");
   int z = getentityproperty(self, "z");
   int a = getentityproperty(self, "a");
   int xx = (x - 8);
   int zz = (z - 1);
   int direction = getentityproperty(self, "direction");
    int i;
    void ent;
    for(i=0; i<openborvariant("ent_max"); i++)
    {
      ent = getentity(i);
      if(getentityproperty(ent, "exists") && getentityproperty(ent, "parent") == self){
	 performattack(ent, openborconstant("ANI_FREESPECIAL") );
	 changeentityproperty(ent, "position", xx, zz, 0);
	 changeentityproperty(ent, "direction", direction);
      }
    }
}

void do_npc_special2(void self)
{
   int x = getentityproperty(self, "x");
   int z = getentityproperty(self, "z");
   int a = getentityproperty(self, "a");
   int xx = (x - 8);
   int zz = (z - 1);
   int direction = getentityproperty(self, "direction");
    int i;
    void ent;
    for(i=0; i<openborvariant("ent_max"); i++)
    {
      ent = getentity(i);
      if(getentityproperty(ent, "exists") && getentityproperty(ent, "parent") == self){
	 performattack(ent, openborconstant("ANI_FREESPECIAL2") );
	 changeentityproperty(ent, "position", xx, zz, a);
	 changeentityproperty(ent, "direction", direction);
      }
    }
}

void do_npc_special3(void self)
{
   int x = getentityproperty(self, "x");
   int z = getentityproperty(self, "z");
   int a = getentityproperty(self, "a");
   int zz = (z - 1);
   int direction = getentityproperty(self, "direction");
    int i;
    void ent;
    for(i=0; i<openborvariant("ent_max"); i++)
    {
      ent = getentity(i);
      if(getentityproperty(ent, "exists") && getentityproperty(ent, "parent") == self){
	 performattack(ent, openborconstant("ANI_FREESPECIAL3") );
	 changeentityproperty(ent, "position", x, zz, a);
	 changeentityproperty(ent, "direction", direction);
      }
    }
}

void do_npc_hyper(void self)
{
   int x = getentityproperty(self, "x");
   int z = getentityproperty(self, "z");
   int a = getentityproperty(self, "a");
   int direction = getentityproperty(self, "direction");
    int i;
    void ent;
    for(i=0; i<openborvariant("ent_max"); i++)
    {
      ent = getentity(i);
      if(getentityproperty(ent, "exists") && getentityproperty(ent, "parent") == self){
	 performattack(ent, openborconstant("ANI_FREESPECIAL7") );
	 changeentityproperty(ent, "position", x, z, a);
	 changeentityproperty(ent, "direction", direction);
      }
    }
}

void do_npc_back(void self)
{
   int x = getentityproperty(self, "x");
   int z = getentityproperty(self, "z");
   int a = getentityproperty(self, "a");
   int direction = getentityproperty(self, "direction");
   int ba = ("direction" * -1);
    int i;
    void ent;
    for(i=0; i<openborvariant("ent_max"); i++)
    {
      ent = getentity(i);
      if(getentityproperty(ent, "exists") && getentityproperty(ent, "parent") == self){
	 performattack(ent, openborconstant("ANI_FREESPECIAL") );
	 changeentityproperty(ent, "position", x, z, a);
	 changeentityproperty(ent, "direction", ba);
      }
    }
}

void do_npc_combo(void self)
{
   int x = getentityproperty(self, "x");
   int z = getentityproperty(self, "z");
   int a = getentityproperty(self, "a");
   int fa = (x + 130);
   int direction = getentityproperty(self, "direction");
    int i;
    void ent;
    for(i=0; i<openborvariant("ent_max"); i++)
    {
      ent = getentity(i);
      if(getentityproperty(ent, "exists") && getentityproperty(ent, "parent") == self){
	 changeentityproperty(ent, "position", fa, z, a);
	 changeentityproperty(ent, "direction", direction);
	 performattack(ent, openborconstant("ANI_FREESPECIAL8") );

      }
    }
}

void do_npc_tspecial(void self)
{
   int x = getentityproperty(self, "x");
   int z = getentityproperty(self, "z");
   int a = getentityproperty(self, "a");
   int zz = (x - 8);
   int direction = getentityproperty(self, "direction");
    int i;
    void ent;
    for(i=0; i<openborvariant("ent_max"); i++)
    {
      ent = getentity(i);
      if(getentityproperty(ent, "exists") && getentityproperty(ent, "parent") == self){
	 performattack(ent, openborconstant("ANI_SPECIAL") );
	 changeentityproperty(ent, "position", zz, z, 0);
	 changeentityproperty(ent, "direction", direction);
      }
    }
}
