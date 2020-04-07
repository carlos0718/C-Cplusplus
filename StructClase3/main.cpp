#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <clocale>
using namespace std;
#include "Funciones.h"

/**
Estructuras

A partir de una estructura llamada Producto que registra los campos que se detallan a continuaci�n.

Producto

ID			entero
Nombre		texto de hasta 30 caracteres
Precio		n�mero real
Stock			n�mero entero
Stock m�nimo	n�mero entero

Elaborar el siguiente programa utilizando un proyecto de consola de CodeBlocks, que permita trabajar
con un m�ximo de 10 productos. Aunque pueden ser menos seg�n lo que cargue el usuario.

MEN� PRODUCTOS
--------------------------------------------------
1 - Cargar producto
2 - Editar producto x ID
3 - Listar producto x ID
4 - Listar productos (ordenados por precio)
--------------------------------------------------
0 - Salir del programa

NOTA:
La opci�n Cargar Producto debe solicitar la carga de un producto por vez.
No debe permitir que se carguen m�s de 10 productos que es el m�ximo que el
programa tolera. Tampoco debe permitir que el ID producto se repita en la lista de productos.

La opci�n Editar Producto debe solicitar el ID de producto y verificar si existe.
En caso de existir debe solicitar el resto de los campos de la estructura y modificarla.
El ID de un producto no puede modificarse. Si el producto no existe indicarlo con un mensaje.

La opci�n Listar Producto por ID debe solicitar el ID de producto y verificar si existe.
En caso de existir debe mostrarla por pantalla. Caso contrario indicarlo con un mensaje.

La opci�n Listar productos debe mostrar todos los productos cargados hasta el momento ordenados de mayor a menor seg�n su precio.

*/
const int TAM = 2;
int main()
{
    struct Producto prod[TAM];

    int cont=0;
    bool seguir=false;
    int op;
    system("color 5F");

    while(!seguir)
    {
        cout<<"\t\tMENU PRODUCTOS   "<<endl;
        cout<<"------------------------------------------------------------"<<endl;
        cout<<"\t1 - Cargar productos"<<endl;
        cout<<"\t2 - Listar producto "<<endl;
        cout<<"\t3 - Editar productos x ID"<<endl;
        cout<<"\t4 - Listar producto x ID"<<endl;
        cout<<"\t5 - Listar producto ordenados por precios"<<endl;
        cout<<"------------------------------------------------------------"<<endl;
        cout<<"\t0 - Salir del programa"<<endl;
        cout<<"SELECCIONE UNA OPCION: ";
        cin>>op;
        cin.ignore();
        system("cls");

        switch(op)
        {
            case 1:
                {
                    bool r;
                    if(cont==0)
                    {
                        cargarProducto(prod,TAM,cont);
                        cont++;
                    }
                    else if(cont<TAM)
                    {
                        r=pto1(prod,TAM,cont);
                        if(r)
                            cont++;
                    }
                    else
                        cout<<"\tNO SE PUEDE AGREGAR MAS PRODUCTOS. ALMACENAMIENTO LLENO"<<endl;
                    cin.ignore();
                }break;
                 case 2:
                {
                    mostrarPto4(prod, TAM);
                    cin.ignore();
                }break;
            case 3:
                {
                    pto2(prod, TAM);
                    cin.ignore();
                }break;
            case 4:
                {
                    pto3(prod,TAM);
                    cin.ignore();
                }break;
            case 5:
                {
                    pto4(prod,TAM);
                    mostrarPto4(prod, TAM);
                    cin.ignore();
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
        system("cls");
    }
    return 0;
}
