#ifndef TIPOS_DE_DATO_H_INCLUDED
#define TIPOS_DE_DATO_H_INCLUDED
const char* ARCHIVO_PLATOS = "platos.dat";
const char* ARCHIVO_CLIENTES = "clientes.dat";
const char* ARCHIVO_PEDIDOS = "pedidos.dat";

struct Fecha
{
    int dia;
    int mes;
    int anio;
};

struct Plato
{
    int id;
    char nombre[50];
    float costo_preparacion;
    float valor_venta;
    int tiempo_preparacion;
    int id_restaurante;
    int comision_restaurante;
    int id_categoria;
    bool estado=false;
};

struct Cliente
{
    int id;
    char nombre[50];
    char apellido[50];
    char mail[50];
    char domicilio[100];
    int cp;
    Fecha fecha_nacimiento;
    bool estado;
};

struct Pedido
{
    int ID;
    int ID_cliente;
    int ID_plato;
    int Cantidad;
    float pre;
    Fecha fecha_pedido;
    float valoracion;
    int estado;
};


#endif // TIPOS_DE_DATO_H_INCLUDED
