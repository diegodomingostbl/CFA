#include <stdio.h>
#include <stdlib.h>

#include "struct.c";

int gravarUsuario(USER usuario){
	char linha[2000];
	char convert[100];

	sprintf(convert, "%d", usuario.id);

	FILE *file;
  	file = fopen("arquivos\\usuario.txt", "a");

  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return 0;
	}

  	strcpy(linha, convert);
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
        tokens = str_split(linha, '|');
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

/*
char ** splitSeparetor(char[2000] linha, int qtdParametros){
    char buf[] ="abc/@qwe/@ccd";
    int i = 0;
    char *p = strtok (linha, "/@");
    char *array[qtdParametros];

    while (p != NULL)
    {
        array[i++] = p;
        p = strtok (NULL, "/@");
    }

    return array;
}
*/
