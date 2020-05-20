void main() {
void p = getplayerproperty(1, "entity");
changeentityproperty(p, "maxmp",getglobalvar("maxmp_2P"));
changeentityproperty(p, "mp", 0);
}
