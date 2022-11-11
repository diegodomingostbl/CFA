#include <stdio.h>
#include <stdlib.h>

#include "dao_residencia.h"
#include "funcoes.h"
#include "struct.h"

int dao_gravarResidencia(RESIDENCIA residencia){
	char linha[2000];

	FILE *file;
  	file = fopen("arquivos\\residencia.txt", "a");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return 0;
	}

  	strcpy(linha, IntToString(residencia.id));
  	strcat(linha, "|");
  	strcat(linha, residencia.endereco);
	strcat(linha, "|");
	strcat(linha, IntToString(residencia.numero_casa));
	strcat(linha, "|");
	strcat(linha, residencia.bloco);
	strcat(linha, "\n");

	fprintf(file, linha);
    fclose(file);

	return 1;
}

int dao_retornaUltimoIdResidencia(){
    char linha[2000];
	char** splitLinha;
	int id = 0;

	FILE *file;
  	file = fopen("arquivos\\residencia.txt", "a+");

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

RESIDENCIA dao_procurarResidenciaId(int id){
	char linha[2000];
	char** tokens;
	RESIDENCIA residencia;
	residencia.id = 0;

	FILE *file;
  	file = fopen("arquivos\\residencia.txt", "a+");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return residencia;
	}

	while(fgets(linha, 2000, file) != NULL){
        tokens = strSplit(linha, '|');
        if (tokens){
            if(stringToINT(*(tokens)) == id){
                residencia = dao_tokenToResidencia(tokens);
            }
            free(tokens);
        }
	}
	fclose(file);

    return residencia;
}

RESIDENCIA dao_tokenToResidencia(char** tokens){
    RESIDENCIA residencia;

    //int id
    residencia.id = stringToINT(*(tokens + 0));
    //char endereco
    strcpy(residencia.endereco, *(tokens + 1));
    //int numero_casa;
    residencia.numero_casa = stringToINT(*(tokens + 2));
    //char bloco
    strcpy(residencia.bloco, removerBarraN(*(tokens + 3)));

    return residencia;
}

void dao_alterarResidencia(RESIDENCIA residencia){
    char linha[10000];
    char linhaBKP[2000];
    char linhaTeste[2000];
	char** tokens;

	strcpy(linhaBKP, "");

	FILE *file;
  	file = fopen("arquivos\\residencia.txt", "a+");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return;
	}

	while(fgets(linha, 2000, file) != NULL){
        strcpy(linhaTeste, linha);
        tokens = strSplit(linha, '|');
        if (tokens){
            if(stringToINT(*(tokens)) != residencia.id){
                strcat(linhaBKP, linhaTeste);
            }
            free(tokens);
        }
	}
	//limpando a memoria
	fclose(file);
	fflush(file);

    //criando linha para inserir o residencia alterado
	strcpy(linha, IntToString(residencia.id));
  	strcat(linha, "|");
	strcat(linha, residencia.endereco);
	strcat(linha, "|");
	strcat(linha, IntToString(residencia.numero_casa));
	strcat(linha, "|");
	strcat(linha, residencia.bloco);
	strcat(linha, "\n");

	strcat(linha, linhaBKP);

	//gravando residencia com os dados alterados
    file = fopen("arquivos\\residencia.txt", "w");
	fprintf(file, linha);
	fclose(file);

	system("cls");
	printf("Residência %d alterado com sucesso.\n", residencia.id);
	system("PAUSE");
	system("cls");
}

RESIDENCIA* dao_procurarResidenciaPorNumero(int numero_residencia, int* qtd){
    char linha[2000];
	char** tokens;
	RESIDENCIA* residencia;
	int qtdResidencia = 0;

	residencia = malloc(sizeof(RESIDENCIA));

	FILE *file;
  	file = fopen("arquivos\\residencia.txt", "a+");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return residencia;
	}

	while(fgets(linha, 2000, file) != NULL){
        tokens = strSplit(linha, '|');
        if (tokens){
            if(stringToINT(*(tokens + 2)) == numero_residencia){
                if(qtdResidencia > 0){
                    residencia = realloc(residencia, (qtdResidencia + 1) * sizeof(RESIDENCIA));
                }
                *(residencia + qtdResidencia) = dao_tokenToResidencia(tokens);
                qtdResidencia++;
            }
            free(tokens);
        }
	}
	fclose(file);

	*qtd = qtdResidencia;

    return residencia;
}

RESIDENCIA* dao_procurarResidenciaPorBloco(char* bloco, int* qtd){
    char linha[2000];
	char** tokens;
	RESIDENCIA* residencia;
	int qtdResidencia = 0;

	residencia = malloc(sizeof(RESIDENCIA));

	FILE *file;
  	file = fopen("arquivos\\residencia.txt", "a+");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return residencia;
	}

	while(fgets(linha, 2000, file) != NULL){
        tokens = strSplit(linha, '|');
        if (tokens){
            if(strcmp(toUpperString(removerBarraN(*(tokens + 3))),toUpperString(bloco)) == 0){
                if(qtdResidencia > 0){
                    residencia = realloc(residencia, (qtdResidencia + 1) * sizeof(RESIDENCIA));
                }
                *(residencia + qtdResidencia) = dao_tokenToResidencia(tokens);
                qtdResidencia++;
            }
            free(tokens);
        }
	}
	fclose(file);

	*qtd = qtdResidencia;

    return residencia;
}

int dao_gravarRelatorioResidencia(RESIDENCIA* residencia, int qtdResidencia, char* nome_arquivo){
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
    fprintf(file, "Foram encontradas %d residências\n", qtdResidencia);
    fprintf(file, "%-5s | %-25s | %-6s | %-6s \n", "ID", "ENDEREÇO", "NÚMERO", "BLOCO");

    for(int i = 0; i < qtdResidencia; i++){
        fprintf(file, "%-5d | %-25s | %-6d | %-6s \n", (residencia + i)->id, (residencia + i)->endereco, (residencia + i)->numero_casa, (residencia + i)->bloco);
    }

    fclose(file);

    system("cls");
    printf("Relatório de residência gerado com sucesso.\n");
    system("PAUSE");

	return 1;
}


RESIDENCIA* dao_procurarTodosResidencia(int* qtd){
    char linha[2000];
	char** tokens;
	RESIDENCIA* residencia;
	int qtdResidencia = 0;

	residencia = malloc(sizeof(RESIDENCIA));

	FILE *file;
  	file = fopen("arquivos\\residencia.txt", "a+");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return residencia;
	}

	while(fgets(linha, 2000, file) != NULL){
        tokens = strSplit(linha, '|');
        if (tokens){
            if(qtdResidencia > 0){
                residencia = realloc(residencia, (qtdResidencia + 1) * sizeof(RESIDENCIA));
            }
            *(residencia + qtdResidencia) = dao_tokenToResidencia(tokens);
            qtdResidencia++;
            free(tokens);
        }
	}
	fclose(file);

	*qtd = qtdResidencia;

    return residencia;
}

