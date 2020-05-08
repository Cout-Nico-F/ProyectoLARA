#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "tipos_de_dato.h"
#include "prototipos.h"
#include "funciones.h"
#include "funciones_clientes.h"
#include "validaciones_clientes.h"

int main()
{
//setBackgroundColor(8);

    while(true) //Menu principal
    {
        cls();
        logo();
        gotoxy(16,15);
        gotoxy(16,15);
        cout<<" |1|-Platos                   "<<endl;
        gotoxy(16,16.5);
        cout<<" |2|-Clientes                 "<<endl;
        gotoxy(16,17.5);
        cout<<" |3|-Pedidos                  "<<endl; //gotoxy experimentales. nose si puedo mantenerlos en todo el programa.
        gotoxy(16,18);
        cout<<" |4|-Reportes                 "<<endl;
        gotoxy(16,19.5);
        cout<<" |5|-Configuracion            "<<endl;
        gotoxy(16,21.5);
        cout<<"- - - - - - - - - - -         "<<endl;
        gotoxy(16,22);
        cout<<" |0|-Salir Del Programa       "<<endl;
        gotoxy(43,16);
        cout<<"Ingrese la opcion deseada: ";
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
            submenuPlatos();
        }
        break;
        case 2:
        {
            submenuClientes();

        }
        break;
        case 3:
        {
            cls();
            logo();

            gotoxy(35,15);
            cout<<"Opcion no disponible en la version DEMO"<<endl;
            gotoxy(45,19.5);
            cout<<"Volviendo al menu"<<endl;
            Sleep(2000);
        }
        break;
        case 4:
        {
            cls();
            logo();

            gotoxy(35,15);
            cout<<"Opcion no disponible en la version DEMO"<<endl;
            gotoxy(45,19.5);
            cout<<"Volviendo al menu"<<endl;
            Sleep(2000);
        }
        break;
        case 5:
        {
            cls();
            logo();

            gotoxy(35,15);
            cout<<"Opcion no disponible en la version DEMO"<<endl;
            gotoxy(45,19.5);
            cout<<"Volviendo al menu"<<endl;
            Sleep(2000);

        }
        break;
        case 0:
        {
            adios();
            Sleep(2500);
            exit(0);
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





//setColor(GREY);

    return 0;
}
