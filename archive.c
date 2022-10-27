#include <stdio.h>
#include <stdlib.h>

#include "archive.h"
#include "funcoes.h"

int gravarUsuario(USER usuario){
	char linha[2000];
	char id[100];

	sprintf(id, "%d", usuario.id);

	FILE *file;
  	file = fopen("arquivos\\usuario.txt", "a");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return 0;
	}

  	strcpy(linha, id);
  	strcat(linha, "|");
	strcat(linha, usuario.nome);
	strcat(linha, "|");
	strcat(linha, usuario.sobrenome);
	strcat(linha, "|");
	strcat(linha, usuario.CPF);
	strcat(linha, "|");
	strcat(linha, usuario.nome);
	strcat(linha, "|");
	strcat(linha, usuario.login);
	strcat(linha, "|");
	strcat(linha, usuario.senha);
	strcat(linha, "\n");

	fprintf(file, linha);

	return 1;
}

int procurarUsuario(int id){
	char linha[2000];
	char** tokens;
	char convert[100];

	sprintf(convert, "%d", id);

	FILE *file;
  	file = fopen("arquivos\\usuario.txt", "a+");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return 0;
	}

	while(fgets(linha, 2000, file) != NULL){
        tokens = strSplit(linha, '|');
        if (tokens)
        {
            int i;
            for (i = 0; *(tokens + i); i++)
            {
                if(i == 0 && *(tokens + i))
                printf("Dados: %s\n", *(tokens + i));
                free(*(tokens + i));
            }
            printf("\n");
            free(tokens);
        }
	}
	fclose(file);

	return 1;
}

int retornaUltimoIdUsuario(){
    char linha[2000];
	char** splitLinha;
	char convert[100];
	int id = 0;

	FILE *file;
  	file = fopen("arquivos\\usuario.txt", "a+");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return 0;
	}

	while(fgets(linha, 2000, file) != NULL){
        splitLinha = strSplit(linha, '|');
        if (splitLinha){
            int i;
            for (i = 0; *(splitLinha + i); i++)
            {
                if(i == 0 && (stringToINT(*(splitLinha + i)) > id)){
                    id = stringToINT(*(splitLinha + i));
                }
                free(*(splitLinha + i));
            }
            free(splitLinha);
        }
	}
	fclose(file);

	return id;
}
