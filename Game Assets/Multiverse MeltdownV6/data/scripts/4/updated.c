void main(){
    int Shown = getindexedvar(0);

    if(Shown == NULL() && openborvariant("current_scene") == "data/scenes/intro.txt"){
      int Play = getindexedvar(1);
      setindexedvar(0, 1);

      if(Play == 1){
        setindexedvar(1, Play+1);
	playgif("data/scenes/hud.gif", 0, 0, 0);
      } else if(Play == 2){
        setindexedvar(1, Play+1);
	playgif("data/scenes/05.gif", 0, 0, 0);
      } else if(Play == 3){
        setindexedvar(1, 0);
	playgif("data/scenes/15.gif", 0, 0, 0);
      } else {
        setindexedvar(1, Play+1);
      }
    }
}