#include "data/scripts/afterimg.c"
void main()
{
   void AniID = getani();
   if(
   AniID == openborconstant("ANI_SPAWN")
   ||AniID == openborconstant("ANI_IDLE")
   ){
      afterimg();
   }
}


