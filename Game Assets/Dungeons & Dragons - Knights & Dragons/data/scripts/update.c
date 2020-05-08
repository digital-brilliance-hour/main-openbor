// in update.c

//Calcula la puntuación con la cual se sube de nivel al nivel "lvl"
int getScoreLevel(int lvl){
	if (lvl%2 == 1){
		return lvl * (lvl/2) * 1000;
	}else{
		return (lvl - 1) * (lvl/2) * 1000;
	}
}

void main()
{   	

	if(getglobalvar("punt_ant_1P") == NULL()){
		setglobalvar("punt_ant_1P", 0);
	}
	if(getglobalvar("punt_ant_2P") == NULL()){
		setglobalvar("punt_ant_2P", 0);
	}
	if(getglobalvar("punt_ant_3P") == NULL()){
		setglobalvar("punt_ant_3P", 0);
	}
	if(getglobalvar("punt_ant_4P") == NULL()){
		setglobalvar("punt_ant_4P", 0);
	}
    void p;
	int i, hp, mp, lv;

	for(i=0; i<4; i++){
		p = getplayerproperty(i, "entity");
		if(p){
			if("Travel"!=getentityproperty(p, "model")) {
				//HP text script
				hp = getentityproperty(p, "health"); if(hp<0) hp=0;
				drawstring(24+120*i, 231, 0, hp+"/"+getentityproperty(p, "maxhealth"));
				//MP text script
				mp = getentityproperty(p, "mp"); if(mp<0) mp=0;
				drawstring(24+120*i, 246, 0, mp+"/"+getentityproperty(p, "maxmp"));
				//Lv
				lv = getglobalvar("level."+i);
				if(!lv) lv=1;
				drawstring(73+120*i, 259, 0, "LVL"+lv);
				//Muestra la barra de nivel
				if(getplayerproperty(i, "score")<=190000)
					drawbox(6+120*i, 258, (getplayerproperty(i, "score")-getScoreLevel(getglobalvar("level."+i)))*62/(getScoreLevel(getglobalvar("level."+i)+1)-getScoreLevel(getglobalvar("level."+i))), 10, 9999, rgbcolor(0,255,255), 0);
				//Muestra las vidas para que muestre la vida 0
				drawstring(96+120*i, 217, 0, getplayerproperty(i, "lives") - 1);
			}
		}
	}
      

}
