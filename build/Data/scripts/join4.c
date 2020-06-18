void main() {
	void p = getplayerproperty(3, "entity");
	changeentityproperty(p, "maxhealth", getglobalvar("maxhealth_4P"));
	changeentityproperty(p, "health", getglobalvar("maxhealth_4P"));
	changeentityproperty(p,"offense",openborconstant("ATK_NORMAL"),getglobalvar("offense_4P"));
	changeentityproperty(p,"defense",openborconstant("ATK_NORMAL"),getglobalvar("defense_4P"));

	if(getglobalvar("maxmp_4P") == NULL()){
		if(getentityproperty(p, "maxmp") < 1) {
			changeentityproperty(p, "maxmp",100);
			setglobalvar("maxmp_4P", 100);
		}
		else {
			setglobalvar("maxmp_4P", getentityproperty(p, "maxmp"));
		}
	}
	else {
		changeentityproperty(p, "maxmp",getglobalvar("maxmp_4P"));
	}

	changeentityproperty(p, "mp",0);
}
