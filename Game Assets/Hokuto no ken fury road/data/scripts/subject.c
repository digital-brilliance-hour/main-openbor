void subobs(int obs)
{// Set's subject to obstacle
    void self = getlocalvar("self");
    changeentityproperty(self, "subject_to_obstacle", obs);
}

void layer(int layer)
{// Set's enemy's layer
    void self = getlocalvar("self");
    changeentityproperty(self, "setlayer", layer);
}

void subscreen(int screen)
{// Set's subject to screen
    void self = getlocalvar("self");
    changeentityproperty(self, "subject_to_screen", screen);
}

void subhole(int hole)
{// Set's subject to hole
    void self = getlocalvar("self");
    changeentityproperty(self, "subject_to_hole", hole);
}

void subwall(int wall)
{// Set's subject to wall
    void self = getlocalvar("self");
    changeentityproperty(self, "subject_to_wall", wall);
}

void subplat(int plat)
{// Set's subject to platform
    void self = getlocalvar("self");
    changeentityproperty(self, "subject_to_platform", plat);
}