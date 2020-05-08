#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED



//validaciones generales
int pedirEnteroValido();
bool esPositivo(int);
bool existeDia(int,int);
bool es_bisiesto(int);
//
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
//clientes
void submenuClientes();
void nuevoCliente();
int cantidadClientes();
//validaciones en clientes
int validado_IdClienteAutonumerico();
char *validado_EmailCliente();
int validado_CpCliente();
int validado_Dia(int);
int validado_Mes();
int validado_Anio();


#endif // PROTOTIPOS_H_INCLUDED
