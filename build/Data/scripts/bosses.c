void main() {
	void self = getlocalvar("self"); //Get calling entity.
	int hp = getentityproperty(self,"health");
	int max = getentityproperty(self,"maxhealth");
	int aggression = getentityproperty(self,"aggression");
	int offense = getentityproperty(self,"offense");
	float ratio = getentityproperty(self, "health")*100/getentityproperty(self,"maxhealth");
	if(ratio <= 25) {
		changeentityproperty(self,"offense",openborconstant("ATK_NORMAL"),offense+0.2);
		changeentityproperty(self,"aggression", aggression+2);
	}
}