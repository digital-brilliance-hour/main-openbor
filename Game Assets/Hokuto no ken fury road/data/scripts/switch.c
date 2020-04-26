void subobs(int obs)
{// Set's subject to obstacle
    void self = getlocalvar("self");
    changeentityproperty(self, "subject_to_obstacle", obs);
}




void main()
{// Switches personal state
    void self = getlocalvar("self"); //Get calling entity.
    void State = getentityvar(self,1);

    if(State == 3){
      setentityvar(self, 1, NULL());
    } else {
      setentityvar(self, 1, 3);
    }
}