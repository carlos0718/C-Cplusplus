#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED
struct Plato;

struct Plato cargarPlato();

struct Plato leerRegistroPlato(int);

bool guardarPlatoEnArchivo(Plato);

int mostrarPlatoPorId(int );

int cantidadPlatos();

void modificarRegistroPlato();

bool guardarRegistroActualizado(int,Plato);

void validacionDeMuestra(int );

void mostrarArchivoPlato();

void validacionDeMuestraRestaurante(int );

int mostrarPlatoPorRestaurante(int );

void bajaLogicoDeRegistroPlato();

bool validarNombrePlato(char *);

void menuPrincipal();

void submenuPlato();

void linea();

void linea1();
#endif // PROTOTIPOS_H_INCLUDED
