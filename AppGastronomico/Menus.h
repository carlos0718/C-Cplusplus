#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED


void menuPrincipal()
{
    bool seguir=false;
    char n[6];
    int op;
    char a=92;
    putchar('\n');
    putchar('\n');
    putchar('\n');
    putchar('\t');
    putchar('\t');
    cout<<"  ";linea();
    putchar('\t');
    putchar('\t');
    cout<<endl;
    cout<<endl;
    cout<<"\t\t"<<setw(33)<<"========"<<endl;
    cout<<"\t\t"<<setw(25)<<"||   ||"<<"  "<<" || "<<"  "<<"||"<<a<<a<<"   "<<"||"<<endl;
    cout<<"\t\t"<<setw(25)<<"||   ||"<<"  "<<" || "<<"  "<<"||"<<setw(2)<<a<<a<<"  "<<"||"<<endl;
    cout<<"\t\t"<<setw(25)<<"||   ||"<<"  "<<" || "<<"  "<<"||"<<setw(3)<<a<<a<<" "<<"||"<<endl;
    cout<<"\t\t"<<setw(25)<<"======"<<"  "<<" || "<<"  "<<"||"<<setw(4)<<a<<a<<""<<"||"<<endl;
    cout<<"\n\t\t"<<setw(35)<<"\tFACULTAD  REGIONAL  GENERAL  PACHECO"<<endl;
    cout<<"\t\t"<<setw(35)<<"\t TRABAJO PRÁCTICO #1"<<endl;
    putchar('\t');
    putchar('\t');
    cout<<"  ";linea();
    cin.ignore();
    system("cls");
    while(!seguir)
    {
        putchar('\n');
        putchar('\t');
        //linea();
        cout<<setw(26)<<"\tL  A  R  A"<<endl;
        cout<<setw(45)<<"\t  Aplicación de pedidos de comida online"<<endl;
        putchar('\t');
        linea();
        cout<<endl;
        cout<<endl;
        cout <<"\t\t    1.- PLATOS                               "<<endl;
        cout <<"\t\t    2.- CLIENTES                            "<<endl;
        cout <<"\t\t    3.- PEDIDOS                             "<<endl;
        cout <<"\t\t    4.- REPORTES                           "<<endl;
        cout <<"\t\t    5.- CONFIGURACIÓN                 "<<endl;
        cout <<"\t\t    0.- SALIR                                  "<<endl;
        putchar('\t');
        linea();
        putchar('\n');
        cout<<"\tIngrese una opción: ";
        cin.getline(n,5);
        if(validarOpcion(n))
        {
            op=atoi(n);
            switch(op)
            {
                case 1:
                {
                    system("cls");
                    submenuPlato();
                }
                break;
                case 2:
                {
                    system("cls");

                }
                break;
                case 3:
                {
                    system("cls");

                }
                break;
                case 4:
                {
                    system("cls");

                }
                break;
                case 0:
                {
                    system("cls");
                    seguir=true;
                }
                break;
                default:
                {
                    cout<<"\tOPCIÓN INCORRECTA"<<endl;
                }
            cin.ignore();
            }
        }
    }
}


void submenuPlato()
{
    Plato plt;
    bool seguir=false;
    char n[6];
    int op;

    while(!seguir)
    {
        system("cls");
        cout<<"\n";
        cout<<setw(33)<<"\t P  L  A  T  O  S"<<endl;
        cout<<"\t";
        linea();
        cout<<"\n"<<endl;
        cout<<"\t            1.- NUEVO PLATO                      "<<endl;
        cout<<"\t            2.- MODIFICAR PLATO                "<<endl;
        cout<<"\t            3.- LISTAR PLATO POR ID            "<<endl;
        cout<<"\t            4.- PLATOS POR RESTAURANT    "<<endl;
        cout<<"\t            5.- LISTAR TODOS LOS PLATOS   "<<endl;
        cout<<"\t            6.- ELIMINAR PLATO                  "<<endl;
        cout<<"\t            0.- SALIR                                    "<<endl;
        cout<<"\t";
        linea();
        cout<<endl;
        cout<<setw(20)<<"\tIngrese una opción: ";
        cin.getline(n,5);
        system("cls");
        if(validarOpcion(n))
        {
            op=atoi(n);
            switch(op)
            {
                case 1:
                {
                    plt=cargarPlato();
                    if(guardarPlatoEnArchivo(plt))
                        cout<<"\n\tPLATO REGISTRADO CORRECTAMENTE"<<endl;
                    else
                        cout<<"\n\tERROR AL GUARDAR REGISTRO"<<endl;
                    cin.ignore();
                }
                break;
                case 2:
                {
                    modificarRegistroPlato();
                    cin.ignore();
                }
                break;
                case 3:
                {
                    int id;
                    cout<<"\n\tINGRESE EL ID DE PLATO : ";
                    cin>>id;
                    cin.ignore();
                    system("cls");
                    validacionDeMuestra(id);
                }
                break;
                case 4:
                {
                    int id;
                    cout<<"\n\tINGRESE EL ID DE RESTAURANTE: ";
                    cin>>id;
                    cin.ignore();
                    system("cls");
                    validacionDeMuestraRestaurante(id);

                }
                break;
                 case 5:
                {
                    mostrarArchivoPlato();
                    cin.ignore();

                }
                break;
                case 6:
                {
                    bajaLogicoDeRegistroPlato();
                    cin.ignore();

                }
                break;
                case 0:
                {
                    seguir=true;
                }
                break;
                default:
                {
                    cout<<"\tOPCIÓN INCORRECTA"<<endl;
                }
             cin.get();
            system("cls");
            }
        }
    }
}
#endif // MENUS_H_INCLUDED
