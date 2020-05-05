#import "data/scripts/library/spawn.h"
#import "data/scripts/library/basic.h"

void offscreenkill( float dx, int E )
{// Check position relative to screen. If enemy is offscreen, suicide!
//  dx : Distance to screen edge
//  E  : Edge selection, 0 = left, 1 = right

    void self = getlocalvar("self");
    int x = getentityproperty(self,"x"); //Get character's x coordinate
    int XPos = openborvariant("xpos"); //Get screen edge's position

    if( (x > XPos + 320 + dx) && (E == 1) ){ // Offscreen to the right?
      killentity(self); //Suicide!
    } else if( (x < XPos - dx) && (E == 0) ){ // Offscreen to the left?
      killentity(self); //Suicide!
    }
}

void spawnN(void Name, float dx, float dy, float dz, int Dir, char Summon)
{ // Spawn entity based on left screen edge with direction setting
   void self = getlocalvar("self");
   void Child = getglobalvar("S"+Summon);
   void Spawn;

   if(Child==NULL()){
     Spawn = spawn02(Name, dx, dy, dz);
     changeentityproperty(Spawn, "direction", Dir);
     setglobalvar("S"+Summon, "X");
   }
}


void main()
{// Update script for locking certain player
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
      int L = getglobalvar("Load10");
      int M = getglobalvar("Load11");
      int N = getglobalvar("Load12");
      int O = getglobalvar("Load13");
      int P = getglobalvar("Load14");
      int Q = getglobalvar("Load15");
      int R = getglobalvar("Load16");
      int S = getglobalvar("Load17");
      int T = getglobalvar("Load18");
      int U = getglobalvar("Load19");
      int V = getglobalvar("Load20");

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
        } else if( model == "EPSILON_EAGLE" && L != 10 ) {
            changemodelproperty(i,4,0);
        } else if( model == "TOEJAM" && M != 11 ) {
            changemodelproperty(i,4,0);
        } else if( model == "EARL" && N != 12 ) {
            changemodelproperty(i,4,0);
        } else if( model == "EARTHWORM_JIM" && O != 13 ) {
            changemodelproperty(i,4,0);
        } else if( model == "PARAPPA" && P != 14 ) {
            changemodelproperty(i,4,0);
        } else if( model == "CRASH" && Q != 15 ) {
            changemodelproperty(i,4,0);
        } else if( model == "JAZZ" && R != 16 ) {
            changemodelproperty(i,4,0);
        } else if( model == "SPAZ" && S != 17 ) {
            changemodelproperty(i,4,0);
        } else if( model == "LORI" && T != 18 ) {
            changemodelproperty(i,4,0);
        } else if( model == "KLONOA" && U != 19 ) {
            changemodelproperty(i,4,0);
        } else if( model == "empty" && V != 20 ) {
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
    int E = fileskim("Rise3", "Test.txt");
    setglobalvar("Load", C);
    setglobalvar("Load2", D);
    setglobalvar("Load3", E);

    int F = fileskim("Rise4", "Test.txt");
    int G = fileskim("Rise5", "Test.txt");
    int H = fileskim("Rise6", "Test.txt");
    setglobalvar("Load6", H);
    setglobalvar("Load4", F);
    setglobalvar("Load5", G);

    int I = fileskim("Rise7", "Test.txt");
    int J = fileskim("Rise8", "Test.txt");
    int K = fileskim("Rise9", "Test.txt");
    setglobalvar("Load7", I);
    setglobalvar("Load8", J);
    setglobalvar("Load9", K);

    int L = fileskim("Rise10", "Test.txt");
    int M = fileskim("Rise11", "Test.txt");
    int N = fileskim("Rise12", "Test.txt");
    setglobalvar("Load10", L);
    setglobalvar("Load11", M);
    setglobalvar("Load12", N);

    int O = fileskim("Rise13", "Test.txt");
    int P = fileskim("Rise14", "Test.txt");
    int Q = fileskim("Rise15", "Test.txt");
    setglobalvar("Load13", O);
    setglobalvar("Load14", P);
    setglobalvar("Load15", Q);

    int R = fileskim("Rise16", "Test.txt");
    int S = fileskim("Rise17", "Test.txt");
    int T = fileskim("Rise18", "Test.txt");
    setglobalvar("Load16", R);
    setglobalvar("Load17", S);
    setglobalvar("Load18", T);

    int U = fileskim("Rise19", "Test.txt");
    int V = fileskim("Rise20", "Test.txt");
    setglobalvar("Load19", U);
    setglobalvar("Load20", V);

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