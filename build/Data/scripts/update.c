void main()
{// Update script for locking certain player
    if(openborvariant("in_selectscreen")==1){
      int models_cached = openborvariant("models_cached");
      void set = openborvariant("current_set");
      int i = 0;
      int C = getglobalvar("Load");
      int D = getglobalvar("Load2");

      for( i = 0; i < models_cached; ++i ) {
        char model = getmodelproperty(i,2);

        if( model == "Royce" && C != 39 && set == 1) {
            changemodelproperty(i,4,0);
        }
      }
    } else if(openborvariant("in_menuscreen")==1){
      setindexedvar(0, NULL());
    }
    if (openborvariant("in_titlescreen")) {
      int T = getglobalvar("TitleMusic");
      if(T != 1) {
        void bg = "data/music/title.bor";
        playmusic(bg, 1);
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