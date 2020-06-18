void main() {
	void p = getplayerproperty(2, "entity");
	changeentityproperty(p, "maxhealth", getglobalvar("maxhealth_3P"));
	changeentityproperty(p, "health", getglobalvar("maxhealth_3P"));
	changeentityproperty(p,"offense",openborconstant("ATK_NORMAL"),getglobalvar("offense_3P"));
	changeentityproperty(p,"defense",openborconstant("ATK_NORMAL"),getglobalvar("defense_3P"));

	if(getglobalvar("maxmp_3P") == NULL()){
		if(getentityproperty(p, "maxmp") < 1) {
			changeentityproperty(p, "maxmp",100);
			setglobalvar("maxmp_3P", 100);
		}
		else {
			setglobalvar("maxmp_3P", getentityproperty(p, "maxmp"));
		}
	}
	else {
		changeentityproperty(p, "maxmp",getglobalvar("maxmp_3P"));
	}

	changeentityproperty(p, "mp",0);
}
