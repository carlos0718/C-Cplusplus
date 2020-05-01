#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

struct Plato
{
    int id_plato;
    char nombre[50];
    float costo_preparacion;
    float valor_venta;
    int tiempo_preparacion;
    int id_restaurante;
    int comision_restaurante;
    int id_categoria;
    bool estado=true;
};
Plato cargarPlato()
{
    Plato plt;
    cout<<"\n\tNOMBRE DEL PLATO : ";
    cin.getline(plt.nombre,50);
    while(*plt.nombre=='\0' || validarNombrePlato(plt.nombre))
    {
        system("cls");
        cout<<"\tNOMBRE DEL PLATO : ";
        cin.getline(plt.nombre,50);
    }

    cout<<"\tCOSTO DE PREPARACÓN : $";
    cin>>plt.costo_preparacion;
    while(plt.costo_preparacion<=0)
    {
        cout<<"\e[A"; ///Esta líinea de codigo la reemplacé por el system("cls"), ya que al ingresar al while hace que se quede en la misma posicion hasta ingresar un valor válido, y no borrarme todo lo anterior.
        cout<<"\tCOSTO DE PREPARACÓN : $";
        cin>>plt.costo_preparacion;
    }

    cout<<"\tPRECIO DE VENTA DEL PLATO : $";
    cin>>plt.valor_venta;
    while(plt.valor_venta<=0 || plt.valor_venta<plt.costo_preparacion)
    {
        cout<<"\e[A";
        cout<<"\tPRECIO DE VENTA DEL PLATO : $";
        cin>>plt.valor_venta;
    }

    cout<<"\tTIEMPO DE PREPARACIÓN DEL PLATO : ";
    cin>>plt.tiempo_preparacion;
    while(plt.tiempo_preparacion<=0)
    {
        cout<<"\e[A";
        cout<<"\tTIEMPO DE PREPARACIÓN DEL PLATO : ";
        cin>>plt.tiempo_preparacion;
    }

    cout<<"\tID DEL RESTAURANTE : ";
    cin>>plt.id_restaurante;
    while(plt.id_restaurante<=0)
    {
        cout<<"\e[A";
        cout<<"\tID DEL RESTAURANTE : ";
        cin>>plt.id_restaurante;
    }

    cout<<"\tCOMISIÓN PARA EL RESTAURANTE : ";
    cin>>plt.comision_restaurante;
    while( plt.comision_restaurante<0  ||plt.comision_restaurante>100)
    {
        cout<<"\e[A";
        cout<<"\tCOMISIÓN PARA EL RESTAURANTE : ";
        cin>>plt.comision_restaurante;
    }

    cout<<"\tID DE CATEGORÍA : ";
    cin>>plt.id_categoria;
    while( plt.id_categoria<=0)
    {
        cout<<"\e[A";
        cout<<"\tID DE CATEGORÍA : ";
        cin>>plt.id_categoria;
    }

    plt.id_plato=(cantidadPlatos()+1)*100;
    plt.estado;
    cin.ignore();
    return plt;
}
bool guardarPlatoEnArchivo(Plato plt)
{
    FILE *p;
    p=fopen(ARCHIVO,"ab");

    if(p==NULL)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        return false;
    }
    fwrite(&plt,sizeof(Plato),1,p);
    fclose(p);
    return true;
}
int mostrarPlatoPorId(int id)
{
    Plato plt;
    int i=0;
    FILE *p;
    p=fopen(ARCHIVO,"rb");
    if(p==NULL)
        return -1;
    cout<<"\n";
    cout<<"\tID "<<setw(4)<<"| "<<setw(10)<<" NOMBRE "<<setw(8)<<" |"<<" COSTO($) "<<setw(2)<<" |"<<" VENTA($)";
    cout<<setw(2)<<" |"<<" TIEMPO PREPACIÓN(min) "<<setw(2)<<" |"<<" ID RESTAURANTE "<<setw(2)<<" |"<<" COMISIÓN(%) "<<setw(2)<<" |"<<" ID CATEGORÍA "<<endl;
    cout<<"\t";linea1();
    cout<<endl;
    while(fread(&plt,sizeof(Plato),1,p))
    {
        if(plt.id_plato==id&&plt.estado)
        {
            cout<<"\t"<<setw(5)<<left<<plt.id_plato<<" "<<setw(20)<<plt.nombre<<" "<<setw(12)<<plt.costo_preparacion<<" ";
            cout<<setw(15)<<plt.valor_venta<<" "<<setw(20)<<plt.tiempo_preparacion<<"  "<<setw(15)<<plt.id_restaurante<<"   ";
            cout<<setw(10)<<plt.comision_restaurante<<"   "<<setw(2)<<plt.id_categoria<<endl;
            cout<<"\t";linea1();
            cout<<endl;
            fclose(p);
            cin.get();
            //cin.ignore();
            return i; ///retorna entero positivo para validar plato y tambien retorna la posicion del registro para ser usado en la funcion de modificar o dar de baja registro
        }
        i++;
    }
    fclose(p);
    return -2;
}

