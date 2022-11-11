#include "struct.h"

#ifndef VIEW_RESIDENCIA_H_INCLUDED
#define VIEW_RESIDENCIA_H_INCLUDED

void view_gravarResidencia(RESIDENCIA residencia);

int view_alterarResidenciaPorID();
void view_alterarResidencia(RESIDENCIA residencia);
int view_alterarResidenciaPorNumero();
int view_alterarResidenciaPorBloco();

int view_relatorioResidenciaPorNumero();
int view_relatorioResidenciaPorBloco();
int view_relatorioResidencias();

#endif // VIEW_RESIDENCIA_H_INCLUDED
