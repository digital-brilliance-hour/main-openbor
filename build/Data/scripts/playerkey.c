void main() 
{
	void ent = getlocalvar("self");
	int iPlIndex = getlocalvar("player"); //Get calling player
    void vSelf = getplayerproperty(iPlIndex , "entity"); //Get calling entity

    void iUp = playerkeys(iPlIndex, 1, "moveup"); // New key status of "Up"
    void iDown = playerkeys(iPlIndex, 1, "movedown"); // New key status of "Down"
    void iLeft = playerkeys(iPlIndex, 1, "moveleft"); // New key status of "Left"
    void iRight = playerkeys(iPlIndex, 1, "moveright"); // New key status of "Right"
    void iJump = playerkeys(iPlIndex, 1, "jump"); //New key status of "Jump"
    void iSpecial = playerkeys(iPlIndex, 1, "Special"); //New key status of "Special"
    void iAttack = playerkeys(iPlIndex, 1, "attack"); //New key status of "Attack"
    void iAttack2 = playerkeys(iPlIndex, 1, "attack2"); // New key status of "Attack 2"
    void iAttack3 = playerkeys(iPlIndex, 1, "attack3"); // New key status of "Attack 3"
    void iAttack4 = playerkeys(iPlIndex, 1, "attack4"); // New key status of "Attack 4"

    void iLeftR = playerkeys(iPlIndex, 2, "moveleft"); // Release status of "Left"
    void iRightR = playerkeys(iPlIndex, 2, "moveright"); // Release status of "Right"
    void iAttackR = playerkeys(iPlIndex, 2, "attack"); //Release status of "Attack"

    void iDownH = playerkeys(iPlIndex, 0, "movedown");
    void iUpH = playerkeys(iPlIndex, 0, "moveup");
    void iLeftH = playerkeys(iPlIndex, 0, "moveleft");
    void iRightH = playerkeys(iPlIndex, 0, "moveright");
	int maxmp = getentityproperty(ent, "maxmp");
	int mp = getentityproperty(ent, "mp");

	if(iSpecial) {
		if(mp < 1) {
			//spawnbind("zoomout", 0, 0, 0);
			//changeopenborvariant("slowmotion", 0);
			//setidle(ent);
		}
	}

	void AniID = getani();
	if(AniID == openborconstant("ANI_SPECIAL")
	||AniID == openborconstant("ANI_FREESPECIAL")
	||AniID == openborconstant("ANI_FREESPECIAL2")
	||AniID == openborconstant("ANI_FREESPECIAL3")
	||AniID == openborconstant("ANI_FREESPECIAL4")
	||AniID == openborconstant("ANI_FREESPECIAL5")
	||AniID == openborconstant("ANI_FREESPECIAL6")
	||AniID == openborconstant("ANI_FREESPECIAL7")
	||AniID == openborconstant("ANI_FREESPECIAL12")
	||AniID == openborconstant("ANI_FREESPECIAL10")
	){
		
	}
}

void getani()
{
	void ent = getlocalvar("self");
	return getentityproperty(ent,"animationID");
}