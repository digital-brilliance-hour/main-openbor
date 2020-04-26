void main()
{// Blink effect script
    void self = getlocalvar("self"); //Get calling entity.
    void Health = getentityproperty(self,"health");

    if (Health > 0){
	changeentityproperty(self, "colourmap", 1);
	changeentityproperty(self, "maptime", 20 + openborvariant("elapsed_time"));
    }
}