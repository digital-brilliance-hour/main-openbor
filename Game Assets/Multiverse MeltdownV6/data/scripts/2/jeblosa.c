void main()
{// onmovea script which sets health deduction if player falls to hole
    void self = getlocalvar("self");
    int y = getentityproperty(self,"a");
    int HP = getentityproperty(self,"health");
    int Vy = getentityproperty(self,"tossv");
    int PIndex = getentityproperty(self,"playerindex");

    if(Vy < 0 && y < -60){
      if(HP > 20){
        setglobalvar(PIndex+"HPs", HP-20);
      } else {
        setglobalvar(PIndex+"HPs", NULL());
      }
    }
}
