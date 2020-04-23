#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void nuevoPlato()
{
    cls();
    logo();
    plato platoEntrante;
    //pido un registro completo con comprobacion de tipo de dato evitando el error del ciclo en la carga.

    while(true)
    {
        cout<<"&---Comenzar a cargar un nuevo plato?---&"<<endl;
        cout<<"&--- [ 1 ] Si --------------------------&"<<endl;
        cout<<"&--- [ 0 ] No (Volver al Menu)----------&"<<endl;
        cout<<"       ";
        bool op;
        while(!(cin>>op))
        {
            cout<<"\nError en el tipo de dato ingresado.\nIngrese 1 para cargar un plato y 0 para volver al menu";
            cin.clear();
            cin.ignore(123,'\n');
        }
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


    while (true)
    {
        cout<<"Cargando un nuevo plato"<<endl;
        cout<<"Ingrese los datos a continuacion:";
        while(true) // comienza validacion de ID
        {
            cout<<"\nID:";
            while(!(cin>>platoEntrante.id))//validacion del tipo de dato entero
            {
                cout<<"\nError en el tipo de dato ingresado.\nIngrese un ID numerico y entero: ";
                cin.clear();
                cin.ignore(123,'\n');
            }
            if(platoEntrante.id < 0)
            {
                cout<<"El ID debe ser un numero positivo."<<endl;
                Sleep(1300);
                continue;
            }

            int retorno = iD_Existente(platoEntrante.id);
            if(retorno==0)
            {
                break; //ID validado.
            }
            else if(retorno==1)
            {
                cout<<"\nError(Ya existe el ID). El ID debe ser unico!"<<endl;
                cout<<"Presione una tecla para volver a intentar"<<endl; ///posibilidad de preguntar si quiere salir
                anykey();

            }
            else if(retorno==2)
            {
                cout<<"Hubo un error al intentar abrir el archivo     (sinPermisosDeLectura/elArchivoExiste?)"<<endl;
                cout<<"Presione una tecla para volver"<<endl;
                anykey();
                return;
            }


        }

        cin.ignore();//el ignore fuera del ciclo para que no ignore parte de la cadena ingresada al iterar por el false del if
        while(true)// validacion de campo NOMBRE
        {
            cout<<"\nNombre: ";
            //cin.ignore(); este ignore causaba un error si el usuario pasaba por el false del if
            cin.getline(platoEntrante.nombre,50);
            if( platoEntrante.nombre[0]!='\0' && platoEntrante.nombre[0]!=32 )
            {
                break;//validada
            }
            else
            {
                cout<<"Error: Debe ingresar un nombre. El primer caracter no puede ser un espacio en blanco"<<endl;
                Sleep(1200);
            }


        }


        while(true) //validacion del costo de preparacion
        {
            cout<<"\nCosto de preparacion: ";
            while(!(cin>>platoEntrante.costo_preparacion))
            {
                cout<<"\nError en el tipo de dato ingresado.\nIngrese un valor numerico: ";
                cin.clear();
                cin.ignore(123,'\n');
            }
            if(platoEntrante.costo_preparacion < 0)
            {
                cout<<"El costo de preparacion no puede ser negativo!"<<endl;
                Sleep(1000);
                continue;
            }
            else
            {
                break; //validado.
            }
        }

        //
        while(true)//validacion del valor de venta
        {
            cout<<"\nValor de venta: ";
            while(!(cin>>platoEntrante.valor_venta))
            {
                cout<<"\nError en el tipo de dato ingresado.\nIngrese un valor numerico: ";
                cin.clear();
                cin.ignore(123,'\n');
            }
            if(platoEntrante.valor_venta > platoEntrante.costo_preparacion) //si es mayor que el costo de preparacion es tambien mayor que cero(p.transitiva)
            {
                break;//validado.
            }
            else
            {
                cout<<"Valor de venta incorrecto. Debe ser mayor al costo de preparacion";
                Sleep(1200);
                continue;
            }
        }

        //
        while(true)//validacion del tiempo de preparacion
        {
            cout<<"\nTiempo de preparacion: ";
            while(!(cin>>platoEntrante.tiempo_preparacion))
            {
                cout<<"\nError en el tipo de dato ingresado.\nIngrese un valor numerico entero: ";
                cin.clear();
                cin.ignore(123,'\n');
            }
            if(platoEntrante.tiempo_preparacion > 1)
            {
                break; // validado.
            }
            else
            {
                cout<<"Error: Ingrese los minutos que toma preparar el plato, no puede ser menor a 1"<<endl;
                Sleep(1200);
                continue;
            }

        }

        //
        while(true)
        {
            cout<<"\nID del restaurante: ";
            while(!(cin>>platoEntrante.id_restaurante))
            {
                cout<<"\nError en el tipo de dato ingresado.\nIngrese un ID numerico entero: ";
                cin.clear();
                cin.ignore(123,'\n');
            }
            if(platoEntrante.id_restaurante >0)
            {
                break;
            }
            else
            {
                cout<<"Error: el id debe ser un numero entero positivo"<<endl;
                Sleep(1200);
                continue;
            }
        }

        //
        while(true)
        {
            cout<<"\nComision del restaurante: ";
            while(!(cin>>platoEntrante.comision_restaurante))
            {
                cout<<"\nError en el tipo de dato ingresado.\nIngrese un valor numerico entero: ";
                cin.clear();
                cin.ignore(123,'\n');
            }
            if(platoEntrante.comision_restaurante >=0 && platoEntrante.comision_restaurante <=100)
            {
                break;
            }
            else
            {
                cout<<"Error: La comision debe ser entre 0 y 100"<<endl;
                Sleep(1200);
                continue;
            }
        }

        //
        while(true)
        {
            cout<<"\nID Categoria: ";
            while(!(cin>>platoEntrante.id_categoria))
            {
                cout<<"\nError en el tipo de dato ingresado.\nIngrese un ID numerico entero: ";
                cin.clear();
                cin.ignore(123,'\n');
            }
            if(platoEntrante.id_categoria > 0)
            {
                break;
            }
            else
            {
                cout<<"Error: el id debe ser un numero entero positivo"<<endl;
                Sleep(1200);
                continue;
            }
        }

        //
        platoEntrante.estado = true;

        // IMPORTANTE
        if(guardarRegistro(platoEntrante)) //esto condiciona a guardarregistro a devolver bool. capas lo cambio
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

int iD_Existente(int id)
{
    plato reg;
    FILE *p;
    p = fopen("platos.dat","ab+");
    if(p==NULL)
    {
        return 2;//el archivo no pudo abrirse o no existe
    }
    while(fread(&reg,sizeof (plato),1,p))
    {
        if(reg.id == id)
        {
            return 1;//el id ingresado es igual a uno existente
        }
    }
    return 0; //el id ingresado es unico

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
        fclose(file);
        return 1;
    }
    fclose(file);
    return 0;

}

void submenuPlatos()
{
    while(true)
    {
        cls();
        logo();


        gotoxy(16,15);
        cout<<" |1|-Nuevo plato              "<<endl;
        gotoxy(16,16.5);
        cout<<" |2|-Modificar  plato         "<<endl;
        gotoxy(16,17.5);
        cout<<" |3|-Listar Plato por ID     "<<endl; //gotoxy experimentales. nose si puedo mantenerlos en todo el programa.
        gotoxy(16,18);
        cout<<" |4|-Listar platos por restaurant    "<<endl;
        gotoxy(16,19.5);
        cout<<" |5|-Listar todos los platos  "<<endl;
        gotoxy(16,20.5);
        cout<<" |6|-Eliminar plato          "<<endl;
        gotoxy(16,22.5);
        cout<<" |0|-Volver al menu principal "<<endl;
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
            nuevoPlato();
        }
        break;
        case 2:
        {
            modificarPlato();
        }
        break;
        case 3:
        {
            listarPlatosporID();
        }
        break;
        case 4:
        {
            listarPlatosPorRestaurant();
        }
        break;
        case 5:
        {
            mostrarLista();

        }
        break;
        case 6:
        {
            eliminarPlato();
        }
        break;
        case 0:
        {
            return;
        }
        break;
        case 101:
        {
            borrarTodo();
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

void logo()
{
    setColor(GREY);
    cout<<"                                                                    ";
    setColor(BROWN);
    cout<<"    ,/((((((((((((((((((((/,    "<<endl;
    setColor(GREY);
    cout<<"         @@                       #@@/            @@@@@@@@@@@@@*    ";
    setColor(BROWN);
    cout<<" *((((((((((((((((((((((((((((, "<<endl;
    setColor(GREY);
    cout<<"         @@                      #@*%@/           @@           @@(  ";
    setColor(YELLOW);
    cout<<"   ,*,....................,*,   "<<endl;
    setColor(GREY);
    cout<<"         @@                     &@/  #@/          @@            @@, ";
    setColor(YELLOW);
    cout<<"     ,,";
    setColor(BROWN);
    cout<<"...,";
    setColor(RED);
    cout<<"////";
    setColor(BROWN);
    cout<<"..........";
    setColor(YELLOW);
    cout<<",,     "<<endl;
    setColor(GREY);
    cout<<"         @@                    %@*    #@(         @@            @@. ";
    setColor(YELLOW);
    cout<<"      ,,";
    setColor(BROWN);
    cout<<"...";
    setColor(RED);
    cout<<"*//";
    setColor(BROWN);
    cout<<",..";
    setColor(RED);
    cout<<"(#######)      "<<endl;
    setColor(GREY);
    cout<<"         @@                   %@,      %@(        @@          ,@@*  ";
    setColor(YELLOW);
    cout<<"       .,,";
    setColor(BROWN);
    cout<<"......";
    setColor(RED);
    cout<<"########.       "<<endl;
    setColor(GREY);
    cout<<"         @@                  &@*////////#@(       @@@@@@@@@@@@%     ";
    setColor(YELLOW);
    cout<<"         ,,";
    setColor(BROWN);
    cout<<".....";
    setColor(RED);
    cout<<"#######         "<<endl;
    setColor(GREY);
    cout<<"         @@                 @@%//////////@@#      @@        @@(     ";
    setColor(YELLOW);
    cout<<"          ,,";
    setColor(BROWN);
    cout<<".....";
    setColor(RED);
    cout<<"####)          "<<endl;
    setColor(GREY);
    cout<<"         @@                &@%            @@#     @@         (@@    ";
    setColor(YELLOW);
    cout<<"           .,,";
    setColor(BROWN);
    cout<<"....";
    setColor(YELLOW);
    cout<<",,            "<<endl;
    setColor(GREY);
    cout<<"         @@QQQQQQQQQQQ    @@%              &@#    @@           @@%  ";
    setColor(YELLOW);
    cout<<"             ,,";
    setColor(BROWN);
    cout<<"..";
    setColor(YELLOW);
    cout<<",,             "<<endl;
    setColor(GREY);
    cout<<"                                                                    ";
    setColor(YELLOW);
    cout<<"              ,,,.              "<<endl;
    setColor(GREY);
    cout<<"                                                                    ";
    setColor(YELLOW);
    cout<<"               .                "<<endl;
    setColor(GREY);
    cout<<"                                                                    ";
    setColor(YELLOW);
    cout<<"                                "<<endl;
    setColor(GREY);
}
void adios()//no me termina de gustar.. tal vez una animacion usando Sleep() ?
{
    cls();
//cout<<"///////////////////////////////////////////s:--/s/++++/////::://////////////////////////////////////"<<endl;
//cout<<"////////////////////////////////////////++oo....oy---++////::.-/////////////////////////////////////"<<endl;
//cout<<"//////////////////////////////////////s+:-/s.....y....s:::::/:`-////////////////////////////////////"<<endl;
//cout<<"///////////////////////////////////::o+....+/....o:.../+..----- :///////////////////////////////////"<<endl;
//cout<<"////////////////////////////////::--.+/....-s....-o....y....... .-::////////////////////////////////"<<endl;
//cout<<"/////////////////////////////::---/+/+s.....s-....y....o:..........--:`:////////////////////////////"<<endl;
//cout<<"///////////////////////////::..../+...s...../+....+:...:o.............`::///////////////////////////"<<endl;
//cout<<"/////////////////////////::-.....o:...//.....y....-s....y-............`.-:://///////////////////////"<<endl; Intento1
//cout<<"///////////////////////`:-......./o....s.....s-....s....+/................-:////////////////////////"<<endl;
//cout<<"////////////////////// ..........-y....o-....:o....//...-y.....:/+/-........:://////////////////////"<<endl;
//cout<<"/////////////////////-............s-...:+.....y.----y---.s:.../o-.:s-........-://///////////////////"<<endl;
//cout<<"/////////////////////-............/+....s.-:/+s+/////:::.-s...y-...o:.........-/////////////////////"<<endl;
//cout<<"////////////////////-.............-y...:s//:-.............s:..y....y-..........-////////////////////"<<endl;
//cout<<"///////////////////:...............o:..-..................-s.:o...-s............:///////////////////"<<endl;
//cout<<"///////////////////-...............-s......................s:s-...o:............-///////////////////"<<endl;
//cout<<"//////////////////:.................s-.....................-yo....y..............://////////////////"<<endl;
//cout<<"//////////////////-.................:o......................-....++..............-//////////////////"<<endl;
//cout<<"//////////////////-..................y...........................y-..............-//////////////////"<<endl;
//cout<<"//////////////////-................../o........................./+...............-//////////////////"<<endl;
//cout<<"//////////////////-...................y.........................y-...............-//////////////////"<<endl;
//cout<<"//////////////////-...................:o.......................+/................-//////////////////"<<endl;
//cout<<"//////////////////:..................../o...................../o.................://////////////////"<<endl;
//cout<<"///////////////////-....................:o-..................++-................-///////////////////"<<endl;
//cout<<"///////////////////:.....................-++-............../o:..................:///////////////////"<<endl;
//cout<<"////////////////////-......................-/+//:-....-:/++:-..................-////////////////////"<<endl;
//cout<<"////////////////////:-.......................---://////:--....................-/////////////////////"<<endl;
//cout<<"///////////////////oyhy+-....:++/-....-:-....-:-........---.....-...--....----:/ymy/////////////////"<<endl;
//cout<<"/////////////////+dmmhmmd:.-ymmmmy-.-odddy:.odddy/-.../hddds:.-yd:.+dd/.+hdddo//dNd/////////////////"<<endl;
//cout<<"/////////////////dmd+/+mmy.hmmoommy.ymmymNd-hmmdmmh/..hmmoymm++mmo-oNmy-mNmys///mNm/////////////////"<<endl;
//cout<<"////////////////oNms///oho/mmd--dmm-mmd-smm+yNNo+mmm/.mNN:-hmd:dNmdmNm/-mmd/////mmm/////////////////"<<endl;
//cout<<"////////////////sNmo/yddds+Nmh..dmm:mmd./mmssmNo.+NNh.mmN--ymm-:smNNy/-:mmmo+///mmm/////////////////"<<endl;
//cout<<"////////////////oNNs/symmd+mmd:-dNm-mmm-:mmyoNNs.:mmd.mmmydmd/...hNm/::+Nmmmd///mNN/////////////////"<<endl;
//cout<<"/////////////////dNd///dNd/dmm+/mNd-yNm+/mNs+mmy-yNmo-mNNdmm/...-hmm+//+Nmdo+///ydh/////////////////"<<endl;
//cout<<"/////////////////+dmdosmms/smmhyNNy:+mNdyNm/+NNddNmy--NNm+dmo-:::hmNo//oNNdyhy///so/////////////////"<<endl;
//cout<<"//////////////////+ydmmds///sdmmdy///odmmmy:/dmmmh+---dmmmds/////smd+//+dmmmdd+/ommo////////////////"<<endl;
//cout<<"/////////////////////++///////++///////++/////++///////++/////////+//////+++/////++/////////////////"<<endl;


//cout<<"ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss"<<endl;
//cout<<"ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss"<<endl;
//cout<<"ssssssssssssssssssssssssssss.  `ss+   /sso`   :sss/.    `-+.       .s/    osssssssssssssssssssssssss"<<endl;
//cout<<"sssssssssssssssssssssss+--:s`  `ss+   /ss-     os/   :+/.-://-   -//s`    .sssssssssssssssssssssssss"<<endl;
//cout<<"sssssssssssssssssssssss:  `s`   ..`   /s+  :.  .s+     `.:+ss+   +ss-  +   /ssssssssssssssssssssssss"<<endl;
//cout<<"ssssssssssssssssssssssss--+s`   --.   /s`  :-   /so/-.`    /s+   +s+  `:`  `osssssssssssssssssssssss"<<endl;
//cout<<"ssssssssssssssssssssssso  :s`  `ss+   /:  `..`  `.` `//:   :s+   +s`  ...   -sssssssssssssssssssssss"<<endl;
//cout<<"sssssssssssssssssssssss/  .s.  `ss+   :  .ssso   -:.    `./ss+   +:  :sss/   +ssssssssssssssssssssss"<<endl;
//cout<<"sssssssssssssssssssssss.   sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss"<<endl; intento2
//cout<<"sssssssssssssssssssssss+///sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss"<<endl;
//cout<<"ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss"<<endl;
//cout<<"ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss"<<endl;
//cout<<"ssssssssssssssssssssss++++sssss+++osss++os++++++++osss++/+osssssso+//+ssss++++ssssssssssssssssssssss"<<endl;
//cout<<"ssssssssssssssssssssss`  `ssss+   :ss+  -+        .s-      `:ss/`      .+s`  `ssssssssssssssssssssss"<<endl;
//cout<<"ssssssssssssssssssssss`  `ssss+   :ss+  -+   /ooooo.  `os+``./:   :ss.   +-  .ssssssssssssssssssssss"<<endl;
//cout<<"ssssssssssssssssssssss`  `ssss+   :ss+  -+       -+   -s:----/`   oss/   :/  /ssssssssssssssssssssss"<<endl;
//cout<<"ssssssssssssssssssssss`  `ssss+   :ss+  -+   :+++oo   .s:-`  --   +ss:   /o--ossssssssssssssssssssss"<<endl;
//cout<<"ssssssssssssssssssssss`   ....:`   --`  /+   `....:/   `-.   -o.  `--   :s-``-ssssssssssssssssssssss"<<endl;
//cout<<"ssssssssssssssssssssss:-------/s/-...-:oso--------:so/-..-/+-/ss+:-..-:oss/--:ssssssssssssssssssssss"<<endl;
//cout<<"ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss"<<endl;


//cout<<"/////////////////////////////////////////////////////////////////////////-`-:///////////////////////"<<endl;
//cout<<"//////////////////////////////////////////////ssso/////////////////////////. .://///////////////////"<<endl;
    cout<<"////////////////////////////////////////////yo-../y+//+oo////////:::////////- `:////////////////////"<<endl;
    cout<<"///////////////////////:://////////////////os.....-hss:-:os///////:..:///////: `:///////////////////"<<endl;
    cout<<"/////////////////////:.-//////////////ossoshs......:h...../y////////:`.://////- .///////////////////"<<endl;
    cout<<"///////////////////:.`://////////////h+....:h-......h:.....y/---::://:``://////. ://////////////////"<<endl;
    cout<<"/////////////////:. .:////////////::oo....../s....../s.....:y......---. -//////: -//////////////////"<<endl;
    cout<<"////////////////:` .//////////::--..+o.......h.......h......h:......... `--:////`.//////////////////"<<endl;
    cout<<"///////////////:` `////////::-...:+/:y.......o+......o+.....+o......... `...--:/.`//////////////////"<<endl;
    cout<<"//////////////:`  ://////:-`...:y/--+d-......-h......:y.....-d-........ .......-..//////////////////"<<endl;
    cout<<"//////////////-  `/////:-. ....h-..../o.......y:......h-.....y/.................``-:////////////////"<<endl;
    cout<<"//////////////.  .///:-..` ...-d......h......./s......+o...../y.................`...-://////////////"<<endl;
    cout<<"/////////////:`  `/:-....``....h/.....o/.......h-.....-h......h-......................-:////////////"<<endl;
    cout<<"////://///////`   -......``....+s.....-y.......o+......s/.....+o........................:///////////"<<endl;
    cout<<"//////////////-   `....... ....-h......y-......:h......:y.....-d-......+soos+-...........-://///////"<<endl;//este queda
    cout<<"//////////////:`   .......`.....y:.....+o.......h:..--:/h+///-.oo.....oo....+y............-:////////"<<endl;
    cout<<"//////////////:.    ............/s......h....:+oysoo++/::----..-d-...-d......d.............-:///////"<<endl;
    cout<<"/////////////:...    ...........-d-.....yoooo/:.................oo...:h.....-h..............-://////"<<endl;
    cout<<"////////////:-....`   ...........o+...:+/-......................-h-..oo.....oo...............-://///"<<endl;
    cout<<"////////////-.......`  `.........-h..............................+s.-h-.....d-................-/////"<<endl;
    cout<<"///////////:...........` `........s/..............................h:/y.....+s..................:////"<<endl;
    cout<<"///////////-..............`.......:h............................../yh-.....h:..................-////"<<endl;
    cout<<"/////////::........................y/..............................+/...../y...................-////"<<endl;
    cout<<"//////////:......................../y.....................................h:....................:///"<<endl;
    cout<<"//////////-.........................y:.................................../y.....................:///"<<endl;
    cout<<"//////////-.........................:h...................................h:.....................:///"<<endl;
    cout<<"//////////-..........................y/................................./s......................:///"<<endl;
    cout<<"//////////:..........................:y................................-h-......................:///"<<endl;
    cout<<"//////////:.........................../y...............................y/......................-////"<<endl;
    cout<<"///////////-.....Hasta Luego!........../y.............................s+.......................-////"<<endl;
    cout<<"///////////:.....(v1.0)NicoF............:s/.........................-s+........................:////"<<endl;
    cout<<"////////////-............................-+s:.....................-os-........................://///"<<endl;
//cout<<"////////////:..............................-+s+-................/oo:.........................-//////"<<endl;
//cout<<"/////////////:................................:+++++/:---:/++++o/..............(v1.0).......-://////"<<endl;
//cout<<"//////////////:....................................-://///:--............NicolasFerreira...-:///////"<<endl;

}

void borrarTodo()
{
    setColor(RED);
    cls();
    cout<<"Esta seguro que desea reestablecer el archivo de datos completo?\nEsto borrara toda la informacion definitivamente. "<<endl;
    cout<<"----[9]-Borrar todo."<<endl;
    cout<<"----[0]-Volver al menu sin hacer cambios."<<endl;
    cout<<"--->[";
    gotoxy(7,5);
    cout<<"]"<<endl;
    int op;
    gotoxy(6,5);
    if(!(cin>>op))
    {
        op=0;
        cin.clear();
        cin.ignore(123,'\n');
    }
    setColor(GREY);
    if(op==9)
    {
        FILE *p;
        p=fopen("platos.dat","wb");
        if(p==NULL)
        {
            cout<<"Error: no pudo realizarse la operacion sobre el archivo.\nNo hay permisos de escritura?"<<endl;
            cout<<"Presione una tecla para volver al menu"<<endl;
            anykey();
            return;

        }
        fclose(p);
        return;
    }
    cout<<"Operacion cancelada, volviendo al menu."<<endl;
    Sleep(1400);

}

void modificarPlato() //convertida a void
{
    cls();
    logo();
    cout<<"&----Desea modificar un plato ?---------&"<<endl;
    cout<<"&--- [ 1 ] Si --------------------------&"<<endl;
    cout<<"&--- [ 0 ] No (Volver al Menu)----------&"<<endl;
    cout<<"       ";
    bool op;
    while(!(cin>>op))
    {
        cout<<"\nError en la opcion ingresada.\n Ingrese 1 para modificar y 0 para volver al menu: ";
        cin.clear();
        cin.ignore(123,'\n');
    }
    if(op==0)
    {
        return;
    }
    //
    int idBuscado;
    while(true)
    {
        cout<<"\nIngrese el ID del plato a modificar";
        while(!(cin>>idBuscado))
        {
            cout<<"Error: el ID debe ser de tipo numerico entero y positivo"<<endl;
            cin.clear();
            cin.ignore(123,'\n');
        }
        if(idBuscado>=0)
        {
            break; //idBuscado validado
        }
    }
    plato reg = buscarRegistro(idBuscado);
    switch(reg.id)
    {
    case -2:
    {
        cout<<"Error en la apertura del archivo.  (soloLectura)"<<endl;
        Sleep(1200);
        return;
    }
    break;
    case -1:
    {
        cout<<"El id ingresado no existe."<<endl;
        Sleep(1200);
        return;
    }
    break;
    default:

        break;
    }
    float nuevo_valor_venta;

    while(true)//validacion del valor de venta
    {
        cout<<"Valor de venta actual: "<<reg.valor_venta<<endl;
        cout<<"\nIngrese el nuevo valor de venta: ";
        while(!(cin>>nuevo_valor_venta))
        {
            cout<<"\nError en el tipo de dato ingresado.\nIngrese un valor numerico: ";
            cin.clear();
            cin.ignore(123,'\n');
        }
        if(nuevo_valor_venta > reg.costo_preparacion) //si es mayor que el costo de preparacion es tambien mayor que cero(p.transitiva)
        {
            break;//validado.
        }
        else
        {
            cout<<"Valor de venta incorrecto. Debe ser mayor al costo de preparacion";
            Sleep(1200);
            continue;
        }
    }
    int nuevo_tiempo_preparacion;
    while(true)//validacion del tiempo de prep
    {
        cout<<"Tiempo de preparacion actual: "<<reg.tiempo_preparacion<<endl;
        cout<<"\nIngrese el nuevo valor para Tiempo de Preparacion: ";
        while(!(cin>>nuevo_tiempo_preparacion))
        {
            cout<<"\nError en el tipo de dato ingresado.\nIngrese un valor numerico entero y positivo: ";
            cin.clear();
            cin.ignore(123,'\n');
        }
        if(nuevo_tiempo_preparacion < 0)
        {
            continue;
        }
        else
            break;
    }
    int indice = indice_ID(idBuscado);

    switch(indice)
    {
    case -2:
    {
        cout<<"Error en la apertura del archivo.  (soloLectura)"<<endl;
        Sleep(1200);
        return ;
    }
    break;
    case -1:
    {
        cout<<"El id ingresado no existe."<<endl;
        Sleep(1200);
        return ;
    }
    break;
    default:

        break;
    }
    reg.valor_venta = nuevo_valor_venta;
    reg.tiempo_preparacion = nuevo_tiempo_preparacion;
    if(modificarRegistro(indice,reg))
    {
        cout<<"Registro modificado con exito"<<endl;
        Sleep(1400);
        return ;
    }
    else
    {
        cout<<"No se pudo modificar el registro. Error en la escritura del archivo"<<endl;
        Sleep(1400);
        return ;
    }

}

int indice_ID (int id_buscado)
{
    plato reg;
    FILE *p;
    p= fopen("platos.dat","rb");
    if(p==NULL)
    {
        return -2;
    }
    int pos=0;
    while(fread(&reg,sizeof (plato),1,p))
    {
        if(id_buscado== reg.id)
        {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

plato buscarRegistro (int id_buscado)
{
    plato reg;
    FILE *p;
    p= fopen("platos.dat","rb");
    if(p==NULL)
    {
        reg.id = -2;
        return reg;
    }
    int pos=0;
    while(fread(&reg,sizeof (plato),1,p))
    {
        if(id_buscado== reg.id)
        {
            fclose(p);
            return reg;
        }
        pos++;
    }
    fclose(p);
    reg.id = -1;
    return reg;
}

int modificarRegistro(int indice,plato reg_modificado)
{
    FILE *p;
    p= fopen("platos.dat","rb+");
    if(p==NULL)
    {
        return -2;
    }
    fseek(p,sizeof (plato)*indice,0);
    fwrite(&reg_modificado,sizeof (plato),1,p);
    fclose(p);
    return 0;
}

void mostrarLista()
{
    cls();
    logo();
    FILE *p;
    p=fopen("platos.dat","rb");
    if(p==NULL)
    {
        cout<<"Error en la apertura del archivo.     (soloLectura)"<<endl;
        cout<<"Presione una tecla cualquiera para continuar"<<endl;
        anykey();
        return;
    }
    plato reg;



    while(fread(&reg,sizeof (plato),1,p))
    {
        char traduce_bool[3];
        if(reg.estado==true)
        {
            strcpy(traduce_bool,"Si");
        }
        else
        {
            strcpy(traduce_bool,"No");
        }
        cout<<"=============================="<<endl;
        cout<<"ID del plato:_________________"<<reg.id<<endl;
        cout<<"Nombre:_______________________"<<reg.nombre<<endl;
        cout<<"Costo de Preparacion:_________"<<reg.costo_preparacion<<endl;
        cout<<"Valor de Venta:_______________"<<reg.valor_venta<<endl;
        cout<<"Tiempo de Preparacion:________"<<reg.tiempo_preparacion<<endl;
        cout<<"ID del Restaurante:___________"<<reg.id_restaurante<<endl;
        cout<<"Comision del Restaurante:_____"<<reg.comision_restaurante<<endl;
        cout<<"ID de Categoria:______________"<<reg.id_categoria<<endl;
        cout<<"Habilitado:___________________"<<traduce_bool<<endl;
    }
    cout<<"=============================="<<endl;
    cout<<"FIN DEL ARCHIVO"<<endl;
    cout<<"Presione una tecla para volver al menu"<<endl;
    anykey();
}
void listarPlatosporID() //(se puede mejorar)
{
    cls();
    logo();
    cout<<"&----------Listar plato por id?---------&"<<endl;
    cout<<"&--- [ 1 ] Si --------------------------&"<<endl;
    cout<<"&--- [ 0 ] No (Volver al Menu)----------&"<<endl;
    cout<<"       ";
    bool op;
    while(!(cin>>op))
    {
        cout<<"\nError en el tipo de dato ingresado.\n Ingrese 1 para listar un plato y 0 para volver al menu: ";
        cin.clear();
        cin.ignore(123,'\n');
    }
    if(op==0)
    {
        return;
    }
    //
    int busqueda;
    while(true)
    {
        cls();
        logo();
        cout<<"\nIngrese el ID del plato buscado: ";
        while(!(cin>>busqueda))
        {
            cout<<"Error: Debe ingresar un numero de ID.\nIngrese el ID del plato buscado: ";
            cin.clear();
            cin.ignore(123,'\n');
        }
        int existe = iD_Existente(busqueda);
        if(existe==1)
        {
            int retorno = mostrarID(busqueda);
            if(retorno==2)
            {
                cout<<"Error en la lectura del archivo."<<endl;
                cout<<"Presione una tecla cualquiera para volver al menu"<<endl;
                anykey();
                return;
            }
            if(retorno==0)
            {
                cout<<"Error: No se encontro el ID buscado"<<endl;
                Sleep(1400);
            }
            if(retorno==1 || retorno == 0)
            {

                cout<<"\n"<<endl;
                cout<<"&------------Listar otro plato por id?-----------&"<<endl;
                cout<<"&------------ [ 1 ] Si --------------------------&"<<endl;
                cout<<"&------------ [ 0 ] No (Volver al Menu)----------&"<<endl;
                cout<<"                ";
                bool op;
                while(!(cin>>op))
                {
                    cout<<"\nError en el tipo de dato ingresado.\n Ingrese 1 para listar un plato y 0 para volver al menu: ";
                    cin.clear();
                    cin.ignore(123,'\n');
                }
                if(op==0)
                {
                    return;
                }
            }
            // mostrar
            //break;//id valido
        }
        else if (existe == 0)
        {
            cout<<"El ID buscado no existe"<<endl;
            Sleep(1400);
        }
        else if ( existe == 2)
        {
            cout<<"No se puede leer el archivo         (SoloLectura)"<<endl;
            cout<<"Presione una tecla cualquiera pra continuar"<<endl;
            continue;
        }
        if(op!=1)
        {
            cls();
            logo();
            cout<<"&--------Intentar nuevamente ?----------&"<<endl;
            cout<<"&--- [ 1 ] Si --------------------------&"<<endl;
            cout<<"&--- [ 0 ] No --------------------------&"<<endl;
            cout<<"      ";
            bool op;
            while(!(cin>>op))
            {
                cout<<"\nError en el tipo de dato ingresado.\nIngrese 1 para intentar de nuevo, o 0 para volver al menu : ";
                cin.clear();
                cin.ignore(123,'\n');
            }
            if(op==0)
            {
                return;
            }
            if(op==1)
            {
                continue;
            }
            else
            {
                cout<<"Opcion incorrecta!"<<endl;
                Sleep(1200);
            }
        }
    }

}

int mostrarID(int id)
{
    plato reg;
    FILE *p;
    p = fopen("platos.dat","rb");
    if(p==NULL)
    {
        return 2;//el archivo no pudo abrirse o no existe
    }
    while(fread(&reg,sizeof (plato),1,p))
    {
        if(reg.id == id)
        {
            if(reg.estado==true)
            {
                cout<<"=============================="<<endl;
                cout<<"ID del plato:_________________"<<reg.id<<endl;
                cout<<"Nombre:_______________________"<<reg.nombre<<endl;
                cout<<"Costo de Preparacion:_________"<<reg.costo_preparacion<<endl;
                cout<<"Valor de Venta:_______________"<<reg.valor_venta<<endl;
                cout<<"Tiempo de Preparacion:________"<<reg.tiempo_preparacion<<endl;
                cout<<"ID del Restaurante:___________"<<reg.id_restaurante<<endl;
                cout<<"Comision del Restaurante:_____"<<reg.comision_restaurante<<endl;
                cout<<"ID de Categoria:______________"<<reg.id_categoria<<endl;
                cout<<"=============================="<<endl;
                return 1;
            }
            else
            {
                cout<<"El registro al que intentas acceder fue dado de baja"<<endl;
                Sleep(2000);
                return 1;
            }
        }
    }

    //            char traduce_bool[3];
//            if(reg.estado==true)
//            {
//                strcpy(traduce_bool,"Si");
//            }
//            else
//            {
//                strcpy(traduce_bool,"No");
//            }
//            cout<<"=============================="<<endl;
//            cout<<"ID del plato:_________________"<<reg.id<<endl;
//            cout<<"Nombre:_______________________"<<reg.nombre<<endl;
//            cout<<"Costo de Preparacion:_________"<<reg.costo_preparacion<<endl;
//            cout<<"Valor de Venta:_______________"<<reg.valor_venta<<endl;
//            cout<<"Tiempo de Preparacion:________"<<reg.tiempo_preparacion<<endl;
//            cout<<"ID del Restaurante:___________"<<reg.id_restaurante<<endl;
//            cout<<"Comision del Restaurante:_____"<<reg.comision_restaurante<<endl;
//            cout<<"ID de Categoria:______________"<<reg.id_categoria<<endl;
//            cout<<"Habilitado:___________________"<<traduce_bool<<endl;
//            cout<<"=============================="<<endl;
//            return 1;//exitoso


    return 0; //el id ingresado no existe

}

void eliminarPlato()
{
    cls();
    logo();
    cout<<"&--------Eliminar plato por id?---------&"<<endl;
    cout<<"&--- [ 1 ] Si --------------------------&"<<endl;
    cout<<"&--- [ 0 ] No (Volver al Menu)----------&"<<endl;
    cout<<"       ";
    bool op;
    while(!(cin>>op))
    {
        cout<<"\nError en el tipo de dato ingresado.\n Ingrese 1 para listar un plato y 0 para volver al menu: ";
        cin.clear();
        cin.ignore(123,'\n');
    }
    if(op==0)
    {
        return;
    }
    //

    int idBuscado;
    while(true)
    {
        cout<<"\nIngrese el ID del plato a dar de baja: ";
        while(!(cin>>idBuscado))
        {
            cout<<"Error: el ID debe ser de tipo numerico entero y positivo"<<endl;
            cin.clear();
            cin.ignore(123,'\n');
        }
        if(idBuscado>=0)
        {
            break; //idBuscado validado
        }
    }
    plato reg = buscarRegistro(idBuscado);
    switch(reg.id)
    {
    case -2:
    {
        cout<<"Error en la apertura del archivo.  (soloLectura)"<<endl;
        Sleep(1400);
        return;
    }
    break;
    case -1:
    {
        cout<<"El id ingresado no existe."<<endl;
        Sleep(1200);
        return ;
    }
    break;
    default:

        break;
    }

    int indice = indice_ID(idBuscado);

    switch(indice)
    {
    case -2:
    {
        cout<<"Error en la apertura del archivo.  (soloLectura)"<<endl;
        Sleep(1200);
        return ;
    }
    break;
    case -1:
    {
        cout<<"El id ingresado no existe."<<endl;
        Sleep(1200);
        return ;
    }
    break;
    default:

        break;
    }
    reg.estado = false; //baja logica.

    if(modificarRegistro(indice,reg)==0)
    {
        cout<<"Registro dado de baja con exito"<<endl;
        Sleep(1400);
        return ;
    }
    else
    {
        cout<<"No se pudo modificar el registro. Error en la escritura del archivo"<<endl;
        Sleep(1400);
        return ;
    }
}

void listarPlatosPorRestaurant ()
{
    cls();
    logo();
    cout<<"&----Listar plato por Restaurant?---------&"<<endl;
    cout<<"&--- [ 1 ] Si --------------------------&"<<endl;
    cout<<"&--- [ 0 ] No (Volver al Menu)----------&"<<endl;
    cout<<"       ";
    bool op;
    while(!(cin>>op))
    {
        cout<<"\nError en el tipo de dato ingresado.\n Ingrese 1 para listar y 0 para volver al menu: ";
        cin.clear();
        cin.ignore(123,'\n');
    }
    if(op==0)
    {
        return;
    }
    //
    int busqueda;
    while(true)
    {
        cls();
        logo();
        cout<<"\nIngrese el ID del Restaurant a listar: ";
        while(!(cin>>busqueda))
        {
            cout<<"Error: Debe ingresar un numero de ID.\nIngrese el ID del Restaurant buscado: ";
            cin.clear();
            cin.ignore(123,'\n');
        }
        int existe = iD_RestaurantExistente(busqueda);
        if(existe==1)
        {
            int retorno = mostrarIDrestaurant(busqueda);
            if(retorno==2)
            {
                cout<<"Error en la lectura del archivo."<<endl;
                cout<<"Presione una tecla cualquiera para volver al menu"<<endl;
                anykey();
                return;
            }
            if(retorno==0)
            {
                cout<<"Error: No se encontro el ID buscado"<<endl;
                Sleep(1400);
            }
            if(retorno==1 || retorno == 0)
            {

                cout<<"\n"<<endl;
                cout<<"&------------Listar otro plato por id?-----------&"<<endl;
                cout<<"&------------ [ 1 ] Si --------------------------&"<<endl;
                cout<<"&------------ [ 0 ] No (Volver al Menu)----------&"<<endl;
                cout<<"                ";
                bool op;
                while(!(cin>>op))
                {
                    cout<<"\nError en el tipo de dato ingresado.\n Ingrese 1 para listar un plato y 0 para volver al menu: ";
                    cin.clear();
                    cin.ignore(123,'\n');
                }
                if(op==0)
                {
                    return;
                }
            }

        }
        else if (existe == 0)
        {
            cout<<"El ID buscado no existe"<<endl;
            Sleep(1400);
        }
        else if ( existe == 2)
        {
            cout<<"No se puede leer el archivo         (SoloLectura)"<<endl;
            cout<<"Presione una tecla cualquiera pra continuar"<<endl;
            continue;
        }
        if(op!=1)
        {
            cls();
            logo();
            cout<<"&--------Intentar nuevamente ?----------&"<<endl;
            cout<<"&--- [ 1 ] Si --------------------------&"<<endl;
            cout<<"&--- [ 0 ] No --------------------------&"<<endl;
            cout<<"      ";
            bool op;
            while(!(cin>>op))
            {
                cout<<"\nError en el tipo de dato ingresado.\nIngrese 1 para intentar de nuevo, o 0 para volver al menu : ";
                cin.clear();
                cin.ignore(123,'\n');
            }
            if(op==0)
            {
                return;
            }
            if(op==1)
            {
                continue;
            }
            else
            {
                cout<<"Opcion incorrecta!"<<endl;
                Sleep(1200);
            }
        }
    }

}

int mostrarIDrestaurant(int id)
{
    int con=0;
    plato reg;
    FILE *p;
    p = fopen("platos.dat","rb");
    if(p==NULL)
    {
        return 2;//el archivo no pudo abrirse o no existe
    }
    cout<<"=============================="<<endl;
//    while(fread(&reg,sizeof (plato),1,p))
//    {
//        if(reg.id_restaurante == id)
//        {
//            char traduce_bool[3];
//            if(reg.estado==true)
//            {
//                strcpy(traduce_bool,"Si");
//            }
//            else
//            {
//                strcpy(traduce_bool,"No");
//            }
//
//            cout<<"ID del plato:_________________"<<reg.id<<endl;
//            cout<<"Nombre:_______________________"<<reg.nombre<<endl;
//            cout<<"Costo de Preparacion:_________"<<reg.costo_preparacion<<endl;
//            cout<<"Valor de Venta:_______________"<<reg.valor_venta<<endl;
//            cout<<"Tiempo de Preparacion:________"<<reg.tiempo_preparacion<<endl;
//            cout<<"ID del Restaurante:___________"<<reg.id_restaurante<<endl;
//            cout<<"Comision del Restaurante:_____"<<reg.comision_restaurante<<endl;
//            cout<<"ID de Categoria:______________"<<reg.id_categoria<<endl;
//            cout<<"Habilitado:___________________"<<traduce_bool<<endl;
//            cout<<"=============================="<<endl;
//            con++;//exitoso

                while(fread(&reg,sizeof (plato),1,p))
    {
        if(reg.id_restaurante == id)
        {

            if(reg.estado==true)
            {
               cout<<"ID del plato:_________________"<<reg.id<<endl;
            cout<<"Nombre:_______________________"<<reg.nombre<<endl;
            cout<<"Costo de Preparacion:_________"<<reg.costo_preparacion<<endl;
            cout<<"Valor de Venta:_______________"<<reg.valor_venta<<endl;
            cout<<"Tiempo de Preparacion:________"<<reg.tiempo_preparacion<<endl;
            cout<<"ID del Restaurante:___________"<<reg.id_restaurante<<endl;
            cout<<"Comision del Restaurante:_____"<<reg.comision_restaurante<<endl;
            cout<<"ID de Categoria:______________"<<reg.id_categoria<<endl;
            cout<<"=============================="<<endl;
            con++;
            }

        }

    }
    if(con==0)
    {
        return 0; //el id ingresado no existe
    }
    else
        return 1;


}

int iD_RestaurantExistente(int id)
{
    plato reg;
    FILE *p;
    p = fopen("platos.dat","ab+");
    if(p==NULL)
    {
        return 2;//el archivo no pudo abrirse o no existe
    }
    while(fread(&reg,sizeof (plato),1,p))
    {
        if(reg.id_restaurante == id)
        {
            return 1;//el id ingresado es igual a uno existente
        }
    }
    return 0; //el id ingresado es unico

}

#endif // FUNCIONES_H_INCLUDED
