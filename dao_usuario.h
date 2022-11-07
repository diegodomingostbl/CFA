#include "struct.h"

#ifndef ARCHIVE_H_INCLUDED
#define ARCHIVE_H_INCLUDED

int gravarUsuario(USER usuario);
USER procurarUsuarioId(int id);
USER procurarUsuarioLogin(char* cLogin);
USER tokenToUser(char** tokens);
int retornaUltimoIdUsuario();
USERLOGIN realizarLogin(USERLOGIN login, char* error);
USERLOGIN realizarLogout();
USERLOGIN retornaUsuarioLogado();
void alterarFuncionarioDAO(USER usuario);
USER* procurarUsuarioCPF(char* CPF, int* qtd);
USER* procurarUsuarioNome(char* nome, int* qtd);

#endif // ARCHIVE_H_INCLUDED
