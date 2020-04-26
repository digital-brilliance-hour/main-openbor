#include "data/scripts/afterimg.c"
void main()
{
   void AniID = getani();
   if(
   AniID == openborconstant("ANI_FREESPECIAL")
   ||AniID == openborconstant("ANI_FREESPECIAL2")
   ||AniID == openborconstant("ANI_FREESPECIAL3")
   ||AniID == openborconstant("ANI_FREESPECIAL12")
   ||AniID == openborconstant("ANI_RUNATTACK")
   ||AniID == openborconstant("ANI_ATTACK4")
   ||AniID == openborconstant("ANI_JUMPATTACK")
   ||AniID == openborconstant("ANI_RUNJUMPATTACK")
   ){
      afterimg();
   }
}


