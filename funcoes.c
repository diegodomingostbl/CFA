#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#include "struct.h"
#include "funcoes.h"

char ** strSplit(char* a_str, const char a_delim){
    char** result = 0;
    size_t count = 0;
    char* tmp = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

int stringToINT(char* str){
    return atoi(str);
}

char* IntToString(int x){
	int length = snprintf( NULL, 0, "%d", x );
	char* str = malloc( length + 1 );

	snprintf( str, length + 1, "%d", x );

	return str;
}

float stringToFloat(char* str){
    return atof(str);
}

char* floatToString(float x){
    char* str = malloc(20 * sizeof(char));
    sprintf(str, "%.2f", x);

	return str;
}

char* DateToString(DATEC data){
    char * string_data;
    string_data = malloc(15 * sizeof(char));

    strcpy(string_data, IntToString(data.dia));
  	strcat(string_data, "/");
  	strcat(string_data, IntToString(data.mes));
  	strcat(string_data, "/");
    strcat(string_data, IntToString(data.ano));

  	return string_data;
}

DATEC stringToDate(char* str){
    DATEC data;
    char *token = strtok(str, "/");

    if(token){
        data.dia = stringToINT(token);
        token = strtok(NULL, "/");
        data.mes = stringToINT(token);
        token = strtok(NULL, "/");
        data.ano = stringToINT(token);
    }else{
        data = retornaDataAtual();
    }

    return data;
}

DATEC retornaDataAtual(){
	DATEC data;
  	time_t t = time(NULL);
  	struct tm tm = *localtime(&t);

  	data.dia = tm.tm_mday;
  	data.mes = tm.tm_mon + 1;
  	data.ano = tm.tm_year + 1900;

  	return data;
}

char* toLowerString(char* s) {
  for(char *p=s; *p; p++) *p=tolower(*p);
  return s;
}

char* toUpperString(char* s) {
  for(char *p=s; *p; p++) *p=toupper(*p);
  return s;
}
