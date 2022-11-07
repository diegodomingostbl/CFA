#include <stdbool.h>

#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

struct data{
	int dia;
	int mes;
	int ano;
};
typedef struct data DATEC;

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

struct veiculo {
    char placa[7];
    char modelo[30];
    char cor[15];
    int idcasa;

};
typedef struct veiculo VEICULO;


#endif // STRUCT_H_INCLUDED

