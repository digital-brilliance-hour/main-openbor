void main()
{//Script for food with 20 health

    void target = getlocalvar("damagetaker"); // Get player who picks the food

    int  PIndex = getentityproperty(target,"playerindex"); // Get player's index
    int  MHealth = getentityproperty(target,"maxhealth"); // Get player's maximum health.
    int  Health = getentityproperty(target,"health"); // Get player's health.
    int  PScore = getplayerproperty(PIndex, "score"); // Get player's score

    if (Health >= MHealth){
      changeplayerproperty(PIndex, "score", PScore+2000); // Give score to player if his/her health is full
    } else {
      changeentityproperty(target, "health", Health+19); // Give health instead if health is not full
    }
}