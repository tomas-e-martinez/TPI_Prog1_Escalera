#include <iostream>
#include <ctime>
#include "funciones.h"
#include "constantes.h"
#include "menu.h"

using namespace std;

int main()
{
    srand(time(0)); //Inicializa la seed con la hora actual para generar numeros pseudoaleatorios

    int vDados[CANTIDAD_DADOS] = {1, 3, 5, 3, 2, 6};
    int vDadosCopia[CANTIDAD_DADOS];

    menu();


    return 0;
}
