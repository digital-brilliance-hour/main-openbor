#define gpp getplayerproperty
#define cpp changeplayerproperty
#define gep getentityproperty
#define cep changeentityproperty
#define ov  openborvariant
#define cv  changeopenborvariant
#define oc  openborconstant
#define glv getlocalvar
#define slv setlocalvar
#define sev setentityvar
#define gev getentityvar
#define sgv setglobalvar
#define ggv getglobalvar
#define glvp getlevelproperty
#define clvp changelevelproperty
#define glp getlayerproperty
#define clp changelayerproperty
#define si setidle
#define pa performattack
#include "data/scripts/levelup/lvup.c"

void main() 
{
	int value = 0;
	void self = getlocalvar("self");
	void player = getlocalvar("damagetaker");
	char name = getentityproperty(self, "name");
	int splitter = searchstr_index(name, "_");
	int namel = strlength(name);
	char type = substr(name, 0, splitter);
	char strvalue = substr(name, splitter+1, namel-splitter-1);
	switch(strvalue) {
		case "twentyfive":
			value = 25;
			break;
		case "fifty":
			value = 50;
			break;
		case "seventyfive":
			value = 75;
			break;
		case "hundred":
			value = 100;
			break;
		case "twohundred":
			value = 200;
			break;
	}

	switch(type) {
		case "xp":
			xp_item(player, value);
			break;
		case "hp":
			hp_item(player, value);
			break;
		case "mp":
			mp_item(player, value);
			break;
		case "offense":
			break;
		case "defense":
			break;
	}
}

void xp_item(void player, int val) 
{
	int iPlIndex = getentityproperty(player, "playerindex");
	int PScore = getplayerproperty(iPlIndex, "score");
	int total = val * 10;
	//log(total);
    changeplayerproperty(iPlIndex, "score", PScore+total);
    changeLv(iPlIndex);


}

void hp_item(void player, int val) 
{
	int maxhp = getentityproperty(player, "maxhealth");
	int hp = getentityproperty(player, "health");
	int health = val * maxhp / 100;
	int total = health + hp;
	changeentityproperty(player,"health",total);
	
}

void mp_item(void player, int val) 
{
	int maxmp = getentityproperty(player, "maxmp");
	int mmp = getentityproperty(player, "mp");
	int mp = val * maxmp / 100;
	//log(val);
	int total = mp + mmp;
	changeentityproperty(player,"mp",total);
	
}

void offense_item(int val) 
{
	
}

void defense_item(int val) 
{
	
}

int searchstr_index(char txt, char pat, int reverse_flag) {
    char tmp = "";

        tmp = strinfirst(txt,pat);
        if ( tmp == -1 ) return -1;
        else return ( strlength(txt)-strlength(tmp) );

}


char substr(char str, int start_index, int length) {
    if ( start_index+length > strlength(str) ) return NULL();
    if ( start_index < 0 || strlength(str) <= 0 ) return NULL();

    str = strright(str, start_index);
    str = strleft(str, length);

    return str;
}

char getchar(char str, int index) {

    if ( index >= strlength(str) ) index = strlength(str)-1;
    else if ( index < 0 ) index = 0;

    if ( strlength(str) > 0 ) {
        str = strright(str, index);

        if ( strlength(str) > 1 ) {
            index = 1;
            str = strleft(str, index);
        }
    }

    return str;
}

int exp(int base, int exp) {
    int i = 0;
    int result;
    int sign = 1;

    if ( base < 0 ) sign = -1;
    base = abs(base);
    exp = abs(exp);
    result = base;

    if ( exp == 0 ) return 1;
    for ( i = 0; i < exp-1; ++i ) {
        result *= base;
    }
    result *= sign;

    return result;
}

