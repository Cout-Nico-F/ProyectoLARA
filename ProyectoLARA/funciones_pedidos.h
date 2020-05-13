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
           // nuevoCliente();
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
           // listarTodosLosClientes();
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
    Pedido nuevoPed = pedirPedido();

}

Pedido pedirPedido()
{
    Pedido ped;
    asignarIdAutonumerico(&ped.ID,2);
}

#endif // FUNCIONES_PEDIDOS_H_INCLUDED
