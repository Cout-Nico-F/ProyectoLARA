#ifndef TIPOS_DE_DATO_H_INCLUDED
#define TIPOS_DE_DATO_H_INCLUDED

struct plato
{
    int id;
    char nombre[50];
    float costo_preparacion;
    float valor_venta;
    int tiempo_praparacion;
    int id_restaurante;
    int comision_restaurante;
    int id_categoria;
    bool estado=false;
};

#endif // TIPOS_DE_DATO_H_INCLUDED
