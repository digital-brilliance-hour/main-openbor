void main()
{
   int damage = getlocalvar("damage");
   void self = getlocalvar("self");
   int x, z, a, t;
   void f;
   if(damage)
   {
      x = getentityproperty(self, "x");
      z = getentityproperty(self, "z")+1;
      a = getentityproperty(self, "a")+40;
      setspawnentry("name", "numflash");
      while(damage)
      {
         t = damage % 10;
         f = spawn();
         changeentityproperty(f, "position", x,z,a);
         updateframe(f, t);
         damage/=10;
         x -= 8;
      }
      f = spawn();
      changeentityproperty(f, "position", x,z,a);
      updateframe(f, 10);
   }
}
