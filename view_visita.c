#include "view_visita.h"
#include "dao_visita.h"
#include "funcoes.h"
#include "struct.h"

void view_gravarVisitaVeiculo(E_VEICULO veiculo){
    veiculo.id = dao_retornaUltimoIdEntradaVeiculo() + 1;
    veiculo.data_entrada = retornaDataAtual();

    dao_gravarVisitaVeiculo(veiculo);
}

void view_gravarVisitaPessoa(E_PESSOA pessoa){
    pessoa.id = dao_retornaUltimoIdEntradaPessoa() + 1;
    pessoa.data_entrada = retornaDataAtual();

    dao_gravarVisitaPessoa(pessoa);
}
