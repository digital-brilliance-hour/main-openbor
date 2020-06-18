#include "data/scripts/levelup/lvup.c"
void main() 
{
 	int  iEntity;
 	void p;
    void vEntity;
    void self        = getlocalvar("self");
    int  iMax        = openborvariant("ent_max");
    int hp = getentityproperty(self, "maxhealth"); 
    int Def, score, total;
               
    for(iEntity=0; iEntity<4; iEntity++)
    {       
        p = getplayerproperty(iEntity, "entity");
        if(p){
	        if("Travel"!=getentityproperty(p, "model")) {	
				score = getplayerproperty(iEntity, "score");
                total = hp * 10; 
				changeplayerproperty(iEntity, "score", total+score);	
                changeLv(iEntity);
	        }
        }
	}	
}