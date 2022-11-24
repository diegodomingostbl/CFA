#include <stdbool.h>

#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct{
    int dia;
	int mes;
	int ano;
}DATEC;

struct usuario{
    int id;
    char nome[150];
    char sobrenome[150];
    char CPF[12];
    char login[50];
    char senha[50];
    DATEC dt_nascimento;
    DATEC dt_cadastro;
    float salario;
    char cargo[20];
    char endereco[150];
    int numeroDaCasa;
    char bairro[50];
    char cidade[50];
    char estado[50];
};
typedef struct usuario USER;

struct userLogado{
    int idUsuario;
    char nome[150];
    char login[50];
    char senha[50];
    char cargo[20];
    bool logado;
};
typedef struct userLogado USERLOGIN;

typedef struct{
    int id;
    char nome[50];
    DATEC dt_vencimento;
    float valor;
}C_PAGAR;

typedef struct{
    int id;
    char nome[50];
    int residencia;
    DATEC dt_vencimento;
    float valor;
}C_RECEBER;

typedef struct{
    int id;
    int idcasa;
    char placa[8];
    char modelo[30];
    char cor[15];
}VEICULO;

typedef struct{
    int id;
    char endereco[50];
    int numero_casa;
    char bloco[6];
}RESIDENCIA;

typedef struct{
    int id;
    int visitando_residencia;
    char placa[8];
    char nomeSobrenomeMotorista[60];
    DATEC data_entrada;

}E_VEICULO;

typedef struct{
    int id;
    int visitando_residencia;
    char CPF[12];
    char nomeSobrenome[60];
    DATEC data_entrada;

}E_PESSOA;

#endif // STRUCT_H_INCLUDED

