#include <stdio.h>
#include <stdlib.h>

#include "dao_conta_pagar.h"
#include "funcoes.h"

int dao_gravarContaPagar(C_PAGAR conta_pagar){
	char linha[2000];

	FILE *file;
  	file = fopen("arquivos\\conta_pagar.txt", "a");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return 0;
	}

  	strcpy(linha, IntToString(conta_pagar.id));
  	strcat(linha, "|");
  	strcat(linha, conta_pagar.nome);
	strcat(linha, "|");
	strcat(linha, DateToString(conta_pagar.dt_vencimento));
	strcat(linha, "|");
	strcat(linha, floatToString(conta_pagar.valor));
	strcat(linha, "\n");

	fprintf(file, linha);
    fclose(file);

	return 1;
}

int dao_retornaUltimoIdContaPagar(){
    char linha[2000];
	char** splitLinha;
	char convert[100];
	int id = 0;

	FILE *file;
  	file = fopen("arquivos\\conta_pagar.txt", "a+");

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

C_PAGAR dao_procurarContaPagarId(int id){
	char linha[2000];
	char** tokens;
	C_PAGAR conta_pagar;
	conta_pagar.id = 0;

	FILE *file;
  	file = fopen("arquivos\\conta_pagar.txt", "a+");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return conta_pagar;
	}

	while(fgets(linha, 2000, file) != NULL){
        tokens = strSplit(linha, '|');
        if (tokens){
            if(stringToINT(*(tokens)) == id){
                conta_pagar = dao_tokenToContaPagar(tokens);
            }
            free(tokens);
        }
	}
	fclose(file);

    return conta_pagar;
}

C_PAGAR dao_tokenToContaPagar(char** tokens){
    C_PAGAR conta_pagar;

    //int id
    conta_pagar.id = stringToINT(*(tokens + 0));
    //nome
    strcpy(conta_pagar.nome, *(tokens + 1));
    //data
    conta_pagar.dt_vencimento = stringToDate(*(tokens + 2));
    //valor;
    conta_pagar.valor = stringToFloat(*(tokens + 3));

    return conta_pagar;
}

void dao_alterarContaPagar(C_PAGAR conta_pagar){
    char linha[10000];
    char linhaBKP[2000];
    char linhaTeste[2000];
	char** tokens;

	strcpy(linhaBKP, "");

	FILE *file;
  	file = fopen("arquivos\\conta_pagar.txt", "a+");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return;
	}

	while(fgets(linha, 2000, file) != NULL){
        strcpy(linhaTeste, linha);
        tokens = strSplit(linha, '|');
        if (tokens){
            if(stringToINT(*(tokens)) != conta_pagar.id){
                strcat(linhaBKP, linhaTeste);
            }
            free(tokens);
        }
	}
	//limpando a memoria
	fclose(file);
	fflush(file);

    //criando linha para inserir o conta a pagar alterado
	strcpy(linha, IntToString(conta_pagar.id));
  	strcat(linha, "|");
	strcat(linha, conta_pagar.nome);
	strcat(linha, "|");
	strcat(linha, DateToString(conta_pagar.dt_vencimento));
	strcat(linha, "|");
	strcat(linha, floatToString(conta_pagar.valor));
	strcat(linha, "\n");

	strcat(linha, linhaBKP);

	//gravando usuarios com os dados alterados
    file = fopen("arquivos\\conta_pagar.txt", "w");
	fprintf(file, linha);
	fclose(file);

	system("cls");
	printf("Conta a pagar %d alterado com sucesso.\n", conta_pagar.id);
	system("PAUSE");
	system("cls");
}

C_PAGAR* dao_procuraContaPagarDataVencimento(DATEC dt_inicial, DATEC dt_final, int* qtd){
    char linha[2000];
	char** tokens;
	C_PAGAR* conta_pagar;
	int qtdPagar = 0;

	conta_pagar = malloc(sizeof(C_PAGAR));

	FILE *file;
  	file = fopen("arquivos\\conta_pagar.txt", "a+");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return conta_pagar;
	}

	while(fgets(linha, 2000, file) != NULL){
        tokens = strSplit(linha, '|');
        if (tokens){
            if(validarDataEntrePeriodos(dt_inicial, dt_final, stringToDate(*(tokens + 2))) == true){
                if(qtdPagar > 0){
                    conta_pagar = realloc(conta_pagar, (qtdPagar + 1) * sizeof(C_PAGAR));
                }
                *(conta_pagar + qtdPagar) = dao_tokenToContaPagar(tokens);
                qtdPagar++;
            }
            free(tokens);
        }
	}
	fclose(file);

	*qtd = qtdPagar;

    return conta_pagar;
}

int dao_gravarRelatorioContaPagar(C_PAGAR* conta_pagar, int qtdContaPagar, char* nome_arquivo){
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

	fprintf(file, "Foram encontrados %d contas a pagar\n", qtdContaPagar);
    fprintf(file, "%-5s | %-20s | %-17s | %-10s\n", "ID", "NOME", "DATA VENCIMENTO", "VALOR");
    for(int i = 0; i < qtdContaPagar; i++){
        fprintf(file, "%-5d | %-20s | %-17s | %-10.2f\n", (conta_pagar + i)->id, (conta_pagar + i)->nome, DateToString((conta_pagar + i)->dt_vencimento), (conta_pagar + i)->valor);
    }

    fclose(file);

    system("cls");
    printf("Relatório de contas a pagar gerada com sucesso.\n");
    system("PAUSE");

	return 1;
}


