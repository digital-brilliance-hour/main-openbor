void Pall()
{//
   void self = getlocalvar("self"); 
   int  map = getentityproperty(self, "map");
   int  iR = rand()%5 + 5;

   if (iR >= 0 && iR < 2){ 
        changeentityproperty(self, "map", 1);
      } else if (iR >= 1 && iR < 3){ 
        changeentityproperty(self, "map", 2);
      } else if (iR >= 2 && iR < 4){ 
        changeentityproperty(self, "map", 3);
      } else if (iR >= 3 && iR < 5){ 
        changeentityproperty(self, "map", 4);
      } else if (iR >= 4 && iR < 6){ 
        changeentityproperty(self, "map", 5);
      } else if (iR >= 5 && iR < 7){ 
        changeentityproperty(self, "map", 6);
      } else if (iR >= 6 && iR < 8){ 
        changeentityproperty(self, "map", 7);
      } else if (iR >= 7 && iR < 9){ 
        changeentityproperty(self, "map", 8);
      } else if (iR >= 8 && iR < 10){ 
        changeentityproperty(self, "map", 9);
      } else { 
        changeentityproperty(self, "map", 10);
      }
}
