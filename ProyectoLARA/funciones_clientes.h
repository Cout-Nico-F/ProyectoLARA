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
        gotoxy(16,20.5);
        cout<<" |0|-Volver al menu principal         "<<endl;

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

        }
        break;
        case 5:
        {


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
        cout<<"Error en el archivo "<<ARCHIVO_CLIENTES<<endl;
}

Cliente pedirCliente()
{
    Cliente cli;
    asignarIdAutonumerico(&cli.id);

    cout<<"Nombre:";
    cin.ignore();
    cin.getline(cli.nombre,50);

    cout<<"\nApellido:";
    cin.getline(cli.apellido,50);

    char mail[49];
    validado_EmailCliente(mail);
    strcpy(cli.mail,mail);

    //strcpy(cli.mail,validado2_EmailCliente());//no funciona en codeblocks. Escribe en memoria incorrecta.

    cout<<"\Domicilio:";
    cin.getline(cli.domicilio,100);

    cout<<"\n";
    cli.cp = validado_CpCliente();

    cli.fecha_nacimiento.anio = validado_Anio();
    cli.fecha_nacimiento.mes = validado_Mes();
    cli.fecha_nacimiento.dia = validado_Dia(cli.fecha_nacimiento);
    //falta mostrar cartel de EXITO
    cli.estado = true;
    return cli;
}

int cantidadClientes()
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

void asignarIdAutonumerico(int* x)//practica de punteros
{
    int auxId = validado_IdClienteAutonumerico();
    if(auxId<1)
    {
        cout<<"Error grave! No se puede asignar el nuevo ID"<<endl;
        cout<<"No se puede acceder al archivo "<<ARCHIVO_CLIENTES<<endl;
        cout<<"Presione una tecla para salir"<<endl;
        anykey();
        exit(404); //deberia salir o volver al menu?
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
        exit(404);
    }
    fseek(p,sizeof(Cliente)*pos,SEEK_SET);
    if(fread(&regModificado,sizeof(Cliente),1,p))
    {
        fflush(stdin);
        cout<<"Ingrese el nuevo Domicilio: ";
        cin.getline(regModificado.apellido,50);
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
#endif // FUNCIONES_CLIENTES_H_INCLUDED
