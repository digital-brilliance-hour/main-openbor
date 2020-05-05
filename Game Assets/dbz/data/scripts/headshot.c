void main()
{// Headshot script (to increase damage if head were shot)
    void self = getlocalvar("self"); //Get calling entity.
    void cross = getlocalvar("attacker");
    int HP = getentityproperty(self, "health");
    int x = getentityproperty(self, "x");
    int Tx = getentityproperty(cross, "x");
    int Ty = getentityproperty(cross, "a");
    void CAni = getentityproperty(self, "animationID");
    int CAniPos = getentityproperty(self, "animpos");
    void PName = getentityproperty(self, "defaultname");
    int Damage = getlocalvar("damage"); //Get received damage
    int H = 220;
//    int SFX = loadsample("data/sounds/shotgun.wav");

    if(PName=="fps"){
      if(CAni == openborconstant("ANI_ATTACK2")){
        if(CAniPos >= 3 && CAniPos < 6){
          H = 160;
        } else if(CAniPos >= 6 && CAniPos < 9){
          H = 135;
        } else if(CAniPos >= 9 && CAniPos < 12){
          H = 160;
        }
      } else if(CAni == openborconstant("ANI_FREESPECIAL")){
        if(CAniPos >= 21 && CAniPos < 24){
          H = 160;
        } else if(CAniPos >= 24 && CAniPos < 27){
          H = 135;
        } else if(CAniPos >= 27 && CAniPos < 30){
          H = 160;
        }
      }
    } else if(PName=="fps2"){
      if(CAni == openborconstant("ANI_FREESPECIAL3")){
        if(CAniPos >= 3 && CAniPos < 6){
          H = 160;
        } else if(CAniPos == 6){
          H = 135;
        } else if(CAniPos >= 7 && CAniPos < 10){
          H = 160;
        }
      }
    } else if(PName=="ship" || PName=="shipS"){
      H = 200;
    }

    setentityvar(cross, 1, 5);

    if(Ty >= H && Tx >= x - 20 && Tx <= x + 20){
//      playsample(SFX, 0, 120, 120, 100, 0);
      setentityvar(cross, 1, 12);
      changeentityproperty(self, "health", HP-Damage);
    }
}