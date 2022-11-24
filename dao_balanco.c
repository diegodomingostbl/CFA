#include "dao_balanco.h"
#include <stdio.h>
#include <stdlib.h>

#include "funcoes.h"

void dao_gravarBalancoPeriodo(float totalContaPagar, int qtdContaPagar, float totalContaReceber, int qtdContaReceber, char* nome_arquivo){
    char caminho[200];

	strcpy(caminho, "relatorios\\");
	strcat(caminho, nome_arquivo);
	strcat(caminho, ".txt");

	FILE *file;
  	file = fopen(caminho, "w");


  	if(file == NULL){
  		printf("Não foi possivel gravar o arquivo.\n");
  		system("PAUSE");
  		return 0;
	}

	fprintf(file, "Foram encontradas %d contas\n", qtdContaPagar + qtdContaReceber);
    fprintf(file, "Quantidade de contas a pagar: %d\n", qtdContaPagar);
    fprintf(file, "Valor total de contas a pagar: %.2f\n", totalContaPagar);
    fprintf(file, "Quantidade de contas a receber: %d\n", qtdContaReceber);
    fprintf(file, "Valor total de contas a receber: %.2f\n\n", totalContaReceber);
    fprintf(file, "Balanço no período: %.2f\n", totalContaReceber - totalContaPagar);

    fclose(file);

    system("cls");
    printf("Balanço gerado com sucesso.\n");
    system("PAUSE");

	return 1;
}
