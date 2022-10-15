#include <stdio.h>
#include <stdlib.h>
#include "struct.c";

int createArchive(){
  // criando a variável ponteiro para o arquivo
  FILE *file;
  
  //abrindo o arquivo
  file = fopen("arquivos\\arquivo.txt", "a");
  
  fprintf(file, "Diego Domingos");
  
  // fechando arquivo
  fclose(file);
  
  //mensagem para o usuário
  printf("O arquivo foi criado com sucesso!");
  
  return 1;
}

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
  	strcat(linha, "|@|");
	strcat(linha, usuario.nome);
	strcat(linha, "|@|");
	strcat(linha, usuario.login);
	strcat(linha, "|@|");
	strcat(linha, usuario.senha);
	strcat(linha, "\n");
	
	fprintf(file, linha);
	
	return 1;
}

int procurarUsuario(int id){
	char linha[2000];
	int i;
	char *arrayP[4];
	
	FILE *file;
  	file = fopen("arquivos\\arquivo.txt", "a+");
  	
  	if(file == NULL){
  		printf("Não foi possivel abrir o arquivo.");
  		return 0;
	}
	
	while(fgets(linha, 2000, file) != NULL){
		arrayP = splitSeparetor(linha, 4);
		for (i = 0; i < 4; ++i) {
			printf("%s\n", arrayP[i]);
		}
	}
	fclose(file);
	
	return 1; 
}

char *splitSeparetor(char[2000] linha, int qtdParametros){
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
