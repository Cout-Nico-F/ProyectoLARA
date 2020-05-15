#ifndef FUNCIONES_CONFIGURACION_H_INCLUDED
#define FUNCIONES_CONFIGURACION_H_INCLUDED

void submenuConfig()
{
    while(true)
    {
        cls();
        logo();

        gotoxy(15,15);
        cout<<" |1|-Realizar copia de Seguridad   "<<endl;
        gotoxy(15,16);
        cout<<" |2|-Restaurar copia de Seguridad  "<<endl;
        gotoxy(15,17);

        gotoxy(15,18);
        cout<<"- - - - - - - - - - - - - - - - - -"<<endl;
        gotoxy(15.5,19);
        cout<<" |0|-Volver al menu principal       "<<endl;

        gotoxy(50,16);
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
            copiaSeguridad();
        }
        break;
        case 2:
        {
            restaurarCopiaSeguridad();
        }
        break;
        case 0:
        {
            return;
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

void copiaSeguridad()
{
    cls();
    logo();
    bool cli = bkp_Clientes();
    bool ped = bkp_Pedidos();
    bool pla = bkp_Platos();
    if (cli && ped && pla)
    {
        cout<<"Copia de seguridad Exitosa!"<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
    }
    else
    {
        cout<<"Copia de seguridad fallida. Uno o mas archivos no pudieron copiarse!"<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
    }
}

bool bkp_Clientes()
{
    struct Cliente* todosLosClientes;
    int cant = cantidadRegistros(1);
    todosLosClientes = (Cliente*) malloc (cant*sizeof(Cliente));
    if(mallocClientes(todosLosClientes,cant)<1)return false;
    if(escribirBackupClientes(todosLosClientes,cant))
    {
        setColor(GREEN);
        cout<<"BACKUP CLIENTES REALIZADO CON EXITO!"<<endl;
        setColor(GREY);
        msleep(200);
        free(todosLosClientes);
        return true;
    }
    else
    {
        cout<<"Error al escribir en el archivo "<<BKP_CLIENTES<<" !!!"<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        free(todosLosClientes);
        return false;
    }
}

bool mallocClientes(Cliente *todosLosClientes,int cant)
{
    //se me ocurre que intente guardarlo en memoria y si no puede por tamaño lo haga desde disco.
    //todosLosClientes = (Cliente*) malloc (cant*sizeof(Cliente)); tuve que sacarla afuera de la funcion (0x000005)
    if (todosLosClientes==NULL)
    {
        cout<<"ERROR No alcanza la memoria ram para cargar el archivo "<<ARCHIVO_CLIENTES<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        return 0;//posibilidad de manera sin mem din.(soporte a archivos de muchos GB)
    }
    int resultado = cargarListaClientes(todosLosClientes,cant);
    switch (resultado)
    {
    case 1:
        break;
    case 0:
        cout<<"ERROR, no se pudo leer el archivo en la posicion indicada  (Archivo vacio?)"<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        exit(5555);
    case -1:
        cout<<"ERROR, no se pudo abrir el archivo "<<ARCHIVO_CLIENTES<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        exit(400);

    default:
        exit(8888);

    }
    return 1;
}

bool escribirBackupClientes(Cliente *lista,int cant)
{
    FILE *p;
    p=fopen(BKP_CLIENTES,"wb");
    if(p==NULL)
    {
        cout<<"Error! ¿no hay permisos de escritura en disco? "<<endl;
        msleep(1200);
        exit(3333);
    }
    if(fwrite(lista,sizeof(Cliente),cant,p)==cant)
    {
        return true;
    }
    return false;
}

bool bkp_Pedidos()
{
    struct Pedido* todosLosPedidos;
    int cant = cantidadRegistros(2);
    todosLosPedidos = (Pedido*) malloc (cant*sizeof(Pedido));
    if(mallocPedidos(todosLosPedidos,cant)<1)return false;
    if(escribirBackupPedidos(todosLosPedidos,cant))
    {
        setColor(GREEN);
        cout<<"BACKUP PEDIDOS REALIZADO CON EXITO!"<<endl;
        setColor(GREY);
        msleep(200);
        free(todosLosPedidos);
        return true;
    }
    else
    {
        cout<<"Error al escribir en el archivo "<<BKP_PEDIDOS<<" !!!"<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        free(todosLosPedidos);
        return false;
    }
}

bool mallocPedidos(Pedido *todosLosPedidos,int cant)
{
    //se me ocurre que intente guardarlo en memoria y si no puede por tamaño lo haga desde disco.
    //todosLosPedidos = (Pedido*) malloc (cant*sizeof(Pedido));
    if (todosLosPedidos==NULL)
    {
        cout<<"ERROR No alcanza la memoria ram para cargar el archivo "<<ARCHIVO_PEDIDOS<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        return 0;//aca insertar manera sin mem din.(soporte a archivos de muchos GB)
    }
    int resultado = cargarListaPedidos(todosLosPedidos,cant);
    switch (resultado)
    {
    case 1:
        break;
    case 0:
        cout<<"ERROR, no se pudo leer el archivo en la posicion indicada  (Archivo vacio?)"<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        exit(6666);
    case -1:
        cout<<"ERROR, no se pudo abrir el archivo "<<ARCHIVO_PEDIDOS<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        exit(500);

    default:
        exit(9991);

    }
    return 1;
}

bool escribirBackupPedidos(Pedido *lista,int cant)
{
    FILE *p;
    p=fopen(BKP_PEDIDOS,"wb");
    if(p==NULL)
    {
        cout<<"Error! ¿no hay permisos de escritura en disco? "<<endl;
        msleep(1200);
        exit(3333);
    }
    if(fwrite(lista,sizeof(Pedido),cant,p)==cant)
    {
        return true;
    }
    return false;
}

bool escribirBackupPlatos(Plato *lista,int cant)
{
    FILE *p;
    p=fopen(BKP_PLATOS,"wb");
    if(p==NULL)
    {
        cout<<"Error! ¿no hay permisos de escritura en disco? "<<endl;
        msleep(1200);
        exit(3333);
    }
    if(fwrite(lista,sizeof(Plato),cant,p)==cant)
    {
        return true;
    }
    return false;
}

bool mallocPlatos(Plato *todosLosPlatos,int cant)
{
    //se me ocurre que intente guardarlo en memoria y si no puede por tamaño lo haga desde disco.
    //todosLosPlatos = (Plato*) malloc (cant*sizeof(Plato));
    if (todosLosPlatos==NULL)
    {
        cout<<"ERROR No alcanza la memoria ram para cargar el archivo "<<ARCHIVO_PLATOS<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        return 0;//aca insertar manera sin mem din.(soporte a archivos de muchos GB)
    }
    int resultado = cargarListaPlatos(todosLosPlatos,cant);
    switch (resultado)
    {
    case 1:
        break;
    case 0:
        cout<<"ERROR, no se pudo leer el archivo en la posicion indicada  (Archivo vacio?)"<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        exit(6666);
    case -1:
        cout<<"ERROR, no se pudo abrir el archivo "<<ARCHIVO_PLATOS<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        exit(500);

    default:
        exit(9991);

    }
    return 1;
}

bool bkp_Platos()
{
    struct Plato* todosLosPlatos;
    int cant = cantidadRegistros(3);
    todosLosPlatos = (Plato*) malloc (cant*sizeof(Plato));
    if(mallocPlatos(todosLosPlatos,cant)<1)return false;
    if(escribirBackupPlatos(todosLosPlatos,cant))
    {
        setColor(GREEN);
        cout<<"BACKUP PLATOS REALIZADO CON EXITO!"<<endl;
        setColor(GREY);
        msleep(200);
        free(todosLosPlatos);
        return true;
    }
    else
    {
        cout<<"Error al escribir en el archivo "<<BKP_PLATOS<<" !!!"<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        free(todosLosPlatos);
        return false;
    }
}

int cargarListaPedidos(Pedido *lista,int cant)
{
    FILE*p;
    p=fopen(ARCHIVO_PEDIDOS,"rb");
    if(p==NULL)
    {
        return -1;
    }
    if(fread(lista,sizeof (Pedido),cant,p))
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

int cargarListaPlatos(Plato *lista,int cant)
{
    FILE*p;
    p=fopen(ARCHIVO_PLATOS,"rb");
    if(p==NULL)
    {
        return -1;
    }
    if(fread(lista,sizeof (Plato),cant,p))
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

void restaurarCopiaSeguridad()
{
    cls();
    logo();
    bool cli = restaurar_bkp_Clientes();
    bool ped = restaurar_bkp_Pedidos();
    bool pla = restaurar_bkp_Platos();
    if (cli && ped && pla)
    {
        cout<<"Copia de seguridad Restaurada Exitosamente!"<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
    }
    else
    {
        cout<<"Restauracion incompleta. Uno o mas archivos no pudieron restaurarse!"<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
    }
}

bool restaurar_bkp_Clientes()
{
    //preguntar si esta seguro avisando del efecto sobrescritura
    struct Cliente* todosLosClientes;
    int cant = cantidadRegistros(4);
    if(cant<=0)return false;
    todosLosClientes = (Cliente*) malloc (cant*sizeof(Cliente));
    if (todosLosClientes==NULL)
    {
        cout<<"ERROR No alcanza la memoria ram para cargar el archivo "<<BKP_CLIENTES<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        return 0;//posibilidad de manera sin mem din.(soporte a archivos de muchos GB)
    }

    if(cargarBackupClientes(todosLosClientes,cant)<1) return false;
    if(sobreescribirClientes(todosLosClientes,cant))
    {
        setColor(GREEN);
        cout<<"BACKUP CLIENTES RESTAURADO CON EXITO!"<<endl;
        setColor(GREY);
        msleep(200);
        free(todosLosClientes);
        return true;
    }
    else
    {
        cout<<"Error al escribir en el archivo "<<BKP_CLIENTES<<" !!!"<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        free(todosLosClientes);
        return false;
    }
}

bool cargarBackupClientes(Cliente *todosLosClientes,int cant)
{
    int resultado = cargarListaBKPClientes(todosLosClientes,cant);
    switch (resultado)
    {
    case 1:
        break;
    case 0:
        cout<<"ERROR, no se pudo leer el archivo en la posicion indicada  (Archivo vacio?)"<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        exit(5551);
    case -1:
        cout<<"ERROR, no se pudo abrir el archivo "<<BKP_CLIENTES<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        exit(401);

    default:
        exit(8888);

    }
    return 1;
}

int cargarListaBKPClientes (Cliente *lista,int cant)
{
    FILE*p;
    p=fopen(BKP_CLIENTES,"rb");
    if(p==NULL)
    {
        return -1;
    }
    if(fread(lista,sizeof (Cliente),cant,p))
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

bool sobreescribirClientes(Cliente *lista,int cant)
{
    FILE *p;
    p=fopen(ARCHIVO_CLIENTES,"wb");
    if(p==NULL)
    {
        cout<<"Error! ¿no hay permisos de escritura en disco? "<<endl;
        msleep(1200);
        exit(3331);
    }
    if(fwrite(lista,sizeof(Cliente),cant,p)==cant)
    {
        return true;
    }
    return false;
}

bool restaurar_bkp_Pedidos()
{
    //preguntar si esta seguro avisando del efecto sobrescritura
    struct Pedido* todosLosPedidos;
    int cant = cantidadRegistros(4);
    if(cant<=0)return false;
    todosLosPedidos = (Pedido*) malloc (cant*sizeof(Pedido));
    if (todosLosPedidos==NULL)
    {
        cout<<"ERROR No alcanza la memoria ram para cargar el archivo "<<BKP_PEDIDOS<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        return 0;//posibilidad de manera sin mem din.(soporte a archivos de muchos GB)
    }

    if(escribirBackupPedidos(todosLosPedidos,cant)<1) return false;
    if(sobreescribirPedidos(todosLosPedidos,cant))
    {
        setColor(GREEN);
        cout<<"BACKUP PEDIDOS RESTAURADO CON EXITO!"<<endl;
        setColor(GREY);
        msleep(200);
        free(todosLosPedidos);
        return true;
    }
    else
    {
        cout<<"Error al escribir en el archivo "<<BKP_PEDIDOS<<" !!!"<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        free(todosLosPedidos);
        return false;
    }
}

bool cargarBackupPedidos(Pedido *todosLosPedidos,int cant)
{
    int resultado = cargarListaBKPPedidos(todosLosPedidos,cant);
    switch (resultado)
    {
    case 1:
        break;
    case 0:
        cout<<"ERROR, no se pudo leer el archivo en la posicion indicada  (Archivo vacio?)"<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        exit(5551);
    case -1:
        cout<<"ERROR, no se pudo abrir el archivo "<<BKP_PEDIDOS<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        exit(401);

    default:
        exit(8888);

    }
    return 1;
}

int cargarListaBKPPedidos (Pedido *lista,int cant)
{
    FILE*p;
    p=fopen(BKP_PEDIDOS,"rb");
    if(p==NULL)
    {
        return -1;
    }
    if(fread(lista,sizeof (Pedido),cant,p))
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

bool sobreescribirPedidos(Pedido *lista,int cant)
{
    FILE *p;
    p=fopen(ARCHIVO_PEDIDOS,"wb");
    if(p==NULL)
    {
        cout<<"Error! ¿no hay permisos de escritura en disco? "<<endl;
        msleep(1200);
        exit(3331);
    }
    if(fwrite(lista,sizeof(Pedido),cant,p)==cant)
    {
        return true;
    }
    return false;
}

bool restaurar_bkp_Platos()
{
    //preguntar si esta seguro avisando del efecto sobrescritura
    struct Plato* todosLosPlatos;
    int cant = cantidadRegistros(4);
    if(cant<=0)return false;
    todosLosPlatos = (Plato*) malloc (cant*sizeof(Plato));
    if (todosLosPlatos==NULL)
    {
        cout<<"ERROR No alcanza la memoria ram para cargar el archivo "<<BKP_PLATOS<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        return 0;//posibilidad de manera sin mem din.(soporte a archivos de muchos GB)
    }

    if(escribirBackupPlatos(todosLosPlatos,cant)<1) return false;
    if(sobreescribirPlatos(todosLosPlatos,cant))
    {
        setColor(GREEN);
        cout<<"BACKUP PLATOS RESTAURADO CON EXITO!"<<endl;
        setColor(GREY);
        msleep(200);
        free(todosLosPlatos);
        return true;
    }
    else
    {
        cout<<"Error al escribir en el archivo "<<BKP_PLATOS<<" !!!"<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        free(todosLosPlatos);
        return false;
    }
}

bool cargarBackupPlatos(Plato *todosLosPlatos,int cant)
{
    int resultado = cargarListaBKPPlatos(todosLosPlatos,cant);
    switch (resultado)
    {
    case 1:
        break;
    case 0:
        cout<<"ERROR, no se pudo leer el archivo en la posicion indicada  (Archivo vacio?)"<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        exit(5551);
    case -1:
        cout<<"ERROR, no se pudo abrir el archivo "<<BKP_PLATOS<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        exit(401);

    default:
        exit(8888);

    }
    return 1;
}

int cargarListaBKPPlatos (Plato *lista,int cant)
{
    FILE*p;
    p=fopen(BKP_PLATOS,"rb");
    if(p==NULL)
    {
        return -1;
    }
    if(fread(lista,sizeof (Plato),cant,p))
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

bool sobreescribirPlatos(Plato *lista,int cant)
{
    FILE *p;
    p=fopen(ARCHIVO_PLATOS,"wb");
    if(p==NULL)
    {
        cout<<"Error! ¿no hay permisos de escritura en disco? "<<endl;
        msleep(1200);
        exit(3331);
    }
    if(fwrite(lista,sizeof(Plato),cant,p)==cant)
    {
        return true;
    }
    return false;
}
#endif // FUNCIONES_CONFIGURACION_H_INCLUDED
