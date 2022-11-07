#include <stdio.h>
#include <locale.h>
#include <string.h>

struct tipo_veiculo_morador {
    char placa[7];
    char modelo[30];
    char cor[15];
    char responsavel[30];
    int bloco;
    char rua[30];
    int numero;
};
typedef struct tipo_veiculo_morador VMORADOR;

struct tipo_veiculo_visitante {
    char placa[7];
    char modelo[30];
    char cor[15];
    char responsavel[30];
    char responsavel_morador[30];
};
typedef struct tipo_veiculo_visitante VVISITANTE;

VMORADOR cadastro_veiculo_morador(){
    VMORADOR veiculo;
    printf(" PLACA:");
    printf(" MODELO:");
    printf(" COR:");
    printf(" RESPONSÁVEL:");
    printf(" BLOCO:");
    printf(" RUA:");
    printf(" NÚMERO:");

    return veiculo;
};


void main(){
    VMORADOR veiculo_morador[500];
    setlocale(LC_ALL, "Portuguese");
    int a, i;
    char z, b; // placa
    char c[20], d[20]; //modelo
    char e[10], f[10]; //cor
    char g[20], h[20], l[20]; //responsáveis
    int x; //bloco
    char j[20]; //rua
    int k; //número
    int resposta;

        printf("\n Deseja cadastrar veículo de morador ou visitante? ");
        printf(" \n [1] MORADOR ");
        printf(" \n [2] VISITANTE");
        scanf("%d", &a);
 do{
                    printf(" PLACA:");
                    gets(cadastro_veiculo_morador(z).placa);
                    printf(" MODELO:");
                    gets(cadastro_veiculo_morador(c).modelo);
                    printf(" COR:");
                    gets(cadastro_veiculo_morador(e).cor);
                    printf(" Código da casa:");
                    gets(cadastro_veiculo_morador(g).responsavel);
                    printf(" BLOCO:");
                    scanf("%d", &x);
                    printf(" RUA:");
                    gets(cadastro_veiculo_morador(j).rua);
                    printf(" NÚMERO:");
                    scanf("%d", &k);
                    printf("Deseja cadastrar mais algum veículo morador?");
                    printf("Sim[1]");
                    printf("Não[2]");
                    scanf("%d", &resposta);
                    if(resposta!= 1 && resposta!=2);
                        scanf("%d", &resposta);
                    }
                    while(resposta==1);

        case 2:     do{
                    printf(" PLACA:");
                    gets(cadastro_veiculo_visitante(b).placa);
                    printf(" MODELO:");
                    gets(cadastro_veiculo_visitante(d).modelo);
                    printf(" COR:");
                    gets(cadastro_veiculo_visitante(f).cor);
                    printf(" RESPONSÁVEL:");
                    gets(cadastro_veiculo_visitante(h).responsavel);
                    printf(" MORADOR RESPONSÁVEL:");
                    gets(cadastro_veiculo_visitante(l).responsavel_morador);
                    printf("Deseja cadastrar mais algum veículo visitante?");
                    printf("Sim[1]");
                    printf("Não[2]");
                    scanf("%d", &resposta);
                    if(resposta!= 1 && resposta!=2);
                        scanf("%d", &resposta);
                    }
                    while(resposta==1);

}
