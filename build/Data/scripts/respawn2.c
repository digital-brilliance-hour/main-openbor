void main() {
void p = getplayerproperty(1, "entity");
changeentityproperty(p, "maxmp",getglobalvar("maxmp_2P"));
changeentityproperty(p, "mp", 0);
changeentityproperty(p, "maxhealth", getglobalvar("maxhealth_2P"));
changeentityproperty(p, "health", getglobalvar("maxhealth_2P"));
}
