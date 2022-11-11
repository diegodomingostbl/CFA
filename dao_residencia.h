#include "struct.h"

#ifndef DAO_RESIDENCIA_H_INCLUDED
#define DAO_RESIDENCIA_H_INCLUDED

int dao_gravarResidencia(RESIDENCIA residencia);
int dao_retornaUltimoIdResidencia();
RESIDENCIA dao_procurarResidenciaId(int id);
RESIDENCIA dao_tokenToResidencia(char** tokens);
void dao_alterarResidencia(RESIDENCIA residencia);
RESIDENCIA* dao_procurarResidenciaPorNumero(int numero_residencia, int* qtd);
RESIDENCIA* dao_procurarResidenciaPorBloco(char* bloco, int* qtd);
int dao_gravarRelatorioResidencia(RESIDENCIA* residencia, int qtdResidencia, char* nome_arquivo);
RESIDENCIA* dao_procurarTodosResidencia(int* qtd);

#endif // DAO_RESIDENCIA_H_INCLUDED
