#include "struct.h"

#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

char ** strSplit(char* a_str, const char a_delim);

int stringToINT(char* str);

char* IntToString(int i);

char* DateToString(DATEC data);

DATEC retornaDataAtual();

#endif // FUNCOES_H_INCLUDED
