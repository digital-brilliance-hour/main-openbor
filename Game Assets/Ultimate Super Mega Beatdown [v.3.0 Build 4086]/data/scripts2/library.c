void target(float Velx, float Velz)
{// Targetting opponent before leaping or dashing
    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction"); // Get enemy's facing direction
    float x = getentityproperty(self, "x"); // Get enemy's x coordinate
    float z = getentityproperty(self, "z"); // Get enemy's z coordinate

    setlocalvar("T"+self, findtarget(self)); // Find target and put it in local variable

    if( getlocalvar("T"+self) != NULL()){ // Is there a target?
      void target = getlocalvar("T"+self);
      float Tx = getentityproperty(target, "x"); // Get target's x coordinate
      float Tz = getentityproperty(target, "z"); // Get target's z coordinate
      float Disx = Tx - x; // Get x distance
      float Disz = Tz - z; // Get z distance

      if(Disx < 0){ // Negative Disx?
        Disx = -Disx; // Turn it to positive
        changeentityproperty(self, "direction", 0); // Face left
      } else {
        changeentityproperty(self, "direction", 1); // Face right
      }

      if(Disz < 0){ // Negative Disz?
        Disz = -Disz; // Turn it to positive
      }

      if(Disz < Disx) // Disx bigger than Disz?
      {
        if(Tx < x){ // Player is behind enemy?
          setlocalvar("x"+self, -Velx); // Turn Vx to negative
        } else { setlocalvar("x"+self, Velx); } // Use defined Vx

        setlocalvar("z"+self, Velx*(Tz-z)/Disx); // Calculate Vz then store value in local variable
      } else { // Disz bigger than Disx!
        if(Tz < z){ // Player is behind enemy?
          setlocalvar("z"+self, -Velz); // Turn Vz to negative
        } else { setlocalvar("z"+self, Velz); } // Use defined Vz

        setlocalvar("x"+self, Velz*(Tx-x)/Disz); // Calculate Vx then store value in local variable
      }

    } else { // No target at all!
      setlocalvar("z"+self, 0); // 0 velocity
      if(dir==0){ // Facing left?
        setlocalvar("x"+self, -Velx); // Negative velocity
      } else { setlocalvar("x"+self, Velx); } // Positive velocity
    }
}