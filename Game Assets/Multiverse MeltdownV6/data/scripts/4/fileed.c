void fileread(void Path)
{// Read values from file defined with Path then store each value in each entity variable
      void self = getlocalvar("self");
      void file = openfilestream(Path, 1);
      void vLoad;
      int i = 0;

      if( file != -1 ){
        setfilestreamposition(file, 0);
        vLoad = getfilestreamargument(file, 0, "string");

        while(vLoad != "#End"){
          setentityvar(self, i, vLoad);
          i = i + 1;
          filestreamnextline(file);
          vLoad = getfilestreamargument(file, 0, "string");
        }

        if(vLoad == "#End"){
          setentityvar(self, i, vLoad);
          closefilestream(file);
        }
        return 1;
      } else {
        return -1;
      }
}

void fileedit(void Path, char Name, void Value)
{// Read values from entity variables, find the one matching with Name then change the value in next line
      void self = getlocalvar("self");
      int Check = fileread(Path);
      int i;
      void vLoad;

      if(Check==1){
        i = 0;
        vLoad = getentityvar(self, i);

        while(vLoad != Name && vLoad != "#End" && vLoad != NULL()){
          i = i + 1;
          vLoad = getentityvar(self, i);
        }

        if(vLoad == Name){
          i = i + 1;
          vLoad = getentityvar(self, i);
          setentityvar(self, i, Value);
        }
      }
}

void filewrite(void Path)
{// Read values from entity variables then write them to a file by name Path
// Must use fileread function first
      void self = getlocalvar("self");
      int i = 0;
      void vLoad = getentityvar(self, i);

      if(vLoad){
        void file = createfilestream();
        filestreamappend(file, vLoad, 1);

        while(vLoad != "#End" && vLoad != NULL()){
          i = i + 1;
          vLoad = getentityvar(self, i);
          filestreamappend(file, vLoad, 0);
        }

        savefilestream(file, Path);
        closefilestream(file);
      }
}

void writedefault(void Path)
{// Writes file by name Path with default values
// Used when there's no file to start with
      void file = createfilestream();
      filestreamappend(file, 11, 1);
      filestreamappend(file, 22, 0);
      filestreamappend(file, 33, 0);
      filestreamappend(file, 44, 0);
      filestreamappend(file, "Lock", 0);
      filestreamappend(file, 8, 0);
      filestreamappend(file, 55, 0);
      filestreamappend(file, "Rise", 0);
      filestreamappend(file, 127, 0);
      filestreamappend(file, "Rise2", 0);
      filestreamappend(file, 85, 0);
      filestreamappend(file, "Rise3", 0);
      filestreamappend(file, 77, 0);
      filestreamappend(file, "Rise4", 0);
      filestreamappend(file, 557, 0);
      filestreamappend(file, "Rise5", 0);
      filestreamappend(file, 1207, 0);
      filestreamappend(file, "Rise6", 0);
      filestreamappend(file, 537, 0);
      filestreamappend(file, "Rise7", 0);
      filestreamappend(file, 227, 0);
      filestreamappend(file, "Rise8", 0);
      filestreamappend(file, 7254, 0);
      filestreamappend(file, "Rise9", 0);
      filestreamappend(file, 1347, 0);
      filestreamappend(file, "Rise10", 0);
      filestreamappend(file, 1823, 0);
      filestreamappend(file, "Rise11", 0);
      filestreamappend(file, 1636, 0);
      filestreamappend(file, "Rise12", 0);
      filestreamappend(file, 375, 0);
      filestreamappend(file, "Rise13", 0);
      filestreamappend(file, 156, 0);
      filestreamappend(file, "Rise14", 0);
      filestreamappend(file, 1302, 0);
      filestreamappend(file, "Rise15", 0);
      filestreamappend(file, 736, 0);
      filestreamappend(file, "Rise16", 0);
      filestreamappend(file, 865, 0);
      filestreamappend(file, "Rise17", 0);
      filestreamappend(file, 398, 0);
      filestreamappend(file, "Rise18", 0);
      filestreamappend(file, 274, 0);
      filestreamappend(file, "Rise19", 0);
      filestreamappend(file, 1153, 0);
      filestreamappend(file, "Rise20", 0);
      filestreamappend(file, 908, 0);
      filestreamappend(file, "#End", 0);

      savefilestream(file, Path);
      closefilestream(file);
}

int load_unlocked_model(char modelname)
{
    int models_cached = openborvariant("models_cached");
    int i = 0;

    for ( i = 0; i < models_cached; ++i ) {
        char model = getmodelproperty(i,2);

        if ( model == modelname ) {
	    if (getmodelproperty(i,4)!=1) {
	      loadmodel(modelname);
	      changemodelproperty(i,4,1);
	    }
            return;
        }
    }
}

void Unlock(int Flag, void Path)
{ // Unlocks certain character based on flag and write the status on file named Path
// 1: Unlocks RASH
// 2: Unlocks ZITZ
// 3: Unlocks PIMPLE
// 4: Unlocks T-BONE
// 5: Unlocks RAZOR
// 6: Unlocks LEONARDO
// 7: Unlocks RAPHAEL
// 8: Unlocks DONATELLO
// 9: Unlocks MICHELANGELO
// 10: Unlocks EPSILON_EAGLE
// 11: Unlocks TOEJAM
// 12: Unlocks EARL
// 13: Unlocks EARTHWORM_JIM
// 14: Unlocks PARAPPA
// 15: Unlocks CRASH
// 16: Unlocks JAZZ
// 17: Unlocks SPAZ
// 18: Unlocks LORI
// 19: Unlocks KLONOA
// 20: Unlocks empty
    void file = openfilestream(Path, 1);
    char Code;
    int Value;


    if(Flag == 1){
      Code = "Rise";
      Value = 1;
    } else if(Flag == 2){
      Code = "Rise2";
      Value = 2;
    } else if(Flag == 3){
      Code = "Rise3";
      Value = 3;
    } else if(Flag == 4){
      Code = "Rise4";
      Value = 4;
    } else if(Flag == 5){
      Code = "Rise5";
      Value = 5;
    } else if(Flag == 6){
      Code = "Rise6";
      Value = 6;
    } else if(Flag == 7){
      Code = "Rise7";
      Value = 7;
    } else if(Flag == 8){
      Code = "Rise8";
      Value = 8;
    } else if(Flag == 9){
      Code = "Rise9";
      Value = 9;
    } else if(Flag == 10){
      Code = "Rise10";
      Value = 10;
    } else if(Flag == 11){
      Code = "Rise11";
      Value = 11;
    } else if(Flag == 12){
      Code = "Rise12";
      Value = 12;
    } else if(Flag == 13){
      Code = "Rise13";
      Value = 13;
    } else if(Flag == 14){
      Code = "Rise14";
      Value = 14;
    } else if(Flag == 15){
      Code = "Rise15";
      Value = 15;
    } else if(Flag == 16){
      Code = "Rise16";
      Value = 16;
    } else if(Flag == 17){
      Code = "Rise17";
      Value = 17;
    } else if(Flag == 18){
      Code = "Rise18";
      Value = 18;
    } else if(Flag == 19){
      Code = "Rise19";
      Value = 19;
    } else if(Flag == 20){
      Code = "Rise20";
      Value = 20;
    }

    if(file == -1){
      writedefault(Path);
    }

    fileedit(Path, Code, Value);
    filewrite(Path);
}

void suicide()
{ // Suicide!!
    void self = getlocalvar("self");

    killentity(self); //Suicide!
}
