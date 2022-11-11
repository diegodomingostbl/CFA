#include "struct.h"

#ifndef DAO_VEICULO_H_INCLUDED
#define DAO_VEICULO_H_INCLUDED

int dao_gravarVeiculo(VEICULO veiculo);
int dao_retornaUltimoIdVeiculo();
VEICULO dao_procurarVeiculoId(int id);
VEICULO dao_tokenToVeiculo(char** tokens);
void dao_alterarVeiculo(VEICULO veiculo);
VEICULO dao_procurarVeiculoPlaca(char* placa);
VEICULO* dao_procurarVeiculoCasa(int id_casa, int* qtd);
int dao_gravarRelatorioVeiculo(VEICULO* veiculo, int qtdVeiculo, char* nome_arquivo);
VEICULO* dao_procurarTodosVeiculos(int* qtd);

#endif // DAO_VEICULO_H_INCLUDED
