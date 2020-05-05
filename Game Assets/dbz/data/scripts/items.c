void main()
{
  int iSnd = loadsample("data/sounds/gem.wav");
  
  playsample(iSnd, 0, openborvariant("effectvol"), openborvariant("effectvol"), 120, 0); //itemup sfx
}