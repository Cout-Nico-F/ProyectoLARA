#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void nuevoPlato()
{
    plato plato;
    //pido un registro completo
    cout<<"Ingrese el ID:";
    while(!(cin>>plato.id))
    {
        cout<<"\nError en el tipo de dato ingresado.\nIngrese un ID numerico: ";
        cin.clear();
        cin.ignore(123,'\n');
    }
}

#endif // FUNCIONES_H_INCLUDED
