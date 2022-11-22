#include "struct.h"

#ifndef DAO_VISITA_H_INCLUDED
#define DAO_VISITA_H_INCLUDED

int dao_gravarVisitaVeiculo(E_VEICULO veiculo);
int dao_retornaUltimoIdEntradaVeiculo();

int dao_gravarVisitaPessoa(E_PESSOA pessoa);
int dao_retornaUltimoIdEntradaPessoa();

#endif // DAO_VISITA_H_INCLUDED