int cantidadPlatos()
{
    int id,tam,pos;
    FILE *p;
    p=fopen(ARCHIVO,"ab");
    if(p==NULL)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        return -1;
    }
    fseek(p,0,SEEK_END);
    pos=ftell(p);
    tam=sizeof(Plato);
    id=pos/tam;

    fclose(p);
    return id;

}
void modificarRegistroPlato()
{
    Plato plt;
    int id;
    cout<<"\n\t======== ACTUALIZACIÓN DE DATOS  ========"<<endl;
    cout<<"\n\tINGRESE EL ID DE PLATO : ";
    cin>>id;
    int pos=mostrarPlatoPorId(id);
    if(pos==-1)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        cin.get();
        cin.ignore();
    }
    else if(pos==-2)
    {
        cout<<"\n\t ID DADO DE BAJA O NO EXISTE EN EL ARCHIVO"<<endl;
        cin.get();
        cin.ignore();
    }

    plt=leerRegistroPlato(pos);
    //modificarPlato(plt);
    cout<<"\n\t*Los únicos datos que puede MODIFICAR son el COSTO DE VENTA y el TIEMPO DE PREPARACIÓN"<<endl;
    cout<<"\n\tPRECIO DE VENTA DEL PLATO : $";
    cin>>plt.valor_venta;
    while(plt.valor_venta<=0 || plt.valor_venta<plt.costo_preparacion)
    {
        cout<<"\e[A";
        cout<<"\n\tPRECIO DE VENTA DEL PLATO : $";
        cin>>plt.valor_venta;
    }

    cout<<"\n\tTIEMPO DE PREPARACIÓN DEL PLATO : ";
    cin>>plt.tiempo_preparacion;
    while(plt.tiempo_preparacion<=0)
    {
        cout<<"\e[A";
        cout<<"\n\tTIEMPO DE PREPARACIÓN DEL PLATO : ";
        cin>>plt.tiempo_preparacion;
    }
    if(guardarRegistroActualizado(pos,plt))
        cout<<"\n\tCAMBIOS GUARDADOS"<<endl;
    else
        cout<<"\n\tERROR AL GUARDAR CAMBIOS"<<endl;
    cin.ignore();
}
Plato leerRegistroPlato(int pos)
{
    Plato plt;
    FILE *p;
    p=fopen(ARCHIVO,"rb");
    if(p==NULL)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        plt.id_plato=-1;
        return plt;
    }
    fseek(p,pos*sizeof(Plato),SEEK_SET);
    fread(&plt,sizeof(Plato),1,p);
    fclose(p);

    return plt;
}

