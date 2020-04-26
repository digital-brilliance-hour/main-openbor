void riseattack(int Rx, int Rz, void Ani)
{// Riseattack with range check
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disx < 0){
        Disx = -Disx;
      }
      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx <= Rx && Disz <= Rz ) // Target within range?
      {
        #if(Tx < x){
        #  changeentityproperty(self, "direction", 0);
        #} else {
        #  changeentityproperty(self, "direction", 1);
        #}
        changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation

	changeentityproperty(self, "aiflag", Ani, 0);
	changeentityproperty(self, "takeaction", "common_attack_proc");



      } 
    }
}