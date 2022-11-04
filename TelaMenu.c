#include <stdio.h>
#include <locale.h>
#include <ctype.h>

#include "telaMenu.h";
#include "funcoes.h";
#include "dao_usuario.h";
#include "view_usuario.h";

void menu(){
    setlocale(LC_ALL, "Portuguese");
    int menu;
    do{
        system("cls");
        printf("CFA - Controle de fluxo automotivo\n");
        printf("[1] - Cadastro\n");
        printf("[2] - Altera��o de cadastro\n");
        printf("[3] - Relat�rios\n");
        printf("[4] - Entrada de visitante\n");
        printf("[0] - Logout\n");
        printf("Escolha um menu: : ");
        scanf("%i", &menu);
        switch (menu){
            case 0:
                    realizarLogout();
                    break;
            case 1: {
                //Cadastro
                int menucadastro;
                do{
                    system("cls");
                    fflush(stdin);
                    printf(" Escolha que deseja cadastrar\n");
                    printf(" [1] Funcionários\n");
                    printf(" [2] Casa\n");
                    printf(" [3] Veículo\n");
                    printf(" [4] Contas a pagar\n");
                    printf(" [5] Contas a receber\n");
                    printf(" [6] Voltar ao menu inicial\n");
                    printf("  ");
                    scanf("%i", &menucadastro);
                    switch (menucadastro){
                        case 1: {
                            //Cadastro d funcionario falta entra com uma função
                            system("cls");
                            fflush(stdin);
                            printf(" Cadastro de funcionário\n");
                            break;
                        }
                        case 2: {
                            //Cadastro de casa falta entra com uma função
                            system("cls");
                            fflush(stdin);
                            printf(" Cadastro de casa\n");
                            break;
                        }
                        case 3: {
                            //Cadastro d veiculo
                            system("cls");
                            fflush(stdin);
                            printf(" Cadastro de veículo\n");
                            break;
                        }
                        case 4: {
                            //Cadastro de contas a pagar
                            system("cls");
                            fflush(stdin);
                            printf(" Cadastro de contas a pagar\n");
                            break;
                        }
                        case 5:{
                            //Cadastro de contas a receber
                            system("cls");
                            fflush(stdin);
                            printf(" Cadastro de contas a receber\n");
                            break;
                        }
                        case 6: {
                            //Voltar
                            system("cls");
                            fflush(stdin);
                            break;
                        }
                        default: {
                            //Numero invalido
                            system("cls");
                            printf("Numero inválido");
                            break;
                        }
                    }
                }while(menucadastro < 1 || menucadastro >= 6);
                break;
            }
                case 2: {
                    //Alteração de cadastro
                    int menualterar;
                    system("cls");
                    fflush(stdin);
                    do{

                        printf(" Escolha o que deseja alterar \n");
                        printf(" [1] Dados de funcionário\n");
                        printf(" [2] Dados de casa\n");
                        printf(" [3] Dados de veículo\n");
                        printf(" [4] Dados de conta a pagar\n");
                        printf (" [5] Dados de conta a receber\n");
                        printf(" [6] Voltar");
                        printf ("  ");
                        scanf("%i", &menualterar);
                        switch (menualterar){
                            case 1: {
                                //Alteração de funcionarios
                                system("cls");
                                alterarFuncionario();
                                break;
                            }
                            case 2: {
                                //Alterção dos dados da casa
                                system("cls");
                                printf("Alteração de casa");
                                break;
                            }
                            case 3: {
                                //Alteração de veículo
                                system("cls");
                                printf("Alteração de veículos");
                                break;
                            }
                            case 4: {
                                //Alteração de conta a pagar
                                system("cls");
                                printf("Alteração de contas a pagar");
                                break;
                            }
                            case 5: {
                                //Alteração de conta a receber
                                system("cls");
                                printf("Alteração de conta a receber");
                                break;
                            }
                            case 6: {
                                printf("Voltar");
                                break;
                            }
                            default:{
                                system("cls");
                                printf("***ERRO***");
                                printf("Opção inválida tente novamente");
                            }
                        }
                    }while(menualterar < 1 || menualterar >= 6);
                    break;
                }
                case 3:{
                    //relatorio;
                    int menurelatorio;
                        system("cls");
                        fflush(stdin);
                        do{

                            printf(" Escolha qual relatorio deseja visualizar \n");
                            printf(" [1] Funcionários\n");
                            printf(" [2] Casas\n");
                            printf(" [3] Veículos por casa\n");
                            printf(" [4] Contas a pagar\n");
                            printf(" [5] Contas a receber\n");
                            printf(" [6] Balanço mensal\n");
                            printf(" [7] Balanço anual\n");
                            printf(" [8] Entrada e saída de visitantes por mês\n");
                            printf(" [9] Voltar\n");
                            printf ("  ");
                            scanf("%i", &menurelatorio);
                            switch (menurelatorio){
                                case 1: {
                                    //Alteração de funcionarios
                                    system("cls");
                                    printf("Relatório de funcionários");
                                    break;
                                }
                                case 2: {
                                    //Alterção dos dados da casa
                                    system("cls");
                                    printf("Relatório de casa");
                                    break;
                                }
                                case 3: {
                                    //Alteração de veículo
                                    system("cls");
                                    printf("Relatório de veículos por casa");
                                    break;
                                }
                                case 4: {
                                    //Alteração de conta a pagar
                                    system("cls");
                                    printf("Relatório de contas a pagar");
                                    break;
                                }
                                case 5: {
                                    //Alteração de conta a receber
                                    system("cls");
                                    printf("Relatório de conta a receber");
                                    break;
                                }
                                case 6: {
                                    system("cls");
                                    printf("Relatório de balanço mensal");
                                    break;
                                }
                                case 7:{
                                    system("cls");
                                    printf("Relatório de balanço anual");
                                    break;
                                }
                                case 8:{
                                    system("cls");
                                    printf("Relatório de entrada e saída por mês");
                                    break;
                                }
                                case 9:{
                                    system("cls");
                                    printf("Voltar");
                                    break;
                                }
                                default:{
                                    system("cls");
                                    printf("***ERRO***");
                                    printf("Opção inválida tente novamente");
                                }
                            }
                        }while(menurelatorio < 1 || menurelatorio >= 9);
                        break;
                }
                case 4:{
                    //entradavisitante;
                    system("cls");
                    fflush(stdin);
                    printf("Entrada de visitante");
                    break;
                }
                default: {
                    //Caso o menu selecionado seja invalido
                    system("cls");
                    fflush(stdin);
                    printf ("\n***Comando invalido***\n\n");
                }
            }
    }while(menu != 0);
}

