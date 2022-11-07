#include <stdio.h>
#include <ctype.h>

#include "view_usuario.h"
#include "dao_usuario.h"
#include "funcoes.h"

int alterarFuncionarioPorID(){
    int id_usuario = 0;
    USER usuario;
    char buscar_novamente = 'N';

    do{
        system("cls");
        printf("Alterar funcion�rio\n");
        printf("Digite 0 (zero) para voltar\n");
        printf("Digite o c�digo interno do funcion�rio: ");
        scanf("%d", &id_usuario);

        if(id_usuario > 0){
            usuario = procurarUsuarioId(id_usuario);
            if(usuario.id > 0){
                view_AlterarUsuarioPorUSER(usuario);
            }else{
                printf("Usu�rio n�o encontrado!\n");
                printf("Deseja busc�-lo novamente ? (S para SIM / N para N�O): ");
                buscar_novamente = getche();
            }
        }else{
            return 1;
        }
    }while(toupper(buscar_novamente) == 'S');

    return 0;
}

int alterarFuncionarioPorCPF(){
    char cpf[14];
    USER* usuario;
    int qtdUsuario = 0;
    char buscar_novamente = 'N';
    char nomeSobrenome[300];
    int idUsuario = 0;
    bool achou_usuario = false;

    do{
        system("cls");
        fflush(stdin);
        printf("Alterar funcion�rio\n");
        printf("Digite 0 (zero) para voltar\n");
        printf("Digite o CPF do funcion�rio: ");
        gets(cpf);

        if(cpf != '0'){
            usuario = procurarUsuarioCPF(cpf, &qtdUsuario);

            if(qtdUsuario == 1){
                view_AlterarUsuarioPorUSER(*(usuario + 0));
            }else if(qtdUsuario > 1){
                do{
                    printf("Foram encontrados %d funcion�rios\n", qtdUsuario);
                    printf("%-5s | %-20s | %-13s | %-10s\n", "ID", "NOME", "CPF", "LOGIN");

                    for(int i = 0; i < qtdUsuario; i++){
                        strcpy(nomeSobrenome, (usuario + i)->nome);
                        strcat(nomeSobrenome, " ");
                        strcat(nomeSobrenome, (usuario + i)->sobrenome);
                        printf("%-5d | %-20s | %-13s | %-10s\n", (usuario + i)->id, nomeSobrenome, (usuario + i)->CPF, (usuario + i)->login);
                    }
                    printf("Digite 0 (zero) para voltar\n");
                    printf("Digite o ID: ");
                    scanf("%d", &idUsuario);

                    if(idUsuario != 0){
                        for(int i = 0; i < qtdUsuario; i++){
                            if((usuario + i)->id == idUsuario){
                                achou_usuario = true;
                                view_AlterarUsuarioPorUSER(*(usuario + i));
                                return 0;
                            }
                        }
                        system("cls");
                        printf("Identificado (ID) inv�lido, escolha uns dos identificadores abaixo\n");
                    }else{
                        return 1;
                    }
                }while(achou_usuario != true && idUsuario != 0);
            }else{
                printf("CPF n�o encontrado!\n");
                printf("Deseja busc�-lo novamente ? (S para SIM / N para N�O): ");
                buscar_novamente = getche();
            }
        }else{
            return 1;
        }
    }while(toupper(buscar_novamente) == 'S');

    return 0;
}

int alterarFuncionarioPorLogin(){
    char login[50];
    USER usuario;
    char buscar_novamente = 'N';

    do{
        fflush(stdin);
        system("cls");
        printf("Alterar funcion�rio\n");
        printf("Digite 0 (zero) para voltar\n");
        printf("Digite o LOGIN do funcion�rio para buscar: ");
        gets(login);

        if(login != '0'){
            usuario = procurarUsuarioLogin(login);
            if(usuario.id > 0){
                view_AlterarUsuarioPorUSER(usuario);
            }else{
                printf("Login n�o encontrado!\n");
                printf("Deseja busc�-lo novamente ? (S para SIM / N para N�O): ");
                buscar_novamente = getche();
            }
        }else{
            return 1;
        }
    }while(toupper(buscar_novamente) == 'S');

    return 0;
}

