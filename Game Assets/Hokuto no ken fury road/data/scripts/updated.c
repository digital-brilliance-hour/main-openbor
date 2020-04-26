void main(){
    void counter= getlocalvar("counter");  // Set a variable to trigger the spawn on and off
if(openborvariant("in_menuscreen")) // Check if the game is in menu screen
  {    counter = setlocalvar("counter",0); }
if((openborvariant("in_titlescreen")) &&(counter!=1)) // Check the variable to avoid double spawn
		{	void subent;
			loadmodel("bgfx"); // name of the entity to be loaded
                      clearspawnentry(); // clean the spawn entry
			setspawnentry("name", "bgfx"); // define the entity to be spawn
			setspawnentry("coords", 0,0,0); // set the position of the entity
			subent=spawn();  //  spawn the entity
			changeentityproperty(subent, "position", 0,0,0); //for safe, set again the position
	counter = setlocalvar("counter",1); // turn on the variable, blocking a new spawn to be made
}

if(openborvariant("in_menuscreen")) // Check if the game is in menu screen
  {    counter = setlocalvar("counter",2); }
if((openborvariant("in_selectscreen")) &&(counter!=3)) // Check the variable to avoid double spawn
		{	void subent;
			loadmodel("bgfx1"); // name of the entity to be loaded
                      clearspawnentry(); // clean the spawn entry
			setspawnentry("name", "bgfx1"); // define the entity to be spawn
			setspawnentry("coords", 0,0,0); // set the position of the entity
			subent=spawn();  //  spawn the entity
			changeentityproperty(subent, "position", 0,0,0); //for safe, set again the position
	counter = setlocalvar("counter",3); // turn on the variable, blocking a new spawn to be made
}


}


