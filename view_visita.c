#include <stdio.h>
#include <stdlib.h>

#include "view_visita.h"
#include "dao_visita.h"
#include "funcoes.h"
#include "struct.h"

void view_gravarVisitaVeiculo(E_VEICULO veiculo){
    veiculo.id = dao_retornaUltimoIdEntradaVeiculo() + 1;
    veiculo.data_entrada = retornaDataAtual();

    dao_gravarVisitaVeiculo(veiculo);
}

void view_gravarVisitaPessoa(E_PESSOA pessoa){
    pessoa.id = dao_retornaUltimoIdEntradaPessoa() + 1;
    pessoa.data_entrada = retornaDataAtual();

    dao_gravarVisitaPessoa(pessoa);
}

int view_relatorioVisitaPessoa(){
    E_PESSOA* pessoa;
    int qtdPessoa = 0;
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
        printf("Relat�rio de visita no per�odo\n");
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
            pessoa = dao_procuraVisitaPessoaData(data_inicial, data_final, &qtdPessoa);

            if(qtdPessoa > 0){
                printf("\nForam encontradas %d visitas de pessoas\n", qtdPessoa);
                printf("%-5s | %-12s | %-30s | %-15s | %-12s\n", "ID", "RESID�NCIA", "NOME COMPLETO", "CPF", "DATA DE ENTRADA");

                for(int i = 0; i < qtdPessoa; i++){
                    printf("%-5d | %-12d | %-30s | %-15s | %-12s\n", (pessoa + i)->id, (pessoa + i)->visitando_residencia, (pessoa + i)->nomeSobrenome, (pessoa + i)->CPF, DateToString((pessoa + i)->data_entrada));
                }
                printf("Deseja salvar o relat�rio ? (S para SIM / N para N�O): ");
                gravar = getche();
                printf("\n");
                if(toupper(gravar) == 'S'){
                    strcpy(nome_arquivo, "Visitas de pessoa no per�odo");
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
                    dao_gravarRelatorioVisitaPessoa(pessoa, qtdPessoa, nome_arquivo);
                }
            }else{
                printf("N�o foram encontradas visitas neste per�odo!\n");
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
/*
int view_relatorioVisitaVeiculo(){
    E_VEICULO* veiculo;
    int qtdVeiculo = 0;
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
        printf("Relat�rio de visita com ve�culo no per�odo\n");
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
            veiculo = dao_procuraVisitaVeiculoData(data_inicial, data_final, &qtdVeiculo);

            if(qtdVeiculo > 0){
                printf("\nForam encontradas %d visitas de pessoas\n", qtdVeiculo);
                printf("%-5s | %-12s | %-30s | %-15s | %-12s\n", "ID", "RESID�NCIA", "NOME COMPLETO", "CPF", "DATA DE ENTRADA");

                for(int i = 0; i < qtdVeiculo; i++){
                    printf("%-5d | %-12d | %-30s | %-15s | %-12s\n", (veiculo + i)->id, (veiculo + i)->visitando_residencia, (veiculo + i)->nomeSobrenomeMotorista, (veiculo + i)->CPF, DateToString((veiculo + i)->data_entrada));
                }
                printf("Deseja salvar o relat�rio ? (S para SIM / N para N�O): ");
                gravar = getche();
                printf("\n");
                if(toupper(gravar) == 'S'){
                    strcpy(nome_arquivo, "Visitas de pessoa com ve�culo no per�odo");
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
                    dao_gravarRelatorioVisitaPessoa(veiculo, qtdVeiculo, nome_arquivo);
                }
            }else{
                printf("N�o foram encontradas visitas com ve�culo neste per�odo!\n");
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
}*/

