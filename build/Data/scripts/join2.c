void main() {
	void p = getplayerproperty(1, "entity");
	changeentityproperty(p, "maxhealth", getglobalvar("maxhealth_2P"));
	changeentityproperty(p, "health", getglobalvar("maxhealth_2P"));
	changeentityproperty(p,"offense",openborconstant("ATK_NORMAL"),getglobalvar("offense_2P"));
	changeentityproperty(p,"defense",openborconstant("ATK_NORMAL"),getglobalvar("defense_2P"));

	if(getglobalvar("maxmp_2P") == NULL()){
		if(getentityproperty(p, "maxmp") < 1) {
			changeentityproperty(p, "maxmp",100);
			setglobalvar("maxmp_2P", 100);
		}
		else {
			setglobalvar("maxmp_2P", getentityproperty(p, "maxmp"));
		}
	}
	else {
		changeentityproperty(p, "maxmp",getglobalvar("maxmp_2P"));
	}

	changeentityproperty(p, "mp",0);
}
