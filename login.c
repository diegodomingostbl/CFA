#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

#include "login.h"
#include "dao_usuario.h"
#include "funcoes.h"
#include "telaMenu.h"

USERLOGIN usuarioLogado;

USERLOGIN login(char* error){
    USERLOGIN uLogin;
    char c;
    int a=0;

    fflush(stdin);
    printf("Login: ");
    gets(uLogin.login);
    printf("Senha: ");
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


void loginMain(){
    SetConsoleTitle("CFA - Controle de fluxo automotivo");
    setlocale(LC_ALL, "Portuguese");
    int opcao = 0;
    char* error = malloc(150 * sizeof(char));
    USERLOGIN usuarioLogadoLocal;


    do{
        system("cls");

        printf("           _______________ \n");
        printf("          / ____/ ____/   |\n");
        printf("         / /   / /_  / /| |\n");
        printf("        / /___/ __/ / ___ |\n");
        printf("        \\____/_/   /_/  |_|\n");
        printf("                       \n");
        printf("Controle de fluxo automotivo\n");
        printf(" 1 - Realizar login\n");
        printf(" 0 - Sair\n");
        printf("Digite uma das opções acima: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                do{
                    system("cls");
                    printf("CFA - Controle de fluxo automotivo\n");
                    usuarioLogadoLocal = login(error);
                    if(usuarioLogadoLocal.logado){
                        menu();
                    }else{
                        printf("\n\n------------------------------\n");
                        printf("| Ocorreu um erro no sistema |\n| %s  |", error);
                        printf("\n------------------------------\n\n");
                        system("pause");
                    }
                }while(usuarioLogadoLocal.logado == false);
                break;
        }
    }while(opcao != 0);
}
