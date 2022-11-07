#include "struct.h"

#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

char ** strSplit(char* a_str, const char a_delim);

int stringToINT(char* str);
//Para receber o parametro, é necessario atribuir em um ponteiro de char ou printar no printf
char* IntToString(int i);

float stringToFloat(char* str);
//Para receber o parametro, é necessario atribuir em um ponteiro de char ou printar no printf
char* floatToString(float i);

//Para receber o parametro, é necessario atribuir em um ponteiro de char ou printar no printf
char* DateToString(DATEC data);
DATEC stringToDate(char* str);
DATEC retornaDataAtual();

char* toLowerString(char* s);
char* toUpperString(char* s);

#endif // FUNCOES_H_INCLUDED
