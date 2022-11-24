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

E_PESSOA dao_tokenToEntradaPessoa(char** tokens){
    E_PESSOA pessoa;

    pessoa.id = stringToINT(*(tokens + 0));
    pessoa.visitando_residencia = stringToINT(*(tokens + 1));
    strcpy(pessoa.nomeSobrenome, *(tokens + 2));
    strcpy(pessoa.CPF, *(tokens + 3));
    pessoa.data_entrada = stringToDate(*(tokens + 4));

    return pessoa;
}

E_VEICULO dao_tokenToEntradaVeiculo(char** tokens){
    E_VEICULO veiculo;

    //int id
    veiculo.id = stringToINT(*(tokens + 0));
    veiculo.visitando_residencia = stringToINT(*(tokens + 1));
    strcpy(veiculo.placa, *(tokens + 2));
    strcpy(veiculo.nomeSobrenomeMotorista, *(tokens + 3));
    veiculo.data_entrada = stringToDate(*(tokens + 4));

    return veiculo;
}

E_PESSOA* dao_procuraVisitaPessoaData(DATEC dt_inicial, DATEC dt_final, int* qtd){
    char linha[2000];
	char** tokens;
	E_PESSOA* pessoa;
	int qtdPessoa = 0;

	pessoa = malloc(sizeof(E_PESSOA));

	FILE *file;
  	file = fopen("arquivos\\entrada_pessoa.txt", "a+");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return pessoa;
	}

	while(fgets(linha, 2000, file) != NULL){
        tokens = strSplit(linha, '|');
        if (tokens){
            if(validarDataEntrePeriodos(dt_inicial, dt_final, stringToDate(*(tokens + 4))) == true){
                if(qtdPessoa > 0){
                    pessoa = realloc(pessoa, (qtdPessoa + 1) * sizeof(E_PESSOA));
                }
                *(pessoa + qtdPessoa) = dao_tokenToEntradaPessoa(tokens);
                qtdPessoa++;
            }
            free(tokens);
        }
	}
	fclose(file);

	*qtd = qtdPessoa;

    return pessoa;
}

E_VEICULO* dao_procuraVisitaVeiculoData(DATEC dt_inicial, DATEC dt_final, int* qtd){
    char linha[2000];
	char** tokens;
	E_VEICULO* veiculo;
	int qtdVeiculo = 0;

	veiculo = malloc(sizeof(E_VEICULO));

	FILE *file;
  	file = fopen("arquivos\\entrada_veiculo.txt", "a+");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return veiculo;
	}

	while(fgets(linha, 2000, file) != NULL){
        tokens = strSplit(linha, '|');
        if (tokens){
            if(validarDataEntrePeriodos(dt_inicial, dt_final, stringToDate(*(tokens + 4))) == true){
                if(qtdVeiculo > 0){
                    veiculo = realloc(veiculo, (qtdVeiculo + 1) * sizeof(E_VEICULO));
                }
                *(veiculo + qtdVeiculo) = dao_tokenToEntradaVeiculo(tokens);
                qtdVeiculo++;
            }
            free(tokens);
        }
	}
	fclose(file);

	*qtd = qtdVeiculo;

    return veiculo;
}

int dao_gravarRelatorioVisitaPessoa(E_PESSOA* pessoa, int qtdPessoa, char* nome_arquivo){
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

	fprintf(file, "Foram encontrados %d visitas de pessoas\n", qtdPessoa);
    fprintf(file, "%-5s | %-12s | %-30s | %-15s | %-12s\n", "ID", "RESIDÊNCIA", "NOME COMPLETO", "CPF", "DATA DE ENTRADA");
    for(int i = 0; i < qtdPessoa; i++){
        fprintf(file, "%-5d | %-12d | %-30s | %-15s | %-12s\n", (pessoa + i)->id, (pessoa + i)->visitando_residencia, (pessoa + i)->nomeSobrenome, (pessoa + i)->CPF, DateToString((pessoa + i)->data_entrada));
    }

    fclose(file);

    system("cls");
    printf("Relatório de visitas gerada com sucesso.\n");
    system("PAUSE");

	return 1;
}

int dao_gravarRelatorioVisitaVeiculo(E_VEICULO* veiculo, int qtdVeiculo, char* nome_arquivo){
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

	fprintf(file, "Foram encontrados %d visitas de pessoas\n", qtdVeiculo);
    fprintf(file, "%-5s | %-12s | %-20s | %-15s | %-12s\n", "ID", "RESIDÊNCIA", "NOME COMPLETO", "CPF", "DATA DE ENTRADA");
    for(int i = 0; i < qtdVeiculo; i++){
        fprintf(file, "%-5d | %-12d | %-20s | %-15s | %-12s\n", (veiculo + i)->id, (veiculo + i)->visitando_residencia, (veiculo + i)->nomeSobrenomeMotorista, (veiculo + i)->placa, DateToString((veiculo + i)->data_entrada));
    }

    fclose(file);

    system("cls");
    printf("Relatório de visitas com veículo gerado com sucesso.\n");
    system("PAUSE");

	return 1;
}
