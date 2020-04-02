#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "FUNCIONES.H"

using namespace std;

int main()
{
    /*int vecMayor[10];
    cargarVectorMayor(vecMayor,10);
    int ptoA=obtenerMaximo(vecMayor,10);
    cout << "El mayor es >>>"<< ptoA <<endl;

    int vecMenor[10];
    cargarVectorMenor(vecMenor,10);
    int ptoB=obtenerMinimo(vecMenor,10);
    cout <<"El menor es >>>" <<ptoB<<endl;
    */

    int cantidadVentas[15][10];
    float impoVenta[15][10];
    float vecSucursalVenta[10];
    int vecCantidadVentas[15];

    ponerCeroEncantidadVentas(cantidadVentas,15,10);
    ponerCeroImpoVenta(impoVenta,15,10);
    ponerCeroVecSucursalVenta(vecSucursalVenta,10);
    ponerCerovecCantidadVentas(vecCantidadVentas,15);

    cargarVentasMatEmp(cantidadVentas,impoVenta,vecSucursalVenta,vecCantidadVentas);
    cout<<"Ventas Cargadas Correctamente"<<endl;
    mostrarVentasPorSucursalYproducto(impoVenta);

    mostrarSucursalSinVentas(vecSucursalVenta,10);

    int mayor=mostrarProductoMasVendido(vecCantidadVentas,15);
    cout<<"El Producto más vendido es: "<<mayor<<endl;

    return 0;
}
