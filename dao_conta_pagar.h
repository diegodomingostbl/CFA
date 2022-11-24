#include "struct.h"

#ifndef DAO_CONTA_PAGAR_H_INCLUDED
#define DAO_CONTA_PAGAR_H_INCLUDED

int dao_gravarContaPagar(C_PAGAR conta_pagar);
int dao_retornaUltimoIdContaPagar();
C_PAGAR dao_procurarContaPagarId(int id);
C_PAGAR dao_tokenToContaPagar(char** tokens);
void dao_alterarContaPagar(C_PAGAR conta_pagar);
C_PAGAR* dao_procuraContaPagarDataVencimento(DATEC dt_inicial, DATEC dt_final, int* qtd);
int dao_gravarRelatorioContaPagar(C_PAGAR* conta_pagar, int qtdContaPagar, char* nome_arquivo);
float dao_somaContaPagar(C_PAGAR* conta_pagar, int qtdContaPagar);

#endif // DAO_CONTA_PAGAR_H_INCLUDED
