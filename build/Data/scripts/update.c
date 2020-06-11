#include "data/scripts/traileru.c"

#define   MODEL_NAME 2
#define   SELECTABLE 4
#define   MAXENTCOUNT openborvariant("models_cached")
#define obv openborvariant
void setValid(void name,void isselectable)
{
   int i;
   for(i=0;i<MAXENTCOUNT;i++)
   {
      if(getmodelproperty(i,MODEL_NAME)==name)
      {
         log(getmodelproperty(i,MODEL_NAME));
         changemodelproperty(i,SELECTABLE,isselectable);
         return;
      }
   }
}

int getScoreLevel(int lvl){
 if (lvl%2 == 1){
 return lvl * (lvl/2) * 1000;
 }else{
 return (lvl - 1) * (lvl/2) * 1000;
 }
}

void main()
{
    void scene=openborvariant("current_scene");
      setValid("Broly",0);
    if(scene == "data/scenes/ending.txt")
    {
      setValid("Broly",1);
    }
    // Update script for locking certain player
    if(openborvariant("in_selectscreen")==1){
      //setValid("Broly",1);

      int S = getglobalvar("SelectMusic");
      if(S != 1) {
        void bg = "data/music/select.ogg";
        playmusic(bg, 1);
        setglobalvar("SelectMusic", 1);
      }
    } else if(openborvariant("in_menuscreen")==1){
      setindexedvar(0, NULL());
        setglobalvar("SelectMusic", 0);
    }
    else {

        setglobalvar("SelectMusic", 0);
    }
    if (openborvariant("in_titlescreen")) {
      loadgamefile();
      log(getsaveinfo(0, "name"));
      //log(getsaveinfo(1, "health"));
      log(getsaveinfo(0, "times_completed"));
      int T = getglobalvar("TitleMusic");
      if(T != 1) {
        void bg = "data/music/menu.ogg";
        playmusic(bg, 1, 1400919);
        setglobalvar("TitleMusic", 1);
      }
    }
    else {
        setglobalvar("TitleMusic", 0);
    }
    if (openborvariant("in_halloffamescreen")) {
      int H = getglobalvar("HOFMusic");
      if(H != 1) {
        void hbg = "data/music/hiscore.bor";
        playmusic(hbg, 1);
        setglobalvar("HOFMusic", 1);
      }
    }
    else {
        setglobalvar("HOFMusic", 0);
    }

    if(getglobalvar("punt_ant_1P") == NULL()){
     setglobalvar("punt_ant_1P", 0);
    }
     if(getglobalvar("punt_ant_2P") == NULL()){
     setglobalvar("punt_ant_2P", 0);
    }
     if(getglobalvar("punt_ant_3P") == NULL()){
     setglobalvar("punt_ant_3P", 0);
    }
     if(getglobalvar("punt_ant_4P") == NULL()){
     setglobalvar("punt_ant_4P", 0);
    }
    if (openborvariant("in_level")) {
       void p;
       int i, hp, mp, lv;
       for(i=0; i<4; i++){
       p = getplayerproperty(i, "entity");
       if(p){
         if("Travel"!=getentityproperty(p, "model")) {
           //HP text script
           hp = getentityproperty(p, "health"); if(hp<0) hp=0;
           //drawstring(24+120*i, 231, 0, hp+"/"+getentityproperty(p, "maxhealth"));
           //MP text script
           mp = getentityproperty(p, "mp"); if(mp<0) mp=0;
           //drawstring(24+120*i, 246, 0, mp+"/"+getentityproperty(p, "maxmp"));
           //Lv
           lv = getglobalvar("level."+i);
           if(!lv) lv=1;
           drawstring(6+120*i, 250, 3, "Power LVL:"+lv);
           //Muestra la barra de nivel
           //if(getplayerproperty(i, "score")<=190000)
           //drawbox(6+120*i, 258, 50, 10, 9999, rgbcolor(0,255,255), 0);
           //Muestra las vidas para que muestre la vida 0
           //drawstring(96+120*i, 217, 0, getplayerproperty(i, "lives") - 1);
         }
       }
      }
      show_enemy_health();
    }
  afterImg();
}

void player_used(char playername)
{
       void p;
       int i, hp, mp, lv;
       for(i=0; i<4; i++){
         p = getplayerproperty(i, "name");
         if(p){
            if(p == playername) {
              return 1;
            }
         }
       }
}

void oncreate()
{
    int C = fileskim("Rise", "Test.txt");
    setglobalvar("Load", C);

    setindexedvar(1, 0);
}

void ondestroy(){
}

void fileskim(char Line, void Path)
{
      void file = openfilestream(Path , 1);
      void vLoad;

      if(file != -1){
        setfilestreamposition(file, 0);
        vLoad = getfilestreamargument(file, 0, "string");

        while(vLoad != Line && vLoad != "#End"){
          filestreamnextline(file);
          vLoad = getfilestreamargument(file, 0, "string");          
        }
        if( vLoad == Line ){
          filestreamnextline(file);
          vLoad = getfilestreamargument(file, 0, "int");
          return vLoad;

          closefilestream(file);
        } else if(vLoad == "#End"){
          closefilestream(file);
          return 0;
        }
      } else {
        return 0;
      }
}