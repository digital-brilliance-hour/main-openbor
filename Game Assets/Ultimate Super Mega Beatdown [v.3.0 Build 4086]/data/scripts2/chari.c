void chunli()
{
    void self = getlocalvar("self");
    void animation = getentityproperty(self,"animation");

      int r = rand()%30;

      if( r > -30 && r < -11 ){
        performattack(self, openborconstant("ANI_FREESPECIAL1"));
      }
     else if( r > -10 && r < 19 ){
        performattack(self, openborconstant("ANI_FREESPECIAL2"));
      }
      else if( r > 20 && r < 30 ){
        performattack(self, openborconstant("ANI_FREESPECIAL3"));
      }
}


void bison()
{
    void self = getlocalvar("self");
    void animation = getentityproperty(self,"animation");

      int r = rand()%30;

      if( r > -30 && r < -11 ){
        performattack(self, openborconstant("ANI_FREESPECIAL1"));
      }
     else if( r > -10 && r < 19 ){
        performattack(self, openborconstant("ANI_FREESPECIAL2"));
      }
      else if( r > 20 && r < 30 ){
        performattack(self, openborconstant("ANI_FREESPECIAL3"));
      }
}

void ryu()
{
    void self = getlocalvar("self");
    void animation = getentityproperty(self,"animation");

      int  iR = rand()%2 + 2;

      if (iR >= 0 && iR < 2){ 
        performattack(self, openborconstant("ANI_FREESPECIAL1"));
      } else if (iR >= 1 && iR < 3){ 
        performattack(self, openborconstant("ANI_FREESPECIAL2"));
      } else if (iR >= 2 && iR < 4){ 
        performattack(self, openborconstant("ANI_FREESPECIAL8"));
      } else if (iR >= 3 && iR < 5){ 
        performattack(self, openborconstant("ANI_FREESPECIAL5"));
      }
}
