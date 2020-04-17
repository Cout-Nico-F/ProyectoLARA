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
}

bool guardarRegistro (platos reg)
{
    FILE *file;
    file = fopen("platos.dat","ab");

    if(file==NULL)
    {
        return 0;
    }
    if(fwrite(&reg,sizeof (platos),1,file))
    {
        return 1;
    }
    return 0;

}
#endif // FUNCIONES_H_INCLUDED
