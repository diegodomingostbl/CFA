#include <stdio.h>
#include <locale.h>
#include <ctype.h>

#include "telaMenu.h";
#include "funcoes.h";
#include "dao_usuario.h";
#include "view_usuario.h";
#include "dao_veiculo.h"
#include "view_veiculo.h"
#include "dao_residencia.h"
#include "view_residencia.h"
#include "struct.h"

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
        printf("Escolha um menu: ");
        scanf("%i", &menu);
        switch (menu){
            case 0:
                    realizarLogout();
                    break;
            case 1:
                menuCadastro();
                break;
            case 2:
                menuAlterar();
                break;
            case 3:
                menuRelatorio();
                break;
            case 4:
                //entradavisitante;
                system("cls");
                fflush(stdin);
                printf("Entrada de visitante");
                break;
        }
    }while(menu != 0);
}

void menuCadastro(){
    int menucadastro;
    do{
        system("cls");
        fflush(stdin);
        printf("MENU - Cadastro \n");
        printf(" 1 - Funcion�rios\n");
        printf(" 2 - Resid�ncia\n");
        printf(" 3 - Ve�culo\n");
        printf(" 4 - Contas a pagar\n");
        printf(" 5 - Contas a receber\n");
        printf(" 0 - Voltar\n");
        printf("Escolha um menu: ");
        scanf("%d", &menucadastro);
        switch (menucadastro){
            case 0:
                return;
                break;
            case 1:
                cadastrarFuncionario();
                break;
            case 2:
                cadastrarResidencia();
                break;
            case 3:
                cadastrarVeiculo();
                break;
            case 4:
                //Cadastro de contas a pagar
                system("cls");
                fflush(stdin);
                printf(" Cadastro de contas a pagar\n");
                break;
            case 5:
                //Cadastro de contas a receber
                system("cls");
                fflush(stdin);
                printf(" Cadastro de contas a receber\n");
                break;
        }
    }while(menucadastro != 0);
}

void menuAlterar(){
    int menualterar;
    do{
        system("cls");
        fflush(stdin);
        printf("MENU - Alterar\n");
        printf(" 1 - Funcion�rio\n");
        printf(" 2 - Resid�ncia\n");
        printf(" 3 - Ve�culo\n");
        printf(" 4 - Conta a pagar\n");
        printf(" 5 - Conta a receber\n");
        printf(" 0 - Voltar\n");
        printf("Escolha um menu: ");
        scanf("%d", &menualterar);
        switch (menualterar){
            case 0:
                return;
                break;
            case 1:
                system("cls");
                alterarFuncionario();
                break;
            case 2:
                alterarResidencia();
                break;
            case 3:
                alterarVeiculo();
                break;
            case 4:
                //Alteração de conta a pagar
                system("cls");
                printf("Alteração de contas a pagar");
                break;
            case 5:
                //Alteração de conta a receber
                system("cls");
                printf("Alteração de conta a receber");
                break;
        }
    }while(menualterar != 0);
}

