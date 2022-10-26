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
    char CPF[11];
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
