#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void ingresarNuevoPlato()
{
    plato plato;
    //pido un registro completo con comprobacion de tipo de dato evitando el error del ciclo en la carga.
    cout<<"Ingrese los datos a continuacion:";
    Sleep(500);
    cls();
    while (true)
    {
        cout<<"Cargando un nuevo plato"<<endl;
        cout<<"Ingrese los datos a continuacion:";
        cout<<"ID:";
        while(!(cin>>plato.id))
        {
            cout<<"\nError en el tipo de dato ingresado.\nIngrese un ID numerico: ";
            cin.clear();
            cin.ignore(123,'\n');
        }

        cout<<"\nNombre: ";
        cin.ignore();
        cin.getline(plato.nombre,50);

        cout<<"\nCosto de preparacion: ";
        while(!(cin>>plato.costo_preparacion))
        {
            cout<<"\nError en el tipo de dato ingresado.\nIngrese un valor numerico: ";
            cin.clear();
            cin.ignore(123,'\n');
        }

        cout<<"\nValor de venta: ";
        while(!(cin>>plato.valor_venta))
        {
            cout<<"\nError en el tipo de dato ingresado.\nIngrese un valor numerico: ";
            cin.clear();
            cin.ignore(123,'\n');
        }

        cout<<"\nTiempo de preparacion: ";
        while(!(cin>>plato.tiempo_praparacion))
        {
            cout<<"\nError en el tipo de dato ingresado.\nIngrese un valor numerico entero: ";
            cin.clear();
            cin.ignore(123,'\n');
        }

        cout<<"\nID del restaurante: ";
        while(!(cin>>plato.id_restaurante))
        {
            cout<<"\nError en el tipo de dato ingresado.\nIngrese un ID numerico entero: ";
            cin.clear();
            cin.ignore(123,'\n');
        }

        cout<<"\nComision del restaurante: ";
        while(!(cin>>plato.comision_restaurante))
        {
            cout<<"\nError en el tipo de dato ingresado.\nIngrese un valor numerico entero: ";
            cin.clear();
            cin.ignore(123,'\n');
        }

        cout<<"\nID Categoria: ";
        while(!(cin>>plato.id_categoria))
        {
            cout<<"\nError en el tipo de dato ingresado.\nIngrese un ID numerico entero: ";
            cin.clear();
            cin.ignore(123,'\n');
        }

        plato.estado = true;

        // IMPORTANTE
        if(guardarRegistro(plato)) //esto condiciona a guardarregistro a devolver bool. capas lo cambio
        {
            cout<<"\nRegistro agregado con exito"<<endl;
            Sleep(700);
        }
        else
        {
            cout<<"\nError, no se puede escribir en disco"<<endl;
            return;
        }
        cls();
        cout<<"&--------Cargar otro registro ? --------&"<<endl;
        cout<<"&--- [ 1 ] Si --------------------------&"<<endl;
        cout<<"&--- [ 0 ] No --------------------------&"<<endl;
        cout<<"      ";
        bool op;
        while(!(cin>>op))
        {
            cout<<"\nError en el tipo de dato ingresado.\nIngrese 1 para cargar otro registro, o 0 para volver al menu : ";
            cin.clear();
            cin.ignore(123,'\n');
        }
        if(op==0)
        {
            return;
        }
    }


}


bool guardarRegistro (plato reg)
{
    FILE *file;
    file = fopen("platos.dat","ab");

    if(file==NULL)
    {
        return 0;
    }
    if(fwrite(&reg,sizeof (plato),1,file))
    {
        return 1;
    }
    return 0;

}

