#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
struct Producto
{
    int id=0;
    char nombre[31]=" ";
    float precio=0;
    int stock=0;
    int stock_minimo=0;
    bool activo=true;

};
/**CABECERAS DE FUNCIONES*/
void mostrarRegistro(Producto);
int buscarProducto(int );
struct Producto leerProducto(int );
bool guardarProductoModificado(int , Producto );
/*****************************************/
/*bool validarID(Producto p,int n)
{
    bool existe=false;
    for(int i=0;i<tam;i++)
    {
        if(p[i].id==p[n].id && i!=n)
            existe=true;
    }
    return existe;
}*/
void gotoxy(int x, int y)
{
   HANDLE hCon;
   hCon = GetStdHandle(STD_OUTPUT_HANDLE);

   COORD dwPos;
   dwPos.X=x;
   dwPos.Y=y;
   SetConsoleCursorPosition(hCon,dwPos);
}
struct Producto cargarProducto()
{
    Producto p;
    cout<<"INGRESE ID DE PRODUCTO: ";
    cin>>p.id;
    cout<<"INGRESE NOMBRE DE PRODUCTO: ";
    cin>>p.nombre;
    cout<<"INGRESE EL PRECIO DEL PRODUCTO: "<<"$";
    cin>>p.precio;
    cout<<"INGRESE EL STOCK DEL PRODUCTO: ";
    cin>>p.stock;
    cout<<"INGRESE EL STOCK MINIMO: ";
    cin>>p.stock_minimo;
    p.activo;
    cout<<"\n\tPRODUCTO CARGADO CORRECTAMENTE"<<endl;
    cin.ignore();
    return p;
}
/**Funciones**/
bool guardarProducto(Producto aux)
{
    FILE *p;
    p=fopen(RUTA,"ab");
    if(p==NULL)
        return false;
    fwrite(&aux,sizeof(Producto),1,p);
    fclose(p);
    return true;
}
bool leerRegistro()
{
    Producto prd;
    FILE *p;
    p=fopen(RUTA,"rb");
    if(p==NULL)
        return false;
    cout<<"\n\t";
    cout<<setw(2)<<"||"<<setw(5)<<"ID"<<setw(5)<<"||"<<setw(10)<<"NOMBRE"<<setw(10)<<"||"<<setw(5)<<"PRECIO"<<setw(5)<<"||"<<setw(5)<<"STOCK"<<setw(5)<<"||"<<setw(5)<<"STOCK MÍNIMO"<<setw(5)<<"||"<<endl;
    cout<<"\t"<<"================================================================="<<endl;
    while(fread(&prd,sizeof(Producto),1,p)==1)
    {
        mostrarRegistro(prd);
    }
    fclose(p);
    return true;
}
/*bool pto1(Producto p, int i)
{
    bool cargo=true;
    int n, c;
    if(i<tam)
    {
        bool existe=true;
        cout<<"INGRESE ID DE PRODUCTO: ";
        cin>>c;

        existe=validarID(c,i);

        if(!existe)
        {
            cout<<"INGRESE NOMBRE DE PRODUCTO: ";
            cin>>p.nombre;
            cout<<"INGRESE EL PRECIO DEL PRODUCTO: "<<"$";
            cin>>p.precio;
            cout<<"INGRESE EL STOCK DEL PRODUCTO: ";
            cin>>p.stock;
            cout<<"INGRESE EL STOCK MINIMO: ";
            cin>>p.stock_minimo;

            cout<<"\tEL PRODUCTO SE CARGO CORRECTAMENTE"<<endl;
            cout<<"----------------------------------"<<endl;
        }
        else
            {cout<<"\tCODIGO DE ID YA EXISTENTE"<<endl;cargo=false; }
    }
    return cargo;
}*/
/*int validarPto2(Producto p,int n)
{
    int pos=-1;
    for(int i=0;i<tam;i++)
    {
        if(p[i].id==n)
            pos=i;
    }
    return pos;
}*/
/*void muestrarPto2(Producto *p,int i, int tam)
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

/*void pto3(Producto *p, int tam)
{
    int n;
    int j;
    cout<<"INGRESE ID DE PRODUCTO: ";
    cin>>n;
    j=validarPto2(p,n,tam);
    if(j>=0)
    {
        gotoxy(2,1);cout<<"==============================================================";
        gotoxy(2,2); cout<<"||";
        gotoxy(4,2);cout<<"ID";
        gotoxy(8,2);cout<<"||";
        gotoxy(14,2); cout<<"PRODUCTO";
        gotoxy(27,2); cout<<"||";
        gotoxy(30,2); cout<<"PRECIO";
        gotoxy(38,2);cout<<"||";
        gotoxy(41,2);cout<<"STOCK";
        gotoxy(47,2);cout<<"||";
        gotoxy(50,2);cout<<"STOCK MINIMO";
        gotoxy(63,2);cout<<"||";
        gotoxy(2,3);cout<<"==============================================================";

        gotoxy(2,4);cout<<"||";
        gotoxy(5,4);cout<<p[j].id;
        gotoxy(8,4);cout<<"||";
        gotoxy(11,4); cout<<p[j].nombre;
        gotoxy(27,4); cout<<"||";
        gotoxy(33,4); cout<<p[j].precio;
        gotoxy(38,4); cout<<"||";
        gotoxy(44,4);cout<<p[j].stock;
        gotoxy(47,4); cout<<"||";
        gotoxy(55,4); cout<<p[j].stock_minimo;
        gotoxy(63,4); cout<<"||";

        gotoxy(2,5);cout<<"=============================================================="<<endl;
    }
    else
        cout<<"\tEL CODIGO DE ID NO EXISTE EN LA BASE DE DATOS"<<endl;
}*/
/**FUNCIONES DE BAJA LÓGICA
*Cero: se hace funcion global-->darDeBajaProducto(): es la funcion global que hace la baja logica
  del producto solicitado.
*Primero: se busca la posicion del producto-->buscarProducto(cod)
*Segundo: se lee el producto en esa posicion-->leerProducto(pos)
*Tercero: se hace la modificacion del producto
*Cuarto: se guarda el producto modificado en el archivo-->guardarProductoModificado(pos, prd)
*/
void darDeBajaProducto()
{
    Producto prd;
    int pos;
    int cod;
    cout<<"\n\tINGRESE CODIGO DE PRODUCTO: ";
    cin>>cod;
    pos=buscarProducto(cod);
    if(pos==-1)
    {
        cout<<"'\n\tPRODUCTO NO EXISTE"<<endl;
        cin.ignore();
        return;
    }
    prd=leerProducto(pos);
    prd.activo=false;
    system("cls");
    if(guardarProductoModificado(pos,prd))
        cout<<"\n\tA DADO DE BAJA EL PRODUCTO "<<prd.nombre<<endl;
    else
        cout<<"\n\tERROR AL PROCESAR LA BAJA"<<endl;
    cin.ignore();
}
int buscarProducto(int id)
{
    Producto prd;
    int i=0;
    FILE *p;
    p=fopen(RUTA,"rb");
    if(p==NULL)
        return -2;
    while(fread(&prd,sizeof(Producto),1,p))
    {
        if(prd.id==id)
        {
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}
struct Producto leerProducto(int i)
{
    Producto prd;
    FILE *p;
    p=fopen(RUTA,"rb");
    if(p==NULL)
        return prd;
    fseek(p,sizeof(Producto)*i,0);
    fread(&prd,sizeof(Producto),1,p);
    fclose(p);
    return prd;
}
bool guardarProductoModificado(int i, Producto prd)
{
    FILE *p;
    p=fopen(RUTA,"rb+");
    if(p==NULL)
        return false;
    fseek(p,i*sizeof(Producto),0);
    fwrite(&prd,sizeof(Producto),1,p);
    fclose(p);
    return true;
}
//////////////////////////////////////////////
void mostrarRegistro(Producto p)
{
    //cout<<"\t";
    if(p.activo==true)
    {
        cout<<"\t"<<setw(2)<<"||"<<setw(5)<<p.id<<setw(5)<<"||"<<setw(10)<<p.nombre<<setw(10)<<"||"<<setw(5)<<p.precio<<setw(5)<<"||"<<setw(5)<<p.stock<<setw(5)<<"||"<<setw(5)<<p.stock_minimo<<setw(8)<<"||"<<endl;
        cout<<"\t"<<"=================================================================="<<endl;
    }


}
/**FUNCION PARA ACTUALIZAR/MODIFICAR REGISTROS**/
void actualizarRegistro()
{
    Producto prd;
    int id,pos;
    cout<<"'\n\tINGRESE EL CÓDIGO DE PRODUCTO: ";
    cin>>id;
    pos=buscarProducto(id);
    if(pos<0)
    {
        cout<<"\n\tPRODUCTO NO EXISTE EN EL REGISTRO"<<endl;
        return;
    }
    cout<<"\n\tPRODUCTO EXISTE "<<endl;
    cin.ignore();
    system("cls");
    prd=leerProducto(pos);
    mostrarRegistro(prd);
    cout<<"\n\tACTUALICE LOS DATOS DEL PRODUCTO"<<endl;
    prd=cargarProducto();
    if(guardarProductoModificado(pos,prd))
        cout<<"\n\tSE ACTUALIZÓ PRODUCTO CORRECTAMENTE"<<endl;
    else
        cout<<"\n\tERROR AL ACTUALIZAR PRODUCTO "<<endl;
}

#endif // FUNCIONES_H_INCLUDED
