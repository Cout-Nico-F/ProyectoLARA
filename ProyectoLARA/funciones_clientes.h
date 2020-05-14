#ifndef FUNCIONES_CLIENTES_H_INCLUDED
#define FUNCIONES_CLIENTES_H_INCLUDED

void submenuClientes()
{
    while(true)
    {
        cls();
        logo();

        gotoxy(16,15);
        cout<<" |1|-Nuevo cliente              "<<endl;
        gotoxy(16,16.5);
        cout<<" |2|-Modificar  cliente         "<<endl;
        gotoxy(16,17.5);
        cout<<" |3|-Listar cliente por ID     "<<endl;
        gotoxy(16,18);
        cout<<" |4|-Listar todos los cliente      "<<endl;
        gotoxy(16,19.5);
        cout<<" |5|-Eliminar cliente"<<endl;
        gotoxy(17,21);
        cout<<"- - - - - - - - - - - - - - -     "<<endl;
        gotoxy(16,22);
        cout<<" |0|-Volver al menu principal       "<<endl;


//        gotoxy(16,20.5);
//        cout<<" |0|-Volver al menu principal         "<<endl;

        gotoxy(48,16);
        cout<<"    Ingrese la opcion deseada: ";
        int op;
        while(!(cin>>op))
        {
            gotoxy(43,17);
            cout<<"Error: la opcion debe ser numerica.";
            gotoxy(43,18);
            cout<<"Ingrese la opcion deseada o 0 para salir: ";
            cin.clear();
            cin.ignore(123,'\n');
        }
        switch (op)
        {
        case 1:
        {
            nuevoCliente();
        }
        break;
        case 2:
        {
            modificarCliente();
        }
        break;
        case 3:
        {
            listarCliente_porID();
        }
        break;
        case 4:
        {
            listarTodosLosClientes();
        }
        break;
        case 5:
        {
            darDeBajaCliente();
        }
        break;
        case 6:
        {

        }
        break;
        case 0:
        {
            return;
        }
        break;
        case 101:
        {
            borrarTodo(ARCHIVO_CLIENTES);
        }
        break;
        default:
        {
            cout<<"Error, debe elegir una opcion del menu"<<endl;
            msleep(600);
        }
        break;
        }

    }
}

void nuevoCliente()
{
    if( preguntar("Desea cargar un nuevo cliente ?") == false )
    {
        return;
    }

    Cliente nuevoReg = pedirCliente();
    if(agregarCliente(nuevoReg))//devuelve 1 si pudo agregarlo o 0 si no pudo
    {
        setColor(GREEN);
        cout<<"Registro añadido correctamente"<<endl;
        setColor(GREY);
        cout<<"Presione una tecla para continuar"<<endl;
        anykey();
    }
    else
        setColor(GREEN);
        cout<<"Error en el archivo "<<ARCHIVO_CLIENTES<<endl;
        setColor(GREY);
        cout<<"Presione una tecla para continuar"<<endl;
        anykey();
}

Cliente pedirCliente()
{
    Cliente cli;
    asignarIdAutonumerico(&cli.id,1);

    cout<<"Nombre:";
    cin.ignore();
    cin.getline(cli.nombre,50);

    cout<<"\nApellido:";
    cin.getline(cli.apellido,50);

    char mail[49];
    validado_EmailCliente(mail);
    strcpy(cli.mail,mail);

    //strcpy(cli.mail,validado2_EmailCliente());//no funciona en codeblocks(pero si en vs). Escribe en memoria incorrecta.

    cout<<"\Domicilio:";
    cin.getline(cli.domicilio,100);

    cout<<"\n";
    cli.cp = validado_CpCliente();

    cli.fecha_nacimiento.anio = validado_Anio();
    cli.fecha_nacimiento.mes = validado_Mes();
    cli.fecha_nacimiento.dia = validado_Dia(cli.fecha_nacimiento);
    cli.estado = true;
    return cli;
}

