void main()
{
   setglobalvar("zoomentity", NULL());

    void p;
 int i, hp, mp, lv, num;
 for(i=0; i<4; i++){
 p = getplayerproperty(i, "entity");
 num = i + 1;
 if(p){
 if("Travel"!=getentityproperty(p, "model")) {
 if(getglobalvar("maxmp_"+num+"P") == NULL()){
 changeentityproperty(p, "maxmp",100);
setglobalvar("maxmp_"+num+"P", 100);
 }
 else {
 	mp = getentityproperty(p, "maxmp");
 	changeentityproperty(p, "maxmp",getglobalvar("maxmp_"+num+"P"));
 }
 
 changeentityproperty(p, "mp",0);
 }
 }
 }	
}
