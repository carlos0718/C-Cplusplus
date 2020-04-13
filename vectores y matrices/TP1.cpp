#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

/*
color de consola :
0 = Negro
1 = Azul
2 = Verde
3 = Aguamarina
4 = Rojo
5 = Purpura
6 = Amarillo
7 = Blanco
8 = Gris
9 = Azul claro

color de texto:
A = Verde claro
B = Aguamarina claro
C = Rojo claro
D = Purpura claro
E = Amarillo claro
F = Blanco brillante
*/



void cargarVec(int *, int);
void mostrarVec(int *, int);
int mostrarMayorVec(int *, int);

void cargarVec3(int *, int);
void mostrarVec3(int *, int);
int mostrarMenorVec3(int *, int);

void cargarVec5(int *, int);
void mostrarVec5(int *, int);
bool mostrarExisteVec5(int *, int, int);

void cargarMat1(int mat1[3][3], int ,int );
void mostrarMat1(int mat1[3][3],int , int );
int maximoDeLaFila(int mat1[3][3],int , int , int );

void cargarMat5(int mat5[3][3], int ,int );
void mostrarMat5(int mat5[3][3],int , int );
int sumaTotalMat5(int mat5[3][3],int , int);

int main()
{
    char op;
    bool salir=false;
    while(!salir)
    {
        system("color A");
        cout <<"--------------------------------"<<endl;
        cout <<"*A-EJERCICIO 2 DE VECTORES     *"<<endl;
        cout <<"*B-EJERCICIO 3 DE VECTORES     *"<<endl;
        cout <<"*C-EJERCICIO 5 DE VECTORES     *"<<endl;
        cout <<"*D-EJERCICIO 1 DE MATRICES     *"<<endl;
        cout <<"*E-EJERCICIO 5 DE MATRICES     *"<<endl;
        cout <<"*S-Salir                       *"<<endl;
        cout <<"--------------------------------"<<endl;
        cout <<"Ingrese una opcion: ";
        cin>>op;
        system("cls");
        cin.ignore();
        switch(op)
        {
        case 'a':
            case 'A':
              {
                    cout<<"EJERCICIO 2 DEL TP"<<endl;
                    int vec[5]={0};
                    int maximo;
                    cout<<"Cargue vector:"<<endl;
                    cargarVec(vec,5);
                    system("cls");
                    system("color D");
                    mostrarVec(vec,5);
                    maximo=mostrarMayorVec(vec,5);
                    cout<<"El mayor elemento del vector es: "<<maximo<<endl;
                    cin.get();

              }break;

        case 'b':
            case 'B':
                {
                    cout<<"EJERCICIO 3 DEL TP"<<endl;
                    int vec3[5]={0};
                    int pos;
                    cout<<"Cargue vector:"<<endl;
                    cargarVec3(vec3, 5);
                    system("cls");
                    system("color D");
                    mostrarVec3(vec3, 5);
                    pos=mostrarMenorVec3(vec3, 5);
                    cout<<"El numero menor esta en la posicion :"<<pos<<endl;
                    cin.get();

                }break;

        case 'c':
            case 'C':
                {
                    cout<<"EJERCICIO 5 DEL TP"<<endl;
                    int vec5[10]={0};

                    int x;///numero al azar para validar en vector.
                    cout<<"Ingrese un numero: ";
                    cin>>x;

                    bool existe;
                    cout<<"Cargue vector:"<<endl;
                    cargarVec5(vec5, 10);
                    system("cls");
                    system("color D");
                    mostrarVec5(vec5, 10);
                    existe=mostrarExisteVec5(vec5, 10, x);
                    if(!existe)
                        cout<<"El numero "<<x<< " NO existe en el vector "<<endl;
                    else
                        cout<<"El numero "<<x<< " SI existe en el vector "<<endl;

                    cin.get();

                }break;
        case 'd':
            case 'D':
                {
                    cout<<"EJERCICIO 1 DE MATRICES DEL TP"<<endl;
                    int mayor,aux,f;
                    int mat1[3][3]={{0},{0}};

                    cout<<"Cargue la matriz "<<endl;
                    cargarMat1(mat1,3 ,3);
                    system("cls");

                    system("color D");
                    mostrarMat1(mat1,3,3);
                    cout<<"Ingrese un numero para la fila: ";
                    cin>>aux;

                    f=aux-1;
                    mayor=maximoDeLaFila(mat1,3, 3,f);
                    cout<<"El mayor numero de la fila "<<aux<<" es: "<<mayor<<endl;

                    cin.get();

                }break;
        case 'e':
            case 'E':
                {
                    cout<<"EJERCICIO 5 DE MATRICES DEL TP"<<endl;
                    int resultado;
                    int mat5[3][3]={0};

                    cout<<"Cargue la matriz "<<endl;
                    cargarMat5(mat5,3 ,3);
                    system("cls");

                    system("color D");
                    mostrarMat5(mat5,3,3);
                    resultado=sumaTotalMat5(mat5,3,3);
                    cout<<"La suma total de los elementos de la matriz es: "<<resultado<<endl;

                    cin.get();

                }break;

        case 's':
            case 'S':
                {
                    salir=true;
                }break;
        default:
        {
            cout <<"Opcion no valida!!!";
        }
        break;
        }
        cin.ignore();
        system("cls");
    }
    return 0;
}
///2)Hacer una función que reciba como parámetros
///un vector de enteros y un número entero que
///indica la cantidad de componentes del vector,
///y que devuelva el valor maximo contenido en ese vector.
void cargarVec(int *vec, int tam)
{
    for(int i=0; i<tam;i++)
    {
        cin>>vec[i];
    }
}
void mostrarVec(int *vec, int tam)
{
    cout<<" --------------------"<<endl;
    for(int i=0; i<tam;i++)
    {
        cout<<" | "<<vec[i];
    }
    cout<<"|"<<endl;
    cout<<" --------------------"<<endl;
}
int mostrarMayorVec(int *vec, int tam)
{
    int mayor=vec[0];
    int r;
    for(int i=1;i<tam; i++)
    {
        if(vec[i]>mayor)
        {
            mayor=vec[i];
            r=mayor;
        }
    }
    return r;
}
///3)Hacer una función que reciba como parámetros un vector
///de enteros y un número entero que indica la cantidad de
///componentes del vector, y que devuelva la posición que
///ocupa el valor mínimo contenido en ese vector.
void cargarVec3(int *vec3, int tam)
{
    for(int i=0; i<tam;i++)
    {
        cin>>vec3[i];
    }
}
void mostrarVec3(int *vec3, int tam)
{
    cout<<" --------------------"<<endl;
    for(int i=0; i<tam;i++)
    {
        cout<<" | "<<vec3[i];
    }
    cout<<"|"<<endl;
    cout<<" --------------------"<<endl;
}
int mostrarMenorVec3(int *vec3, int tam)
{
    int menor=vec3[0];
    int r;
    for(int i=1;i<tam; i++)
    {
        if(vec3[i]<menor)
        {
            menor=vec3[i];
            r=i;
        }
    }
    return r;
}
///5)Hacer una función que reciba como parámetros un vector
///de enteros de 10 elementos y un número entero, y que
///devuelva verdadero si el número recibido existe en el vector,
///o falso si no existe.
void cargarVec5(int *vec5, int tam)
{
    for(int i=0; i<tam; i++)
    {
        cin>>vec5[i];
    }
}
void mostrarVec5(int *vec5, int tam)
{
    cout<<" ------------------------"<<endl;
    for(int i=0; i<tam;i++)
    {
        cout<<" | "<<vec5[i];
    }
    cout<<"|"<<endl;
    cout<<" ------------------------"<<endl;
}
bool mostrarExisteVec5(int *vec5, int tam, int num)
{
    bool e=true;
    for(int i=0; i<tam;i++)
    {
        if(vec5[i]==num)
        {
            e=true;
            break;
        }
        else
            e=false;
    }
    return e;
}
///MATRICES:
///1.Hacer una función que reciba como parámetros una matriz de enteros de 10x10
///y un número entero (entre 0 y 9), y devuelva el máximo de la fila indicada por el
///segundo parámetro.
void cargarMat1(int mat1[3][3], int f,int c)
{
    for(int i=0; i<f;i++)
    {
        for(int j=0; j<c;j++)
        {
            cin>>mat1[i][j];
        }

    }
}
void mostrarMat1(int m[3][3],int f, int c)
{
    for(int i=0; i<f; i++)
    {
        cout <<"*---*---*---*"<<endl<<"| ";
        for(int j=0; j<c; j++)
        {
            cout <<m[i][j]<<" | ";
        }
        cout <<endl;
    }
    cout <<"*---*---*---*"<<endl;
}
int maximoDeLaFila(int mat1[3][3],int f, int c, int num)
{
    int mayor;

    for(int i=0; i<f;i++)
    {
        if(num==i)
        {
            mayor=mat1[i][0];
            for(int j=1; j<c; j++)
            {
                if(mat1[i][j+1]>mayor)
                {
                    mayor=mat1[i][j];
                }
            }
        }
    }
    return mayor;
}

///5. Hacer una función que reciba como parámetros una matriz de enteros de 10x10,
///y devuelva la suma de todos los componentes de la matriz.
void cargarMat5(int mat5[3][3], int f,int c)
{
    for(int i=0; i<f;i++)
    {
        for(int j=0; j<c;j++)
        {
            cin>>mat5[i][j];
        }

    }
}
void mostrarMat5(int mat5[3][3],int f, int c)
{
    for(int i=0; i<f; i++)
    {
        cout <<"*---*---*---*"<<endl<<"| ";
        for(int j=0; j<c; j++)
        {
            cout <<mat5[i][j]<<" | ";
        }
        cout <<endl;
    }
    cout <<"*---*---*---*"<<endl;
}
int sumaTotalMat5(int mat5[3][3],int f, int c)
{
    int suma=0;

    for(int i=0; i<f;i++)
    {
        for(int j=0; j<c; j++)
        {
            suma+=mat5[i][j];
        }
    }
    return suma;
}
