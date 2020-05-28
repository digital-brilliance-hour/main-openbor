#include "data/scripts/afterimg.c"
void main()
{
   void AniID = getani();
   if(
   AniID == openborconstant("ANI_SPECIAL")
   ||AniID == openborconstant("ANI_FREESPECIAL")
   ||AniID == openborconstant("ANI_FREESPECIAL2")
   ||AniID == openborconstant("ANI_FREESPECIAL3")
   ||AniID == openborconstant("ANI_FREESPECIAL4")
   ){
      afterimg();
   }
}