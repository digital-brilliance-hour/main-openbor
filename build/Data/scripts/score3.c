#import "data/scripts/levelup/lvup.c"
void main()
{
	int puntos =  getplayerproperty(2,"score");
	int resta = puntos - getglobalvar("punt_ant_3P");
	changeplayerproperty(2, "score", puntos+((openborvariant("count_players")-1)*resta));
	setglobalvar("punt_ant_3P", getplayerproperty(2,"score"));
	changeLv(2);
}
