#ifndef VALIDACIONES_CLIENTES_H_INCLUDED
#define VALIDACIONES_CLIENTES_H_INCLUDED

int validado_IdAutonumerico(int archivo)//devuelve un numero entero positivo AUTONUMERICO segun el archivo indicado
{
    int cant;
    cant = cantidadRegistros(archivo)+1;
    return cant;
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

float pedirFloatValido()
{
    float f;
    while(!(cin>>f))
    {
        cout<<"\nError en el tipo de dato ingresado.\nIngrese un numero: ";
        cin.clear();
        cin.ignore(123,'\n');
    }
    return f;
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
            cout<<"Codigo Postal no valido. (Debe ser un entero entre 1000 y 9999)"<<endl;

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
            cout<<"El dia debe ser un numero mayor a cero"<<endl;
            msleep(1200);
            continue;
        }
        if( !existeDia(fe,dia) )
        {
            cout<<"El dia ingresado no existe en el calendario"<<endl;
            msleep(1200);
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
            cout<<"El mes no puede ser un numero negativo ni mayor a 12"<<endl;
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
            msleep(1200);
            continue;
        }
    }
    return anio;
}

bool existeDia(Fecha fe,int dia)
{
//segun el mes y año indicado comprueba si existe
    if(esBisiesto(fe.anio))
    {
        int cant_dias_bisiesto [12] = {31,29,31,30,31,30,31,31,30,31,30,31};
        if(dia>cant_dias_bisiesto[fe.mes-1])
            return 0;
        else
            return 1;
    }
    else
    {
        int cant_dias [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if(dia>cant_dias[fe.mes-1])
            return 0;
    }
    return 1;
}

bool esBisiesto(int anio) //revisar
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

//    char mail[50];
//    while(true)
//    {
//        cout<<"Email:";
//        cin.getline(mail,50);
//        ///estandard RFC2822 regex obtenida de: https://regexr.com/2rhq7
//        const regex expresion ("[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*@(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?");
//
//        if( regex_match(mail,expresion) ) //devuelve 1 si es valida o 0 si no lo es.
//        {
//            break;
//        }
//        else
//        {
//            cout<<"Mail invalido, intente nuevamente"<<endl;
//            Sleep(1200);
//        }
//    }
//    return mail;
//}
void validado_EmailCliente(char *cad)
{

    while(true)
    {
        cout<<"Email:";
        cin.getline(cad,50);
        ///estandard RFC2822 regex obtenida de: https://regexr.com/2rhq7
        const regex expresion ("[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*@(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?");

        if( regex_match(cad,expresion) ) //devuelve 1 si es valida o 0 si no lo es.
        {
            break;
        }
        else
        {
            cout<<"Mail invalido, intente nuevamente"<<endl;
            msleep(1200);
        }
    }
    return;
}

#endif // VALIDACIONES_CLIENTES_H_INCLUDED
