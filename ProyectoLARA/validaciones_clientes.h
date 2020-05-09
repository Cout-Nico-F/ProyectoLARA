#ifndef VALIDACIONES_CLIENTES_H_INCLUDED
#define VALIDACIONES_CLIENTES_H_INCLUDED

int validado_IdClienteAutonumerico()//devuelve un numero entero positivo AUTONUMERICO
{
    int id,cant;
    cant = cantidadClientes();
    if(cant == -1)
    {
        return -1;
    }
    id = cant+1;
    return id;
}

int pedirEnteroValido()//validacion del tipo de dato entero
{
    int entero;
    while(!(cin>>entero))
    {
        cout<<"\nError en el tipo de dato ingresado.\nIngrese un numero entero: ";
        cin.clear();
        cin.ignore(123,'\n');
    }
    return entero;
}

bool esPositivo(int numero)
{
    if( numero > 0)
        return 1;
    else
        return 0;
}

int validado_CpCliente()
{
    int cp = 0;
    while(cp<1000 || cp>9999)
    {
        cout<<"Codigo Postal: ";
        cp = pedirEnteroValido();

        if(cp>=1000 && cp<=9999)
        {
            break;
        }
        else
        {
            cout<<"Codigo Postal no valido. (Debe ser un entero entre 1000 y 9999)";
            Sleep(1300);
        }
    }
    return cp;
}

int validado_Dia (Fecha fe)
{
    while(true)
    {
        cout<<"Dia:";
        int dia = pedirEnteroValido();
        if( !esPositivo(dia) )
        {
            cout<<"El dia no puede ser un numero negativo"<<endl;
            Sleep(1200);
            continue;
        }
        if( !existeDia(fe) )
        {
            cout<<"El dia ingresado no existe en el calendario"<<endl;
            Sleep(1200);
            continue;
        }
        return dia;
    }

}

int validado_Mes()
{
    int mes;
    while(true)
    {
        cout<<"Mes:";
        mes = pedirEnteroValido();
        if(mes>12 || !esPositivo(mes))
        {
            cout<<"El mes no puede ser un numero negativo"<<endl;
            Sleep(1200);
            continue;
        }
        else
            break;
    }
    return mes;
}

int validado_Anio()
{
    int anio;
    while(true)
    {
        cout<<"Año:";
        anio = pedirEnteroValido();
        if (anio>1900)
        {
            break;
        }
        else
        {
            cout<<"El año ingresado no es valido    (Fuera de rango)"<<endl;
            Sleep(1200);
            continue;
        }
    }
}

bool existeDia(Fecha fe)
{
//segun el mes indicado comprueba si existe
    if(esBisiesto(fe.anio))
    {
        int cant_dias [12] = {31,29,31,30,31,30,31,31,30,31,30,31};
        if(fe.dia>cant_dias[fe.mes]) return 0;
        else return 1;
    }
    else
    {
        int cant_dias [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if(fe.dia>cant_dias[fe.mes]) return 0;
    }
    return 1;
}

bool esBisiesto(int anio)
{
    if (anio % 4 == 0)
    {
        if ( anio % 100 != 0)
        {
            return true;
        }
        else if (anio % 400 == 0)
        {
            return true;
        }
    }
    return false;
}
#endif // VALIDACIONES_CLIENTES_H_INCLUDED
