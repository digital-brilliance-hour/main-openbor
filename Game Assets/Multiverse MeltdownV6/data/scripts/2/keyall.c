void main()
{
    int iPlIndex = getlocalvar("player"); //Get Player's index
    void vSelf = getlocalvar("self"); //Get player
    void vAniID = getentityproperty(vSelf,"animationID"); //Get current animation ID
    void vAniPos = getentityproperty(vSelf, "animpos"); //Get current animation frame

    void iUp = playerkeys(iPlIndex, 1, "moveup"); // New key status of "Up"
    void iDown = playerkeys(iPlIndex, 1, "movedown"); // New key status of "Down"
    void iLeft = playerkeys(iPlIndex, 1, "moveleft"); // New key status of "Left"
    void iRight = playerkeys(iPlIndex, 1, "moveright"); // New key status of "Right"
    void iAttack = playerkeys(iPlIndex, 1, "attack");// New key status of "Attack"
    void iAttack2 = playerkeys(iPlIndex, 1, "attack2");// New key status of "Attack2"
    void iAttack3 = playerkeys(iPlIndex, 1, "attack3");// New key status of "Attack3"
    void iAttack4 = playerkeys(iPlIndex, 1, "attack4");// New key status of "Attack4"
    void iSpecial = playerkeys(iPlIndex, 1, "special");// New key status of "Special"
    void iJump = playerkeys(iPlIndex, 1, "jump");// New key status of "Jump"
    void iStart = playerkeys(iPlIndex, 1, "start");// New key status of "Start"

    void iUpR = playerkeys(iPlIndex, 2, "moveup"); // Release status of "Up"
    void iDownR = playerkeys(iPlIndex, 2, "movedown"); // Release status of "Down"
    void iLeftR = playerkeys(iPlIndex, 2, "moveleft"); // Release status of "Left"
    void iRightR = playerkeys(iPlIndex, 2, "moveright"); // Release status of "Right"
    void iAttackR = playerkeys(iPlIndex, 2, "attack");// Release status of "Attack"
    void iAttack2R = playerkeys(iPlIndex, 2, "attack2");// Release status of "Attack2"
    void iAttack3R = playerkeys(iPlIndex, 2, "attack3");// Release status of "Attack3"
    void iAttack4R = playerkeys(iPlIndex, 2, "attack4");// Release status of "Attack4"
    void iJumpR = playerkeys(iPlIndex, 2, "jump");// Release status of "Jump"
    void iStartR = playerkeys(iPlIndex, 2, "start");// Release status of "Start"

    void iUpH = playerkeys(iPlIndex, 0, "moveup"); // Held key status of "Up"
    void iDownH = playerkeys(iPlIndex, 0, "movedown"); // Held key status of "Down"
    void iLeftH = playerkeys(iPlIndex, 0, "moveleft"); // Held key status of "Left"
    void iRightH = playerkeys(iPlIndex, 0, "moveright"); // Held key status of "Right"

// Movement event capture
    if(iLeft){ //Left is pressed?
      setglobalvar(iPlIndex+"X", -1);
    } else if(iRight){ //Right is pressed?
      setglobalvar(iPlIndex+"X", 1);
    }
    if(iUp){ //Up is pressed?
      setglobalvar(iPlIndex+"Y", 1);
    } else if(iDown){ //Down is pressed?
      setglobalvar(iPlIndex+"Y", -1);
    }

    if(iLeftR || iRightR){ //Left or Right is released?
      setglobalvar(iPlIndex+"X", 0);
    }
    if(iUpR || iDownR){ //Up or Down is released?
      setglobalvar(iPlIndex+"Y", 0);
    }

// Action event capture
    if(iAttack){ //Attack is pressed?
      setglobalvar(iPlIndex+"A", 1);
    }
    if(iAttackR){ //Attack is released?
      setglobalvar(iPlIndex+"A", NULL());
    }

    if(iAttack2){ //Attack2 is pressed?
      setglobalvar(iPlIndex+"A2", 1);
    }
    if(iAttack2R){ //Attack2 is released?
      setglobalvar(iPlIndex+"A2", NULL());
    }

    if(iAttack3){ //Attack3 is pressed?
      setglobalvar(iPlIndex+"A3", 1);
    }
    if(iAttack3R){ //Attack3 is released?
      setglobalvar(iPlIndex+"A3", NULL());
    }

    if(iAttack4){ //Attack4 is pressed?
      setglobalvar(iPlIndex+"A4", 1);
    }
    if(iAttack4R){ //Attack4 is released?
      setglobalvar(iPlIndex+"A4", NULL());
    }

    if(iJump){ //Jump is pressed?
      setglobalvar(iPlIndex+"J", 1);
    }
    if(iJumpR){ //Jump is released?
      setglobalvar(iPlIndex+"J", NULL());
    }

    if(iStart){ //Start is pressed?
      setglobalvar(iPlIndex+"St", 1);
    }
    if(iStartR){ //Start is released?
      setglobalvar(iPlIndex+"St", NULL());
    }
}