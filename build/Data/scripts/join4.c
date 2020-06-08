void main() {
	void p = getplayerproperty(3, "entity");

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
