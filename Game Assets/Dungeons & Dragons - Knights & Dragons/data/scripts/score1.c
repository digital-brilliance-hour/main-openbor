#import "data/scripts/levelup/lvup.c"
void main()
{
	
int puntos =  getplayerproperty(0,"score");
int resta = puntos - getglobalvar("punt_ant_1P");
changeplayerproperty(0, "score", puntos+((openborvariant("count_players")-1)*resta));
setglobalvar("punt_ant_1P", getplayerproperty(0,"score"));
changeLv(0);

}
