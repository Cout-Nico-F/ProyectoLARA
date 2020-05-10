#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED



//validaciones generales
int pedirEnteroValido();
bool esPositivo(int);
bool existeDia(Fecha,int);
bool esBisiesto(int);
bool confirmarOpcion(char *);//
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
struct Plato buscarRegistro(int);
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
struct Cliente pedirCliente();
void mostrarCliente(Cliente);//
void mostrarFecha(Fecha);//
bool agregarCliente(Cliente);

//validaciones en clientes
int validado_IdClienteAutonumerico();
char *validado2_EmailCliente();
int validado_CpCliente();
int validado_Dia(Fecha);
int validado_Mes();
int validado_Anio();
void validado_EmailCliente(char*);
void asignarIdAutonumerico(int*);


#endif // PROTOTIPOS_H_INCLUDED
