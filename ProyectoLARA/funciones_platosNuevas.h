#ifndef FUNCIONES_PLATOSNUEVAS_H_INCLUDED
#define FUNCIONES_PLATOSNUEVAS_H_INCLUDED

void ingresoPlatoNuevo()
{
    cls();
    logo();

    if( preguntar("Comenzar a cargar un nuevo plato?") == false )
    {
        return;
    }
    while(true)
    {
        cls();
        logo();
        Plato platoEntrante = pedirPlato();
        if(agregarPlato(platoEntrante))
        {
            cout<<"\nPlato agregado con exito"<<endl;
            msleep(1200);
        }
        else
        {
            cout<<"Error grave!"<<endl;
            cout<<"No se puede acceder al archivo"<<ARCHIVO_PLATOS<<endl;
            cout<<"Presione una tecla para salir"<<endl;
            anykey();
            exit(402);
        }
        if( preguntar("Cargar otro plato?") == false )
        {
            break;
        }
    }
    return;
}

struct Plato pedirPlato()
{
    Plato pl;
    pl.id = pedirIDvalidado();//ID
    cin.ignore();//el ignore fuera del ciclo para que no ignore parte de la cadena ingresada al iterar por el false del if
    char nom[49];
    pedirNombreValido(nom);
    strcpy(pl.nombre,nom);
    pl.costo_preparacion = pedirCostoPrepValido();
    pl.valor_venta = pedirValorVentaValido(pl.costo_preparacion);
    pl.tiempo_preparacion = pedirTiempoPrepValido();
    pl.id_restaurante = pedirIdRestauranteValido();
    pl.comision_restaurante = pedirComisionRestValido();
    pl.id_categoria = pedirIdCategoria();
    pl.estado = true;
    return pl;
};

int pedirIDvalidado()
{
    //cls();
    //logo();
    cout<<"Cargando un nuevo plato"<<endl;
    cout<<"Ingrese los datos a continuacion:";
    int id;
    while(true)
    {
        cout<<"\nID:";
        id = pedirEnteroValido();//valida tipo de dato
        if( !esPositivo(id) )        //valida positivo
        {
            cout<<"El ID debe ser un numero positivo."<<endl;
            msleep(1300);
            if( preguntar("Desea volver a intentar?")== false )
            {
                submenuPlatos();
            }
            else
                continue;
        }
        int existe = iD_PlatoExistente(id);
        if( existe )  //valida no existente
        {
            cout<<"\nError(Ya existe el ID). El ID debe ser unico!"<<endl;
            msleep(1300);
            if( preguntar("Desea volver a intentar?")== false )
            {
                submenuPlatos();
            }
            else
                continue;
        }
        break;
    }
    return id;
}

void pedirNombreValido(char *cad)
{
    while(true)
    {
        cout<<"\nNombre: ";
        fflush(stdin);
        cin.getline(cad,49);
        if( cad[0]!='\0' && cad[0]!=32 )
        {
            break;//validada
        }
        else
        {
            cout<<"Error: Debe ingresar un nombre. El primer caracter no puede ser un espacio en blanco"<<endl;
            msleep(1200);
            if( preguntar("Desea volver a intentar?")== false )
            {

                submenuPlatos();
            }
            else
                continue;
        }
    }
}

void pedirApellidoValido(char *cad)
{
    while(true)
    {
        cout<<"\nApellido:";
        fflush(stdin);
        cin.getline(cad,49);
        if( cad[0]!='\0' && cad[0]!=32 )
        {
            break;//validada
        }
        else
        {
            cout<<"Error: Debe ingresar un apellido. El primer caracter no puede ser un espacio en blanco"<<endl;
            msleep(1200);
            if( preguntar("Desea volver a intentar?")== false )
            {

                submenuPlatos();
            }
            else
                continue;
        }
    }
}

void pedirDomicilioValido(char *cad)
{
    while(true)
    {
        cout<<"\nDomicilio:";
        fflush(stdin);
        cin.getline(cad,49);
        if( cad[0]!='\0' && cad[0]!=32 )
        {
            break;//validada
        }
        else
        {
            cout<<"Error: Debe ingresar un apellido. El primer caracter no puede ser un espacio en blanco"<<endl;
            msleep(1200);
            if( preguntar("Desea volver a intentar?")== false )
            {

                submenuPlatos();
            }
            else
                continue;
        }
    }
}

float pedirCostoPrepValido()
{
    int costo;
    while(true)
    {
        cout<<"\nCosto de preparacion: ";
        costo = pedirFloatValido();
        if(costo <= 0)
        {
            cout<<"El costo de preparacion no puede ser negativo!"<<endl;
            msleep(1000);
            continue;
        }
        else
        {
            break; //validado.
        }
    }
    return costo;
}

float pedirValorVentaValido(int costo)
{
    float valor;
    while(true)
    {
        cout<<"\nValor de venta: ";
        valor = pedirEnteroValido();
        if(valor > costo) //si es mayor que el costo de preparacion es tambien mayor que cero(p.transitiva)
        {
            break;//validado.
        }
        else
        {
            cout<<"Valor de venta incorrecto. Debe ser mayor al costo de preparacion";
            msleep(1300);
            if( preguntar("Desea volver a intentar?")== false )
            {
                submenuPlatos();
            }
            else
                continue;
        }
    }
    return valor;
}

int pedirTiempoPrepValido()
{
    int tiempo;
    while(true)
    {
        cout<<"\nTiempo de preparacion: ";
        tiempo = pedirEnteroValido();
        if(tiempo >= 1)
        {
            break; // validado.
        }
        else
        {
            cout<<"Error: Ingrese los minutos que toma preparar el plato, no puede ser menor a 1"<<endl;
            msleep(1300);
            if( preguntar("Desea volver a intentar?")== false )
            {
                submenuPlatos();//esto funciona bien o puede traer problemas? ( puede intentar volver a esta funcion al terminar la funcion submenu? )
            }
            else
                continue;
        }

    }
    return tiempo;
}

int pedirIdRestauranteValido()
{
    int idRest;
    while(true)
    {
        cout<<"\nID del restaurante: ";
        idRest = pedirEnteroValido();

        if(idRest > 0)
        {
            break;
        }
        else
        {
            cout<<"Error: el id debe ser un numero entero positivo"<<endl;
            msleep(1300);
            if( preguntar("Desea volver a intentar?")== false )
            {
                submenuPlatos();
            }
            else
                continue;
        }
    }
    return idRest;
}

int pedirComisionRestValido()
{
    int comi;
    while(true)
    {
        cout<<"\nComision del restaurante: ";
        comi = pedirEnteroValido();

        if(comi >=0 && comi <=100)
        {
            break;//validado
        }
        else
        {
            cout<<"Error: La comision debe ser entre 0 y 100"<<endl;
            msleep(1300);
            if( preguntar("Desea volver a intentar?")== false )
            {
                submenuPlatos();
            }
            else
                continue;
        }
    }
    return comi;
}

int pedirIdCategoria()
{
    int idCat;
    while(true)
    {
        cout<<"\nID Categoria: ";
        idCat = pedirEnteroValido();

        if(idCat > 0)
        {
            break;
        }
        else
        {
            cout<<"Error: el id debe ser un numero entero positivo"<<endl;
            msleep(1300);
            if( preguntar("Desea volver a intentar?")== false )
            {
                submenuPlatos();
            }
            else
                continue;
        }
    }
    return idCat;
}
#endif // FUNCIONES_PLATOSNUEVAS_H_INCLUDED
