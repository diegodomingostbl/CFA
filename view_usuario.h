#include "struct.h"

#ifndef VIEW_USUARIO_H_INCLUDED
#define VIEW_USUARIO_H_INCLUDED

int alterarFuncionarioPorID();
int alterarFuncionarioPorCPF();
int alterarFuncionarioPorLogin();
int alterarFuncionarioPorNome();
void view_AlterarUsuarioPorUSER(USER usuario);
int view_relatorioFuncionarioPorNome();
int view_relatorioFuncionarioPorDataCadastro();
int view_relatorioFuncionarioPorDataNascimento();

#endif // VIEW_USUARIO_H_INCLUDED
