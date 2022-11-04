#include <stdio.h>
#include <ctype.h>

#include "view_usuario.h"
#include "dao_usuario.h"
#include "funcoes.h"

int alterarFuncionarioPorID(){
    int id_usuario = 0;
    USER usuario;
    USER usuarioAlterado;
    char buscar_novamente = 'N';
    int opcao = 0;

    do{
        system("cls");
        printf("Alterar funcionário\n");
        printf("Digite [0] para voltar\n");
        printf("Digite o código interno do funcionário: ");
        scanf("%d", &id_usuario);

        if(id_usuario > 0){
            usuario = procurarUsuarioId(id_usuario);
            usuarioAlterado = usuario;
            if(usuario.id > 0){
                do{
                    printf("[1] - Nome: %s\n", usuario.nome);
                    printf("[2] - Sobrenome: %s\n", usuario.sobrenome);
                    printf("[3] - CPF: %¨s\n", usuario.CPF);
                    printf("[4] - Data de nascimento: %s\n", DateToString(usuario.dt_nascimento));
                    printf("[5] - Salário: %.2f\n", usuario.salario);
                    printf("[6] - Cargo: %s\n", usuario.cargo);
                    printf("[7] - Endereço: %s\n", usuario.endereco);
                    printf("[8] - Número: %d\n", usuario.numeroDaCasa);
                    printf("[9] - Bairro: %s\n", usuario.bairro);
                    printf("[10] - Cidade: %s\n", usuario.cidade);
                    printf("[11] - UF: %s\n", usuario.endereco);
                    printf("[12] - Login: %s\n", usuario.login);
                    printf("[13] - Senha\n");
                    printf("[0] - Voltar\n");
                    printf("Qual informação deseja alterar ? ");
                    scanf("%d", &opcao);

                    switch(opcao){
                        case 0:

                            break;
                        case 1:
                            //nome
                            printf("Nome: ");
                            gets(usuarioAlterado.nome);
                            break;
                        case 2:
                            //sobrenome
                            printf("Sobrenome: ");
                            gets(usuarioAlterado.sobrenome);
                            break;
                        case 3:
                            //cpf
                            printf("CPF (sem pontuação): ");
                            gets(usuarioAlterado.CPF);
                            break;
                        case 4:
                            //data nascimento
                            break;
                        case 5:
                            //salario
                            printf("Salário: ");
                            scanf("%f", &usuarioAlterado.salario);
                            break;
                        case 6:
                            //cargo
                            printf("Cargo: ");
                            gets(usuarioAlterado.cargo);
                            break;
                        case 7:
                            //endereco

                            break;
                        case 8:
                            //numero

                            break;
                        case 9:
                            //bairro
                            break;
                        case 10:
                            //cidade

                            break;

                        case 11:
                            //uf

                            break;
                        case 12:
                            //login

                            break;
                        case 13:
                            //senha

                            break;
                    }

                }while(opcao != 0);

            }else{
                printf("Usuário não encontrado!\n");
                printf("Deseja buscá-lo novamente ? (S para SIM / N para NÃO): ");
                buscar_novamente = getche();
            }
        }else{
            return 1;
        }
    }while(toupper(buscar_novamente) == 'S');

    return 0;
}

/*
	printf("Data de nascimento: \n");
	printf("	Dia: ");
	scanf("%d", &usuario.dt_nascimento.dia);
	printf("	Mês: ");
	scanf("%d", &usuario.dt_nascimento.mes);
	printf("	Ano: ");
	scanf("%d", &usuario.dt_nascimento.ano);


	printf("Endereço: ");
	gets(usuario.endereco);
	printf("Número: ");
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
*/
