#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <cstdio>
#include <cstdlib>
using namespace std;
 ///1)Dado un vector de enteros de 10 elementos.
 ///Hacer una función llamada obtenerMaximo que reciba
 ///el vector y el tamaño y devuelva el mayor valor del vector.
int obtenerMaximo(int*vec,int tam)
{
    int mayor=vec[0];

    for(int i=1;i<tam;i++)
    {
        if(vec[i]>mayor)
        {
            mayor=vec[i];
        }
    }
    return mayor;
}

void cargarVectorMayor(int *vec, int tam)
{
    for(int i=0;i<tam;i++)
    {
        cout<<"posicion "<<i<<" :";
        cin>>vec[i];
    }
}
 ///2)Dado un vector de enteros de 10 elementos.
 ///Hacer una función llamada obtenerMinimo que reciba
 ///el vector y el tamaño y devuelva el mayor valor del vector.
int obtenerMinimo(int*vec,int tam)
{
    int menor=vec[0];

    for(int i=1;i<tam;i++)
    {
        if(vec[i]<menor)
        {
            menor=vec[i];
        }
    }
    return menor;
}

void cargarVectorMenor(int *vec, int tam)
{
    for(int i=0;i<tam;i++)
    {
        cout<<"posicion "<<i<<" :";
        cin>>vec[i];
    }
}
///3)Un empresa dispone de 15 productos que se comercializan
///en 10 sucursales. Hacer un programa que permita cargar
///las ventas realizadas el mes pasado. Por cada venta se registra:
///Día de la venta, Código de producto (1 a 15), Código de sucursal (1 a 10) e importe de la venta.
///El fin de la carga de datos se indica con un día de la venta igual a cero. Calcular e informar:

///-  Por cada producto y sucursal, el total facturado.

///-  Las sucursales sin ventas el mes pasado.

///-  El producto que haya registrado la mayor cantidad de ventas.

void ponerCeroEncantidadVentas(int cantidadVentas[15][10], int f, int c)
{
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<c;j++)
        {
            cantidadVentas[i][j]=0;
        }
    }
}
void ponerCeroImpoVenta(float impoVenta[15][10],int f,int c)
{
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<c;j++)
        {
            impoVenta[i][j]=0;
        }
    }
}
void ponerCeroVecSucursalVenta(float *vecSucursalVenta,int tam)
{
    for(int i=0;i<tam;i++)
    {
        vecSucursalVenta[i]=0;
    }
}
void ponerCerovecCantidadVentas(int *vecCantidadVentas, int tam)
{
   for(int i=0;i<tam;i++)
    {
        vecCantidadVentas[i]=0;
    }
}
void cargarVentasMatEmp(int cantidadVentas[15][10], float impoVenta[15][10],float *vecSucursalVenta,int *vecCantidadVentas)
{
    int diaVenta;
    int codSucursal;
    int codProducto;
    int venta;
    int cantidad;


    cout<<"Dia de Venta: ";
    cin >>diaVenta;

    while(diaVenta!=0)
    {
        cout<<"Ingrese Codigo de Producto: ";
        cin>>codProducto;
        cout<<"Ingrese Codigo de Sucursal: ";
        cin>>codSucursal;
        cout<<"Importe de Venta: ";
        cin >>venta;
        cout<<"Ingrese la cantidad vendida de producto: ";
        cin>>cantidad;

        impoVenta[codProducto-1][codSucursal-1]+=venta;
        vecSucursalVenta[codSucursal-1]+=venta;
        cantidadVentas[codProducto-1][codSucursal-1]+=cantidad;
        vecCantidadVentas[codProducto-1]+=cantidad;


        cout<<"------------------------------\n"<<endl;
        cout<<"Dia de Venta: ";
        cin >>diaVenta;


    }
    cout<<"\tFIN DE LA CARGA"<<endl;
    cout<<"------------------------------\n"<<endl;
}
void mostrarVentasPorSucursalYproducto(float impoVenta[15][10])
{
    char seguir= 's';
    int x,y;
    while(seguir=='s')
    {
        cout<<"Ingrese el numero de Sucursal: ";
        cin>>x;
        cout<<"Ingrese el  numero de Producto: ";
        cin>>y;

        cout<<"La sucursal "<< x <<" Facturo: "<<impoVenta[y][x]<<"$ "<< " del producto "<< y <<endl;

        cout<<"Seleccionara otra sucursal? s/n :";
        cin>>seguir;
        cout<<"------------------------------\n"<<endl;
    }
}

void mostrarSucursalSinVentas(float *vecSucursalVenta, int sucursal)
{
    cout<<"Sucursales sin ventas: "<<endl;
    for(int i=0;i<sucursal;i++)
    {
        if(vecSucursalVenta[i]==0)
            cout<<">>>"<<i+1<<endl;
    }
}

int mostrarProductoMasVendido(int *vecCantidadVentas, int producto)
{
    int mayor=vecCantidadVentas[0];
    int codProducto;
    for(int i=1; i<producto;i++)
    {
        if(vecCantidadVentas[i]>mayor)
        {
            mayor=vecCantidadVentas[i];
            codProducto= i+1;
        }
    }
    return codProducto;
}
#endif // FUNCIONES_H_INCLUDED