bool guardarRegistroActualizado(int pos,Plato plt)
{
    FILE *p;
    p=fopen(ARCHIVO,"rb+");
    if(p==NULL)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        return false;
    }
    fseek(p,pos*sizeof(Plato),SEEK_SET);
    fwrite(&plt,sizeof(Plato),1,p);
    fclose(p);

    return true;
}
void mostrarArchivoPlato()
{
    Plato plt;
    FILE *p;
    p=fopen(ARCHIVO,"rb");
    if(p==NULL)
        return;
    cout<<"\n";
    cout<<"\tID "<<setw(4)<<"|"<<setw(10)<<" NOMBRE "<<setw(12)<<"|"<<" COSTO($)"<<setw(4)<<"|"<<" VENTA($)";
    cout<<setw(4)<<"|"<<" TIEMPO PREPACIÓN(min) "<<setw(2)<<"|"<<" ID RESTAURANTE "<<setw(2)<<"|"<<" COMISIÓN(%)"<<setw(2)<<"|"<<" ID CATEGORÍA "<<endl;
    cout<<"\t";linea1();
    cout<<endl;
    while(fread(&plt,sizeof(Plato),1,p))
    {
        if(plt.estado)
        {

            cout<<"\t"<<setw(6)<<left<<plt.id_plato<<" "<<setw(22)<<plt.nombre<<" "<<setw(15)<<plt.costo_preparacion<<" ";
            cout<<setw(15)<<plt.valor_venta<<" "<<setw(20)<<plt.tiempo_preparacion<<"  "<<setw(15)<<plt.id_restaurante<<"   ";
            cout<<setw(10)<<plt.comision_restaurante<<"   "<<setw(2)<<plt.id_categoria<<endl;
            cout<<"\t";linea1();
            cout<<endl;
        }
    }
    fclose(p);
}
int mostrarPlatoPorRestaurante(int id)
{
    Plato plt;
    FILE *p;
    p=fopen(ARCHIVO,"rb");
    if(p==NULL)
        return -1;
    cout<<"\n";
    cout<<"\tID "<<setw(4)<<"| "<<setw(10)<<" NOMBRE "<<setw(8)<<"| "<<" COSTO($) "<<setw(2)<<" | "<<" VENTA($)";
    cout<<setw(2)<<"| "<<" TIEMPO PREPACIÓN(min) "<<setw(2)<<" | "<<" ID RESTAURANTE "<<setw(2)<<"| "<<" COMISIÓN(%) "<<setw(2)<<"| "<<" ID CATEGORÍA "<<endl;
    cout<<"\t";linea1();
    cout<<endl;
    while(fread(&plt,sizeof(Plato),1,p))
    {
        if(plt.id_restaurante==id&&plt.estado)
        {
            cout<<"\t"<<setw(6)<<left<<plt.id_plato<<" "<<setw(20)<<plt.nombre<<" "<<setw(10)<<plt.costo_preparacion<<" ";
            cout<<setw(15)<<plt.valor_venta<<" "<<setw(20)<<plt.tiempo_preparacion<<"  "<<setw(15)<<plt.id_restaurante<<"   ";
            cout<<setw(10)<<plt.comision_restaurante<<"   "<<setw(2)<<plt.id_categoria<<endl;
            cout<<"\t";linea1();
            cout<<endl;

        }
    }
    cin.get();
    fclose(p);
    return 1;
}
void bajaLogicoDeRegistroPlato()
{
    Plato plt;
    int id;
    cout<<"\n\t======== DAR DE BAJA REGISTRO ========"<<endl;
    cout<<"\n\tINGRESE EL ID DE PLATO : ";
    cin>>id;
    int pos=mostrarPlatoPorId(id);
    if(pos==-1)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        cin.get();
        cin.ignore();
    }
    else if(pos==-2)
    {
        cout<<"\n\t ID DADO DE BAJA O NO EXISTE EN EL ARCHIVO"<<endl;
        cin.get();
        cin.ignore();
    }

    plt=leerRegistroPlato(pos);
    plt.estado=false;
    if(guardarRegistroActualizado(pos,plt))
        cout<<"\n\tPLATO DADO DE BAJA CORRECTAMENTE"<<endl;
    else
        cout<<"\n\tERROR AL DAR LA BAJA DEL PLATO"<<endl;
}
bool validarNombrePlato(char n[50])
{
    Plato plt;
    FILE *p;
    p=fopen(ARCHIVO,"rb");
    if(p==NULL)
        return false;
    while(fread(&plt,sizeof(Plato),1,p))
    {
        if(strcmp(n,plt.nombre)==0)
        {
            cout<<"tNOMBRE DE PLATO YA EXISTE"<<endl;
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}
void linea()
{
    for(int i=0;i<50;i++)
        putchar('_');
}
void linea1()
{
    for(int i=0;i<122;i++)
        putchar('_');
}
#endif // FUNCIONES_H_INCLUDED
