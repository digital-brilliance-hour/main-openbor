void randSound(char s1,char s2,char s3)
{
   int r = rand()%300;
   char sound;
   if (r<=-100)
   {
      sound=s1;
   }else if(r<=100){
      sound=s2;
   }else{
      sound=s3;
   }
   playSound("data/sounds/"+sound);
}
void randSound2(char s1,char s2,char s3,char s4,char s5,char s6)
{
   int      r      =   rand()%300+300;
   char   sound   =   "";

   if (r<100){
      sound=s1;
   }else if(r<200){
      sound=s2;
   }else if(r<300){
      sound=s3;
   }else if(r<400){
      sound=s4;
   }else if(r<500){
      sound=s5;
   }else if(r<600){
      sound=s6;
   }
   playSound("data/sounds/"+sound);
}
void playSound(void file)
{
   if(!file||file==""){return;}else{}
   int sfx=loadsample(file);
   playsample(sfx, 0, openborvariant("effectvol"), openborvariant("effectvol"), 100, 0);
}
