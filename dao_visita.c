#include <stdio.h>
#include <stdlib.h>

#include "dao_visita.h"
#include "funcoes.h"
#include "struct.h"

int dao_gravarVisitaVeiculo(E_VEICULO veiculo){
	char linha[2000];

	FILE *file;
  	file = fopen("arquivos\\entrada_veiculo.txt", "a");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return 0;
	}

  	strcpy(linha, IntToString(veiculo.id));
  	strcat(linha, "|");
  	strcat(linha, IntToString(veiculo.visitando_residencia));
	strcat(linha, "|");
	strcat(linha, veiculo.placa);
	strcat(linha, "|");
	strcat(linha, veiculo.nomeSobrenomeMotorista);
	strcat(linha, "|");
	strcat(linha, DateToString(veiculo.data_entrada));
	strcat(linha, "\n");

	fprintf(file, linha);
    fclose(file);

	return 1;
}

int dao_retornaUltimoIdEntradaVeiculo(){
    char linha[2000];
	char** splitLinha;
	int id = 0;

	FILE *file;
  	file = fopen("arquivos\\entrada_veiculo.txt", "a+");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return id;
	}

	while(fgets(linha, 2000, file) != NULL){
        splitLinha = strSplit(linha, '|');
        if (splitLinha){
            if(stringToINT(*(splitLinha + 0)) > id){
                id = stringToINT(*(splitLinha + 0));
            }
            free(splitLinha);
        }
	}
	fclose(file);

	return id;
}

int dao_gravarVisitaPessoa(E_PESSOA pessoa){
	char linha[2000];

	FILE *file;
  	file = fopen("arquivos\\entrada_pessoa.txt", "a");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return 0;
	}

  	strcpy(linha, IntToString(pessoa.id));
  	strcat(linha, "|");
  	strcat(linha, IntToString(pessoa.visitando_residencia));
	strcat(linha, "|");
	strcat(linha, pessoa.nomeSobrenome);
	strcat(linha, "|");
	strcat(linha, pessoa.CPF);
	strcat(linha, "|");
	strcat(linha, DateToString(pessoa.data_entrada));
	strcat(linha, "\n");

	fprintf(file, linha);
    fclose(file);

	return 1;
}

int dao_retornaUltimoIdEntradaPessoa(){
    char linha[2000];
	char** splitLinha;
	int id = 0;

	FILE *file;
  	file = fopen("arquivos\\entrada_pessoa.txt", "a+");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return id;
	}

	while(fgets(linha, 2000, file) != NULL){
        splitLinha = strSplit(linha, '|');
        if (splitLinha){
            if(stringToINT(*(splitLinha + 0)) > id){
                id = stringToINT(*(splitLinha + 0));
            }
            free(splitLinha);
        }
	}
	fclose(file);

	return id;
}