void submenuPlatos()
{
    cls();
    logo();

gotoxy(16,15);
gotoxy(16,15);   cout<<" |1|-Nuevo plato              "<<endl;
gotoxy(16,16.5); cout<<" |2|-Modificar  plato         "<<endl;
gotoxy(16,17.5); cout<<" |3|-Mostrar Plato por ID     "<<endl; //gotoxy experimentales. nose si puedo mantenerlos en todo el programa.
gotoxy(16,18);   cout<<" |4|-Platos por restaurant    "<<endl;
gotoxy(16,19.5); cout<<" |5|-Listar todos los platos  "<<endl;
gotoxy(16,20.5);cout<<"  |6|-Eliminar plato          "<<endl;
gotoxy(16,22.5); cout<<" |0|-Volver al menu principal "<<endl;
gotoxy(48,17);
cout<<"Ingrese la opcion deseada: ";
int op;
cin>>op;
//switch (op)

}

void logo()
{
setColor(CYAN);cout<<"                                                                    ";setColor(LIGHTCYAN);cout<<"    ,/((((((((((((((((((((/,    "<<endl;
setColor(CYAN);cout<<"         @@                       #@@/            @@@@@@@@@@@@@*    ";setColor(LIGHTCYAN);cout<<" *((((((((((((((((((((((((((((, "<<endl;
setColor(CYAN);cout<<"         @@                      #@*%@/           @@           @@(  ";setColor(LIGHTCYAN);cout<<"   ,*,....................,*,   "<<endl;
setColor(CYAN);cout<<"         @@                     &@/  #@/          @@            @@, ";setColor(LIGHTCYAN);cout<<"     ,,...,////..........,,     "<<endl;
setColor(CYAN);cout<<"         @@                    %@*    #@(         @@            @@. ";setColor(LIGHTCYAN);cout<<"      ,,...*//,..(#######)      "<<endl;
setColor(CYAN);cout<<"         @@                   %@,      %@(        @@          ,@@*  ";setColor(LIGHTCYAN);cout<<"       .,,......########.       "<<endl;
setColor(CYAN);cout<<"         @@                  &@*////////#@(       @@@@@@@@@@@@%     ";setColor(LIGHTCYAN);cout<<"         ,,.....#######         "<<endl;
setColor(CYAN);cout<<"         @@                 @@%//////////@@#      @@        @@(     ";setColor(LIGHTCYAN);cout<<"          ,,.....####)          "<<endl;
setColor(CYAN);cout<<"         @@                &@%            @@#     @@         (@@    ";setColor(LIGHTCYAN);cout<<"           .,,....,,            "<<endl;
setColor(CYAN);cout<<"         @@QQQQQQQQQQQ    @@%              &@#    @@           @@%  ";setColor(LIGHTCYAN);cout<<"             ,,..,,             "<<endl;
setColor(CYAN);cout<<"                                                                    ";setColor(LIGHTCYAN);cout<<"              ,,,.              "<<endl;
setColor(CYAN);cout<<"                                                                    ";setColor(LIGHTCYAN);cout<<"               .                "<<endl;
setColor(CYAN);cout<<"                                                                    ";setColor(LIGHTCYAN);cout<<"                                "<<endl;
}

void menuPrincipal()
{
gotoxy(16,15);
gotoxy(16,15);  cout<<" |1|-Platos                   "<<endl;
gotoxy(16,16.5);cout<<" |2|-Clientes                 "<<endl;
gotoxy(16,17.5);cout<<" |3|-Pedidos                  "<<endl; //gotoxy experimentales. nose si puedo mantenerlos en todo el programa.
gotoxy(16,18);  cout<<" |4|-Reportes                 "<<endl;
gotoxy(16,19.5);cout<<" |5|-Configuracion            "<<endl;
gotoxy(16,21.5);cout<<"- - - - - - - - - - -         "<<endl;
gotoxy(16,22);  cout<<" |0|-Salir Del Programa       "<<endl;
gotoxy(43,16);
cout<<"Ingrese la opcion deseada: ";
int op;
cin>>op;
switch (op)
{
case 1:
    {
        submenuPlatos();
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
case 0:
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
#endif // FUNCIONES_H_INCLUDED