int cantidadRegistros(int num_archivo)
{
    if(num_archivo==1)
    {
        int cant;
        FILE *p;
        p=fopen(ARCHIVO_CLIENTES,"ab+");
        if(p==NULL)
        {
            return -1;
        }
        fseek(p,0,SEEK_END);
        cant = ftell(p)/sizeof(Cliente);
        fclose(p);
        return cant;
    }
    if(num_archivo == 2)
    {
        int cant;
        FILE *p;
        p=fopen(ARCHIVO_PEDIDOS,"ab+");
        if(p==NULL)
        {
            return -1;
        }
        fseek(p,0,SEEK_END);
        cant = ftell(p)/sizeof(Pedido);
        fclose(p);
        return cant;
    }
    else
        cout<<"HAY UN ERROR EN EL NUMERO DE ARCHIVO PASADO A CANTIDADREGISTROS()"<<endl;
        exit(888);

}

void mostrarCliente(Cliente cli)
{
    cout<<"ID: . . . . . . . . "<<cli.id<<endl;
    cout<<"Nombre: . . . . . . "<<cli.nombre<<endl;
    cout<<"Apellido: . . . . . "<<cli.apellido<<endl;
    cout<<"Mail: . . . . . . . "<<cli.mail<<endl;
    cout<<"Domicilio: . . . .  "<<cli.domicilio<<endl;
    cout<<"Cp: . . . . . . . . "<<cli.cp<<endl;
    cout<<"Fecha Nacimiento: . "<<cli.fecha_nacimiento.dia<<"/"<<cli.fecha_nacimiento.mes<<"/"<<cli.fecha_nacimiento.anio;
    cout<<"\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
}

bool agregarCliente(Cliente cli)
{
    FILE *p;
    p=fopen(ARCHIVO_CLIENTES,"ab");
    if(p==NULL)
    {
        return 0;
    }
    if(fwrite(&cli,sizeof (Cliente),1,p))
    {
        fclose(p);
        return 1;
    }
    fclose(p);
    return 0;
}

bool preguntar(const char *pregunta)
{
    while (true)
    {
        cls();
        logo();
        fflush(stdin);
        cout<<"&--- "<<pregunta<<"--&"<<endl;
        cout<<"&--- [ 1 ] Si --------------------------&"<<endl;
        cout<<"&--- [ 0 ] No (Volver al Menu)----------&"<<endl;
        cout<<"       ";
        int op = pedirEnteroValido();
        if(op==0)
        {
            return 0;
        }
        if(op==1)
        {
            return 1;
        }
        cout<<"Opcion incorrecta"<<endl;
        msleep(1300);
    }
}

void asignarIdAutonumerico(int* x,int archivo)//practica de punteros
{
    int auxId = validado_IdAutonumerico(archivo);
    if(auxId<1)
    {
        cout<<"Error grave! No se puede asignar el nuevo ID"<<endl;
        cout<<"No se puede acceder al archivo "<<ARCHIVO_CLIENTES<<endl;
        cout<<"Presione una tecla para salir"<<endl;
        anykey();
        exit(404);
    }
    else *x = auxId;
}

//La opción Modificar Cliente deberá solicitar el ID de un cliente
//y permitir modificar el domicilio del mismo.

void modificarCliente()
{
    cls();
    logo();
    cout<<"Ingrese el ID del cliente a modificar: ";
// modificarRegistroCliente(crearRegModificadoClientes(encontrarCliente(pedirEnteroValido())));

    int id = pedirEnteroValido();
    int pos = encontrarPosicionCliente(id);

    switch(pos)
    {
    case -1:
        cout<<"El archivo no existe o no es posible acceder a el"<<endl;
        msleep(1000);
        return;


    case -2:
        cout<<"No se encuentra el id de cliente buscado"<<endl;
        msleep(1000);
        return;


    default:
        modificarRegistroCliente(crearRegModificadoClientes(pos),pos);

        cout<<"Registro modificado con exito"<<endl;
        cout<<"Presione una tecla para continuar"<<endl;
        anykey();
        break;
    }
}

