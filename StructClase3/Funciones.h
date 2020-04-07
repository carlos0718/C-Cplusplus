#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

struct Producto
{
    int id=0;
    char nombre[31]=" ";
    float precio=0;
    int stock=0;
    int stock_minimo=0;

};
bool validarID(Producto *p,int n, int tam)
{
    bool existe=false;
    for(int i=0;i<tam;i++)
    {
        if(p[i].id==p[n].id && i!=n)
            existe=true;
    }
    return existe;
}
void cargarProducto(Producto *p, int tam,int i)
{
    cout<<"INGRESE ID DE PRODUCTO: ";
    cin>>p[i].id;
    cout<<"INGRESE NOMBRE DE PRODUCTO: ";
    cin>>p[i].nombre;
    cout<<"INGRESE EL PRECIO DEL PRODUCTO: "<<"$";
    cin>>p[i].precio;
    cout<<"INGRESE EL STOCK DEL PRODUCTO: ";
    cin>>p[i].stock;
    cout<<"INGRESE EL STOCK MINIMO: ";
    cin>>p[i].stock_minimo;

    cout<<"\tEL PRODUCTO SE CARGO CORRECTAMENTE"<<endl;
    cout<<"----------------------------------"<<endl;
}
bool pto1(Producto *p,int tam, int i)
{
    bool cargo=true;
    int n;
    if(i<tam)
    {
        bool existe=true;
        cout<<"INGRESE ID DE PRODUCTO: ";
        cin>>p[i].id;

        existe=validarID(p,i,tam);

        if(!existe)
        {
            cout<<"INGRESE NOMBRE DE PRODUCTO: ";
            cin>>p[i].nombre;
            cout<<"INGRESE EL PRECIO DEL PRODUCTO: "<<"$";
            cin>>p[i].precio;
            cout<<"INGRESE EL STOCK DEL PRODUCTO: ";
            cin>>p[i].stock;
            cout<<"INGRESE EL STOCK MINIMO: ";
            cin>>p[i].stock_minimo;

            cout<<"\tEL PRODUCTO SE CARGO CORRECTAMENTE"<<endl;
            cout<<"----------------------------------"<<endl;
        }
        else
            {cout<<"\tCODIGO DE ID YA EXISTENTE"<<endl;cargo=false; }
    }
    return cargo;
}
int validarPto2(Producto *p,int n, int tam)
{
    int pos=-1;
    for(int i=0;i<tam;i++)
    {
        if(p[i].id==n)
            pos=i;
    }
    return pos;
}
void muestrarPto2(Producto *p,int i, int tam)
{
    //system("color B");///AGUAMARINA
    cout<<" ID "<<" PRODUCTO "<<"  PRECIO "<<"  STOCK "<<"  STOCK MINIMO "<<endl;
    cout<<"-------------------------------------------------"<<endl;
    //system("color C");///ROJO CLARO
    cout<<" "<<p[i].id<<setw(10)<<p[i].nombre<<setw(8)<<p[i].precio<<setw(10)<<p[i].stock<<setw(10)<<p[i].stock_minimo<<endl;

    cout<<"-----------------------------------------------"<<endl;
}
void pto2(Producto *p,int tam)
{
    int n;
    char act='n';
    int j;
    cout<<"INGRESE ID DE PRODUCTO: ";
    cin>>n;

    j=validarPto2(p,n,tam);

    if(j>=0)
    {
        cout<<"t\ ID DE PRODUCTO SI EXISTE"<<endl;

        cin.ignore();
        cin.get();
        system("cls");

        muestrarPto2(p,j,tam);

        cout<<"=============================================="<<endl;
        cout<<"\tDESEA ACTUALIZAR LOS DATOS(s/n)? ";
        cin>>act;
        if(act=='s')
        {
            cout<<"INGRESE NOMBRE DE PRODUCTO: ";
            cin>>p[j].nombre;
            cout<<"INGRESE EL PRECIO DEL PRODUCTO: "<<"$";
            cin>>p[j].precio;
            cout<<"INGRESE EL STOCK DEL PRODUCTO: ";
            cin>>p[j].stock;
            cout<<"INGRESE EL STOCK MINIMO: ";
            cin>>p[j].stock_minimo;

            cout<<"\tEL PRODUCTO SE ACTUALIZO CORRECTAMENTE"<<endl;
            cout<<"----------------------------------"<<endl;
        }
    }
    else
    {
        cout<<"\tCODIGO DE ID NO EXISTE EN LA BASE DE DATOS"<<endl;
    }
}

void pto3(Producto *p, int tam)
{
    int n;
    int j;
    cout<<"INGRESE ID DE PRODUCTO: ";
    cin>>n;
    j=validarPto2(p,n,tam);
    if(j>=0)
    {
        //system("color B");///AGUAMARINA
        cout<<"||"<<" ID "<<"||"<<" PRODUCTO "<<"   ||"<<"  PRECIO "<<" ||"<<"  STOCK "<<"||"<<"  STOCK MINIMO "<<"||"<<endl;
        cout<<"==========================================================="<<endl;
       // system("color C");///ROJO CLARO
        cout<<"|| "<<p[j].id<<setw(4)<<"||"<<setw(10)<<p[j].nombre<<setw(5)<<"||"<<setw(6)<<p[j].precio<<setw(6)<<"||"<<setw(5)<<p[j].stock<<setw(5)<<"||"<<setw(9)<<p[j].stock_minimo<<setw(8)<<"||"<<endl;

        cout<<"==========================================================="<<endl;
    }
    else
        cout<<"\tEL CODIGO DE ID NO EXISTE EN LA BASE DE DATOS"<<endl;
}
void pto4(Producto *p, int tam)
{
    Producto mayor;
    for(int i=0;i<tam;i++)
    {
        for(int j=1;j<tam;j++)
        {
            if(p[j].precio>p[i].precio)
            {
                mayor=p[j];
                p[j]=p[i];
                p[i]=mayor;
            }
        }
    }
}

void mostrarPto4(Producto *p, int tam)
{
    cout<<"||"<<" ID "<<"||"<<" PRODUCTO "<<"   ||"<<"  PRECIO "<<" ||"<<"  STOCK "<<"||"<<"  STOCK MINIMO "<<"||"<<endl;
    cout<<"============================================================="<<endl;
    for(int j=0;j<tam;j++)
    {

        cout<<"|| "<<p[j].id<<setw(4)<<"||"<<setw(10)<<p[j].nombre<<setw(5)<<"||"<<setw(6)<<p[j].precio<<setw(6)<<"||"<<setw(5)<<p[j].stock<<setw(5)<<"||"<<setw(9)<<p[j].stock_minimo<<setw(8)<<"||"<<endl;

        cout<<"============================================================="<<endl;
    }
}
#endif // FUNCIONES_H_INCLUDED
