#ifndef FUNCIONES_PEDIDOS_H_INCLUDED
#define FUNCIONES_PEDIDOS_H_INCLUDED

void submenuPedidos()
{
    while(true)
    {
        cls();
        logo();

        gotoxy(16,15);
        cout<<" |1|-Nuevo pedido              "<<endl;
        gotoxy(16,16.5);
        cout<<" |2|-Modificar  pedido         "<<endl;
        gotoxy(16,17.5);
        cout<<" |3|-Listar pedido por ID     "<<endl;
        gotoxy(16,18);
        cout<<" |4|-Listar todos los pedidos      "<<endl;
        gotoxy(17,20);
        cout<<"- - - - - - - - - - - - - - -     "<<endl;
        gotoxy(16,21);
        cout<<" |0|-Volver al menu principal       "<<endl;


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
            nuevoPedido();
        }
        break;
        case 2:
        {
            // modificarCliente();
        }
        break;
        case 3:
        {
            // listarCliente_porID();
        }
        break;
        case 4:
        {
            listarTodosLosPedidos();
        }
        break;
        case 5:
        {
            //darDeBajaCliente();
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
            borrarTodo(ARCHIVO_PEDIDOS);
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

void nuevoPedido()
{
    if( preguntar("Desea cargar un nuevo pedido ?") == false )
    {
        return;
    }
    while(true)
    {
        Pedido nuevoPed = pedirPedido();
        if(agregarPedido(nuevoPed))
        {
            cout<<"Pedido agregado con exito"<<endl;
            cout<<"Presione una tecla para continuar"<<endl;
            anykey();
        }
        else
        {
            cout<<"Error en la escritura.\nNo se pudo agregar el registro nuevo."<<endl;
            cout<<"Presione una tecla para continuar"<<endl;
            anykey();
        }
        if( preguntar("Cargar otro pedido?") == false )
        {
            break;
        }
    }
    return;
}

Pedido pedirPedido()
{
    Pedido ped;
    asignarIdAutonumerico(&ped.ID,2);
    ped.ID_cliente = validado_IdClienteExistente();
    ped.ID_plato = validado_IdPlatoExistente();
    ped.Cantidad = validado_Cantidad();
    ped.pre = devolverPrecio(ped.ID_plato);
    ped.fecha_pedido.anio = validado_Anio();
    ped.fecha_pedido.mes = validado_Mes();
    ped.fecha_pedido.dia = validado_Dia(ped.fecha_pedido);
    ped.valoracion = validado_valoracion();
    ped.estado = 1;
    return ped;
}

bool iD_clienteExistente(int id)
{
    Cliente reg;
    FILE *p;
    p = fopen(ARCHIVO_CLIENTES,"ab+");
    if(p==NULL)
    {
        cout<<"Error grave!"<<endl;
        cout<<"No se puede acceder al archivo"<<ARCHIVO_PEDIDOS<<endl;
        cout<<"Presione una tecla para salir"<<endl;
        anykey();
        exit(405);///faltan permisos de escritura?
    }
    while(fread(&reg,sizeof (Cliente),1,p))
    {
        if(reg.id == id)
        {
            fclose(p);
            return 1;//el id ingresado es igual a uno existente
        }
    }
    fclose(p);
    return 0; //el id ingresado no existe

}

int validado_IdClienteExistente()
{
    int num;
    while(true)
    {
        cout<<"ID del Cliente: ";
        num = pedirEnteroValido();
        if (iD_clienteExistente(num))
        {
            break;
        }
        else
        {
            cout<<"Error, el ID ingresado no corresponde a ningun cliente cargado en clientes.dat"<<endl;
            msleep(1200);
        }
    }
    return num;
}

int validado_IdPlatoExistente()
{
    int num;
    while(true)
    {
        cout<<"ID del Plato: ";
        num = pedirEnteroValido();
        if (iD_PlatoExistente(num))
        {
            break;
        }
        else
        {
            cout<<"Error, el ID ingresado no corresponde a ningun plato cargado en platos.dat"<<endl;
            msleep(1200);
        }
    }
    return num;
}

int validado_Cantidad()
{
    int ente;
    while(true)
    {
        cout<<"Cantidad: ";
        ente = pedirEnteroValido();
        if(esPositivo(ente))
        {
            break;
        }
        else
        {
            cout<<"La cantidad debe ser un numero mayor que cero"<<endl;
            msleep(1200);
        }
    }
    return ente;
}

float devolverPrecio (int id)
{
    Plato reg;
    FILE *p;
    p = fopen(ARCHIVO_PLATOS,"rb");
    if(p==NULL)
    {
        cout<<"Error grave!"<<endl;
        cout<<"No se puede acceder al archivo"<<ARCHIVO_PLATOS<<endl;
        cout<<"Presione una tecla para salir"<<endl;
        anykey();
        exit(405);///faltan permisos de escritura?
    }

    while(fread(&reg,sizeof (Plato),1,p))
    {
        if(reg.id == id)
        {
            fclose(p);
            return reg.valor_venta;
        }
    }
    fclose(p);
    cout<<"Error grave! No existe el id ingresado. presione una tecla para salir"<<endl;
    anykey();
    exit(2020);///si el id esta bien corroborado nunca deberia salir por aca el programa
}

int validado_valoracion ()
{
    int val;
    while (true)
    {
        cout<<"Valoracion:";
        val = pedirEnteroValido();
        if(val>=0 && val <=10)
        {
            break;
        }
        else
        {
            cout<<"Valoracion invalida. Debe ser un entero entre 0 y 10 inclusive."<<endl;
            msleep(1200);
        }
    }
    return val;
}

bool agregarPedido (Pedido reg)
{
    FILE *file;
    file = fopen(ARCHIVO_PEDIDOS,"ab");

    if(file==NULL)
    {
        return 0;
    }
    if(fwrite(&reg,sizeof (Pedido),1,file))
    {
        fclose(file);
        return 1;
    }
    fclose(file);
    return 0;
}

void listarTodosLosPedidos()
{
    int cant_pedidos = cantidadRegistros(2);
    cls();
    logo();
    int contador_mostrados=0;
    cout<<"LISTA DE PEDIDOS";
    cout<<"\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
    Pedido ped;
    FILE*p;
    p=fopen(ARCHIVO_PEDIDOS,"rb");
    if(p==NULL)
    {

        setColor(LIGHTRED);
        cout<<"Error en la lectura del archivo"<<ARCHIVO_PEDIDOS<<endl;
        setColor(GREY);
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        return;
    }
    while(fread(&ped,sizeof(Pedido),1,p))
    {
        mostrarPedido(ped);
        cout<<"-------------------------------------"<<endl;
        contador_mostrados++;
    }
    fclose(p);
    if(contador_mostrados)
    {
        cout<<"FIN DE LISTA PEDIDOS"<<endl;
    }
    else
    {
        cout<<"NO HAY PEDIDOS CARGADOS\n"<<endl;
    }
    cout<<"Presione una tecla cualquiera para continuar"<<endl;
    anykey();
}

void mostrarPedido(Pedido pe)
{
    char traduce_int[10];
    if(pe.estado == 1)
    {
        strcpy(traduce_int,"En Curso");
    }
    else if( pe.estado == 2)
    {
        strcpy(traduce_int,"Completado");
    }
    else if(pe.estado == 3)
    {
        strcpy(traduce_int,"Cancelado");
    }

    cout<<"ID: . . . . . . . . "<<pe.ID<<endl;
    cout<<"ID Cliente: . . . . "<<pe.ID_cliente<<endl;
    cout<<"ID Plato: . . . . . "<<pe.ID_plato<<endl;
    cout<<"Cantidad: . . . . . "<<pe.Cantidad<<endl;
    cout<<"Precio Unit: . . . ."<<pe.pre<<endl;
    cout<<"Fecha:. . . . . . . "<<pe.fecha_pedido.dia<<"/"<<pe.fecha_pedido.mes<<"/"<<pe.fecha_pedido.anio<<endl;
    cout<<"Valoracion:. . . . ."<<pe.valoracion<<endl;
    cout<<"Estado:. . . . . . .";
    if(pe.estado ==1 )
    {
        setColor(YELLOW);
        cout<<traduce_int<<endl;
        setColor(GREY);
    }
    else if(pe.estado == 2)
    {
        setColor(GREEN);
        cout<<traduce_int<<endl;
        setColor(GREY);
    }
    else if(pe.estado == 3)
    {
        setColor(LIGHTRED);
        cout<<traduce_int<<endl;
        setColor(GREY);
    }
    cout<<"\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
}
#endif // FUNCIONES_PEDIDOS_H_INCLUDED