int encontrarPosicionCliente(int id)
{
    Cliente reg;
    int pos=0;
    FILE *p;
    p=fopen(ARCHIVO_CLIENTES,"rb");
    if(p==NULL)
    {
        return -1;
    }
    while(fread(&reg,sizeof(Cliente),1,p))
    {
        if (id == reg.id)
        {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -2;
}

Cliente crearRegModificadoClientes(int pos)
{
    Cliente regModificado;
    FILE*p;
    p=fopen(ARCHIVO_CLIENTES,"rb+");
    if(p==NULL)
    {
        cout<<"Error Grave!\nNo se puede leer el archivo "<<ARCHIVO_CLIENTES<<endl;
        cout<<"Presione una tecla para salir"<<endl;
        anykey();
        exit(407);
    }
    fseek(p,sizeof(Cliente)*pos,SEEK_SET);
    if(fread(&regModificado,sizeof(Cliente),1,p))
    {
        fflush(stdin);
        cout<<"Ingrese el nuevo Domicilio: ";
        cin.getline(regModificado.domicilio,50);
        fclose(p);
        return regModificado;
    }
    fclose(p);
}

bool modificarRegistroCliente (Cliente reg,int pos)
{
    FILE*p;
    p=fopen(ARCHIVO_CLIENTES,"rb+");
    if(p==NULL)
    {
        return 0;
    }
    fseek(p,sizeof(Cliente) * pos,SEEK_SET);
    if (fwrite(&reg,sizeof(Cliente),1,p))
    {
        fclose(p);
        return 1;
    }
    return 0;
    fclose(p);
}

void listarCliente_porID()
{
    cls();
    logo();
    cout<<"BUSCAR CLIENTE POR ID"<<endl;
    cout<<"Ingrese el ID: ";
    int id = pedirEnteroValido();
    int pos = encontrarPosicionCliente(id);
    if(mostrarCliente_porPosicion(pos))
    {
        cout<<"Presione una tecla para continuar"<<endl;
        anykey();
    }
    else
    {
        cout<<"No se pudo leer el archivo "<<ARCHIVO_CLIENTES<<endl;
        cout<<"Presione una tecla para continuar"<<endl;
        anykey();
    }
}

bool mostrarCliente_porPosicion(int pos)
{

    Cliente reg;
    FILE *p;
    p=fopen(ARCHIVO_CLIENTES,"rb");
    if(p==NULL)
    {
        return false;
    }
    fseek(p,sizeof(Cliente)*pos,SEEK_SET);
    if(fread(&reg,sizeof(Cliente),1,p))
    {
        mostrarCliente(reg);
        fclose(p);
        return true;
    }
    fclose(p);
    return false;
}

void listarTodosLosClientes()
{
    cls();
    logo();
    struct Cliente* listaClientes;
    int cantidad_clientes = cantidadRegistros(1);
    listaClientes = (Cliente*) malloc (cantidad_clientes * sizeof(Cliente));
    if (listaClientes==NULL)
        return;

    int     resultado = cargarListaClientes(listaClientes,cantidad_clientes);
    switch (resultado)
    {
    case 1:
        break;
    case 0:
        cout<<"ERROR, no se pudo leer el archivo en la posicion indicada  (Archivo vacio?)"<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        return;
    case -1:
        cout<<"ERROR, no se pudo abrir el archivo "<<ARCHIVO_CLIENTES<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        return;

    default:
        exit(999999);

    }
    ordenarListaClientes(listaClientes,cantidad_clientes);

    mostrarListaClientes(listaClientes,cantidad_clientes);
    free(listaClientes);
}

int cargarListaClientes(Cliente *lista,int cantidad_clientes)
{
    FILE*p;
    p=fopen(ARCHIVO_CLIENTES,"rb");
    if(p==NULL)
    {
        return -1;
    }
    if(fread(lista,sizeof (Cliente),cantidad_clientes,p))
    {
        fclose(p);
        return 1;
    }
    else
    {
        fclose(p);
        return 0;
    }
}

void ordenarListaClientes(Cliente *lista,int cant_Cli)
{
    //ordenamiento por seleccion
    Cliente aux;
    int posMin;

    for(int i=0 ; i<cant_Cli-1 ; i++)
    {
        posMin=i;
        //strcpy(men,lista[i].apellido);

        for(int j=i+1; j<cant_Cli; j++)
        {
            if(strcmp(lista[j].apellido,lista[posMin].apellido) < 0)
            {
                posMin=j;
            }
        }
        aux = lista[i];
        lista[i] = lista[posMin];
        lista[posMin] = aux;
    }
}

void mostrarListaClientes (Cliente *lista,int cant_Cli)
{
    int contador_mostrados=0,contador_clientes=0;
    cout<<"LISTA DE CLIENTES"<<endl;
    cout<<"-------------------------------------"<<endl;
    for(int i=0; i<cant_Cli; i++)
    {
        contador_clientes++;
        if(lista[i].estado)
        {
            mostrarCliente(lista[i]);
            cout<<"-------------------------------------"<<endl;
            contador_mostrados++;
        }

    }
    if(contador_mostrados)
    {
        cout<<"FIN DE LISTA CLIENTES"<<endl;
    }
    else
    {
        cout<<"NO HAY CLIENTES CARGADOS\n"<<endl;
    }
    if(contador_mostrados!=contador_clientes)
    {
        cout<<"(Algunos registros no se muestran en la lista porque fueron dados de baja)"<<endl;
    }
    cout<<"Presione una tecla cualquiera para continuar"<<endl;
    anykey();
}

void darDeBajaCliente()
{
    cls();
    logo();
    cout<<"Ingrese el ID de cliente a dar de baja: ";
    int id = pedirEnteroValido();
    cout<<endl;
    if(preguntar("Esta seguro que desea dar de baja al cliente?\n     Esta accion borrara el registro"))
    {
        int pos = encontrarPosicionCliente(id);
        switch (pos)
        {
        case -1:
            cout<<"ERROR, no se pudo abrir el archivo "<<ARCHIVO_CLIENTES<<endl;
            cout<<"Presione una tecla cualquiera para continuar"<<endl;
            anykey();
            return;
        case -2:
            cout<<"ERROR, el id ingresado no se encuentra en el archivo "<<ARCHIVO_CLIENTES<<endl;
            cout<<"Presione una tecla cualquiera para continuar"<<endl;
            anykey();
            return;
        default:
            break;
        }
        if(bajaLogica(pos))
        {
            cout<<"CLIENTE DADO DE BAJA"<<endl;
            cout<<"Presione una tecla cualquiera para continuar"<<endl;
            anykey();
        }
        else
        {
            cout<<"NO SE REALIZARON CAMBIOS. Error en el archivo clientes.dat"<<endl;
            cout<<"Presione una tecla cualquiera para continuar"<<endl;
            anykey();
        }
    }


}

bool bajaLogica(int pos)
{
    Cliente reg;
    FILE*p;
    p=fopen(ARCHIVO_CLIENTES,"rb+");
    if(p==NULL)
    {
        return 0;
    }
    fseek(p,sizeof(Cliente) * pos,SEEK_SET);

    if(fread(&reg,sizeof(Cliente),1,p)==0)
        return 0;
    reg.estado = false;

    fseek(p,sizeof(Cliente) * pos,SEEK_SET);
    if (fwrite(&reg,sizeof(Cliente),1,p))
    {
        fclose(p);
        return 1;
    }
    return 0;
    fclose(p);
}
#endif // FUNCIONES_CLIENTES_H_INCLUDED
