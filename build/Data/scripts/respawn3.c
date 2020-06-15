void main() {
void p = getplayerproperty(2, "entity");
changeentityproperty(p, "maxmp",getglobalvar("maxmp_3P"));
changeentityproperty(p, "mp", 0);
changeentityproperty(p, "maxhealth", getglobalvar("maxhealth_3P"));
changeentityproperty(p, "health", getglobalvar("maxhealth_3P"));
}