#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <clocale>//LIBRERIA PARA CARACTERES CON TILDE

using namespace std;

const char ARCHIVO[]="LARA.dat";

#include "Prototipos.h"
#include "Validaciones.h"
#include "Funciones.h"
#include "Menus.h"



int main()
{
    setlocale(LC_ALL,"spanish");//PERMITE IMPRIMIR CARACTARES CON TILDE
    menuPrincipal();

    return 0;
}
