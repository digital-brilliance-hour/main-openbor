void main()
{
    void self = getlocalvar("self");
    int Dir = getentityproperty(self, "direction");
    int x = getentityproperty(self, "x");
    int y = getentityproperty(self, "a");
    int z = getentityproperty(self, "z");
    int Vx = getentityproperty(self, "xdir");
    void Anim = getentityproperty(self, "animationID");
    int C;
    int D;

    if(Dir == 1){
      C = -55;
      D = 0;
    } else {
      C = 55;
      D = 1;
    }

    if(y <= checkwall(x+C,z) && (Anim == openborconstant("ANI_FALL") || Anim == openborconstant("ANI_FALL3") || Anim == openborconstant("ANI_FALL4") || Anim == openborconstant("ANI_FALL12"))){
      changeentityproperty(self, "velocity", -Vx-1);
      changeentityproperty(self, "direction", D);
    }
}