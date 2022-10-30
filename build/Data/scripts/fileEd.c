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
      filestreamappend(file, 77, 0);
      filestreamappend(file, "Jise", 0);
      filestreamappend(file, 39, 0);
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
// 1: Unlocks Paladin
    void file = openfilestream(Path, 1);
    char Code;
    int Value;

    if(Flag == 1){
      Code = "Rise";
      Value = 39;
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