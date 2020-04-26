void main (void self)
{
   void self = getlocalvar("self");
   void animation = getentityproperty(self, "animation");

   if animation = openborconstant("ANI_IDLE");
    {
	 performattack(ent, openborconstant("ANI_FREESPECIAL3") );
      }
}