int cadastrarFuncionario(){
	USER usuario;

	printf("Cadastro de funcion�rio\n");
	printf("Nome: ");
	gets(usuario.nome);
	printf("Sobrenome: ");
	gets(usuario.sobrenome);
	printf("CPF (sem pontua��o)");
	gets(usuario.CPF);
	printf("Data de nascimento: \n");
	printf("	Dia: ");
	scanf("%d", &usuario.dt_nascimento.dia);
	printf("	M�s: ");
	scanf("%d", &usuario.dt_nascimento.mes);
	printf("	Ano: ");
	scanf("%d", &usuario.dt_nascimento.ano);
	printf("Sal�rio: ");
	scanf("%f", &usuario.salario);
	printf("Cargo: ");
	gets(usuario.cargo);
	printf("Endere�o: ");
	gets(usuario.endereco);
	printf("N�mero: ");
	scanf("%d", &usuario.numeroDaCasa);
	printf("Bairro: ");
	gets(usuario.bairro);
	printf("Cidade: ");
	gets(usuario.cidade);
	printf("UF: ");
	gets(usuario.estado);
	printf("Login: ");
	gets(usuario.login);
	printf("Senha: ");
	gets(usuario.senha);
	usuario.dt_cadastro = retornaDataAtual();
    usuario.id = retornaUltimoIdUsuario() + 1;

    gravarUsuario(usuario);
}

void alterarFuncionario(){
    int opcao;
    int repitir = 0;

    do{
        system("cls");
        printf("Alterar funcion�rio\n");
        printf("Deseja buscar o funcion�rio por: \n");
        printf("[1] - C�digo interno\n");
        printf("[2] - CPF\n");
        printf("[3] - Login\n");
        printf("[4] - Nome\n");
        printf("[0] - Voltar\n");
        printf("Digite uma das op��es acima: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao){
            case 0:
                return;
                break;
            case 1: //Buscar usuario por id
                repitir = alterarFuncionarioPorID();
                break;
            case 2:
                //buscar por cpf
                break;
            case 3:
                //buscar por login
                break;
            case 4:
                //buscar por nome
                break;
            default:
                printf("Op��o inv�lida\n");
        }
    }while(opcao != 0 || repitir == 1);
}
