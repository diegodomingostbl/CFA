#include<stdio.h>
#include<locale.h>
#include<string.h>
#include "archive.c";

void main(){
    setlocale(LC_ALL, "Portuguese");
    int criar_Arquivo;
    
    USER usuario;
    usuario.id = 1;
    strcpy(usuario.nome, "Diego Domingos");
    strcpy(usuario.login, "diego");
    strcpy(usuario.senha, "12345");
    
    printf("CFA - Controle de fluxo automotivo");

	//criar_Arquivo = createArchive();
	
	criar_Arquivo = gravarUsuario(usuario);
	//criar_Arquivo = procurarUsuario(1);
}
