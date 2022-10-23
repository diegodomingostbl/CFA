#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char nome[30], dia[3], mes[3], ano[5];
    float valor;
    bool contaValida;
}c_pagar;

typedef struct{
    char nome[30], dia[3], mes[3], ano[5];
    float valor;
    bool contaValida;
}c_receber;

//prototipos funcoes
c_receber criarContaReceber();
c_pagar criarContaPagar();
bool textoVazio(char texto[]);

void main(){

    setlocale (LC_ALL, "portuguese");
    int tam = 450, count_p = 0, count_r = 0, cp = 0, cr = 0, op, retorno;
    char resposta, nome[30];
    float total_desp = 0, total_rec = 0;
    c_pagar pagar[100];
    c_receber receber[100];


    do{
        printf("**********************************************\n");
        printf("*     CFC - CONTROLE DE FLUXO CONDOMINIO     *\n");
        printf("**********************************************\n");
        printf("\n******************CADASTROS*******************\n\n");
        printf("[1] CADASTRAR CONTAS A PAGAR\n");
        printf("[2] CADASTRAR CONTAS A RECEBER\n");
        printf("\n******************CONSULTAS*******************\n\n");
        printf("[3] CONSULTAR CONTAS A PAGAR\n");
        printf("[4] CONSULTAR CONTAS A RECEBER\n");
        printf("[5] CONSULTAR RESULTADO LIQUIDO MÊS\n");
        printf("[6] CONSULTAR RESULTADO LIQUIDO ANO\n");
        printf("\n******************ALTERAÇÕES******************\n\n");
        printf("[7] ALTERAR CADASTRO DE CONTAS A PAGAR\n");
        printf("[8] ALTERAR CADASTRO DE CONTAS A RECEBER\n");
        printf("[0] SAIR DO SISTEMA\n");
        printf("\nDigite a opção desejada: ");
        scanf("%d", &op);

        switch(op){
            case 1: // o usuario cadastra contas a pagar do cliente
            printf("\nPara efetuar o cadastro de contas a pagar digite os dados abaixo: \n");
            do{
                do {
                    pagar[count_p] = criarContaPagar(); //chamada funcao criarContaPagar()
                }while(!pagar[count_p].contaValida);

                printf("\nDeseja fazer outro cadastro (s/n)?: ");
                resposta = getche();
                resposta = tolower(resposta); // converte a resposta do usuário para um caractere minúsculo
                printf("\n\n");
                fflush(stdin);
                count_p++;
                cp++;

            }while(resposta == 's' && count_p < tam);

            system("pause");
            system("cls"); // limpa a tela
        break;

        case 2: // o usuario cadastra contas a receber do cliente
            printf("\nPara efetuar um cadastro de contas a receber digite os dados abaixo: \n");
            do{
                do {
                    receber[count_r] = criarContaReceber();//chamada funcao criarContaReceber()
                }while(!receber[count_r].contaValida);

                printf("\nDeseja fazer outro cadastro (s/n)?: ");
                resposta = getche();
                resposta = tolower(resposta);// converte a resposta do usuário para um caractere minúsculo
                printf("\n\n");
                fflush(stdin);
                count_r++;
                cr++;

            }while(resposta == 's' && count_r < tam);
        break;

        case 3:{
             // usuario consulta contas a pagar
        char mes[3], ano[5];
        int retorno2;

            if (cp == 0)
                printf("\nA empresa não possui contas a pagar\n\n");

            else{
                fflush(stdin);
                printf("\nInforme o mês: ");
                scanf("%s", &mes);
                fflush(stdin);
                printf("\nInforme o ano: ");
                scanf("%s", &ano);
                printf("\n****************CONTAS A PAGAR****************\n");

                int existeConta = 0;
                for (int i = 0; i < cp; i++){
                    retorno = strcmp(pagar[i].mes,mes); // compara a string e se for igual resultado será 0
                    retorno2 = strcmp(pagar[i].ano,ano);

                    if (retorno == 0 && retorno2 == 0){
                        printf("\n**********************************************\n");
                        printf("\nFornecedor:%s \n", pagar[i].nome);
                        printf("Data da compra:%02s/%02s/%04s \n", pagar[i].dia, pagar[i].mes, pagar[i].ano);
                        printf("Valor da compra: R$ %.2f \n", pagar[i].valor);
                        total_desp = total_desp + pagar[i].valor;
                        existeConta++;
                    }
                 }
                if (existeConta == 0)
                        printf("não possui despesas para o mes %s e ano %s \n", mes, ano);
             }
                if (total_desp > 0)
                    printf("\n**********************************************\n");
                    printf("\nO total de despesas para o mes %s é R$ %.2f\n\n", mes, total_desp);
                    total_desp = 0;
                    system ("pause");
            break;
        }// FIM case3

        case 4:{ // usuario consulta contas a receber
            char mes[3], ano[5];
            int retorno2;

                if (cr == 0)
                    printf("\nA empresa não possui contas a receber\n\n");

                else{
                    fflush(stdin);
                    printf("\nInforme o mês: ");
                    scanf("%s", &mes);
                    fflush(stdin);
                    printf("\nInforme o ano: ");
                    scanf("%s", &ano);
                    printf("\n***************CONTAS A RECEBER***************\n");

                    int existeConta = 0;
                    for (int i = 0; i < cr; i++){
                        retorno = strcmp(receber[i].mes,mes); // STRCMP compara a string e se for igual resultado será 0
                        retorno2 = strcmp(receber[i].ano,ano);

                        if (retorno == 0 && retorno2 == 0){
                            printf("\n**********************************************\n");
                            printf("\nCliente:%s \n", receber[i].nome);
                            printf("Data do recebimento:%02s/%02s/%04s \n", receber[i].dia, receber[i].mes, receber[i].ano);
                            printf("Valor a receber: R$ %.2f \n", receber[i].valor);
                            total_rec += receber[i].valor;
                            existeConta++;
                        }
                     }

                if (existeConta == 0)
                        printf("Você não possui contas a receber no mes %s e ano %s \n\n", mes, ano);
                }
                if (total_rec > 0){
                    printf("\n**********************************************\n");
                    printf("\nO total de receita para o mes %s é R$ %.2f\n\n", mes, total_rec);
                    total_rec = 0;
                    system ("pause");
                }
                break;
            }// FIM case4


        case 5:{// cliente consulta resultado liquido do MES
             char mes[3], ano[5];
             float t_cr = 0, t_cp = 0;
             int ret_Pm, ret_Pa, ret_Rm, ret_Ra;

             printf("\n************RESULTADO LIQUIDO MÊS************\n\n");
             fflush(stdin);
             printf("\nDigite o mês para consultar o RESULTADO: ");
             scanf("%s", &mes);
             printf("\nDigite o ano para consultar o RESULTADO: ");
             scanf("%s", &ano);

             if(cr != 0)
                 for (int i = 0; i < cr; i++){
                    ret_Rm = strcmp(receber[i].mes,mes);
                    ret_Ra = strcmp(receber[i].ano,ano); // STRCMP compara a string e for igual resultado será 0
                    if (ret_Rm == 0 && ret_Ra == 0)
                        t_cr += receber[i].valor;
                 }

             if (cp != 0)
                for (int i = 0; i < cp; i++){
                    ret_Pm = strcmp(pagar[i].mes,mes);
                    ret_Pa = strcmp(pagar[i].ano,ano); // STRCMP compara a string e for igual resultado será 0
                    if (ret_Pm == 0 && ret_Pa == 0)
                    t_cp += pagar[i].valor;
                }

             if(cr == 0 && cp == 0)
               printf("\nVocê não possui contas cadastradas\n\n");

             if (t_cr !=0 || t_cp != 0){
                printf("\nO resultado liquido do mês %s do ano %s é: R$ %.2f\n\n", mes, ano, t_cr - t_cp);
                system ("pause");
             }


             else{
                printf("\nVocê não possui contas para o periodo %s/%s\n", mes, ano);
                system ("pause");
             }
             break;
       } //case 5
        case 6:{ // cliente consulta resultado liquido do ANO
             char ano[5];
             float t_cr = 0, t_cp = 0;
             int ret_Pa, ret_Ra;

             printf("\n************RESULTADO LIQUIDO ANO************\n\n");
             fflush(stdin);
             printf("\nDigite o ano para consultar o RESULTADO: ");
             scanf("%s", &ano);

             if(cr != 0)
                 for (int i = 0; i < cr; i++){
                    ret_Ra = strcmp(receber[i].ano,ano); // STRCMP compara a string e for igual resultado será 0
                    if (ret_Ra == 0)
                        t_cr += receber[i].valor;
                 }

             if (cp != 0)
                for (int i = 0; i < cp; i++){
                    ret_Pa = strcmp(pagar[i].ano,ano); // STRCMP compara a string e for igual resultado será 0
                    if (ret_Pa == 0)
                    t_cp += pagar[i].valor;
                }

             if(cr == 0 && cp == 0){
               printf("\nVocê não possui contas cadastradas\n");
               system ("pause");
             }


             if (t_cr !=0 || t_cp != 0){
                printf("\nO resultado liquido do ano %s é: R$ %.2f\n\n", ano, t_cr - t_cp);
                system ("pause");
             }

             else{
                printf("\nVocê não possui contas para o ano %s\n\n", ano);
                system ("pause");
             }
             break;
        }// case6

        case 7:{// Usuario altera cadastro contas a pagar
            char mes[3], ano[5];
            int r_Pm, r_Pa, achou = 0;

            if (count_p == 0){
                printf("\nVocê ainda não cadastrou nenhuma conta a pagar\n\n");
                system ("pause");
            }

            else{
                fflush(stdin);
                printf("\nInforme o nome do fornecedor: ");
                gets(nome);
                strlwr(nome);
                fflush(stdin);
                printf("\nDigite o mês: ");
                scanf("%s", &mes);
                fflush(stdin);
                printf("\nDigite o ano: ");
                scanf("%s", &ano);

                    for (int i = 0; i < count_p; i++){
                       strlwr(pagar[i].nome);
                       r_Pm = strcmp(pagar[i].mes,mes);
                       r_Pa = strcmp(pagar[i].ano,ano);

                        if (strcmp(nome, pagar[i].nome) == 0 && r_Pm == 0 && r_Pa == 0){
                            achou = 1;
                            printf("\nFornecedor:%s \n", pagar[i].nome);
                            printf("Data da compra:%02s/%02s/%04s \n", pagar[i].dia, pagar[i].mes, pagar[i].ano);
                            printf("Valor da compra: R$ %.2f \n", pagar[i].valor);

                            printf("\n\nDeseja alterar os dados do fornecedor? (s/n): ");
                            resposta = getche();
                            resposta = tolower(resposta);
                            printf("\n");

                            if(resposta == 's'){
                                printf("\n*************ALTERAÇÃO DE DADOS CONTAS A PAGAR*************\n");
                                fflush(stdin);
                                printf("Digite o novo nome da fornecedor: ");
                                gets(pagar[i].nome);
                                fflush(stdin);
                                printf("Insira o novo dia de vencimento da conta: ");
                                scanf("%s", &pagar[i].dia);
                                fflush(stdin);
                                printf("Insira o novo mes de vencimento da conta: ");
                                scanf("%s", &pagar[i].mes);
                                fflush(stdin);
                                printf("Insira o novo ano de vencimento da conta: ");
                                scanf("%s", &pagar[i].ano);
                                fflush(stdin);
                                printf("digite o novo valor da conta: ");
                                scanf("%f", &pagar[i].valor);
                                fflush(stdin);

                                printf("\n************DADOS ALTERADOS COM SUCESSO!************\n");

                                printf("\nFornecedor:%s \n", pagar[i].nome);
                                printf("Data da compra:%02s/%02s/%04s \n", pagar[i].dia, pagar[i].mes, pagar[i].ano);
                                printf("Valor da compra: R$ %.2f \n", pagar[i].valor);
                                system("pause");
                            }
                            else(resposta != 's');
                            break;
                        }
                    }
                            if(achou == 0){
                                printf("\nNenhum fornecedor com o nome %s no periodo %s/%s foi encontrado.\n\n", nome, mes, ano);
                                system ("pause");
                                break;
                        }
            }
            break;
        } //case 7

        case 8:{// Usuario altera cadastro contas a receber
            char mes[3], ano[5];
            int r_Rm, r_Ra, achou = 0;

            if (count_r == 0){
                printf("\nVocê ainda não cadastrou nenhuma conta a receber\n");
                system ("pause");
            }

            else{
                fflush(stdin);
                printf("\nInforme o nome do cliente: ");
                gets(nome);
                strlwr(nome);
                fflush(stdin);
                printf("\nDigite o mês: ");
                scanf("%s", &mes);
                fflush(stdin);
                printf("\nDigite o ano: ");
                scanf("%s", &ano);

                for (int i = 0; i < count_r; i++){
                   strlwr(receber[i].nome);
                   r_Rm = strcmp(receber[i].mes,mes);
                   r_Ra = strcmp(receber[i].ano,ano);


                    if (strcmp(receber[i].nome, nome) == 0 && r_Rm == 0 && r_Ra == 0){
                        achou = 1;
                        printf("\nCliente:%s \n", receber[i].nome);
                        printf("Data do recebimento:%02s/%02s/%04s \n", receber[i].dia, receber[i].mes, receber[i].ano);
                        printf("Valor a receber: R$ %.2f \n", receber[i].valor);

                        printf("\n\nDeseja alterar os dados do cliente? (s/n): ");
                        resposta = getche();
                        resposta = tolower(resposta);
                        printf("\n");

                        if(resposta == 's'){
                            printf("\n*************ALTERAÇÃO DE DADOS CONTA A RECEBER*************\n");
                            fflush(stdin);
                            printf("Digite o novo nome da cliente: ");
                            gets(receber[i].nome);
                            fflush(stdin);
                            printf("Insira o novo dia de recebimento da conta: ");
                            scanf("%s", &receber[i].dia);
                            fflush(stdin);
                            printf("Insira o novo mes de recebimento da conta: ");
                            scanf("%s", &receber[i].mes);
                            fflush(stdin);
                            printf("Insira o novo ano de recebimento da conta: ");
                            scanf("%s", &receber[i].ano);
                            fflush(stdin);
                            printf("digite o novo valor a receber: ");
                            scanf("%f", &receber[i].valor);
                            fflush(stdin);

                            printf("\n************DADOS ALTERADOS COM SUCESSO!************\n");

                            printf("\nCliente:%s \n", receber[i].nome);
                            printf("Data de recebimento:%02s/%02s/%04s \n", receber[i].dia, receber[i].mes, receber[i].ano);
                            printf("Valor a receber:R$ %.2f \n", receber[i].valor);
                            system ("pause");
                        }
                         else(resposta != 's');
                            break;
                    }
                }

                        if(achou == 0){
                            printf("\nNenhum cliente com o nome %s no periodo %s/%s foi encontrado.\n\n", nome, mes, ano);
                            system ("pause");
                            break;
                        }


            }
            break;
        } //case 8
    }// switch
    }while (op != 0);
}