int to_int(char num) {
    char str_decimal = "", str_mantix = "", str_digit = "", tmp = "";
    int decimal = 0, sign = 1, sign_flag = 0;
    int digit = 0;
    int i = 0;
    int float_num = 0, mantix = 0;

    i = searchstr_index(num,".");
    if ( i != -1 ) {
        str_decimal = substr(num,0,i);
        str_mantix = substr(num,i+1,strlength(num)-i-1);
    } else {
        str_decimal = num;
        str_mantix = "";
    }

    tmp = getchar(str_decimal,0);
         if ( tmp == "+" ) { sign =  1; sign_flag = 1; }
    else if ( tmp == "-" ) { sign = -1; sign_flag = 1; }
    if ( sign_flag ) str_decimal = substr(str_decimal,1,strlength(str_decimal)-1);

    // get decimal part
    for ( i = strlength(str_decimal)-1; i >= 0; --i ) {
        str_digit = getchar(str_decimal,i);

             if ( str_digit == "0" ) digit = 0;
        else if ( str_digit == "1" ) digit = 1;
        else if ( str_digit == "2" ) digit = 2;
        else if ( str_digit == "3" ) digit = 3;
        else if ( str_digit == "4" ) digit = 4;
        else if ( str_digit == "5" ) digit = 5;
        else if ( str_digit == "6" ) digit = 6;
        else if ( str_digit == "7" ) digit = 7;
        else if ( str_digit == "8" ) digit = 8;
        else if ( str_digit == "9" ) digit = 9;
        else continue;

        digit *= exp(10,strlength(str_decimal)-1-i);
        decimal += digit;
    }

    // get mantix part
    for ( i = 0; i < strlength(str_mantix); ++i ) {
        int div = 0;

        str_digit = getchar(str_mantix,i);

             if ( str_digit == "0" ) digit = 0;
        else if ( str_digit == "1" ) digit = 1;
        else if ( str_digit == "2" ) digit = 2;
        else if ( str_digit == "3" ) digit = 3;
        else if ( str_digit == "4" ) digit = 4;
        else if ( str_digit == "5" ) digit = 5;
        else if ( str_digit == "6" ) digit = 6;
        else if ( str_digit == "7" ) digit = 7;
        else if ( str_digit == "8" ) digit = 8;
        else if ( str_digit == "9" ) digit = 9;
        else continue;

        div = exp(10,i+1);
        digit = (digit*1.0)/div; // *1.0 to normalize to float
        mantix += digit;
    }

    float_num = (sign*(decimal));

    return float_num;
}

int is_float(char num) {
    char str_decimal = "", str_mantix = "", str_digit = "", tmp = "";
    int sign_flag = 0;
    int digit = 0;
    int i = 0;

    i = searchstr_index(num,".");
    if ( i != -1 ) {
        str_decimal = substr(num,0,i);
        str_mantix = substr(num,i+1,strlength(num)-i-1);
    } else {
        str_decimal = num;
        str_mantix = "";
    }

    tmp = getchar(str_decimal,0);
         if ( tmp == "+" ) { sign_flag = 1; }
    else if ( tmp == "-" ) { sign_flag = 1; }
    if ( sign_flag ) str_decimal = substr(str_decimal,1,strlength(str_decimal)-1);

    // get decimal part
    for ( i = strlength(str_decimal)-1; i >= 0; --i ) {
        str_digit = getchar(str_decimal,i);

             if ( str_digit == "0" ) digit = 0;
        else if ( str_digit == "1" ) digit = 1;
        else if ( str_digit == "2" ) digit = 2;
        else if ( str_digit == "3" ) digit = 3;
        else if ( str_digit == "4" ) digit = 4;
        else if ( str_digit == "5" ) digit = 5;
        else if ( str_digit == "6" ) digit = 6;
        else if ( str_digit == "7" ) digit = 7;
        else if ( str_digit == "8" ) digit = 8;
        else if ( str_digit == "9" ) digit = 9;
        else return 0;
    }

    // get mantix part
    for ( i = 0; i < strlength(str_mantix); ++i ) {
        str_digit = getchar(str_mantix,i);

             if ( str_digit == "0" ) digit = 0;
        else if ( str_digit == "1" ) digit = 1;
        else if ( str_digit == "2" ) digit = 2;
        else if ( str_digit == "3" ) digit = 3;
        else if ( str_digit == "4" ) digit = 4;
        else if ( str_digit == "5" ) digit = 5;
        else if ( str_digit == "6" ) digit = 6;
        else if ( str_digit == "7" ) digit = 7;
        else if ( str_digit == "8" ) digit = 8;
        else if ( str_digit == "9" ) digit = 9;
        else return 0;
    }

    return 1;
}

void get_parsed_var(char label) {
    void self = glv("self");
    void value = gev(self,label);

    return value;
}

int trunc(int num) {
    int sign = 1;

    if ( num < 0 ) {
        sign = -1;
        num *= -1;
    }

    num = num%(num+1);
    num *= sign;

    return num;
}

float abs(float num) {
    if (num < 0) num *= -1;

    return num;
}