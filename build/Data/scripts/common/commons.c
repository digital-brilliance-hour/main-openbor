//Story System for OpenBOR
//Original by Volcanic; Modifications by CRxTRDude

//commons.c

char getchar(char str, int index) {

    if ( index >= strlength(str) ) index = strlength(str)-1;
    else if ( index < 0 ) index = 0;

    if ( strlength(str) > 0 ) {
        str = strright(str, index);

        if ( strlength(str) > 1 ) {
            index = 1;
            str = strleft(str, index);
        }
    } //else str = "";

    return str;
}