#include "struct.h"

#ifndef DAO_CONTA_RECEBER_H_INCLUDED
#define DAO_CONTA_RECEBER_H_INCLUDED

int dao_gravarContaReceber(C_RECEBER conta_receber);
int dao_retornaUltimoIdContaReceber();
C_RECEBER dao_procurarContaReceberId(int id);
C_RECEBER dao_tokenToContaReceber(char** tokens);
void dao_alterarContaReceber(C_RECEBER conta_receber);
C_RECEBER* dao_procuraContaReceberDataVencimento(DATEC dt_inicial, DATEC dt_final, int* qtd);
int dao_gravarRelatorioContaReceber(C_RECEBER* conta_receber, int qtdContaReceber, char* nome_arquivo);
float dao_somaContaReceber(C_RECEBER* conta_receber, int qtdContaReceber);

#endif // DAO_CONTA_RECEBER_H_INCLUDED
