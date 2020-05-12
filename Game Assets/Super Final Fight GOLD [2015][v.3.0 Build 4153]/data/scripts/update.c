// in update.c
void main()
{   	
//
    void p;
	int i, hp, mp, lv;

	for(i=0; i<4; i++){
		p = getplayerproperty(i, "entity");
		if(p){
			if("Travel"!=getentityproperty(p, "model")) {
				//HP text script
				hp = getentityproperty(p, "health"); if(hp<0) hp=0;
				drawstring(999999+160*i, 999999, 0, hp+"/"+getentityproperty(p, "maxhealth"));
				//MP text script
				mp = getentityproperty(p, "mp"); if(mp<0) mp=0;
				drawstring(999999+160*i, 999999, 0, mp+"/"+getentityproperty(p, "maxmp"));
				//Lv
				lv = getglobalvar("level."+i);
				if(!lv) lv=1;
				drawstring(22+160*i, 34, 0, "LVL"+lv);
			}
		}
	}
      

}
