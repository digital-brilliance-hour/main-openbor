void main() {
void p = getplayerproperty(0, "entity");
changeentityproperty(p, "maxmp",getglobalvar("maxmp_1P"));
changeentityproperty(p, "mp", 0);
changeentityproperty(p, "maxhealth", getglobalvar("maxhealth_1P"));
changeentityproperty(p, "health", getglobalvar("maxhealth_1P"));
}
