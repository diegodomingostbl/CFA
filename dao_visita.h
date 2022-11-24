#include "struct.h"

#ifndef DAO_VISITA_H_INCLUDED
#define DAO_VISITA_H_INCLUDED

int dao_gravarVisitaVeiculo(E_VEICULO veiculo);
int dao_retornaUltimoIdEntradaVeiculo();

int dao_gravarVisitaPessoa(E_PESSOA pessoa);
int dao_retornaUltimoIdEntradaPessoa();

E_PESSOA dao_tokenToEntradaPessoa(char** tokens);
E_VEICULO dao_tokenToEntradaVeiculo(char** tokens);
E_PESSOA* dao_procuraVisitaPessoaData(DATEC dt_inicial, DATEC dt_final, int* qtd);
E_VEICULO* dao_procuraVisitaVeiculoData(DATEC dt_inicial, DATEC dt_final, int* qtd);

int dao_gravarRelatorioVisitaPessoa(E_PESSOA* pessoa, int qtdPessoa, char* nome_arquivo);
int dao_gravarRelatorioVisitaVeiculo(E_VEICULO* veiculo, int qtdVeiculo, char* nome_arquivo);

#endif // DAO_VISITA_H_INCLUDED
