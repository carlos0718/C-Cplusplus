#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

bool validarOpcion(char *numero)
{
    bool esNum=false;
    for(int i=0; i<strlen(numero); i++)
    {
        if(!(isdigit(numero[i])))
        {
            cout<<"\tINGRESE SOLO NUMEROS"<<endl;
            cin.ignore();
            return esNum;
        }
    }
    esNum=true;
    return esNum;
}
void validacionDeMuestraRestaurante(int id)
{
    int r=mostrarPlatoPorRestaurante(id);
    if(r==-1)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        cin.get();
        cin.ignore();
    }
}
void validacionDeMuestra(int id)
{
    int r=mostrarPlatoPorId(id);
    if(r==-1)
    {
        cout<<"\n\tERROR: ARCHIVO NO SE A ENCONTRADA O NO EXISTE "<<endl;
        cin.get();
        cin.ignore();
    }
    else if(r==-2)
    {
        cout<<"\n\t ID DADO DE BAJA O NO EXISTE EN EL ARCHIVO"<<endl;
        cin.get();
        cin.ignore();
    }
}

#endif // VALIDACIONES_H_INCLUDED
