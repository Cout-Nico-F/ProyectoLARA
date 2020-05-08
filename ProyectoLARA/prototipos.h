#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

void nuevoPlato();
bool guardarRegistro(Plato);
void submenuPlatos();
void logo();
void menuPrincipal();
int iD_Existente(int);
void borrarTodo();
void adios();
int indice_ID(int);
Plato buscarRegistro(int);
void modificarPlato();
int modificarRegistro(int,Plato);
void mostrarLista();
int mostrarID(int);
void listarPlatosporID();
void eliminarPlato();
int iD_RestaurantExistente(int);
void listarPlatosPorRestaurant();
int mostrarIDrestaurant(int);

#endif // PROTOTIPOS_H_INCLUDED
