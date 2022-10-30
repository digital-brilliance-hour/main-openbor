void playSound(void file)
{
	if(!file||file==""){return;}else{}
	void sfx=loadsample(file,1);
	void vol=openborvariant("effectvol");
	playsample(sfx, 0, vol,vol, 100, 0);
}
