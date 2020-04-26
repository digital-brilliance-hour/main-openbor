void addHealth(int v)
{
	void target = getlocalvar("damagetaker"); // Get player who picks the food
	int  PIndex = getentityproperty(target,"playerindex"); // Get player's index
	int  MHealth = getentityproperty(target,"maxhealth"); // Get player's maximum health.
	int  Health = getentityproperty(target,"health"); // Get player's health.
	int  PScore = getplayerproperty(PIndex, "score"); // Get player's score
	int  lostHealth=(MHealth - Health);
	int  addScore;
	if (v>lostHealth){addScore=(v-lostHealth)*30;}else{addScore=0;}
	if (MHealth==Health){addScore*=2;}
	changeplayerproperty(PIndex, "score", PScore+addScore); // Give score to player if his/her health is full
	changeentityproperty(target, "health",Health+v); // Give health instead if health is not full
}