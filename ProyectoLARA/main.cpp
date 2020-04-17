#include <iostream>

using namespace std;
#include <rlutil.h>
using namespace rlutil;

int main()
{

//int LIGHTCYAN;

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
setColor(BROWN);

gotoxy(16,15);
gotoxy(16,15);  cout<<" |1|-Platos                   "<<endl;
gotoxy(16,16.5);cout<<" |2|-Clientes                 "<<endl;
gotoxy(16,17.5);cout<<" |3|-Pedidos                  "<<endl; //gotoxy experimentales. nose si puedo mantenerlos en todo el programa.
gotoxy(16,18);  cout<<" |4|-Reportes                 "<<endl;
gotoxy(16,19.5);cout<<" |5|-Configuracion            "<<endl;
gotoxy(16,21.5);cout<<"- - - - - - - - - - -       "<<endl;
gotoxy(16,22);  cout<<" |0|-Salir Del Programa       "<<endl;
gotoxy(43,16);
cout<<"Ingrese la opcion deseada: ";
int op;
cin>>op;
//setColor(GREY);

    return 0;
}
