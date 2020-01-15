void wordAtEnd(char string){
	//function to check for periods,exclamations or question marks
	//at the end of the sentence. They must be a space ('_') before
	//the word.
	void temp;
	
	temp = strright(string,2);
	
	if (temp == "._" || temp == "!_" || temp == "?_") return 1;
	else return 0;
}

void genderParser(char string){
	//log ("message acquired = "+string+"\n");
	char temp = string;
	char final;
	char give;

	//gender pronouns (he, she)	
	void	flagPro = strinfirst(string, "%gp");
	
	//gender preposition (him, her)
	void	flagPos = strinfirst(string, "%gr");
	
	//gender determiners (his, her)
	void	flagDet = strinfirst(string, "%gd");
	
	
	//temporary strings	
	void	tempmsgA;
	void	tempmsgB;
	void	tempcontext;
	int gender = getindexedvar(story_playerGender);
	
	//parser works by first checking for the flags '%gn'
	//and '%gp', then trims them all until we have
	//replaced every piece of them. 	
	
	while (flagPro != NULL() && flagPro != "" && flagPro != -1){
		int pos = strlength(temp) - strlength(flagPro);
		tempmsgA = strleft(temp,pos);
		tempmsgB = strright(temp,pos+3);
		if (gender) {
			if (tempmsgA == NULL()||wordAtEnd(tempmsgA)) tempcontext = "He";
			else tempcontext = "he";
		}
		else {
			if (tempmsgA == NULL()||wordAtEnd(tempmsgA)) tempcontext = "She";
			else tempcontext = "she";
		} 
		final = tempmsgA+tempcontext+tempmsgB;
		flagPro = strinfirst(final, "%gp");
	}
	
	while (flagPos != NULL() && flagPos != "" && flagPos != -1){
		int pos = strlength(temp) - strlength(flagPos);
		tempmsgA = strleft(temp,pos);
		tempmsgB = strright(temp,pos+3);
		if (gender) {
			if (tempmsgA != NULL()||wordAtEnd(tempmsgA)) tempcontext = "him";
		}
		else {
			if (tempmsgA != NULL()||wordAtEnd(tempmsgA)) tempcontext = "her";
		} 
		final = tempmsgA+tempcontext+tempmsgB;
		flagPos = strinfirst(final, "%gr");
	}

	while (flagDet != NULL() && flagDet != "" && flagDet != -1){
		int pos = strlength(temp) - strlength(flagDet);
		tempmsgA = strleft(temp,pos);
		tempmsgB = strright(temp,pos+3);
		if (gender) {
			if (tempmsgA == NULL()||wordAtEnd(tempmsgA)) tempcontext = "His";
			else tempcontext = "his";
		}
		else {
			if (tempmsgA == NULL()||wordAtEnd(tempmsgA)) tempcontext = "Her";
			else tempcontext = "her";
		} 
		final = tempmsgA+tempcontext+tempmsgB;
		flagDet = strinfirst(final, "%gd");
	}
	
	//if there are no parsable flags, just give the string anyway.	
	if (final==NULL()) final=temp;
	else if (final=="_") final="_"; 
	
  //log ("message parsed = "+final+"\n");
	
	give = final;
	
	final = NULL();
			
	return give;
	
 }