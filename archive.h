#include "struct.h"

#ifndef ARCHIVE_H_INCLUDED
#define ARCHIVE_H_INCLUDED

int gravarUsuario(USER usuario);
USER procurarUsuarioId(int id);
USER procurarUsuarioLogin(char* cLogin);
USER tokenToUser(char** tokens);
int retornaUltimoIdUsuario();
USERLOGIN realizarLogin(USERLOGIN login, char* error);
USERLOGIN realizarLogout(char* error);
void retornaUsuarioLogado();

#endif // ARCHIVE_H_INCLUDED
