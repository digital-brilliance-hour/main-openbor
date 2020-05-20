void main() {
void p = getplayerproperty(2, "entity");
changeentityproperty(p, "maxmp",getglobalvar("maxmp_3P"));
changeentityproperty(p, "mp", 0);
}