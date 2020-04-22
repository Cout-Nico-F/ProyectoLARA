#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

void nuevoPlato();
bool guardarRegistro(plato);
void submenuPlatos();
void logo();
void menuPrincipal();
int iD_Existente(int);
void borrarTodo();
void adios();
int indice_ID(int);
plato buscarRegistro(int);
int modificarPlato();
int modificarRegistro(int,plato);
void mostrarLista();
int mostrarID(int);
void listarPlatosporID();

#endif // PROTOTIPOS_H_INCLUDED
