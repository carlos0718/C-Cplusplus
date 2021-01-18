#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <windows.h>
#include <clocale>//LIBRERIA PARA CARACTERES CON TILDE
using namespace std;
const char RUTA[]="Productos.dat";
#include "Funciones.h"
//#include "Precargados.h"
/**
Estructuras

A partir de una estructura llamada Producto que registra los campos que se detallan a continuación.

Producto

ID			entero
Nombre		texto de hasta 30 caracteres
Precio		número real
Stock			número entero
Stock mínimo	número entero

Elaborar el siguiente programa utilizando un proyecto de consola de CodeBlocks, que permita trabajar
con un máximo de 10 productos. Aunque pueden ser menos según lo que cargue el usuario.

MENÚ PRODUCTOS
--------------------------------------------------
1 - Cargar producto
2 - Editar producto x ID
3 - Listar producto x ID
4 - Listar productos (ordenados por precio)
--------------------------------------------------
0 - Salir del programa

NOTA:
La opción Cargar Producto debe solicitar la carga de un producto por vez.
No debe permitir que se carguen más de 10 productos que es el máximo que el
programa tolera. Tampoco debe permitir que el ID producto se repita en la lista de productos.

La opción Editar Producto debe solicitar el ID de producto y verificar si existe.
En caso de existir debe solicitar el resto de los campos de la estructura y modificarla.
El ID de un producto no puede modificarse. Si el producto no existe indicarlo con un mensaje.

La opción Listar Producto por ID debe solicitar el ID de producto y verificar si existe.
En caso de existir debe mostrarla por pantalla. Caso contrario indicarlo con un mensaje.

La opción Listar productos debe mostrar todos los productos cargados hasta el momento ordenados de mayor a menor según su precio.

*/

int main()
{
    setlocale(LC_ALL,"spanish");//PERMITE IMPRIMIR CARACTARES CON TILDE
    struct Producto prod;

    int cont=0;
    bool seguir=false;
    int op;
    system("color C");
    cout<<"\n\t\tARCHIVO PARA REGISTRAR PRODUCTOS";
    cout<<"\n\t\tAGREGA, MODIFICA Y ELIMINA";
    putchar('\n');
    putchar('\t');
    for(int i=0;i<50;i++)
        putchar('_');
    cout<<endl;
    cin.ignore();
    system("cls");
    system("color 5F");

    while(!seguir)
    {
        cout<<"\t\tMENU PRODUCTOS   "<<endl;
        cout<<"------------------------------------------------------------"<<endl;
        cout<<"\t1 - Cargar productos"<<endl;
        cout<<"\t2 - Listar producto "<<endl;
        cout<<"\t3 - Editar productos x ID"<<endl;
        cout<<"\t4 - Dar de Baja producto x ID"<<endl;
        cout<<"\t5 - Listar producto ordenados por precios"<<endl;
        cout<<"------------------------------------------------------------"<<endl;
        cout<<"\t0 - Salir del programa"<<endl;
        cout<<"SELECCIONE UNA OPCIÓN: ";
        cin>>op;
        cin.ignore();
        system("cls");

        switch(op)
        {
            case 1:
                {
                        prod=cargarProducto();
                        cin.ignore();
                        system("cls");
                        if(guardarProducto(prod))
                            cout<<"\tREGISTRO SE GUARDÓ CORRECTAMENTE"<<endl;
                        else
                            cout<<"\tERROR AL GUARDAR REGISTRO"<<endl;

                }break;
                 case 2:
                {
                    if(!leerRegistro())
                        cout<<"\n\tERROR AL LEER REGISTRO"<<endl;
                }break;
            case 3:
                {
                    actualizarRegistro();

                }break;
            case 4:
                {
                   darDeBajaProducto();

                }break;
            case 5:
                {
                    //pto4(prod,TAM);
                    //mostrarPto4(prod, TAM);

                }break;
            case 0:
                {
                    seguir=true;
                }break;
            default:
                cout<<"\tOPCION INCORRECTA";
                break;
        }
        cin.get();
        //cin.ignore();
        system("cls");
    }
    return 0;
}
