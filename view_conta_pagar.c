#include <stdio.h>
#include <stdlib.h>

#include "view_conta_pagar.h"
#include "dao_conta_pagar.h"
#include "funcoes.h"

void view_gravarContaPagar(C_PAGAR conta_pagar){
    conta_pagar.id = dao_retornaUltimoIdContaPagar() + 1;

    dao_gravarContaPagar(conta_pagar);
}

int view_alterarContaPagarPorID(){
    int id_conta_pagar = 0;
    C_PAGAR conta_pagar;
    char buscar_novamente = 'N';

    do{
        fflush(stdin);
        system("cls");
        printf("Alterar conta a pagar\n");
        printf("Digite 0 (zero) para voltar\n");
        printf("Digite o c�digo interno (ID): ");
        scanf("%d", &id_conta_pagar);

        if(id_conta_pagar > 0){
            conta_pagar = dao_procurarContaPagarId(id_conta_pagar);
            if(conta_pagar.id > 0){
                view_alterarContaPagar(conta_pagar);
            }else{
                printf("Conta a pagar n�o encontrado!\n");
                printf("Deseja busc�-lo novamente ? (S para SIM / N para N�O): ");
                buscar_novamente = getche();
            }
        }else{
            return 1;
        }
    }while(toupper(buscar_novamente) == 'S');

    return 0;
}

void view_alterarContaPagar(C_PAGAR conta_pagar){
    C_PAGAR conta_pagar_alterada = conta_pagar;
    char alterar_novamente = 'N';
    char salvarDadosAlterados = 'N';
    int opcao = 0;
    bool dadosAlterados = false;

    do{
        alterar_novamente = 'N';
        system("cls");
        printf("C�digo da conta a pagar: %d\n", conta_pagar.id);
        printf("  1 - Nome: %s\n", conta_pagar.nome);
        printf("  2 - Data de vencimento: %s\n", DateToString(conta_pagar.dt_vencimento));
        printf("  3 - Valor: %.2f\n", conta_pagar.valor);
        printf("  0 - Voltar\n");
        printf("Qual informa��o deseja alterar ? ");
        scanf("%d", &opcao);

        fflush(stdin);
        if(opcao != 0){
            dadosAlterados = true;
            switch(opcao){
                case 1:
                    fflush(stdin);
                    printf("Nome: ");
                    gets(conta_pagar_alterada.nome);
                    break;
                case 2:
                    fflush(stdin);
                    printf("Data de vencimento: \n");
                    printf("	Dia: ");
                    scanf("%d", &conta_pagar_alterada.dt_vencimento.dia);
                    printf("	M�s: ");
                    scanf("%d", &conta_pagar_alterada.dt_vencimento.mes);
                    printf("	Ano: ");
                    scanf("%d", &conta_pagar_alterada.dt_vencimento.ano);
                    break;
                case 3:
                    printf("Valor: R$ ");
                    scanf("%f", &conta_pagar_alterada.valor);
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
        dao_alterarContaPagar(conta_pagar_alterada);
    }
}


int view_relatorioContaPagarPorDataVencimento(){
    C_PAGAR* conta_pagar;
    int qtdContaPagar = 0;
    char buscar_novamente = 'N';
    char gravar = 'N';
    char nome_arquivo[100];
    DATEC data;
    DATEC data_inicial;
    DATEC data_final;


    do{
        buscar_novamente = 'N';
        system("cls");
        fflush(stdin);
        printf("Relat�rio de contas a pagar por data de vencimento\n");
        printf("Digite 0 (zero) para voltar\n");
        printf("Digite o per�odo inicial: \n");
        printf("	Dia: ");
        scanf("%d", &data_inicial.dia);
        if(data_inicial.dia == 0) return 1;
        printf("	M�s: ");
        scanf("%d", &data_inicial.mes);
        if(data_inicial.mes == 0) return 1;
        printf("	Ano: ");
        scanf("%d", &data_inicial.ano);
        if(data_inicial.ano == 0) return 1;
        printf("Digite o per�odo final: \n");
        printf("	Dia: ");
        scanf("%d", &data_final.dia);
        if(data_final.dia == 0) return 1;
        printf("	M�s: ");
        scanf("%d", &data_final.mes);
        if(data_final.mes == 0) return 1;
        printf("	Ano: ");
        scanf("%d", &data_final.ano);
        if(data_final.ano == 0) return 1;

        if(validarPeriodoInicialFinal(data_inicial, data_final) == true){
            conta_pagar = dao_procuraContaPagarDataVencimento(data_inicial, data_final, &qtdContaPagar);

            if(qtdContaPagar > 0){
                printf("Foram encontrados %d contas a pagar\n", qtdContaPagar);
                printf("%-5s | %-20s | %-17s | %-10s\n", "ID", "NOME", "DATA VENCIMENTO", "VALOR");

                for(int i = 0; i < qtdContaPagar; i++){
                    printf("%-5d | %-20s | %-17s | %-10.2f\n", (conta_pagar + i)->id, (conta_pagar + i)->nome, DateToString((conta_pagar + i)->dt_vencimento), (conta_pagar + i)->valor);
                }
                printf("Deseja salvar o relat�rio ? (S para SIM / N para N�O): ");
                gravar = getche();
                printf("\n");
                if(toupper(gravar) == 'S'){
                    strcpy(nome_arquivo, "Contas a pagar no per�odo");
                    strcat(nome_arquivo, " - ");
                    strcat(nome_arquivo, IntToString(data_inicial.dia));
                    strcat(nome_arquivo, "-");
                    strcat(nome_arquivo, IntToString(data_inicial.mes));
                    strcat(nome_arquivo, "-");
                    strcat(nome_arquivo, IntToString(data_inicial.ano));
                    strcat(nome_arquivo, " a ");
                    strcat(nome_arquivo, IntToString(data_final.dia));
                    strcat(nome_arquivo, "-");
                    strcat(nome_arquivo, IntToString(data_final.mes));
                    strcat(nome_arquivo, "-");
                    strcat(nome_arquivo, IntToString(data_final.ano));
                    dao_gravarRelatorioContaPagar(conta_pagar, qtdContaPagar, nome_arquivo);
                }
            }else{
                printf("N�o foram encontradas contas a pagar neste per�odo!\n");
                printf("Deseja busc�-la novamente ? (S para SIM / N para N�O): ");
                buscar_novamente = getche();
            }
        }else{
            buscar_novamente = 'S';
            printf("Per�odo de datas inv�lido!\n");
            system("PAUSE");
            return 1;
        }
    }while(toupper(buscar_novamente) == 'S');

    return 0;
}
