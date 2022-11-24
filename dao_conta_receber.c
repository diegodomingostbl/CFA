#include <stdio.h>
#include <stdlib.h>

#include "dao_conta_receber.h"
#include "funcoes.h"

int dao_gravarContaReceber(C_RECEBER conta_receber){
	char linha[2000];

	FILE *file;
  	file = fopen("arquivos\\conta_receber.txt", "a");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return 0;
	}

  	strcpy(linha, IntToString(conta_receber.id));
  	strcat(linha, "|");
  	strcat(linha, conta_receber.nome);
	strcat(linha, "|");
	strcat(linha, DateToString(conta_receber.dt_vencimento));
	strcat(linha, "|");
	strcat(linha, floatToString(conta_receber.valor));
	strcat(linha, "\n");

	fprintf(file, linha);
    fclose(file);

    system("cls");
    printf("Conta a receber cadastrada com sucesso.\n");
    system("PAUSE");

	return 1;
}

int dao_retornaUltimoIdContaReceber(){
    char linha[2000];
	char** splitLinha;
	char convert[100];
	int id = 0;

	FILE *file;
  	file = fopen("arquivos\\conta_receber.txt", "a+");

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

C_RECEBER dao_procurarContaReceberId(int id){
	char linha[2000];
	char** tokens;
	C_RECEBER conta_receber;
	conta_receber.id = 0;

	FILE *file;
  	file = fopen("arquivos\\conta_receber.txt", "a+");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return conta_receber;
	}

	while(fgets(linha, 2000, file) != NULL){
        tokens = strSplit(linha, '|');
        if (tokens){
            if(stringToINT(*(tokens)) == id){
                conta_receber = dao_tokenToContaReceber(tokens);
            }
            free(tokens);
        }
	}
	fclose(file);

    return conta_receber;
}

C_RECEBER dao_tokenToContaReceber(char** tokens){
    C_RECEBER conta_receber;

    //int id
    conta_receber.id = stringToINT(*(tokens + 0));
    //nome
    strcpy(conta_receber.nome, *(tokens + 1));
    //data
    conta_receber.dt_vencimento = stringToDate(*(tokens + 2));
    //valor;
    conta_receber.valor = stringToFloat(*(tokens + 3));

    return conta_receber;
}

void dao_alterarContaReceber(C_RECEBER conta_receber){
    char linha[10000];
    char linhaBKP[2000];
    char linhaTeste[2000];
	char** tokens;

	strcpy(linhaBKP, "");

	FILE *file;
  	file = fopen("arquivos\\conta_receber.txt", "a+");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return;
	}

	while(fgets(linha, 2000, file) != NULL){
        strcpy(linhaTeste, linha);
        tokens = strSplit(linha, '|');
        if (tokens){
            if(stringToINT(*(tokens)) != conta_receber.id){
                strcat(linhaBKP, linhaTeste);
            }
            free(tokens);
        }
	}
	//limpando a memoria
	fclose(file);
	fflush(file);

    //criando linha para inserir o conta a receber alterado
	strcpy(linha, IntToString(conta_receber.id));
  	strcat(linha, "|");
	strcat(linha, conta_receber.nome);
	strcat(linha, "|");
	strcat(linha, DateToString(conta_receber.dt_vencimento));
	strcat(linha, "|");
	strcat(linha, floatToString(conta_receber.valor));
	strcat(linha, "\n");

	strcat(linha, linhaBKP);

	//gravando usuarios com os dados alterados
    file = fopen("arquivos\\conta_receber.txt", "w");
	fprintf(file, linha);
	fclose(file);

	system("cls");
	printf("Conta a receber %d alterado com sucesso.\n", conta_receber.id);
	system("PAUSE");
	system("cls");
}

C_RECEBER* dao_procuraContaReceberDataVencimento(DATEC dt_inicial, DATEC dt_final, int* qtd){
    char linha[2000];
	char** tokens;
	C_RECEBER* conta_receber;
	int qtdReceber = 0;

	conta_receber = malloc(sizeof(C_RECEBER));

	FILE *file;
  	file = fopen("arquivos\\conta_receber.txt", "a+");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return conta_receber;
	}

	while(fgets(linha, 2000, file) != NULL){
        tokens = strSplit(linha, '|');
        if (tokens){
            if(validarDataEntrePeriodos(dt_inicial, dt_final, stringToDate(*(tokens + 2))) == true){
                if(qtdReceber > 0){
                    conta_receber = realloc(conta_receber, (qtdReceber + 1) * sizeof(C_RECEBER));
                }
                *(conta_receber + qtdReceber) = dao_tokenToContaReceber(tokens);
                qtdReceber++;
            }
            free(tokens);
        }
	}
	fclose(file);

	*qtd = qtdReceber;

    return conta_receber;
}

int dao_gravarRelatorioContaReceber(C_RECEBER* conta_receber, int qtdContaReceber, char* nome_arquivo){
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

	fprintf(file, "Foram encontrados %d contas a receber\n", qtdContaReceber);
    fprintf(file, "%-5s | %-20s | %-17s | %-10s\n", "ID", "NOME", "DATA VENCIMENTO", "VALOR");
    for(int i = 0; i < qtdContaReceber; i++){
        fprintf(file, "%-5d | %-20s | %-17s | %-10.2f\n", (conta_receber + i)->id, (conta_receber + i)->nome, DateToString((conta_receber + i)->dt_vencimento), (conta_receber + i)->valor);
    }

    fclose(file);

    system("cls");
    printf("Relatório de contas a receber gerada com sucesso.\n");
    system("PAUSE");

	return 1;
}

float dao_somaContaReceber(C_RECEBER* conta_receber, int qtdContaReceber){
    int i = 0;
    float soma = 0;

    for(i = 0; i < qtdContaReceber; i++){
        soma += (conta_receber + i)->valor;
    }

    return soma;
}

