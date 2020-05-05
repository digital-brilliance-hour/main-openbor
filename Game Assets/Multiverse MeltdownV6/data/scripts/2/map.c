void mapParNum()
{ // Change remap based Parent's Index
    void self = getlocalvar("self");
    void Parent = getentityproperty(self, "parent");
    int ParIndex = getentityproperty(Parent,"playerindex");

    if(ParIndex==0){
      changeentityproperty(self, "map", 0);
    } else if(ParIndex==1){
      changeentityproperty(self, "map", 1);
    } else if(ParIndex==2){
      changeentityproperty(self, "map", 2);
    }
}