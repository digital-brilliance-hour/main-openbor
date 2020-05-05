void main()
{// Update script for locking certain player
//    drawstring(220,130,3, getindexedvar(0));
//    drawstring(220,150,3, getindexedvar(1));

    if(openborvariant("in_selectscreen")==1){
      int models_cached = openborvariant("models_cached");
      int i = 0;
      int C = getglobalvar("Load");
      int D = getglobalvar("Load2");
      int E = getglobalvar("Load3");
      int F = getglobalvar("Load4");
      int G = getglobalvar("Load5");
      int H = getglobalvar("Load6");
      int I = getglobalvar("Load7");
      int J = getglobalvar("Load8");
      int K = getglobalvar("Load9");

      for( i = 0; i < models_cached; ++i ) {
        char model = getmodelproperty(i,2);

        if( model == "RASH" && C != 1 ) {
            changemodelproperty(i,4,0);
        } else if( model == "ZITZ" && D != 2 ) {
            changemodelproperty(i,4,0);
        } else if( model == "PIMPLE" && E != 3 ) {
            changemodelproperty(i,4,0);
        } else if( model == "T-BONE" && F != 4 ) {
            changemodelproperty(i,4,0);
        } else if( model == "RAZOR" && G != 5 ) {
            changemodelproperty(i,4,0);
        } else if( model == "LEONARDO" && H != 6 ) {
            changemodelproperty(i,4,0);
        } else if( model == "RAPHAEL" && I != 7 ) {
            changemodelproperty(i,4,0);
        } else if( model == "DONATELLO" && J != 8 ) {
            changemodelproperty(i,4,0);
        } else if( model == "MICHELANGELO" && K != 9 ) {
            changemodelproperty(i,4,0);
        }
      }
    } else if(openborvariant("in_menuscreen")==1){
      setindexedvar(0, NULL());
    }
}

void oncreate()
{
    int C = fileskim("Rise", "Test.txt");
    int D = fileskim("Rise2", "Test.txt");
    setglobalvar("Load", C);
    setglobalvar("Load2", D);
    int E = fileskim("Rise3", "Test.txt");
    setglobalvar("Load3", E);
    int F = fileskim("Rise4", "Test.txt");
    setglobalvar("Load4", F);
    int G = fileskim("Rise5", "Test.txt");
    setglobalvar("Load5", G);
    int H = fileskim("Rise6", "Test.txt");
    setglobalvar("Load6", H);
    int I = fileskim("Rise7", "Test.txt");
    setglobalvar("Load7", I);
    int J = fileskim("Rise8", "Test.txt");
    setglobalvar("Load8", J);
    int K = fileskim("Rise9", "Test.txt");
    setglobalvar("Load9", K);

    setindexedvar(1, 0);
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