int alterarFuncionarioPorNome(){
    char nome[300];
    USER* usuario;
    int qtdUsuario = 0;
    char buscar_novamente = 'N';
    char nomeSobrenome[300];
    int idUsuario = 0;
    bool achou_usuario = false;

    do{
        system("cls");
        fflush(stdin);
        printf("Alterar funcion�rio\n");
        printf("Digite 0 (zero) para voltar\n");
        printf("Digite o nome do funcion�rio: ");
        gets(nome);

        if(nome != '0'){
            usuario = procurarUsuarioNome(nome, &qtdUsuario);

            if(qtdUsuario == 1){
                view_AlterarUsuarioPorUSER(*(usuario + 0));
            }else if(qtdUsuario > 1){
                do{
                    printf("Foram encontrados %d funcion�rios\n", qtdUsuario);
                    printf("%-5s | %-20s | %-13s | %-10s\n", "ID", "NOME", "CPF", "LOGIN");

                    for(int i = 0; i < qtdUsuario; i++){
                        strcpy(nomeSobrenome, (usuario + i)->nome);
                        strcat(nomeSobrenome, " ");
                        strcat(nomeSobrenome, (usuario + i)->sobrenome);
                        printf("%-5d | %-20s | %-13s | %-10s\n", (usuario + i)->id, nomeSobrenome, (usuario + i)->CPF, (usuario + i)->login);
                    }
                    printf("Digite 0 (zero) para voltar\n");
                    printf("Digite o ID: ");
                    scanf("%d", &idUsuario);

                    if(idUsuario != 0){
                        for(int i = 0; i < qtdUsuario; i++){
                            if((usuario + i)->id == idUsuario){
                                achou_usuario = true;
                                view_AlterarUsuarioPorUSER(*(usuario + i));
                                return 0;
                            }
                        }
                        system("cls");
                        printf("Identificado (ID) inv�lido, escolha uns dos identificadores abaixo\n");
                    }else{
                        return 1;
                    }
                }while(achou_usuario != true && idUsuario != 0);
            }else{
                printf("Nome  n�o encontrado!\n");
                printf("Deseja busc�-lo novamente ? (S para SIM / N para N�O): ");
                buscar_novamente = getche();
            }
        }else{
            return 1;
        }
    }while(toupper(buscar_novamente) == 'S');

    return 0;
}

void view_AlterarUsuarioPorUSER(USER usuario){
    USER usuarioAlterado = usuario;
    char alterar_novamente = 'N';
    char salvarDadosAlterados = 'N';
    int opcao = 0;
    bool dadosAlterados = false;

    do{
        alterar_novamente = 'N';
        system("cls");
        printf("C�digo do funcion�rio: %d\n", usuario.id);
        printf("  1 - Nome: %s\n", usuario.nome);
        printf("  2 - Sobrenome: %s\n", usuario.sobrenome);
        printf("  3 - CPF: %s\n", usuario.CPF);
        printf("  4 - Data de nascimento: %s\n", DateToString(usuario.dt_nascimento));
        printf("  5 - Sal�rio: %.2f\n", usuario.salario);
        printf("  6 - Cargo: %s\n", usuario.cargo);
        printf("  7 - Endere�o: %s\n", usuario.endereco);
        printf("  8 - N�mero: %d\n", usuario.numeroDaCasa);
        printf("  9 - Bairro: %s\n", usuario.bairro);
        printf(" 10  - Cidade: %s\n", usuario.cidade);
        printf(" 11 - UF: %s\n", usuario.endereco);
        printf(" 12 - Login: %s\n", usuario.login);
        printf(" 13 - Senha\n");
        printf("  0 - Voltar\n");
        printf("Qual informa��o deseja alterar ? ");
        scanf("%d", &opcao);

        fflush(stdin);
        if(opcao != 0){
            dadosAlterados = true;
            switch(opcao){
                case 1:
                    printf("Nome: ");
                    gets(usuarioAlterado.nome);
                    break;
                case 2:
                    printf("Sobrenome: ");
                    gets(usuarioAlterado.sobrenome);
                    break;
                case 3:
                    printf("CPF (sem pontua��o): ");
                    gets(usuarioAlterado.CPF);
                    break;
                case 4:
                    printf("Data de nascimento: \n");
                    printf("	Dia: ");
                    scanf("%d", &usuarioAlterado.dt_nascimento.dia);
                    printf("	M�s: ");
                    scanf("%d", &usuarioAlterado.dt_nascimento.mes);
                    printf("	Ano: ");
                    scanf("%d", &usuarioAlterado.dt_nascimento.ano);
                    break;
                case 5:
                    printf("Sal�rio: ");
                    scanf("%f", &usuarioAlterado.salario);
                    break;
                case 6:
                    printf("Cargo: ");
                    gets(usuarioAlterado.cargo);
                    break;
                case 7:
                    printf("Endere�o: ");
                    gets(usuarioAlterado.endereco);
                    break;
                case 8:
                    printf("N�mero: ");
                    scanf("%d", &usuarioAlterado.numeroDaCasa);
                    break;
                case 9:
                    printf("Bairro: ");
                    gets(usuarioAlterado.bairro);
                    break;
                case 10:
                    printf("Cidade: ");
                    gets(usuarioAlterado.cidade);
                    break;
                case 11:
                    printf("UF: ");
                    gets(usuarioAlterado.estado);
                    break;
                case 12:
                    printf("Login: ");
                    gets(usuarioAlterado.login);
                    break;
                case 13:
                    printf("Senha: ");
                    gets(usuario.senha);
                    break;
            }

            printf("Deseja alterar outra informa��o ? (S para SIM / N para N�O): ");
            alterar_novamente = getche();
            printf("\n");
        }

    }while(opcao != 0 && toupper(alterar_novamente) == 'S');

    if(dadosAlterados == true && opcao == 0){
        printf("Alguns dados foram alterados, deseja salvar ? (S para SIM / N para N�O): ");
        salvarDadosAlterados = getche();
    }

    if(opcao != 0 || toupper(salvarDadosAlterados) == 'S'){
        alterarFuncionarioDAO(usuarioAlterado);
    }
}
