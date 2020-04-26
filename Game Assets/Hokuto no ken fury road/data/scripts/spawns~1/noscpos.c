// Removes scroll pos effect
void main()
{
    void self = getlocalvar("self"); //Get calling entity.
    int x = getentityproperty(self,"x"); //Get character's x coordinate
    int XPos = openborvariant("xpos");

    changeentityproperty(self, "position", x - XPos);
}