void menuRelatorio(){
    int menurelatorio;
    do{
        system("cls");
        fflush(stdin);
        printf(" MENU - Relat�rio \n");
        printf(" 1 - Funcion�rio\n");
        printf(" 2 - Resid�ncia\n");
        printf(" 3 - Ve�culo\n");
        printf(" 4 - Contas a pagar\n");
        printf(" 5 - Contas a receber\n");
        printf(" 6 - Balan�o mensal\n");
        printf(" 7 - Balan�o anual\n");
        printf(" 8 - Entrada e sa�da de visitantes por m�s\n");
        printf(" 0 - Voltar\n");
        printf("Escolha um menu: ");
        scanf("%d", &menurelatorio);
        switch (menurelatorio){
            case 1: {
                relatorioFuncionario();
                break;
            }
            case 2: {
                relatorioResidencia();
                break;
            }
            case 3: {
                relatorioVeiculo();
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
    }while(menurelatorio != 0);
}

void cadastrarFuncionario(){
	USER usuario;

    system("cls");
    fflush(stdin);
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
    int repetir = 0;

    do{
        system("cls");
        printf("Alterar funcion�rio\n");
        printf("Deseja buscar o funcion�rio por: \n");
        printf(" 1 - C�digo interno\n");
        printf(" 2 - CPF\n");
        printf(" 3 - Login\n");
        printf(" 4 - Nome\n");
        printf(" 0 - Voltar\n");
        printf("Digite uma das op��es acima: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao){
            case 0:
                return;
                break;
            case 1:
                repetir = alterarFuncionarioPorID();
                break;
            case 2:
                repetir = alterarFuncionarioPorCPF();
                break;
            case 3:
                repetir = alterarFuncionarioPorLogin();
                break;
            case 4:
                repetir = alterarFuncionarioPorNome();
                break;
            default:
                printf("Op��o inv�lida\n");
        }
    }while(opcao != 0 && repetir == 1);

}

void relatorioFuncionario(){
    int opcao;
    int repetir = 0;

    do{
        system("cls");
        printf("Relat�rio de funcion�rio\n");
        printf("Deseja buscar por: \n");
        printf(" 1 - Nome\n");
        printf(" 2 - Data de cadastro\n");
        printf(" 3 - Data de nascimento\n");
        printf(" 0 - Voltar\n");
        printf("Digite uma das op��es acima: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao){
            case 0:
                return;
                break;
            case 1:
                repetir = view_relatorioFuncionarioPorNome();
                break;
            case 2:
                repetir = view_relatorioFuncionarioPorDataCadastro();
                break;
            case 3:
                repetir = view_relatorioFuncionarioPorDataNascimento();
                break;
        }
    }while(opcao != 0 && repetir == 1);
}

void entradaVisitante(){
}

void cadastrarVeiculo(){
    VEICULO veiculo;

    system("cls");
    fflush(stdin);
	printf("Cadastro de veiculo\n");
    printf("Placa: ");
    gets(veiculo.placa);
    printf("Modelo:");
    gets(veiculo.modelo);
    printf("Cor:");
    gets(veiculo.cor);
    printf("C�digo da casa: ");
    scanf("%d", &veiculo.idcasa);

    view_gravarVeiculo(veiculo);
}

void alterarVeiculo(){
    int opcao;
    int repetir = 0;

    do{
        system("cls");
        printf("Alterar veiculo\n");
        printf("Deseja buscar o veiculo por: \n");
        printf(" 1 - C�digo interno do veiculo\n");
        printf(" 2 - Placa\n");
        printf(" 3 - Casa\n");
        printf(" 0 - Voltar\n");
        printf("Digite uma das op��es acima: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao){
            case 0:
                return;
                break;
            case 1:
                repetir = view_alterarVeiculoPorID();
                break;
            case 2:
                repetir = view_alterarVeiculoPorPlaca();
                break;
            case 3:
                repetir = view_alterarVeiculoPorCasa();
                break;
            default:
                printf("Op��o inv�lida\n");
        }
    }while(opcao != 0 && repetir == 1);
}

void relatorioVeiculo(){
    int opcao;
    int repetir = 0;

    do{
        system("cls");
        printf("Relat�rio de ve�culo\n");
        printf("Deseja buscar por: \n");
        printf(" 1 - Casa\n");
        printf(" 2 - Todos\n");
        printf(" 0 - Voltar\n");
        printf("Digite uma das op��es acima: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao){
            case 0:
                return;
                break;
            case 1:
                repetir = view_relatorioVeiculoPorCasa();
                break;
            case 2:
                repetir = view_relatorioVeiculos();
                break;
        }
    }while(opcao != 0 && repetir == 1);
}

void cadastrarResidencia(){
    RESIDENCIA residencia;

    system("cls");
    fflush(stdin);
	printf("Cadastro de resid�ncia\n");
    printf("Endere�o: ");
    gets(residencia.endereco);
    printf("N�mero da resid�ncia: ");
    scanf("%d", &residencia.numero_casa);
    fflush(stdin);
    printf("Bloco: ");
    gets(residencia.bloco);

    view_gravarResidencia(residencia);
}

void alterarResidencia(){
    int opcao;
    int repetir = 0;

    do{
        system("cls");
        printf("Alterar resid�ncia\n");
        printf("Deseja buscar o resid�ncia por: \n");
        printf(" 1 - C�digo interno\n");
        printf(" 2 - N�mero\n");
        printf(" 3 - Bloco\n");
        printf(" 0 - Voltar\n");
        printf("Digite uma das op��es acima: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao){
            case 0:
                return;
                break;
            case 1:
                repetir = view_alterarResidenciaPorID();
                break;
            case 2:
                repetir = view_alterarResidenciaPorNumero();
                break;
            case 3:
                repetir = view_alterarResidenciaPorBloco();
                break;
            default:
                printf("Op��o inv�lida\n");
        }
    }while(opcao != 0 && repetir == 1);
}

void relatorioResidencia(){
    int opcao;
    int repetir = 0;

    do{
        system("cls");
        printf("Relat�rio de resid�ncia\n");
        printf("Deseja buscar por: \n");
        printf(" 1 - N�mero\n");
        printf(" 2 - Bloco\n");
        printf(" 3 - Todos\n");
        printf(" 0 - Voltar\n");
        printf("Digite uma das op��es acima: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao){
            case 0:
                return;
                break;
            case 1:
                repetir = view_relatorioResidenciaPorNumero();
                break;
            case 2:
                repetir = view_relatorioResidenciaPorBloco();
                break;
            case 3:
                repetir = view_relatorioResidencias();
                break;
        }
    }while(opcao != 0 && repetir == 1);
}
