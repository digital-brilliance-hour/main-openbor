#import "data/scripts/levelup/lvup.c"
void main()
{
	int puntos =  getplayerproperty(3,"score");
	int resta = puntos - getglobalvar("punt_ant_4P");
	changeplayerproperty(3, "score", puntos+((openborvariant("count_players")-1)*resta));
	setglobalvar("punt_ant_4P", getplayerproperty(3,"score"));
	changeLv(3);
}
