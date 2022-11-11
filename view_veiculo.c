#include <stdio.h>

#include "view_veiculo.h"
#include "dao_veiculo.h"
#include "funcoes.h"
#include "struct.h"


void view_gravarVeiculo(VEICULO veiculo){
    veiculo.id = dao_retornaUltimoIdVeiculo() + 1;
    strcpy(veiculo.placa, toUpperString(veiculo.placa));

    dao_gravarVeiculo(veiculo);
}

int view_alterarVeiculoPorID(){
    int id_veiculo = 0;
    VEICULO veiculo;
    char buscar_novamente = 'N';

    do{
        fflush(stdin);
        system("cls");
        printf("Alterar veículo\n");
        printf("Digite 0 (zero) para voltar\n");
        printf("Digite o código interno do veículo: ");
        scanf("%d", &id_veiculo);

        if(id_veiculo > 0){
            veiculo = dao_procurarVeiculoId(id_veiculo);
            if(veiculo.id > 0){
                view_alterarVeiculo(veiculo);
            }else{
                printf("Veículo não encontrado!\n");
                printf("Deseja buscá-lo novamente ? (S para SIM / N para NÃO): ");
                buscar_novamente = getche();
            }
        }else{
            return 1;
        }
    }while(toupper(buscar_novamente) == 'S');

    return 0;
}

int view_alterarVeiculoPorPlaca(){
    char placa[8];
    VEICULO veiculo;
    char buscar_novamente = 'N';

    do{
        fflush(stdin);
        system("cls");
        buscar_novamente = 'N';

        printf("Alterar veículo\n");
        printf("Digite 0 (zero) para voltar\n");
        printf("Digite a placa do veículo: ");
        gets(placa);

        if(placa != '0'){
            veiculo = dao_procurarVeiculoPlaca(placa);
            if(veiculo.id > 0){
                view_alterarVeiculo(veiculo);
            }else{
                printf("Veículo não encontrado!\n");
                printf("Deseja buscá-lo novamente ? (S para SIM / N para NÃO): ");
                buscar_novamente = getche();
            }
        }else{
            return 1;
        }
    }while(toupper(buscar_novamente) == 'S');

    return 0;
}

int view_alterarVeiculoPorCasa(){
    int id_casa = 0;
    int id_veiculo = 0;
    VEICULO* veiculo;
    char buscar_novamente = 'N';
    int qtdVeiculo = 0;
    bool achou_usuario = false;

    do{
        fflush(stdin);
        system("cls");
        buscar_novamente = 'N';

        printf("Alterar veículo\n");
        printf("Digite 0 (zero) para voltar\n");
        printf("Digite a casa para buscar o veículo: ");
        scanf("%d", &id_casa);

        if(id_casa > 0){
            veiculo = dao_procurarVeiculoCasa(id_casa, &qtdVeiculo);
            if(qtdVeiculo == 1){
                view_alterarVeiculo(*(veiculo + 0));
            }else if(qtdVeiculo > 1){
                do{
                    printf("Foram encontrados %d veículos\n", qtdVeiculo);
                    printf("%-5s | %-5s | %-9s | %-25s | %-8s \n", "ID", "CASA", "PLACA", "MODELO", "COR");

                    for(int i = 0; i < qtdVeiculo; i++){
                        printf("%-5d | %-5d | %-9s | %-25s | %-8s \n", (veiculo + i)->id, (veiculo + i)->idcasa, (veiculo + i)->placa, (veiculo + i)->modelo, (veiculo + i)->cor);
                    }

                    printf("Digite 0 (zero) para voltar\n");
                    printf("Digite o ID: ");
                    scanf("%d", &id_veiculo);

                    if(id_veiculo != 0){
                        for(int i = 0; i < qtdVeiculo; i++){
                            if((veiculo + i)->id == id_veiculo){
                                achou_usuario = true;
                                view_alterarVeiculo(*(veiculo + i));
                                return 0;
                            }
                        }
                        system("cls");
                        printf("Identificado (ID) inválido, escolha uns dos identificadores abaixo\n");
                    }else{
                        return 1;
                    }
                }while(achou_usuario != true && id_veiculo != 0);
            }else{
                printf("Veículo não encontrado!\n");
                printf("Deseja buscá-lo novamente ? (S para SIM / N para NÃO): ");
                buscar_novamente = getche();
            }
        }else{
            return 1;
        }
    }while(toupper(buscar_novamente) == 'S');

    return 0;
}

