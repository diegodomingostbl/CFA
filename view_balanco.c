#include <stdio.h>
#include <stdlib.h>

#include "view_balanco.h"
#include "dao_balanco.h"
#include "funcoes.h"

int view_relatorioBalancoPorPeriodo(){
    C_PAGAR* conta_pagar;
    C_RECEBER* conta_receber;
    int qtdContaPagar = 0;
    int qtdContaReceber = 0;
    char buscar_novamente = 'N';
    char gravar = 'N';
    char nome_arquivo[100];
    DATEC data;
    DATEC data_inicial;
    DATEC data_final;
    int i = 0;
    float totalContaPagar = 0;
    float totalContaReceber = 0;

    do{
        buscar_novamente = 'N';
        system("cls");
        fflush(stdin);
        printf("Balan�o no per�odo\n");
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
            conta_receber = dao_procuraContaReceberDataVencimento(data_inicial, data_final, &qtdContaReceber);

            if(qtdContaPagar > 0 || qtdContaReceber > 0){
                for(i = 0; i < qtdContaPagar; i++){
                    totalContaPagar += (conta_pagar + i)->valor;
                }

                for(i = 0; i < qtdContaReceber; i++){
                    totalContaReceber += (conta_receber + i)->valor;
                }

                printf("Foram encontradas %d contas\n", qtdContaPagar + qtdContaReceber);
                printf("Per�odo de %s a %s\n\n", DateToString(data_inicial), DateToString(data_final));
                printf("Quantidade de contas a pagar: %d\n", qtdContaPagar);
                printf("Valor total de contas a pagar: %.2f\n", totalContaPagar);
                printf("Quantidade de contas a receber: %d\n", qtdContaReceber);
                printf("Valor total de contas a receber: %.2f\n\n", totalContaReceber);

                printf("Balan�o no per�odo: %.2f\n\n", totalContaReceber - totalContaPagar);

                printf("Deseja salvar o relat�rio ? (S para SIM / N para N�O): ");
                gravar = getche();
                printf("\n");
                if(toupper(gravar) == 'S'){
                    strcpy(nome_arquivo, "Balanco-periodo");
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
                    dao_gravarBalancoPeriodo(totalContaPagar, qtdContaPagar, totalContaReceber, qtdContaReceber, nome_arquivo);
                }
            }else{
                printf("N�o foram encontradas contas neste per�odo!\n");
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
