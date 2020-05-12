void main()
{// Update script for locking certain player
 void p;
 int i, max, mp;
 for(i=0; i<4; i++){
 p = getplayerproperty(i, "entity");
 if(p){
 max = getentityproperty(p, "maxmp");
 mp = getentityproperty(p, "mp");
 if(mp < max) {
 changeentityproperty(p, "mp", mp-1);
 }
 }
 }
}