void view_alterarVeiculo(VEICULO veiculo){
    VEICULO veiculoAlterado = veiculo;
    char alterar_novamente = 'N';
    char salvarDadosAlterados = 'N';
    int opcao = 0;
    bool dadosAlterados = false;

    do{
        alterar_novamente = 'N';
        system("cls");
        printf("Código do veículo: %d\n", veiculo.id);
        printf("  1 - Casa: %d\n", veiculo.idcasa);
        printf("  2 - Placa: %s\n", veiculo.placa);
        printf("  3 - Modelo: %s\n", veiculo.modelo);
        printf("  4 - Cor: %s\n", veiculo.cor);
        printf("  0 - Voltar\n");
        printf("Qual informação deseja alterar ? ");
        scanf("%d", &opcao);

        fflush(stdin);
        if(opcao != 0){
            dadosAlterados = true;
            switch(opcao){
                case 1:
                    printf("Casa: ");
                    scanf("%d", &veiculoAlterado.idcasa);
                    break;
                case 2:
                    printf("Placa: ");
                    gets(veiculoAlterado.placa);
                    break;
                case 3:
                    printf("Modelo: ");
                    gets(veiculoAlterado.modelo);
                    break;
                case 4:
                    printf("Cor: ");
                    gets(veiculoAlterado.cor);
                    break;
            }

            printf("Deseja alterar outra informação ? (S para SIM / N para NÃO): ");
            alterar_novamente = getche();
            printf("\n");
        }
    }while(opcao != 0 && toupper(alterar_novamente) == 'S');

    if(dadosAlterados == true && opcao == 0){
        printf("Alguns dados foram alterados, deseja salvar ? (S para SIM / N para NÃO): ");
        salvarDadosAlterados = getche();
    }

    if(opcao != 0 || toupper(salvarDadosAlterados) == 'S'){
        dao_alterarVeiculo(veiculoAlterado);
    }
}

int view_relatorioVeiculoPorCasa(){
    VEICULO* veiculo;
    int qtdVeiculo = 0;
    int id_casa = 0;
    char buscar_novamente = 'N';
    char gravar = 'N';
    bool achou_usuario = false;
    char nome_arquivo[100];
    DATEC data;

    do{
        system("cls");
        fflush(stdin);
        printf("Relatório de veículo por casa\n");
        printf("Digite 0 (zero) para voltar\n");
        printf("Digite o ID da casa para filtrar: ");
        scanf("%d", &id_casa);

        if(id_casa > 0){
            veiculo = dao_procurarVeiculoCasa(id_casa, &qtdVeiculo);

            if(qtdVeiculo > 0){
                printf("Foram encontrados %d veículos\n", qtdVeiculo);
                printf("%-5s | %-5s | %-9s | %-25s | %-8s \n", "ID", "CASA", "PLACA", "MODELO", "COR");

                for(int i = 0; i < qtdVeiculo; i++){
                    printf("%-5d | %-5d | %-9s | %-25s | %-8s \n", (veiculo + i)->id, (veiculo + i)->idcasa, (veiculo + i)->placa, (veiculo + i)->modelo, (veiculo + i)->cor);
                }
                printf("Deseja salvar o relatório ? (S para SIM / N para NÃO): ");
                gravar = getche();
                printf("\n");
                if(toupper(gravar) == 'S'){
                    data = retornaDataAtual();
                    strcpy(nome_arquivo, "Relatorio_Veiculo");
                    strcat(nome_arquivo, " - ");
                    strcat(nome_arquivo, IntToString(data.dia));
                    strcat(nome_arquivo, "-");
                    strcat(nome_arquivo, IntToString(data.mes));
                    strcat(nome_arquivo, "-");
                    strcat(nome_arquivo, IntToString(data.ano));
                    dao_gravarRelatorioVeiculo(veiculo, qtdVeiculo, nome_arquivo);
                }
            }else{
                printf("Veículo não encontrado!\n");
                printf("Deseja buscá-lo novamente ? (S para SIM / N para NÃO): ");
                buscar_novamente = getche();
            }
        }else{
            return 1;
        }
    }while(toupper(buscar_novamente) == 'S');

    return 0;
}


int view_relatorioVeiculos(){
    VEICULO* veiculo;
    int qtdVeiculo = 0;
    int id_casa = 0;
    char buscar_novamente = 'N';
    char gravar = 'N';
    bool achou_usuario = false;
    char nome_arquivo[100];
    DATEC data;

    veiculo = dao_procurarTodosVeiculos(&qtdVeiculo);

    system("cls");
    if(qtdVeiculo > 0){

        printf("Foram encontrados %d veículos\n", qtdVeiculo);
        printf("%-5s | %-5s | %-9s | %-25s | %-8s \n", "ID", "CASA", "PLACA", "MODELO", "COR");

        for(int i = 0; i < qtdVeiculo; i++){
            printf("%-5d | %-5d | %-9s | %-25s | %-8s \n", (veiculo + i)->id, (veiculo + i)->idcasa, (veiculo + i)->placa, (veiculo + i)->modelo, (veiculo + i)->cor);
        }
        printf("Deseja salvar o relatório ? (S para SIM / N para NÃO): ");
        gravar = getche();
        printf("\n");
        if(toupper(gravar) == 'S'){
            data = retornaDataAtual();
            strcpy(nome_arquivo, "Relatorio_Todos_Veiculos");
            strcat(nome_arquivo, " - ");
            strcat(nome_arquivo, IntToString(data.dia));
            strcat(nome_arquivo, "-");
            strcat(nome_arquivo, IntToString(data.mes));
            strcat(nome_arquivo, "-");
            strcat(nome_arquivo, IntToString(data.ano));
            dao_gravarRelatorioVeiculo(veiculo, qtdVeiculo, nome_arquivo);
        }
    }else{
        printf("Veículos não encontrado!\n");
        system("PAUSE");
        return 1;
    }
    return 0;
}
