#include <stdio.h>
#include <stdlib.h>

#include "dao_veiculo.h"
#include "funcoes.h"
#include "struct.h"

int dao_gravarVeiculo(VEICULO veiculo){
	char linha[2000];

	FILE *file;
  	file = fopen("arquivos\\veiculo.txt", "a");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return 0;
	}

  	strcpy(linha, IntToString(veiculo.id));
  	strcat(linha, "|");
	strcat(linha, IntToString(veiculo.idcasa));
	strcat(linha, "|");
	strcat(linha, veiculo.placa);
	strcat(linha, "|");
	strcat(linha, veiculo.modelo);
	strcat(linha, "|");
	strcat(linha, veiculo.cor);
	strcat(linha, "\n");

	fprintf(file, linha);
    fclose(file);

	return 1;
}

int dao_retornaUltimoIdVeiculo(){
    char linha[2000];
	char** splitLinha;
	char convert[100];
	int id = 0;

	FILE *file;
  	file = fopen("arquivos\\veiculo.txt", "a+");

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

VEICULO dao_procurarVeiculoId(int id){
	char linha[2000];
	char** tokens;
	VEICULO veiculo;
	veiculo.id = 0;
    veiculo.idcasa = 0;

	FILE *file;
  	file = fopen("arquivos\\veiculo.txt", "a+");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return veiculo;
	}

	while(fgets(linha, 2000, file) != NULL){
        tokens = strSplit(linha, '|');
        if (tokens){
            if(stringToINT(*(tokens)) == id){
                veiculo = dao_tokenToVeiculo(tokens);
            }
            free(tokens);
        }
	}
	fclose(file);

    return veiculo;
}

VEICULO dao_tokenToVeiculo(char** tokens){
    VEICULO veiculo;

    //int id
    veiculo.id = stringToINT(*(tokens + 0));
    //int idCasa
    veiculo.idcasa = stringToINT(*(tokens + 1));
    //char placa;
    strcpy(veiculo.placa, *(tokens + 2));
    //char modelo
    strcpy(veiculo.modelo, *(tokens + 3));
    //char cor
    strcpy(veiculo.cor, removerBarraN(*(tokens + 4)));

    return veiculo;
}

void dao_alterarVeiculo(VEICULO veiculo){
    char linha[10000];
    char linhaBKP[2000];
    char linhaTeste[2000];
	char** tokens;

	strcpy(linhaBKP, "");

	FILE *file;
  	file = fopen("arquivos\\veiculo.txt", "a+");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return;
	}

	while(fgets(linha, 2000, file) != NULL){
        strcpy(linhaTeste, linha);
        tokens = strSplit(linha, '|');
        if (tokens){
            if(stringToINT(*(tokens)) != veiculo.id){
                strcat(linhaBKP, linhaTeste);
            }
            free(tokens);
        }
	}
	//limpando a memoria
	fclose(file);
	fflush(file);

	strcpy(veiculo.placa, toUpperString(veiculo.placa));

    //criando linha para inserir o veiculo alterado
	strcpy(linha, IntToString(veiculo.id));
  	strcat(linha, "|");
	strcat(linha, IntToString(veiculo.idcasa));
	strcat(linha, "|");
	strcat(linha, veiculo.placa);
	strcat(linha, "|");
	strcat(linha, veiculo.modelo);
	strcat(linha, "|");
	strcat(linha, veiculo.cor);
	strcat(linha, "\n");

	strcat(linha, linhaBKP);

	//gravando usuarios com os dados alterados
    file = fopen("arquivos\\veiculo.txt", "w");
	fprintf(file, linha);
	fclose(file);

	system("cls");
	printf("Veiculo %d alterado com sucesso.\n", veiculo.id);
	system("PAUSE");
	system("cls");
}

VEICULO dao_procurarVeiculoPlaca(char* placa){
	char linha[2000];
	char** tokens;
	VEICULO veiculo;
	veiculo.id = 0;
    veiculo.idcasa = 0;

	FILE *file;
  	file = fopen("arquivos\\veiculo.txt", "a+");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return veiculo;
	}

	while(fgets(linha, 2000, file) != NULL){
        tokens = strSplit(linha, '|');
        if (tokens){
            if(strcmp(toUpperString(*(tokens + 2)), toUpperString(placa)) == 0){
                veiculo = dao_tokenToVeiculo(tokens);
            }
            free(tokens);
        }
	}
	fclose(file);

    return veiculo;
}

VEICULO* dao_procurarVeiculoCasa(int id_casa, int* qtd){
    char linha[2000];
	char** tokens;
	VEICULO* veiculo;
	int qtdVeiculo = 0;

	veiculo = malloc(sizeof(VEICULO));

	FILE *file;
  	file = fopen("arquivos\\veiculo.txt", "a+");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return veiculo;
	}

	while(fgets(linha, 2000, file) != NULL){
        tokens = strSplit(linha, '|');
        if (tokens){
            if(stringToINT(*(tokens + 1)) == id_casa){
                if(qtdVeiculo > 0){
                    veiculo = realloc(veiculo, (qtdVeiculo + 1) * sizeof(VEICULO));
                }
                *(veiculo + qtdVeiculo) = dao_tokenToVeiculo(tokens);
                qtdVeiculo++;
            }
            free(tokens);
        }
	}
	fclose(file);

	*qtd = qtdVeiculo;

    return veiculo;
}

int dao_gravarRelatorioVeiculo(VEICULO* veiculo, int qtdVeiculo, char* nome_arquivo){
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
    fprintf(file, "Foram encontrados %d veículos\n", qtdVeiculo);
    fprintf(file, "%-5s | %-5s | %-9s | %-25s | %-8s \n", "ID", "CASA", "PLACA", "MODELO", "COR");

    for(int i = 0; i < qtdVeiculo; i++){
        fprintf(file, "%-5d | %-5d | %-9s | %-25s | %-8s \n", (veiculo + i)->id, (veiculo + i)->idcasa, (veiculo + i)->placa, (veiculo + i)->modelo, (veiculo + i)->cor);
    }

    fclose(file);

    system("cls");
    printf("Relatório de veículos gerado com sucesso.\n");
    system("PAUSE");

	return 1;
}

VEICULO* dao_procurarTodosVeiculos(int* qtd){
    char linha[2000];
	char** tokens;
	VEICULO* veiculo;
	int qtdVeiculo = 0;

	veiculo = malloc(sizeof(VEICULO));

	FILE *file;
  	file = fopen("arquivos\\veiculo.txt", "a+");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return veiculo;
	}

	while(fgets(linha, 2000, file) != NULL){
        tokens = strSplit(linha, '|');
        if (tokens){
            if(qtdVeiculo > 0){
                veiculo = realloc(veiculo, (qtdVeiculo + 1) * sizeof(VEICULO));
            }
            *(veiculo + qtdVeiculo) = dao_tokenToVeiculo(tokens);
            qtdVeiculo++;
            free(tokens);
        }
	}
	fclose(file);

	*qtd = qtdVeiculo;

    return veiculo;
}
