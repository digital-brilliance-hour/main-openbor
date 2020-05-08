void m_ks(char name, int b)
{//Script to remove entity
    void self = getlocalvar("self"); //Get calling entity
    void Status ;
	if(!self) {return ; }
	else if(name!="") { Status = getglobalvar(name); }
	else { Status = getglobalvar(getentityproperty(self,"name")); }

	if((!b && !Status) || (b && Status)) {
      killentity(self);
	  setlocalvar("self", NULL());
    }
}

void ks(char name) {
	m_ks(name, 1);
}


void ksI(char name) {
	m_ks(name, 0);
}

