#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

#include "archive.h"
#include "funcoes.h"

USERLOGIN usuarioLogado;

USERLOGIN login(char* error){
    USERLOGIN uLogin;
    char c;
    int a=0;

    printf("Entre com o login: ");
    gets(uLogin.login);
    printf("Entre com a senha: ");
    do{
        c=getch();
        if(isprint(c)){
            uLogin.senha[a] = c;
            a++;
            printf("*");
        }else if(c == 8 && a){
            uLogin.senha[a] = '\0';
            a--;
            printf("\b \b");
        }
    }while(c != 13);
    uLogin.senha[a]='\0';

    if(strcmp(uLogin.login, "") && strcmp(uLogin.senha, "")){
        uLogin = realizarLogin(uLogin, error);
    }else{
        strcpy(error, "Credenciais inválidas");
        uLogin.logado = false;
        strcpy(uLogin.senha, "");
    }

    return uLogin;
}

void main(){
    setlocale(LC_ALL, "Portuguese");
    USER usuario;
    char* error = malloc(150 * sizeof(char));

    usuarioLogado = login(error);
    printf("\n");

    if(usuarioLogado.logado == true){
        printf("Usuário %s logado com sucesso\n", usuarioLogado.nome);
    }else{
        printf("Error: %s\n", error);
    }

    retornaUsuarioLogado();
}
