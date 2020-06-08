void main() {
	void p = getplayerproperty(2, "entity");

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
