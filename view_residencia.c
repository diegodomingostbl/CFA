#include <stdio.h>

#include "view_residencia.h"
#include "dao_residencia.h"
#include "funcoes.h"
#include "struct.h"

void view_gravarResidencia(RESIDENCIA residencia){
    residencia.id = dao_retornaUltimoIdResidencia() + 1;

    dao_gravarResidencia(residencia);
}

int view_alterarResidenciaPorID(){
    int id_residencia = 0;
    RESIDENCIA residencia;
    char buscar_novamente = 'N';

    do{
        fflush(stdin);
        system("cls");
        printf("Alterar resid�ncia\n");
        printf("Digite 0 (zero) para voltar\n");
        printf("Digite o c�digo interno da resid�ncia: ");
        scanf("%d", &id_residencia);

        if(id_residencia > 0){
            residencia = dao_procurarResidenciaId(id_residencia);
            if(residencia.id > 0){
                view_alterarResidencia(residencia);
            }else{
                printf("Resid�ncia n�o encontrado!\n");
                printf("Deseja busc�-lo novamente ? (S para SIM / N para N�O): ");
                buscar_novamente = getche();
            }
        }else{
            return 1;
        }
    }while(toupper(buscar_novamente) == 'S');

    return 0;
}

void view_alterarResidencia(RESIDENCIA residencia){
    RESIDENCIA residenciaAlterada = residencia;
    char alterar_novamente = 'N';
    char salvarDadosAlterados = 'N';
    int opcao = 0;
    bool dadosAlterados = false;

    do{
        alterar_novamente = 'N';
        system("cls");
        printf("C�digo da resid�ncia: %d\n", residencia.id);
        printf("  1 - Endere�o: %s\n", residencia.endereco);
        printf("  2 - N�mero da resid�ncia: %d\n", residencia.numero_casa);
        printf("  3 - Bloco: %s\n", residencia.bloco);
        printf("  0 - Voltar\n");
        printf("Qual informa��o deseja alterar ? ");
        scanf("%d", &opcao);

        fflush(stdin);
        if(opcao > 0){
            dadosAlterados = true;
            switch(opcao){
                case 1:
                    printf("Endere�o: ");
                    gets(residenciaAlterada.endereco);
                    break;
                case 2:
                    printf("N�mero da resid�ncia: ");
                    scanf("%d", &residenciaAlterada.numero_casa);
                    break;
                case 3:
                    printf("Bloco: ");
                    gets(residenciaAlterada.bloco);
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
        dao_alterarResidencia(residenciaAlterada);
    }
}

int view_alterarResidenciaPorNumero(){
    RESIDENCIA* residencia;
    int numero_residencia = 0;
    int id_residencia = 0;
    char buscar_novamente = 'N';
    int qtdResidencia = 0;
    bool achou_usuario = false;

    do{
        fflush(stdin);
        system("cls");
        buscar_novamente = 'N';

        printf("Alterar resid�ncia\n");
        printf("Digite 0 (zero) para voltar\n");
        printf("Digite o n�mero da resid�ncia para filtrar: ");
        scanf("%d", &numero_residencia);

        if(numero_residencia > 0){
            residencia = dao_procurarResidenciaPorNumero(numero_residencia, &qtdResidencia);
            if(qtdResidencia == 1){
                view_alterarResidencia(*(residencia + 0));
            }else if(qtdResidencia > 1){
                do{
                    printf("Foram encontradas %d resid�ncias\n", qtdResidencia);
                    printf("%-5s | %-25s | %-6s | %-6s \n", "ID", "ENDERE�O", "N�MERO", "BLOCO");

                    for(int i = 0; i < qtdResidencia; i++){
                        printf("%-5d | %-25s | %-6d | %-6s \n", (residencia + i)->id, (residencia + i)->endereco, (residencia + i)->numero_casa, (residencia + i)->bloco);
                    }

                    printf("Digite 0 (zero) para voltar\n");
                    printf("Digite o ID: ");
                    scanf("%d", &id_residencia);

                    if(id_residencia > 0){
                        for(int i = 0; i < qtdResidencia; i++){
                            if((residencia + i)->id == id_residencia){
                                achou_usuario = true;
                                view_alterarResidencia(*(residencia + i));
                                return 0;
                            }
                        }
                        system("cls");
                        printf("Identificado (ID) inv�lido, escolha uns dos identificadores abaixo\n");
                    }else{
                        return 1;
                    }
                }while(achou_usuario != true && id_residencia > 0);
            }else{
                printf("Resid�ncia n�o encontrada!\n");
                printf("Deseja busc�-la novamente ? (S para SIM / N para N�O): ");
                buscar_novamente = getche();
            }
        }else{
            return 1;
        }
    }while(toupper(buscar_novamente) == 'S');

    return 0;
}

int view_alterarResidenciaPorBloco(){
    int id_residencia = 0;
    RESIDENCIA* residencia;
    char bloco[10];
    char buscar_novamente = 'N';
    int qtdResidencia = 0;
    bool achou_usuario = false;

    do{
        fflush(stdin);
        system("cls");
        buscar_novamente = 'N';

        printf("Alterar resid�ncia\n");
        printf("Digite 0 (zero) para voltar\n");
        printf("Digite o bloco da resid�ncia para filtrar: ");
        gets(bloco);

        if(bloco != '0'){
            residencia = dao_procurarResidenciaPorBloco(bloco, &qtdResidencia);
            if(qtdResidencia == 1){
                view_alterarResidencia(*(residencia + 0));
            }else if(qtdResidencia > 1){
                do{
                    printf("Foram encontradas %d resid�ncias\n", qtdResidencia);
                    printf("%-5s | %-25s | %-6s | %-6s \n", "ID", "ENDERE�O", "N�MERO", "BLOCO");

                    for(int i = 0; i < qtdResidencia; i++){
                        printf("%-5d | %-25s | %-6d | %-6s \n", (residencia + i)->id, (residencia + i)->endereco, (residencia + i)->numero_casa, (residencia + i)->bloco);
                    }

                    printf("Digite 0 (zero) para voltar\n");
                    printf("Digite o ID: ");
                    scanf("%d", &id_residencia);

                    if(id_residencia > 0){
                        for(int i = 0; i < qtdResidencia; i++){
                            if((residencia + i)->id == id_residencia){
                                achou_usuario = true;
                                view_alterarResidencia(*(residencia + i));
                                return 0;
                            }
                        }
                        system("cls");
                        printf("Identificado (ID) inv�lido, escolha uns dos identificadores abaixo\n");
                    }else{
                        return 1;
                    }
                }while(achou_usuario != true && id_residencia > 0);
            }else{
                printf("Resid�ncia n�o encontrada!\n");
                printf("Deseja busc�-la novamente ? (S para SIM / N para N�O): ");
                buscar_novamente = getche();
            }
        }else{
            return 1;
        }
    }while(toupper(buscar_novamente) == 'S');

    return 0;
}

int view_relatorioResidenciaPorNumero(){
    RESIDENCIA* residencia;
    int qtdResidencia = 0;
    int numero_residencia = 0;
    char buscar_novamente = 'N';
    char gravar = 'N';
    bool achou_usuario = false;
    char nome_arquivo[100];
    DATEC data;

    do{
        system("cls");
        fflush(stdin);
        printf("Relat�rio de resid�ncia por n�mero\n");
        printf("Digite 0 (zero) para voltar\n");
        printf("Digite o n�mero da resid�ncia para filtrar: ");
        scanf("%d", &numero_residencia);

        if(numero_residencia > 0){
            residencia = dao_procurarResidenciaPorNumero(numero_residencia, &qtdResidencia);

            if(qtdResidencia > 0){
                printf("Foram encontradas %d resid�ncias\n", qtdResidencia);
                printf("%-5s | %-25s | %-6s | %-6s \n", "ID", "ENDERE�O", "N�MERO", "BLOCO");

                for(int i = 0; i < qtdResidencia; i++){
                    printf("%-5d | %-25s | %-6d | %-6s \n", (residencia + i)->id, (residencia + i)->endereco, (residencia + i)->numero_casa, (residencia + i)->bloco);
                }
                printf("Deseja salvar o relat�rio ? (S para SIM / N para N�O): ");
                gravar = getche();
                printf("\n");
                if(toupper(gravar) == 'S'){
                    data = retornaDataAtual();
                    strcpy(nome_arquivo, "Relatorio_Residencia - ");
                    strcat(nome_arquivo, IntToString(numero_residencia));
                    strcat(nome_arquivo, " - ");
                    strcat(nome_arquivo, IntToString(data.dia));
                    strcat(nome_arquivo, "-");
                    strcat(nome_arquivo, IntToString(data.mes));
                    strcat(nome_arquivo, "-");
                    strcat(nome_arquivo, IntToString(data.ano));
                    dao_gravarRelatorioResidencia(residencia, qtdResidencia, nome_arquivo);
                }
            }else{
                printf("Resid�ncia n�o encontrado!\n");
                printf("Deseja busc�-lo novamente ? (S para SIM / N para N�O): ");
                buscar_novamente = getche();
            }
        }else{
            return 1;
        }
    }while(toupper(buscar_novamente) == 'S');

    return 0;
}

int view_relatorioResidenciaPorBloco(){
    RESIDENCIA* residencia;
    int qtdResidencia = 0;
    char bloco[10];
    char buscar_novamente = 'N';
    char gravar = 'N';
    bool achou_usuario = false;
    char nome_arquivo[100];
    DATEC data;

    do{
        system("cls");
        fflush(stdin);
        printf("Relat�rio de resid�ncia por n�mero\n");
        printf("Digite 0 (zero) para voltar\n");
        printf("Digite o n�mero da resid�ncia para filtrar: ");
        gets(bloco);

        if(bloco != '0'){
            residencia = dao_procurarResidenciaPorBloco(bloco, &qtdResidencia);

            if(qtdResidencia > 0){
                printf("Foram encontradas %d resid�ncias\n", qtdResidencia);
                printf("%-5s | %-25s | %-6s | %-6s \n", "ID", "ENDERE�O", "N�MERO", "BLOCO");

                for(int i = 0; i < qtdResidencia; i++){
                    printf("%-5d | %-25s | %-6d | %-6s \n", (residencia + i)->id, (residencia + i)->endereco, (residencia + i)->numero_casa, (residencia + i)->bloco);
                }
                printf("Deseja salvar o relat�rio ? (S para SIM / N para N�O): ");
                gravar = getche();
                printf("\n");
                if(toupper(gravar) == 'S'){
                    data = retornaDataAtual();
                    strcpy(nome_arquivo, "Relatorio_Residencia - ");
                    strcat(nome_arquivo, bloco);
                    strcat(nome_arquivo, " - ");
                    strcat(nome_arquivo, IntToString(data.dia));
                    strcat(nome_arquivo, "-");
                    strcat(nome_arquivo, IntToString(data.mes));
                    strcat(nome_arquivo, "-");
                    strcat(nome_arquivo, IntToString(data.ano));
                    dao_gravarRelatorioResidencia(residencia, qtdResidencia, nome_arquivo);
                }
            }else{
                printf("Resid�ncia n�o encontrado!\n");
                printf("Deseja busc�-lo novamente ? (S para SIM / N para N�O): ");
                buscar_novamente = getche();
            }
        }else{
            return 1;
        }
    }while(toupper(buscar_novamente) == 'S');

    return 0;
}


int view_relatorioResidencias(){
    RESIDENCIA* residencia;
    int qtdResidencia = 0;;
    char buscar_novamente = 'N';
    char gravar = 'N';
    char nome_arquivo[100];
    DATEC data;

    residencia = dao_procurarTodosResidencia(&qtdResidencia);

    system("cls");
    if(qtdResidencia > 0){

        printf("Foram encontradas %d resid�ncias\n", qtdResidencia);
        printf("%-5s | %-25s | %-6s | %-6s \n", "ID", "ENDERE�O", "N�MERO", "BLOCO");

        for(int i = 0; i < qtdResidencia; i++){
            printf("%-5d | %-25s | %-6d | %-6s \n", (residencia + i)->id, (residencia + i)->endereco, (residencia + i)->numero_casa, (residencia + i)->bloco);
        }
        printf("Deseja salvar o relat�rio ? (S para SIM / N para N�O): ");
        gravar = getche();
        printf("\n");
        if(toupper(gravar) == 'S'){
            data = retornaDataAtual();
            strcpy(nome_arquivo, "Relatorio_Todas_Residencias");
            strcat(nome_arquivo, " - ");
            strcat(nome_arquivo, IntToString(data.dia));
            strcat(nome_arquivo, "-");
            strcat(nome_arquivo, IntToString(data.mes));
            strcat(nome_arquivo, "-");
            strcat(nome_arquivo, IntToString(data.ano));
            dao_gravarRelatorioResidencia(residencia, qtdResidencia, nome_arquivo);
        }
    }else{
        printf("Resid�ncia n�o encontrado!\n");
        system("PAUSE");
        return 1;
    }
    return 0;
}
