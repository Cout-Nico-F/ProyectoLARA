#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED



void logo();
void menuPrincipal();
void borrarTodo();
void adios();
//validaciones generales
int pedirEnteroValido();
float pedirFloatValido();
bool esPositivo(int);
bool existeDia(Fecha,int);
bool esBisiesto(int);
bool preguntar(const char *);///
//platos
void submenuPlatos();
void ingresoNuevoPlato();
bool guardarPlato(Plato);
bool iD_Existente(int);
int indice_ID(int);
struct Plato buscarPlato(int);
void modificarPlato();
int modificarRegistroPlatos(int,Plato);
void mostrarLista();
int mostrarID(int);
void listarPlatosporID();
void eliminarPlato();
void listarPlatosPorRestaurant();
int mostrarIDrestaurant(int);
int iD_RestaurantExistente(int);
//platosNuevas
void ingresoPlatoNuevo();
struct Plato pedirPlato();
int pedirIDvalidado();
void pedirNombreValido(char *);
float pedirCostoPrepValido();
float pedirValorVentaValido(int);
int pedirTiempoPrepValido();
int pedirIdRestauranteValido();
int pedirComisionRestValido();
int pedirIdCategoria();
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
int validado_CpCliente();
int validado_Dia(Fecha);
int validado_Mes();
int validado_Anio();
void validado_EmailCliente(char*);
void asignarIdAutonumerico(int*);


#endif // PROTOTIPOS_H_INCLUDED
