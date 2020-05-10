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

        }
        break;
        case 3:
        {

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
            Sleep(600);
        }
        break;
        }

    }
}

void nuevoCliente()
{

    while(true)
    {
        cls();
        logo();
        cout<<"&--- Comenzar a cargar un nuevo cliente?--&"<<endl;
        cout<<"&--- [ 1 ] Si --------------------------&"<<endl;
        cout<<"&--- [ 0 ] No (Volver al Menu)----------&"<<endl;
        cout<<"       ";
        int op = pedirEnteroValido();
        if(op==0)
        {
            return;
        }
        if(op==1)
        {
            break;
        }
        cout<<"Opcion incorrecta"<<endl;
        Sleep(1300);
    }


    Cliente nuevoReg = pedirCliente();
    mostrarCliente(nuevoReg);
    anykey();
    //agregarCliente();//devuelve 1 si pudo agregarlo o 0 si no pudo



}

Cliente pedirCliente()
{
    Cliente cli;
    cli.id = validado_IdClienteAutonumerico();
    cout<<"Nombre:";
    cin.ignore();
    cin.getline(cli.nombre,50);

    cout<<"\nApellido:";
    cin.getline(cli.apellido,50);

    char mail[49];
    validado_EmailCliente(mail);
    strcpy(cli.mail,mail);

    //strcpy(cli.mail,validado_EmailCliente());//cadena a debe ser mayor a cadena b
    //cout<<validado_EmailCliente();

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

int cantidadClientes()
{
    int cant;
    FILE *p;
    p=fopen(ARCHIVO_CLIENTES,"rb");
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
    cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
}

#endif // FUNCIONES_CLIENTES_H_INCLUDED
