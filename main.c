#include<stdio.h>

struct motorista {
    char nome [50];
    char motorista_rg_cpf_cnh[15];
    char bloco_casas[10];
    char placa[10];
};

void main(){
	int opcao;
    struct motorista motorista;
	do{
        printf("*Cadastro de visitante*");
		printf("\n[1] - Motorista");
		printf("\n[2] - Pedestre");
		printf("\n O que deseja cadastrar: ");
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
			    fflush(stdin);
			    fflush(stdout);
			    system("cls");
				printf("\n *Cadastro de motorista*");
				printf("\n Informe o nome completo do visitante: ");
				gets(motorista.nome);
				printf("\n Informe o RG, CPF ou CNH: ");
				gets(motorista.motorista_rg_cpf_cnh);
				printf("\n Bloco ou numero da casa reponsável: ");
				gets(motorista.bloco_casas);
				printf("\n Dados da placa: ");
				gets(motorista.placa);
				break;
			case 2:
                fflush(stdin);
                fflush(stdout);
			    system("cls");
				printf("\n *Cadastro de pedestre*");
				printf("\n Informe o nome completo do visitante: ");
				gets(motorista.nome);
				printf("\n Informe o RG, CPF ou CNH: ");
				gets(motorista.motorista_rg_cpf_cnh);
				printf("\n Bloco ou numero da casa reponsável: ");
				gets(motorista.bloco_casas);
				break;
			default:
			    system("cls");
				printf("\nOpcao invalida");
		}
	}while(opcao < 1 || opcao > 2);
}
