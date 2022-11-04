#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

#include "dao_usuario.h"
#include "funcoes.h"
#include "telaMenu.h"
#include "login.h"


void main(int argc, char *argv[ ]){
    SetConsoleTitle("CFA - Controle de fluxo automotivo");
    setlocale(LC_ALL, "Portuguese");

    loginMain();
}
