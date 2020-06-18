void main() {
	void p = getplayerproperty(0, "entity");

	changeentityproperty(p, "maxhealth", getglobalvar("maxhealth_1P"));
	changeentityproperty(p, "health", getglobalvar("maxhealth_1P"));
	changeentityproperty(p,"offense",openborconstant("ATK_NORMAL"),getglobalvar("offense_1P"));
	changeentityproperty(p,"defense",openborconstant("ATK_NORMAL"),getglobalvar("defense_1P"));

	if(getglobalvar("maxmp_1P") == NULL()){
		if(getentityproperty(p, "maxmp") < 1) {
			changeentityproperty(p, "maxmp",100);
			setglobalvar("maxmp_1P", 100);
		}
		else {
			setglobalvar("maxmp_1P", getentityproperty(p, "maxmp"));
		}
	}
	else {
		changeentityproperty(p, "maxmp",getglobalvar("maxmp_1P"));
	}

	changeentityproperty(p, "mp",0);
}
