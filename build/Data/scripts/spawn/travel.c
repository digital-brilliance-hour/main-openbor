
void center() {
	int i;
	float x, z, mx=0, mz=0, c=0;
	void p;
	for(i=0; i<4; i++){
		p = getplayerproperty(i, "entity");
		if(p){
			c++;
			x = getentityproperty(p, "x");
			z = getentityproperty(p, "z");
			mx+=x;
			mz+=z;

		}
	}
	if(c) {
		mx/=c;
		mz/=c;
	}
	mx-=480/2;
	mz-=272/2;
	if(mx<0) {
		mx=0;
	} else if(mx>openborvariant("levelwidth")-480){
		mx=openborvariant("levelwidth")-480;
	}
	if(mz<4) {
		mz=4;
	} else if(mz>openborvariant("levelheight")-272){
		mz=openborvariant("levelheight")-272;
	}
	changeopenborvariant("xpos", mx);
	changeopenborvariant("ypos", mz);
	log("map " + mx + ", " + mz + "\n");
}

void adj(){
	int i, x, z;
	void p;
	for(i=0; i<4; i++){
		p = getplayerproperty(i, "entity");
		if(p) {
			x = getglobalvar("x"+i);
			z = getglobalvar("z"+i);
			if(x && z) {
				changeentityproperty(p,"position", x, z);
			}
		}
	}

	center();
}