// criando funcoes
c_receber criarContaReceber() {
    c_receber conta;
    conta.contaValida = false;
    printf("\n*******************INICIANDO CADASTRO*******************\n");
    fflush(stdin);
    printf("\nDigite o nome do cliente: ");
    gets(conta.nome);
    if(textoVazio(conta.nome))
        return conta;

    fflush(stdin);
    printf("Insira o dia de recebimento da conta: ");
    scanf("%s", &conta.dia);

    fflush(stdin);
    printf("Insira mes de recebimento da conta: ");
    scanf("%s", &conta.mes);
    fflush(stdin);

    printf("Insira ano de recebimento da conta: ");
    scanf("%s", &conta.ano);
    fflush(stdin);

    printf("Digite o valor a receber: ");
    scanf("%f", &conta.valor);

    printf("\n*************CADASTRO REALIZADO COM SUCESSO*************\n");
    fflush(stdin);
    conta.contaValida = true;
    return conta;
}

c_pagar criarContaPagar(){
    c_pagar contaPagar;
    contaPagar.contaValida = false;
    printf("\n*******************INICIANDO CADASTRO*******************\n");
    fflush(stdin);

    printf("\nDigite o nome do fornecedor: ");
    gets(contaPagar.nome);
    if(textoVazio(contaPagar.nome))
        return contaPagar;
    fflush(stdin);

    printf("Insira o dia de vencimento da conta: ");
    scanf("%s", &contaPagar.dia);
    fflush(stdin);

    printf("Insira mes de vencimento da conta: ");
    scanf("%s", &contaPagar.mes);
    fflush(stdin);

    printf("Insira ano de vencimento da conta: ");
    scanf("%s", &contaPagar.ano);
    fflush(stdin);

    printf("Digite o valor da conta: ");
    scanf("%f", &contaPagar.valor);
    fflush(stdin);

    printf("\n*************CADASTRO REALIZADO COM SUCESSO*************\n");
    contaPagar.contaValida = true;
    return contaPagar;
}

_Bool textoVazio(char texto[]){
//    if(texto[0] == '\0'){
//        return true;
//    }else {
//        return false;
//    }
    return texto[0] == '\0';
}
